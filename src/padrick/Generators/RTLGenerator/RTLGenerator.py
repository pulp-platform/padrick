from pathlib import Path
import logging
import click_log
from Model.Padframe import Padframe
from mako.template import Template
from importlib.resources import read_text

logger = logging.getLogger(__name__)
click_log.basic_config(logger)


def generate_packages(padframe: Padframe, dir: Path):
    for pad_domain in padframe.pad_domains:
        logger.debug(f"Generating SV packages for pad_domain {pad_domain}")
        #Generate pad signal package
        pkg_pads_path = dir/f"pkg_{pad_domain.name}_pads.sv"
        with pkg_pads_path.open(mode='w+') as f:
            tp = Template(read_text('Generators.RTLGenerator', 'pkg_pads.sv.mako'))
            print(tp.render(domain=pad_domain))

def generate_rtl(padframe: Padframe, dir: Path):
    generate_packages(padframe, dir)