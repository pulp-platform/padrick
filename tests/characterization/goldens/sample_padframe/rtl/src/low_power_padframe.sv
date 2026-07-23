
module low_power_padframe
  import pkg_low_power_padframe::*;
#(
  parameter int unsigned   AW = 32,
  parameter int unsigned   DW = 32,
  parameter type req_t = logic, // reg_interface request type
  parameter type resp_t = logic, // reg_interface response type
  parameter logic [DW-1:0] DecodeErrRespData = 32'hdeadda7a
)(
  input logic                                clk_i,
  input logic                                rst_ni,
  input override_signals_t                   override_signals,
  output static_connection_signals_pad2soc_t static_connection_signals_pad2soc,
  output port_signals_pad2soc_t              port_signals_pad2soc,
  input port_signals_soc2pad_t               port_signals_soc2pad,
  // Landing Pads
  inout wire logic                           pad_always_on_pads_pad_ref_clk_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa0_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa1_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa2_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa3_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa4_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa5_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa6_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa7_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa8_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa9_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa10_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa11_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa12_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa13_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa14_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa15_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa16_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa17_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa18_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa19_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa20_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa21_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa22_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa23_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa24_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa25_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa26_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa27_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa28_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa29_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa30_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioa31_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob0_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob1_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob2_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob3_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob4_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob5_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob6_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob7_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob8_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob9_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob10_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob11_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob12_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob13_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob14_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob15_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob16_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob17_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob18_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob19_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob20_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob21_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob22_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob23_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob24_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob25_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob26_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob27_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob28_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob29_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob30_pad,
  inout wire logic                           pad_always_on_pads_pad_gpiob31_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioc0_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioc1_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioc2_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioc3_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioc4_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioc5_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioc6_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioc7_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioc8_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioc9_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioc10_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioc11_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioc12_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioc13_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioc14_pad,
  inout wire logic                           pad_always_on_pads_pad_gpioc15_pad,
  // Config Interface
  input req_t                                config_req_i,
  output resp_t                              config_rsp_o
  );


  req_t always_on_pads_config_req;
  resp_t always_on_pads_config_resp;
  low_power_padframe_always_on_pads #(
    .req_t(req_t),
    .resp_t(resp_t)
  ) i_always_on_pads (
   .clk_i,
   .rst_ni,
   .override_signals_i(override_signals.always_on_pads),
   .static_connection_signals_pad2soc(static_connection_signals_pad2soc.always_on_pads),
   .port_signals_pad2soc_o(port_signals_pad2soc.always_on_pads),
   .port_signals_soc2pad_i(port_signals_soc2pad.always_on_pads),
   .pad_pad_ref_clk_pad(pad_always_on_pads_pad_ref_clk_pad),
   .pad_pad_gpioa0_pad(pad_always_on_pads_pad_gpioa0_pad),
   .pad_pad_gpioa1_pad(pad_always_on_pads_pad_gpioa1_pad),
   .pad_pad_gpioa2_pad(pad_always_on_pads_pad_gpioa2_pad),
   .pad_pad_gpioa3_pad(pad_always_on_pads_pad_gpioa3_pad),
   .pad_pad_gpioa4_pad(pad_always_on_pads_pad_gpioa4_pad),
   .pad_pad_gpioa5_pad(pad_always_on_pads_pad_gpioa5_pad),
   .pad_pad_gpioa6_pad(pad_always_on_pads_pad_gpioa6_pad),
   .pad_pad_gpioa7_pad(pad_always_on_pads_pad_gpioa7_pad),
   .pad_pad_gpioa8_pad(pad_always_on_pads_pad_gpioa8_pad),
   .pad_pad_gpioa9_pad(pad_always_on_pads_pad_gpioa9_pad),
   .pad_pad_gpioa10_pad(pad_always_on_pads_pad_gpioa10_pad),
   .pad_pad_gpioa11_pad(pad_always_on_pads_pad_gpioa11_pad),
   .pad_pad_gpioa12_pad(pad_always_on_pads_pad_gpioa12_pad),
   .pad_pad_gpioa13_pad(pad_always_on_pads_pad_gpioa13_pad),
   .pad_pad_gpioa14_pad(pad_always_on_pads_pad_gpioa14_pad),
   .pad_pad_gpioa15_pad(pad_always_on_pads_pad_gpioa15_pad),
   .pad_pad_gpioa16_pad(pad_always_on_pads_pad_gpioa16_pad),
   .pad_pad_gpioa17_pad(pad_always_on_pads_pad_gpioa17_pad),
   .pad_pad_gpioa18_pad(pad_always_on_pads_pad_gpioa18_pad),
   .pad_pad_gpioa19_pad(pad_always_on_pads_pad_gpioa19_pad),
   .pad_pad_gpioa20_pad(pad_always_on_pads_pad_gpioa20_pad),
   .pad_pad_gpioa21_pad(pad_always_on_pads_pad_gpioa21_pad),
   .pad_pad_gpioa22_pad(pad_always_on_pads_pad_gpioa22_pad),
   .pad_pad_gpioa23_pad(pad_always_on_pads_pad_gpioa23_pad),
   .pad_pad_gpioa24_pad(pad_always_on_pads_pad_gpioa24_pad),
   .pad_pad_gpioa25_pad(pad_always_on_pads_pad_gpioa25_pad),
   .pad_pad_gpioa26_pad(pad_always_on_pads_pad_gpioa26_pad),
   .pad_pad_gpioa27_pad(pad_always_on_pads_pad_gpioa27_pad),
   .pad_pad_gpioa28_pad(pad_always_on_pads_pad_gpioa28_pad),
   .pad_pad_gpioa29_pad(pad_always_on_pads_pad_gpioa29_pad),
   .pad_pad_gpioa30_pad(pad_always_on_pads_pad_gpioa30_pad),
   .pad_pad_gpioa31_pad(pad_always_on_pads_pad_gpioa31_pad),
   .pad_pad_gpiob0_pad(pad_always_on_pads_pad_gpiob0_pad),
   .pad_pad_gpiob1_pad(pad_always_on_pads_pad_gpiob1_pad),
   .pad_pad_gpiob2_pad(pad_always_on_pads_pad_gpiob2_pad),
   .pad_pad_gpiob3_pad(pad_always_on_pads_pad_gpiob3_pad),
   .pad_pad_gpiob4_pad(pad_always_on_pads_pad_gpiob4_pad),
   .pad_pad_gpiob5_pad(pad_always_on_pads_pad_gpiob5_pad),
   .pad_pad_gpiob6_pad(pad_always_on_pads_pad_gpiob6_pad),
   .pad_pad_gpiob7_pad(pad_always_on_pads_pad_gpiob7_pad),
   .pad_pad_gpiob8_pad(pad_always_on_pads_pad_gpiob8_pad),
   .pad_pad_gpiob9_pad(pad_always_on_pads_pad_gpiob9_pad),
   .pad_pad_gpiob10_pad(pad_always_on_pads_pad_gpiob10_pad),
   .pad_pad_gpiob11_pad(pad_always_on_pads_pad_gpiob11_pad),
   .pad_pad_gpiob12_pad(pad_always_on_pads_pad_gpiob12_pad),
   .pad_pad_gpiob13_pad(pad_always_on_pads_pad_gpiob13_pad),
   .pad_pad_gpiob14_pad(pad_always_on_pads_pad_gpiob14_pad),
   .pad_pad_gpiob15_pad(pad_always_on_pads_pad_gpiob15_pad),
   .pad_pad_gpiob16_pad(pad_always_on_pads_pad_gpiob16_pad),
   .pad_pad_gpiob17_pad(pad_always_on_pads_pad_gpiob17_pad),
   .pad_pad_gpiob18_pad(pad_always_on_pads_pad_gpiob18_pad),
   .pad_pad_gpiob19_pad(pad_always_on_pads_pad_gpiob19_pad),
   .pad_pad_gpiob20_pad(pad_always_on_pads_pad_gpiob20_pad),
   .pad_pad_gpiob21_pad(pad_always_on_pads_pad_gpiob21_pad),
   .pad_pad_gpiob22_pad(pad_always_on_pads_pad_gpiob22_pad),
   .pad_pad_gpiob23_pad(pad_always_on_pads_pad_gpiob23_pad),
   .pad_pad_gpiob24_pad(pad_always_on_pads_pad_gpiob24_pad),
   .pad_pad_gpiob25_pad(pad_always_on_pads_pad_gpiob25_pad),
   .pad_pad_gpiob26_pad(pad_always_on_pads_pad_gpiob26_pad),
   .pad_pad_gpiob27_pad(pad_always_on_pads_pad_gpiob27_pad),
   .pad_pad_gpiob28_pad(pad_always_on_pads_pad_gpiob28_pad),
   .pad_pad_gpiob29_pad(pad_always_on_pads_pad_gpiob29_pad),
   .pad_pad_gpiob30_pad(pad_always_on_pads_pad_gpiob30_pad),
   .pad_pad_gpiob31_pad(pad_always_on_pads_pad_gpiob31_pad),
   .pad_pad_gpioc0_pad(pad_always_on_pads_pad_gpioc0_pad),
   .pad_pad_gpioc1_pad(pad_always_on_pads_pad_gpioc1_pad),
   .pad_pad_gpioc2_pad(pad_always_on_pads_pad_gpioc2_pad),
   .pad_pad_gpioc3_pad(pad_always_on_pads_pad_gpioc3_pad),
   .pad_pad_gpioc4_pad(pad_always_on_pads_pad_gpioc4_pad),
   .pad_pad_gpioc5_pad(pad_always_on_pads_pad_gpioc5_pad),
   .pad_pad_gpioc6_pad(pad_always_on_pads_pad_gpioc6_pad),
   .pad_pad_gpioc7_pad(pad_always_on_pads_pad_gpioc7_pad),
   .pad_pad_gpioc8_pad(pad_always_on_pads_pad_gpioc8_pad),
   .pad_pad_gpioc9_pad(pad_always_on_pads_pad_gpioc9_pad),
   .pad_pad_gpioc10_pad(pad_always_on_pads_pad_gpioc10_pad),
   .pad_pad_gpioc11_pad(pad_always_on_pads_pad_gpioc11_pad),
   .pad_pad_gpioc12_pad(pad_always_on_pads_pad_gpioc12_pad),
   .pad_pad_gpioc13_pad(pad_always_on_pads_pad_gpioc13_pad),
   .pad_pad_gpioc14_pad(pad_always_on_pads_pad_gpioc14_pad),
   .pad_pad_gpioc15_pad(pad_always_on_pads_pad_gpioc15_pad),
   .config_req_i(always_on_pads_config_req),
   .config_rsp_o(always_on_pads_config_resp)
  );


   localparam int unsigned NUM_PAD_DOMAINS = 1;
   localparam int unsigned REG_ADDR_WIDTH = 10;
   typedef struct packed {
      int unsigned idx;
      logic [REG_ADDR_WIDTH-1:0] start_addr;
      logic [REG_ADDR_WIDTH-1:0] end_addr;
   } addr_rule_t;

   localparam addr_rule_t[NUM_PAD_DOMAINS-1:0] ADDR_DEMUX_RULES = '{
     '{ idx: 0, start_addr: 10'd0,  end_addr: 10'd644}
     };
   logic[$clog2(NUM_PAD_DOMAINS+1)-1:0] pad_domain_sel; // +1 since there is an additional error slave
   addr_decode #(
       .NoIndices(NUM_PAD_DOMAINS+1),
       .NoRules(NUM_PAD_DOMAINS),
       .addr_t(logic[REG_ADDR_WIDTH-1:0]),
       .rule_t(addr_rule_t)
     ) i_addr_decode(
       .addr_i(config_req_i.addr[REG_ADDR_WIDTH-1:0]),
       .addr_map_i(ADDR_DEMUX_RULES),
       .dec_valid_o(),
       .dec_error_o(),
       .idx_o(pad_domain_sel),
       .en_default_idx_i(1'b1),
       .default_idx_i(1'd1) // The last entry is the error slave
     );

     req_t error_slave_req;
     resp_t error_slave_rsp;

     // Config Interface demultiplexing
     reg_demux #(
       .NoPorts(NUM_PAD_DOMAINS+1), //+1 for the error slave
       .req_t(req_t),
       .rsp_t(resp_t)
     ) i_config_demuxer (
       .clk_i,
       .rst_ni,
       .in_select_i(pad_domain_sel),
       .in_req_i(config_req_i),
       .in_rsp_o(config_rsp_o),
       .out_req_o({error_slave_req, always_on_pads_config_req}),
       .out_rsp_i({error_slave_rsp, always_on_pads_config_resp})
     );

     assign error_slave_rsp.error = 1'b1;
     assign error_slave_rsp.rdata = DecodeErrRespData;
     assign error_slave_rsp.ready = 1'b1;

endmodule
