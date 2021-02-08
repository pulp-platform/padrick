from typing import Optional, Mapping, List, Union, Set

from Model.Constants import SYSTEM_VERILOG_IDENTIFIER
from Model.ParseContext import PARSE_CONTEXT
from Model.PadSignal import PadSignal, ConnectionType, PadSignalKind, Signal
from Model.PadType import PadType
from Model.SignalExpressionType import SignalExpressionType
from pydantic import BaseModel, constr, validator, root_validator, Extra, conint


class PadInstance(BaseModel):
    name: constr(regex=SYSTEM_VERILOG_IDENTIFIER)
    description: Optional[str]
    multiple: conint(ge=1) = 1
    pad_type: Union[constr(regex=SYSTEM_VERILOG_IDENTIFIER), PadType]
    is_static: bool = False
    connections: Optional[Mapping[Union[PadSignal, str], Optional[SignalExpressionType]]]

    #pydantic model config
    class Config:
        extra = Extra.forbid

    @validator('pad_type')
    def lookup_pad_type(cls, v: Union[PadType, str]) -> PadType:
        if isinstance(v, PadType):
            return v
        pad_type = PARSE_CONTEXT.find_pad_type(v)
        if not pad_type:
            raise ValueError(f"Unknown pad_type {v}. Did you mispell the pad_type or forgot to declare it?")
        else:
            return pad_type

    @validator('connections')
    def link_and_validate_connections(cls, v: Mapping[str, SignalExpressionType], values):
        linked_connections = {}
        for pad_signal_name, expression in v.items():
            # Create a copy of the pad signal instance so we can override its connection_type according to the
            # is_static override value
            if 'pad_type' not in values:
                raise ValueError("Missing pad_type for pad_instance")
            pad_signal = values['pad_type'].get_pad_signal(pad_signal_name).copy() #This will raise a ValueError if
            # the # pad signal does not exist
            if values['is_static']: pad_signal.conn_type = ConnectionType.static

            # Only for input pad_signals it is allowed to have an empty expression (-> leave unconnected) as the
            # expression
            if pad_signal.kind != PadSignalKind.input and not expression:
                raise ValueError(f"Cannot leave pad_signal {pad_signal.name} of kind {pad_signal.kind} unconnected. "
                                 f"Please provide a connection expression")

            # Replace expression of type None with empty expression instance
            if not expression:
                expression = SignalExpressionType.validate(None)
            # If the pad_signal is of conn_type dynamic, make sure the expression is a const_expression
            if pad_signal.conn_type == ConnectionType.dynamic:
                if not (expression or expression.is_const_expr):
                    raise ValueError(f"Pad Signal connections expression for dynamic pad_signal {pad_signal.name} must "
                                     f"be a constant expression")
            linked_connections[pad_signal] = expression
        return linked_connections

    @property
    def static_signals(self) -> Set[Signal]:
        signals = set()
        if self.connections:
            for pad_signal, expr in self.connections.items():
                for signal_name in expr.signal_collection:
                    static_signal = Signal(name=signal_name, size=pad_signal.size)
                    signals.add(static_signal)
        return signals

    @property
    def pad_signal_registers(self) -> List[PadSignal]:
        """
        Returns a list of all pad_signals that require a dedicated configuration register. That is, the list contains all
        pad_signals of type dynamic.
        Returns:

        """
        return [pad_signal for pad_signal in self.pad_type.pad_signals if pad_signal.conn_type == ConnectionType.dynamic]

