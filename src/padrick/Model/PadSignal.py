from enum import Enum
from typing import Optional, Set
from Model.Constants import SYSTEM_VERILOG_IDENTIFIER
from Model.SignalExpressionType import SignalExpressionType

from pydantic import BaseModel, constr, conint, validator, PrivateAttr, root_validator, Extra

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
    name: constr(regex=SYSTEM_VERILOG_IDENTIFIER)
    size: conint(ge=1) = 1
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
    description: Optional[str]
    kind: PadSignalKind
    conn_type: Optional[ConnectionType]
    and_override_signal: SignalExpressionType = SignalExpressionType("")
    or_override_signal: SignalExpressionType = SignalExpressionType("")
    default_reset_value: Optional[SignalExpressionType]
    default_static_value: Optional[SignalExpressionType]
    _static_signals: Set[Signal] = PrivateAttr(default=set())

    @property
    def direction(self):
        if self.kind == PadSignalKind.input:
            return SignalDirection.soc2pads
        elif self.kind == PadSignalKind.output:
            return SignalDirection.pads2soc
        else:
            return SignalDirection.bidir

    #pydantic model config
    class Config:
        extra = Extra.forbid

    @validator('default_reset_value')
    def must_be_const_expr(cls, v: SignalExpressionType):
        if v and not v.is_const_expr:
            raise ValueError(f"The default_reset_value must be a constant expression. Expr: {v.expression} contains "
                             f"references to signals {v.signal_collection}")
        return v

    @root_validator(skip_on_failure=True)
    def must_contain_conn_type_unsless_kind_pad(cls, values):
        if values['kind'] != PadSignalKind.pad and not values['conn_type']:
            raise ValueError("All Padsignals except the ones of kind 'pad' must contain a 'conn_type'")
        return values

    @root_validator(skip_on_failure=True)
    def must_not_contain_default_value_if_landing_pad(cls, values):
        if values['kind'] == PadSignalKind.pad:
            if values.get('default_reset_value', None):
                raise ValueError("Padsignals of kind 'pad' must not contain a default reset value.")
            if values.get('default_static_value', None):
                raise ValueError("Padsignals of kind 'pad' must not contain a default static value.")
        return values

    @root_validator(skip_on_failure=True)
    def validate_output_pad(cls, values):
        if values['kind'] == PadSignalKind.output:
            if values.get('default_reset_value', None):
                raise ValueError("Padsignals of kind 'output' must not contain a reset value.")
            if not values.get('default_static_value'):
                values['default_static_value'] = SignalExpressionType("")
            else:
                if not values['default_static_value'].is_single_signal:
                    raise ValueError("Padsignals of kind 'output' must not have complex expression as "
                                     "default_static_value. Only single signal identifiers or the empty expression is allowed.")
                if not values['and_override_signal'].is_empty:
                    raise ValueError("Padsignals of kind 'output' must not have override signals.")
                if not values['or_override_signal'].is_empty:
                    raise ValueError("Padsignals of kind 'output' must not have override signals.")
        return values

    @root_validator(skip_on_failure=True)
    def must_contain_default_values_if_kind_input(cls, values):
        if values['kind'] == PadSignalKind.input:
            if not values.get('default_reset_value', None):
                raise ValueError("Padsignals of kind 'input' must specify a default reset value")
            if not values.get('default_static_value', None):
                raise ValueError("Padsignals of kind 'input' must specify a default static value")
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

