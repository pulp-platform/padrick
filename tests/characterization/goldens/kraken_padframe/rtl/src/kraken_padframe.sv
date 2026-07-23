
module kraken_padframe
  import pkg_kraken_padframe::*;
#(
  parameter int unsigned   AW = 32,
  parameter int unsigned   DW = 32,
  parameter type req_t = logic, // reg_interface request type
  parameter type resp_t = logic, // reg_interface response type
  parameter logic [DW-1:0] DecodeErrRespData = 32'hdeadda7a
)(
  input logic                                clk_i,
  input logic                                rst_ni,
  output static_connection_signals_pad2soc_t static_connection_signals_pad2soc,
  input  static_connection_signals_soc2pad_t static_connection_signals_soc2pad,
  output port_signals_pad2soc_t              port_signals_pad2soc,
  input port_signals_soc2pad_t               port_signals_soc2pad,
  // Landing Pads
  inout wire logic                           pad_aon_pad_bypass_fll_pad,
  inout wire logic                           pad_aon_pad_ext_clk_pad,
  inout wire logic                           pad_aon_pad_ref_clk_pad,
  inout wire logic                           pad_aon_pad_bootsel0_pad,
  inout wire logic                           pad_aon_pad_bootsel1_pad,
  inout wire logic                           pad_aon_pad_bypass_pad,
  inout wire logic                           pad_aon_pad_reset_pad,
  inout wire logic                           pad_aon_pad_jtag_tck_pad,
  inout wire logic                           pad_aon_pad_jtag_tms_pad,
  inout wire logic                           pad_aon_pad_jtag_tdi_pad,
  inout wire logic                           pad_aon_pad_jtag_trstn_pad,
  inout wire logic                           pad_aon_pad_jtag_tdo_pad,
  inout wire logic                           pad_aon_pad_hyp_cs0_pad,
  inout wire logic                           pad_aon_pad_hyp_cs1_pad,
  inout wire logic                           pad_aon_pad_hyp_ck_pad,
  inout wire logic                           pad_aon_pad_hyp_ckn_pad,
  inout wire logic                           pad_aon_pad_hyp_rwds_pad,
  inout wire logic                           pad_aon_pad_hyp_reset_pad,
  inout wire logic                           pad_aon_pad_hyp_dq0_pad,
  inout wire logic                           pad_aon_pad_hyp_dq1_pad,
  inout wire logic                           pad_aon_pad_hyp_dq2_pad,
  inout wire logic                           pad_aon_pad_hyp_dq3_pad,
  inout wire logic                           pad_aon_pad_hyp_dq4_pad,
  inout wire logic                           pad_aon_pad_hyp_dq5_pad,
  inout wire logic                           pad_aon_pad_hyp_dq6_pad,
  inout wire logic                           pad_aon_pad_hyp_dq7_pad,
  inout wire logic                           pad_aon_pad_gpioa0_pad,
  inout wire logic                           pad_aon_pad_gpioa1_pad,
  inout wire logic                           pad_aon_pad_gpioa2_pad,
  inout wire logic                           pad_aon_pad_gpioa3_pad,
  inout wire logic                           pad_aon_pad_gpioa4_pad,
  inout wire logic                           pad_aon_pad_gpioa5_pad,
  inout wire logic                           pad_aon_pad_gpioa6_pad,
  inout wire logic                           pad_aon_pad_gpioa7_pad,
  inout wire logic                           pad_aon_pad_gpioa8_pad,
  inout wire logic                           pad_aon_pad_gpioa9_pad,
  inout wire logic                           pad_aon_pad_gpioa10_pad,
  inout wire logic                           pad_aon_pad_gpioa11_pad,
  inout wire logic                           pad_aon_pad_gpioa12_pad,
  inout wire logic                           pad_aon_pad_gpioa13_pad,
  inout wire logic                           pad_aon_pad_gpioa14_pad,
  inout wire logic                           pad_aon_pad_gpioa15_pad,
  inout wire logic                           pad_aon_pad_gpioa16_pad,
  inout wire logic                           pad_aon_pad_gpioa17_pad,
  inout wire logic                           pad_aon_pad_gpioa18_pad,
  inout wire logic                           pad_aon_pad_gpioa19_pad,
  inout wire logic                           pad_aon_pad_gpioa20_pad,
  inout wire logic                           pad_aon_pad_gpioa21_pad,
  inout wire logic                           pad_aon_pad_gpioa22_pad,
  inout wire logic                           pad_aon_pad_gpioa23_pad,
  inout wire logic                           pad_aon_pad_gpioa24_pad,
  inout wire logic                           pad_aon_pad_gpioa25_pad,
  inout wire logic                           pad_aon_pad_gpiob0_pad,
  inout wire logic                           pad_aon_pad_gpiob1_pad,
  inout wire logic                           pad_aon_pad_gpiob2_pad,
  inout wire logic                           pad_aon_pad_gpiob3_pad,
  inout wire logic                           pad_aon_pad_gpiob4_pad,
  inout wire logic                           pad_aon_pad_gpiob5_pad,
  inout wire logic                           pad_aon_pad_gpiob6_pad,
  inout wire logic                           pad_aon_pad_gpiob7_pad,
  inout wire logic                           pad_aon_pad_gpiob8_pad,
  inout wire logic                           pad_aon_pad_gpiob9_pad,
  inout wire logic                           pad_aon_pad_gpiob10_pad,
  inout wire logic                           pad_aon_pad_gpiob11_pad,
  inout wire logic                           pad_aon_pad_gpiob12_pad,
  inout wire logic                           pad_aon_pad_gpiob13_pad,
  inout wire logic                           pad_aon_pad_gpiob14_pad,
  inout wire logic                           pad_aon_pad_gpiob15_pad,
  // Config Interface
  input req_t                                config_req_i,
  output resp_t                              config_rsp_o
  );


  req_t aon_config_req;
  resp_t aon_config_resp;
  kraken_padframe_aon #(
    .req_t(req_t),
    .resp_t(resp_t)
  ) i_aon (
   .clk_i,
   .rst_ni,
   .static_connection_signals_pad2soc(static_connection_signals_pad2soc.aon),
   .static_connection_signals_soc2pad(static_connection_signals_soc2pad.aon),
   .port_signals_pad2soc_o(port_signals_pad2soc.aon),
   .port_signals_soc2pad_i(port_signals_soc2pad.aon),
   .pad_pad_bypass_fll_pad(pad_aon_pad_bypass_fll_pad),
   .pad_pad_ext_clk_pad(pad_aon_pad_ext_clk_pad),
   .pad_pad_ref_clk_pad(pad_aon_pad_ref_clk_pad),
   .pad_pad_bootsel0_pad(pad_aon_pad_bootsel0_pad),
   .pad_pad_bootsel1_pad(pad_aon_pad_bootsel1_pad),
   .pad_pad_bypass_pad(pad_aon_pad_bypass_pad),
   .pad_pad_reset_pad(pad_aon_pad_reset_pad),
   .pad_pad_jtag_tck_pad(pad_aon_pad_jtag_tck_pad),
   .pad_pad_jtag_tms_pad(pad_aon_pad_jtag_tms_pad),
   .pad_pad_jtag_tdi_pad(pad_aon_pad_jtag_tdi_pad),
   .pad_pad_jtag_trstn_pad(pad_aon_pad_jtag_trstn_pad),
   .pad_pad_jtag_tdo_pad(pad_aon_pad_jtag_tdo_pad),
   .pad_pad_hyp_cs0_pad(pad_aon_pad_hyp_cs0_pad),
   .pad_pad_hyp_cs1_pad(pad_aon_pad_hyp_cs1_pad),
   .pad_pad_hyp_ck_pad(pad_aon_pad_hyp_ck_pad),
   .pad_pad_hyp_ckn_pad(pad_aon_pad_hyp_ckn_pad),
   .pad_pad_hyp_rwds_pad(pad_aon_pad_hyp_rwds_pad),
   .pad_pad_hyp_reset_pad(pad_aon_pad_hyp_reset_pad),
   .pad_pad_hyp_dq0_pad(pad_aon_pad_hyp_dq0_pad),
   .pad_pad_hyp_dq1_pad(pad_aon_pad_hyp_dq1_pad),
   .pad_pad_hyp_dq2_pad(pad_aon_pad_hyp_dq2_pad),
   .pad_pad_hyp_dq3_pad(pad_aon_pad_hyp_dq3_pad),
   .pad_pad_hyp_dq4_pad(pad_aon_pad_hyp_dq4_pad),
   .pad_pad_hyp_dq5_pad(pad_aon_pad_hyp_dq5_pad),
   .pad_pad_hyp_dq6_pad(pad_aon_pad_hyp_dq6_pad),
   .pad_pad_hyp_dq7_pad(pad_aon_pad_hyp_dq7_pad),
   .pad_pad_gpioa0_pad(pad_aon_pad_gpioa0_pad),
   .pad_pad_gpioa1_pad(pad_aon_pad_gpioa1_pad),
   .pad_pad_gpioa2_pad(pad_aon_pad_gpioa2_pad),
   .pad_pad_gpioa3_pad(pad_aon_pad_gpioa3_pad),
   .pad_pad_gpioa4_pad(pad_aon_pad_gpioa4_pad),
   .pad_pad_gpioa5_pad(pad_aon_pad_gpioa5_pad),
   .pad_pad_gpioa6_pad(pad_aon_pad_gpioa6_pad),
   .pad_pad_gpioa7_pad(pad_aon_pad_gpioa7_pad),
   .pad_pad_gpioa8_pad(pad_aon_pad_gpioa8_pad),
   .pad_pad_gpioa9_pad(pad_aon_pad_gpioa9_pad),
   .pad_pad_gpioa10_pad(pad_aon_pad_gpioa10_pad),
   .pad_pad_gpioa11_pad(pad_aon_pad_gpioa11_pad),
   .pad_pad_gpioa12_pad(pad_aon_pad_gpioa12_pad),
   .pad_pad_gpioa13_pad(pad_aon_pad_gpioa13_pad),
   .pad_pad_gpioa14_pad(pad_aon_pad_gpioa14_pad),
   .pad_pad_gpioa15_pad(pad_aon_pad_gpioa15_pad),
   .pad_pad_gpioa16_pad(pad_aon_pad_gpioa16_pad),
   .pad_pad_gpioa17_pad(pad_aon_pad_gpioa17_pad),
   .pad_pad_gpioa18_pad(pad_aon_pad_gpioa18_pad),
   .pad_pad_gpioa19_pad(pad_aon_pad_gpioa19_pad),
   .pad_pad_gpioa20_pad(pad_aon_pad_gpioa20_pad),
   .pad_pad_gpioa21_pad(pad_aon_pad_gpioa21_pad),
   .pad_pad_gpioa22_pad(pad_aon_pad_gpioa22_pad),
   .pad_pad_gpioa23_pad(pad_aon_pad_gpioa23_pad),
   .pad_pad_gpioa24_pad(pad_aon_pad_gpioa24_pad),
   .pad_pad_gpioa25_pad(pad_aon_pad_gpioa25_pad),
   .pad_pad_gpiob0_pad(pad_aon_pad_gpiob0_pad),
   .pad_pad_gpiob1_pad(pad_aon_pad_gpiob1_pad),
   .pad_pad_gpiob2_pad(pad_aon_pad_gpiob2_pad),
   .pad_pad_gpiob3_pad(pad_aon_pad_gpiob3_pad),
   .pad_pad_gpiob4_pad(pad_aon_pad_gpiob4_pad),
   .pad_pad_gpiob5_pad(pad_aon_pad_gpiob5_pad),
   .pad_pad_gpiob6_pad(pad_aon_pad_gpiob6_pad),
   .pad_pad_gpiob7_pad(pad_aon_pad_gpiob7_pad),
   .pad_pad_gpiob8_pad(pad_aon_pad_gpiob8_pad),
   .pad_pad_gpiob9_pad(pad_aon_pad_gpiob9_pad),
   .pad_pad_gpiob10_pad(pad_aon_pad_gpiob10_pad),
   .pad_pad_gpiob11_pad(pad_aon_pad_gpiob11_pad),
   .pad_pad_gpiob12_pad(pad_aon_pad_gpiob12_pad),
   .pad_pad_gpiob13_pad(pad_aon_pad_gpiob13_pad),
   .pad_pad_gpiob14_pad(pad_aon_pad_gpiob14_pad),
   .pad_pad_gpiob15_pad(pad_aon_pad_gpiob15_pad),
   .config_req_i(aon_config_req),
   .config_rsp_o(aon_config_resp)
  );


   localparam int unsigned NUM_PAD_DOMAINS = 1;
   localparam int unsigned REG_ADDR_WIDTH = 9;
   typedef struct packed {
      int unsigned idx;
      logic [REG_ADDR_WIDTH-1:0] start_addr;
      logic [REG_ADDR_WIDTH-1:0] end_addr;
   } addr_rule_t;

   localparam addr_rule_t[NUM_PAD_DOMAINS-1:0] ADDR_DEMUX_RULES = '{
     '{ idx: 0, start_addr: 9'd0,  end_addr: 9'd340}
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
       .out_req_o({error_slave_req, aon_config_req}),
       .out_rsp_i({error_slave_rsp, aon_config_resp})
     );

     assign error_slave_rsp.error = 1'b1;
     assign error_slave_rsp.rdata = DecodeErrRespData;
     assign error_slave_rsp.ready = 1'b1;

endmodule
