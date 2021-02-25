module ${padframe.name}_${pad_domain.name}_pads
  import pkg_${padframe.name}::*;
  import pkg_internal_${padframe.name}_${pad_domain.name}::*;
(
% if pad_domain.override_signals:
  //Override signals
  input  pad_domain_${pad_domain.name}_override_signals_t override_signals_i,
% endif
% if pad_domain.static_connection_signals_pad2soc:
  output pad_domain_${pad_domain.name}_static_connection_signals_pad2soc_t static_connection_signals_pad2soc,
% endif
% if pad_domain.static_connection_signals_soc2pad:
  input  pad_domain_${pad_domain.name}_static_connection_signals_soc2pad_t static_connection_signals_soc2pad,
% endif
 // Dynamic Pad control signals, these signals are controlled by the multiplexer in the correpsongin pad_controller module
% if any([pad.dynamic_pad_signals_soc2pad for pad in pad_domain.pad_list]):
  input mux_to_pads_t mux_to_pads_i,
% endif
% if any([pad.dynamic_pad_signals_soc2pad for pad in pad_domain.pad_list]):
  output pads_to_mux_t pads_to_mux_o,
% endif
  inout pad_domain_${pad_domain.name}_landing_pads_t pads
  );

   // Pad instantiations
% for pad in pad_domain.pad_list:
% for i in range(pad.multiple):
<%
  from padrick.Model.PadSignal import SignalDirection
  pad_suffix = i if pad.multiple > 1 else ""
  instance_name = f"i_{pad.name}{pad_suffix}"
  connections = {}
  static_signal_name_mapping = {signal.name: f'static_connection_signals_pad2soc.{signal.name}' for signal in pad.static_connection_signals if signal.direction == SignalDirection.pads2soc}
  static_signal_name_mapping.update({signal.name: f'static_connection_signals_soc2pad.{signal.name}' for signal in pad.static_connection_signals if signal.direction == SignalDirection.soc2pads})
  override_signal_name_mapping = {signal.name: f'override_signals_i.{signal.name}' for signal in pad.override_signals}
  for ps in pad.static_pad_signals:
    if ps in pad.static_pad_signal_connections:
      connections[ps] = pad.static_pad_signal_connections[ps].get_mapped_expr(static_signal_name_mapping).expression
    else:
      connections[ps] = " "
  for ps in pad.dynamic_pad_signals_soc2pad:
    connections[ps] = f"mux_to_pads_i.{pad.name}{pad_suffix}.{ps.name}"
  for ps in pad.dynamic_pad_signals_pad2soc:
    connections[ps] = f"pads_to_mux_o.{pad.name}{pad_suffix}.{ps.name}"
  for ps in pad.landing_pads:
    connections[ps] = f"pads.{pad.name}{pad_suffix}_pad"
  for ps, expr in connections.items():
    if not ps.or_override_signal.is_empty:
      connections[ps] = f'({expr})|({ps.or_override_signal.get_mapped_expr(override_signal_name_mapping).expression})'
    if not ps.and_override_signal.is_empty:
      connections[ps] = f'({expr})&({ps.and_override_signal.get_mapped_expr(override_signal_name_mapping).expression})'
  pad_signal_connection = {signal.name: expr for signal, expr in connections.items()}
  # print(pad_signal_connection)
%> \
% for line in pad.pad_type.template.render(instance_name=instance_name, pad_signal_connection=pad_signal_connection).splitlines():
  ${line}
% endfor
% endfor
% endfor

endmodule : ${padframe.name}_${pad_domain.name}_pads
