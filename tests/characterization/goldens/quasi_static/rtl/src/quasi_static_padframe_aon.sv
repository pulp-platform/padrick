
module quasi_static_padframe_aon
  import pkg_quasi_static_padframe::*;
  import pkg_internal_quasi_static_padframe_aon::*;
#(
  parameter type              req_t  = logic, // reg_interface request type
  parameter type             resp_t  = logic // reg_interface response type
) (
  input logic clk_i,
  input logic rst_ni,
  output pad_domain_aon_ports_pad2soc_t port_signals_pad2soc_o,
  input pad_domain_aon_ports_soc2pad_t port_signals_soc2pad_i,
  inout wire logic pad_pad_hw_pad,
  inout wire logic pad_pad_qs_pad,
  inout wire logic pad_pad_io0_pad,
  inout wire logic pad_pad_io1_pad,
  input req_t config_req_i,
  output resp_t config_rsp_o
);

   mux_to_pads_t s_mux_to_pads;
   pads_to_mux_t s_pads_to_mux;

   quasi_static_padframe_aon_pads i_aon_pads (
     .mux_to_pads_i(s_mux_to_pads),
     .pads_to_mux_o(s_pads_to_mux),
     .pad_pad_hw_pad,
     .pad_pad_qs_pad,
     .pad_pad_io0_pad,
     .pad_pad_io1_pad

  );

   quasi_static_padframe_aon_muxer #(
     .req_t(req_t),
     .resp_t(resp_t)
   )i_aon_muxer (
     .clk_i,
     .rst_ni,
     .port_signals_soc2pad_i,
     .port_signals_pad2soc_o,
     .mux_to_pads_o(s_mux_to_pads),
     .pads_to_mux_i(s_pads_to_mux),
     // Configuration interface using register_interface protocol
     .config_req_i,
     .config_rsp_o
   );

endmodule : quasi_static_padframe_aon
