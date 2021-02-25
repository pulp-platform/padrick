from typing import Optional, Mapping, List, Union, Set

from padrick.Model.Constants import SYSTEM_VERILOG_IDENTIFIER
from padrick.Model.ParseContext import PARSE_CONTEXT
from padrick.Model.PadSignal import PadSignal, ConnectionType, PadSignalKind, Signal
from padrick.Model.PadType import PadType
from padrick.Model.SignalExpressionType import SignalExpressionType
from pydantic import BaseModel, constr, validator, root_validator, Extra, conint, Field


class PadInstance(BaseModel):
    name: constr(regex=SYSTEM_VERILOG_IDENTIFIER)
    description: Optional[str]
    multiple: conint(ge=1) = 1
    pad_type: Union[constr(regex=SYSTEM_VERILOG_IDENTIFIER), PadType]
    is_static: bool = False
    package_pad_nr: Optional[int]
    mux_group: constr(strip_whitespace=True, regex=SYSTEM_VERILOG_IDENTIFIER) = "all"
    connections: Optional[Mapping[Union[PadSignal, str], Optional[SignalExpressionType]]]

    #pydantic model config
    class Config:
        extra = Extra.forbid

    @validator("mux_group")
    def normalize_mux_groups (cls, mux_group):
        return mux_group.strip().lower()


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

            # For output pad_signals, only single signals are allowed. We cannot connect an output signal to an
            # expression!
            if pad_signal.kind == PadSignalKind.output and not expression.is_empty and not expression.is_single_signal:
                raise ValueError(f"No complex expressions are allowed for output signals. Possible expressions are "
                                 f"single signal identifiers or the empty expression to leave the output signal "
                                 f"unconnected.")

            # If the pad_signal is of conn_type dynamic, make sure the expression is a const_expression
            if pad_signal.conn_type == ConnectionType.dynamic:
                if not (expression or expression.is_const_expr):
                    raise ValueError(f"Pad Signal connections expression for dynamic pad_signal {pad_signal.name} must "
                                     f"be a constant expression")
            linked_connections[pad_signal] = expression
        return linked_connections

    @root_validator(skip_on_failure=True)
    def no_connections_for_pad_signal_of_kind_pad(cls, values):
        if values.get('connections'):
            for pad_signal in values['connections'].keys():
                if pad_signal.kind == PadSignalKind.pad:
                    raise ValueError("Padsignals of kind pad cannot be referenced in the connections list.")
        return values

    @property
    def static_connection_signals(self) -> Set[Signal]:
        """
        Returns all static connection signals used for the given pad.
        Returns:
        """
        signals = set()
        for pad_signal in self.static_pad_signals:
            # If there is an entry in the connections list use the signals in the expression list
            if self.connections and pad_signal in self.connections.keys():
                for signal_name in self.connections[pad_signal].signal_collection:
                    static_signal = Signal(name=signal_name, size=pad_signal.size, direction=pad_signal.direction)
                    signals.add(static_signal)
            #Otherwise use the signals in the default_static_signal expression
            else:
                for signal_name in pad_signal.default_static_value.signal_collection:
                    static_signal = Signal(name=signal_name, size=pad_signal.size, direction=pad_signal.direction)
                    signals.add(static_signal)
        return signals

    @property
    def override_signals(self) -> Set[Signal]:
        signals = set()
        for pad_signal in self.pad_type.pad_signals:
            if pad_signal.and_override_signal:
                for signal_name in pad_signal.and_override_signal.signal_collection:
                    signal = Signal(name=signal_name, size=pad_signal.size, direction=pad_signal.direction)
                    signals.add(signal)
            if pad_signal.or_override_signal:
                for signal_name in pad_signal.or_override_signal.signal_collection:
                    signal = Signal(name=signal_name, size=pad_signal.size, direction=pad_signal.direction)
                    signals.add(signal)
        return signals



    @property
    def dynamic_pad_signals(self) -> List[PadSignal]:
        """
        Returns a list of all pad_signals that require a dedicated configuration register. That is, the list contains all
        pad_signals of type dynamic.
        Returns:

        """
        if self.is_static:
            return []
        else:
            return [pad_signal for pad_signal in self.pad_type.pad_signals if pad_signal.kind != PadSignalKind.pad and pad_signal.conn_type == ConnectionType.dynamic]

    @property
    def dynamic_pad_signals_soc2pad(self) -> List[PadSignal]:
        return [pad_signal for pad_signal in self.dynamic_pad_signals if pad_signal.kind == PadSignalKind.input]

    @property
    def dynamic_pad_signals_pad2soc(self) -> List[PadSignal]:
        return [pad_signal for pad_signal in self.dynamic_pad_signals if pad_signal.kind == PadSignalKind.output]

    @property
    def static_pad_signals(self):
        #If the instance itself is static, all pad_signals are static (override).
        if self.is_static:
            return [pad_signal for pad_signal in self.pad_type.pad_signals if pad_signal.kind != PadSignalKind.pad]
        else:
            return [pad_signal for pad_signal in self.pad_type.pad_signals if pad_signal.conn_type == ConnectionType.static]


    @property
    def landing_pads(self):
        return [pad_signal for pad_signal in self.pad_type.pad_signals if pad_signal.kind == PadSignalKind.pad]

    @property
    def static_pad_signal_connections(self) -> Mapping[Signal, SignalExpressionType]:
        pad_signal_connection = {}
        for pad_signal in self.pad_type.pad_signals:
            if self.is_static or pad_signal.conn_type == ConnectionType.static:
                # If there is an entry in the connections list use the signals in the expression list
                if self.connections and pad_signal in self.connections.keys():
                    pad_signal_connection[pad_signal] = self.connections[pad_signal]
                # Otherwise use the signals in the default_static_signal expression
                else:
                    pad_signal_connection[pad_signal] = self.pad_type.get_pad_signal(pad_signal.name).default_static_value
        return pad_signal_connection
