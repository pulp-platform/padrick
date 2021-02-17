from typing import List, Optional, Set, Mapping

from Model.Constants import SYSTEM_VERILOG_IDENTIFIER
from Model.PadInstance import PadInstance
from Model.PadSignal import Signal, SignalDirection
from Model.PadType import PadType
from Model.ParseContext import PARSE_CONTEXT
from Model.PortGroup import PortGroup
from pydantic import BaseModel, constr, conlist, root_validator, validator


class PadDomain(BaseModel):
    """
    A pad_domain contains the configuration about one collection of pads and ports that can connected with each other.
    """
    name: constr(regex=SYSTEM_VERILOG_IDENTIFIER)
    description: Optional[str]
    pad_types: conlist(PadType, min_items=1)
    pad_list: conlist(PadInstance, min_items=1)
    port_groups: List[PortGroup]


    def __init__(self, *args, **kwargs):
        PARSE_CONTEXT.set_context(self)
        super().__init__(*args, **kwargs)

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
                else:
                    seen[signal.name] = signal
        return v

    @property
    def override_signals(self) -> Set[Signal]:
        override_signals = set()
        for pad in self.pad_list:
            override_signals.update(pad.override_signals)
        return override_signals

    @property
    def static_connection_signals(self) -> Set[Signal]:
        static_connection_signals = set()
        for pad in self.pad_list:
            static_connection_signals.update(pad.static_connection_signals)
        return static_connection_signals

    @property
    def static_connection_signals_soc2pad(self) -> Set[Signal]:
        return set([signal for signal in self.static_connection_signals if signal.direction ==
                    SignalDirection.soc2pads])

    @property
    def static_connection_signals_pad2soc(self) -> Set[Signal]:
        return set([signal for signal in self.static_connection_signals if signal.direction ==
                    SignalDirection.pads2soc])
