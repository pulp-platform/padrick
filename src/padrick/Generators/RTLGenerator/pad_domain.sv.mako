module ${padframe.name}_${pad_domain.name} (
  input logic clk_i,
  input logic rst_ni,
% if pad_domain.override_signals:
  input pad_domain_${pad_domain.name}_override_signals_t override_signals_i,
% endif
% if pad_domain.static_connection_signals_pad2soc:
  output pad_domain_${pad_domain.name}_static_connection_signals_pad2soc_t static_connection_signals_pad2soc,
% endif
% if pad_domain.static_connection_signals_soc2pad:
  input pad_domain_${pad_domain.name}_static_connection_signals_soc2pad_t static_connection_signals_soc2pad,
% endif
% if any([port_group.port_signals_pads2soc for port_group in pad_domain.port_groups]):
  output pad_domain_${pad_domain.name}_ports_pad2soc_t port_signals_pad2soc,
% endif
% if any([port_group.port_signals_soc2pads for port_group in pad_domain.port_groups]):
  input pad_domain_${pad_domain.name}_ports_soc2pad_t port_signals_soc2pad,
% endif
  inout pad_domain_${pad_domain.name}_landing_pads_t pads
);



endmodule : ${padframe.name}_${pad_domain.name}
