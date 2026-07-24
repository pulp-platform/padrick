# Copyright 2026 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Kai Berszin, ETH Zurich

from glob import iglob
from pathlib import Path
from typing import Any, List, Optional, Union

import ruamel.yaml

WILDCARD_CHARS = ("*", "?", "[")


class YamlIncludeConstructor:
    """
    Constructor for the custom '!include <path>' YAML tag.

    The path is resolved relative to base_dir and may contain shell-style
    wildcards; a wildcard include yields the list of all matched documents.
    Included files may themselves contain '!include' tags.
    """
    yaml_tag = '!include'

    def __init__(self, base_dir: Optional[str] = None):
        self.__name__ = self.yaml_tag
        self.base_dir = base_dir

    def from_yaml(self, constructor: ruamel.yaml.Constructor, node: Any) -> Any:
        if not isinstance(node, ruamel.yaml.ScalarNode):
            raise ruamel.yaml.YAMLError(
                f"!include only supports a scalar file path, got {node!r}")
        pathname = constructor.construct_scalar(node)
        if self.base_dir:
            pathname = str(Path(self.base_dir) / pathname)
        if any(c in pathname for c in WILDCARD_CHARS):
            matches = sorted(iglob(pathname, recursive=True))
            if not matches:
                raise ruamel.yaml.YAMLError(
                    f"!include pattern {pathname} does not match any file")
            return [self._load_file(m) for m in matches]
        return self._load_file(pathname)

    def to_yaml(self, representer: ruamel.yaml.Representer, node: Any) -> None:
        raise ruamel.yaml.YAMLError("Cannot dump included content back to file.")

    def _load_file(self, pathname: Union[str, Path]) -> Any:
        yaml = ruamel.yaml.YAML(typ='rt')
        yaml.register_class(self)
        with open(pathname) as f:
            return yaml.load(f)


class IgnoreIncludeConstructor:
    """Drop-in for YamlIncludeConstructor that ignores all includes."""
    yaml_tag = '!include'

    @classmethod
    def from_yaml(cls, constructor: ruamel.yaml.Constructor, node: Any) -> str:
        return f"Ignored include: {node}"

    @classmethod
    def to_yaml(cls, representer: ruamel.yaml.Representer, node: Any) -> Any:
        return representer.represent_str(node)
