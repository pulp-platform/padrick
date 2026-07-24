# Copyright 2021-2022 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Manuel Eggimann, ETH Zurich
import logging
from typing import Optional, Mapping, List, Union, Set, Tuple, Dict
from typing_extensions import Annotated, Literal

from natsort import natsorted

from padrick.Model.Port import Port
from padrick.Model.Constants import SYSTEM_VERILOG_IDENTIFIER, LOWERCASE_IDENTIFIER
from padrick.Model.ParseContext import PARSE_CONTEXT
from padrick.Model.PadSignal import PadSignal, ConnectionType, PadSignalKind, Signal
from padrick.Model.PadType import PadType
from padrick.Model.PortGroup import PortGroup
from padrick.Model.SignalExpressionType import SignalExpressionType
from pydantic import BaseModel, ConfigDict, Field, StringConstraints, ValidationInfo, field_validator, model_validator

from padrick.Model.TemplatedIdentifier import TemplatedIdentifierType
from padrick.Model.TemplatedPortIdentifier import TemplatedPortIdentifierType
from padrick.Model.TemplatedString import TemplatedStringType
from padrick.Model.UserAttrs import UserAttrs
from padrick.Model.Utilities import sort_signals, cached_property

logger = logging.getLogger("padrick.Configparser")

class PadInstance(BaseModel):
    name: TemplatedIdentifierType = Field(description="Instance name of the pad. May contain {i} index "
        "templates which are expanded when multiple > 1.")
    description: Optional[TemplatedStringType] = Field(default=None, description="Optional description of "
        "the pad's function. May contain {i} index templates when multiple > 1.")
    multiple: Annotated[int, Field(ge=1, description="Number of copies of this pad to generate. When "
        "greater than 1, {i} templates in name, description, mux_groups and connections are replaced with "
        "the instance index starting from 0.")] = 1
    pad_type: Union[Annotated[str, StringConstraints(pattern=SYSTEM_VERILOG_IDENTIFIER)], PadType] = Field(
        description="Name of the pad type (declared in pad_types) that this instance uses.")
    is_static: bool = Field(default=False, description="If true, forces every pad signal of this instance to "
        "conn_type 'static' so the pad is controlled solely by its connections and cannot be muxed to ports. "
        "Mutually exclusive with quasi_static.")
    quasi_static: Union[bool, Literal["muxed", "hardwired"]] = Field(default=False, description="If set, treat "
        "this otherwise-dynamic pad as fixed to a single port: padrick enforces that exactly one port is "
        "muxable to it and sets that port as the default_port. 'muxed' (equivalent to true) keeps the 1-bit "
        "mux and its config registers so software can still fall back to register-controlled GPIO mode. "
        "'hardwired' removes the mux and the pad's config/mux_sel registers entirely: port-mapped pad signals "
        "are directly connected to the port and all other pad signals are tied to their reset values. "
        "Experimental; mutually exclusive with is_static.")
    mux_groups: Annotated[Set[TemplatedIdentifierType], Field(min_length=1, description="Set of mux-group "
        "labels controlling connectivity. A port can be routed to this pad if their mux-group sets intersect. "
        "Defaults to 'all' and 'self'; 'self' expands to the pad instance name (with index).")] = {TemplatedIdentifierType("all"), TemplatedIdentifierType("self")}
    connections: Optional[Mapping[Union[PadSignal, str], Optional[SignalExpressionType]]] = Field(default=None,
        description="Mapping of pad signal name to expression that overrides static signal connections or "
        "sets the reset value of the config register for dynamic signals. Signals of kind 'pad' must not "
        "appear here; only kind 'output' signals may be left unconnected (~).")
    default_port: Optional[Union[Mapping[Union[Literal['*'], TemplatedIdentifierType], TemplatedPortIdentifierType], TemplatedPortIdentifierType, Tuple[PortGroup, Port]]] = Field(default=None,
        description="Port to connect to this pad by default after reset, given as "
        "'<port_group>.<port>'. For multi-pads you can instead provide an ordered mapping from expanded pad "
        "name (or '*' wildcard) to port specifier; later entries override earlier ones.")
    user_attr: Optional[UserAttrs] = Field(default=None, description="Optional custom key-value pairs that "
        "are also exposed during template rendering.")
    _method_cache: Mapping = {}
    model_config = ConfigDict(extra="forbid", validate_assignment=True)


    @field_validator('pad_type')
    @classmethod
    def lookup_pad_type(cls, v: Union[PadType, str]) -> PadType:
        if isinstance(v, PadType):
            return v
        pad_type = PARSE_CONTEXT.find_pad_type(v)
        if not pad_type:
            raise ValueError(f"Unknown pad_type {v}. Did you mispell the pad_type or forgot to declare it?")
        else:
            return pad_type

    @field_validator('quasi_static')
    @classmethod
    def normalize_quasi_static(cls, v: Union[bool, str]) -> Union[bool, str]:
        """Normalize the legacy boolean 'true' to the equivalent 'muxed' mode."""
        return "muxed" if v is True else v

    @property
    def is_hardwired(self) -> bool:
        """True if this quasi-static pad is hardwired to its port without a mux."""
        return self.quasi_static == "hardwired"

    @field_validator('mux_groups')
    @classmethod
    def mux_groups_must_not_contain_uppercase_letters(cls, mux_groups):
        for mux_group in mux_groups:
            if not str(mux_group).islower():
                raise ValueError("Mux groups must not contain upper-case letters.")
        return mux_groups

    @field_validator('connections')
    @classmethod
    def link_and_validate_connections(cls, v: Mapping[str, SignalExpressionType], info: ValidationInfo):
        linked_connections = {}
        if v:
            for pad_signal, expression in v.items():
                # Create a copy of the pad signal instance so we can override its connection_type according to the
                # is_static override value
                if 'pad_type' not in info.data:
                    raise ValueError("Missing pad_type for pad_instance")
                if not isinstance(pad_signal, PadSignal):
                    pad_signal = info.data['pad_type'].get_pad_signal(pad_signal).model_copy() #This will raise a ValueError if
                                                                                       # the # pad signal does not exist
                if info.data['is_static']: pad_signal.conn_type = ConnectionType.static

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

    @model_validator(mode='after')
    def no_connections_for_pad_signal_of_kind_pad(self):
        if self.connections:
            for pad_signal in self.connections.keys():
                if pad_signal.kind == PadSignalKind.pad:
                    raise ValueError("Padsignals of kind pad cannot be referenced in the connections list.")
        return self

    @model_validator(mode='after')
    def quasi_static_flag_and_is_static_mutually_exclusive(self):
        if self.quasi_static and self.is_static:
            raise ValueError("The quasi_static flag the is_static flag are mutually exclusive.")
        return self
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
            dynamic_pad_signals = [pad_signal for pad_signal in self.pad_type.pad_signals if pad_signal.kind != PadSignalKind.pad \
                                 and pad_signal.conn_type == ConnectionType.dynamic]
            return sort_signals(dynamic_pad_signals)

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
            expanded_pad = self.model_copy()
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
