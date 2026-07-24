
module quasi_static_padframe_aon_muxer
  import pkg_internal_quasi_static_padframe_aon::*;
  import pkg_quasi_static_padframe::*;
  import quasi_static_padframe_aon_config_reg_pkg::*;
#(
  parameter type              req_t  = logic, // reg_interface request type
  parameter type             resp_t  = logic // reg_interface response type
) (
  input logic clk_i,
  input logic rst_ni,
  input pad_domain_aon_ports_soc2pad_t port_signals_soc2pad_i,
  output pad_domain_aon_ports_pad2soc_t port_signals_pad2soc_o,
  output mux_to_pads_t mux_to_pads_o,
  input pads_to_mux_t pads_to_mux_i,
  // Configuration interface using register_interface protocol
  input req_t config_req_i,
  output resp_t config_rsp_o
);
   // Connections between register file and pads
     quasi_static_padframe_aon_config_reg2hw_t s_reg2hw;

  // Register File Instantiation
  quasi_static_padframe_aon_config_reg_top #(
    .reg_req_t(req_t),
    .reg_rsp_t(resp_t)
    ) i_regfile (
    .clk_i,
    .rst_ni,
    .reg2hw(s_reg2hw),
    .reg_req_i(config_req_i),
    .reg_rsp_o(config_rsp_o),
    .devmode_i(1'b1)
  );


   // SoC -> Pad Multiplex Logic
   // Pad pad_hw (hardwired to port uart.tx)
   assign mux_to_pads_o.pad_hw.chip2pad = port_signals_soc2pad_i.uart.tx_o;
   assign mux_to_pads_o.pad_hw.driving_strength = 2'd2;
   assign mux_to_pads_o.pad_hw.output_en = 1'b1;
   assign mux_to_pads_o.pad_hw.pull_up_en = 1'b0;

   // Pad pad_qs
   always_comb begin
     unique case (s_reg2hw.pad_qs_mux_sel.q)
       PAD_MUX_GROUP_PAD_QS_SEL_DEFAULT: begin
         mux_to_pads_o.pad_qs.chip2pad = s_reg2hw.pad_qs_cfg.chip2pad.q;
         mux_to_pads_o.pad_qs.driving_strength = s_reg2hw.pad_qs_cfg.driving_strength.q;
         mux_to_pads_o.pad_qs.output_en = s_reg2hw.pad_qs_cfg.output_en.q;
         mux_to_pads_o.pad_qs.pull_up_en = s_reg2hw.pad_qs_cfg.pull_up_en.q;
       end
       PAD_MUX_GROUP_PAD_QS_SEL_UART_RX: begin
          mux_to_pads_o.pad_qs.chip2pad = s_reg2hw.pad_qs_cfg.chip2pad.q;
          mux_to_pads_o.pad_qs.driving_strength = s_reg2hw.pad_qs_cfg.driving_strength.q;
          mux_to_pads_o.pad_qs.output_en = 1'b0;
          mux_to_pads_o.pad_qs.pull_up_en = s_reg2hw.pad_qs_cfg.pull_up_en.q;
       end
       default: begin
         mux_to_pads_o.pad_qs.chip2pad = s_reg2hw.pad_qs_cfg.chip2pad.q;
         mux_to_pads_o.pad_qs.driving_strength = s_reg2hw.pad_qs_cfg.driving_strength.q;
         mux_to_pads_o.pad_qs.output_en = s_reg2hw.pad_qs_cfg.output_en.q;
         mux_to_pads_o.pad_qs.pull_up_en = s_reg2hw.pad_qs_cfg.pull_up_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_io0
   always_comb begin
     unique case (s_reg2hw.pad_io0_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SEL_DEFAULT: begin
         mux_to_pads_o.pad_io0.chip2pad = s_reg2hw.pad_io0_cfg.chip2pad.q;
         mux_to_pads_o.pad_io0.driving_strength = s_reg2hw.pad_io0_cfg.driving_strength.q;
         mux_to_pads_o.pad_io0.output_en = s_reg2hw.pad_io0_cfg.output_en.q;
         mux_to_pads_o.pad_io0.pull_up_en = s_reg2hw.pad_io0_cfg.pull_up_en.q;
       end
       PAD_MUX_GROUP_GPIO_SEL_GPIO_IO0: begin
          mux_to_pads_o.pad_io0.chip2pad = port_signals_soc2pad_i.gpio.out0;
          mux_to_pads_o.pad_io0.driving_strength = s_reg2hw.pad_io0_cfg.driving_strength.q;
          mux_to_pads_o.pad_io0.output_en = port_signals_soc2pad_i.gpio.dir0;
          mux_to_pads_o.pad_io0.pull_up_en = s_reg2hw.pad_io0_cfg.pull_up_en.q;
       end
       PAD_MUX_GROUP_GPIO_SEL_GPIO_IO1: begin
          mux_to_pads_o.pad_io0.chip2pad = port_signals_soc2pad_i.gpio.out1;
          mux_to_pads_o.pad_io0.driving_strength = s_reg2hw.pad_io0_cfg.driving_strength.q;
          mux_to_pads_o.pad_io0.output_en = port_signals_soc2pad_i.gpio.dir1;
          mux_to_pads_o.pad_io0.pull_up_en = s_reg2hw.pad_io0_cfg.pull_up_en.q;
       end
       default: begin
         mux_to_pads_o.pad_io0.chip2pad = s_reg2hw.pad_io0_cfg.chip2pad.q;
         mux_to_pads_o.pad_io0.driving_strength = s_reg2hw.pad_io0_cfg.driving_strength.q;
         mux_to_pads_o.pad_io0.output_en = s_reg2hw.pad_io0_cfg.output_en.q;
         mux_to_pads_o.pad_io0.pull_up_en = s_reg2hw.pad_io0_cfg.pull_up_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_io1
   always_comb begin
     unique case (s_reg2hw.pad_io1_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SEL_DEFAULT: begin
         mux_to_pads_o.pad_io1.chip2pad = s_reg2hw.pad_io1_cfg.chip2pad.q;
         mux_to_pads_o.pad_io1.driving_strength = s_reg2hw.pad_io1_cfg.driving_strength.q;
         mux_to_pads_o.pad_io1.output_en = s_reg2hw.pad_io1_cfg.output_en.q;
         mux_to_pads_o.pad_io1.pull_up_en = s_reg2hw.pad_io1_cfg.pull_up_en.q;
       end
       PAD_MUX_GROUP_GPIO_SEL_GPIO_IO0: begin
          mux_to_pads_o.pad_io1.chip2pad = port_signals_soc2pad_i.gpio.out0;
          mux_to_pads_o.pad_io1.driving_strength = s_reg2hw.pad_io1_cfg.driving_strength.q;
          mux_to_pads_o.pad_io1.output_en = port_signals_soc2pad_i.gpio.dir0;
          mux_to_pads_o.pad_io1.pull_up_en = s_reg2hw.pad_io1_cfg.pull_up_en.q;
       end
       PAD_MUX_GROUP_GPIO_SEL_GPIO_IO1: begin
          mux_to_pads_o.pad_io1.chip2pad = port_signals_soc2pad_i.gpio.out1;
          mux_to_pads_o.pad_io1.driving_strength = s_reg2hw.pad_io1_cfg.driving_strength.q;
          mux_to_pads_o.pad_io1.output_en = port_signals_soc2pad_i.gpio.dir1;
          mux_to_pads_o.pad_io1.pull_up_en = s_reg2hw.pad_io1_cfg.pull_up_en.q;
       end
       default: begin
         mux_to_pads_o.pad_io1.chip2pad = s_reg2hw.pad_io1_cfg.chip2pad.q;
         mux_to_pads_o.pad_io1.driving_strength = s_reg2hw.pad_io1_cfg.driving_strength.q;
         mux_to_pads_o.pad_io1.output_en = s_reg2hw.pad_io1_cfg.output_en.q;
         mux_to_pads_o.pad_io1.pull_up_en = s_reg2hw.pad_io1_cfg.pull_up_en.q;
       end
     endcase
   end // always_comb


  // Pad -> SoC Multiplex Logic
  // Port Group uart

  // Port Signal tx_lb_i (hardwired to pad pad_hw)
  assign port_signals_pad2soc_o.uart.tx_lb_i = pads_to_mux_i.pad_hw.pad2chip;


  // Port Signal rx_i
  logic [0:0] port_mux_sel_uart_rx_i_req;
  logic [PORT_MUX_GROUP_PAD_QS_SEL_WIDTH-1:0] port_mux_sel_uart_rx_i_arbitrated;
  logic port_mux_sel_uart_rx_i_no_connection;

   assign port_mux_sel_uart_rx_i_req[PORT_MUX_GROUP_PAD_QS_SEL_PAD_QS] = s_reg2hw.pad_qs_mux_sel.q == PAD_MUX_GROUP_PAD_QS_SEL_UART_RX ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_uart_rx_i_arbiter (
     .in_i(port_mux_sel_uart_rx_i_req),
     .cnt_o(port_mux_sel_uart_rx_i_arbitrated),
     .empty_o(port_mux_sel_uart_rx_i_no_connection)
   );

   always_comb begin
     if (port_mux_sel_uart_rx_i_no_connection) begin
        port_signals_pad2soc_o.uart.rx_i = 1'b1;
     end else begin
        unique case (port_mux_sel_uart_rx_i_arbitrated)
          PORT_MUX_GROUP_PAD_QS_SEL_PAD_QS: begin
            port_signals_pad2soc_o.uart.rx_i = pads_to_mux_i.pad_qs.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.uart.rx_i = 1'b1;
          end
       endcase
     end
   end

  // Port Group gpio

  // Port Signal in0
  logic [1:0] port_mux_sel_gpio_in0_req;
  logic [PORT_MUX_GROUP_GPIO_SEL_WIDTH-1:0] port_mux_sel_gpio_in0_arbitrated;
  logic port_mux_sel_gpio_in0_no_connection;

   assign port_mux_sel_gpio_in0_req[PORT_MUX_GROUP_GPIO_SEL_PAD_IO0] = s_reg2hw.pad_io0_mux_sel.q == PAD_MUX_GROUP_GPIO_SEL_GPIO_IO0 ? 1'b1 : 1'b0;
   assign port_mux_sel_gpio_in0_req[PORT_MUX_GROUP_GPIO_SEL_PAD_IO1] = s_reg2hw.pad_io1_mux_sel.q == PAD_MUX_GROUP_GPIO_SEL_GPIO_IO0 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(2),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_in0_arbiter (
     .in_i(port_mux_sel_gpio_in0_req),
     .cnt_o(port_mux_sel_gpio_in0_arbitrated),
     .empty_o(port_mux_sel_gpio_in0_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_in0_no_connection) begin
        port_signals_pad2soc_o.gpio.in0 = 1'b0;
     end else begin
        unique case (port_mux_sel_gpio_in0_arbitrated)
          PORT_MUX_GROUP_GPIO_SEL_PAD_IO0: begin
            port_signals_pad2soc_o.gpio.in0 = pads_to_mux_i.pad_io0.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SEL_PAD_IO1: begin
            port_signals_pad2soc_o.gpio.in0 = pads_to_mux_i.pad_io1.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio.in0 = 1'b0;
          end
       endcase
     end
   end


  // Port Signal in1
  logic [1:0] port_mux_sel_gpio_in1_req;
  logic [PORT_MUX_GROUP_GPIO_SEL_WIDTH-1:0] port_mux_sel_gpio_in1_arbitrated;
  logic port_mux_sel_gpio_in1_no_connection;

   assign port_mux_sel_gpio_in1_req[PORT_MUX_GROUP_GPIO_SEL_PAD_IO0] = s_reg2hw.pad_io0_mux_sel.q == PAD_MUX_GROUP_GPIO_SEL_GPIO_IO1 ? 1'b1 : 1'b0;
   assign port_mux_sel_gpio_in1_req[PORT_MUX_GROUP_GPIO_SEL_PAD_IO1] = s_reg2hw.pad_io1_mux_sel.q == PAD_MUX_GROUP_GPIO_SEL_GPIO_IO1 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(2),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_in1_arbiter (
     .in_i(port_mux_sel_gpio_in1_req),
     .cnt_o(port_mux_sel_gpio_in1_arbitrated),
     .empty_o(port_mux_sel_gpio_in1_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_in1_no_connection) begin
        port_signals_pad2soc_o.gpio.in1 = 1'b0;
     end else begin
        unique case (port_mux_sel_gpio_in1_arbitrated)
          PORT_MUX_GROUP_GPIO_SEL_PAD_IO0: begin
            port_signals_pad2soc_o.gpio.in1 = pads_to_mux_i.pad_io0.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SEL_PAD_IO1: begin
            port_signals_pad2soc_o.gpio.in1 = pads_to_mux_i.pad_io1.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio.in1 = 1'b0;
          end
       endcase
     end
   end

endmodule : quasi_static_padframe_aon_muxer
