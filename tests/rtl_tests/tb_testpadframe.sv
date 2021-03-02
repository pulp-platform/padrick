`include "register_interface/typedef.svh"
`include "register_interface/assign.svh"

module tb_testpadframe;
   import pkg_testpadframe::*;
   import testpadframe_domain0_config_reg_pkg::*;

   // timing parameters
   localparam time CyclTime = 10ns;
   localparam time ApplTime =  2ns;
   localparam time TestTime =  8ns;

   typedef logic [31:0] addr_t;
   typedef logic [31:0] data_t;
   typedef logic [3:0]  strb_t;
   `REG_BUS_TYPEDEF_ALL(config_reg, addr_t, data_t, strb_t);

   // Connection Signals
   logic clk, rst_n;
   REG_BUS #(
     .ADDR_WIDTH(32), 
     .DATA_WIDTH(32)) config_bus(.clk_i(clk));
   config_reg_req_t config_req;
   config_reg_rsp_t config_resp;
   override_signals_t                   override_signals;
   static_connection_signals_pad2soc_t static_connection_signals_pad2soc;
   port_signals_pad2soc_t              port_signals_pad2soc;
   port_signals_soc2pad_t               port_signals_soc2pad;
   wire landing_pads_t                       pads;
   landing_pads_t tb2pads;

   assign pads = tb2pads;

   `REG_BUS_ASSIGN_TO_REQ(config_req, config_bus);
   `REG_BUS_ASSIGN_FROM_RSP(config_bus, config_resp);

   //-----------------------------------
   // Clock generator
   //-----------------------------------
   clk_rst_gen #(
     .ClkPeriod   ( CyclTime ),
     .RstClkCycles( 5        )
   ) i_clk_gen (
     .clk_o (clk),
     .rst_no(rst_n)
   );

   testpadframe # (
     .AW(32),
     .DW(32),
     .req_t(config_reg_req_t),
     .resp_t(config_reg_rsp_t)
   ) i_dut (
     .clk_i(clk),
     .rst_ni(rst_n),
     .override_signals,
     .static_connection_signals_pad2soc,
     .port_signals_pad2soc,
     .port_signals_soc2pad,
     .pads,
     .config_req_i(config_req),
     .config_rsp_o(config_resp)
   );

   reg_test::reg_driver #(
     .AW(32),
     .DW(32),
     .TA(ApplTime),
     .TT(TestTime)) config_driver;

   initial begin : initial_test
     automatic logic error;
     automatic testpadframe_domain0_config_reg2hw_pad_gpio2_cfg_reg_t gpio2_config;
     config_driver        = new(config_bus);
     port_signals_soc2pad = '0;
     override_signals = '0;
     tb2pads              = 'Z;
     @(posedge rst_n); // Wait for reset deassertion
     config_driver.send_write(TESTPADFRAME_DOMAIN0_CONFIG_PAD_GPIO0_MUX_SEL_OFFSET, 2, '1, error); // Connect i2c1.sda to gpio0
     config_driver.send_write(TESTPADFRAME_DOMAIN0_CONFIG_PAD_GPIO1_MUX_SEL_OFFSET, 2, '1, error); // Connect i2c1.sc to gpio1
     gpio2_config = '{ output_en: 1'b1, rx_en: 1'b1, chip2pad: 1'b1};
     config_driver.send_write(TESTPADFRAME_DOMAIN0_CONFIG_PAD_GPIO2_CFG_OFFSET, gpio2_config, '1, error);
     
     @(posedge clk);
   end


endmodule : tb_testpadframe
