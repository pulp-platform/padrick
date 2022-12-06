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

from typing import Optional, List, Dict, Union

from padrick.Model.Constants import SYSTEM_VERILOG_IDENTIFIER
from padrick.Model.ParseContext import PARSE_CONTEXT
from padrick.Model.PadSignal import PadSignal, PadSignalKind
from mako import exceptions
from mako.template import Template
from pydantic import BaseModel, constr, validator, conlist, Extra

from padrick.Model.UserAttrs import UserAttrs


class PadType(BaseModel):
    name: constr(regex=SYSTEM_VERILOG_IDENTIFIER)
    description: Optional[str]
    template: str
    pad_signals: List[PadSignal] = []
    user_attr: Optional[UserAttrs]

    #pydantic model config
    class Config:
        extra = Extra.forbid
        underscore_attrs_are_private = True

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        PARSE_CONTEXT.register_pad_type(self)

    @validator('template')
    def check_valid_mako_template(cls, v):
        try:
            return Template(v)
        except:
            raise ValueError(f"Illegal Mako template provided: {exceptions.text_error_template().render()}")

    @validator('name')
    def check_unique_padtype_name(cls, v):
        if PARSE_CONTEXT.find_pad_type(v):
#        if v in PARSE_CONTEXT.pad_type_registry:
            raise ValueError(f"Double declaration of pad_type {v}. PadType names must be unique.")
        else:
            return v

    @validator('pad_signals')
    def must_contain_at_least_one_landing_pad(cls, v: List[PadSignal]) ->List[PadSignal]:
        if not [pad_signal for pad_signal in v if pad_signal.kind == PadSignalKind.pad]:
            raise ValueError("Each IO Pad Type must contain at least one Pad Signal of kind 'pad'")
        return v

    def get_pad_signal(self, name: str) -> PadSignal:
        for pad_signal in self.pad_signals:
            if pad_signal.name == name:
                return pad_signal
        raise ValueError(f"Did not find  Pad Signal {name} in scope of Pad Type {self.name}")
