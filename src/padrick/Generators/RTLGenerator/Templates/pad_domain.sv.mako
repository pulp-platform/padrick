module ${padframe.name}_${pad_domain.name}
  import pkg_${padframe.name}::*;
  import pkg_internal_${padframe.name}_${pad_domain.name}::*;
#(
  parameter type              req_t  = logic, // reg_interface request type
  parameter type             resp_t  = logic // reg_interface response type
) (
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
  output pad_domain_${pad_domain.name}_ports_pad2soc_t port_signals_pad2soc_o,
% endif
% if any([port_group.port_signals_soc2pads for port_group in pad_domain.port_groups]):
  input pad_domain_${pad_domain.name}_ports_soc2pad_t port_signals_soc2pad_i,
% endif
  inout wire pad_domain_${pad_domain.name}_landing_pads_t pads,
  input req_t config_req_i,
  output resp_t config_rsp_o
);

% if any([pad.dynamic_pad_signals_soc2pad for pad in pad_domain.pad_list]):
   mux_to_pads_t s_mux_to_pads;
% endif
% if any([pad.dynamic_pad_signals_pad2soc for pad in pad_domain.pad_list]):
   pads_to_mux_t s_pads_to_mux;

% endif
   ${padframe.name}_${pad_domain.name}_pads i_${pad_domain.name}_pads (
% if pad_domain.override_signals:
     .override_signals_i,
% endif
% if pad_domain.static_connection_signals_pad2soc:
     .static_connection_signals_pad2soc,
% endif
% if pad_domain.static_connection_signals_soc2pad:
     .static_connection_signals_soc2pad,
% endif
% if any([pad.dynamic_pad_signals_soc2pad for pad in pad_domain.pad_list]):
     .mux_to_pads_i(s_mux_to_pads),
% endif
% if any([pad.dynamic_pad_signals_pad2soc for pad in pad_domain.pad_list]):
     .pads_to_mux_o(s_pads_to_mux),
% endif
     .pads
   );

   ${padframe.name}_${pad_domain.name}_muxer #(
     .req_t(req_t),
     .resp_t(resp_t)
   )i_${pad_domain.name}_muxer (
     .clk_i,
     .rst_ni,
% if any([port_group.port_signals_soc2pads for port_group in pad_domain.port_groups]):
     .port_signals_soc2pad_i,
% endif
% if any([port_group.port_signals_pads2soc for port_group in pad_domain.port_groups]):
     .port_signals_pad2soc_o,
% endif
% if any([pad.dynamic_pad_signals_soc2pad for pad in pad_domain.pad_list]):
     .mux_to_pads_o(s_mux_to_pads),
% endif
% if any([pad.dynamic_pad_signals_soc2pad for pad in pad_domain.pad_list]):
     .pads_to_mux_i(s_pads_to_mux),
% endif
     // Configuration interface using register_interface protocol
     .config_req_i,
     .config_rsp_o
   );

endmodule : ${padframe.name}_${pad_domain.name}
