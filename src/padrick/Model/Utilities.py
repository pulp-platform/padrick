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

from typing import Iterable, List, Optional, Dict, Union

from natsort import natsorted

from padrick.Model.TemplatedString import TemplatedStringType


def sort_signals(seq: Iterable['Signal']):
    return natsorted(seq, key=lambda x: x.name)


def sort_ports(seq: Iterable['Port']):
    return natsorted(seq, key=lambda x: x.name)


def sort_pads(seq: Iterable['PadInstance']):
    return natsorted(seq, key=lambda x: x.name)


def cached_property(func):
    @property
    def wrapper(self, *args, **kwargs):
        if not hasattr(self, '_method_cache'):
            raise RuntimeError(f"Object of type {self.__class__.__name__} has _method_cache attribute.")
        if func.__name__ not in self._method_cache:
            self._method_cache[func.__name__] =  func(self, *args, **kwargs)
        return self._method_cache[func.__name__]

    return wrapper