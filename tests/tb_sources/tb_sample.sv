module tb_low_power_padframe;
   import pkg_low_power_padframe::*;
   typedef struct packed {
      logic [31:0] addr;
      logic      write;
      logic [31:0] wdata;
      logic [3:0]  wstrb;
      logic       valid;
   } req_t;

   typedef struct packed {
      logic [31:0] rdata;
      logic        error;
      logic        ready;
   } resp_t;

   // TB connection signals
   logic           clk;
   logic           rst;
   override_signals_t                   override_signals;
   static_connection_signals_pad2soc_t static_connection_signals_pad2soc;
   port_signals_pad2soc_t              port_signals_pad2soc;
   port_signals_soc2pad_t               port_signals_soc2pad;
   wire landing_pads_t                       pads;
   req_t                                config_req_i;
   resp_t                              config_rsp_o;

   logic           end_of_sim = 1'b0;
   localparam CLK_HIGH = 0.5ns;
   localparam CLK_LOW = 0.5ns;
   initial begin : clk_gen
     while (~end_of_sim) begin
       clk = 1'b1;
       #CLK_HIGH;
       clk = 1'b0;
       #CLK_LOW;
     end
   end

   initial begin: tb
     override_signals = '0;
     rst              = 1'b0;
     config_req_i     = '0;
     port_signals_soc2pad = '0;
     #5ns;
     rst = 1'b1;
     #5ns;
   end


   low_power_padframe #(
     .req_t(req_t),
     .resp_t(resp_t)
   ) i_low_power_padframe (
     .clk_i(clk),
     .rst_ni(rst),
     .override_signals,
     .static_connection_signals_pad2soc,
     .port_signals_pad2soc,
     .port_signals_soc2pad,
     .pads,
     .config_req_i,
     .config_rsp_o
   );

endmodule : tb_low_power_padframe
