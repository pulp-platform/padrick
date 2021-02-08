from pathlib import Path
import logging
from typing import List, Union

import click_log
from pydantic import ValidationError

logger = logging.getLogger(__name__)
click_log.basic_config(logger)
import yaml

from Model.Padframe import Padframe

def get_human_readable_error_path(config_data: dict, error_location: List[Union[str, int]]):
    transformed_path_segments = []
    node = config_data
    for path_segment in error_location:
        try:
            node = node[path_segment]
        except:
            transformed_path_segments.append(path_segment)
            break
        if isinstance(path_segment, int):
            transformed_path_segments.append(node.get('name', path_segment))
        else:
            transformed_path_segments.append(path_segment)
    return "->".join(transformed_path_segments)



def parse_config(config_file: Path) -> Padframe:
    with config_file.open() as file:
        try:
            config_data = yaml.full_load(file)
        except yaml.YAMLError as e:
            logger.error(f"Error while parsing config_file:\n{e}")
        try:
            padframe_model = Padframe.parse_obj(config_data)
            return padframe_model
        except ValidationError as e:
            logger.error(f"Encountered {len(e.errors())} validation errors while parsing the configuration file:")
            for error in e.errors():
                if error['type'] == 'value_error.extra':
                    error['msg'] = f'Unknown field {error["loc"][-1]}. Did you mispell the field name?'
                error_path = get_human_readable_error_path(config_data, error["loc"])
                logger.error(f"""{error_path}:
                                     {error["msg"]}""")
            return None


