module pad_multiplexer
  import pkg_internal_${padframe.name}_${pad_domain.name}::**;
  import pkg_${padframe.name}::*;
#(
  parameter type              req_t  = logic, // reg_interface request type
  parameter type             resp_t  = logic, // reg_interface response type
) (
  input logic clk_i,
  input logic rst_ni,
% if any([port_group.port_signals_soc2pads for port_group in pad_domain.port_groups]):
  input pad_domain_${pad_domain.name}_ports_soc2pad_t ports_soc2pad_i,
% endif
% if any([port_group.port_signals_pads2soc for port_group in pad_domain.port_groups]):
  output pad_domain_${pad_domain.name}_ports_pad2soc_t ports_pad2soc_o,
% endif
% if any([pad.dynamic_pad_signals_soc2pad for pad in pad_domain.pad_list]):
  output mux_to_pads_t mux_to_pads_o,
% endif
% if any([pad.dynamic_pad_signals_soc2pad for pad in pad_domain.pad_list]):
  input pads_to_mux_t pads_to_mux_i,
% endif
  // Configuration interface using register_interface protocol
  input req_t config_req_i,
  output resp_t config_rsp_o
);

  // Register File
  

endmodule : pad_multiplexer
