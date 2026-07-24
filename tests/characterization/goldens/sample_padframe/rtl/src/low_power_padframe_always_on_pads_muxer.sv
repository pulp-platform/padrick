
module low_power_padframe_always_on_pads_muxer
  import pkg_internal_low_power_padframe_always_on_pads::*;
  import pkg_low_power_padframe::*;
  import low_power_padframe_always_on_pads_config_reg_pkg::*;
#(
  parameter type              req_t  = logic, // reg_interface request type
  parameter type             resp_t  = logic // reg_interface response type
) (
  input logic clk_i,
  input logic rst_ni,
  input pad_domain_always_on_pads_ports_soc2pad_t port_signals_soc2pad_i,
  output pad_domain_always_on_pads_ports_pad2soc_t port_signals_pad2soc_o,
  output mux_to_pads_t mux_to_pads_o,
  input pads_to_mux_t pads_to_mux_i,
  // Configuration interface using register_interface protocol
  input req_t config_req_i,
  output resp_t config_rsp_o
);
   // Connections between register file and pads
     low_power_padframe_always_on_pads_config_reg2hw_t s_reg2hw;

  // Register File Instantiation
  low_power_padframe_always_on_pads_config_reg_top #(
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
   // Pad pad_gpioa0
   always_comb begin
     unique case (s_reg2hw.pad_gpioa0_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA0_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa0.chip2pad = s_reg2hw.pad_gpioa0_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa0.output_en = s_reg2hw.pad_gpioa0_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa0.pull_up_en = s_reg2hw.pad_gpioa0_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa0.rx_en = s_reg2hw.pad_gpioa0_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA0_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa0.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa0.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa0.pull_up_en = s_reg2hw.pad_gpioa0_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa0.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA0_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa0.chip2pad = s_reg2hw.pad_gpioa0_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa0.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa0.pull_up_en = s_reg2hw.pad_gpioa0_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa0.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA0_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa0.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa0.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa0.pull_up_en = s_reg2hw.pad_gpioa0_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa0.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA0_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa0.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa0.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa0.pull_up_en = s_reg2hw.pad_gpioa0_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa0.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA0_SEL_GPIO_A_GPIO00: begin
          mux_to_pads_o.pad_gpioa0.chip2pad = port_signals_soc2pad_i.gpio_a.gpio0_i;
          mux_to_pads_o.pad_gpioa0.output_en = s_reg2hw.pad_gpioa0_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa0.pull_up_en = s_reg2hw.pad_gpioa0_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa0.rx_en = port_signals_soc2pad_i.gpio_a.dir0_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa0.chip2pad = s_reg2hw.pad_gpioa0_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa0.output_en = s_reg2hw.pad_gpioa0_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa0.pull_up_en = s_reg2hw.pad_gpioa0_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa0.rx_en = s_reg2hw.pad_gpioa0_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa1
   always_comb begin
     unique case (s_reg2hw.pad_gpioa1_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA1_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa1.chip2pad = s_reg2hw.pad_gpioa1_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa1.output_en = s_reg2hw.pad_gpioa1_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa1.pull_up_en = s_reg2hw.pad_gpioa1_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa1.rx_en = s_reg2hw.pad_gpioa1_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA1_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa1.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa1.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa1.pull_up_en = s_reg2hw.pad_gpioa1_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa1.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA1_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa1.chip2pad = s_reg2hw.pad_gpioa1_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa1.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa1.pull_up_en = s_reg2hw.pad_gpioa1_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa1.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA1_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa1.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa1.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa1.pull_up_en = s_reg2hw.pad_gpioa1_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa1.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA1_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa1.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa1.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa1.pull_up_en = s_reg2hw.pad_gpioa1_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa1.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA1_SEL_GPIO_A_GPIO01: begin
          mux_to_pads_o.pad_gpioa1.chip2pad = port_signals_soc2pad_i.gpio_a.gpio1_i;
          mux_to_pads_o.pad_gpioa1.output_en = s_reg2hw.pad_gpioa1_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa1.pull_up_en = s_reg2hw.pad_gpioa1_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa1.rx_en = port_signals_soc2pad_i.gpio_a.dir1_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa1.chip2pad = s_reg2hw.pad_gpioa1_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa1.output_en = s_reg2hw.pad_gpioa1_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa1.pull_up_en = s_reg2hw.pad_gpioa1_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa1.rx_en = s_reg2hw.pad_gpioa1_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa2
   always_comb begin
     unique case (s_reg2hw.pad_gpioa2_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA2_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa2.chip2pad = s_reg2hw.pad_gpioa2_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa2.output_en = s_reg2hw.pad_gpioa2_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa2.pull_up_en = s_reg2hw.pad_gpioa2_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa2.rx_en = s_reg2hw.pad_gpioa2_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA2_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa2.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa2.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa2.pull_up_en = s_reg2hw.pad_gpioa2_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa2.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA2_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa2.chip2pad = s_reg2hw.pad_gpioa2_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa2.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa2.pull_up_en = s_reg2hw.pad_gpioa2_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa2.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA2_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa2.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa2.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa2.pull_up_en = s_reg2hw.pad_gpioa2_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa2.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA2_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa2.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa2.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa2.pull_up_en = s_reg2hw.pad_gpioa2_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa2.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA2_SEL_GPIO_A_GPIO02: begin
          mux_to_pads_o.pad_gpioa2.chip2pad = port_signals_soc2pad_i.gpio_a.gpio2_i;
          mux_to_pads_o.pad_gpioa2.output_en = s_reg2hw.pad_gpioa2_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa2.pull_up_en = s_reg2hw.pad_gpioa2_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa2.rx_en = port_signals_soc2pad_i.gpio_a.dir2_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa2.chip2pad = s_reg2hw.pad_gpioa2_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa2.output_en = s_reg2hw.pad_gpioa2_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa2.pull_up_en = s_reg2hw.pad_gpioa2_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa2.rx_en = s_reg2hw.pad_gpioa2_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa3
   always_comb begin
     unique case (s_reg2hw.pad_gpioa3_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA3_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa3.chip2pad = s_reg2hw.pad_gpioa3_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa3.output_en = s_reg2hw.pad_gpioa3_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa3.pull_up_en = s_reg2hw.pad_gpioa3_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa3.rx_en = s_reg2hw.pad_gpioa3_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA3_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa3.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa3.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa3.pull_up_en = s_reg2hw.pad_gpioa3_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa3.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA3_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa3.chip2pad = s_reg2hw.pad_gpioa3_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa3.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa3.pull_up_en = s_reg2hw.pad_gpioa3_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa3.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA3_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa3.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa3.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa3.pull_up_en = s_reg2hw.pad_gpioa3_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa3.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA3_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa3.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa3.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa3.pull_up_en = s_reg2hw.pad_gpioa3_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa3.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA3_SEL_GPIO_A_GPIO03: begin
          mux_to_pads_o.pad_gpioa3.chip2pad = port_signals_soc2pad_i.gpio_a.gpio3_i;
          mux_to_pads_o.pad_gpioa3.output_en = s_reg2hw.pad_gpioa3_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa3.pull_up_en = s_reg2hw.pad_gpioa3_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa3.rx_en = port_signals_soc2pad_i.gpio_a.dir3_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa3.chip2pad = s_reg2hw.pad_gpioa3_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa3.output_en = s_reg2hw.pad_gpioa3_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa3.pull_up_en = s_reg2hw.pad_gpioa3_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa3.rx_en = s_reg2hw.pad_gpioa3_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa4
   always_comb begin
     unique case (s_reg2hw.pad_gpioa4_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA4_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa4.chip2pad = s_reg2hw.pad_gpioa4_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa4.output_en = s_reg2hw.pad_gpioa4_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa4.pull_up_en = s_reg2hw.pad_gpioa4_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa4.rx_en = s_reg2hw.pad_gpioa4_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA4_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa4.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa4.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa4.pull_up_en = s_reg2hw.pad_gpioa4_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa4.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA4_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa4.chip2pad = s_reg2hw.pad_gpioa4_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa4.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa4.pull_up_en = s_reg2hw.pad_gpioa4_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa4.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA4_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa4.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa4.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa4.pull_up_en = s_reg2hw.pad_gpioa4_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa4.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA4_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa4.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa4.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa4.pull_up_en = s_reg2hw.pad_gpioa4_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa4.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA4_SEL_GPIO_A_GPIO04: begin
          mux_to_pads_o.pad_gpioa4.chip2pad = port_signals_soc2pad_i.gpio_a.gpio4_i;
          mux_to_pads_o.pad_gpioa4.output_en = s_reg2hw.pad_gpioa4_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa4.pull_up_en = s_reg2hw.pad_gpioa4_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa4.rx_en = port_signals_soc2pad_i.gpio_a.dir4_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa4.chip2pad = s_reg2hw.pad_gpioa4_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa4.output_en = s_reg2hw.pad_gpioa4_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa4.pull_up_en = s_reg2hw.pad_gpioa4_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa4.rx_en = s_reg2hw.pad_gpioa4_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa5
   always_comb begin
     unique case (s_reg2hw.pad_gpioa5_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA5_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa5.chip2pad = s_reg2hw.pad_gpioa5_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa5.output_en = s_reg2hw.pad_gpioa5_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa5.pull_up_en = s_reg2hw.pad_gpioa5_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa5.rx_en = s_reg2hw.pad_gpioa5_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA5_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa5.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa5.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa5.pull_up_en = s_reg2hw.pad_gpioa5_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa5.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA5_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa5.chip2pad = s_reg2hw.pad_gpioa5_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa5.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa5.pull_up_en = s_reg2hw.pad_gpioa5_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa5.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA5_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa5.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa5.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa5.pull_up_en = s_reg2hw.pad_gpioa5_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa5.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA5_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa5.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa5.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa5.pull_up_en = s_reg2hw.pad_gpioa5_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa5.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA5_SEL_GPIO_A_GPIO05: begin
          mux_to_pads_o.pad_gpioa5.chip2pad = port_signals_soc2pad_i.gpio_a.gpio5_i;
          mux_to_pads_o.pad_gpioa5.output_en = s_reg2hw.pad_gpioa5_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa5.pull_up_en = s_reg2hw.pad_gpioa5_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa5.rx_en = port_signals_soc2pad_i.gpio_a.dir5_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa5.chip2pad = s_reg2hw.pad_gpioa5_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa5.output_en = s_reg2hw.pad_gpioa5_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa5.pull_up_en = s_reg2hw.pad_gpioa5_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa5.rx_en = s_reg2hw.pad_gpioa5_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa6
   always_comb begin
     unique case (s_reg2hw.pad_gpioa6_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA6_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa6.chip2pad = s_reg2hw.pad_gpioa6_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa6.output_en = s_reg2hw.pad_gpioa6_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa6.pull_up_en = s_reg2hw.pad_gpioa6_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa6.rx_en = s_reg2hw.pad_gpioa6_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA6_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa6.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa6.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa6.pull_up_en = s_reg2hw.pad_gpioa6_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa6.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA6_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa6.chip2pad = s_reg2hw.pad_gpioa6_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa6.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa6.pull_up_en = s_reg2hw.pad_gpioa6_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa6.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA6_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa6.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa6.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa6.pull_up_en = s_reg2hw.pad_gpioa6_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa6.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA6_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa6.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa6.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa6.pull_up_en = s_reg2hw.pad_gpioa6_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa6.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA6_SEL_GPIO_A_GPIO06: begin
          mux_to_pads_o.pad_gpioa6.chip2pad = port_signals_soc2pad_i.gpio_a.gpio6_i;
          mux_to_pads_o.pad_gpioa6.output_en = s_reg2hw.pad_gpioa6_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa6.pull_up_en = s_reg2hw.pad_gpioa6_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa6.rx_en = port_signals_soc2pad_i.gpio_a.dir6_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa6.chip2pad = s_reg2hw.pad_gpioa6_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa6.output_en = s_reg2hw.pad_gpioa6_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa6.pull_up_en = s_reg2hw.pad_gpioa6_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa6.rx_en = s_reg2hw.pad_gpioa6_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa7
   always_comb begin
     unique case (s_reg2hw.pad_gpioa7_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA7_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa7.chip2pad = s_reg2hw.pad_gpioa7_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa7.output_en = s_reg2hw.pad_gpioa7_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa7.pull_up_en = s_reg2hw.pad_gpioa7_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa7.rx_en = s_reg2hw.pad_gpioa7_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA7_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa7.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa7.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa7.pull_up_en = s_reg2hw.pad_gpioa7_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa7.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA7_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa7.chip2pad = s_reg2hw.pad_gpioa7_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa7.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa7.pull_up_en = s_reg2hw.pad_gpioa7_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa7.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA7_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa7.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa7.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa7.pull_up_en = s_reg2hw.pad_gpioa7_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa7.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA7_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa7.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa7.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa7.pull_up_en = s_reg2hw.pad_gpioa7_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa7.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA7_SEL_GPIO_A_GPIO07: begin
          mux_to_pads_o.pad_gpioa7.chip2pad = port_signals_soc2pad_i.gpio_a.gpio7_i;
          mux_to_pads_o.pad_gpioa7.output_en = s_reg2hw.pad_gpioa7_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa7.pull_up_en = s_reg2hw.pad_gpioa7_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa7.rx_en = port_signals_soc2pad_i.gpio_a.dir7_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa7.chip2pad = s_reg2hw.pad_gpioa7_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa7.output_en = s_reg2hw.pad_gpioa7_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa7.pull_up_en = s_reg2hw.pad_gpioa7_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa7.rx_en = s_reg2hw.pad_gpioa7_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa8
   always_comb begin
     unique case (s_reg2hw.pad_gpioa8_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA8_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa8.chip2pad = s_reg2hw.pad_gpioa8_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa8.output_en = s_reg2hw.pad_gpioa8_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa8.pull_up_en = s_reg2hw.pad_gpioa8_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa8.rx_en = s_reg2hw.pad_gpioa8_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA8_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa8.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa8.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa8.pull_up_en = s_reg2hw.pad_gpioa8_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa8.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA8_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa8.chip2pad = s_reg2hw.pad_gpioa8_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa8.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa8.pull_up_en = s_reg2hw.pad_gpioa8_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa8.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA8_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa8.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa8.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa8.pull_up_en = s_reg2hw.pad_gpioa8_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa8.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA8_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa8.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa8.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa8.pull_up_en = s_reg2hw.pad_gpioa8_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa8.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA8_SEL_GPIO_A_GPIO08: begin
          mux_to_pads_o.pad_gpioa8.chip2pad = port_signals_soc2pad_i.gpio_a.gpio8_i;
          mux_to_pads_o.pad_gpioa8.output_en = s_reg2hw.pad_gpioa8_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa8.pull_up_en = s_reg2hw.pad_gpioa8_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa8.rx_en = port_signals_soc2pad_i.gpio_a.dir8_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa8.chip2pad = s_reg2hw.pad_gpioa8_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa8.output_en = s_reg2hw.pad_gpioa8_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa8.pull_up_en = s_reg2hw.pad_gpioa8_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa8.rx_en = s_reg2hw.pad_gpioa8_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa9
   always_comb begin
     unique case (s_reg2hw.pad_gpioa9_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA9_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa9.chip2pad = s_reg2hw.pad_gpioa9_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa9.output_en = s_reg2hw.pad_gpioa9_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa9.pull_up_en = s_reg2hw.pad_gpioa9_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa9.rx_en = s_reg2hw.pad_gpioa9_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA9_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa9.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa9.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa9.pull_up_en = s_reg2hw.pad_gpioa9_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa9.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA9_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa9.chip2pad = s_reg2hw.pad_gpioa9_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa9.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa9.pull_up_en = s_reg2hw.pad_gpioa9_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa9.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA9_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa9.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa9.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa9.pull_up_en = s_reg2hw.pad_gpioa9_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa9.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA9_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa9.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa9.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa9.pull_up_en = s_reg2hw.pad_gpioa9_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa9.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA9_SEL_GPIO_A_GPIO09: begin
          mux_to_pads_o.pad_gpioa9.chip2pad = port_signals_soc2pad_i.gpio_a.gpio9_i;
          mux_to_pads_o.pad_gpioa9.output_en = s_reg2hw.pad_gpioa9_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa9.pull_up_en = s_reg2hw.pad_gpioa9_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa9.rx_en = port_signals_soc2pad_i.gpio_a.dir9_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa9.chip2pad = s_reg2hw.pad_gpioa9_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa9.output_en = s_reg2hw.pad_gpioa9_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa9.pull_up_en = s_reg2hw.pad_gpioa9_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa9.rx_en = s_reg2hw.pad_gpioa9_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa10
   always_comb begin
     unique case (s_reg2hw.pad_gpioa10_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA10_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa10.chip2pad = s_reg2hw.pad_gpioa10_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa10.output_en = s_reg2hw.pad_gpioa10_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa10.pull_up_en = s_reg2hw.pad_gpioa10_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa10.rx_en = s_reg2hw.pad_gpioa10_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA10_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa10.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa10.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa10.pull_up_en = s_reg2hw.pad_gpioa10_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa10.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA10_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa10.chip2pad = s_reg2hw.pad_gpioa10_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa10.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa10.pull_up_en = s_reg2hw.pad_gpioa10_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa10.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA10_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa10.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa10.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa10.pull_up_en = s_reg2hw.pad_gpioa10_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa10.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA10_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa10.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa10.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa10.pull_up_en = s_reg2hw.pad_gpioa10_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa10.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA10_SEL_GPIO_A_GPIO10: begin
          mux_to_pads_o.pad_gpioa10.chip2pad = port_signals_soc2pad_i.gpio_a.gpio10_i;
          mux_to_pads_o.pad_gpioa10.output_en = s_reg2hw.pad_gpioa10_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa10.pull_up_en = s_reg2hw.pad_gpioa10_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa10.rx_en = port_signals_soc2pad_i.gpio_a.dir10_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa10.chip2pad = s_reg2hw.pad_gpioa10_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa10.output_en = s_reg2hw.pad_gpioa10_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa10.pull_up_en = s_reg2hw.pad_gpioa10_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa10.rx_en = s_reg2hw.pad_gpioa10_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa11
   always_comb begin
     unique case (s_reg2hw.pad_gpioa11_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA11_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa11.chip2pad = s_reg2hw.pad_gpioa11_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa11.output_en = s_reg2hw.pad_gpioa11_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa11.pull_up_en = s_reg2hw.pad_gpioa11_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa11.rx_en = s_reg2hw.pad_gpioa11_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA11_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa11.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa11.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa11.pull_up_en = s_reg2hw.pad_gpioa11_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa11.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA11_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa11.chip2pad = s_reg2hw.pad_gpioa11_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa11.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa11.pull_up_en = s_reg2hw.pad_gpioa11_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa11.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA11_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa11.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa11.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa11.pull_up_en = s_reg2hw.pad_gpioa11_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa11.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA11_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa11.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa11.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa11.pull_up_en = s_reg2hw.pad_gpioa11_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa11.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA11_SEL_GPIO_A_GPIO11: begin
          mux_to_pads_o.pad_gpioa11.chip2pad = port_signals_soc2pad_i.gpio_a.gpio11_i;
          mux_to_pads_o.pad_gpioa11.output_en = s_reg2hw.pad_gpioa11_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa11.pull_up_en = s_reg2hw.pad_gpioa11_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa11.rx_en = port_signals_soc2pad_i.gpio_a.dir11_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa11.chip2pad = s_reg2hw.pad_gpioa11_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa11.output_en = s_reg2hw.pad_gpioa11_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa11.pull_up_en = s_reg2hw.pad_gpioa11_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa11.rx_en = s_reg2hw.pad_gpioa11_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa12
   always_comb begin
     unique case (s_reg2hw.pad_gpioa12_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA12_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa12.chip2pad = s_reg2hw.pad_gpioa12_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa12.output_en = s_reg2hw.pad_gpioa12_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa12.pull_up_en = s_reg2hw.pad_gpioa12_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa12.rx_en = s_reg2hw.pad_gpioa12_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA12_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa12.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa12.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa12.pull_up_en = s_reg2hw.pad_gpioa12_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa12.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA12_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa12.chip2pad = s_reg2hw.pad_gpioa12_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa12.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa12.pull_up_en = s_reg2hw.pad_gpioa12_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa12.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA12_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa12.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa12.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa12.pull_up_en = s_reg2hw.pad_gpioa12_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa12.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA12_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa12.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa12.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa12.pull_up_en = s_reg2hw.pad_gpioa12_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa12.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA12_SEL_GPIO_A_GPIO12: begin
          mux_to_pads_o.pad_gpioa12.chip2pad = port_signals_soc2pad_i.gpio_a.gpio12_i;
          mux_to_pads_o.pad_gpioa12.output_en = s_reg2hw.pad_gpioa12_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa12.pull_up_en = s_reg2hw.pad_gpioa12_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa12.rx_en = port_signals_soc2pad_i.gpio_a.dir12_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa12.chip2pad = s_reg2hw.pad_gpioa12_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa12.output_en = s_reg2hw.pad_gpioa12_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa12.pull_up_en = s_reg2hw.pad_gpioa12_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa12.rx_en = s_reg2hw.pad_gpioa12_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa13
   always_comb begin
     unique case (s_reg2hw.pad_gpioa13_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA13_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa13.chip2pad = s_reg2hw.pad_gpioa13_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa13.output_en = s_reg2hw.pad_gpioa13_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa13.pull_up_en = s_reg2hw.pad_gpioa13_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa13.rx_en = s_reg2hw.pad_gpioa13_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA13_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa13.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa13.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa13.pull_up_en = s_reg2hw.pad_gpioa13_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa13.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA13_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa13.chip2pad = s_reg2hw.pad_gpioa13_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa13.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa13.pull_up_en = s_reg2hw.pad_gpioa13_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa13.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA13_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa13.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa13.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa13.pull_up_en = s_reg2hw.pad_gpioa13_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa13.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA13_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa13.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa13.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa13.pull_up_en = s_reg2hw.pad_gpioa13_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa13.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA13_SEL_GPIO_A_GPIO13: begin
          mux_to_pads_o.pad_gpioa13.chip2pad = port_signals_soc2pad_i.gpio_a.gpio13_i;
          mux_to_pads_o.pad_gpioa13.output_en = s_reg2hw.pad_gpioa13_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa13.pull_up_en = s_reg2hw.pad_gpioa13_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa13.rx_en = port_signals_soc2pad_i.gpio_a.dir13_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa13.chip2pad = s_reg2hw.pad_gpioa13_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa13.output_en = s_reg2hw.pad_gpioa13_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa13.pull_up_en = s_reg2hw.pad_gpioa13_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa13.rx_en = s_reg2hw.pad_gpioa13_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa14
   always_comb begin
     unique case (s_reg2hw.pad_gpioa14_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA14_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa14.chip2pad = s_reg2hw.pad_gpioa14_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa14.output_en = s_reg2hw.pad_gpioa14_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa14.pull_up_en = s_reg2hw.pad_gpioa14_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa14.rx_en = s_reg2hw.pad_gpioa14_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA14_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa14.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa14.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa14.pull_up_en = s_reg2hw.pad_gpioa14_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa14.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA14_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa14.chip2pad = s_reg2hw.pad_gpioa14_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa14.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa14.pull_up_en = s_reg2hw.pad_gpioa14_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa14.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA14_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa14.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa14.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa14.pull_up_en = s_reg2hw.pad_gpioa14_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa14.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA14_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa14.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa14.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa14.pull_up_en = s_reg2hw.pad_gpioa14_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa14.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA14_SEL_GPIO_A_GPIO14: begin
          mux_to_pads_o.pad_gpioa14.chip2pad = port_signals_soc2pad_i.gpio_a.gpio14_i;
          mux_to_pads_o.pad_gpioa14.output_en = s_reg2hw.pad_gpioa14_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa14.pull_up_en = s_reg2hw.pad_gpioa14_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa14.rx_en = port_signals_soc2pad_i.gpio_a.dir14_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa14.chip2pad = s_reg2hw.pad_gpioa14_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa14.output_en = s_reg2hw.pad_gpioa14_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa14.pull_up_en = s_reg2hw.pad_gpioa14_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa14.rx_en = s_reg2hw.pad_gpioa14_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa15
   always_comb begin
     unique case (s_reg2hw.pad_gpioa15_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA15_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa15.chip2pad = s_reg2hw.pad_gpioa15_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa15.output_en = s_reg2hw.pad_gpioa15_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa15.pull_up_en = s_reg2hw.pad_gpioa15_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa15.rx_en = s_reg2hw.pad_gpioa15_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA15_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa15.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa15.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa15.pull_up_en = s_reg2hw.pad_gpioa15_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa15.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA15_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa15.chip2pad = s_reg2hw.pad_gpioa15_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa15.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa15.pull_up_en = s_reg2hw.pad_gpioa15_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa15.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA15_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa15.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa15.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa15.pull_up_en = s_reg2hw.pad_gpioa15_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa15.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA15_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa15.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa15.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa15.pull_up_en = s_reg2hw.pad_gpioa15_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa15.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA15_SEL_GPIO_A_GPIO15: begin
          mux_to_pads_o.pad_gpioa15.chip2pad = port_signals_soc2pad_i.gpio_a.gpio15_i;
          mux_to_pads_o.pad_gpioa15.output_en = s_reg2hw.pad_gpioa15_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa15.pull_up_en = s_reg2hw.pad_gpioa15_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa15.rx_en = port_signals_soc2pad_i.gpio_a.dir15_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa15.chip2pad = s_reg2hw.pad_gpioa15_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa15.output_en = s_reg2hw.pad_gpioa15_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa15.pull_up_en = s_reg2hw.pad_gpioa15_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa15.rx_en = s_reg2hw.pad_gpioa15_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa16
   always_comb begin
     unique case (s_reg2hw.pad_gpioa16_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA16_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa16.chip2pad = s_reg2hw.pad_gpioa16_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa16.output_en = s_reg2hw.pad_gpioa16_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa16.pull_up_en = s_reg2hw.pad_gpioa16_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa16.rx_en = s_reg2hw.pad_gpioa16_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA16_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa16.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa16.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa16.pull_up_en = s_reg2hw.pad_gpioa16_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa16.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA16_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa16.chip2pad = s_reg2hw.pad_gpioa16_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa16.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa16.pull_up_en = s_reg2hw.pad_gpioa16_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa16.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA16_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa16.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa16.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa16.pull_up_en = s_reg2hw.pad_gpioa16_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa16.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA16_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa16.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa16.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa16.pull_up_en = s_reg2hw.pad_gpioa16_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa16.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA16_SEL_GPIO_A_GPIO16: begin
          mux_to_pads_o.pad_gpioa16.chip2pad = port_signals_soc2pad_i.gpio_a.gpio16_i;
          mux_to_pads_o.pad_gpioa16.output_en = s_reg2hw.pad_gpioa16_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa16.pull_up_en = s_reg2hw.pad_gpioa16_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa16.rx_en = port_signals_soc2pad_i.gpio_a.dir16_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa16.chip2pad = s_reg2hw.pad_gpioa16_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa16.output_en = s_reg2hw.pad_gpioa16_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa16.pull_up_en = s_reg2hw.pad_gpioa16_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa16.rx_en = s_reg2hw.pad_gpioa16_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa17
   always_comb begin
     unique case (s_reg2hw.pad_gpioa17_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA17_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa17.chip2pad = s_reg2hw.pad_gpioa17_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa17.output_en = s_reg2hw.pad_gpioa17_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa17.pull_up_en = s_reg2hw.pad_gpioa17_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa17.rx_en = s_reg2hw.pad_gpioa17_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA17_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa17.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa17.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa17.pull_up_en = s_reg2hw.pad_gpioa17_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa17.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA17_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa17.chip2pad = s_reg2hw.pad_gpioa17_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa17.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa17.pull_up_en = s_reg2hw.pad_gpioa17_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa17.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA17_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa17.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa17.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa17.pull_up_en = s_reg2hw.pad_gpioa17_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa17.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA17_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa17.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa17.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa17.pull_up_en = s_reg2hw.pad_gpioa17_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa17.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA17_SEL_GPIO_A_GPIO17: begin
          mux_to_pads_o.pad_gpioa17.chip2pad = port_signals_soc2pad_i.gpio_a.gpio17_i;
          mux_to_pads_o.pad_gpioa17.output_en = s_reg2hw.pad_gpioa17_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa17.pull_up_en = s_reg2hw.pad_gpioa17_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa17.rx_en = port_signals_soc2pad_i.gpio_a.dir17_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa17.chip2pad = s_reg2hw.pad_gpioa17_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa17.output_en = s_reg2hw.pad_gpioa17_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa17.pull_up_en = s_reg2hw.pad_gpioa17_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa17.rx_en = s_reg2hw.pad_gpioa17_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa18
   always_comb begin
     unique case (s_reg2hw.pad_gpioa18_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA18_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa18.chip2pad = s_reg2hw.pad_gpioa18_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa18.output_en = s_reg2hw.pad_gpioa18_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa18.pull_up_en = s_reg2hw.pad_gpioa18_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa18.rx_en = s_reg2hw.pad_gpioa18_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA18_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa18.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa18.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa18.pull_up_en = s_reg2hw.pad_gpioa18_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa18.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA18_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa18.chip2pad = s_reg2hw.pad_gpioa18_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa18.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa18.pull_up_en = s_reg2hw.pad_gpioa18_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa18.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA18_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa18.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa18.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa18.pull_up_en = s_reg2hw.pad_gpioa18_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa18.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA18_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa18.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa18.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa18.pull_up_en = s_reg2hw.pad_gpioa18_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa18.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA18_SEL_GPIO_A_GPIO18: begin
          mux_to_pads_o.pad_gpioa18.chip2pad = port_signals_soc2pad_i.gpio_a.gpio18_i;
          mux_to_pads_o.pad_gpioa18.output_en = s_reg2hw.pad_gpioa18_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa18.pull_up_en = s_reg2hw.pad_gpioa18_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa18.rx_en = port_signals_soc2pad_i.gpio_a.dir18_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa18.chip2pad = s_reg2hw.pad_gpioa18_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa18.output_en = s_reg2hw.pad_gpioa18_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa18.pull_up_en = s_reg2hw.pad_gpioa18_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa18.rx_en = s_reg2hw.pad_gpioa18_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa19
   always_comb begin
     unique case (s_reg2hw.pad_gpioa19_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA19_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa19.chip2pad = s_reg2hw.pad_gpioa19_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa19.output_en = s_reg2hw.pad_gpioa19_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa19.pull_up_en = s_reg2hw.pad_gpioa19_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa19.rx_en = s_reg2hw.pad_gpioa19_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA19_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa19.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa19.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa19.pull_up_en = s_reg2hw.pad_gpioa19_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa19.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA19_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa19.chip2pad = s_reg2hw.pad_gpioa19_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa19.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa19.pull_up_en = s_reg2hw.pad_gpioa19_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa19.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA19_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa19.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa19.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa19.pull_up_en = s_reg2hw.pad_gpioa19_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa19.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA19_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa19.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa19.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa19.pull_up_en = s_reg2hw.pad_gpioa19_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa19.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA19_SEL_GPIO_A_GPIO19: begin
          mux_to_pads_o.pad_gpioa19.chip2pad = port_signals_soc2pad_i.gpio_a.gpio19_i;
          mux_to_pads_o.pad_gpioa19.output_en = s_reg2hw.pad_gpioa19_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa19.pull_up_en = s_reg2hw.pad_gpioa19_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa19.rx_en = port_signals_soc2pad_i.gpio_a.dir19_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa19.chip2pad = s_reg2hw.pad_gpioa19_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa19.output_en = s_reg2hw.pad_gpioa19_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa19.pull_up_en = s_reg2hw.pad_gpioa19_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa19.rx_en = s_reg2hw.pad_gpioa19_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa20
   always_comb begin
     unique case (s_reg2hw.pad_gpioa20_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA20_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa20.chip2pad = s_reg2hw.pad_gpioa20_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa20.output_en = s_reg2hw.pad_gpioa20_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa20.pull_up_en = s_reg2hw.pad_gpioa20_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa20.rx_en = s_reg2hw.pad_gpioa20_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA20_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa20.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa20.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa20.pull_up_en = s_reg2hw.pad_gpioa20_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa20.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA20_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa20.chip2pad = s_reg2hw.pad_gpioa20_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa20.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa20.pull_up_en = s_reg2hw.pad_gpioa20_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa20.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA20_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa20.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa20.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa20.pull_up_en = s_reg2hw.pad_gpioa20_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa20.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA20_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa20.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa20.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa20.pull_up_en = s_reg2hw.pad_gpioa20_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa20.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA20_SEL_GPIO_A_GPIO20: begin
          mux_to_pads_o.pad_gpioa20.chip2pad = port_signals_soc2pad_i.gpio_a.gpio20_i;
          mux_to_pads_o.pad_gpioa20.output_en = s_reg2hw.pad_gpioa20_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa20.pull_up_en = s_reg2hw.pad_gpioa20_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa20.rx_en = port_signals_soc2pad_i.gpio_a.dir20_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa20.chip2pad = s_reg2hw.pad_gpioa20_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa20.output_en = s_reg2hw.pad_gpioa20_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa20.pull_up_en = s_reg2hw.pad_gpioa20_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa20.rx_en = s_reg2hw.pad_gpioa20_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa21
   always_comb begin
     unique case (s_reg2hw.pad_gpioa21_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA21_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa21.chip2pad = s_reg2hw.pad_gpioa21_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa21.output_en = s_reg2hw.pad_gpioa21_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa21.pull_up_en = s_reg2hw.pad_gpioa21_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa21.rx_en = s_reg2hw.pad_gpioa21_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA21_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa21.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa21.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa21.pull_up_en = s_reg2hw.pad_gpioa21_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa21.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA21_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa21.chip2pad = s_reg2hw.pad_gpioa21_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa21.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa21.pull_up_en = s_reg2hw.pad_gpioa21_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa21.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA21_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa21.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa21.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa21.pull_up_en = s_reg2hw.pad_gpioa21_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa21.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA21_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa21.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa21.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa21.pull_up_en = s_reg2hw.pad_gpioa21_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa21.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA21_SEL_GPIO_A_GPIO21: begin
          mux_to_pads_o.pad_gpioa21.chip2pad = port_signals_soc2pad_i.gpio_a.gpio21_i;
          mux_to_pads_o.pad_gpioa21.output_en = s_reg2hw.pad_gpioa21_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa21.pull_up_en = s_reg2hw.pad_gpioa21_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa21.rx_en = port_signals_soc2pad_i.gpio_a.dir21_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa21.chip2pad = s_reg2hw.pad_gpioa21_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa21.output_en = s_reg2hw.pad_gpioa21_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa21.pull_up_en = s_reg2hw.pad_gpioa21_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa21.rx_en = s_reg2hw.pad_gpioa21_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa22
   always_comb begin
     unique case (s_reg2hw.pad_gpioa22_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA22_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa22.chip2pad = s_reg2hw.pad_gpioa22_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa22.output_en = s_reg2hw.pad_gpioa22_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa22.pull_up_en = s_reg2hw.pad_gpioa22_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa22.rx_en = s_reg2hw.pad_gpioa22_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA22_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa22.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa22.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa22.pull_up_en = s_reg2hw.pad_gpioa22_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa22.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA22_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa22.chip2pad = s_reg2hw.pad_gpioa22_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa22.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa22.pull_up_en = s_reg2hw.pad_gpioa22_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa22.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA22_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa22.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa22.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa22.pull_up_en = s_reg2hw.pad_gpioa22_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa22.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA22_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa22.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa22.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa22.pull_up_en = s_reg2hw.pad_gpioa22_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa22.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA22_SEL_GPIO_A_GPIO22: begin
          mux_to_pads_o.pad_gpioa22.chip2pad = port_signals_soc2pad_i.gpio_a.gpio22_i;
          mux_to_pads_o.pad_gpioa22.output_en = s_reg2hw.pad_gpioa22_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa22.pull_up_en = s_reg2hw.pad_gpioa22_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa22.rx_en = port_signals_soc2pad_i.gpio_a.dir22_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa22.chip2pad = s_reg2hw.pad_gpioa22_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa22.output_en = s_reg2hw.pad_gpioa22_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa22.pull_up_en = s_reg2hw.pad_gpioa22_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa22.rx_en = s_reg2hw.pad_gpioa22_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa23
   always_comb begin
     unique case (s_reg2hw.pad_gpioa23_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA23_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa23.chip2pad = s_reg2hw.pad_gpioa23_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa23.output_en = s_reg2hw.pad_gpioa23_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa23.pull_up_en = s_reg2hw.pad_gpioa23_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa23.rx_en = s_reg2hw.pad_gpioa23_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA23_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa23.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa23.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa23.pull_up_en = s_reg2hw.pad_gpioa23_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa23.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA23_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa23.chip2pad = s_reg2hw.pad_gpioa23_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa23.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa23.pull_up_en = s_reg2hw.pad_gpioa23_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa23.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA23_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa23.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa23.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa23.pull_up_en = s_reg2hw.pad_gpioa23_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa23.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA23_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa23.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa23.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa23.pull_up_en = s_reg2hw.pad_gpioa23_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa23.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA23_SEL_GPIO_A_GPIO23: begin
          mux_to_pads_o.pad_gpioa23.chip2pad = port_signals_soc2pad_i.gpio_a.gpio23_i;
          mux_to_pads_o.pad_gpioa23.output_en = s_reg2hw.pad_gpioa23_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa23.pull_up_en = s_reg2hw.pad_gpioa23_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa23.rx_en = port_signals_soc2pad_i.gpio_a.dir23_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa23.chip2pad = s_reg2hw.pad_gpioa23_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa23.output_en = s_reg2hw.pad_gpioa23_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa23.pull_up_en = s_reg2hw.pad_gpioa23_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa23.rx_en = s_reg2hw.pad_gpioa23_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa24
   always_comb begin
     unique case (s_reg2hw.pad_gpioa24_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA24_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa24.chip2pad = s_reg2hw.pad_gpioa24_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa24.output_en = s_reg2hw.pad_gpioa24_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa24.pull_up_en = s_reg2hw.pad_gpioa24_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa24.rx_en = s_reg2hw.pad_gpioa24_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA24_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa24.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa24.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa24.pull_up_en = s_reg2hw.pad_gpioa24_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa24.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA24_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa24.chip2pad = s_reg2hw.pad_gpioa24_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa24.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa24.pull_up_en = s_reg2hw.pad_gpioa24_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa24.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA24_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa24.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa24.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa24.pull_up_en = s_reg2hw.pad_gpioa24_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa24.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA24_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa24.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa24.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa24.pull_up_en = s_reg2hw.pad_gpioa24_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa24.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA24_SEL_GPIO_A_GPIO24: begin
          mux_to_pads_o.pad_gpioa24.chip2pad = port_signals_soc2pad_i.gpio_a.gpio24_i;
          mux_to_pads_o.pad_gpioa24.output_en = s_reg2hw.pad_gpioa24_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa24.pull_up_en = s_reg2hw.pad_gpioa24_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa24.rx_en = port_signals_soc2pad_i.gpio_a.dir24_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa24.chip2pad = s_reg2hw.pad_gpioa24_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa24.output_en = s_reg2hw.pad_gpioa24_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa24.pull_up_en = s_reg2hw.pad_gpioa24_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa24.rx_en = s_reg2hw.pad_gpioa24_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa25
   always_comb begin
     unique case (s_reg2hw.pad_gpioa25_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA25_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa25.chip2pad = s_reg2hw.pad_gpioa25_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa25.output_en = s_reg2hw.pad_gpioa25_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa25.pull_up_en = s_reg2hw.pad_gpioa25_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa25.rx_en = s_reg2hw.pad_gpioa25_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA25_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa25.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa25.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa25.pull_up_en = s_reg2hw.pad_gpioa25_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa25.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA25_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa25.chip2pad = s_reg2hw.pad_gpioa25_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa25.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa25.pull_up_en = s_reg2hw.pad_gpioa25_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa25.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA25_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa25.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa25.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa25.pull_up_en = s_reg2hw.pad_gpioa25_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa25.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA25_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa25.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa25.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa25.pull_up_en = s_reg2hw.pad_gpioa25_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa25.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA25_SEL_GPIO_A_GPIO25: begin
          mux_to_pads_o.pad_gpioa25.chip2pad = port_signals_soc2pad_i.gpio_a.gpio25_i;
          mux_to_pads_o.pad_gpioa25.output_en = s_reg2hw.pad_gpioa25_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa25.pull_up_en = s_reg2hw.pad_gpioa25_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa25.rx_en = port_signals_soc2pad_i.gpio_a.dir25_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa25.chip2pad = s_reg2hw.pad_gpioa25_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa25.output_en = s_reg2hw.pad_gpioa25_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa25.pull_up_en = s_reg2hw.pad_gpioa25_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa25.rx_en = s_reg2hw.pad_gpioa25_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa26
   always_comb begin
     unique case (s_reg2hw.pad_gpioa26_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA26_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa26.chip2pad = s_reg2hw.pad_gpioa26_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa26.output_en = s_reg2hw.pad_gpioa26_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa26.pull_up_en = s_reg2hw.pad_gpioa26_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa26.rx_en = s_reg2hw.pad_gpioa26_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA26_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa26.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa26.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa26.pull_up_en = s_reg2hw.pad_gpioa26_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa26.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA26_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa26.chip2pad = s_reg2hw.pad_gpioa26_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa26.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa26.pull_up_en = s_reg2hw.pad_gpioa26_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa26.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA26_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa26.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa26.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa26.pull_up_en = s_reg2hw.pad_gpioa26_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa26.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA26_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa26.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa26.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa26.pull_up_en = s_reg2hw.pad_gpioa26_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa26.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA26_SEL_GPIO_A_GPIO26: begin
          mux_to_pads_o.pad_gpioa26.chip2pad = port_signals_soc2pad_i.gpio_a.gpio26_i;
          mux_to_pads_o.pad_gpioa26.output_en = s_reg2hw.pad_gpioa26_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa26.pull_up_en = s_reg2hw.pad_gpioa26_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa26.rx_en = port_signals_soc2pad_i.gpio_a.dir26_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa26.chip2pad = s_reg2hw.pad_gpioa26_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa26.output_en = s_reg2hw.pad_gpioa26_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa26.pull_up_en = s_reg2hw.pad_gpioa26_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa26.rx_en = s_reg2hw.pad_gpioa26_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa27
   always_comb begin
     unique case (s_reg2hw.pad_gpioa27_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA27_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa27.chip2pad = s_reg2hw.pad_gpioa27_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa27.output_en = s_reg2hw.pad_gpioa27_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa27.pull_up_en = s_reg2hw.pad_gpioa27_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa27.rx_en = s_reg2hw.pad_gpioa27_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA27_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa27.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa27.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa27.pull_up_en = s_reg2hw.pad_gpioa27_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa27.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA27_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa27.chip2pad = s_reg2hw.pad_gpioa27_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa27.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa27.pull_up_en = s_reg2hw.pad_gpioa27_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa27.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA27_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa27.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa27.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa27.pull_up_en = s_reg2hw.pad_gpioa27_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa27.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA27_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa27.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa27.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa27.pull_up_en = s_reg2hw.pad_gpioa27_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa27.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA27_SEL_GPIO_A_GPIO27: begin
          mux_to_pads_o.pad_gpioa27.chip2pad = port_signals_soc2pad_i.gpio_a.gpio27_i;
          mux_to_pads_o.pad_gpioa27.output_en = s_reg2hw.pad_gpioa27_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa27.pull_up_en = s_reg2hw.pad_gpioa27_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa27.rx_en = port_signals_soc2pad_i.gpio_a.dir27_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa27.chip2pad = s_reg2hw.pad_gpioa27_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa27.output_en = s_reg2hw.pad_gpioa27_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa27.pull_up_en = s_reg2hw.pad_gpioa27_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa27.rx_en = s_reg2hw.pad_gpioa27_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa28
   always_comb begin
     unique case (s_reg2hw.pad_gpioa28_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA28_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa28.chip2pad = s_reg2hw.pad_gpioa28_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa28.output_en = s_reg2hw.pad_gpioa28_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa28.pull_up_en = s_reg2hw.pad_gpioa28_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa28.rx_en = s_reg2hw.pad_gpioa28_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA28_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa28.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa28.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa28.pull_up_en = s_reg2hw.pad_gpioa28_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa28.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA28_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa28.chip2pad = s_reg2hw.pad_gpioa28_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa28.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa28.pull_up_en = s_reg2hw.pad_gpioa28_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa28.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA28_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa28.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa28.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa28.pull_up_en = s_reg2hw.pad_gpioa28_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa28.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA28_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa28.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa28.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa28.pull_up_en = s_reg2hw.pad_gpioa28_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa28.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA28_SEL_GPIO_A_GPIO28: begin
          mux_to_pads_o.pad_gpioa28.chip2pad = port_signals_soc2pad_i.gpio_a.gpio28_i;
          mux_to_pads_o.pad_gpioa28.output_en = s_reg2hw.pad_gpioa28_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa28.pull_up_en = s_reg2hw.pad_gpioa28_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa28.rx_en = port_signals_soc2pad_i.gpio_a.dir28_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa28.chip2pad = s_reg2hw.pad_gpioa28_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa28.output_en = s_reg2hw.pad_gpioa28_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa28.pull_up_en = s_reg2hw.pad_gpioa28_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa28.rx_en = s_reg2hw.pad_gpioa28_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa29
   always_comb begin
     unique case (s_reg2hw.pad_gpioa29_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA29_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa29.chip2pad = s_reg2hw.pad_gpioa29_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa29.output_en = s_reg2hw.pad_gpioa29_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa29.pull_up_en = s_reg2hw.pad_gpioa29_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa29.rx_en = s_reg2hw.pad_gpioa29_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA29_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa29.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa29.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa29.pull_up_en = s_reg2hw.pad_gpioa29_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa29.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA29_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa29.chip2pad = s_reg2hw.pad_gpioa29_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa29.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa29.pull_up_en = s_reg2hw.pad_gpioa29_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa29.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA29_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa29.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa29.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa29.pull_up_en = s_reg2hw.pad_gpioa29_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa29.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA29_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa29.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa29.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa29.pull_up_en = s_reg2hw.pad_gpioa29_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa29.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA29_SEL_GPIO_A_GPIO29: begin
          mux_to_pads_o.pad_gpioa29.chip2pad = port_signals_soc2pad_i.gpio_a.gpio29_i;
          mux_to_pads_o.pad_gpioa29.output_en = s_reg2hw.pad_gpioa29_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa29.pull_up_en = s_reg2hw.pad_gpioa29_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa29.rx_en = port_signals_soc2pad_i.gpio_a.dir29_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa29.chip2pad = s_reg2hw.pad_gpioa29_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa29.output_en = s_reg2hw.pad_gpioa29_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa29.pull_up_en = s_reg2hw.pad_gpioa29_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa29.rx_en = s_reg2hw.pad_gpioa29_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa30
   always_comb begin
     unique case (s_reg2hw.pad_gpioa30_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA30_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa30.chip2pad = s_reg2hw.pad_gpioa30_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa30.output_en = s_reg2hw.pad_gpioa30_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa30.pull_up_en = s_reg2hw.pad_gpioa30_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa30.rx_en = s_reg2hw.pad_gpioa30_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA30_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa30.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa30.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa30.pull_up_en = s_reg2hw.pad_gpioa30_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa30.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA30_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa30.chip2pad = s_reg2hw.pad_gpioa30_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa30.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa30.pull_up_en = s_reg2hw.pad_gpioa30_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa30.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA30_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa30.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa30.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa30.pull_up_en = s_reg2hw.pad_gpioa30_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa30.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA30_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa30.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa30.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa30.pull_up_en = s_reg2hw.pad_gpioa30_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa30.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA30_SEL_GPIO_A_GPIO30: begin
          mux_to_pads_o.pad_gpioa30.chip2pad = port_signals_soc2pad_i.gpio_a.gpio30_i;
          mux_to_pads_o.pad_gpioa30.output_en = s_reg2hw.pad_gpioa30_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa30.pull_up_en = s_reg2hw.pad_gpioa30_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa30.rx_en = port_signals_soc2pad_i.gpio_a.dir30_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa30.chip2pad = s_reg2hw.pad_gpioa30_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa30.output_en = s_reg2hw.pad_gpioa30_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa30.pull_up_en = s_reg2hw.pad_gpioa30_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa30.rx_en = s_reg2hw.pad_gpioa30_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioa31
   always_comb begin
     unique case (s_reg2hw.pad_gpioa31_mux_sel.q)
       PAD_MUX_GROUP_ALL_PAD_GPIOA31_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioa31.chip2pad = s_reg2hw.pad_gpioa31_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa31.output_en = s_reg2hw.pad_gpioa31_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa31.pull_up_en = s_reg2hw.pad_gpioa31_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa31.rx_en = s_reg2hw.pad_gpioa31_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA31_SEL_SPI_CSN: begin
          mux_to_pads_o.pad_gpioa31.chip2pad = port_signals_soc2pad_i.spi.csn;
          mux_to_pads_o.pad_gpioa31.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa31.pull_up_en = s_reg2hw.pad_gpioa31_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa31.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA31_SEL_SPI_MISO: begin
          mux_to_pads_o.pad_gpioa31.chip2pad = s_reg2hw.pad_gpioa31_cfg.chip2pad.q;
          mux_to_pads_o.pad_gpioa31.output_en = 1'b0;
          mux_to_pads_o.pad_gpioa31.pull_up_en = s_reg2hw.pad_gpioa31_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa31.rx_en = 1'b1;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA31_SEL_SPI_MOSI: begin
          mux_to_pads_o.pad_gpioa31.chip2pad = port_signals_soc2pad_i.spi.mosi & port_signals_soc2pad_i.spi.spi_en;
          mux_to_pads_o.pad_gpioa31.output_en = ~port_signals_soc2pad_i.spi.oen;
          mux_to_pads_o.pad_gpioa31.pull_up_en = s_reg2hw.pad_gpioa31_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa31.rx_en = port_signals_soc2pad_i.spi.oen;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA31_SEL_SPI_SCK: begin
          mux_to_pads_o.pad_gpioa31.chip2pad = port_signals_soc2pad_i.spi.sck;
          mux_to_pads_o.pad_gpioa31.output_en = 1'b1;
          mux_to_pads_o.pad_gpioa31.pull_up_en = s_reg2hw.pad_gpioa31_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa31.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_ALL_PAD_GPIOA31_SEL_GPIO_A_GPIO31: begin
          mux_to_pads_o.pad_gpioa31.chip2pad = port_signals_soc2pad_i.gpio_a.gpio31_i;
          mux_to_pads_o.pad_gpioa31.output_en = s_reg2hw.pad_gpioa31_cfg.output_en.q;
          mux_to_pads_o.pad_gpioa31.pull_up_en = s_reg2hw.pad_gpioa31_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioa31.rx_en = port_signals_soc2pad_i.gpio_a.dir31_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioa31.chip2pad = s_reg2hw.pad_gpioa31_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioa31.output_en = s_reg2hw.pad_gpioa31_cfg.output_en.q;
         mux_to_pads_o.pad_gpioa31.pull_up_en = s_reg2hw.pad_gpioa31_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioa31.rx_en = s_reg2hw.pad_gpioa31_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob0
   always_comb begin
     unique case (s_reg2hw.pad_gpiob0_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob0.chip2pad = s_reg2hw.pad_gpiob0_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob0.output_en = s_reg2hw.pad_gpiob0_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob0.pull_up_en = s_reg2hw.pad_gpiob0_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob0.rx_en = s_reg2hw.pad_gpiob0_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob0.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob0.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob0.pull_up_en = s_reg2hw.pad_gpiob0_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob0.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob0.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob0.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob0.pull_up_en = s_reg2hw.pad_gpiob0_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob0.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob0.chip2pad = s_reg2hw.pad_gpiob0_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob0.output_en = s_reg2hw.pad_gpiob0_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob0.pull_up_en = s_reg2hw.pad_gpiob0_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob0.rx_en = s_reg2hw.pad_gpiob0_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob1
   always_comb begin
     unique case (s_reg2hw.pad_gpiob1_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob1.chip2pad = s_reg2hw.pad_gpiob1_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob1.output_en = s_reg2hw.pad_gpiob1_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob1.pull_up_en = s_reg2hw.pad_gpiob1_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob1.rx_en = s_reg2hw.pad_gpiob1_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob1.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob1.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob1.pull_up_en = s_reg2hw.pad_gpiob1_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob1.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob1.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob1.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob1.pull_up_en = s_reg2hw.pad_gpiob1_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob1.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob1.chip2pad = s_reg2hw.pad_gpiob1_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob1.output_en = s_reg2hw.pad_gpiob1_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob1.pull_up_en = s_reg2hw.pad_gpiob1_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob1.rx_en = s_reg2hw.pad_gpiob1_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob2
   always_comb begin
     unique case (s_reg2hw.pad_gpiob2_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob2.chip2pad = s_reg2hw.pad_gpiob2_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob2.output_en = s_reg2hw.pad_gpiob2_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob2.pull_up_en = s_reg2hw.pad_gpiob2_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob2.rx_en = s_reg2hw.pad_gpiob2_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob2.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob2.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob2.pull_up_en = s_reg2hw.pad_gpiob2_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob2.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob2.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob2.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob2.pull_up_en = s_reg2hw.pad_gpiob2_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob2.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob2.chip2pad = s_reg2hw.pad_gpiob2_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob2.output_en = s_reg2hw.pad_gpiob2_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob2.pull_up_en = s_reg2hw.pad_gpiob2_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob2.rx_en = s_reg2hw.pad_gpiob2_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob3
   always_comb begin
     unique case (s_reg2hw.pad_gpiob3_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob3.chip2pad = s_reg2hw.pad_gpiob3_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob3.output_en = s_reg2hw.pad_gpiob3_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob3.pull_up_en = s_reg2hw.pad_gpiob3_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob3.rx_en = s_reg2hw.pad_gpiob3_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob3.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob3.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob3.pull_up_en = s_reg2hw.pad_gpiob3_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob3.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob3.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob3.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob3.pull_up_en = s_reg2hw.pad_gpiob3_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob3.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob3.chip2pad = s_reg2hw.pad_gpiob3_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob3.output_en = s_reg2hw.pad_gpiob3_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob3.pull_up_en = s_reg2hw.pad_gpiob3_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob3.rx_en = s_reg2hw.pad_gpiob3_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob4
   always_comb begin
     unique case (s_reg2hw.pad_gpiob4_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob4.chip2pad = s_reg2hw.pad_gpiob4_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob4.output_en = s_reg2hw.pad_gpiob4_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob4.pull_up_en = s_reg2hw.pad_gpiob4_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob4.rx_en = s_reg2hw.pad_gpiob4_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob4.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob4.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob4.pull_up_en = s_reg2hw.pad_gpiob4_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob4.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob4.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob4.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob4.pull_up_en = s_reg2hw.pad_gpiob4_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob4.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob4.chip2pad = s_reg2hw.pad_gpiob4_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob4.output_en = s_reg2hw.pad_gpiob4_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob4.pull_up_en = s_reg2hw.pad_gpiob4_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob4.rx_en = s_reg2hw.pad_gpiob4_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob5
   always_comb begin
     unique case (s_reg2hw.pad_gpiob5_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob5.chip2pad = s_reg2hw.pad_gpiob5_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob5.output_en = s_reg2hw.pad_gpiob5_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob5.pull_up_en = s_reg2hw.pad_gpiob5_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob5.rx_en = s_reg2hw.pad_gpiob5_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob5.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob5.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob5.pull_up_en = s_reg2hw.pad_gpiob5_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob5.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob5.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob5.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob5.pull_up_en = s_reg2hw.pad_gpiob5_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob5.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob5.chip2pad = s_reg2hw.pad_gpiob5_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob5.output_en = s_reg2hw.pad_gpiob5_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob5.pull_up_en = s_reg2hw.pad_gpiob5_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob5.rx_en = s_reg2hw.pad_gpiob5_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob6
   always_comb begin
     unique case (s_reg2hw.pad_gpiob6_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob6.chip2pad = s_reg2hw.pad_gpiob6_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob6.output_en = s_reg2hw.pad_gpiob6_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob6.pull_up_en = s_reg2hw.pad_gpiob6_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob6.rx_en = s_reg2hw.pad_gpiob6_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob6.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob6.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob6.pull_up_en = s_reg2hw.pad_gpiob6_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob6.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob6.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob6.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob6.pull_up_en = s_reg2hw.pad_gpiob6_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob6.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob6.chip2pad = s_reg2hw.pad_gpiob6_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob6.output_en = s_reg2hw.pad_gpiob6_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob6.pull_up_en = s_reg2hw.pad_gpiob6_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob6.rx_en = s_reg2hw.pad_gpiob6_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob7
   always_comb begin
     unique case (s_reg2hw.pad_gpiob7_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob7.chip2pad = s_reg2hw.pad_gpiob7_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob7.output_en = s_reg2hw.pad_gpiob7_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob7.pull_up_en = s_reg2hw.pad_gpiob7_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob7.rx_en = s_reg2hw.pad_gpiob7_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob7.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob7.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob7.pull_up_en = s_reg2hw.pad_gpiob7_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob7.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob7.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob7.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob7.pull_up_en = s_reg2hw.pad_gpiob7_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob7.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob7.chip2pad = s_reg2hw.pad_gpiob7_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob7.output_en = s_reg2hw.pad_gpiob7_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob7.pull_up_en = s_reg2hw.pad_gpiob7_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob7.rx_en = s_reg2hw.pad_gpiob7_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob8
   always_comb begin
     unique case (s_reg2hw.pad_gpiob8_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob8.chip2pad = s_reg2hw.pad_gpiob8_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob8.output_en = s_reg2hw.pad_gpiob8_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob8.pull_up_en = s_reg2hw.pad_gpiob8_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob8.rx_en = s_reg2hw.pad_gpiob8_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob8.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob8.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob8.pull_up_en = s_reg2hw.pad_gpiob8_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob8.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob8.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob8.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob8.pull_up_en = s_reg2hw.pad_gpiob8_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob8.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob8.chip2pad = s_reg2hw.pad_gpiob8_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob8.output_en = s_reg2hw.pad_gpiob8_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob8.pull_up_en = s_reg2hw.pad_gpiob8_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob8.rx_en = s_reg2hw.pad_gpiob8_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob9
   always_comb begin
     unique case (s_reg2hw.pad_gpiob9_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob9.chip2pad = s_reg2hw.pad_gpiob9_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob9.output_en = s_reg2hw.pad_gpiob9_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob9.pull_up_en = s_reg2hw.pad_gpiob9_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob9.rx_en = s_reg2hw.pad_gpiob9_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob9.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob9.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob9.pull_up_en = s_reg2hw.pad_gpiob9_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob9.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob9.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob9.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob9.pull_up_en = s_reg2hw.pad_gpiob9_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob9.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob9.chip2pad = s_reg2hw.pad_gpiob9_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob9.output_en = s_reg2hw.pad_gpiob9_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob9.pull_up_en = s_reg2hw.pad_gpiob9_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob9.rx_en = s_reg2hw.pad_gpiob9_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob10
   always_comb begin
     unique case (s_reg2hw.pad_gpiob10_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob10.chip2pad = s_reg2hw.pad_gpiob10_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob10.output_en = s_reg2hw.pad_gpiob10_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob10.pull_up_en = s_reg2hw.pad_gpiob10_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob10.rx_en = s_reg2hw.pad_gpiob10_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob10.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob10.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob10.pull_up_en = s_reg2hw.pad_gpiob10_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob10.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob10.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob10.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob10.pull_up_en = s_reg2hw.pad_gpiob10_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob10.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob10.chip2pad = s_reg2hw.pad_gpiob10_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob10.output_en = s_reg2hw.pad_gpiob10_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob10.pull_up_en = s_reg2hw.pad_gpiob10_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob10.rx_en = s_reg2hw.pad_gpiob10_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob11
   always_comb begin
     unique case (s_reg2hw.pad_gpiob11_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob11.chip2pad = s_reg2hw.pad_gpiob11_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob11.output_en = s_reg2hw.pad_gpiob11_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob11.pull_up_en = s_reg2hw.pad_gpiob11_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob11.rx_en = s_reg2hw.pad_gpiob11_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob11.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob11.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob11.pull_up_en = s_reg2hw.pad_gpiob11_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob11.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob11.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob11.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob11.pull_up_en = s_reg2hw.pad_gpiob11_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob11.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob11.chip2pad = s_reg2hw.pad_gpiob11_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob11.output_en = s_reg2hw.pad_gpiob11_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob11.pull_up_en = s_reg2hw.pad_gpiob11_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob11.rx_en = s_reg2hw.pad_gpiob11_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob12
   always_comb begin
     unique case (s_reg2hw.pad_gpiob12_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob12.chip2pad = s_reg2hw.pad_gpiob12_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob12.output_en = s_reg2hw.pad_gpiob12_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob12.pull_up_en = s_reg2hw.pad_gpiob12_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob12.rx_en = s_reg2hw.pad_gpiob12_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob12.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob12.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob12.pull_up_en = s_reg2hw.pad_gpiob12_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob12.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob12.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob12.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob12.pull_up_en = s_reg2hw.pad_gpiob12_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob12.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob12.chip2pad = s_reg2hw.pad_gpiob12_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob12.output_en = s_reg2hw.pad_gpiob12_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob12.pull_up_en = s_reg2hw.pad_gpiob12_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob12.rx_en = s_reg2hw.pad_gpiob12_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob13
   always_comb begin
     unique case (s_reg2hw.pad_gpiob13_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob13.chip2pad = s_reg2hw.pad_gpiob13_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob13.output_en = s_reg2hw.pad_gpiob13_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob13.pull_up_en = s_reg2hw.pad_gpiob13_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob13.rx_en = s_reg2hw.pad_gpiob13_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob13.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob13.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob13.pull_up_en = s_reg2hw.pad_gpiob13_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob13.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob13.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob13.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob13.pull_up_en = s_reg2hw.pad_gpiob13_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob13.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob13.chip2pad = s_reg2hw.pad_gpiob13_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob13.output_en = s_reg2hw.pad_gpiob13_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob13.pull_up_en = s_reg2hw.pad_gpiob13_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob13.rx_en = s_reg2hw.pad_gpiob13_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob14
   always_comb begin
     unique case (s_reg2hw.pad_gpiob14_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob14.chip2pad = s_reg2hw.pad_gpiob14_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob14.output_en = s_reg2hw.pad_gpiob14_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob14.pull_up_en = s_reg2hw.pad_gpiob14_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob14.rx_en = s_reg2hw.pad_gpiob14_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob14.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob14.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob14.pull_up_en = s_reg2hw.pad_gpiob14_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob14.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob14.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob14.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob14.pull_up_en = s_reg2hw.pad_gpiob14_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob14.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob14.chip2pad = s_reg2hw.pad_gpiob14_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob14.output_en = s_reg2hw.pad_gpiob14_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob14.pull_up_en = s_reg2hw.pad_gpiob14_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob14.rx_en = s_reg2hw.pad_gpiob14_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob15
   always_comb begin
     unique case (s_reg2hw.pad_gpiob15_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob15.chip2pad = s_reg2hw.pad_gpiob15_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob15.output_en = s_reg2hw.pad_gpiob15_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob15.pull_up_en = s_reg2hw.pad_gpiob15_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob15.rx_en = s_reg2hw.pad_gpiob15_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob15.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob15.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob15.pull_up_en = s_reg2hw.pad_gpiob15_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob15.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob15.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob15.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob15.pull_up_en = s_reg2hw.pad_gpiob15_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob15.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob15.chip2pad = s_reg2hw.pad_gpiob15_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob15.output_en = s_reg2hw.pad_gpiob15_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob15.pull_up_en = s_reg2hw.pad_gpiob15_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob15.rx_en = s_reg2hw.pad_gpiob15_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob16
   always_comb begin
     unique case (s_reg2hw.pad_gpiob16_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob16.chip2pad = s_reg2hw.pad_gpiob16_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob16.output_en = s_reg2hw.pad_gpiob16_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob16.pull_up_en = s_reg2hw.pad_gpiob16_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob16.rx_en = s_reg2hw.pad_gpiob16_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob16.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob16.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob16.pull_up_en = s_reg2hw.pad_gpiob16_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob16.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob16.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob16.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob16.pull_up_en = s_reg2hw.pad_gpiob16_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob16.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob16.chip2pad = s_reg2hw.pad_gpiob16_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob16.output_en = s_reg2hw.pad_gpiob16_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob16.pull_up_en = s_reg2hw.pad_gpiob16_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob16.rx_en = s_reg2hw.pad_gpiob16_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob17
   always_comb begin
     unique case (s_reg2hw.pad_gpiob17_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob17.chip2pad = s_reg2hw.pad_gpiob17_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob17.output_en = s_reg2hw.pad_gpiob17_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob17.pull_up_en = s_reg2hw.pad_gpiob17_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob17.rx_en = s_reg2hw.pad_gpiob17_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob17.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob17.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob17.pull_up_en = s_reg2hw.pad_gpiob17_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob17.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob17.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob17.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob17.pull_up_en = s_reg2hw.pad_gpiob17_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob17.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob17.chip2pad = s_reg2hw.pad_gpiob17_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob17.output_en = s_reg2hw.pad_gpiob17_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob17.pull_up_en = s_reg2hw.pad_gpiob17_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob17.rx_en = s_reg2hw.pad_gpiob17_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob18
   always_comb begin
     unique case (s_reg2hw.pad_gpiob18_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob18.chip2pad = s_reg2hw.pad_gpiob18_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob18.output_en = s_reg2hw.pad_gpiob18_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob18.pull_up_en = s_reg2hw.pad_gpiob18_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob18.rx_en = s_reg2hw.pad_gpiob18_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob18.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob18.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob18.pull_up_en = s_reg2hw.pad_gpiob18_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob18.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob18.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob18.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob18.pull_up_en = s_reg2hw.pad_gpiob18_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob18.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob18.chip2pad = s_reg2hw.pad_gpiob18_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob18.output_en = s_reg2hw.pad_gpiob18_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob18.pull_up_en = s_reg2hw.pad_gpiob18_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob18.rx_en = s_reg2hw.pad_gpiob18_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob19
   always_comb begin
     unique case (s_reg2hw.pad_gpiob19_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob19.chip2pad = s_reg2hw.pad_gpiob19_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob19.output_en = s_reg2hw.pad_gpiob19_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob19.pull_up_en = s_reg2hw.pad_gpiob19_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob19.rx_en = s_reg2hw.pad_gpiob19_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob19.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob19.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob19.pull_up_en = s_reg2hw.pad_gpiob19_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob19.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob19.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob19.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob19.pull_up_en = s_reg2hw.pad_gpiob19_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob19.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob19.chip2pad = s_reg2hw.pad_gpiob19_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob19.output_en = s_reg2hw.pad_gpiob19_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob19.pull_up_en = s_reg2hw.pad_gpiob19_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob19.rx_en = s_reg2hw.pad_gpiob19_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob20
   always_comb begin
     unique case (s_reg2hw.pad_gpiob20_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob20.chip2pad = s_reg2hw.pad_gpiob20_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob20.output_en = s_reg2hw.pad_gpiob20_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob20.pull_up_en = s_reg2hw.pad_gpiob20_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob20.rx_en = s_reg2hw.pad_gpiob20_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob20.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob20.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob20.pull_up_en = s_reg2hw.pad_gpiob20_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob20.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob20.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob20.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob20.pull_up_en = s_reg2hw.pad_gpiob20_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob20.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob20.chip2pad = s_reg2hw.pad_gpiob20_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob20.output_en = s_reg2hw.pad_gpiob20_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob20.pull_up_en = s_reg2hw.pad_gpiob20_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob20.rx_en = s_reg2hw.pad_gpiob20_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob21
   always_comb begin
     unique case (s_reg2hw.pad_gpiob21_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob21.chip2pad = s_reg2hw.pad_gpiob21_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob21.output_en = s_reg2hw.pad_gpiob21_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob21.pull_up_en = s_reg2hw.pad_gpiob21_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob21.rx_en = s_reg2hw.pad_gpiob21_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob21.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob21.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob21.pull_up_en = s_reg2hw.pad_gpiob21_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob21.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob21.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob21.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob21.pull_up_en = s_reg2hw.pad_gpiob21_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob21.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob21.chip2pad = s_reg2hw.pad_gpiob21_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob21.output_en = s_reg2hw.pad_gpiob21_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob21.pull_up_en = s_reg2hw.pad_gpiob21_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob21.rx_en = s_reg2hw.pad_gpiob21_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob22
   always_comb begin
     unique case (s_reg2hw.pad_gpiob22_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob22.chip2pad = s_reg2hw.pad_gpiob22_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob22.output_en = s_reg2hw.pad_gpiob22_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob22.pull_up_en = s_reg2hw.pad_gpiob22_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob22.rx_en = s_reg2hw.pad_gpiob22_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob22.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob22.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob22.pull_up_en = s_reg2hw.pad_gpiob22_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob22.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob22.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob22.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob22.pull_up_en = s_reg2hw.pad_gpiob22_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob22.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob22.chip2pad = s_reg2hw.pad_gpiob22_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob22.output_en = s_reg2hw.pad_gpiob22_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob22.pull_up_en = s_reg2hw.pad_gpiob22_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob22.rx_en = s_reg2hw.pad_gpiob22_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob23
   always_comb begin
     unique case (s_reg2hw.pad_gpiob23_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob23.chip2pad = s_reg2hw.pad_gpiob23_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob23.output_en = s_reg2hw.pad_gpiob23_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob23.pull_up_en = s_reg2hw.pad_gpiob23_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob23.rx_en = s_reg2hw.pad_gpiob23_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob23.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob23.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob23.pull_up_en = s_reg2hw.pad_gpiob23_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob23.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob23.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob23.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob23.pull_up_en = s_reg2hw.pad_gpiob23_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob23.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob23.chip2pad = s_reg2hw.pad_gpiob23_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob23.output_en = s_reg2hw.pad_gpiob23_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob23.pull_up_en = s_reg2hw.pad_gpiob23_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob23.rx_en = s_reg2hw.pad_gpiob23_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob24
   always_comb begin
     unique case (s_reg2hw.pad_gpiob24_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob24.chip2pad = s_reg2hw.pad_gpiob24_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob24.output_en = s_reg2hw.pad_gpiob24_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob24.pull_up_en = s_reg2hw.pad_gpiob24_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob24.rx_en = s_reg2hw.pad_gpiob24_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob24.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob24.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob24.pull_up_en = s_reg2hw.pad_gpiob24_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob24.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob24.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob24.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob24.pull_up_en = s_reg2hw.pad_gpiob24_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob24.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob24.chip2pad = s_reg2hw.pad_gpiob24_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob24.output_en = s_reg2hw.pad_gpiob24_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob24.pull_up_en = s_reg2hw.pad_gpiob24_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob24.rx_en = s_reg2hw.pad_gpiob24_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob25
   always_comb begin
     unique case (s_reg2hw.pad_gpiob25_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob25.chip2pad = s_reg2hw.pad_gpiob25_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob25.output_en = s_reg2hw.pad_gpiob25_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob25.pull_up_en = s_reg2hw.pad_gpiob25_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob25.rx_en = s_reg2hw.pad_gpiob25_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob25.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob25.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob25.pull_up_en = s_reg2hw.pad_gpiob25_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob25.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob25.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob25.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob25.pull_up_en = s_reg2hw.pad_gpiob25_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob25.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob25.chip2pad = s_reg2hw.pad_gpiob25_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob25.output_en = s_reg2hw.pad_gpiob25_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob25.pull_up_en = s_reg2hw.pad_gpiob25_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob25.rx_en = s_reg2hw.pad_gpiob25_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob26
   always_comb begin
     unique case (s_reg2hw.pad_gpiob26_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob26.chip2pad = s_reg2hw.pad_gpiob26_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob26.output_en = s_reg2hw.pad_gpiob26_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob26.pull_up_en = s_reg2hw.pad_gpiob26_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob26.rx_en = s_reg2hw.pad_gpiob26_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob26.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob26.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob26.pull_up_en = s_reg2hw.pad_gpiob26_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob26.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob26.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob26.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob26.pull_up_en = s_reg2hw.pad_gpiob26_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob26.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob26.chip2pad = s_reg2hw.pad_gpiob26_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob26.output_en = s_reg2hw.pad_gpiob26_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob26.pull_up_en = s_reg2hw.pad_gpiob26_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob26.rx_en = s_reg2hw.pad_gpiob26_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob27
   always_comb begin
     unique case (s_reg2hw.pad_gpiob27_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob27.chip2pad = s_reg2hw.pad_gpiob27_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob27.output_en = s_reg2hw.pad_gpiob27_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob27.pull_up_en = s_reg2hw.pad_gpiob27_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob27.rx_en = s_reg2hw.pad_gpiob27_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob27.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob27.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob27.pull_up_en = s_reg2hw.pad_gpiob27_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob27.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob27.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob27.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob27.pull_up_en = s_reg2hw.pad_gpiob27_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob27.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob27.chip2pad = s_reg2hw.pad_gpiob27_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob27.output_en = s_reg2hw.pad_gpiob27_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob27.pull_up_en = s_reg2hw.pad_gpiob27_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob27.rx_en = s_reg2hw.pad_gpiob27_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob28
   always_comb begin
     unique case (s_reg2hw.pad_gpiob28_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob28.chip2pad = s_reg2hw.pad_gpiob28_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob28.output_en = s_reg2hw.pad_gpiob28_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob28.pull_up_en = s_reg2hw.pad_gpiob28_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob28.rx_en = s_reg2hw.pad_gpiob28_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob28.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob28.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob28.pull_up_en = s_reg2hw.pad_gpiob28_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob28.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob28.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob28.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob28.pull_up_en = s_reg2hw.pad_gpiob28_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob28.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob28.chip2pad = s_reg2hw.pad_gpiob28_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob28.output_en = s_reg2hw.pad_gpiob28_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob28.pull_up_en = s_reg2hw.pad_gpiob28_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob28.rx_en = s_reg2hw.pad_gpiob28_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob29
   always_comb begin
     unique case (s_reg2hw.pad_gpiob29_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob29.chip2pad = s_reg2hw.pad_gpiob29_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob29.output_en = s_reg2hw.pad_gpiob29_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob29.pull_up_en = s_reg2hw.pad_gpiob29_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob29.rx_en = s_reg2hw.pad_gpiob29_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob29.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob29.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob29.pull_up_en = s_reg2hw.pad_gpiob29_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob29.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob29.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob29.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob29.pull_up_en = s_reg2hw.pad_gpiob29_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob29.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob29.chip2pad = s_reg2hw.pad_gpiob29_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob29.output_en = s_reg2hw.pad_gpiob29_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob29.pull_up_en = s_reg2hw.pad_gpiob29_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob29.rx_en = s_reg2hw.pad_gpiob29_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob30
   always_comb begin
     unique case (s_reg2hw.pad_gpiob30_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob30.chip2pad = s_reg2hw.pad_gpiob30_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob30.output_en = s_reg2hw.pad_gpiob30_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob30.pull_up_en = s_reg2hw.pad_gpiob30_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob30.rx_en = s_reg2hw.pad_gpiob30_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob30.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob30.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob30.pull_up_en = s_reg2hw.pad_gpiob30_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob30.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob30.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob30.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob30.pull_up_en = s_reg2hw.pad_gpiob30_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob30.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob30.chip2pad = s_reg2hw.pad_gpiob30_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob30.output_en = s_reg2hw.pad_gpiob30_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob30.pull_up_en = s_reg2hw.pad_gpiob30_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob30.rx_en = s_reg2hw.pad_gpiob30_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpiob31
   always_comb begin
     unique case (s_reg2hw.pad_gpiob31_mux_sel.q)
       PAD_MUX_GROUP_GPIO_SETB_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpiob31.chip2pad = s_reg2hw.pad_gpiob31_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob31.output_en = s_reg2hw.pad_gpiob31_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob31.pull_up_en = s_reg2hw.pad_gpiob31_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob31.rx_en = s_reg2hw.pad_gpiob31_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SCL: begin
          mux_to_pads_o.pad_gpiob31.chip2pad = port_signals_soc2pad_i.i2c.scl;
          mux_to_pads_o.pad_gpiob31.output_en = 1'b1;
          mux_to_pads_o.pad_gpiob31.pull_up_en = s_reg2hw.pad_gpiob31_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob31.rx_en = 1'b0;
       end
       PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA: begin
          mux_to_pads_o.pad_gpiob31.chip2pad = port_signals_soc2pad_i.i2c.sda_o;
          mux_to_pads_o.pad_gpiob31.output_en = port_signals_soc2pad_i.i2c.out_en;
          mux_to_pads_o.pad_gpiob31.pull_up_en = s_reg2hw.pad_gpiob31_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpiob31.rx_en = ~port_signals_soc2pad_i.i2c.out_en;
       end
       default: begin
         mux_to_pads_o.pad_gpiob31.chip2pad = s_reg2hw.pad_gpiob31_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpiob31.output_en = s_reg2hw.pad_gpiob31_cfg.output_en.q;
         mux_to_pads_o.pad_gpiob31.pull_up_en = s_reg2hw.pad_gpiob31_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpiob31.rx_en = s_reg2hw.pad_gpiob31_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioc0
   always_comb begin
     unique case (s_reg2hw.pad_gpioc0_mux_sel.q)
       PAD_MUX_GROUP_PAD_GPIOC0_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioc0.chip2pad = s_reg2hw.pad_gpioc0_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc0.output_en = s_reg2hw.pad_gpioc0_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc0.pull_up_en = s_reg2hw.pad_gpioc0_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc0.rx_en = s_reg2hw.pad_gpioc0_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_PAD_GPIOC0_SEL_GPIO_C_GPIOC00: begin
          mux_to_pads_o.pad_gpioc0.chip2pad = port_signals_soc2pad_i.gpio_c.gpio0_i;
          mux_to_pads_o.pad_gpioc0.output_en = s_reg2hw.pad_gpioc0_cfg.output_en.q;
          mux_to_pads_o.pad_gpioc0.pull_up_en = s_reg2hw.pad_gpioc0_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioc0.rx_en = port_signals_soc2pad_i.gpio_c.dir0_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioc0.chip2pad = s_reg2hw.pad_gpioc0_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc0.output_en = s_reg2hw.pad_gpioc0_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc0.pull_up_en = s_reg2hw.pad_gpioc0_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc0.rx_en = s_reg2hw.pad_gpioc0_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioc1
   always_comb begin
     unique case (s_reg2hw.pad_gpioc1_mux_sel.q)
       PAD_MUX_GROUP_PAD_GPIOC1_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioc1.chip2pad = s_reg2hw.pad_gpioc1_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc1.output_en = s_reg2hw.pad_gpioc1_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc1.pull_up_en = s_reg2hw.pad_gpioc1_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc1.rx_en = s_reg2hw.pad_gpioc1_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_PAD_GPIOC1_SEL_GPIO_C_GPIOC01: begin
          mux_to_pads_o.pad_gpioc1.chip2pad = port_signals_soc2pad_i.gpio_c.gpio1_i;
          mux_to_pads_o.pad_gpioc1.output_en = s_reg2hw.pad_gpioc1_cfg.output_en.q;
          mux_to_pads_o.pad_gpioc1.pull_up_en = s_reg2hw.pad_gpioc1_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioc1.rx_en = port_signals_soc2pad_i.gpio_c.dir1_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioc1.chip2pad = s_reg2hw.pad_gpioc1_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc1.output_en = s_reg2hw.pad_gpioc1_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc1.pull_up_en = s_reg2hw.pad_gpioc1_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc1.rx_en = s_reg2hw.pad_gpioc1_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioc2
   always_comb begin
     unique case (s_reg2hw.pad_gpioc2_mux_sel.q)
       PAD_MUX_GROUP_PAD_GPIOC2_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioc2.chip2pad = s_reg2hw.pad_gpioc2_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc2.output_en = s_reg2hw.pad_gpioc2_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc2.pull_up_en = s_reg2hw.pad_gpioc2_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc2.rx_en = s_reg2hw.pad_gpioc2_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_PAD_GPIOC2_SEL_GPIO_C_GPIOC02: begin
          mux_to_pads_o.pad_gpioc2.chip2pad = port_signals_soc2pad_i.gpio_c.gpio2_i;
          mux_to_pads_o.pad_gpioc2.output_en = s_reg2hw.pad_gpioc2_cfg.output_en.q;
          mux_to_pads_o.pad_gpioc2.pull_up_en = s_reg2hw.pad_gpioc2_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioc2.rx_en = port_signals_soc2pad_i.gpio_c.dir2_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioc2.chip2pad = s_reg2hw.pad_gpioc2_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc2.output_en = s_reg2hw.pad_gpioc2_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc2.pull_up_en = s_reg2hw.pad_gpioc2_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc2.rx_en = s_reg2hw.pad_gpioc2_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioc3
   always_comb begin
     unique case (s_reg2hw.pad_gpioc3_mux_sel.q)
       PAD_MUX_GROUP_PAD_GPIOC3_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioc3.chip2pad = s_reg2hw.pad_gpioc3_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc3.output_en = s_reg2hw.pad_gpioc3_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc3.pull_up_en = s_reg2hw.pad_gpioc3_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc3.rx_en = s_reg2hw.pad_gpioc3_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_PAD_GPIOC3_SEL_GPIO_C_GPIOC03: begin
          mux_to_pads_o.pad_gpioc3.chip2pad = port_signals_soc2pad_i.gpio_c.gpio3_i;
          mux_to_pads_o.pad_gpioc3.output_en = s_reg2hw.pad_gpioc3_cfg.output_en.q;
          mux_to_pads_o.pad_gpioc3.pull_up_en = s_reg2hw.pad_gpioc3_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioc3.rx_en = port_signals_soc2pad_i.gpio_c.dir3_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioc3.chip2pad = s_reg2hw.pad_gpioc3_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc3.output_en = s_reg2hw.pad_gpioc3_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc3.pull_up_en = s_reg2hw.pad_gpioc3_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc3.rx_en = s_reg2hw.pad_gpioc3_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioc4
   always_comb begin
     unique case (s_reg2hw.pad_gpioc4_mux_sel.q)
       PAD_MUX_GROUP_PAD_GPIOC4_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioc4.chip2pad = s_reg2hw.pad_gpioc4_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc4.output_en = s_reg2hw.pad_gpioc4_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc4.pull_up_en = s_reg2hw.pad_gpioc4_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc4.rx_en = s_reg2hw.pad_gpioc4_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_PAD_GPIOC4_SEL_GPIO_C_GPIOC04: begin
          mux_to_pads_o.pad_gpioc4.chip2pad = port_signals_soc2pad_i.gpio_c.gpio4_i;
          mux_to_pads_o.pad_gpioc4.output_en = s_reg2hw.pad_gpioc4_cfg.output_en.q;
          mux_to_pads_o.pad_gpioc4.pull_up_en = s_reg2hw.pad_gpioc4_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioc4.rx_en = port_signals_soc2pad_i.gpio_c.dir4_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioc4.chip2pad = s_reg2hw.pad_gpioc4_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc4.output_en = s_reg2hw.pad_gpioc4_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc4.pull_up_en = s_reg2hw.pad_gpioc4_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc4.rx_en = s_reg2hw.pad_gpioc4_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioc5
   always_comb begin
     unique case (s_reg2hw.pad_gpioc5_mux_sel.q)
       PAD_MUX_GROUP_PAD_GPIOC5_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioc5.chip2pad = s_reg2hw.pad_gpioc5_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc5.output_en = s_reg2hw.pad_gpioc5_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc5.pull_up_en = s_reg2hw.pad_gpioc5_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc5.rx_en = s_reg2hw.pad_gpioc5_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_PAD_GPIOC5_SEL_GPIO_C_GPIOC05: begin
          mux_to_pads_o.pad_gpioc5.chip2pad = port_signals_soc2pad_i.gpio_c.gpio5_i;
          mux_to_pads_o.pad_gpioc5.output_en = s_reg2hw.pad_gpioc5_cfg.output_en.q;
          mux_to_pads_o.pad_gpioc5.pull_up_en = s_reg2hw.pad_gpioc5_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioc5.rx_en = port_signals_soc2pad_i.gpio_c.dir5_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioc5.chip2pad = s_reg2hw.pad_gpioc5_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc5.output_en = s_reg2hw.pad_gpioc5_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc5.pull_up_en = s_reg2hw.pad_gpioc5_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc5.rx_en = s_reg2hw.pad_gpioc5_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioc6
   always_comb begin
     unique case (s_reg2hw.pad_gpioc6_mux_sel.q)
       PAD_MUX_GROUP_PAD_GPIOC6_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioc6.chip2pad = s_reg2hw.pad_gpioc6_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc6.output_en = s_reg2hw.pad_gpioc6_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc6.pull_up_en = s_reg2hw.pad_gpioc6_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc6.rx_en = s_reg2hw.pad_gpioc6_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_PAD_GPIOC6_SEL_GPIO_C_GPIOC06: begin
          mux_to_pads_o.pad_gpioc6.chip2pad = port_signals_soc2pad_i.gpio_c.gpio6_i;
          mux_to_pads_o.pad_gpioc6.output_en = s_reg2hw.pad_gpioc6_cfg.output_en.q;
          mux_to_pads_o.pad_gpioc6.pull_up_en = s_reg2hw.pad_gpioc6_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioc6.rx_en = port_signals_soc2pad_i.gpio_c.dir6_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioc6.chip2pad = s_reg2hw.pad_gpioc6_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc6.output_en = s_reg2hw.pad_gpioc6_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc6.pull_up_en = s_reg2hw.pad_gpioc6_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc6.rx_en = s_reg2hw.pad_gpioc6_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioc7
   always_comb begin
     unique case (s_reg2hw.pad_gpioc7_mux_sel.q)
       PAD_MUX_GROUP_PAD_GPIOC7_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioc7.chip2pad = s_reg2hw.pad_gpioc7_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc7.output_en = s_reg2hw.pad_gpioc7_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc7.pull_up_en = s_reg2hw.pad_gpioc7_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc7.rx_en = s_reg2hw.pad_gpioc7_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_PAD_GPIOC7_SEL_GPIO_C_GPIOC07: begin
          mux_to_pads_o.pad_gpioc7.chip2pad = port_signals_soc2pad_i.gpio_c.gpio7_i;
          mux_to_pads_o.pad_gpioc7.output_en = s_reg2hw.pad_gpioc7_cfg.output_en.q;
          mux_to_pads_o.pad_gpioc7.pull_up_en = s_reg2hw.pad_gpioc7_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioc7.rx_en = port_signals_soc2pad_i.gpio_c.dir7_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioc7.chip2pad = s_reg2hw.pad_gpioc7_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc7.output_en = s_reg2hw.pad_gpioc7_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc7.pull_up_en = s_reg2hw.pad_gpioc7_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc7.rx_en = s_reg2hw.pad_gpioc7_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioc8
   always_comb begin
     unique case (s_reg2hw.pad_gpioc8_mux_sel.q)
       PAD_MUX_GROUP_PAD_GPIOC8_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioc8.chip2pad = s_reg2hw.pad_gpioc8_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc8.output_en = s_reg2hw.pad_gpioc8_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc8.pull_up_en = s_reg2hw.pad_gpioc8_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc8.rx_en = s_reg2hw.pad_gpioc8_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_PAD_GPIOC8_SEL_GPIO_C_GPIOC08: begin
          mux_to_pads_o.pad_gpioc8.chip2pad = port_signals_soc2pad_i.gpio_c.gpio8_i;
          mux_to_pads_o.pad_gpioc8.output_en = s_reg2hw.pad_gpioc8_cfg.output_en.q;
          mux_to_pads_o.pad_gpioc8.pull_up_en = s_reg2hw.pad_gpioc8_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioc8.rx_en = port_signals_soc2pad_i.gpio_c.dir8_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioc8.chip2pad = s_reg2hw.pad_gpioc8_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc8.output_en = s_reg2hw.pad_gpioc8_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc8.pull_up_en = s_reg2hw.pad_gpioc8_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc8.rx_en = s_reg2hw.pad_gpioc8_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioc9
   always_comb begin
     unique case (s_reg2hw.pad_gpioc9_mux_sel.q)
       PAD_MUX_GROUP_PAD_GPIOC9_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioc9.chip2pad = s_reg2hw.pad_gpioc9_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc9.output_en = s_reg2hw.pad_gpioc9_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc9.pull_up_en = s_reg2hw.pad_gpioc9_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc9.rx_en = s_reg2hw.pad_gpioc9_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_PAD_GPIOC9_SEL_GPIO_C_GPIOC09: begin
          mux_to_pads_o.pad_gpioc9.chip2pad = port_signals_soc2pad_i.gpio_c.gpio9_i;
          mux_to_pads_o.pad_gpioc9.output_en = s_reg2hw.pad_gpioc9_cfg.output_en.q;
          mux_to_pads_o.pad_gpioc9.pull_up_en = s_reg2hw.pad_gpioc9_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioc9.rx_en = port_signals_soc2pad_i.gpio_c.dir9_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioc9.chip2pad = s_reg2hw.pad_gpioc9_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc9.output_en = s_reg2hw.pad_gpioc9_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc9.pull_up_en = s_reg2hw.pad_gpioc9_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc9.rx_en = s_reg2hw.pad_gpioc9_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioc10
   always_comb begin
     unique case (s_reg2hw.pad_gpioc10_mux_sel.q)
       PAD_MUX_GROUP_PAD_GPIOC10_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioc10.chip2pad = s_reg2hw.pad_gpioc10_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc10.output_en = s_reg2hw.pad_gpioc10_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc10.pull_up_en = s_reg2hw.pad_gpioc10_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc10.rx_en = s_reg2hw.pad_gpioc10_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_PAD_GPIOC10_SEL_GPIO_C_GPIOC10: begin
          mux_to_pads_o.pad_gpioc10.chip2pad = port_signals_soc2pad_i.gpio_c.gpio10_i;
          mux_to_pads_o.pad_gpioc10.output_en = s_reg2hw.pad_gpioc10_cfg.output_en.q;
          mux_to_pads_o.pad_gpioc10.pull_up_en = s_reg2hw.pad_gpioc10_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioc10.rx_en = port_signals_soc2pad_i.gpio_c.dir10_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioc10.chip2pad = s_reg2hw.pad_gpioc10_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc10.output_en = s_reg2hw.pad_gpioc10_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc10.pull_up_en = s_reg2hw.pad_gpioc10_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc10.rx_en = s_reg2hw.pad_gpioc10_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioc11
   always_comb begin
     unique case (s_reg2hw.pad_gpioc11_mux_sel.q)
       PAD_MUX_GROUP_PAD_GPIOC11_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioc11.chip2pad = s_reg2hw.pad_gpioc11_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc11.output_en = s_reg2hw.pad_gpioc11_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc11.pull_up_en = s_reg2hw.pad_gpioc11_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc11.rx_en = s_reg2hw.pad_gpioc11_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_PAD_GPIOC11_SEL_GPIO_C_GPIOC11: begin
          mux_to_pads_o.pad_gpioc11.chip2pad = port_signals_soc2pad_i.gpio_c.gpio11_i;
          mux_to_pads_o.pad_gpioc11.output_en = s_reg2hw.pad_gpioc11_cfg.output_en.q;
          mux_to_pads_o.pad_gpioc11.pull_up_en = s_reg2hw.pad_gpioc11_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioc11.rx_en = port_signals_soc2pad_i.gpio_c.dir11_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioc11.chip2pad = s_reg2hw.pad_gpioc11_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc11.output_en = s_reg2hw.pad_gpioc11_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc11.pull_up_en = s_reg2hw.pad_gpioc11_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc11.rx_en = s_reg2hw.pad_gpioc11_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioc12
   always_comb begin
     unique case (s_reg2hw.pad_gpioc12_mux_sel.q)
       PAD_MUX_GROUP_PAD_GPIOC12_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioc12.chip2pad = s_reg2hw.pad_gpioc12_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc12.output_en = s_reg2hw.pad_gpioc12_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc12.pull_up_en = s_reg2hw.pad_gpioc12_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc12.rx_en = s_reg2hw.pad_gpioc12_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_PAD_GPIOC12_SEL_GPIO_C_GPIOC12: begin
          mux_to_pads_o.pad_gpioc12.chip2pad = port_signals_soc2pad_i.gpio_c.gpio12_i;
          mux_to_pads_o.pad_gpioc12.output_en = s_reg2hw.pad_gpioc12_cfg.output_en.q;
          mux_to_pads_o.pad_gpioc12.pull_up_en = s_reg2hw.pad_gpioc12_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioc12.rx_en = port_signals_soc2pad_i.gpio_c.dir12_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioc12.chip2pad = s_reg2hw.pad_gpioc12_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc12.output_en = s_reg2hw.pad_gpioc12_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc12.pull_up_en = s_reg2hw.pad_gpioc12_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc12.rx_en = s_reg2hw.pad_gpioc12_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioc13
   always_comb begin
     unique case (s_reg2hw.pad_gpioc13_mux_sel.q)
       PAD_MUX_GROUP_PAD_GPIOC13_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioc13.chip2pad = s_reg2hw.pad_gpioc13_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc13.output_en = s_reg2hw.pad_gpioc13_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc13.pull_up_en = s_reg2hw.pad_gpioc13_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc13.rx_en = s_reg2hw.pad_gpioc13_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_PAD_GPIOC13_SEL_GPIO_C_GPIOC13: begin
          mux_to_pads_o.pad_gpioc13.chip2pad = port_signals_soc2pad_i.gpio_c.gpio13_i;
          mux_to_pads_o.pad_gpioc13.output_en = s_reg2hw.pad_gpioc13_cfg.output_en.q;
          mux_to_pads_o.pad_gpioc13.pull_up_en = s_reg2hw.pad_gpioc13_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioc13.rx_en = port_signals_soc2pad_i.gpio_c.dir13_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioc13.chip2pad = s_reg2hw.pad_gpioc13_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc13.output_en = s_reg2hw.pad_gpioc13_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc13.pull_up_en = s_reg2hw.pad_gpioc13_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc13.rx_en = s_reg2hw.pad_gpioc13_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioc14
   always_comb begin
     unique case (s_reg2hw.pad_gpioc14_mux_sel.q)
       PAD_MUX_GROUP_PAD_GPIOC14_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioc14.chip2pad = s_reg2hw.pad_gpioc14_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc14.output_en = s_reg2hw.pad_gpioc14_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc14.pull_up_en = s_reg2hw.pad_gpioc14_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc14.rx_en = s_reg2hw.pad_gpioc14_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_PAD_GPIOC14_SEL_GPIO_C_GPIOC14: begin
          mux_to_pads_o.pad_gpioc14.chip2pad = port_signals_soc2pad_i.gpio_c.gpio14_i;
          mux_to_pads_o.pad_gpioc14.output_en = s_reg2hw.pad_gpioc14_cfg.output_en.q;
          mux_to_pads_o.pad_gpioc14.pull_up_en = s_reg2hw.pad_gpioc14_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioc14.rx_en = port_signals_soc2pad_i.gpio_c.dir14_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioc14.chip2pad = s_reg2hw.pad_gpioc14_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc14.output_en = s_reg2hw.pad_gpioc14_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc14.pull_up_en = s_reg2hw.pad_gpioc14_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc14.rx_en = s_reg2hw.pad_gpioc14_cfg.rx_en.q;
       end
     endcase
   end // always_comb

   // Pad pad_gpioc15
   always_comb begin
     unique case (s_reg2hw.pad_gpioc15_mux_sel.q)
       PAD_MUX_GROUP_PAD_GPIOC15_SEL_DEFAULT: begin
         mux_to_pads_o.pad_gpioc15.chip2pad = s_reg2hw.pad_gpioc15_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc15.output_en = s_reg2hw.pad_gpioc15_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc15.pull_up_en = s_reg2hw.pad_gpioc15_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc15.rx_en = s_reg2hw.pad_gpioc15_cfg.rx_en.q;
       end
       PAD_MUX_GROUP_PAD_GPIOC15_SEL_GPIO_C_GPIOC15: begin
          mux_to_pads_o.pad_gpioc15.chip2pad = port_signals_soc2pad_i.gpio_c.gpio15_i;
          mux_to_pads_o.pad_gpioc15.output_en = s_reg2hw.pad_gpioc15_cfg.output_en.q;
          mux_to_pads_o.pad_gpioc15.pull_up_en = s_reg2hw.pad_gpioc15_cfg.pull_up_en.q;
          mux_to_pads_o.pad_gpioc15.rx_en = port_signals_soc2pad_i.gpio_c.dir15_i;
       end
       default: begin
         mux_to_pads_o.pad_gpioc15.chip2pad = s_reg2hw.pad_gpioc15_cfg.chip2pad.q;
         mux_to_pads_o.pad_gpioc15.output_en = s_reg2hw.pad_gpioc15_cfg.output_en.q;
         mux_to_pads_o.pad_gpioc15.pull_up_en = s_reg2hw.pad_gpioc15_cfg.pull_up_en.q;
         mux_to_pads_o.pad_gpioc15.rx_en = s_reg2hw.pad_gpioc15_cfg.rx_en.q;
       end
     endcase
   end // always_comb


  // Pad -> SoC Multiplex Logic
  // Port Group spi


  // Port Signal miso
  logic [31:0] port_mux_sel_spi_miso_req;
  logic [PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_WIDTH-1:0] port_mux_sel_spi_miso_arbitrated;
  logic port_mux_sel_spi_miso_no_connection;

   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA0] = s_reg2hw.pad_gpioa0_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA0_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA1] = s_reg2hw.pad_gpioa1_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA1_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA2] = s_reg2hw.pad_gpioa2_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA2_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA3] = s_reg2hw.pad_gpioa3_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA3_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA4] = s_reg2hw.pad_gpioa4_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA4_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA5] = s_reg2hw.pad_gpioa5_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA5_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA6] = s_reg2hw.pad_gpioa6_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA6_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA7] = s_reg2hw.pad_gpioa7_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA7_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA8] = s_reg2hw.pad_gpioa8_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA8_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA9] = s_reg2hw.pad_gpioa9_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA9_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA10] = s_reg2hw.pad_gpioa10_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA10_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA11] = s_reg2hw.pad_gpioa11_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA11_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA12] = s_reg2hw.pad_gpioa12_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA12_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA13] = s_reg2hw.pad_gpioa13_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA13_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA14] = s_reg2hw.pad_gpioa14_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA14_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA15] = s_reg2hw.pad_gpioa15_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA15_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA16] = s_reg2hw.pad_gpioa16_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA16_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA17] = s_reg2hw.pad_gpioa17_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA17_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA18] = s_reg2hw.pad_gpioa18_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA18_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA19] = s_reg2hw.pad_gpioa19_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA19_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA20] = s_reg2hw.pad_gpioa20_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA20_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA21] = s_reg2hw.pad_gpioa21_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA21_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA22] = s_reg2hw.pad_gpioa22_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA22_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA23] = s_reg2hw.pad_gpioa23_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA23_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA24] = s_reg2hw.pad_gpioa24_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA24_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA25] = s_reg2hw.pad_gpioa25_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA25_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA26] = s_reg2hw.pad_gpioa26_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA26_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA27] = s_reg2hw.pad_gpioa27_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA27_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA28] = s_reg2hw.pad_gpioa28_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA28_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA29] = s_reg2hw.pad_gpioa29_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA29_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA30] = s_reg2hw.pad_gpioa30_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA30_SEL_SPI_MISO ? 1'b1 : 1'b0;
   assign port_mux_sel_spi_miso_req[PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA31] = s_reg2hw.pad_gpioa31_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA31_SEL_SPI_MISO ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(32),
     .MODE(1'b0)
   ) i_port_muxsel_spi_miso_arbiter (
     .in_i(port_mux_sel_spi_miso_req),
     .cnt_o(port_mux_sel_spi_miso_arbitrated),
     .empty_o(port_mux_sel_spi_miso_no_connection)
   );

   always_comb begin
     if (port_mux_sel_spi_miso_no_connection) begin
        port_signals_pad2soc_o.spi.miso = 1'b0;
     end else begin
        unique case (port_mux_sel_spi_miso_arbitrated)
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA0: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa0.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA1: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa1.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA2: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa2.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA3: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa3.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA4: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa4.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA5: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa5.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA6: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa6.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA7: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa7.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA8: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa8.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA9: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa9.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA10: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa10.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA11: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa11.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA12: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa12.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA13: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa13.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA14: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa14.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA15: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa15.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA16: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa16.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA17: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa17.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA18: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa18.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA19: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa19.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA20: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa20.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA21: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa21.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA22: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa22.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA23: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa23.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA24: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa24.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA25: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa25.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA26: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa26.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA27: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa27.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA28: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa28.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA29: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa29.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA30: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa30.pad2chip;
          end
          PORT_MUX_GROUP_ALL_ALWAYS_ON_PADS_MISO_SEL_PAD_GPIOA31: begin
            port_signals_pad2soc_o.spi.miso = pads_to_mux_i.pad_gpioa31.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.spi.miso = 1'b0;
          end
       endcase
     end
   end



  // Port Group i2c

  // Port Signal sda_i
  logic [31:0] port_mux_sel_i2c_sda_i_req;
  logic [PORT_MUX_GROUP_GPIO_SETB_SEL_WIDTH-1:0] port_mux_sel_i2c_sda_i_arbitrated;
  logic port_mux_sel_i2c_sda_i_no_connection;

   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB0] = s_reg2hw.pad_gpiob0_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB1] = s_reg2hw.pad_gpiob1_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB2] = s_reg2hw.pad_gpiob2_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB3] = s_reg2hw.pad_gpiob3_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB4] = s_reg2hw.pad_gpiob4_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB5] = s_reg2hw.pad_gpiob5_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB6] = s_reg2hw.pad_gpiob6_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB7] = s_reg2hw.pad_gpiob7_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB8] = s_reg2hw.pad_gpiob8_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB9] = s_reg2hw.pad_gpiob9_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB10] = s_reg2hw.pad_gpiob10_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB11] = s_reg2hw.pad_gpiob11_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB12] = s_reg2hw.pad_gpiob12_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB13] = s_reg2hw.pad_gpiob13_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB14] = s_reg2hw.pad_gpiob14_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB15] = s_reg2hw.pad_gpiob15_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB16] = s_reg2hw.pad_gpiob16_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB17] = s_reg2hw.pad_gpiob17_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB18] = s_reg2hw.pad_gpiob18_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB19] = s_reg2hw.pad_gpiob19_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB20] = s_reg2hw.pad_gpiob20_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB21] = s_reg2hw.pad_gpiob21_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB22] = s_reg2hw.pad_gpiob22_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB23] = s_reg2hw.pad_gpiob23_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB24] = s_reg2hw.pad_gpiob24_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB25] = s_reg2hw.pad_gpiob25_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB26] = s_reg2hw.pad_gpiob26_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB27] = s_reg2hw.pad_gpiob27_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB28] = s_reg2hw.pad_gpiob28_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB29] = s_reg2hw.pad_gpiob29_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB30] = s_reg2hw.pad_gpiob30_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;
   assign port_mux_sel_i2c_sda_i_req[PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB31] = s_reg2hw.pad_gpiob31_mux_sel.q == PAD_MUX_GROUP_GPIO_SETB_SEL_I2C_SDA ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(32),
     .MODE(1'b0)
   ) i_port_muxsel_i2c_sda_i_arbiter (
     .in_i(port_mux_sel_i2c_sda_i_req),
     .cnt_o(port_mux_sel_i2c_sda_i_arbitrated),
     .empty_o(port_mux_sel_i2c_sda_i_no_connection)
   );

   always_comb begin
     if (port_mux_sel_i2c_sda_i_no_connection) begin
        port_signals_pad2soc_o.i2c.sda_i = 1'b0;
     end else begin
        unique case (port_mux_sel_i2c_sda_i_arbitrated)
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB0: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob0.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB1: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob1.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB2: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob2.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB3: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob3.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB4: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob4.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB5: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob5.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB6: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob6.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB7: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob7.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB8: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob8.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB9: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob9.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB10: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob10.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB11: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob11.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB12: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob12.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB13: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob13.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB14: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob14.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB15: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob15.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB16: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob16.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB17: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob17.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB18: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob18.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB19: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob19.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB20: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob20.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB21: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob21.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB22: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob22.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB23: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob23.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB24: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob24.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB25: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob25.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB26: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob26.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB27: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob27.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB28: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob28.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB29: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob29.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB30: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob30.pad2chip;
          end
          PORT_MUX_GROUP_GPIO_SETB_SEL_PAD_GPIOB31: begin
            port_signals_pad2soc_o.i2c.sda_i = pads_to_mux_i.pad_gpiob31.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.i2c.sda_i = 1'b0;
          end
       endcase
     end
   end


  // Port Group gpio_a

  // Port Signal gpio0_o
  logic [0:0] port_mux_sel_gpio_a_gpio0_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA0_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio0_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio0_o_no_connection;

   assign port_mux_sel_gpio_a_gpio0_o_req[PORT_MUX_GROUP_PAD_GPIOA0_SEL_PAD_GPIOA0] = s_reg2hw.pad_gpioa0_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA0_SEL_GPIO_A_GPIO00 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio0_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio0_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio0_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio0_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio0_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio0_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio0_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA0_SEL_PAD_GPIOA0: begin
            port_signals_pad2soc_o.gpio_a.gpio0_o = pads_to_mux_i.pad_gpioa0.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio0_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio1_o
  logic [0:0] port_mux_sel_gpio_a_gpio1_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA1_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio1_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio1_o_no_connection;

   assign port_mux_sel_gpio_a_gpio1_o_req[PORT_MUX_GROUP_PAD_GPIOA1_SEL_PAD_GPIOA1] = s_reg2hw.pad_gpioa1_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA1_SEL_GPIO_A_GPIO01 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio1_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio1_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio1_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio1_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio1_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio1_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio1_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA1_SEL_PAD_GPIOA1: begin
            port_signals_pad2soc_o.gpio_a.gpio1_o = pads_to_mux_i.pad_gpioa1.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio1_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio2_o
  logic [0:0] port_mux_sel_gpio_a_gpio2_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA2_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio2_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio2_o_no_connection;

   assign port_mux_sel_gpio_a_gpio2_o_req[PORT_MUX_GROUP_PAD_GPIOA2_SEL_PAD_GPIOA2] = s_reg2hw.pad_gpioa2_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA2_SEL_GPIO_A_GPIO02 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio2_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio2_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio2_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio2_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio2_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio2_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio2_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA2_SEL_PAD_GPIOA2: begin
            port_signals_pad2soc_o.gpio_a.gpio2_o = pads_to_mux_i.pad_gpioa2.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio2_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio3_o
  logic [0:0] port_mux_sel_gpio_a_gpio3_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA3_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio3_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio3_o_no_connection;

   assign port_mux_sel_gpio_a_gpio3_o_req[PORT_MUX_GROUP_PAD_GPIOA3_SEL_PAD_GPIOA3] = s_reg2hw.pad_gpioa3_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA3_SEL_GPIO_A_GPIO03 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio3_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio3_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio3_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio3_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio3_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio3_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio3_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA3_SEL_PAD_GPIOA3: begin
            port_signals_pad2soc_o.gpio_a.gpio3_o = pads_to_mux_i.pad_gpioa3.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio3_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio4_o
  logic [0:0] port_mux_sel_gpio_a_gpio4_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA4_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio4_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio4_o_no_connection;

   assign port_mux_sel_gpio_a_gpio4_o_req[PORT_MUX_GROUP_PAD_GPIOA4_SEL_PAD_GPIOA4] = s_reg2hw.pad_gpioa4_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA4_SEL_GPIO_A_GPIO04 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio4_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio4_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio4_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio4_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio4_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio4_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio4_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA4_SEL_PAD_GPIOA4: begin
            port_signals_pad2soc_o.gpio_a.gpio4_o = pads_to_mux_i.pad_gpioa4.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio4_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio5_o
  logic [0:0] port_mux_sel_gpio_a_gpio5_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA5_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio5_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio5_o_no_connection;

   assign port_mux_sel_gpio_a_gpio5_o_req[PORT_MUX_GROUP_PAD_GPIOA5_SEL_PAD_GPIOA5] = s_reg2hw.pad_gpioa5_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA5_SEL_GPIO_A_GPIO05 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio5_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio5_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio5_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio5_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio5_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio5_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio5_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA5_SEL_PAD_GPIOA5: begin
            port_signals_pad2soc_o.gpio_a.gpio5_o = pads_to_mux_i.pad_gpioa5.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio5_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio6_o
  logic [0:0] port_mux_sel_gpio_a_gpio6_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA6_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio6_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio6_o_no_connection;

   assign port_mux_sel_gpio_a_gpio6_o_req[PORT_MUX_GROUP_PAD_GPIOA6_SEL_PAD_GPIOA6] = s_reg2hw.pad_gpioa6_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA6_SEL_GPIO_A_GPIO06 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio6_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio6_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio6_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio6_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio6_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio6_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio6_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA6_SEL_PAD_GPIOA6: begin
            port_signals_pad2soc_o.gpio_a.gpio6_o = pads_to_mux_i.pad_gpioa6.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio6_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio7_o
  logic [0:0] port_mux_sel_gpio_a_gpio7_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA7_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio7_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio7_o_no_connection;

   assign port_mux_sel_gpio_a_gpio7_o_req[PORT_MUX_GROUP_PAD_GPIOA7_SEL_PAD_GPIOA7] = s_reg2hw.pad_gpioa7_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA7_SEL_GPIO_A_GPIO07 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio7_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio7_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio7_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio7_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio7_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio7_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio7_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA7_SEL_PAD_GPIOA7: begin
            port_signals_pad2soc_o.gpio_a.gpio7_o = pads_to_mux_i.pad_gpioa7.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio7_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio8_o
  logic [0:0] port_mux_sel_gpio_a_gpio8_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA8_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio8_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio8_o_no_connection;

   assign port_mux_sel_gpio_a_gpio8_o_req[PORT_MUX_GROUP_PAD_GPIOA8_SEL_PAD_GPIOA8] = s_reg2hw.pad_gpioa8_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA8_SEL_GPIO_A_GPIO08 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio8_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio8_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio8_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio8_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio8_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio8_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio8_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA8_SEL_PAD_GPIOA8: begin
            port_signals_pad2soc_o.gpio_a.gpio8_o = pads_to_mux_i.pad_gpioa8.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio8_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio9_o
  logic [0:0] port_mux_sel_gpio_a_gpio9_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA9_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio9_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio9_o_no_connection;

   assign port_mux_sel_gpio_a_gpio9_o_req[PORT_MUX_GROUP_PAD_GPIOA9_SEL_PAD_GPIOA9] = s_reg2hw.pad_gpioa9_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA9_SEL_GPIO_A_GPIO09 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio9_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio9_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio9_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio9_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio9_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio9_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio9_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA9_SEL_PAD_GPIOA9: begin
            port_signals_pad2soc_o.gpio_a.gpio9_o = pads_to_mux_i.pad_gpioa9.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio9_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio10_o
  logic [0:0] port_mux_sel_gpio_a_gpio10_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA10_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio10_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio10_o_no_connection;

   assign port_mux_sel_gpio_a_gpio10_o_req[PORT_MUX_GROUP_PAD_GPIOA10_SEL_PAD_GPIOA10] = s_reg2hw.pad_gpioa10_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA10_SEL_GPIO_A_GPIO10 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio10_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio10_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio10_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio10_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio10_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio10_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio10_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA10_SEL_PAD_GPIOA10: begin
            port_signals_pad2soc_o.gpio_a.gpio10_o = pads_to_mux_i.pad_gpioa10.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio10_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio11_o
  logic [0:0] port_mux_sel_gpio_a_gpio11_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA11_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio11_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio11_o_no_connection;

   assign port_mux_sel_gpio_a_gpio11_o_req[PORT_MUX_GROUP_PAD_GPIOA11_SEL_PAD_GPIOA11] = s_reg2hw.pad_gpioa11_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA11_SEL_GPIO_A_GPIO11 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio11_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio11_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio11_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio11_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio11_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio11_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio11_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA11_SEL_PAD_GPIOA11: begin
            port_signals_pad2soc_o.gpio_a.gpio11_o = pads_to_mux_i.pad_gpioa11.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio11_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio12_o
  logic [0:0] port_mux_sel_gpio_a_gpio12_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA12_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio12_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio12_o_no_connection;

   assign port_mux_sel_gpio_a_gpio12_o_req[PORT_MUX_GROUP_PAD_GPIOA12_SEL_PAD_GPIOA12] = s_reg2hw.pad_gpioa12_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA12_SEL_GPIO_A_GPIO12 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio12_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio12_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio12_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio12_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio12_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio12_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio12_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA12_SEL_PAD_GPIOA12: begin
            port_signals_pad2soc_o.gpio_a.gpio12_o = pads_to_mux_i.pad_gpioa12.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio12_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio13_o
  logic [0:0] port_mux_sel_gpio_a_gpio13_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA13_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio13_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio13_o_no_connection;

   assign port_mux_sel_gpio_a_gpio13_o_req[PORT_MUX_GROUP_PAD_GPIOA13_SEL_PAD_GPIOA13] = s_reg2hw.pad_gpioa13_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA13_SEL_GPIO_A_GPIO13 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio13_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio13_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio13_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio13_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio13_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio13_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio13_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA13_SEL_PAD_GPIOA13: begin
            port_signals_pad2soc_o.gpio_a.gpio13_o = pads_to_mux_i.pad_gpioa13.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio13_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio14_o
  logic [0:0] port_mux_sel_gpio_a_gpio14_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA14_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio14_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio14_o_no_connection;

   assign port_mux_sel_gpio_a_gpio14_o_req[PORT_MUX_GROUP_PAD_GPIOA14_SEL_PAD_GPIOA14] = s_reg2hw.pad_gpioa14_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA14_SEL_GPIO_A_GPIO14 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio14_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio14_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio14_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio14_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio14_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio14_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio14_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA14_SEL_PAD_GPIOA14: begin
            port_signals_pad2soc_o.gpio_a.gpio14_o = pads_to_mux_i.pad_gpioa14.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio14_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio15_o
  logic [0:0] port_mux_sel_gpio_a_gpio15_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA15_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio15_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio15_o_no_connection;

   assign port_mux_sel_gpio_a_gpio15_o_req[PORT_MUX_GROUP_PAD_GPIOA15_SEL_PAD_GPIOA15] = s_reg2hw.pad_gpioa15_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA15_SEL_GPIO_A_GPIO15 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio15_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio15_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio15_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio15_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio15_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio15_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio15_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA15_SEL_PAD_GPIOA15: begin
            port_signals_pad2soc_o.gpio_a.gpio15_o = pads_to_mux_i.pad_gpioa15.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio15_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio16_o
  logic [0:0] port_mux_sel_gpio_a_gpio16_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA16_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio16_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio16_o_no_connection;

   assign port_mux_sel_gpio_a_gpio16_o_req[PORT_MUX_GROUP_PAD_GPIOA16_SEL_PAD_GPIOA16] = s_reg2hw.pad_gpioa16_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA16_SEL_GPIO_A_GPIO16 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio16_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio16_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio16_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio16_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio16_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio16_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio16_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA16_SEL_PAD_GPIOA16: begin
            port_signals_pad2soc_o.gpio_a.gpio16_o = pads_to_mux_i.pad_gpioa16.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio16_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio17_o
  logic [0:0] port_mux_sel_gpio_a_gpio17_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA17_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio17_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio17_o_no_connection;

   assign port_mux_sel_gpio_a_gpio17_o_req[PORT_MUX_GROUP_PAD_GPIOA17_SEL_PAD_GPIOA17] = s_reg2hw.pad_gpioa17_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA17_SEL_GPIO_A_GPIO17 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio17_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio17_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio17_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio17_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio17_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio17_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio17_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA17_SEL_PAD_GPIOA17: begin
            port_signals_pad2soc_o.gpio_a.gpio17_o = pads_to_mux_i.pad_gpioa17.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio17_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio18_o
  logic [0:0] port_mux_sel_gpio_a_gpio18_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA18_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio18_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio18_o_no_connection;

   assign port_mux_sel_gpio_a_gpio18_o_req[PORT_MUX_GROUP_PAD_GPIOA18_SEL_PAD_GPIOA18] = s_reg2hw.pad_gpioa18_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA18_SEL_GPIO_A_GPIO18 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio18_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio18_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio18_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio18_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio18_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio18_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio18_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA18_SEL_PAD_GPIOA18: begin
            port_signals_pad2soc_o.gpio_a.gpio18_o = pads_to_mux_i.pad_gpioa18.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio18_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio19_o
  logic [0:0] port_mux_sel_gpio_a_gpio19_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA19_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio19_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio19_o_no_connection;

   assign port_mux_sel_gpio_a_gpio19_o_req[PORT_MUX_GROUP_PAD_GPIOA19_SEL_PAD_GPIOA19] = s_reg2hw.pad_gpioa19_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA19_SEL_GPIO_A_GPIO19 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio19_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio19_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio19_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio19_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio19_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio19_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio19_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA19_SEL_PAD_GPIOA19: begin
            port_signals_pad2soc_o.gpio_a.gpio19_o = pads_to_mux_i.pad_gpioa19.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio19_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio20_o
  logic [0:0] port_mux_sel_gpio_a_gpio20_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA20_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio20_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio20_o_no_connection;

   assign port_mux_sel_gpio_a_gpio20_o_req[PORT_MUX_GROUP_PAD_GPIOA20_SEL_PAD_GPIOA20] = s_reg2hw.pad_gpioa20_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA20_SEL_GPIO_A_GPIO20 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio20_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio20_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio20_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio20_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio20_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio20_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio20_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA20_SEL_PAD_GPIOA20: begin
            port_signals_pad2soc_o.gpio_a.gpio20_o = pads_to_mux_i.pad_gpioa20.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio20_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio21_o
  logic [0:0] port_mux_sel_gpio_a_gpio21_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA21_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio21_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio21_o_no_connection;

   assign port_mux_sel_gpio_a_gpio21_o_req[PORT_MUX_GROUP_PAD_GPIOA21_SEL_PAD_GPIOA21] = s_reg2hw.pad_gpioa21_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA21_SEL_GPIO_A_GPIO21 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio21_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio21_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio21_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio21_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio21_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio21_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio21_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA21_SEL_PAD_GPIOA21: begin
            port_signals_pad2soc_o.gpio_a.gpio21_o = pads_to_mux_i.pad_gpioa21.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio21_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio22_o
  logic [0:0] port_mux_sel_gpio_a_gpio22_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA22_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio22_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio22_o_no_connection;

   assign port_mux_sel_gpio_a_gpio22_o_req[PORT_MUX_GROUP_PAD_GPIOA22_SEL_PAD_GPIOA22] = s_reg2hw.pad_gpioa22_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA22_SEL_GPIO_A_GPIO22 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio22_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio22_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio22_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio22_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio22_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio22_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio22_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA22_SEL_PAD_GPIOA22: begin
            port_signals_pad2soc_o.gpio_a.gpio22_o = pads_to_mux_i.pad_gpioa22.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio22_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio23_o
  logic [0:0] port_mux_sel_gpio_a_gpio23_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA23_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio23_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio23_o_no_connection;

   assign port_mux_sel_gpio_a_gpio23_o_req[PORT_MUX_GROUP_PAD_GPIOA23_SEL_PAD_GPIOA23] = s_reg2hw.pad_gpioa23_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA23_SEL_GPIO_A_GPIO23 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio23_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio23_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio23_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio23_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio23_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio23_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio23_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA23_SEL_PAD_GPIOA23: begin
            port_signals_pad2soc_o.gpio_a.gpio23_o = pads_to_mux_i.pad_gpioa23.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio23_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio24_o
  logic [0:0] port_mux_sel_gpio_a_gpio24_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA24_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio24_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio24_o_no_connection;

   assign port_mux_sel_gpio_a_gpio24_o_req[PORT_MUX_GROUP_PAD_GPIOA24_SEL_PAD_GPIOA24] = s_reg2hw.pad_gpioa24_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA24_SEL_GPIO_A_GPIO24 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio24_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio24_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio24_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio24_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio24_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio24_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio24_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA24_SEL_PAD_GPIOA24: begin
            port_signals_pad2soc_o.gpio_a.gpio24_o = pads_to_mux_i.pad_gpioa24.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio24_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio25_o
  logic [0:0] port_mux_sel_gpio_a_gpio25_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA25_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio25_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio25_o_no_connection;

   assign port_mux_sel_gpio_a_gpio25_o_req[PORT_MUX_GROUP_PAD_GPIOA25_SEL_PAD_GPIOA25] = s_reg2hw.pad_gpioa25_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA25_SEL_GPIO_A_GPIO25 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio25_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio25_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio25_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio25_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio25_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio25_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio25_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA25_SEL_PAD_GPIOA25: begin
            port_signals_pad2soc_o.gpio_a.gpio25_o = pads_to_mux_i.pad_gpioa25.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio25_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio26_o
  logic [0:0] port_mux_sel_gpio_a_gpio26_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA26_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio26_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio26_o_no_connection;

   assign port_mux_sel_gpio_a_gpio26_o_req[PORT_MUX_GROUP_PAD_GPIOA26_SEL_PAD_GPIOA26] = s_reg2hw.pad_gpioa26_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA26_SEL_GPIO_A_GPIO26 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio26_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio26_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio26_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio26_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio26_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio26_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio26_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA26_SEL_PAD_GPIOA26: begin
            port_signals_pad2soc_o.gpio_a.gpio26_o = pads_to_mux_i.pad_gpioa26.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio26_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio27_o
  logic [0:0] port_mux_sel_gpio_a_gpio27_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA27_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio27_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio27_o_no_connection;

   assign port_mux_sel_gpio_a_gpio27_o_req[PORT_MUX_GROUP_PAD_GPIOA27_SEL_PAD_GPIOA27] = s_reg2hw.pad_gpioa27_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA27_SEL_GPIO_A_GPIO27 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio27_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio27_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio27_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio27_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio27_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio27_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio27_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA27_SEL_PAD_GPIOA27: begin
            port_signals_pad2soc_o.gpio_a.gpio27_o = pads_to_mux_i.pad_gpioa27.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio27_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio28_o
  logic [0:0] port_mux_sel_gpio_a_gpio28_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA28_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio28_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio28_o_no_connection;

   assign port_mux_sel_gpio_a_gpio28_o_req[PORT_MUX_GROUP_PAD_GPIOA28_SEL_PAD_GPIOA28] = s_reg2hw.pad_gpioa28_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA28_SEL_GPIO_A_GPIO28 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio28_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio28_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio28_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio28_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio28_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio28_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio28_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA28_SEL_PAD_GPIOA28: begin
            port_signals_pad2soc_o.gpio_a.gpio28_o = pads_to_mux_i.pad_gpioa28.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio28_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio29_o
  logic [0:0] port_mux_sel_gpio_a_gpio29_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA29_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio29_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio29_o_no_connection;

   assign port_mux_sel_gpio_a_gpio29_o_req[PORT_MUX_GROUP_PAD_GPIOA29_SEL_PAD_GPIOA29] = s_reg2hw.pad_gpioa29_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA29_SEL_GPIO_A_GPIO29 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio29_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio29_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio29_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio29_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio29_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio29_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio29_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA29_SEL_PAD_GPIOA29: begin
            port_signals_pad2soc_o.gpio_a.gpio29_o = pads_to_mux_i.pad_gpioa29.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio29_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio30_o
  logic [0:0] port_mux_sel_gpio_a_gpio30_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA30_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio30_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio30_o_no_connection;

   assign port_mux_sel_gpio_a_gpio30_o_req[PORT_MUX_GROUP_PAD_GPIOA30_SEL_PAD_GPIOA30] = s_reg2hw.pad_gpioa30_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA30_SEL_GPIO_A_GPIO30 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio30_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio30_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio30_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio30_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio30_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio30_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio30_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA30_SEL_PAD_GPIOA30: begin
            port_signals_pad2soc_o.gpio_a.gpio30_o = pads_to_mux_i.pad_gpioa30.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio30_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio31_o
  logic [0:0] port_mux_sel_gpio_a_gpio31_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOA31_SEL_WIDTH-1:0] port_mux_sel_gpio_a_gpio31_o_arbitrated;
  logic port_mux_sel_gpio_a_gpio31_o_no_connection;

   assign port_mux_sel_gpio_a_gpio31_o_req[PORT_MUX_GROUP_PAD_GPIOA31_SEL_PAD_GPIOA31] = s_reg2hw.pad_gpioa31_mux_sel.q == PAD_MUX_GROUP_ALL_PAD_GPIOA31_SEL_GPIO_A_GPIO31 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_a_gpio31_o_arbiter (
     .in_i(port_mux_sel_gpio_a_gpio31_o_req),
     .cnt_o(port_mux_sel_gpio_a_gpio31_o_arbitrated),
     .empty_o(port_mux_sel_gpio_a_gpio31_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_a_gpio31_o_no_connection) begin
        port_signals_pad2soc_o.gpio_a.gpio31_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_a_gpio31_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOA31_SEL_PAD_GPIOA31: begin
            port_signals_pad2soc_o.gpio_a.gpio31_o = pads_to_mux_i.pad_gpioa31.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_a.gpio31_o = '0;
          end
       endcase
     end
   end

  // Port Group gpio_c

  // Port Signal gpio0_o
  logic [0:0] port_mux_sel_gpio_c_gpio0_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOC0_SEL_WIDTH-1:0] port_mux_sel_gpio_c_gpio0_o_arbitrated;
  logic port_mux_sel_gpio_c_gpio0_o_no_connection;

   assign port_mux_sel_gpio_c_gpio0_o_req[PORT_MUX_GROUP_PAD_GPIOC0_SEL_PAD_GPIOC0] = s_reg2hw.pad_gpioc0_mux_sel.q == PAD_MUX_GROUP_PAD_GPIOC0_SEL_GPIO_C_GPIOC00 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_c_gpio0_o_arbiter (
     .in_i(port_mux_sel_gpio_c_gpio0_o_req),
     .cnt_o(port_mux_sel_gpio_c_gpio0_o_arbitrated),
     .empty_o(port_mux_sel_gpio_c_gpio0_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_c_gpio0_o_no_connection) begin
        port_signals_pad2soc_o.gpio_c.gpio0_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_c_gpio0_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOC0_SEL_PAD_GPIOC0: begin
            port_signals_pad2soc_o.gpio_c.gpio0_o = pads_to_mux_i.pad_gpioc0.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_c.gpio0_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio1_o
  logic [0:0] port_mux_sel_gpio_c_gpio1_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOC1_SEL_WIDTH-1:0] port_mux_sel_gpio_c_gpio1_o_arbitrated;
  logic port_mux_sel_gpio_c_gpio1_o_no_connection;

   assign port_mux_sel_gpio_c_gpio1_o_req[PORT_MUX_GROUP_PAD_GPIOC1_SEL_PAD_GPIOC1] = s_reg2hw.pad_gpioc1_mux_sel.q == PAD_MUX_GROUP_PAD_GPIOC1_SEL_GPIO_C_GPIOC01 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_c_gpio1_o_arbiter (
     .in_i(port_mux_sel_gpio_c_gpio1_o_req),
     .cnt_o(port_mux_sel_gpio_c_gpio1_o_arbitrated),
     .empty_o(port_mux_sel_gpio_c_gpio1_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_c_gpio1_o_no_connection) begin
        port_signals_pad2soc_o.gpio_c.gpio1_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_c_gpio1_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOC1_SEL_PAD_GPIOC1: begin
            port_signals_pad2soc_o.gpio_c.gpio1_o = pads_to_mux_i.pad_gpioc1.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_c.gpio1_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio2_o
  logic [0:0] port_mux_sel_gpio_c_gpio2_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOC2_SEL_WIDTH-1:0] port_mux_sel_gpio_c_gpio2_o_arbitrated;
  logic port_mux_sel_gpio_c_gpio2_o_no_connection;

   assign port_mux_sel_gpio_c_gpio2_o_req[PORT_MUX_GROUP_PAD_GPIOC2_SEL_PAD_GPIOC2] = s_reg2hw.pad_gpioc2_mux_sel.q == PAD_MUX_GROUP_PAD_GPIOC2_SEL_GPIO_C_GPIOC02 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_c_gpio2_o_arbiter (
     .in_i(port_mux_sel_gpio_c_gpio2_o_req),
     .cnt_o(port_mux_sel_gpio_c_gpio2_o_arbitrated),
     .empty_o(port_mux_sel_gpio_c_gpio2_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_c_gpio2_o_no_connection) begin
        port_signals_pad2soc_o.gpio_c.gpio2_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_c_gpio2_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOC2_SEL_PAD_GPIOC2: begin
            port_signals_pad2soc_o.gpio_c.gpio2_o = pads_to_mux_i.pad_gpioc2.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_c.gpio2_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio3_o
  logic [0:0] port_mux_sel_gpio_c_gpio3_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOC3_SEL_WIDTH-1:0] port_mux_sel_gpio_c_gpio3_o_arbitrated;
  logic port_mux_sel_gpio_c_gpio3_o_no_connection;

   assign port_mux_sel_gpio_c_gpio3_o_req[PORT_MUX_GROUP_PAD_GPIOC3_SEL_PAD_GPIOC3] = s_reg2hw.pad_gpioc3_mux_sel.q == PAD_MUX_GROUP_PAD_GPIOC3_SEL_GPIO_C_GPIOC03 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_c_gpio3_o_arbiter (
     .in_i(port_mux_sel_gpio_c_gpio3_o_req),
     .cnt_o(port_mux_sel_gpio_c_gpio3_o_arbitrated),
     .empty_o(port_mux_sel_gpio_c_gpio3_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_c_gpio3_o_no_connection) begin
        port_signals_pad2soc_o.gpio_c.gpio3_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_c_gpio3_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOC3_SEL_PAD_GPIOC3: begin
            port_signals_pad2soc_o.gpio_c.gpio3_o = pads_to_mux_i.pad_gpioc3.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_c.gpio3_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio4_o
  logic [0:0] port_mux_sel_gpio_c_gpio4_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOC4_SEL_WIDTH-1:0] port_mux_sel_gpio_c_gpio4_o_arbitrated;
  logic port_mux_sel_gpio_c_gpio4_o_no_connection;

   assign port_mux_sel_gpio_c_gpio4_o_req[PORT_MUX_GROUP_PAD_GPIOC4_SEL_PAD_GPIOC4] = s_reg2hw.pad_gpioc4_mux_sel.q == PAD_MUX_GROUP_PAD_GPIOC4_SEL_GPIO_C_GPIOC04 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_c_gpio4_o_arbiter (
     .in_i(port_mux_sel_gpio_c_gpio4_o_req),
     .cnt_o(port_mux_sel_gpio_c_gpio4_o_arbitrated),
     .empty_o(port_mux_sel_gpio_c_gpio4_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_c_gpio4_o_no_connection) begin
        port_signals_pad2soc_o.gpio_c.gpio4_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_c_gpio4_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOC4_SEL_PAD_GPIOC4: begin
            port_signals_pad2soc_o.gpio_c.gpio4_o = pads_to_mux_i.pad_gpioc4.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_c.gpio4_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio5_o
  logic [0:0] port_mux_sel_gpio_c_gpio5_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOC5_SEL_WIDTH-1:0] port_mux_sel_gpio_c_gpio5_o_arbitrated;
  logic port_mux_sel_gpio_c_gpio5_o_no_connection;

   assign port_mux_sel_gpio_c_gpio5_o_req[PORT_MUX_GROUP_PAD_GPIOC5_SEL_PAD_GPIOC5] = s_reg2hw.pad_gpioc5_mux_sel.q == PAD_MUX_GROUP_PAD_GPIOC5_SEL_GPIO_C_GPIOC05 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_c_gpio5_o_arbiter (
     .in_i(port_mux_sel_gpio_c_gpio5_o_req),
     .cnt_o(port_mux_sel_gpio_c_gpio5_o_arbitrated),
     .empty_o(port_mux_sel_gpio_c_gpio5_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_c_gpio5_o_no_connection) begin
        port_signals_pad2soc_o.gpio_c.gpio5_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_c_gpio5_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOC5_SEL_PAD_GPIOC5: begin
            port_signals_pad2soc_o.gpio_c.gpio5_o = pads_to_mux_i.pad_gpioc5.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_c.gpio5_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio6_o
  logic [0:0] port_mux_sel_gpio_c_gpio6_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOC6_SEL_WIDTH-1:0] port_mux_sel_gpio_c_gpio6_o_arbitrated;
  logic port_mux_sel_gpio_c_gpio6_o_no_connection;

   assign port_mux_sel_gpio_c_gpio6_o_req[PORT_MUX_GROUP_PAD_GPIOC6_SEL_PAD_GPIOC6] = s_reg2hw.pad_gpioc6_mux_sel.q == PAD_MUX_GROUP_PAD_GPIOC6_SEL_GPIO_C_GPIOC06 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_c_gpio6_o_arbiter (
     .in_i(port_mux_sel_gpio_c_gpio6_o_req),
     .cnt_o(port_mux_sel_gpio_c_gpio6_o_arbitrated),
     .empty_o(port_mux_sel_gpio_c_gpio6_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_c_gpio6_o_no_connection) begin
        port_signals_pad2soc_o.gpio_c.gpio6_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_c_gpio6_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOC6_SEL_PAD_GPIOC6: begin
            port_signals_pad2soc_o.gpio_c.gpio6_o = pads_to_mux_i.pad_gpioc6.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_c.gpio6_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio7_o
  logic [0:0] port_mux_sel_gpio_c_gpio7_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOC7_SEL_WIDTH-1:0] port_mux_sel_gpio_c_gpio7_o_arbitrated;
  logic port_mux_sel_gpio_c_gpio7_o_no_connection;

   assign port_mux_sel_gpio_c_gpio7_o_req[PORT_MUX_GROUP_PAD_GPIOC7_SEL_PAD_GPIOC7] = s_reg2hw.pad_gpioc7_mux_sel.q == PAD_MUX_GROUP_PAD_GPIOC7_SEL_GPIO_C_GPIOC07 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_c_gpio7_o_arbiter (
     .in_i(port_mux_sel_gpio_c_gpio7_o_req),
     .cnt_o(port_mux_sel_gpio_c_gpio7_o_arbitrated),
     .empty_o(port_mux_sel_gpio_c_gpio7_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_c_gpio7_o_no_connection) begin
        port_signals_pad2soc_o.gpio_c.gpio7_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_c_gpio7_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOC7_SEL_PAD_GPIOC7: begin
            port_signals_pad2soc_o.gpio_c.gpio7_o = pads_to_mux_i.pad_gpioc7.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_c.gpio7_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio8_o
  logic [0:0] port_mux_sel_gpio_c_gpio8_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOC8_SEL_WIDTH-1:0] port_mux_sel_gpio_c_gpio8_o_arbitrated;
  logic port_mux_sel_gpio_c_gpio8_o_no_connection;

   assign port_mux_sel_gpio_c_gpio8_o_req[PORT_MUX_GROUP_PAD_GPIOC8_SEL_PAD_GPIOC8] = s_reg2hw.pad_gpioc8_mux_sel.q == PAD_MUX_GROUP_PAD_GPIOC8_SEL_GPIO_C_GPIOC08 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_c_gpio8_o_arbiter (
     .in_i(port_mux_sel_gpio_c_gpio8_o_req),
     .cnt_o(port_mux_sel_gpio_c_gpio8_o_arbitrated),
     .empty_o(port_mux_sel_gpio_c_gpio8_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_c_gpio8_o_no_connection) begin
        port_signals_pad2soc_o.gpio_c.gpio8_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_c_gpio8_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOC8_SEL_PAD_GPIOC8: begin
            port_signals_pad2soc_o.gpio_c.gpio8_o = pads_to_mux_i.pad_gpioc8.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_c.gpio8_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio9_o
  logic [0:0] port_mux_sel_gpio_c_gpio9_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOC9_SEL_WIDTH-1:0] port_mux_sel_gpio_c_gpio9_o_arbitrated;
  logic port_mux_sel_gpio_c_gpio9_o_no_connection;

   assign port_mux_sel_gpio_c_gpio9_o_req[PORT_MUX_GROUP_PAD_GPIOC9_SEL_PAD_GPIOC9] = s_reg2hw.pad_gpioc9_mux_sel.q == PAD_MUX_GROUP_PAD_GPIOC9_SEL_GPIO_C_GPIOC09 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_c_gpio9_o_arbiter (
     .in_i(port_mux_sel_gpio_c_gpio9_o_req),
     .cnt_o(port_mux_sel_gpio_c_gpio9_o_arbitrated),
     .empty_o(port_mux_sel_gpio_c_gpio9_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_c_gpio9_o_no_connection) begin
        port_signals_pad2soc_o.gpio_c.gpio9_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_c_gpio9_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOC9_SEL_PAD_GPIOC9: begin
            port_signals_pad2soc_o.gpio_c.gpio9_o = pads_to_mux_i.pad_gpioc9.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_c.gpio9_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio10_o
  logic [0:0] port_mux_sel_gpio_c_gpio10_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOC10_SEL_WIDTH-1:0] port_mux_sel_gpio_c_gpio10_o_arbitrated;
  logic port_mux_sel_gpio_c_gpio10_o_no_connection;

   assign port_mux_sel_gpio_c_gpio10_o_req[PORT_MUX_GROUP_PAD_GPIOC10_SEL_PAD_GPIOC10] = s_reg2hw.pad_gpioc10_mux_sel.q == PAD_MUX_GROUP_PAD_GPIOC10_SEL_GPIO_C_GPIOC10 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_c_gpio10_o_arbiter (
     .in_i(port_mux_sel_gpio_c_gpio10_o_req),
     .cnt_o(port_mux_sel_gpio_c_gpio10_o_arbitrated),
     .empty_o(port_mux_sel_gpio_c_gpio10_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_c_gpio10_o_no_connection) begin
        port_signals_pad2soc_o.gpio_c.gpio10_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_c_gpio10_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOC10_SEL_PAD_GPIOC10: begin
            port_signals_pad2soc_o.gpio_c.gpio10_o = pads_to_mux_i.pad_gpioc10.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_c.gpio10_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio11_o
  logic [0:0] port_mux_sel_gpio_c_gpio11_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOC11_SEL_WIDTH-1:0] port_mux_sel_gpio_c_gpio11_o_arbitrated;
  logic port_mux_sel_gpio_c_gpio11_o_no_connection;

   assign port_mux_sel_gpio_c_gpio11_o_req[PORT_MUX_GROUP_PAD_GPIOC11_SEL_PAD_GPIOC11] = s_reg2hw.pad_gpioc11_mux_sel.q == PAD_MUX_GROUP_PAD_GPIOC11_SEL_GPIO_C_GPIOC11 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_c_gpio11_o_arbiter (
     .in_i(port_mux_sel_gpio_c_gpio11_o_req),
     .cnt_o(port_mux_sel_gpio_c_gpio11_o_arbitrated),
     .empty_o(port_mux_sel_gpio_c_gpio11_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_c_gpio11_o_no_connection) begin
        port_signals_pad2soc_o.gpio_c.gpio11_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_c_gpio11_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOC11_SEL_PAD_GPIOC11: begin
            port_signals_pad2soc_o.gpio_c.gpio11_o = pads_to_mux_i.pad_gpioc11.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_c.gpio11_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio12_o
  logic [0:0] port_mux_sel_gpio_c_gpio12_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOC12_SEL_WIDTH-1:0] port_mux_sel_gpio_c_gpio12_o_arbitrated;
  logic port_mux_sel_gpio_c_gpio12_o_no_connection;

   assign port_mux_sel_gpio_c_gpio12_o_req[PORT_MUX_GROUP_PAD_GPIOC12_SEL_PAD_GPIOC12] = s_reg2hw.pad_gpioc12_mux_sel.q == PAD_MUX_GROUP_PAD_GPIOC12_SEL_GPIO_C_GPIOC12 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_c_gpio12_o_arbiter (
     .in_i(port_mux_sel_gpio_c_gpio12_o_req),
     .cnt_o(port_mux_sel_gpio_c_gpio12_o_arbitrated),
     .empty_o(port_mux_sel_gpio_c_gpio12_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_c_gpio12_o_no_connection) begin
        port_signals_pad2soc_o.gpio_c.gpio12_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_c_gpio12_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOC12_SEL_PAD_GPIOC12: begin
            port_signals_pad2soc_o.gpio_c.gpio12_o = pads_to_mux_i.pad_gpioc12.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_c.gpio12_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio13_o
  logic [0:0] port_mux_sel_gpio_c_gpio13_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOC13_SEL_WIDTH-1:0] port_mux_sel_gpio_c_gpio13_o_arbitrated;
  logic port_mux_sel_gpio_c_gpio13_o_no_connection;

   assign port_mux_sel_gpio_c_gpio13_o_req[PORT_MUX_GROUP_PAD_GPIOC13_SEL_PAD_GPIOC13] = s_reg2hw.pad_gpioc13_mux_sel.q == PAD_MUX_GROUP_PAD_GPIOC13_SEL_GPIO_C_GPIOC13 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_c_gpio13_o_arbiter (
     .in_i(port_mux_sel_gpio_c_gpio13_o_req),
     .cnt_o(port_mux_sel_gpio_c_gpio13_o_arbitrated),
     .empty_o(port_mux_sel_gpio_c_gpio13_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_c_gpio13_o_no_connection) begin
        port_signals_pad2soc_o.gpio_c.gpio13_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_c_gpio13_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOC13_SEL_PAD_GPIOC13: begin
            port_signals_pad2soc_o.gpio_c.gpio13_o = pads_to_mux_i.pad_gpioc13.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_c.gpio13_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio14_o
  logic [0:0] port_mux_sel_gpio_c_gpio14_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOC14_SEL_WIDTH-1:0] port_mux_sel_gpio_c_gpio14_o_arbitrated;
  logic port_mux_sel_gpio_c_gpio14_o_no_connection;

   assign port_mux_sel_gpio_c_gpio14_o_req[PORT_MUX_GROUP_PAD_GPIOC14_SEL_PAD_GPIOC14] = s_reg2hw.pad_gpioc14_mux_sel.q == PAD_MUX_GROUP_PAD_GPIOC14_SEL_GPIO_C_GPIOC14 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_c_gpio14_o_arbiter (
     .in_i(port_mux_sel_gpio_c_gpio14_o_req),
     .cnt_o(port_mux_sel_gpio_c_gpio14_o_arbitrated),
     .empty_o(port_mux_sel_gpio_c_gpio14_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_c_gpio14_o_no_connection) begin
        port_signals_pad2soc_o.gpio_c.gpio14_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_c_gpio14_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOC14_SEL_PAD_GPIOC14: begin
            port_signals_pad2soc_o.gpio_c.gpio14_o = pads_to_mux_i.pad_gpioc14.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_c.gpio14_o = '0;
          end
       endcase
     end
   end


  // Port Signal gpio15_o
  logic [0:0] port_mux_sel_gpio_c_gpio15_o_req;
  logic [PORT_MUX_GROUP_PAD_GPIOC15_SEL_WIDTH-1:0] port_mux_sel_gpio_c_gpio15_o_arbitrated;
  logic port_mux_sel_gpio_c_gpio15_o_no_connection;

   assign port_mux_sel_gpio_c_gpio15_o_req[PORT_MUX_GROUP_PAD_GPIOC15_SEL_PAD_GPIOC15] = s_reg2hw.pad_gpioc15_mux_sel.q == PAD_MUX_GROUP_PAD_GPIOC15_SEL_GPIO_C_GPIOC15 ? 1'b1 : 1'b0;

   lzc #(
     .WIDTH(1),
     .MODE(1'b0)
   ) i_port_muxsel_gpio_c_gpio15_o_arbiter (
     .in_i(port_mux_sel_gpio_c_gpio15_o_req),
     .cnt_o(port_mux_sel_gpio_c_gpio15_o_arbitrated),
     .empty_o(port_mux_sel_gpio_c_gpio15_o_no_connection)
   );

   always_comb begin
     if (port_mux_sel_gpio_c_gpio15_o_no_connection) begin
        port_signals_pad2soc_o.gpio_c.gpio15_o = '0;
     end else begin
        unique case (port_mux_sel_gpio_c_gpio15_o_arbitrated)
          PORT_MUX_GROUP_PAD_GPIOC15_SEL_PAD_GPIOC15: begin
            port_signals_pad2soc_o.gpio_c.gpio15_o = pads_to_mux_i.pad_gpioc15.pad2chip;
          end
          default: begin
            port_signals_pad2soc_o.gpio_c.gpio15_o = '0;
          end
       endcase
     end
   end

endmodule : low_power_padframe_always_on_pads_muxer
