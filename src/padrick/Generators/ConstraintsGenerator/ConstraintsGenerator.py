# Copyright 2021-2022 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Manuel Eggimann, ETH Zurich

import logging
import os
from pathlib import Path
import click_log

from padrick.Generators.ConstraintsGenerator.ConstraintsSpec import ConstraintsSpec, ConstraintsMode
from padrick.Generators.GeneratorSettings import ConstraintsTemplates
from padrick.Model.Padframe import Padframe

logger = logging.getLogger("padrick.ConstraintsGenerator")
click_log.basic_config(logger)

template_package = 'padrick.Generators.RTLGenerator.Templates'

def generate_constraints(templates: ConstraintsTemplates, padframe: Padframe, constraints_spec: ConstraintsSpec, dir: Path, header_text: str, **extra_template_kwargs):
    os.makedirs(dir, exist_ok=True)
    for constraints_mode in constraints_spec.modes:
        templates.case_analysis.render(dir, logger=logger, padframe=padframe, header_text=header_text, constraints_mode=constraints_mode, **extra_template_kwargs)
