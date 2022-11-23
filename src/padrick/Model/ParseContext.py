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

from typing import Set, Mapping, Union, List


class ParseContext:
    _current_pad_domain: 'PadDomain'
    _pad_types: Mapping[str, 'PadType'] = {}

    def set_context(self, ctx: 'PadDomain'):
        self._current_pad_domain = ctx
        self._pad_types = {}

    def register_pad_type(self, pad_type: 'PadType'):
        self._pad_types[pad_type.name] = pad_type

    def find_pad_type(self, name: str) -> Union['PadType', None]:
        return self._pad_types.get(name, None)

    def find_pad_signal_instances(self, name: str) -> List[Union['Signal']]:
        pad_signal_references = []
        for pad_type in self._pad_types.values():
            for pad_signal in pad_type.pad_signals:
                if pad_signal.name == name:
                    pad_signal_references.append(pad_signal)
        return pad_signal_references

PARSE_CONTEXT = ParseContext()
