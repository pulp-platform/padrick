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
import os
from pathlib import Path
import click_log

from padrick.Generators.ConstraintsGenerator.ConstraintsSpec import ConstraintsSpec, ConstraintsMode
from padrick.Generators.GeneratorSettings import ConstraintsTemplates
from padrick.Model.Padframe import Padframe

logger = logging.getLogger("padrick.ConstraintsGenerator")
click_log.basic_config(logger)

template_package = 'padrick.Generators.RTLGenerator.Templates'

def generate_constraints(templates: ConstraintsTemplates, padframe: Padframe, constraints_spec: ConstraintsSpec, dir: Path, header_text: str):
    os.makedirs(dir, exist_ok=True)
    for constraints_mode in constraints_spec.modes:
        templates.case_analysis.render(dir, logger=logger, padframe=padframe, header_text=header_text, constraints_mode=constraints_mode)
