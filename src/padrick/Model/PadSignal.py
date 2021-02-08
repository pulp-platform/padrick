from enum import Enum
from typing import Optional, Set
from Model.Constants import SYSTEM_VERILOG_IDENTIFIER
from Model.SignalExpressionType import SignalExpressionType

from pydantic import BaseModel, constr, conint, validator, PrivateAttr, root_validator, Extra


class PadSignalKind(str, Enum):
    input = "input"
    output = "output"
    pad = "pad"

class ConnectionType(str, Enum):
    static = "static"
    dynamic = "dynamic"

class Signal(BaseModel):
    name: constr(regex=SYSTEM_VERILOG_IDENTIFIER)
    size: conint(ge=1) = 1

    def __eq__(self, other):
        if isinstance(other, Signal):
            return self.name == other.name and self.size == other.size
        else:
            raise NotImplemented

    def __hash__(self):
        return hash((self.name, self.size))

class PadSignal(Signal):
    kind: PadSignalKind
    description: Optional[str]
    conn_type: Optional[ConnectionType]
    and_override_signal: Optional[SignalExpressionType]
    or_override_signal: Optional[SignalExpressionType]
    default_reset_value: Optional[SignalExpressionType]
    default_static_value: Optional[SignalExpressionType]
    _static_signals: Set[Signal] = PrivateAttr(default=set())

    #pydantic model config
    class Config:
        extra = Extra.forbid

    @validator('default_reset_value')
    def must_be_const_expr(cls, v: SignalExpressionType, values):
        if values['conn_type'] != ConnectionType.dynamic:
            raise ValueError(f'Cannot combine default_reset_value with connection type {values["conn_type"]}.')
        if not v.is_const_expr:
            raise ValueError(f"The default_reset_value must be a constant expression. Expr: {v.expression} contains "
                             f"references to signals {v.signal_collection}")
        return v

    @validator('default_static_value')
    def must_be_combined_with_conn_type_static(cls, v: SignalExpressionType, values):
        if values['conn_type'] != ConnectionType.static:
            raise ValueError(f'Cannot combine default_static_value with connection type {values["conn_type"]}.')
        return v

    @root_validator(skip_on_failure=True)
    def validate_reset_values(cls, values):
        if values['kind'] == PadSignalKind.pad and (values['default_reset_value'] or values['default_static_value']):
            raise ValueError("Padsignals of kind 'pad must not have a default_static_value or default_reset_value")
        if values['conn_type'] == ConnectionType.dynamic:
            if values['kind'] == PadSignalKind.output and values.get('default_reset_value'):
                raise ValueError(f"Padsignal of kind 'output' must not have a default_reset_value")
            elif values['kind'] == PadSignalKind.input and  not values.get('default_reset_value'):
                raise ValueError(f"Missing key default_reset_value for pad_signal of connection type {values['conn_type']}")
        elif values['conn_type'] == ConnectionType.static and not values.get('default_static_value'):
            raise ValueError(f"Missing key default_statci_value for pad_signal of connection type"
                             f" {values['conn_type']}")
        return values

    @root_validator(skip_on_failure=True)
    def must_contain_conn_type_unsless_kind_pad(cls, values):
        if values['kind'] != PadSignalKind.pad and not values['conn_type']:
            raise ValueError("All Padsignals except the ones of kind 'pad' must contain a 'conn_type'")
        return values


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

