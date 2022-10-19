import importlib.resources as resources
import logging
import os
import shutil
from pathlib import Path
from typing import Tuple, Mapping

import click_log
import hjson

from padrick.Generators.GeneratorSettings import DriverTemplates
from padrick.Generators.PadrickTemplate import PadrickTemplate
from padrick.Model import Constants
from padrick.Model.Padframe import Padframe
from reggen import gen_cheader as reggen_gen_header
from reggen import validate as reggen_validate
from reggen.ip_block import IpBlock

logger = logging.getLogger("padrick.DriverGenerator")
click_log.basic_config(logger)

rtl_template_package = 'padrick.Generators.RTLGenerator.Templates'
template_package = 'padrick.Generators.DriverGenerator.Templates'


class DriverGenException(Exception):
    pass

def generate_driver(templates:DriverTemplates, padframe: Padframe, dir: Path,  header_text: str):
    os.makedirs(dir/"src", exist_ok=True)
    os.makedirs(dir/"include", exist_ok=True)
    next_pad_domain_reg_offset = 0 # Offset of the first register of the current pad_frame's register file. All
    address_ranges: Mapping[str, Tuple[int, int]] = {} # dictionary of pad_domain to start- end-address tupple
    for pad_domain in padframe.pad_domains:
        templates.regfile_hjson.render(dir, logger=logger, padframe=padframe, pad_domain=pad_domain,
                                   start_address_offset=hex(next_pad_domain_reg_offset), header_text=header_text,
                                   hw_version=Constants.HARDWARE_VERSION)

        logger.debug("Invoking reggen to generate C header file for the padframe configuration registers.")
        hjson_reg_file = dir/f"{padframe.name}_{pad_domain.name}_regs.hjson"
        try:
            obj = IpBlock.from_path(str(hjson_reg_file), [])
        except ValueError as e:
            logger.error(f"Fatal error while parsing auto generated register file for pad_domain {pad_domain.name}.")
            raise DriverGenException(f"Error parsing regfile.") from e
        address_ranges[pad_domain.name] = (next_pad_domain_reg_offset, obj.reg_blocks[None].offset)
        next_pad_domain_reg_offset = obj.reg_blocks[None].offset
        address_space_size = next_pad_domain_reg_offset-4
        output_file = dir/f"include/{padframe.name}_{pad_domain.name}_regs.h"
        with output_file.open('w') as f:
            return_code = reggen_gen_header.gen_cdefines(obj, f, "", "")
        if return_code != 0 and not (return_code is None):
            logger.error(f"Regtool template rendering of register file header for pad domain {pad_domain.name} failed")
            raise DriverGenException("Reggen header file rendering failed")

    templates.driver_header.render(dir / 'include', logger, padframe, header_text=header_text)
    templates.driver_source.render(dir/'src', logger, padframe, header_text=header_text)
    with open(dir/'include'/'bitfield.h', 'w') as f:
        f.write(resources.read_text(template_package, 'bitfield.h'))
