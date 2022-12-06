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
from typing import Dict, Union, Optional, Mapping

from pydantic import BaseModel

from padrick.Model.TemplatedString import TemplatedStringType


class UserAttrs(BaseModel):
    __root__: Mapping[TemplatedStringType, Union['UserAttrs', int, bool, TemplatedStringType]]

    def __iter__(self):
        return iter(self.__root__)

    def __getitem__(self, item):
        return self.__root__[item]

    def items(self):
        return self.__root__.items()

    def values(self):
        return self.__root__.values()

    def keys(self):
        return self.__root__.keys()

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
