# Copyright 2021-2022 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Manuel Eggimann, ETH Zurich

from typing import Optional, List, Dict, Union

from padrick.Model.Constants import SYSTEM_VERILOG_IDENTIFIER
from padrick.Model.ParseContext import PARSE_CONTEXT
from padrick.Model.PadSignal import PadSignal, PadSignalKind
from mako import exceptions
from mako.template import Template
from pydantic import field_validator, StringConstraints, ConfigDict, BaseModel, conlist, Field

from padrick.Model.UserAttrs import UserAttrs
from typing_extensions import Annotated


class PadType(BaseModel):
    """A pad type describes one IO cell flavor from your library, characterized by its instantiation
    template and the set of pad signals used to control it."""
    name: Annotated[str, StringConstraints(pattern=SYSTEM_VERILOG_IDENTIFIER), Field(description="Name of "
        "the pad type. Referenced by pad instances via their pad_type key and must be unique.")]
    description: Optional[str] = Field(default=None, description="Optional short description of the pad type.")
    template: str = Field(description="Mako template that describes how to instantiate this pad cell in the "
        "generated RTL. The variables 'instance_name' and the 'conn' dictionary (keyed by pad signal name) "
        "are available during rendering.")
    pad_signals: List[PadSignal] = Field(default=[], description="List of all pad signals used to control "
        "this pad type, including the chip-to-pad and pad-to-chip signals, the bonding-pad signal and any "
        "configuration signals. A signal of kind 'pad' produces a toplevel landing-pad port; pad types "
        "without one are legal: an empty list declares a physical-only cell (supply, corner, tie) whose "
        "template is emitted verbatim, and padless cells with signals (e.g. supply-sense outputs) connect "
        "those signals without exposing a pad.")
    user_attr: Optional[UserAttrs] = Field(default=None, description="Optional custom key-value pairs that "
        "are also exposed during template rendering.")
    model_config = ConfigDict(extra="forbid")

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        PARSE_CONTEXT.register_pad_type(self)

    @field_validator('template')
    @classmethod
    def check_valid_mako_template(cls, v):
        try:
            return Template(v)
        except:
            raise ValueError(f"Illegal Mako template provided: {exceptions.text_error_template().render()}")

    @field_validator('name')
    @classmethod
    def check_unique_padtype_name(cls, v):
        if PARSE_CONTEXT.find_pad_type(v):
#        if v in PARSE_CONTEXT.pad_type_registry:
            raise ValueError(f"Double declaration of pad_type {v}. PadType names must be unique.")
        else:
            return v

    def get_pad_signal(self, name: str) -> PadSignal:
        for pad_signal in self.pad_signals:
            if pad_signal.name == name:
                return pad_signal
        raise ValueError(f"Did not find  Pad Signal {name} in scope of Pad Type {self.name}")
