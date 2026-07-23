# Copyright 2021-2022 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Manuel Eggimann, ETH Zurich

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