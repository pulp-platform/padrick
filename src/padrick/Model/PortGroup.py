from typing import Optional, List, Set, Mapping, Union

from Model.Constants import SYSTEM_VERILOG_IDENTIFIER
from Model.PadSignal import Signal, SignalDirection
from Model.Port import Port
from Model.SignalExpressionType import SignalExpressionType
from pydantic import BaseModel, constr, conlist, validator


class PortGroup(BaseModel):
    name: constr(regex=SYSTEM_VERILOG_IDENTIFIER)
    description: Optional[str]
    ports: List[Port]
    connection_defaults: Optional[Mapping[Union[Signal, str], Optional[SignalExpressionType]]]


    @validator('connection_defaults')
    def validate_and_link_output_defaults(cls, v: Mapping[str, SignalExpressionType], values):
        """Make sure the signals specified in connection_defaults are actually pad2chip port signals and make sure
        the associated expression is static."""
        linked_connection_defaults: Mapping[Signal, SignalExpressionType] = {}
        for signal_name, expression in v:
            port_signals = set.union(*[port for port in values['ports']])
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






    @validator('ports')
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


    @property
    def port_signals(self) -> Set[Signal]:
        return set.union(*[port.port_signals for port in self.ports])

    @property
    def port_signals_soc2pads(self) -> Set[Signal]:
        return set([signal for signal in self.port_signals if signal.direction == SignalDirection.soc2pads])

    @property
    def port_signals_pads2soc(self) -> Set[Signal]:
        return set([signal for signal in self.port_signals if signal.direction == SignalDirection.pads2soc])