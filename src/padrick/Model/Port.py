from functools import reduce
from typing import Optional, Mapping, Union, Set

from padrick.Model.Constants import SYSTEM_VERILOG_IDENTIFIER
from padrick.Model.ParseContext import PARSE_CONTEXT
from padrick.Model.PadSignal import PadSignal, ConnectionType, PadSignalKind, Signal, SignalDirection
from padrick.Model.SignalExpressionType import SignalExpressionType
from pydantic import BaseModel, constr, validator, Extra, PrivateAttr


class Port(BaseModel):
    name: constr(regex=SYSTEM_VERILOG_IDENTIFIER)
    description: Optional[str]
    connections: Optional[Mapping[Union[Signal, str], Optional[SignalExpressionType]]]
    mux_group: constr(strip_whitespace=True, regex=SYSTEM_VERILOG_IDENTIFIER) = "all"

    #pydantic model config
    class Config:
        extra = Extra.forbid


    @validator('connections')
    def link_and_validate_connections(cls, v: Mapping[str, SignalExpressionType], values):
        linked_connections = {}
        for signal_name, expression in v.items():
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

    @property
    def port_signals_chip2pad(self) -> Set[Signal]:
        port_signals = set()
        if self.connections:
            for signal, expr in self.connections.items():
                if signal.direction == SignalDirection.soc2pads:
                    for signal_name in expr.signal_collection:
                        port_signal = Signal(name=signal_name, size=signal.size, direction=signal.direction)
                        port_signals.add(port_signal)
        return port_signals

    @property
    def port_signals_pad2chip(self) -> Set[Signal]:
        port_signals = set()
        if self.connections:
            for signal, expr in self.connections.items():
                if signal.direction == SignalDirection.pads2soc:
                    port_signals.add(signal)
        return port_signals

    @property
    def port_signals(self) -> Set[Signal]:
        """

        Returns: The union of pad2chip and chip2pad port signals.

        """
        return self.port_signals_pad2chip | self.port_signals_chip2pad

