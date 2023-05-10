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

import csv
import logging
import os
from importlib import resources
from pathlib import Path

from padrick.Generators.GeneratorSettings import DocTemplates
from padrick.Generators.PadrickTemplate import PadrickTemplate
from padrick.Model.PadInstance import PadInstance
from padrick.Model.Padframe import Padframe
from plumbum import local, CommandNotFound

logger = logging.getLogger("padrick.DocGenerator")

template_package = 'padrick.Generators.DocGenerator.Templates'

class DocGenException(Exception):
    pass

def generate_padmux_illustration(templates: DocTemplates, padframe: Padframe, dir: Path, header_text: str, **kwargs):
    logger.info("Generating Graphviz dot file...")
    templates.mux_graph.render(dir, logger=logger, padframe=padframe, header_text = header_text, **kwargs)
    logger.info(f"Dot file rendered successfully in {dir/templates.mux_graph.target_file_name.format(padframe=padframe)}")
    logger.info("Rendering PDF using graphviz...")
    try:
        dot_cmd = local.get("dot")
        (dot_cmd["-Tpdf", str(dir/templates.mux_graph.target_file_name.format(padframe=padframe))] > f"{padframe.name}_muxing.pdf") ()
    except CommandNotFound:
        logger.error("Could not find graphviz dot command in your path. Is it installed?")
def generate_padlist(padframe: Padframe, dir: Path):
    os.makedirs(dir, exist_ok=True)
    output_file_path = dir/f"{padframe.name}.csv"

    with  output_file_path.open("w", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=["pad_nr", "pad_name", "type"])
        writer.writeheader()
        pad_index = 0
        for pad_domain in padframe.pad_domains:
            for pad in pad_domain.pad_list:
                pad: PadInstance
                for i in range(pad.multiple):
                    suffix = str(i) if pad.multiple > 1 else ""
                    row = {'pad_nr': pad_index,
                           'pad_name': pad.name+suffix,
                           'type': pad.pad_type.name}
                    pad_index += 1
                    writer.writerow(row)
