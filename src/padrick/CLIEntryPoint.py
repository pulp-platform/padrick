import logging
import time
from pathlib import Path

import padrick.Generators.CLIGeneratorCommands
import click
import click_completion
import click_log
from padrick.Generators.RTLGenerator.RTLGenerator import generate_rtl
from padrick.Generators import CLIGeneratorCommands
from padrick.ConfigParser import parse_config

logger = logging.getLogger("padrick")
click_log.basic_config(logger)

click_completion.init()
_CONTEXT_SETTINGS = dict(help_option_names=['-h', '--help'])

@click.group(context_settings=_CONTEXT_SETTINGS)
def cli():
    """
    Generate padframes for SoC
    """

@cli.command()
@click.option('--append/--overwrite', help="Append the completion code to the file", default=None)
@click.option('-i', '--case-insensitive/--no-case-insensitive', help="Case insensitive completion")
@click.argument('shell', required=False, type=click_completion.DocumentedChoice(click_completion.core.shells))
@click.argument('path', required=False)
def install_completions(append, case_insensitive, shell, path):
    """Install the command line tool's bash completion for your shell

    If you don't provide any additional arguments this command tries to detect your current shell in use and appends the relevant settings to your .bashrc, .zshrc etc."""
    extra_env = {'_CLICK_COMPLETION_COMMAND_CASE_INSENSITIVE_COMPLETE': 'ON'} if case_insensitive else {}
    shell, path = click_completion.core.install(shell=shell, path=path, append=append, extra_env=extra_env)
    click.echo('%s completion installed in %s' % (shell, path))

@cli.command()
@click.argument('file', type=click.Path(dir_okay=False, file_okay=True, exists=True, readable=True))
@click_log.simple_verbosity_option(logger)
def validate(file):
    """ Parse and validate the given config file
    """
    model = parse_config(Path(file))
    if model != None:
        click.echo(f"Successfully parsed configuration file.")
    else:
        click.echo(f"Error while parsing configuration file {file}")

# Register first level subcommand
#cli.add_command(Rosetta.rosetta)
#cli.add_command(Vega.vega)
cli.add_command(padrick.Generators.CLIGeneratorCommands.generate)

# For debugging purposes only
if __name__ == '__main__':
    #cli(['rosetta', '-o' 'test.avc', 'write-mem', '0x1c008080=0xdeadbeef'])
    while True:
        config_file = '../../examples/sample_padframe.yaml'
        output = '/home/meggiman/garbage/test_padrick'
        try:
            padframe = parse_config(Path(config_file))
            generate_rtl(padframe, Path(output))
            print("Generated RTL")
        except Exception as e:
            print(e)
            pass
        time.sleep(1)

    cli(['generate', 'rtl',  '-v' 'INFO', '-o', '/home/meggiman/garbage/test_padrick',
             '../../examples/sample_padframe.yaml'])
    #cli(['generate', 'rtl', '-h'])