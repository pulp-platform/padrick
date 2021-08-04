import itertools
import logging
from typing import List, Optional, Set, Mapping, Iterable, Dict, Union

import click_log
from padrick.Model.Constants import SYSTEM_VERILOG_IDENTIFIER
from padrick.Model.PadInstance import PadInstance
from padrick.Model.PadSignal import Signal, SignalDirection
from padrick.Model.PadType import PadType
from padrick.Model.ParseContext import PARSE_CONTEXT
from padrick.Model.Port import Port
from padrick.Model.PortGroup import PortGroup
from pydantic import BaseModel, constr, conlist, root_validator, validator
from natsort import natsorted

from padrick.Model.SignalExpressionType import SignalExpressionType
from padrick.Model.Utilities import sort_signals, sort_ports, sort_pads

logger = logging.getLogger("padrick.Configparser")
click_log.basic_config(logger)

class PadDomain(BaseModel):
    """
    A pad_domain contains the configuration about one collection of pads and ports that can connected with each other.
    """
    name: constr(regex=SYSTEM_VERILOG_IDENTIFIER)
    description: Optional[str]
    pad_types: conlist(PadType, min_items=1)
    pad_list: conlist(PadInstance, min_items=1)
    port_groups: List[PortGroup]
    user_attr: Optional[Dict[str, Union[str, int, bool]]]


    def __init__(self, *args, **kwargs):
        PARSE_CONTEXT.set_context(self)
        super().__init__(*args, **kwargs)

    @validator('port_groups')
    def expand_multi_port_groups(cls, port_groups: List[PortGroup]):
        expanded_port_groups = []
        for port_group in port_groups:
            expanded_port_groups.extend(port_group.expand_port_group())
        return expanded_port_groups

    @validator('port_groups')
    def check_port_group_names_are_unique(cls, port_groups: List[PortGroup]):
        port_groups_seen = set()
        for port_group in port_groups:
            if port_group.name in port_groups_seen:
                raise ValueError(f"Found duplicate port_group {port_group.name}. Port Group names must be unique.")
            else:
                port_groups_seen.add(port_group.name)
        return port_groups

    @root_validator(skip_on_failure=True)
    def check_padsignal_with_same_name_have_same_size_and_direction(cls, values):
        pad_signal_names_seen = set()
        pad_signals_seen : Set[Signal] = set()
        for pad_type in values['pad_types']:
            for pad_signal in pad_type.pad_signals:
                if pad_signal.name in pad_signal_names_seen and pad_signal not in pad_signals_seen:
                    raise ValueError(f"Duplicate pad signal {pad_signal.name} for pad {values['name']}")
                else:
                    pad_signal_names_seen.add(pad_signal.name)
                    pad_signals_seen.add(pad_signal)
        return values

    @validator('pad_list')
    def expand_multi_pads(cls, pads: List[PadInstance]):
        expanded_pads = []
        for pad in pads:
            expanded_pads.extend(pad.expand_padinstance())
        return expanded_pads

    @validator("pad_list")
    def normalize_pad_mux_groups (cls, pads: List[PadInstance]):
        expanded_pads = []
        for pad in pads:
            if "self" in pad.mux_groups:
                pad.mux_groups.discard("self")
                pad.mux_groups.add(pad.name.lower().strip())
        return pads

    @validator('port_groups')
    def override_port_mux_group(cls, port_groups: List[PortGroup], values):
        for port_group in port_groups:
            for port in port_group.ports:
                if not port_group.mux_groups is None:
                    port.mux_groups = port_group.mux_groups
        return port_groups

    @validator('port_groups')
    def normalize_port_mux_groups(cls, port_groups: List[PortGroup], values):
        for port_group in port_groups:
            for port in port_group.ports:
                if "self" in port.mux_groups:
                    port.mux_groups.discard("self")
                    port.mux_groups.add(f"{values['name']}_{port.name}")
        return port_groups


    @validator('pad_list')
    def check_static_connection_signals_are_not_bidirectional(cls, v):
        static_connection_signal = set()
        for pad in v:
            static_connection_signal.update(pad.static_connection_signals)
        # Check if there are entries with the same name but different direction.
        seen: Mapping[str, Signal] = {}
        for signal in static_connection_signal:
            if signal.name in seen:
                if seen[signal.name].direction != signal.direction:
                    raise ValueError(f"Found static signal {signal.name} that is used for both, input and output "
                                     f"pad_signals. "
                                     f"Bi-directional static connection signals are not supported.")
                if seen[signal.name].size != signal.size:
                    raise ValueError(f"Found static signal whith ambiguous size. static signals must only be "
                                     f"connected to pad signals of same size and direction.")
            else:
                seen[signal.name] = signal
        return v

    @validator('pad_list')
    def check_each_pad_instance_name_is_unique(cls, pads: List[PadInstance]):
        pad_names_seen = set()
        for pad in pads:
            if pad.name in pad_names_seen:
                raise ValueError(f"Duplicate pad instance name {pad.name}. Pad instance names must be unique.")
            else:
                pad_names_seen.add(pad.name)
        return pads

    @root_validator(skip_on_failure=True)
    def validate_and_link_default_role_ports(cls, values):
        pad: PadInstance
        for pad in values['pad_list']:
            # Try to find the port in the port in the list of muxable ports for this pad_instance
            if isinstance(pad.default_port, str):
                (default_port_group_name, default_port_name) = pad.default_port.split(".", maxsplit=1)
                linked_default_port = None
                for port_group in values['port_groups']:
                    if port_group.name == default_port_group_name:
                        for port in port_group.ports:
                            if port.mux_groups.intersection(pad.mux_groups) and port.name == default_port_name:
                                linked_default_port = (port_group, port)
                                break
                if linked_default_port:
                    pad.default_port = linked_default_port
                else:
                    raise ValueError(f"Default_port {pad.default_port} for pad {pad.name} is not in the list of connectable ports.")
        return values

    @root_validator(skip_on_failure=True)
    def warn_about_orphan_pads_and_ports(cls, values):
        port_mux_groups = set.union(*[port.mux_groups for port_group in values['port_groups'] for port in
                                      port_group.ports])
        # We need to handle pads differently since they do not expand the 'self' keyword
        pad_mux_groups = set()
        for pad in values['pad_list']:
            if pad.dynamic_pad_signals:
                expanded_mux_groups = set()
                for mux_group in pad.mux_groups:
                    for i in range(pad.multiple):
                        expanded_mux_groups.add(mux_group.replace('<>', str(i)))
                if not expanded_mux_groups.intersection(port_mux_groups):
                    logger.warning(
                        f"Found pad {pad.name} with mux_groups {str(pad.mux_groups)} but no port specifies any of these mux groups.")
                pad_mux_groups.update(expanded_mux_groups)

        for port_group in values['port_groups']:
            for port in port_group.ports:
                if not port.mux_groups.intersection(pad_mux_groups):
                    logger.warning(
                        f"Found port {port.name} in port group {port_group.name} with mux_groups"
                        f" {str(port.mux_groups)} but no pad specifies any of these mux groups.")
        return values

    @property
    def override_signals(self) -> List[Signal]:
        override_signals = set()
        for pad in self.pad_list:
            override_signals.update(pad.override_signals)
        return sort_signals(override_signals)

    @property
    def static_connection_signals(self) -> List[Signal]:
        static_connection_signals = set()
        for pad in self.pad_list:
            static_connection_signals.update(pad.static_connection_signals)
        return sort_signals(static_connection_signals)

    @property
    def static_connection_signals_soc2pad(self) -> List[Signal]:
        return sort_signals(set([signal for signal in self.static_connection_signals if signal.direction ==
                    SignalDirection.soc2pads]))

    @property
    def static_connection_signals_pad2soc(self) -> List[Signal]:
        return sort_signals(set([signal for signal in self.static_connection_signals if signal.direction ==
                    SignalDirection.pads2soc]))

    @property
    def dynamic_pad_signals(self) -> List[Signal]:
        dynamic_pad_signals = set()
        for pad in self.pad_list:
            dynamic_pad_signals.update(pad.dynamic_pad_signals)
        return sort_signals(dynamic_pad_signals)

    def get_dynamic_pad_signals_for_mux_group(self, mux_group: str) -> List[Signal]:
        dynamic_pad_signals = set()
        for pad in self.pad_list:
            if pad.mux_group == mux_group:
                dynamic_pad_signals.update(pad.dynamic_pad_signals)
        return sort_signals(dynamic_pad_signals)

    @property
    def dynamic_pad_signals_soc2pad(self) -> List[Signal]:
        return sort_signals(set([signal for signal in self.dynamic_pad_signals if signal.direction ==
                          SignalDirection.soc2pads]))

    def get_dynamic_pad_signals_soc2pad_for_mux_group(self, mux_group: str) -> List[Signal]:
        return sort_signals(set([signal for signal in self.get_dynamic_pad_signals_for_mux_group(mux_group) if
                        signal.direction ==
                    SignalDirection.soc2pads]))

    @property
    def dynamic_pad_signals_pad2soc(self):
        return sort_signals(set([signal for signal in self.dynamic_pad_signals if signal.direction ==
                                 SignalDirection.pads2soc]))

    def get_dynamic_pad_signals_pad2soc_for_mux_group(self, mux_group: str):
        return sort_signals(set([signal for signal in self.get_dynamic_pad_signals_for_mux_group(mux_group) if
                        signal.direction ==
                    SignalDirection.pads2soc]))

    def get_ports_in_mux_groups(self, mux_groups: Set[str]) -> List[Port]:
        ports_in_mux_groups = list(itertools.chain(*[port_group.get_ports_in_mux_groups(mux_groups) for port_group in self.port_groups]))
        return ports_in_mux_groups

    def get_dynamic_pads_in_mux_groups(self, mux_groups: Set[str]) -> List[Port]:
        pads_in_mux_groups = [pad for pad in self.pad_list if mux_groups.intersection(pad.mux_groups) and pad.dynamic_pad_signals]
        return sort_pads(pads_in_mux_groups)

    @property
    def port_mux_group_sets(self) -> List[Set[str]]:
        port_mux_group_sets = set((frozenset(port.mux_groups) for port_group in self.port_groups for port in port_group.ports))
        return natsorted(port_mux_group_sets, lambda x: "_".join(natsorted(x)).upper())

    @property
    def pad_mux_group_sets(self) -> List[Set[str]]:
        pad_mux_group_sets = set((frozenset(pad.mux_groups) for pad in self.pad_list if pad.dynamic_pad_signals))
        return natsorted(pad_mux_group_sets, lambda x: "_".join(natsorted(x)).upper())
