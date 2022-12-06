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
import logging
from typing import Optional, Mapping, List, Union, Set, Tuple, Dict
from typing_extensions import Literal

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
from padrick.Model.UserAttrs import UserAttrs
from padrick.Model.Utilities import sort_signals, cached_property

logger = logging.getLogger("padrick.Configparser")

class PadInstance(BaseModel):
    name: TemplatedIdentifierType
    description: Optional[TemplatedStringType]
    multiple: conint(ge=1) = 1
    pad_type: Union[constr(regex=SYSTEM_VERILOG_IDENTIFIER), PadType]
    is_static: bool = False
    mux_groups: conset(TemplatedIdentifierType, min_items=1) = {TemplatedIdentifierType("all"), TemplatedIdentifierType("self")}
    connections: Optional[Mapping[Union[PadSignal, str], Optional[SignalExpressionType]]]
    default_port: Optional[Union[Mapping[Union[Literal['*'], TemplatedIdentifierType], TemplatedPortIdentifierType], TemplatedPortIdentifierType, Tuple[PortGroup, Port]]]
    user_attr: Optional[UserAttrs]
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
        # We use the following variable to detect if a default port mapping contains any mappings that are not used which
        # most likely is a user typo. We want to warn the user about this.
        matched_default_port_mappings = set()
        for i in range(self.multiple):
            expanded_pad = self.copy()
            expanded_pad._method_cache = {}
            expanded_pad.name = expanded_pad.name.evaluate_template(i)
            expanded_pad.description = expanded_pad.description.evaluate_template(i) if expanded_pad.description else None
            expanded_pad.user_attr = expanded_pad.user_attr.expand_user_attrs(i) if expanded_pad.user_attr else None
            expanded_pad.mux_groups = set(map(lambda mux_group: mux_group.evaluate_template(i), expanded_pad.mux_groups))
            expanded_pad.multiple = 1
            if expanded_pad.default_port:
                # Default port can be a single TemplatedPortIdentifier that we should expand or it can
                # be a mapping from expanded pad names to TemplatedPortIdentifier. Expand both options
                # in the right way.
                if isinstance(expanded_pad.default_port, Mapping):
                    default_port = None
                    for pad_name_tmpl, port_tmpl in expanded_pad.default_port.items():
                        if pad_name_tmpl == "*" or expanded_pad.name == pad_name_tmpl.evaluate_template(i):
                            default_port = port_tmpl.evaluate_template(i)
                            matched_default_port_mappings.add(pad_name_tmpl)
                    expanded_pad.default_port = default_port
                else:
                     expanded_pad.default_port = expanded_pad.default_port.evaluate_template(i)

            expanded_connections = {}
            if expanded_pad.connections:
                for key, value in expanded_pad.connections.items():
                    if isinstance(value, SignalExpressionType):
                        value = str(value.evaluate_template(i))
                    expanded_connections[key] = value
                expanded_pad.connections = expanded_connections
            expanded_pads.append(expanded_pad)
        # For default_port mappings, check if all user supplied mappings have been matched to an expanded pad. If not,
        # this is most likely a user error (typo) and we should warn about it.
        if isinstance(self.default_port, Mapping) and matched_default_port_mappings != set(self.default_port.keys()):
            msg = f"The default_port entry for pad {self.name} contains the following entries that did not match to any of the expanded pad names:"
            msg += "\n"
            msg += ','.join([f'"{v}"' for v in set(self.default_port.keys()).difference(matched_default_port_mappings)])
            msg += "\nMaybe there is a typo in one of your mappings?"
            msg += f"\nThe current default_port settings for this pad are as follows:\n"
            msg += f"{chr(10).join([f'{pad.name}: {pad.default_port}' for pad in expanded_pads])}"
            logger.warning(msg)
        return expanded_pads
