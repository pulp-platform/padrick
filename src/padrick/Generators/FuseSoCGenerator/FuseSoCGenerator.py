import logging
from pathlib import Path

import click_spinner
from click import UsageError
from mako import exceptions
from mako.template import Template

from padrick.ConfigParser import parse_config
from padrick.Generators.FuseSoCGenerator.FuseSoCGeneratorConfigFileModel import ConfigFileModel, GeneratorKind, \
    RTLGenerateStep, CustomGenerateStep
from padrick.Generators.GeneratorSettings import GeneratorSettings
from padrick.Generators.RTLGenerator.RTLGenerator import generate_rtl
from padrick.Model.Padframe import Padframe
from padrick.Utils.WorkingDir import working_dir

logger = logging.getLogger("padrick.FuseSoCGenerator")


def generate_core(config_file_path: Path):
    """Parses the config file supplied by FuseSoC to generate
    a valid FuseSoC core config file."""


    logger.info("Parsing FuseSoC Config File...")
    with click_spinner.spinner():
        # Parse the config file twice, first only partially to figure out the root file path, then a second time with
        # support include files, relative to the calling core file.
        config = parse_config(ConfigFileModel, config_file_path)
        root =  config.files_root
        if not config:
            raise UsageError("Failed to parse the configuration file")
        padframe_config = parse_config(Padframe, root/config.parameters.padframe_manifest, include_base_dir=config.files_root)
        if not padframe_config:
            raise UsageError("Failed to parse the padframe configuration file.")
        if config.parameters.generator_settings:
            generator_settings = parse_config(GeneratorSettings, root/config.parameters.generator_settings, include_base_dir=config.files_root)
            if not generator_settings:
                raise UsageError("Failed to parse generator settings file.")
        else:
            generator_settings = GeneratorSettings()


    logger.info("Parsing successful. Proceeding with generate steps...")
    for step in config.parameters.generate_steps:
        logger.info(f"Processing {step}")
        if isinstance(step, RTLGenerateStep):
            generate_rtl(generator_settings.rtl_templates, padframe_config, header_text="", dir=Path("."), vlnv=config.vlnv)
        elif isinstance(step, CustomGenerateStep):
            try:
                mk_template = Template(Path(config.files_root)/step.template_file)
                step.output_filename.write_text(mk_template.render(padframe=padframe_config, vlnv=config.vlnv))
            except Exception as e:
                logger.error(f"Error while rendering custom template:\
                                        n{exceptions.text_error_template().render()}")
