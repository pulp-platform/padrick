from pathlib import Path

import click
import click_log
import yaml
from ConfigParser import parse_config
from Generators.RTLGenerator import RTLGenerator
from Generators.RTLGenerator.RTLGenerator import generate_rtl
import logging

from click import UsageError

logger = logging.getLogger("padrick")
click_log.basic_config(logger)


@click.group()
def generate():
    """ Generate various output files for the provided pad_frame configuration"""
    pass

@generate.command()
@click.argument('config_file', type=click.Path(file_okay=True, dir_okay=False, exists=True, readable=True))
@click.option('-o', '--output', type=click.Path(dir_okay=True, file_okay=False), default=".", help="Location where to save the RTL")
@click_log.simple_verbosity_option(logger)
def rtl(config_file, output):
    """
    Generate SystemVerilog implementation from the padframe configuration.
    """
    logger.info("Parsing configuration file...")
    padframe = parse_config(Path(config_file))
    if not padframe:
        raise UsageError("Failed to parse the configuration file")
    generate_rtl(padframe, Path(output))