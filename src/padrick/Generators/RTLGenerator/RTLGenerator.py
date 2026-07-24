# Copyright 2021-2022 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Manuel Eggimann, ETH Zurich

import importlib.resources as resources
import logging
import os
from pathlib import Path
from typing import Tuple, Mapping

import hjson
from padrick.Generators.PadrickTemplate import PadrickTemplate
from padrick.Generators.GeneratorSettings import RTLTemplates
from padrick.Model import Constants
from padrick.Model.Padframe import Padframe
from padrick.Logging import configure_logging
from reggen import gen_rtl as reggen_gen_rtl
from reggen import validate as reggen_validate
from reggen.ip_block import IpBlock

logger = logging.getLogger("padrick.RTLGenerator")
configure_logging()

template_package = 'padrick.Generators.RTLGenerator.Templates'

class RTLGenException(Exception):
    pass

def domain_register_bytes(pad_domain) -> int:
    """Byte size of a pad domain's register block: 4 bytes per 32-bit register.

    Mirrors the register set emitted by the regfile templates (INFO plus, per non-hardwired
    dynamic pad, its config register group and its mux_sel register). The reggen and peakrdl
    backends both pack these 32-bit registers sequentially, so this predicts identical
    per-domain sizes and hence identical inter-domain offsets across both backends.
    """
    num_regs = 1  # INFO
    for pad in pad_domain.pad_list:
        if pad.is_hardwired:
            continue
        if pad.dynamic_pad_signals_soc2pad:
            total_bits = 0
            num_cfg_regs = 1
            for signal in pad.dynamic_pad_signals_soc2pad:
                if total_bits + signal.size > 32:
                    num_cfg_regs += 1
                    total_bits = signal.size
                else:
                    total_bits += signal.size
            num_regs += num_cfg_regs
        if pad.dynamic_pad_signals:
            num_regs += 1  # mux_sel
    return num_regs * 4


def generate_rtl(templates: RTLTemplates, padframe: Padframe, dir: Path, header_text: str, vlnv=None,
                 register_backend: str = "reggen", **extra_template_kwargs):
    os.makedirs(dir/"src", exist_ok=True)
    os.makedirs(dir/"include"/padframe.name, exist_ok=True)
    templates.toplevel_sv_package.render(dir/"src", logger=logger, padframe=padframe, header_text=header_text)

    next_pad_domain_reg_offset = 0 # Offset of the first register of the current pad_frame's register file. All
    address_ranges: Mapping[str, Tuple[int, int]] = {} # dictionary of pad_domain to start- end-address tupple
    # mappings. The end address is inclusive
    # registers in the padframe are mapped to a contiguous address space.
    shared_peakrdl = (register_backend == "peakrdl" and
                      padframe.config_port_topology.value == "shared")
    for pad_domain in padframe.pad_domains:
        templates.pad_domain_top.render(dir /"src", logger=logger, padframe=padframe, pad_domain=pad_domain, header_text=header_text, register_backend=register_backend, **extra_template_kwargs)
        templates.pad_inst_module.render(dir /"src", logger=logger, padframe=padframe, pad_domain=pad_domain, header_text=header_text, **extra_template_kwargs)
        templates.internal_pkg.render(dir /"src", logger=logger, padframe=padframe, pad_domain=pad_domain, header_text=header_text, **extra_template_kwargs)
        templates.pad_mux_module.render(dir /"src", logger=logger, padframe=padframe, pad_domain=pad_domain, header_text=header_text, register_backend=register_backend, **extra_template_kwargs)

        if register_backend == "peakrdl":
            # For the shared topology all domains land in one flattened regblock emitted after
            # the loop; only reserve the address range here. per_domain gets its own regblock.
            size = domain_register_bytes(pad_domain)
            address_ranges[pad_domain.name] = (next_pad_domain_reg_offset,
                                               next_pad_domain_reg_offset + size)
            if not shared_peakrdl:
                _generate_regblock_peakrdl(templates, padframe, pad_domain, dir, header_text)
            next_pad_domain_reg_offset += size
        else:
            templates.regfile_hjson.render(dir /"src", logger=logger, padframe=padframe, pad_domain=pad_domain,
                                           start_address_offset=hex(next_pad_domain_reg_offset), header_text=header_text, hw_version=Constants.HARDWARE_VERSION, **extra_template_kwargs)


            # Generate Register file using lowRisc reg_tool
            logger.debug("Invoking reggen to generate register file from Register file description")
            hjson_reg_file = dir/"src"/f"{padframe.name}_{pad_domain.name}_regs.hjson"
            try:
                obj = IpBlock.from_path(str(hjson_reg_file), [])
            except ValueError as e:
                logger.error(f"Fatal error while parsing auto generated register file for pad_domain {pad_domain.name}.")
                raise RTLGenException(f"Error parsing regfile.") from e
            address_ranges[pad_domain.name] = (next_pad_domain_reg_offset, obj.reg_blocks[None].offset)
            next_pad_domain_reg_offset = obj.reg_blocks[None].offset
            return_code = reggen_gen_rtl.gen_rtl(obj, (dir/"src").as_posix())
            if return_code != 0 and not (return_code is None):
                logger.error(f"Regtool template rendering of register file for pad domain {pad_domain.name} failed")
                raise RTLGenException("Reggen Rendering failed")

    if shared_peakrdl:
        _generate_flattened_regblock_peakrdl(templates, padframe, dir, header_text, address_ranges)

    templates.toplevel_module.render(dir / "src", logger=logger, padframe=padframe, address_ranges=address_ranges,
                                     address_space_size=next_pad_domain_reg_offset, header_text=header_text, register_backend=register_backend, **extra_template_kwargs)
    templates.assign_header_file.render(dir / "include" / padframe.name, logger=logger, padframe=padframe, header_text=header_text, **extra_template_kwargs)

    templates.bender_project_file.render(dir, logger=logger, padframe=padframe, header_text=header_text, templates=templates, register_backend=register_backend, **extra_template_kwargs)
    # Skip generation of FuseSoC core file if the config file does not contain a VLNV and we do not supply it externally
    if vlnv:
        templates.fusesoc_core_file.render(dir, logger=logger, padframe=padframe, header_text=header_text, templates=templates, vlnv=vlnv,  **extra_template_kwargs)
    templates.ipapprox_src_files_yml.render(dir, logger=logger, padframe=padframe, header_text=header_text, templates=templates, **extra_template_kwargs)
    templates.ipapprox_ips_list_yml.render(dir, logger=logger, padframe=padframe, header_text=header_text, **extra_template_kwargs)


def _generate_regblock_peakrdl(templates, padframe, pad_domain, dir, header_text):
    """Render a per-domain .rdl and generate its standalone PeakRDL-regblock (per_domain topology)."""
    from padrick.Generators.PeakRDLBackend import generate_regblock, PeakRDLBackendException
    templates.regfile_rdl.render(dir / "src", logger=logger, padframe=padframe, pad_domain=pad_domain,
                                 start_address_offset="0x0", header_text=header_text,
                                 hw_version=Constants.HARDWARE_VERSION)
    rdl_file = dir / "src" / f"{padframe.name}_{pad_domain.name}_regs.rdl"
    module_name = f"{padframe.name}_{pad_domain.name}_config_reg_top"
    package_name = f"{padframe.name}_{pad_domain.name}_config_reg_pkg"
    logger.debug("Invoking PeakRDL-regblock to generate the register file from the SystemRDL description")
    try:
        generate_regblock(rdl_file, dir / "src", module_name, package_name,
                          frontend=padframe.config_interface.value)
    except PeakRDLBackendException as e:
        logger.error(f"PeakRDL register block generation failed for pad domain {pad_domain.name}.")
        raise RTLGenException("PeakRDL Rendering failed") from e


def _generate_flattened_regblock_peakrdl(templates, padframe, dir, header_text, address_ranges):
    """Render one flattened .rdl (a top addrmap wrapping per-domain regfiles) and generate a
    single regblock living at the padframe top level (shared topology)."""
    from padrick.Generators.PeakRDLBackend import generate_regblock, PeakRDLBackendException
    flatten = [(pad_domain, address_ranges[pad_domain.name][0]) for pad_domain in padframe.pad_domains]
    templates.regfile_rdl_flat.render(dir / "src", logger=logger, padframe=padframe,
                                      flatten=flatten, header_text=header_text,
                                      hw_version=Constants.HARDWARE_VERSION)
    rdl_file = dir / "src" / f"{padframe.name}_regs.rdl"
    module_name = f"{padframe.name}_config_reg_top"
    package_name = f"{padframe.name}_config_reg_pkg"
    top_def_name = f"{padframe.name}_config"
    logger.debug("Invoking PeakRDL-regblock to generate the flattened register file from the SystemRDL description")
    try:
        generate_regblock(rdl_file, dir / "src", module_name, package_name,
                          frontend=padframe.config_interface.value, top_def_name=top_def_name)
    except PeakRDLBackendException as e:
        logger.error("PeakRDL flattened register block generation failed.")
        raise RTLGenException("PeakRDL Rendering failed") from e





