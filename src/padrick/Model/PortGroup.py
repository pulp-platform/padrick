# Copyright 2021-2022 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Manuel Eggimann, ETH Zurich

from typing import Optional, List, Set, Mapping, Union, Dict

from padrick.Model.Constants import SYSTEM_VERILOG_IDENTIFIER
from padrick.Model.PadSignal import Signal, SignalDirection
from padrick.Model.Port import Port
from padrick.Model.SignalExpressionType import SignalExpressionType
from pydantic import BaseModel, ConfigDict, Field, ValidationInfo, constr, field_validator, model_validator

from padrick.Model.TemplatedIdentifier import TemplatedIdentifierType
from padrick.Model.TemplatedString import TemplatedStringType
from padrick.Model.UserAttrs import UserAttrs
from padrick.Model.Utilities import sort_signals, sort_ports, cached_property
from typing_extensions import Annotated


class PortGroup(BaseModel):
    """A port group logically groups related ports (e.g. all ports of one peripheral) and defines the
    peripheral-signal namespace shared amongst them."""
    name: TemplatedIdentifierType = Field(description="Name of the port group. May contain {i} index "
        "templates which are expanded when multiple > 1.")
    description: Optional[TemplatedStringType] = Field(default=None, description="Optional description of "
        "the port group. May contain {i} index templates when multiple > 1.")
    mux_groups: Optional[Annotated[Set[TemplatedIdentifierType], Field(min_length=1)]] = Field(default=None,
        description="Optional default set of mux-group labels applied to every port in this group that does "
        "not specify its own mux_groups.")
    ports: List[Port] = Field(description="List of ports belonging to this port group.")
    output_defaults: Union[SignalExpressionType, Mapping[Union[Signal, str], Optional[SignalExpressionType]]] = Field(
        default={}, description="Default value driven onto each pad-to-SoC (pad2chip) port signal when no pad "
        "is connected to it. Provide either a single expression applied to all such signals or a mapping from "
        "port signal name to a constant expression. Every pad2chip port signal in the group must have a "
        "default.")
    multiple: Annotated[int, Field(ge=1, description="Number of copies of this port group to generate. When "
        "greater than 1, {i} templates in name, description and mux_groups are replaced with the group index "
        "starting from 0.")] = 1
    user_attr: Optional[UserAttrs] = Field(default=None, description="Optional custom key-value pairs that "
        "are also exposed during template rendering.")
    _method_cache = {}
    model_config = ConfigDict(extra="forbid")

    @field_validator('output_defaults')
    @classmethod
    def expand_default_value_for_connection_defaults(cls, output_defaults, info: ValidationInfo):
        if isinstance(output_defaults, SignalExpressionType):
            port_signals_pad2soc = set()
            for port in info.data.get('ports', []):
                port_signals_pad2soc.update(port.port_signals_pad2chip)
            output_defaults = {port_signal.name: output_defaults for port_signal in port_signals_pad2soc}
        return output_defaults

    @field_validator('output_defaults')
    @classmethod
    def validate_and_link_output_defaults(cls, v: Mapping[str, SignalExpressionType], info: ValidationInfo):
        """Make sure the signals specified in connection_defaults are actually pad2chip port signals and make sure
        the associated expression is static."""
        linked_connection_defaults: Mapping[Signal, SignalExpressionType] = {}
        for signal_name, expression in v.items():
            port_signals = set().union(*[set(port.port_signals) for port in info.data.get('ports', [])])
            # Try to find the port signal in the implicitly declared port signal list (a name used in the connections
            # section declares a new port signal)
            signal_found = False
            for port_signal in port_signals:
                if port_signal.name == signal_name:
                    # Make sure the port signal has the right directionality. Only pad2chip port signals can have a
                    # default_connection.
                    if port_signal.direction == SignalDirection.pads2soc:
                        # Make sure the expression on the RHS is a constant expression
                        if expression.is_const_expr:
                            signal_found = True
                            linked_connection_defaults[port_signal] = expression
                            break
                        else:
                            raise ValueError(f"Expression {expression} for connection_default of port signal {signal_name} is "
                                             f"not constant.")
                    else:
                        raise ValueError(f"Found port-signal {signal_name} with wrong direcitonality in "
                                         f"connection_default "
                                         f"section. Only port_signals with direction pad2chip can be referenced.")
            if not signal_found:
                raise ValueError(f"Found unknown port signal {signal_name} in connetion_defaults section. Only port "
                                 f"signal names declared in the connection sections of one of the port within this "
                                 f"port group are legal.")

        return linked_connection_defaults

    @model_validator(mode='after')
    def check_all_pad2soc_ports_have_default(self):
        port_signals_pad2soc = set()
        for port in self.ports:
            port_signals_pad2soc.update(port.port_signals_pad2chip)
        for port in port_signals_pad2soc:
            if port not in self.output_defaults and port.name not in self.output_defaults:
                raise ValueError(f"Found port signal {port.name} with direction pad2soc that does not specify a connection default.")
        return self


    @field_validator('ports')
    @classmethod
    def expand_multi_ports(cls, ports):
        """
        Expand ports with muliple>1 into individual port objects replacing the '<>' token in name, description and signalexpression with the array index.
        """
        expanded_ports = []
        for port in ports:
            expanded_ports.extend(port.expand_port())
        return expanded_ports

    @field_validator('ports')
    @classmethod
    def check_ports_are_unique(cls, ports):
        port_names_seen = set()
        for port in ports:
            if port.name in port_names_seen:
                raise ValueError(f"Duplicate port name {port.name}. Ports within a port group must be unique.")
            else:
                port_names_seen.add(port.name)
        return ports

    @field_validator('ports')
    @classmethod
    def check_port_signals_are_not_bidirectional(cls, v):
        port_signals = set()
        for port in v:
            port_signals.update(port.port_signals)
        # Check if there are entries with the same name but different direction.
        seen: Mapping[str, Signal] = {}
        for signal in port_signals:
            if signal.name in seen:
                if seen[signal.name].direction != signal.direction:
                    raise ValueError(f"Found port signal {signal.name} that is used for both, input and output "
                                     f"pad_signals. "
                                     f"Bi-directional port signals are not supported.")
            else:
                seen[signal.name] = signal
        return v

    @field_validator('ports')
    @classmethod
    def check_pad2soc_ports_are_not_multiple_connected(cls, v):
        port_signals = set()
        for port in v:
            for port_signal in port.port_signals_pad2chip:
                if port_signal in port_signals:
                    raise ValueError(f"Cannot connect pad2soc signal {port_signal.name} to multiple pad_signals. "
                                     f"Within a single port_group a port signal with direction pad2soc must only be"
                                     f"referenced in at most one port connection list. (Otherwise we would have driving conflicts).")
                else:
                    port_signals.add(port_signal)
        return v

    @cached_property
    def port_signals(self) -> List[Signal]:
        return sort_signals(set().union(*[set(port.port_signals) for port in self.ports]))

    @cached_property
    def port_signals_soc2pads(self) -> List[Signal]:
        return sort_signals(set([signal for signal in self.port_signals if signal.direction ==
                                 SignalDirection.soc2pads]))

    @cached_property
    def port_signals_pads2soc(self) -> List[Signal]:
        return sort_signals(set([signal for signal in self.port_signals if signal.direction ==
                                 SignalDirection.pads2soc]))

    def get_ports_in_mux_groups(self, mux_groups: Set[str]) -> List[Port]:
        ports_in_mux_group = [port for port in self.ports if mux_groups.intersection(port.mux_groups)]
        return sort_ports(ports_in_mux_group)

    def expand_port_group(self) -> List['PortGroup']:
        expanded_port_groups = []
        for i in range(self.multiple):
            expanded_port_group: PortGroup = self.model_copy()
            expanded_port_group.name = expanded_port_group.name.evaluate_template(i)
            expanded_port_group.description = expanded_port_group.description.evaluate_template(i) if expanded_port_group.description else None
            expanded_port_group.user_attr = expanded_port_group.user_attr.expand_user_attrs(i) if expanded_port_group.user_attr else None
            expanded_port_group.mux_groups = set(map(lambda mux_group: mux_group.evaluate_template(i), expanded_port_group.mux_groups)) if expanded_port_group.mux_groups else None
            expanded_port_group.multiple = 1
            expanded_port_groups.append(expanded_port_group)
        return expanded_port_groups

