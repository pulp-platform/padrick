import importlib.resources as resources
import logging
from pathlib import Path

import click_log
import hjson
from padrick.Generators.TemplateRenderJob import TemplateRenderJob
from padrick.Model.Padframe import Padframe
from reggen import gen_rtl as reggen_gen_rtl
from reggen import validate as reggen_validate

logger = logging.getLogger("padrick.RTLGenerator")
click_log.basic_config(logger)

class RTLGenException(Exception):
    pass

def generate_rtl(padframe: Padframe, dir: Path):
    TemplateRenderJob(name='SV package',
                      target_file_name='pkg_{padframe.name}.sv',
                      template=resources.read_text('padrick.Generators.RTLGenerator.Templates', 'pkg_padframe.sv.mako')
                      ).render(dir, logger=logger, padframe=padframe)
    TemplateRenderJob(name='Padframe module',
                      target_file_name='{padframe.name}.sv',
                      template=resources.read_text('padrick.Generators.RTLGenerator.Templates', 'padframe.sv.mako')
                      ).render(dir, logger=logger, padframe=padframe)
    for pad_domain in padframe.pad_domains:
        TemplateRenderJob(name=f'Paddomain module {pad_domain.name}',
                          target_file_name=f'{padframe.name}_{pad_domain.name}.sv',
                          template=resources.read_text('padrick.Generators.RTLGenerator.Templates', 'pad_domain.sv.mako')
                          ).render(dir, logger=logger, padframe=padframe, pad_domain=pad_domain)
        TemplateRenderJob(name=f'Pad instantiation module {pad_domain.name}',
                          target_file_name=f'{padframe.name}_{pad_domain.name}_pads.sv',
                          template=resources.read_text('padrick.Generators.RTLGenerator.Templates', 'pads.sv.mako')
                          ).render(dir, logger=logger, padframe=padframe, pad_domain=pad_domain)
        TemplateRenderJob(name=f'Internal package for {pad_domain.name}',
                          target_file_name=f'pkg_internal_{padframe.name}_{pad_domain.name}.sv',
                          template=resources.read_text('padrick.Generators.RTLGenerator.Templates', 'pkg_pad_domain_internals.sv.mako')
                          ).render(dir, logger=logger, padframe=padframe, pad_domain=pad_domain)
        TemplateRenderJob(name=f'Register File Specification for {pad_domain.name}',
                          target_file_name=f'{padframe.name}_regs.hjson',
                          template=resources.read_text('padrick.Generators.RTLGenerator.Templates', 'regfile.hjson.mako')
                          ).render(dir, logger=logger, padframe=padframe, pad_domain=pad_domain)

        # Generate Register file using lowRisc reg_tool
        logger.debug("Invoking reggen to generate register file from Register file description")
        hjson_reg_file = dir/f"{padframe.name}_regs.hjson"
        try:
            obj = hjson.loads(hjson_reg_file.read_text(), use_decimal=True,
                              object_pairs_hook=reggen_validate.checking_dict)
        except ValueError as e:
            logger.error(f"Fatal error while parsing auto generated register file for pad_domain {pad_domain.name}.")
            raise RTLGenException(f"Error parsing regfile.") from e
        error_count = reggen_validate.validate(obj)
        if error_count != 0:
            logger.error(f"Validation of auto generated register file configuration failed.")
            raise RTLGenException("Reggen Validation failed")
        return_code = reggen_gen_rtl.gen_rtl(obj, dir.as_posix())
        if return_code != 0:
            logger.error(f"Regtool template rendering of register file for pad domain {pad_domain.name} failed")
            raise RTLGenException("Reggen Rendering failed")





