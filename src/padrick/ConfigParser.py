# Copyright 2021-2022 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Manuel Eggimann, ETH Zurich
from pathlib import Path
import logging
import sys
from typing import List, Union, Tuple, Mapping, Type, TypeVar, Optional

import click
from pydantic import ValidationError, BaseModel
from ruamel.yaml.comments import CommentedMap
from padrick.YamlInclude import YamlIncludeConstructor, IgnoreIncludeConstructor
from padrick.Logging import configure_logging

logger = logging.getLogger("padrick.ConfigParser")
configure_logging()
from ruamel.yaml import YAMLError
import ruamel.yaml




def get_error_context(config_file: Path, line, column, context_before=4, context_after=4):
    if sys.stderr.isatty():
        return _rich_error_context(config_file, line, column, context_before, context_after)
    lines_to_return = []
    with config_file.open() as file:
        for line_idx, l in enumerate(file.readlines()):
            if line_idx + 1 == line:
                lines_to_return.append(l)
                lines_to_return.append(click.style(column * " " + "^\n", blink=True, fg='yellow'))
            elif line_idx + 1 >= line - context_before and line_idx + 1 <= line + context_after:
                lines_to_return.append(l)
    return "".join(lines_to_return)


def _rich_error_context(config_file: Path, line, column, context_before, context_after):
    """Render the offending YAML excerpt with syntax highlighting for terminals."""
    import io
    from rich.console import Console
    from rich.syntax import Syntax
    first = max(1, line - context_before)
    with config_file.open() as file:
        excerpt = "".join(file.readlines()[first - 1:line + context_after])
    console = Console(file=io.StringIO(), force_terminal=True, width=120)
    console.print(Syntax(excerpt, "yaml", line_numbers=True, start_line=first,
                         highlight_lines={line}))
    return console.file.getvalue()


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

def parse_config(cls: T, config_file: Path, include_base_dir: Optional[Path] = None, ignore_includes = False,
                 errors_out: Optional[List[dict]] = None) -> Union[T, None]:
    """
    Parse and validate a config file; on failure, log errors and optionally
    collect machine-readable error dicts into errors_out.
    """
    with config_file.open() as file:
        try:
            yaml = ruamel.yaml.YAML(typ='rt')
            if not include_base_dir:
                include_base_dir = config_file.parent
            if not ignore_includes:
                include_constructor = YamlIncludeConstructor(base_dir=str(include_base_dir))
            else:
                include_constructor = IgnoreIncludeConstructor
            yaml.register_class(include_constructor)
            config_data = yaml.load(file)
        except YAMLError as e:
            logger.error(f"Error while parsing config_file:\n{e}")
            if errors_out is not None:
                errors_out.append({"type": "yaml_error", "msg": str(e), "loc": [], "line": None, "column": None})
            return None
        try:
            model = cls.model_validate(config_data)
            return model
        except ValidationError as e:
            logger.error(f"Encountered {len(e.errors())} validation errors while parsing the configuration file:")
            for error in e.errors():
                if error['type'] == 'extra_forbidden':
                    error['msg'] = f'Unknown field {error["loc"][-1]}. Did you mispell the field name?'
                if error['type'] == 'missing':
                    error['msg'] = f'Missing field \'{error["loc"][-1]}\''
                (line, column), subtree = get_file_location(config_data, error["loc"])
                error_context = get_error_context(config_file, line, column, context_after=10)
                logger.error(f"Line {line}, Column {column}:")
                logger.error(f"...\n{error_context}\n...")
                logger.error(f"Error: {error['msg']}")
                if errors_out is not None:
                    errors_out.append({"type": error['type'], "msg": error['msg'],
                                       "loc": list(error['loc']), "line": line, "column": column})
            return None
