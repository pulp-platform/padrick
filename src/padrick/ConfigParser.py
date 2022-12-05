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

from pathlib import Path
import logging
from typing import List, Union, Tuple, Mapping, Type, TypeVar

import click
import click_log
from pydantic import ValidationError, BaseModel
from ruamel.yaml.comments import CommentedMap
from yamlinclude import YamlIncludeConstructor

logger = logging.getLogger("padrick.ConfigParser")
click_log.basic_config(logger)
from ruamel.yaml import YAMLError
import ruamel.yaml




def get_error_context(config_file: Path, line, column, context_before=4, context_after=4):
    lines_to_return = []
    with config_file.open() as file:
        for line_idx, l in enumerate(file.readlines()):
            if line_idx + 1 == line:
                lines_to_return.append(l)
                lines_to_return.append(click.style(column * " " + "^\n", blink=True, fg='yellow'))
            elif line_idx + 1 >= line - context_before and line_idx + 1 <= line + context_after:
                lines_to_return.append(l)
    return "".join(lines_to_return)


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


def get_file_location(config_data: CommentedMap, error_location: List[Union[str, int]]) -> Tuple[
    Tuple[int, int], Mapping]:
    node = config_data
    location = (node.lc.line + 1, node.lc.col)
    subtree = node
    for path_segment in error_location:
        try:
            location = (node.lc.data[path_segment][0] + 1, node.lc.data[path_segment][1])
            node = node[path_segment]
            if isinstance(node, Mapping):
                subtree = node
        except:
            break
    return location, subtree


T = TypeVar('T', bound=BaseModel)

def parse_config(cls: T, config_file: Path) -> Union[T, None]:
    with config_file.open() as file:
        try:
            yaml = ruamel.yaml.YAML(typ='rt')
            # enable support for !include directives (see pyyaml-include package)
            include_constructor = YamlIncludeConstructor(base_dir=str(config_file.parent))
            yaml.register_class(include_constructor)
            config_data = yaml.load(file)
            #config_data = ruamel.yaml.load(file, Loader=ruamel.yaml.RoundTripLoader)
        except YAMLError as e:
            logger.error(f"Error while parsing config_file:\n{e}")
            return None
        try:
            model = cls.parse_obj(config_data)
            return model
        except ValidationError as e:
            logger.error(f"Encountered {len(e.errors())} validation errors while parsing the configuration file:")
            for error in e.errors():
                if error['type'] == 'value_error.extra':
                    error['msg'] = f'Unknown field {error["loc"][-1]}. Did you mispell the field name?'
                if error['type'] == 'value_error.missing':
                    error['msg'] = f'Missing field \'{error["loc"][-1]}\''
                # error_path = get_human_readable_error_path(config_data, error["loc"])
                (line, column), subtree = get_file_location(config_data, error["loc"])
                error_context = get_error_context(config_file, line, column, context_after=10)
                logger.error(f"Line {line}, Column {column}:")
                logger.error(f"...\n{error_context}\n...")
                logger.error(f"Error: {error['msg']}")
            return None
