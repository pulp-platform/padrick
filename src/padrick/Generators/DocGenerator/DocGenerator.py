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
