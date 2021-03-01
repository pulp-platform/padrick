from typing import Optional, List, Set, Mapping, Union

from padrick.Model.Constants import SYSTEM_VERILOG_IDENTIFIER
from padrick.Model.PadSignal import Signal, SignalDirection
from padrick.Model.Port import Port
from padrick.Model.SignalExpressionType import SignalExpressionType
from pydantic import BaseModel, constr, conlist, validator, root_validator


class PortGroup(BaseModel):
    name: constr(regex=SYSTEM_VERILOG_IDENTIFIER)
    description: Optional[str]
    mux_group: Optional[constr(strip_whitespace=True, regex=SYSTEM_VERILOG_IDENTIFIER)]
    ports: List[Port]
    output_defaults: Mapping[Union[Signal, str], Optional[SignalExpressionType]] = {}

    @validator('output_defaults')
    def validate_and_link_output_defaults(cls, v: Mapping[str, SignalExpressionType], values):
        """Make sure the signals specified in connection_defaults are actually pad2chip port signals and make sure
        the associated expression is static."""
        linked_connection_defaults: Mapping[Signal, SignalExpressionType] = {}
        for signal_name, expression in v.items():
            port_signals = set.union(*[port.port_signals for port in values.get('ports', [])])
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

    @root_validator(skip_on_failure=True)
    def check_all_pad2soc_ports_have_default(cls, values):
        port_signals_pad2soc = set()
        for port in values['ports']:
            port_signals_pad2soc.update(port.port_signals_pad2chip)
        for port in port_signals_pad2soc:
            if port not in values['output_defaults'] and port.name not in values['output_defaults']:
                raise ValueError(f"Found port signal {port.name} with direction pad2soc that does not specify a connection default.")
        return values


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

    @validator('ports')
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

    @validator('ports', each_item=True)
    def override_port_mux_group(cls, port, values):
        if values.get('mux_group', None):
            port.mux_group = values['mux_group']
        return port


    @property
    def port_signals(self) -> Set[Signal]:
        return set.union(*[port.port_signals for port in self.ports])

    @property
    def port_signals_soc2pads(self) -> Set[Signal]:
        return set([signal for signal in self.port_signals if signal.direction == SignalDirection.soc2pads])

    @property
    def port_signals_pads2soc(self) -> Set[Signal]:
        return set([signal for signal in self.port_signals if signal.direction == SignalDirection.pads2soc])

    def get_port_signals_for_mux_group(self, mux_group: str) -> Set[Signal]:
        return set.union(*[port.port_signals for port in self.ports if port.mux_group == mux_group])

    def get_port_signals_soc2pads_for_mux_group(self, mux_group: str) -> Set[Signal]:
        return set([signal for signal in self.get_port_signals_for_mux_group(mux_group) if signal.direction ==
                    SignalDirection.soc2pads])

    def port_signals_pads2soc_for_mux_group(self, mux_group: str) -> Set[Signal]:
        return set([signal for signal in self.get_port_signals_for_mux_group(mux_group) if signal.direction ==
                    SignalDirection.pads2soc])
