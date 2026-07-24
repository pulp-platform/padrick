# Copyright 2021-2022 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Manuel Eggimann, ETH Zurich
from typing import Dict, Union, Optional, Mapping

from pydantic import RootModel

from padrick.Model.TemplatedString import TemplatedStringType


class UserAttrs(RootModel):
    root: Mapping[TemplatedStringType, Union['UserAttrs', int, bool, TemplatedStringType]]

    def __iter__(self):
        return iter(self.root)

    def __getitem__(self, item):
        return self.root[item]

    def items(self):
        return self.root.items()

    def values(self):
        return self.root.values()

    def keys(self):
        return self.root.keys()

    def expand_user_attrs(self, i: int) -> Dict[str, Union[str, int, bool]]:
        rendered_attrs = {}
        for key, value in self.items():
            rendered_key = key.evaluate_template(i)
            if isinstance(value, TemplatedStringType):
                rendered_attrs[rendered_key] = value.evaluate_template(i)
            elif isinstance(value, UserAttrs):
                rendered_attrs[rendered_key] = value.expand_user_attrs(i)
            else:
                rendered_attrs[rendered_key] = value
        return rendered_attrs
