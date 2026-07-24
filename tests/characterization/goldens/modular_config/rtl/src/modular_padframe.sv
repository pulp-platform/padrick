
module modular_padframe
  import pkg_modular_padframe::*;
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
  inout wire logic                           pad_domain_pad_ref_clk_pad_p,
  inout wire logic                           pad_domain_pad_ref_clk_pad_n,
  inout wire logic                           pad_domain_pad_clk_byp_pad,
  inout wire logic                           pad_domain_pad_reset_n_pad,
  inout wire logic                           pad_domain_pad_debug_en_pad,
  inout wire logic                           pad_domain_pad_jtag_tck_pad,
  inout wire logic                           pad_domain_pad_jtag_trst_pad,
  inout wire logic                           pad_domain_pad_jtag_tms_pad,
  inout wire logic                           pad_domain_pad_jtag_tdi_pad,
  inout wire logic                           pad_domain_pad_jtag_tdo_pad,
  inout wire logic                           pad_domain_pad_io00_pad,
  inout wire logic                           pad_domain_pad_io01_pad,
  inout wire logic                           pad_domain_pad_io02_pad,
  inout wire logic                           pad_domain_pad_io03_pad,
  inout wire logic                           pad_domain_pad_io04_pad,
  inout wire logic                           pad_domain_pad_io05_pad,
  inout wire logic                           pad_domain_pad_io06_pad,
  inout wire logic                           pad_domain_pad_io07_pad,
  inout wire logic                           pad_domain_pad_io08_pad,
  inout wire logic                           pad_domain_pad_io09_pad,
  inout wire logic                           pad_domain_pad_io10_pad,
  inout wire logic                           pad_domain_pad_io11_pad,
  inout wire logic                           pad_domain_pad_io12_pad,
  inout wire logic                           pad_domain_pad_io13_pad,
  inout wire logic                           pad_domain_pad_io14_pad,
  inout wire logic                           pad_domain_pad_io15_pad,
  inout wire logic                           pad_domain_pad_io16_pad,
  inout wire logic                           pad_domain_pad_io17_pad,
  inout wire logic                           pad_domain_pad_io18_pad,
  inout wire logic                           pad_domain_pad_io19_pad,
  inout wire logic                           pad_domain_pad_io20_pad,
  inout wire logic                           pad_domain_pad_io21_pad,
  inout wire logic                           pad_domain_pad_io22_pad,
  inout wire logic                           pad_domain_pad_io23_pad,
  inout wire logic                           pad_domain_pad_io24_pad,
  inout wire logic                           pad_domain_pad_io25_pad,
  inout wire logic                           pad_domain_pad_io26_pad,
  inout wire logic                           pad_domain_pad_io27_pad,
  inout wire logic                           pad_domain_pad_io28_pad,
  inout wire logic                           pad_domain_pad_io29_pad,
  inout wire logic                           pad_domain_pad_io30_pad,
  inout wire logic                           pad_domain_pad_io31_pad,
  // Config Interface
  input req_t                                config_req_i,
  output resp_t                              config_rsp_o
  );


  req_t domain_config_req;
  resp_t domain_config_resp;
  modular_padframe_domain #(
    .req_t(req_t),
    .resp_t(resp_t)
  ) i_domain (
   .clk_i,
   .rst_ni,
   .static_connection_signals_pad2soc(static_connection_signals_pad2soc.domain),
   .static_connection_signals_soc2pad(static_connection_signals_soc2pad.domain),
   .port_signals_pad2soc_o(port_signals_pad2soc.domain),
   .port_signals_soc2pad_i(port_signals_soc2pad.domain),
   .pad_pad_ref_clk_pad_p(pad_domain_pad_ref_clk_pad_p),
   .pad_pad_ref_clk_pad_n(pad_domain_pad_ref_clk_pad_n),
   .pad_pad_clk_byp_pad(pad_domain_pad_clk_byp_pad),
   .pad_pad_reset_n_pad(pad_domain_pad_reset_n_pad),
   .pad_pad_debug_en_pad(pad_domain_pad_debug_en_pad),
   .pad_pad_jtag_tck_pad(pad_domain_pad_jtag_tck_pad),
   .pad_pad_jtag_trst_pad(pad_domain_pad_jtag_trst_pad),
   .pad_pad_jtag_tms_pad(pad_domain_pad_jtag_tms_pad),
   .pad_pad_jtag_tdi_pad(pad_domain_pad_jtag_tdi_pad),
   .pad_pad_jtag_tdo_pad(pad_domain_pad_jtag_tdo_pad),
   .pad_pad_io00_pad(pad_domain_pad_io00_pad),
   .pad_pad_io01_pad(pad_domain_pad_io01_pad),
   .pad_pad_io02_pad(pad_domain_pad_io02_pad),
   .pad_pad_io03_pad(pad_domain_pad_io03_pad),
   .pad_pad_io04_pad(pad_domain_pad_io04_pad),
   .pad_pad_io05_pad(pad_domain_pad_io05_pad),
   .pad_pad_io06_pad(pad_domain_pad_io06_pad),
   .pad_pad_io07_pad(pad_domain_pad_io07_pad),
   .pad_pad_io08_pad(pad_domain_pad_io08_pad),
   .pad_pad_io09_pad(pad_domain_pad_io09_pad),
   .pad_pad_io10_pad(pad_domain_pad_io10_pad),
   .pad_pad_io11_pad(pad_domain_pad_io11_pad),
   .pad_pad_io12_pad(pad_domain_pad_io12_pad),
   .pad_pad_io13_pad(pad_domain_pad_io13_pad),
   .pad_pad_io14_pad(pad_domain_pad_io14_pad),
   .pad_pad_io15_pad(pad_domain_pad_io15_pad),
   .pad_pad_io16_pad(pad_domain_pad_io16_pad),
   .pad_pad_io17_pad(pad_domain_pad_io17_pad),
   .pad_pad_io18_pad(pad_domain_pad_io18_pad),
   .pad_pad_io19_pad(pad_domain_pad_io19_pad),
   .pad_pad_io20_pad(pad_domain_pad_io20_pad),
   .pad_pad_io21_pad(pad_domain_pad_io21_pad),
   .pad_pad_io22_pad(pad_domain_pad_io22_pad),
   .pad_pad_io23_pad(pad_domain_pad_io23_pad),
   .pad_pad_io24_pad(pad_domain_pad_io24_pad),
   .pad_pad_io25_pad(pad_domain_pad_io25_pad),
   .pad_pad_io26_pad(pad_domain_pad_io26_pad),
   .pad_pad_io27_pad(pad_domain_pad_io27_pad),
   .pad_pad_io28_pad(pad_domain_pad_io28_pad),
   .pad_pad_io29_pad(pad_domain_pad_io29_pad),
   .pad_pad_io30_pad(pad_domain_pad_io30_pad),
   .pad_pad_io31_pad(pad_domain_pad_io31_pad),
   .config_req_i(domain_config_req),
   .config_rsp_o(domain_config_resp)
  );


   localparam int unsigned NUM_PAD_DOMAINS = 1;
   localparam int unsigned REG_ADDR_WIDTH = 9;
   typedef struct packed {
      int unsigned idx;
      logic [REG_ADDR_WIDTH-1:0] start_addr;
      logic [REG_ADDR_WIDTH-1:0] end_addr;
   } addr_rule_t;

   localparam addr_rule_t[NUM_PAD_DOMAINS-1:0] ADDR_DEMUX_RULES = '{
     '{ idx: 0, start_addr: 9'd0,  end_addr: 9'd260}
     };
   logic[$clog2(NUM_PAD_DOMAINS+1)-1:0] pad_domain_sel; // +1 since there is an additional error slave
   // Fusion Compiler (Presto) cannot member-select the parameter-type config_req_i in a
   // port connection, so hoist the address slice into a procedural signal first.
   logic [REG_ADDR_WIDTH-1:0] config_req_addr;
   always_comb config_req_addr = config_req_i.addr[REG_ADDR_WIDTH-1:0];
   addr_decode #(
       .NoIndices(NUM_PAD_DOMAINS+1),
       .NoRules(NUM_PAD_DOMAINS),
       .addr_t(logic[REG_ADDR_WIDTH-1:0]),
       .rule_t(addr_rule_t)
     ) i_addr_decode(
       .addr_i(config_req_addr),
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
       .out_req_o({error_slave_req, domain_config_req}),
       .out_rsp_i({error_slave_rsp, domain_config_resp})
     );

     // Procedural for the same Presto reason as config_req_addr above.
     always_comb begin
       error_slave_rsp.error = 1'b1;
       error_slave_rsp.rdata = DecodeErrRespData;
       error_slave_rsp.ready = 1'b1;
     end

endmodule
