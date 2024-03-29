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
import os
from importlib import resources
from pathlib import Path

from padrick.Generators.PadrickTemplate import PadrickTemplate
from padrick.Model.PadInstance import PadInstance
from padrick.Model.Padframe import Padframe

template_package = 'padrick.Generators.DocGenerator.Templates'

class DocGenException(Exception):
    pass


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
