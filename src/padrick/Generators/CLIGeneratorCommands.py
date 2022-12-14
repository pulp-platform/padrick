# Manuel Eggimann <meggimann@iis.ee.ethz.ch>
#
# Copyright (C) 2021-2022 ETH Zürich
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import logging
from dataclasses import astuple
from importlib import resources
from pathlib import Path
from typing import Tuple

import click
import click_log
from ruamel.yaml import YAMLError, YAML
from mako import exceptions
from mako.template import Template

from padrick.Generators.ConstraintsGenerator.ConstraintsGenerator import generate_constraints
from padrick.Generators.ConstraintsGenerator.ConstraintsSpec import ConstraintsGenException, ConstraintsSpec
from padrick.Generators.GeneratorSettings import GeneratorSettings, RTLTemplates, DriverTemplates, DocTemplates
from padrick.Model.Padframe import Padframe

yaml = YAML()


import padrick
from padrick.ConfigParser import parse_config
from padrick.Generators.DocGenerator.DocGenerator import generate_padlist, DocGenException
from padrick.Generators.DriverGenerator.DriverGenerator import generate_driver
from padrick.Generators.RTLGenerator.RTLGenerator import generate_rtl, RTLGenException
from padrick.Generators.PadrickTemplate import TemplateRenderException, PadrickTemplate
from click import UsageError, ClickException
import click_spinner
import os

logger = logging.getLogger("padrick")
click_log.basic_config(logger)

pass_generator_settings = click.make_pass_decorator(GeneratorSettings, ensure=True)

@click.group()
@click.option('-s','--generator_settings_file', type=click.Path(file_okay=True, dir_okay=False, exists=True, readable=True), help="A yaml file containing custom settings for the generate command.")
@click.pass_context
def generate(ctx, generator_settings_file: str):
    """ Generate various output files for the provided pad_frame configuration"""
    if generator_settings_file:
        generator_settings = parse_config(GeneratorSettings, Path(generator_settings_file))
        if not generator_settings:
            raise click.UsageError("Failed to parse generator settings file.")
        else:
            ctx.obj = generator_settings

@generate.command()
@click.option('-o', '--output', type=click.Path(dir_okay=True, file_okay=False), default=".", help="Location where to save the RTL")
def template_customization(output):
    """
    Generate a padrick_gen_settings.yml file and folder structure containing copies of all internal Mako templates for customization of the generated file formats.

    This is an advanced feature and allows the user to customize the internal Mako templates used to generate the various export files. In order for the customize option
    to have any effect, you need to invoke the generate commands with the additional -s flag:
    e.g.: padrick generate -s padrick_gen_settings.yml rtl my_padframe.yml

    The -s option needs to come before the subcommand (in this case 'rtl').
    """
    default_settings = GeneratorSettings()
    rtl_templates_dir = Path(output)/"rtl_templates"
    driver_templates_dir = Path(output)/"driver_templates"
    doc_templates_dir = Path(output)/"doc_templates"
    constraints_templates_dir = Path(output)/"constraints_templates"
    os.makedirs(rtl_templates_dir, exist_ok=True)
    os.makedirs(driver_templates_dir, exist_ok=True)
    os.makedirs(doc_templates_dir, exist_ok=True)
    os.makedirs(constraints_templates_dir, exist_ok=True)
    for _,template in default_settings.rtl_templates:
        if isinstance(template, PadrickTemplate):
            template_file_name = rtl_templates_dir/template.template.resource
            with template_file_name.open('w') as tf:
                tf.write(resources.read_text(template.template.package, template.template.resource))
                template.template = str(template_file_name)
    for _,template in default_settings.driver_templates:
        if isinstance(template, PadrickTemplate):
            template_file_name = driver_templates_dir / template.template.resource
            with template_file_name.open('w') as tf:
                tf.write(resources.read_text(template.template.package, template.template.resource))
                template.template = str(template_file_name)
    for _,template in default_settings.doc_templates:
        if isinstance(template, PadrickTemplate):
            template_file_name = doc_templates_dir / template.template.resource
            with template_file_name.open('w') as tf:
                tf.write(resources.read_text(template.template.package, template.template.resource))
                template.template = str(template_file_name)
    for _,template in default_settings.constraints_templates:
        if isinstance(template, PadrickTemplate):
            template_file_name = constraints_templates_dir / template.template.resource
            with template_file_name.open('w') as tf:
                tf.write(resources.read_text(template.template.package, template.template.resource))
                template.template = str(template_file_name)
    with (Path(output)/"padrick_generator_settings.yml").open("w") as settings_file:
        yaml.dump(default_settings.dict(), settings_file)




@generate.command()
@click.argument('config_file', type=click.Path(file_okay=True, dir_okay=False, exists=True, readable=True))
@click.option('-o', '--output', type=click.Path(dir_okay=True, file_okay=False), default=".", help="Location where to save the RTL")
@click.option('--header', type=click.Path(dir_okay=False, file_okay=True, exists=True), help="A text file who's content (extended with appropriate comment characters) is inserted as the header in each auto-generated file. "
                                                                                             "Useful for copyright and author information.")
@click.option('--version-string/--no-version-string', default=True, show_default=True, help="Append current version of padrick to the header of each generated file.")
@click_log.simple_verbosity_option(logger)
@pass_generator_settings
def rtl(generator_settings: GeneratorSettings, config_file: str, output: str, header, version_string):
    """
    Generate SystemVerilog implementation from the padframe configuration.
    """
    logger.info("Parsing configuration file...")
    with click_spinner.spinner():
        padframe = parse_config(Padframe, Path(config_file))
    if not padframe:
        raise UsageError("Failed to parse the configuration file")

    logger.info("Parsing successful. Generating RTL...")
    if not Path(output).exists():
        logger.debug("Output directory does not exist. Creating new one.")
        os.makedirs(output, exist_ok=True)

    header_sections = []
    if version_string:
        header_sections.append(f"File auto-generated by Padrick {padrick.__version__}")

    if header:
        logger.debug(f"Using text in {header} for headers.")
        header_sections.append(Path(header).read_text())


    header_text = "\n\n".join(header_sections)
    with click_spinner.spinner():
        try:
            generate_rtl(generator_settings.rtl_templates, padframe, Path(output), header_text)
        except (RTLGenException, TemplateRenderException) as e:
            raise ClickException("RTL Generation failed") from e
        except Exception as e:
            logger.error("Padrick crashed while generating RTL :-(")
            raise e
        logger.info(f"Successfully generated RTL files in {output}")

@generate.command()
@click.argument('config_file', type=click.Path(file_okay=True, dir_okay=False, exists=True, readable=True))
@click.option('-o', '--output', type=click.Path(dir_okay=True, file_okay=False), default=".", help="Location where to save the driver")
@click.option('--header', type=click.Path(dir_okay=False, file_okay=True, exists=True), help="A text file who's content (extended with appropriate comment characters) is inserted as the header in each auto-generated file. "
                                                                                             "Useful for copyright and author information.")
@click.option('--version-string/--no-version-string', default=True, show_default=True, help="Append current version of padrick to the header of each generated file.")
@click_log.simple_verbosity_option(logger)
@pass_generator_settings
def driver(generator_settings: GeneratorSettings, config_file: str, output: str, header, version_string):
    """
    Generate C driver to interact with the padframe.
    """
    logger.info("Parsing configuration file...")
    with click_spinner.spinner():
        padframe = parse_config(Padframe, Path(config_file))
    logger.info("Parsing successful. Generating C-Driver...")
    if not Path(output).exists():
        logger.debug("Output directory does not exist. Creating new one.")
        os.makedirs(output, exist_ok=True)
    if not padframe:
        raise UsageError("Failed to parse the configuration file")
    header_sections = []
    if version_string:
        header_sections.append(f"File auto-generated by Padrick {padrick.__version__}")

    if header:
        logger.debug(f"Using text in {header} for headers.")
        header_sections.append(Path(header).read_text())

    header_text = "\n\n".join(header_sections)
    with click_spinner.spinner():
        try:
            generate_driver(generator_settings.driver_templates, padframe, Path(output), header_text)
        except (RTLGenException, TemplateRenderException) as e:
            raise ClickException("C Driver Generation failed") from e
        except Exception as e:
            logger.error("Padrick crashed while generating the C Driver :-(")
            raise e
        logger.info(f"Successfully generated C driver files in {output}")

@generate.command()
@click.argument('config_file', type=click.Path(file_okay=True, dir_okay=False, exists=True, readable=True))
@click.argument('constraints_spec_file', type=click.Path(file_okay=True, dir_okay=False, exists=True, readable=True))
@click.option('-o', '--output', type=click.Path(dir_okay=True, file_okay=False), default=".", help="Directory where to save the SDC files")
@click.option('--header', type=click.Path(dir_okay=False, file_okay=True, exists=True), help="A text file who's content (extended with appropriate comment characters) is inserted as the header in each auto-generated file. "
                                                                                             "Useful for copyright and author information.")
@click.option('--version-string/--no-version-string', default=True, show_default=True, help="Append current version of padrick to the header of each generated file.")
@click_log.simple_verbosity_option(logger)
@pass_generator_settings
def constraints(generator_settings: GeneratorSettings, config_file: str, constraints_spec_file: str, output: str, version_string: bool, header: str):
    """
    Generate an SDC constraints file with set_case_analysis on all configuration registers of the padmultiplexer.

    The generated SDC file is usefull in constraining the padmultiplexer to only consider a fixed static configuration
    to prevent STA from considering all possible multiplex configurations.

    On top of the usual pad configuration file (CONFIG_FILE), this command accepts a case specification file as the second argument
    that specifies to which values the different multiplex registers shall be constrained to.
    """

    header_sections = []
    if version_string:
        header_sections.append(f"File auto-generated by Padrick {padrick.__version__}")

    if header:
        logger.debug(f"Using text in {header} for headers.")
        header_sections.append(Path(header).read_text())

    header_text = "\n\n".join(header_sections)
    logger.info("Parsing configuration files...")
    with click_spinner.spinner():
        constraints_specs: ConstraintsSpec = parse_config(ConstraintsSpec, Path(constraints_spec_file))
        padframe = parse_config(Padframe, Path(config_file))
    if not padframe or not constraints_specs:
        raise click.UsageError("Failed to parse configuration file.")

    try:
        constraints_specs.link_with_pad_domain(padframe)
    except ConstraintsGenException as e:
        logger.error(e)
        raise ClickException("Constraints Spec parsing failed") from e

    logger.info("Parsing successful. Generating constraints file...")
    if not Path(output).exists():
        logger.debug("Output directory does not exist. Creating new one.")
        os.makedirs(output, exist_ok=True)
    with click_spinner.spinner():
        try:
            generate_constraints(generator_settings.constraints_templates, padframe, constraints_specs, Path(output), header_text=header_text)
        except (ConstraintsGenException, TemplateRenderException) as e:
            raise ClickException("Constraints generation failed") from e
        except Exception as e:
            logger.error("Padrick crashed while generating the constraints :-(")
            raise e
        logger.info(f"Successfully generated constraints.")


@generate.command()
@click.argument('config_file', type=click.Path(file_okay=True, dir_okay=False, exists=True, readable=True))
@click.option('-o', '--output', type=click.Path(dir_okay=True, file_okay=False), default=".", help="Directory where to save the padlist CSV")
@click_log.simple_verbosity_option(logger)
@pass_generator_settings
def padlist(generator_settings: GeneratorSettings, config_file: str, output: str):
    """
    Generate a CSV file that lists all pads in your configuration.
    """
    logger.info("Parsing configuration file...")
    with click_spinner.spinner():
        padframe = parse_config(Padframe, Path(config_file))
    logger.info("Parsing successful. Generating pad list...")
    if not Path(output).exists():
        logger.debug("Output directory does not exist. Creating new one.")
        os.makedirs(output, exist_ok=True)
    if not padframe:
        raise UsageError("Failed to parse the configuration file")

    with click_spinner.spinner():
        try:
            generate_padlist(padframe, Path(output))
        except (DocGenException, TemplateRenderException) as e:
            raise ClickException("Padlist Generation failed") from e
        except Exception as e:
            logger.error("Padrick crashed while generating the padlist :-(")
            raise e
        logger.info(f"Successfully generated the padlist CSV file in {output}")


@generate.command()
@click.argument('config_file', type=click.Path(file_okay=True, dir_okay=False, exists=True, readable=True))
@click.argument('template', type=click.File(mode='r'))
@click.argument('output', type=click.File(mode='w'))
@click_log.simple_verbosity_option(logger)
def custom(config_file:str, template, output):
    """
    Render a user-specified custom Mako Template TEMPLATE file using the parsed CONFIG_FILE pad configuration data.

    This command is usefull for any kind of desired output format for which Padrick doesn't already ship with the
    right template. The rendered template will be printed to OUTPUT. Both TEMPLATE and OUTPUT accept either a path to
    a file or the special argument '-' to read from/write to stdin/stdout.
    """
    logger.info("Parsing configuration file...")
    with click_spinner.spinner():
        padframe = parse_config(Padframe, Path(config_file))
    if not padframe:
        raise UsageError("Failed to parse the configuration file")
    logger.info("Parsing successful.")
    logger.info("Rendering custom template")
    try:
        mk_template = Template(template.read())
        output.write(mk_template.render(padframe=padframe))
    except Exception as e:
        logger.error(f"Error while rendering custom template for padframe {padframe.name}:\
                            n{exceptions.text_error_template().render()}")