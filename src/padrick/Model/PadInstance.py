from typing import Optional, Mapping, List, Union, Set, Tuple, Dict

from natsort import natsorted

from padrick.Model.Port import Port
from padrick.Model.Constants import SYSTEM_VERILOG_IDENTIFIER, LOWERCASE_IDENTIFIER
from padrick.Model.ParseContext import PARSE_CONTEXT
from padrick.Model.PadSignal import PadSignal, ConnectionType, PadSignalKind, Signal
from padrick.Model.PadType import PadType
from padrick.Model.PortGroup import PortGroup
from padrick.Model.SignalExpressionType import SignalExpressionType
from pydantic import BaseModel, constr, validator, root_validator, Extra, conint, Field, conset

from padrick.Model.TemplatedIdentifier import TemplatedIdentifierType
from padrick.Model.TemplatedPortIdentifier import TemplatedPortIdentifierType
from padrick.Model.TemplatedString import TemplatedStringType
from padrick.Model.Utilities import sort_signals, cached_property


class PadInstance(BaseModel):
    name: TemplatedIdentifierType
    description: Optional[TemplatedStringType]
    multiple: conint(ge=1) = 1
    pad_type: Union[constr(regex=SYSTEM_VERILOG_IDENTIFIER), PadType]
    is_static: bool = False
    mux_groups: conset(TemplatedIdentifierType, min_items=1) = {TemplatedIdentifierType("all"), TemplatedIdentifierType("self")}
    connections: Optional[Mapping[Union[PadSignal, str], Optional[SignalExpressionType]]]
    default_port: Optional[Union[TemplatedPortIdentifierType, Tuple[PortGroup, Port]]]
    user_attr: Optional[Dict[str, Union[str, int, bool]]]
    _method_cache: Mapping = {}

    #pydantic model config
    class Config:
        extra = Extra.forbid
        validate_assignment = True
        underscore_attrs_are_private = True


    @validator('pad_type')
    def lookup_pad_type(cls, v: Union[PadType, str]) -> PadType:
        if isinstance(v, PadType):
            return v
        pad_type = PARSE_CONTEXT.find_pad_type(v)
        if not pad_type:
            raise ValueError(f"Unknown pad_type {v}. Did you mispell the pad_type or forgot to declare it?")
        else:
            return pad_type

    @validator('mux_groups', each_item=True)
    def mux_groups_must_not_contain_uppercase_letters(cls, mux_group: TemplatedIdentifierType):
        mux_group_str = str(mux_group)
        if not mux_group_str.islower():
            raise ValueError("Mux groups must not contain upper-case letters.")
        return mux_group

    @validator('connections')
    def link_and_validate_connections(cls, v: Mapping[str, SignalExpressionType], values):
        linked_connections = {}
        if v:
            for pad_signal, expression in v.items():
                # Create a copy of the pad signal instance so we can override its connection_type according to the
                # is_static override value
                if 'pad_type' not in values:
                    raise ValueError("Missing pad_type for pad_instance")
                if not isinstance(pad_signal, PadSignal):
                    pad_signal = values['pad_type'].get_pad_signal(pad_signal).copy() #This will raise a ValueError if
                                                                                       # the # pad signal does not exist
                if values['is_static']: pad_signal.conn_type = ConnectionType.static

                # Only for output pad_signals it is allowed to have an empty expression (-> leave unconnected) as the
                # expression
                if pad_signal.kind != PadSignalKind.output and not expression:
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
    def static_connection_signals(self) -> List[Signal]:
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
        return sort_signals(signals)

    @property
    def override_signals(self) -> List[Signal]:
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
        return sort_signals(signals)



    @cached_property
    def dynamic_pad_signals(self) -> List[PadSignal]:
        """
        Returns a list of all pad_signals that require a dedicated configuration register. That is, the list contains all
        pad_signals of type dynamic.
        Returns:

        """
        if self.is_static:
            return []
        else:
            return sort_signals([pad_signal for pad_signal in self.pad_type.pad_signals if pad_signal.kind != PadSignalKind.pad \
                                 and pad_signal.conn_type == ConnectionType.dynamic])

    @cached_property
    def dynamic_pad_signals_soc2pad(self) -> List[PadSignal]:
        return [pad_signal for pad_signal in self.dynamic_pad_signals if pad_signal.kind == PadSignalKind.input]

    @cached_property
    def dynamic_pad_signals_pad2soc(self) -> List[PadSignal]:
        return [pad_signal for pad_signal in self.dynamic_pad_signals if pad_signal.kind == PadSignalKind.output]

    @cached_property
    def static_pad_signals(self):
        #If the instance itself is static, all pad_signals are static (override).
        if self.is_static:
            return [pad_signal for pad_signal in self.pad_type.pad_signals if pad_signal.kind != PadSignalKind.pad]
        else:
            return [pad_signal for pad_signal in self.pad_type.pad_signals if pad_signal.conn_type == ConnectionType.static]


    @cached_property
    def landing_pads(self):
        return [pad_signal for pad_signal in self.pad_type.pad_signals if pad_signal.kind == PadSignalKind.pad]

    @cached_property
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

    @cached_property
    def mux_group_name(self) -> str:
        return "_".join(natsorted(self.mux_groups)).upper()

    def expand_padinstance(self) -> List['PadInstance']:
        expanded_pads = []
        for i in range(self.multiple):
            expanded_pad = self.copy()
            expanded_pad._method_cache = {}
            expanded_pad.name = expanded_pad.name.evaluate_template(i)
            expanded_pad.description = expanded_pad.description.evaluate_template(i) if expanded_pad.description else None
            expanded_pad.mux_groups = set(map(lambda mux_group: mux_group.evaluate_template(i), expanded_pad.mux_groups))
            expanded_pad.multiple = 1
            if expanded_pad.default_port:
                expanded_pad.default_port = expanded_pad.default_port.evaluate_template(i)
            expanded_connections = {}
            if expanded_pad.connections:
                for key, value in expanded_pad.connections.items():
                    if isinstance(value, SignalExpressionType):
                        value = str(value.evaluate_template(i))
                    expanded_connections[key] = value
                expanded_pad.connections = expanded_connections
            expanded_pads.append(expanded_pad)
        return expanded_pads
