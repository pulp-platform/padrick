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

from functools import reduce
from typing import Optional, Mapping, Union, Set, List, Dict

from natsort import natsorted

from padrick.Model.TemplatedIdentifier import TemplatedIdentifierType
from padrick.Model.Constants import SYSTEM_VERILOG_IDENTIFIER, LOWERCASE_IDENTIFIER
from padrick.Model.ParseContext import PARSE_CONTEXT
from padrick.Model.PadSignal import PadSignal, ConnectionType, PadSignalKind, Signal, SignalDirection
from padrick.Model.SignalExpressionType import SignalExpressionType
from pydantic import BaseModel, constr, validator, Extra, PrivateAttr, conint, conset

from padrick.Model.TemplatedString import TemplatedStringType
from padrick.Model.UserAttrs import UserAttrs
from padrick.Model.Utilities import sort_signals


class Port(BaseModel):
    name: TemplatedIdentifierType
    description: Optional[TemplatedStringType]
    connections: Optional[Mapping[Union[Signal, str], Optional[SignalExpressionType]]]
    mux_groups: conset(TemplatedIdentifierType, min_items=1) = \
        {TemplatedIdentifierType("all"), TemplatedIdentifierType("self")}
    multiple: conint(ge=1) = 1
    user_attr: Optional[UserAttrs]

    #pydantic model config
    class Config:
        extra = Extra.forbid
        validate_assignment = True
        underscore_attrs_are_private = True

    @validator('connections')
    def link_and_validate_connections(cls, v: Mapping[Union[Signal, str], SignalExpressionType], values):
        linked_connections = {}
        for signal, expression in v.items():
            signal_name = signal.name if isinstance(signal, Signal) else signal
            pad_signal_instances = PARSE_CONTEXT.find_pad_signal_instances(signal_name)
            if len(pad_signal_instances) == 0:
                # Check if it is a pad2chip signal in this case, the right hand side must contain only pad-signal
                # references with kind pad2chip
                referenced_pad_signals = []
                if not expression.signal_collection:
                    raise ValueError(f"Found illegal port connection {signal_name}:{expression}. You either "
                                     f"misspelled the name of a pad_signal or you tried to assign a static or empty "
                                     f"expression to a port signal.")
                for name in expression.signal_collection:
                    pad_signal_instances = PARSE_CONTEXT.find_pad_signal_instances(name)
                    if len(pad_signal_instances) == 0:
                        raise ValueError(f'Found reference to unknown pad_signal {name} in Port connection '
                                         f'expression of a pad2chip port signal {signal_name}.')
                    else:
                        if pad_signal_instances[0].direction != SignalDirection.pads2soc:
                            raise ValueError(f'Found reference to pad_signal {name} with direction '
                                             f'{pad_signal_instances[0].direction} in expression {expression} of a '
                                             f'pas2chip port connection. Only pad2soc pad-signals must be referenced '
                                             f'in pad2chip connection expressions.')
                        referenced_pad_signals.append(pad_signal_instances[0])
                    # Make sure all referenced pad-signals have the same bitwidth. Otherwise, we can not
                    # un-ambiguosly infer the size of the port-signal
                    if len(set([pad.size for pad in referenced_pad_signals])) > 1:
                        raise ValueError(f'Pad signal references in pad2chip port connection expression {expression} '
                                         f'for port {signal_name} must all have the same size.')
            else:
                #Disallow connection for purely static pad_signals
                if all([ps.conn_type == ConnectionType.static for ps in pad_signal_instances]):
                    raise ValueError(f"Found reference to static pad_signal {signal_name}. Only pad_signal names that are of 'conn_type' "
                                     f"dynamic for at least one pad can be used in the port connection mapping.")

                #Landing pad signals must not be referenced
                if any([ps.kind == PadSignalKind.pad for ps in pad_signal_instances]):
                    raise ValueError(f"Found reference to landing pad signal {signal_name}. Only pad_signal names that are of 'conn_type' "
                                     f"dynamic for at least one pad can be used in the port connection mapping.")

                #Pad2chip signals must not appear on the left hand side (i.e. the key) of the connection
                if any([ps.kind == PadSignalKind.output for ps in pad_signal_instances]):
                    raise ValueError(f"Output pad signal {signal_name} must not appear on the left hand side in the "
                                     f"connections section.")

                # Replace expression of type None with empty expression instance
                if not expression:
                    expression = SignalExpressionType.validate(None)

            #Generate Signal instance from size information of the discovered pad_signal_instance. The PadDomain
            # validator ensures, that all pad_signal instances have the same size so it doesn't matter which instance
            # we use for that matter
            signal = Signal(name=signal_name, size=pad_signal_instances[0].size, direction=pad_signal_instances[0].direction)
            linked_connections[signal] = expression
        return linked_connections

    @validator('mux_groups', each_item=True)
    def mux_groups_must_not_contain_uppercase_letters(cls, mux_group: TemplatedIdentifierType):
        mux_group_str = str(mux_group)
        if not mux_group_str.islower():
            raise ValueError("Mux groups must not contain upper-case letters.")
        return mux_group


    @property
    def port_signals_chip2pad(self) -> List[Signal]:
        port_signals = set()
        if self.connections:
            for signal, expr in self.connections.items():
                if signal.direction == SignalDirection.soc2pads:
                    for signal_name in expr.signal_collection:
                        port_signal = Signal(name=signal_name, size=signal.size, direction=signal.direction)
                        port_signals.add(port_signal)
        return sort_signals(port_signals)

    @property
    def port_signals_pad2chip(self) -> List[Signal]:
        port_signals = set()
        if self.connections:
            for signal, expr in self.connections.items():
                if signal.direction == SignalDirection.pads2soc:
                    port_signals.add(signal)
        return sort_signals(port_signals)

    @property
    def port_signals(self) -> List[Signal]:
        """

        Returns: The union of pad2chip and chip2pad port signals.

        """
        return sort_signals(self.port_signals_pad2chip + self.port_signals_chip2pad)

    @property
    def mux_group_name(self) -> str:
        return "_".join(natsorted(self.mux_groups)).upper()

    def expand_port(self) -> List['Port']:
        expanded_ports = []
        for i in range(self.multiple):
            expanded_port: Port = self.copy()
            expanded_port.name = expanded_port.name.evaluate_template(i)
            expanded_port.description = expanded_port.description.evaluate_template(i) if expanded_port.description else None
            expanded_port.user_attr = expanded_port.user_attr.expand_user_attrs(i) if expanded_port.user_attr else None
            expanded_port.mux_groups = set(map(lambda mux_group: mux_group.evaluate_template(i), expanded_port.mux_groups))
            expanded_port.multiple = 1
            expanded_connections = {}
            for key, value in expanded_port.connections.items():
                if isinstance(key, SignalExpressionType):
                    key = str(key.evaluate_template(i))
                elif isinstance(key, Signal):
                    key = str(key.name.evaluate_template(i))
                if isinstance(value, SignalExpressionType):
                    value = str(value.evaluate_template(i))
                elif isinstance(value, Signal):
                    value = str(value.name.evaluate_template(i))
                expanded_connections[key] = value
            expanded_port.connections = expanded_connections
            expanded_ports.append(expanded_port)
        return expanded_ports
