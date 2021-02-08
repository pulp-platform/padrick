from typing import List, Optional, Set

from Model.Constants import SYSTEM_VERILOG_IDENTIFIER
from Model.PadInstance import PadInstance
from Model.PadSignal import Signal
from Model.PadType import PadType
from Model.ParseContext import PARSE_CONTEXT
from Model.PortGroup import PortGroup
from pydantic import BaseModel, constr, conlist, root_validator


class PadDomain(BaseModel):
    """
    A pad_domain contains the configuration about one collection of pads and ports that can connected with each other.
    """
    name: constr(regex=SYSTEM_VERILOG_IDENTIFIER)
    description: Optional[str]
    pad_types: conlist(PadType, min_items=1)
    pad_list: conlist(PadInstance, min_items=1)
    port_groups: List[PortGroup]


    @root_validator(skip_on_failure=True)
    def check_padsignal_with_same_name_have_same_size(cls, values):
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



    def __init__(self, *args, **kwargs):
        PARSE_CONTEXT.set_context(self)
        super().__init__(*args, **kwargs)

