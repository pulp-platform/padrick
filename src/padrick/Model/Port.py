from functools import reduce
from typing import Optional, Mapping, Union, Set

from Model.Constants import SYSTEM_VERILOG_IDENTIFIER
from Model.ParseContext import PARSE_CONTEXT
from Model.PadSignal import PadSignal, ConnectionType, PadSignalKind, Signal
from Model.SignalExpressionType import SignalExpressionType
from pydantic import BaseModel, constr, validator, Extra


class Port(BaseModel):
    name: constr(regex=SYSTEM_VERILOG_IDENTIFIER)
    description: Optional[str]
    connections: Optional[Mapping[Union[Signal, str], Optional[SignalExpressionType]]]

    #pydantic model config
    class Config:
        extra = Extra.forbid

    @validator('connections')
    def link_and_validate_connections(cls, v: Mapping[str, SignalExpressionType], values):
        linked_connections = {}
        for pad_signal_name, expression in v.items():
            pad_signal_instances = PARSE_CONTEXT.find_pad_signal_instances(pad_signal_name)
            if len(pad_signal_instances) == 0:
                raise ValueError(f'Found reference to unknown pad_signal {pad_signal_name} in Port connections.')

            #Disallow connection for purely static pad_signals
            if all([ps.conn_type == ConnectionType.static for ps in pad_signal_instances]):
                raise ValueError(f"Found reference to static pad_signal {pad_signal_name}. Only pad_signal names that are of 'conn_type' "
                                 f"dynamic for at least one pad can be used in the port connection mapping.")

            # Replace expression of type None with empty expression instance
            if not expression:
                expression = SignalExpressionType.validate(None)
            #Generate Signal instance from size informatin of the discovered pad_signal_instance. The PadDomain
            # validator ensures, that all pad_signal instances have the same size so it doesn't matter which instance
            # we use for that matter
            signal = Signal(name=pad_signal_name, size=pad_signal_instances[0].size)
            linked_connections[signal] = expression
        return linked_connections

    @property
    def port_signals(self) -> Set[Signal]:
        port_signals = set()
        if self.connections:
            for pad_signal, expr in self.connections.items():
                for signal_name in expr.signal_collection:
                    port_signal = Signal(name=signal_name, size=pad_signal.size)
                    port_signals.add(port_signal)
        return port_signals