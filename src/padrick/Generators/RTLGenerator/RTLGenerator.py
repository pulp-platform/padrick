from dataclasses import dataclass
from pathlib import Path
import logging
import click_log
from Generators.TemplateRenderJob import TemplateRenderJob
from Model.Padframe import Padframe
from mako.template import Template
import importlib.resources as resources
from mako import exceptions

logger = logging.getLogger("padrick.RTLGenerator")
click_log.basic_config(logger)

def generate_rtl(padframe: Padframe, dir: Path):
    TemplateRenderJob(name='SV package',
                      target_file_name='pkg_{padframe.name}.sv',
                      template=resources.read_text('Generators.RTLGenerator', 'pkg_padframe.sv.mako')
                      ).render(dir, logger=logger, padframe=padframe)
    TemplateRenderJob(name='Padframe module',
                      target_file_name='{padframe.name}.sv',
                      template=resources.read_text('Generators.RTLGenerator', 'padframe.sv.mako')
                      ).render(dir, logger=logger, padframe=padframe)
    for pad_domain in padframe.pad_domains:
        TemplateRenderJob(name=f'Paddomain module {pad_domain.name}',
                          target_file_name=f'{padframe.name}_{pad_domain.name}.sv',
                          template=resources.read_text('Generators.RTLGenerator', 'pad_domain.sv.mako')
                          ).render(dir, logger=logger, padframe=padframe, pad_domain=pad_domain)
        TemplateRenderJob(name=f'Pad instantiation module {pad_domain.name}',
                          target_file_name=f'{padframe.name}_{pad_domain.name}.sv',
                          template=resources.read_text('Generators.RTLGenerator', 'pads.sv.mako')
                          ).render(dir, logger=logger, padframe=padframe, pad_domain=pad_domain)