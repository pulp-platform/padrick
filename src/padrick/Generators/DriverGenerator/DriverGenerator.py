import importlib.resources as resources
import logging
import os
from pathlib import Path
from typing import Tuple, Mapping

import click_log
import hjson
from padrick.Generators.TemplateRenderJob import TemplateRenderJob
from padrick.Model.Padframe import Padframe
from reggen import gen_ctheader as reggen_gen_header
from reggen import validate as reggen_validate

logger = logging.getLogger("padrick.DriverGenerator")
click_log.basic_config(logger)

rtl_template_package = 'padrick.Generators.RTLGenerator.Templates'
template_package = 'padrick.Generators.DriverGenerator.Templates'


class DriverGenException(Exception):
    pass

def generate_driver(padframe: Padframe, dir: Path):
    os.makedirs(dir/"src", exist_ok=True)
    os.makedirs(dir/"include", exist_ok=True)
    next_pad_domain_reg_offset = 0 # Offset of the first register of the current pad_frame's register file. All
    address_ranges: Mapping[str, Tuple[int, int]] = {} # dictionary of pad_domain to start- end-address tupple
    for pad_domain in padframe.pad_domains:
        TemplateRenderJob(name=f'Register File Specification for {pad_domain.name}',
                          target_file_name=f'{padframe.name}_{pad_domain.name}_regs.hjson',
                          template=resources.read_text(rtl_template_package, 'regfile.hjson.mako')
                          ).render(dir, logger=logger, padframe=padframe, pad_domain=pad_domain,
                                   start_address_offset=hex(next_pad_domain_reg_offset))

        logger.debug("Invoking reggen to generate C header file for the padframe configuration registers.")
        hjson_reg_file = dir/f"{padframe.name}_{pad_domain.name}_regs.hjson"
        try:
            obj = hjson.loads(hjson_reg_file.read_text(), use_decimal=True,
                              object_pairs_hook=reggen_validate.checking_dict)
        except ValueError as e:
            logger.error(f"Fatal error while parsing auto generated register file config for pad_domain {pad_domain.name}.")
            raise DriverGenException(f"Error parsing regfile.") from e
        error_count = reggen_validate.validate(obj)
        address_ranges[pad_domain.name] = (next_pad_domain_reg_offset, obj["gennextoffset"])
        next_pad_domain_reg_offset = obj["gennextoffset"]
        address_space_size = next_pad_domain_reg_offset-4
        if error_count != 0:
            logger.error(f"Validation of auto generated register file configuration failed.")
            raise DriverGenException("Reggen Validation failed")
        output_file = dir/f"include/{padframe.name}_{pad_domain.name}_regs.h"
        with output_file.open('w') as f:
            return_code = reggen_gen_header.gen_cdefines(obj, f, "", "")
        if return_code != 0 and not (return_code is None):
            logger.error(f"Regtool template rendering of register file header for pad domain {pad_domain.name} failed")
            raise DriverGenException("Reggen header file rendering failed")

    TemplateRenderJob(name="Driver header file",
                      target_file_name=f"{padframe.name}.h",
                      template=resources.read_text(template_package,'driver.h.mako')
                      ).render(dir/'include', logger, padframe)
    TemplateRenderJob(name="Driver implementation file",
                      target_file_name=f"{padframe.name}.c",
                      template=resources.read_text(template_package, 'driver.c.mako')
                      ).render(dir/'src', logger, padframe)