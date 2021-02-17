module padframe_${padframe.name}_pad_domain_${pad_domain.name}_pads
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
  inout pad_domain_${pad_domain.name}_landing_pads_t pads
  // Dynamic Pad control signals, these signals are controlled by the multiplexer in the correpsongin pad_controller module
  );

   // Pad instantiations
% for pad in pad_domain.pad_list:
 % if pad.multiple > 1:
  % for i in range(pad.multiple):
  <%
    instance_name = f"i_{pad.name}{i}"
    connections = {}
    static_signal_name_mapping = {signal.name: f'static_connection_signals_pad2soc.{signal.name}' for signal in pad.static_connection_signals}
    override_signal_name_mapping = {signal.name: f'override_signals_i.{signal.name}' for signal in pad.override_signals}
    for ps in pad.static_pad_signals:
      if ps in pad.static_pad_signal_connections:
        connections[ps] = pad.static_pad_signal_connections[ps].get_mapped_expr(static_signal_name_mapping).expression
      else:
        connections[ps] = " "
    for ps in pad.dynamic_pad_signals:
      connections[ps] = "42"
    for ps in pad.landing_pads:
      connections[ps] = f"pads.{pad.name}{i}_pad"
    for ps, expr in connections.items():
      if not ps.or_override_signal.is_empty:
        connections[ps] = f'({expr})|({ps.or_override_signal.get_mapped_expr(override_signal_name_mapping).expression})'
      if not ps.and_override_signal.is_empty:
        connections[ps] = f'({expr})&({ps.and_override_signal.get_mapped_expr(override_signal_name_mapping).expression})'
    pad_signal_connection = {signal.name: expr for signal, expr in connections.items()}
    print(pad_signal_connection)
  %>
   % for line in pad.pad_type.template.render(instance_name=instance_name, pad_signal_connection=pad_signal_connection).splitlines():
  ${line}
   % endfor
  % endfor
 % else:
  <%
    instance_name = f"i_{pad.name}"
    connections = {}
    static_signal_name_mapping = {signal.name: f'static_connection_signals_pad2soc.{signal.name}' for signal in pad.static_connection_signals}
    override_signal_name_mapping = {signal.name: f'override_signals_i.{signal.name}' for signal in pad.override_signals}
    print(f"Static mapping for pad {pad.name}: {static_signal_name_mapping}")
    for ps in pad.static_pad_signals:
      connections[ps] = pad.static_pad_signal_connections[ps].get_mapped_expr(static_signal_name_mapping)
    for ps in pad.dynamic_pad_signals:
      connections[ps] = "42"
    for ps in pad.landing_pads:
      connections[ps] = f"pads.{pad.name}_{ps.name}"
    for ps, expr in connections.items():
      if not ps.or_override_signal.is_empty:
        connections[ps] = f'({expr})|({ps.or_override_signal.get_mapped_expr(override_signal_name_mapping)})'
      if not ps.and_override_signal.is_empty:
        connections[ps] = f'({expr})&({ps.and_override_signal.get_mapped_expr(override_signal_name_mapping)})'
    pad_signal_connection = {signal.name: str(expr) for signal, expr in connections.items()}
    print(pad_signal_connection)  
  %>
  % for line in pad.pad_type.template.render(instance_name=instance_name, pad_signal_connection=pad_signal_connection).splitlines():
  ${line}
  % endfor
 % endif

% endfor

endmodule : padframe_${padframe.name}_pad_domain_${pad_domain.name}_pads
