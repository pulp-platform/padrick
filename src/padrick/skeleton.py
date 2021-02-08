# -*- coding: utf-8 -*-
"""
This is a skeleton file that can serve as a starting point for a Python
console script. To run this script uncomment the following lines in the
[options.entry_points] section in setup.cfg:

    console_scripts =
         fibonacci = padrick.skeleton:run

Then run `python setup.py install` which will install the command `fibonacci`
inside your current environment.
Besides console scripts, the header (i.e. until _logger...) of this file can
also be used as template for Python modules.

Note: This skeleton file can be safely removed if not needed!
"""

import logging
from pathlib import Path

import yaml
from Model.Padframe import Padframe

from padrick import __version__

__author__ = "Manuel Eggimann"
__copyright__ = "Manuel Eggimann"
__license__ = "apache"

_logger = logging.getLogger(__name__)

if __name__ == "__main__":
    sample_config = Path('../../examples/sample_padframe.yaml')
    with sample_config.open() as config_file:
        configuration = yaml.full_load(config_file)
        pad_frame = Padframe.parse_obj(configuration)
        print(pad_frame)