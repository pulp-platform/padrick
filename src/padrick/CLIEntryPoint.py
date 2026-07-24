# Copyright 2021-2022 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Manuel Eggimann, ETH Zurich

import logging
import os
import sys
import time
import traceback
from pathlib import Path

from mako.template import Template

import padrick.Generators.CLIGeneratorCommands
import rich_click as click
import json

from padrick.Generators.FuseSoCGenerator.FuseSoCGenerator import generate_core
from padrick.Generators.GeneratorSettings import RTLTemplates
from padrick.Generators.RTLGenerator.RTLGenerator import generate_rtl
from padrick.Generators import CLIGeneratorCommands
from padrick.ConfigParser import parse_config
from padrick.Logging import configure_logging, reserve_stdout_for_data, verbosity_option
from padrick.Model.Padframe import Padframe
from padrick.Model.PadSignal import Signal
from padrick.Model.SignalExpressionType import SignalExpressionType
from pydantic import BaseModel

logger = logging.getLogger("padrick")
configure_logging()

_CONTEXT_SETTINGS = dict(help_option_names=['-h', '--help'])

@click.group(context_settings=_CONTEXT_SETTINGS)
@click.version_option()
def cli():
    """
    Generate padframes for SoC
    """

_COMPLETION_SNIPPETS = {
    'bash': 'eval "$(_PADRICK_COMPLETE=bash_source padrick)"',
    'zsh': 'eval "$(_PADRICK_COMPLETE=zsh_source padrick)"',
    'fish': '_PADRICK_COMPLETE=fish_source padrick | source',
}

_COMPLETION_RC_FILES = {
    'bash': '~/.bashrc',
    'zsh': '~/.zshrc',
    'fish': '~/.config/fish/completions/padrick.fish',
}


@cli.command()
@click.argument('shell', required=False, type=click.Choice(sorted(_COMPLETION_SNIPPETS)))
def install_completions(shell):
    """Print the shell completion snippet for your shell (bash, zsh or fish).

    If you don't provide a SHELL argument the current shell is detected from the $SHELL
    environment variable. Add the printed snippet to your shell's startup file to enable
    tab-completion for padrick."""
    if not shell:
        shell = Path(os.environ.get('SHELL', '')).name
    if shell not in _COMPLETION_SNIPPETS:
        raise click.UsageError(
            f"Could not determine a supported shell (got '{shell or 'unknown'}'). "
            f"Pass one of {', '.join(sorted(_COMPLETION_SNIPPETS))} explicitly.")
    click.echo(f"# Add the following line to {_COMPLETION_RC_FILES[shell]} to enable padrick {shell} completion:")
    click.echo(_COMPLETION_SNIPPETS[shell])

@cli.command()
@click.argument('file', type=click.Path(dir_okay=False, file_okay=True, exists=True, readable=True))
@click.option('--format', 'output_format', type=click.Choice(['text', 'json']), default='text',
              show_default=True, help="Output format; json prints a machine-readable result to stdout.")
@verbosity_option
def validate(file, output_format):
    """ Parse and validate the given config file
    """
    if output_format == 'json':
        reserve_stdout_for_data()
    errors = []
    model = parse_config(Padframe, Path(file), errors_out=errors)
    if output_format == 'json':
        click.echo(json.dumps({"valid": model is not None, "errors": errors}, indent=2))
        if model is None:
            sys.exit(1)
    elif model != None:
        click.echo(f"Successfully parsed configuration file.")
    else:
        click.echo(f"Error while parsing configuration file {file}")
        sys.exit(1)


@cli.command()
@click.option('-o', '--output', type=click.Path(dir_okay=False, writable=True),
              help="Write the schema to this file instead of stdout.")
def schema(output):
    """Print the JSON Schema of the padframe configuration file format.

    Reference it from a config file via a yaml-language-server directive to get
    completion and validation while editing:

    # yaml-language-server: $schema=padrick_schema.json"""
    text = json.dumps(Padframe.model_json_schema(), indent=2)
    if output:
        Path(output).write_text(text + "\n")
        click.echo(f"Schema written to {output}")
    else:
        click.echo(text)

@cli.command()
@click.argument('file', type=click.Path(dir_okay=False, file_okay=True, exists=True, readable=True))
@verbosity_option
def config(file):
    """ Print the parsed padframe configuration file """
    model = parse_config(Padframe, Path(file))
    if model != None:
        class ModelEncoder(json.JSONEncoder):
            def default(self, o):
                return str(o)
            def sanitize(self, o):
                if isinstance(o, list):
                    return [self.sanitize(v) for v in o]
                if isinstance(o, tuple):
                    return tuple([self.sanitize(v) for v in o])
                elif isinstance(o, dict):
                    return {self.sanitize(key): self.sanitize(v) for key, v in o.items()}
                elif isinstance(o, Template):
                    return o.source
                elif isinstance(o, SignalExpressionType):
                    if o.is_empty:
                        return None
                    else:
                        return o.expression
                elif isinstance(o, Signal):
                    return o.name
                elif isinstance(o, BaseModel):
                    return {name: self.sanitize(getattr(o, name)) for name in type(o).model_fields}
                else:
                    return o
            def encode(self, o):
                return super().encode(self.sanitize(o))
        click.echo(json.dumps(model, cls=ModelEncoder, indent=4))
    else:
        click.echo(f"Error while parsing configuration file {file}")
        sys.exit(1)

@cli.command()
@click.argument('config_file', type=click.Path(dir_okay=False, file_okay=True, exists=True, readable=True))
def fusesoc_gen(config_file):
    """Generator invocation for FuseSoC.

    Parses the supplied config_file command and generates RTL + Core files in the current direcotry.
    Check the documentation for more information about available FuseSoC Generator parameters.
    """
    click.echo("Padrick started in FuseSoC generator mode.")
    generate_core(Path(config_file))
    click.echo("Finished core generation")

# Register first level subcommand
cli.add_command(padrick.Generators.CLIGeneratorCommands.generate)

# For debugging purposes only
if __name__ == '__main__':
    #cli(['rosetta', '-o' 'test.avc', 'write-mem', '0x1c008080=0xdeadbeef'])
    # while True:
        cli(['generate', 'template-customization'])
        cli(['generate', '-s', 'padrick_gen_settings.yml', 'rtl'])
        config_file = '../../examples/siracusa_pads.yml'
        output = '/home/meggiman/garbage/test_padrick_siracusa'
        try:
            padframe = parse_config(Padframe, Path(config_file))
            if padframe:
                generate_rtl(RTLTemplates(), padframe, Path(output), header_text="")
                print("Generated RTL")
        except Exception as e:
            traceback.print_exc()
            pass
        # time.sleep(5)
    #cli(['config', '../../examples/kraken_padframe.yml'])