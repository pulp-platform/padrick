# Copyright 2021-2022 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Manuel Eggimann, ETH Zurich

from enum import Enum
from typing import Optional, Set, Dict, Union
from padrick.Model.Constants import SYSTEM_VERILOG_IDENTIFIER
from padrick.Model.SignalExpressionType import SignalExpressionType

from pydantic import model_validator, Field, ConfigDict, BaseModel, constr, validator, PrivateAttr

from padrick.Model.TemplatedIdentifier import TemplatedIdentifierType
from padrick.Model.UserAttrs import UserAttrs
from typing_extensions import Annotated


class PadSignalKind(str, Enum):
    input = "input"
    output = "output"
    pad = "pad"

class SignalDirection(str, Enum):
    soc2pads= "soc2pads"
    pads2soc = "pads2soc"
    bidir = "bidir"

class ConnectionType(str, Enum):
    static = "static"
    dynamic = "dynamic"

class Signal(BaseModel):
    name: TemplatedIdentifierType
    size: Annotated[int, Field(ge=1, le=32)] = 1
    _direction: Optional[SignalDirection] = PrivateAttr(None)

    def __init__(self, direction=None, *values, **kwargs):
        super().__init__(*values, **kwargs)
        self._direction = direction

    def __eq__(self, other):
        if isinstance(other, Signal):
            return self.name == other.name and self.size == other.size and self.direction == other.direction
        else:
            raise NotImplemented
    @property
    def direction(self):
        return self._direction

    def __hash__(self):
        return hash((self.name, self.size, self.direction))

class PadSignal(Signal):
    description: Optional[str] = None
    kind: PadSignalKind
    conn_type: Optional[ConnectionType] = None
    and_override_signal: SignalExpressionType = SignalExpressionType("")
    or_override_signal: SignalExpressionType = SignalExpressionType("")
    default_reset_value: Optional[int] = None
    default_static_value: Optional[SignalExpressionType] = None
    _static_signals: Set[Signal] = PrivateAttr(default=set())
    user_attr: Optional[UserAttrs] = None

    @property
    def direction(self):
        if self.kind == PadSignalKind.input:
            return SignalDirection.soc2pads
        elif self.kind == PadSignalKind.output:
            return SignalDirection.pads2soc
        else:
            return SignalDirection.bidir
    model_config = ConfigDict(extra="forbid")

    @model_validator(mode='after')
    def must_contain_conn_type_unsless_kind_pad(self):
        if self.kind != PadSignalKind.pad and not self.conn_type:
            raise ValueError("All Padsignals except the ones of kind 'pad' must contain a 'conn_type'")
        return self

    @model_validator(mode='after')
    def must_not_contain_default_value_if_landing_pad(self):
        if self.kind == PadSignalKind.pad:
            if self.default_reset_value:
                raise ValueError("Padsignals of kind 'pad' must not contain a default reset value.")
            if self.default_static_value:
                raise ValueError("Padsignals of kind 'pad' must not contain a default static value.")
        return self

    @model_validator(mode='after')
    def validate_output_pad(self):
        if self.kind == PadSignalKind.output:
            if self.default_reset_value != None:
                raise ValueError("Padsignals of kind 'output' must not contain a reset value.")
            if not self.default_static_value:
                self.default_static_value = SignalExpressionType("")
            else:
                if not self.default_static_value.is_single_signal:
                    raise ValueError("Padsignals of kind 'output' must not have complex expression as "
                                     "default_static_value. Only single signal identifiers or the empty expression is allowed.")
                if not self.and_override_signal.is_empty:
                    raise ValueError("Padsignals of kind 'output' must not have override signals.")
                if not self.or_override_signal.is_empty:
                    raise ValueError("Padsignals of kind 'output' must not have override signals.")
        return self

    @model_validator(mode='after')
    def must_contain_default_values_if_kind_input(self):
        if self.kind == PadSignalKind.input:
            if self.default_reset_value == None:
                raise ValueError("Padsignals of kind 'input' must specify a default reset value")
            if self.default_static_value == None:
                raise ValueError("Padsignals of kind 'input' must specify a default static value")
        return self


    @property
    def static_signals(self):
        static_signals = set()
        if self.and_override_signal:
            for signal_name in self.and_override_signal.signal_collection:
                static_signals.add(Signal(signal_name, self.size))
        if self.or_override_signal:
            for signal_name in self.or_override_signal.signal_collection:
                static_signals.add(Signal(signal_name, self.size))
        if self.default_reset_value:
            for signal_name in self.default_reset_value.signal_collection:
                static_signals.add(Signal(signal_name, self.size))
        if self.default_static_value:
            for signal_name in self.default_static_value.signal_collection:
                static_signals.add(Signal(signal_name, self.size))
        return static_signals

