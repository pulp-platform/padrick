import importlib.resources as resources
import logging
import os
from pathlib import Path
from typing import Tuple, Mapping

import click_log
import hjson
from padrick.Generators.TemplateRenderJob import TemplateRenderJob
from padrick.Model.Padframe import Padframe
from reggen import gen_rtl as reggen_gen_rtl
from reggen import validate as reggen_validate

logger = logging.getLogger("padrick.RTLGenerator")
click_log.basic_config(logger)

template_package = 'padrick.Generators.RTLGenerator.Templates'

class RTLGenException(Exception):
    pass

def generate_rtl(padframe: Padframe, dir: Path, header_text: str):
    os.makedirs(dir/"src", exist_ok=True)
    TemplateRenderJob(name='SV package',
                      target_file_name='pkg_{padframe.name}.sv',
                      template=resources.read_text(template_package, 'pkg_padframe.sv.mako')
                      ).render(dir/"src", logger=logger, padframe=padframe, header_text=header_text)

    next_pad_domain_reg_offset = 0 # Offset of the first register of the current pad_frame's register file. All
    address_ranges: Mapping[str, Tuple[int, int]] = {} # dictionary of pad_domain to start- end-address tupple
    # mappings. The end address is inclusive
    # registers in the padframe are mapped to a contiguous address space.
    for pad_domain in padframe.pad_domains:
        TemplateRenderJob(name=f'Paddomain module {pad_domain.name}',
                          target_file_name=f'{padframe.name}_{pad_domain.name}.sv',
                          template=resources.read_text(template_package, 'pad_domain.sv.mako')
                          ).render(dir/"src", logger=logger, padframe=padframe, pad_domain=pad_domain, header_text=header_text)
        TemplateRenderJob(name=f'Pad instantiation module {pad_domain.name}',
                          target_file_name=f'{padframe.name}_{pad_domain.name}_pads.sv',
                          template=resources.read_text(template_package, 'pads.sv.mako')
                          ).render(dir/"src", logger=logger, padframe=padframe, pad_domain=pad_domain, header_text=header_text)
        TemplateRenderJob(name=f'Internal package for {pad_domain.name}',
                          target_file_name=f'pkg_internal_{padframe.name}_{pad_domain.name}.sv',
                          template=resources.read_text(template_package, 'pkg_pad_domain_internals.sv.mako')
                          ).render(dir/"src", logger=logger, padframe=padframe, pad_domain=pad_domain, header_text=header_text)
        TemplateRenderJob(name=f'Pad Multiplexer for {pad_domain.name}',
                          target_file_name=f'{padframe.name}_{pad_domain.name}_muxer.sv',
                          template=resources.read_text(template_package, 'pad_multiplexer.sv.mako')
                          ).render(dir/"src", logger=logger, padframe=padframe, pad_domain=pad_domain,
                                   debug_render=True, header_text=header_text)
        TemplateRenderJob(name=f'Register File Specification for {pad_domain.name}',
                          target_file_name=f'{padframe.name}_{pad_domain.name}_regs.hjson',
                          template=resources.read_text(template_package, 'regfile.hjson.mako')
                          ).render(dir/"src", logger=logger, padframe=padframe, pad_domain=pad_domain,
                                   start_address_offset=hex(next_pad_domain_reg_offset), header_text=header_text)


        # Generate Register file using lowRisc reg_tool
        logger.debug("Invoking reggen to generate register file from Register file description")
        hjson_reg_file = dir/"src"/f"{padframe.name}_{pad_domain.name}_regs.hjson"
        try:
            obj = hjson.loads(hjson_reg_file.read_text(), use_decimal=True,
                              object_pairs_hook=reggen_validate.checking_dict)
        except ValueError as e:
            logger.error(f"Fatal error while parsing auto generated register file for pad_domain {pad_domain.name}.")
            raise RTLGenException(f"Error parsing regfile.") from e
        error_count = reggen_validate.validate(obj)
        address_ranges[pad_domain.name] = (next_pad_domain_reg_offset, obj["gennextoffset"])
        next_pad_domain_reg_offset = obj["gennextoffset"]
        address_space_size = next_pad_domain_reg_offset-4
        if error_count != 0:
            logger.error(f"Validation of auto generated register file configuration failed.")
            raise RTLGenException("Reggen Validation failed")
        return_code = reggen_gen_rtl.gen_rtl(obj, (dir/"src").as_posix())
        if return_code != 0 and not (return_code is None):
            logger.error(f"Regtool template rendering of register file for pad domain {pad_domain.name} failed")
            raise RTLGenException("Reggen Rendering failed")

    TemplateRenderJob(name='Padframe Top Module',
                      target_file_name='{padframe.name}.sv',
                      template=resources.read_text(template_package, 'padframe.sv.mako')
                      ).render(dir / "src", logger=logger, padframe=padframe, address_ranges=address_ranges,
                               address_space_size=address_space_size, header_text=header_text)

    TemplateRenderJob(name=f'Bender.yml Project file',
                      target_file_name="Bender.yml",
                      template=resources.read_text(template_package, 'Bender.yml.mako')
                      ).render(dir, logger=logger, padframe=padframe, header_text=header_text)
    TemplateRenderJob(name=f'IPApprox src_files.yml',
                      target_file_name="src_files.yml",
                      template=resources.read_text(template_package, 'src_files.yml.mako')
                      ).render(dir, logger=logger, padframe=padframe, header_text=header_text)
    TemplateRenderJob(name=f'IPApprox ips_list.yml',
                      target_file_name="ips_list.yml",
                      template=resources.read_text(template_package, 'ips_list.yml.mako')
                      ).render(dir, logger=logger, padframe=padframe, header_text=header_text)





