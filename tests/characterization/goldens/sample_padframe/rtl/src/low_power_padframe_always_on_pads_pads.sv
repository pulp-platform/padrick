
module low_power_padframe_always_on_pads_pads
  import pkg_low_power_padframe::*;
  import pkg_internal_low_power_padframe_always_on_pads::*;
(
  //Override signals
  input  pad_domain_always_on_pads_override_signals_t override_signals_i,
  output pad_domain_always_on_pads_static_connection_signals_pad2soc_t static_connection_signals_pad2soc,
 // Dynamic Pad control signals, these signals are controlled by the multiplexer in the correpsongin pad_controller module
  input mux_to_pads_t mux_to_pads_i,
  output pads_to_mux_t pads_to_mux_o,
  // Landing Pads
  inout wire logic pad_pad_ref_clk_pad,
  inout wire logic pad_pad_gpioa0_pad,
  inout wire logic pad_pad_gpioa1_pad,
  inout wire logic pad_pad_gpioa2_pad,
  inout wire logic pad_pad_gpioa3_pad,
  inout wire logic pad_pad_gpioa4_pad,
  inout wire logic pad_pad_gpioa5_pad,
  inout wire logic pad_pad_gpioa6_pad,
  inout wire logic pad_pad_gpioa7_pad,
  inout wire logic pad_pad_gpioa8_pad,
  inout wire logic pad_pad_gpioa9_pad,
  inout wire logic pad_pad_gpioa10_pad,
  inout wire logic pad_pad_gpioa11_pad,
  inout wire logic pad_pad_gpioa12_pad,
  inout wire logic pad_pad_gpioa13_pad,
  inout wire logic pad_pad_gpioa14_pad,
  inout wire logic pad_pad_gpioa15_pad,
  inout wire logic pad_pad_gpioa16_pad,
  inout wire logic pad_pad_gpioa17_pad,
  inout wire logic pad_pad_gpioa18_pad,
  inout wire logic pad_pad_gpioa19_pad,
  inout wire logic pad_pad_gpioa20_pad,
  inout wire logic pad_pad_gpioa21_pad,
  inout wire logic pad_pad_gpioa22_pad,
  inout wire logic pad_pad_gpioa23_pad,
  inout wire logic pad_pad_gpioa24_pad,
  inout wire logic pad_pad_gpioa25_pad,
  inout wire logic pad_pad_gpioa26_pad,
  inout wire logic pad_pad_gpioa27_pad,
  inout wire logic pad_pad_gpioa28_pad,
  inout wire logic pad_pad_gpioa29_pad,
  inout wire logic pad_pad_gpioa30_pad,
  inout wire logic pad_pad_gpioa31_pad,
  inout wire logic pad_pad_gpiob0_pad,
  inout wire logic pad_pad_gpiob1_pad,
  inout wire logic pad_pad_gpiob2_pad,
  inout wire logic pad_pad_gpiob3_pad,
  inout wire logic pad_pad_gpiob4_pad,
  inout wire logic pad_pad_gpiob5_pad,
  inout wire logic pad_pad_gpiob6_pad,
  inout wire logic pad_pad_gpiob7_pad,
  inout wire logic pad_pad_gpiob8_pad,
  inout wire logic pad_pad_gpiob9_pad,
  inout wire logic pad_pad_gpiob10_pad,
  inout wire logic pad_pad_gpiob11_pad,
  inout wire logic pad_pad_gpiob12_pad,
  inout wire logic pad_pad_gpiob13_pad,
  inout wire logic pad_pad_gpiob14_pad,
  inout wire logic pad_pad_gpiob15_pad,
  inout wire logic pad_pad_gpiob16_pad,
  inout wire logic pad_pad_gpiob17_pad,
  inout wire logic pad_pad_gpiob18_pad,
  inout wire logic pad_pad_gpiob19_pad,
  inout wire logic pad_pad_gpiob20_pad,
  inout wire logic pad_pad_gpiob21_pad,
  inout wire logic pad_pad_gpiob22_pad,
  inout wire logic pad_pad_gpiob23_pad,
  inout wire logic pad_pad_gpiob24_pad,
  inout wire logic pad_pad_gpiob25_pad,
  inout wire logic pad_pad_gpiob26_pad,
  inout wire logic pad_pad_gpiob27_pad,
  inout wire logic pad_pad_gpiob28_pad,
  inout wire logic pad_pad_gpiob29_pad,
  inout wire logic pad_pad_gpiob30_pad,
  inout wire logic pad_pad_gpiob31_pad,
  inout wire logic pad_pad_gpioc0_pad,
  inout wire logic pad_pad_gpioc1_pad,
  inout wire logic pad_pad_gpioc2_pad,
  inout wire logic pad_pad_gpioc3_pad,
  inout wire logic pad_pad_gpioc4_pad,
  inout wire logic pad_pad_gpioc5_pad,
  inout wire logic pad_pad_gpioc6_pad,
  inout wire logic pad_pad_gpioc7_pad,
  inout wire logic pad_pad_gpioc8_pad,
  inout wire logic pad_pad_gpioc9_pad,
  inout wire logic pad_pad_gpioc10_pad,
  inout wire logic pad_pad_gpioc11_pad,
  inout wire logic pad_pad_gpioc12_pad,
  inout wire logic pad_pad_gpioc13_pad,
  inout wire logic pad_pad_gpioc14_pad,
  inout wire logic pad_pad_gpioc15_pad
  );

   // Pad instantiations
   PDDW04808 i_pad_ref_clk (
    .PAD(pad_pad_ref_clk_pad),
    .IE(1'b1),
    .OE((1'b0)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(1'b0),
    .O(static_connection_signals_pad2soc.ref_clk)
  );
   PDDW04808 i_pad_gpioa0 (
    .PAD(pad_pad_gpioa0_pad),
    .IE(mux_to_pads_i.pad_gpioa0.rx_en),
    .OE((mux_to_pads_i.pad_gpioa0.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa0.chip2pad),
    .O(pads_to_mux_o.pad_gpioa0.pad2chip)
  );
   PDDW04808 i_pad_gpioa1 (
    .PAD(pad_pad_gpioa1_pad),
    .IE(mux_to_pads_i.pad_gpioa1.rx_en),
    .OE((mux_to_pads_i.pad_gpioa1.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa1.chip2pad),
    .O(pads_to_mux_o.pad_gpioa1.pad2chip)
  );
   PDDW04808 i_pad_gpioa2 (
    .PAD(pad_pad_gpioa2_pad),
    .IE(mux_to_pads_i.pad_gpioa2.rx_en),
    .OE((mux_to_pads_i.pad_gpioa2.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa2.chip2pad),
    .O(pads_to_mux_o.pad_gpioa2.pad2chip)
  );
   PDDW04808 i_pad_gpioa3 (
    .PAD(pad_pad_gpioa3_pad),
    .IE(mux_to_pads_i.pad_gpioa3.rx_en),
    .OE((mux_to_pads_i.pad_gpioa3.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa3.chip2pad),
    .O(pads_to_mux_o.pad_gpioa3.pad2chip)
  );
   PDDW04808 i_pad_gpioa4 (
    .PAD(pad_pad_gpioa4_pad),
    .IE(mux_to_pads_i.pad_gpioa4.rx_en),
    .OE((mux_to_pads_i.pad_gpioa4.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa4.chip2pad),
    .O(pads_to_mux_o.pad_gpioa4.pad2chip)
  );
   PDDW04808 i_pad_gpioa5 (
    .PAD(pad_pad_gpioa5_pad),
    .IE(mux_to_pads_i.pad_gpioa5.rx_en),
    .OE((mux_to_pads_i.pad_gpioa5.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa5.chip2pad),
    .O(pads_to_mux_o.pad_gpioa5.pad2chip)
  );
   PDDW04808 i_pad_gpioa6 (
    .PAD(pad_pad_gpioa6_pad),
    .IE(mux_to_pads_i.pad_gpioa6.rx_en),
    .OE((mux_to_pads_i.pad_gpioa6.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa6.chip2pad),
    .O(pads_to_mux_o.pad_gpioa6.pad2chip)
  );
   PDDW04808 i_pad_gpioa7 (
    .PAD(pad_pad_gpioa7_pad),
    .IE(mux_to_pads_i.pad_gpioa7.rx_en),
    .OE((mux_to_pads_i.pad_gpioa7.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa7.chip2pad),
    .O(pads_to_mux_o.pad_gpioa7.pad2chip)
  );
   PDDW04808 i_pad_gpioa8 (
    .PAD(pad_pad_gpioa8_pad),
    .IE(mux_to_pads_i.pad_gpioa8.rx_en),
    .OE((mux_to_pads_i.pad_gpioa8.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa8.chip2pad),
    .O(pads_to_mux_o.pad_gpioa8.pad2chip)
  );
   PDDW04808 i_pad_gpioa9 (
    .PAD(pad_pad_gpioa9_pad),
    .IE(mux_to_pads_i.pad_gpioa9.rx_en),
    .OE((mux_to_pads_i.pad_gpioa9.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa9.chip2pad),
    .O(pads_to_mux_o.pad_gpioa9.pad2chip)
  );
   PDDW04808 i_pad_gpioa10 (
    .PAD(pad_pad_gpioa10_pad),
    .IE(mux_to_pads_i.pad_gpioa10.rx_en),
    .OE((mux_to_pads_i.pad_gpioa10.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa10.chip2pad),
    .O(pads_to_mux_o.pad_gpioa10.pad2chip)
  );
   PDDW04808 i_pad_gpioa11 (
    .PAD(pad_pad_gpioa11_pad),
    .IE(mux_to_pads_i.pad_gpioa11.rx_en),
    .OE((mux_to_pads_i.pad_gpioa11.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa11.chip2pad),
    .O(pads_to_mux_o.pad_gpioa11.pad2chip)
  );
   PDDW04808 i_pad_gpioa12 (
    .PAD(pad_pad_gpioa12_pad),
    .IE(mux_to_pads_i.pad_gpioa12.rx_en),
    .OE((mux_to_pads_i.pad_gpioa12.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa12.chip2pad),
    .O(pads_to_mux_o.pad_gpioa12.pad2chip)
  );
   PDDW04808 i_pad_gpioa13 (
    .PAD(pad_pad_gpioa13_pad),
    .IE(mux_to_pads_i.pad_gpioa13.rx_en),
    .OE((mux_to_pads_i.pad_gpioa13.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa13.chip2pad),
    .O(pads_to_mux_o.pad_gpioa13.pad2chip)
  );
   PDDW04808 i_pad_gpioa14 (
    .PAD(pad_pad_gpioa14_pad),
    .IE(mux_to_pads_i.pad_gpioa14.rx_en),
    .OE((mux_to_pads_i.pad_gpioa14.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa14.chip2pad),
    .O(pads_to_mux_o.pad_gpioa14.pad2chip)
  );
   PDDW04808 i_pad_gpioa15 (
    .PAD(pad_pad_gpioa15_pad),
    .IE(mux_to_pads_i.pad_gpioa15.rx_en),
    .OE((mux_to_pads_i.pad_gpioa15.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa15.chip2pad),
    .O(pads_to_mux_o.pad_gpioa15.pad2chip)
  );
   PDDW04808 i_pad_gpioa16 (
    .PAD(pad_pad_gpioa16_pad),
    .IE(mux_to_pads_i.pad_gpioa16.rx_en),
    .OE((mux_to_pads_i.pad_gpioa16.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa16.chip2pad),
    .O(pads_to_mux_o.pad_gpioa16.pad2chip)
  );
   PDDW04808 i_pad_gpioa17 (
    .PAD(pad_pad_gpioa17_pad),
    .IE(mux_to_pads_i.pad_gpioa17.rx_en),
    .OE((mux_to_pads_i.pad_gpioa17.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa17.chip2pad),
    .O(pads_to_mux_o.pad_gpioa17.pad2chip)
  );
   PDDW04808 i_pad_gpioa18 (
    .PAD(pad_pad_gpioa18_pad),
    .IE(mux_to_pads_i.pad_gpioa18.rx_en),
    .OE((mux_to_pads_i.pad_gpioa18.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa18.chip2pad),
    .O(pads_to_mux_o.pad_gpioa18.pad2chip)
  );
   PDDW04808 i_pad_gpioa19 (
    .PAD(pad_pad_gpioa19_pad),
    .IE(mux_to_pads_i.pad_gpioa19.rx_en),
    .OE((mux_to_pads_i.pad_gpioa19.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa19.chip2pad),
    .O(pads_to_mux_o.pad_gpioa19.pad2chip)
  );
   PDDW04808 i_pad_gpioa20 (
    .PAD(pad_pad_gpioa20_pad),
    .IE(mux_to_pads_i.pad_gpioa20.rx_en),
    .OE((mux_to_pads_i.pad_gpioa20.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa20.chip2pad),
    .O(pads_to_mux_o.pad_gpioa20.pad2chip)
  );
   PDDW04808 i_pad_gpioa21 (
    .PAD(pad_pad_gpioa21_pad),
    .IE(mux_to_pads_i.pad_gpioa21.rx_en),
    .OE((mux_to_pads_i.pad_gpioa21.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa21.chip2pad),
    .O(pads_to_mux_o.pad_gpioa21.pad2chip)
  );
   PDDW04808 i_pad_gpioa22 (
    .PAD(pad_pad_gpioa22_pad),
    .IE(mux_to_pads_i.pad_gpioa22.rx_en),
    .OE((mux_to_pads_i.pad_gpioa22.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa22.chip2pad),
    .O(pads_to_mux_o.pad_gpioa22.pad2chip)
  );
   PDDW04808 i_pad_gpioa23 (
    .PAD(pad_pad_gpioa23_pad),
    .IE(mux_to_pads_i.pad_gpioa23.rx_en),
    .OE((mux_to_pads_i.pad_gpioa23.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa23.chip2pad),
    .O(pads_to_mux_o.pad_gpioa23.pad2chip)
  );
   PDDW04808 i_pad_gpioa24 (
    .PAD(pad_pad_gpioa24_pad),
    .IE(mux_to_pads_i.pad_gpioa24.rx_en),
    .OE((mux_to_pads_i.pad_gpioa24.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa24.chip2pad),
    .O(pads_to_mux_o.pad_gpioa24.pad2chip)
  );
   PDDW04808 i_pad_gpioa25 (
    .PAD(pad_pad_gpioa25_pad),
    .IE(mux_to_pads_i.pad_gpioa25.rx_en),
    .OE((mux_to_pads_i.pad_gpioa25.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa25.chip2pad),
    .O(pads_to_mux_o.pad_gpioa25.pad2chip)
  );
   PDDW04808 i_pad_gpioa26 (
    .PAD(pad_pad_gpioa26_pad),
    .IE(mux_to_pads_i.pad_gpioa26.rx_en),
    .OE((mux_to_pads_i.pad_gpioa26.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa26.chip2pad),
    .O(pads_to_mux_o.pad_gpioa26.pad2chip)
  );
   PDDW04808 i_pad_gpioa27 (
    .PAD(pad_pad_gpioa27_pad),
    .IE(mux_to_pads_i.pad_gpioa27.rx_en),
    .OE((mux_to_pads_i.pad_gpioa27.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa27.chip2pad),
    .O(pads_to_mux_o.pad_gpioa27.pad2chip)
  );
   PDDW04808 i_pad_gpioa28 (
    .PAD(pad_pad_gpioa28_pad),
    .IE(mux_to_pads_i.pad_gpioa28.rx_en),
    .OE((mux_to_pads_i.pad_gpioa28.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa28.chip2pad),
    .O(pads_to_mux_o.pad_gpioa28.pad2chip)
  );
   PDDW04808 i_pad_gpioa29 (
    .PAD(pad_pad_gpioa29_pad),
    .IE(mux_to_pads_i.pad_gpioa29.rx_en),
    .OE((mux_to_pads_i.pad_gpioa29.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa29.chip2pad),
    .O(pads_to_mux_o.pad_gpioa29.pad2chip)
  );
   PDDW04808 i_pad_gpioa30 (
    .PAD(pad_pad_gpioa30_pad),
    .IE(mux_to_pads_i.pad_gpioa30.rx_en),
    .OE((mux_to_pads_i.pad_gpioa30.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa30.chip2pad),
    .O(pads_to_mux_o.pad_gpioa30.pad2chip)
  );
   PDDW04808 i_pad_gpioa31 (
    .PAD(pad_pad_gpioa31_pad),
    .IE(mux_to_pads_i.pad_gpioa31.rx_en),
    .OE((mux_to_pads_i.pad_gpioa31.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioa31.chip2pad),
    .O(pads_to_mux_o.pad_gpioa31.pad2chip)
  );
   PDDW04808 i_pad_gpiob0 (
    .PAD(pad_pad_gpiob0_pad),
    .IE(mux_to_pads_i.pad_gpiob0.rx_en),
    .OE((mux_to_pads_i.pad_gpiob0.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob0.chip2pad),
    .O(pads_to_mux_o.pad_gpiob0.pad2chip)
  );
   PDDW04808 i_pad_gpiob1 (
    .PAD(pad_pad_gpiob1_pad),
    .IE(mux_to_pads_i.pad_gpiob1.rx_en),
    .OE((mux_to_pads_i.pad_gpiob1.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob1.chip2pad),
    .O(pads_to_mux_o.pad_gpiob1.pad2chip)
  );
   PDDW04808 i_pad_gpiob2 (
    .PAD(pad_pad_gpiob2_pad),
    .IE(mux_to_pads_i.pad_gpiob2.rx_en),
    .OE((mux_to_pads_i.pad_gpiob2.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob2.chip2pad),
    .O(pads_to_mux_o.pad_gpiob2.pad2chip)
  );
   PDDW04808 i_pad_gpiob3 (
    .PAD(pad_pad_gpiob3_pad),
    .IE(mux_to_pads_i.pad_gpiob3.rx_en),
    .OE((mux_to_pads_i.pad_gpiob3.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob3.chip2pad),
    .O(pads_to_mux_o.pad_gpiob3.pad2chip)
  );
   PDDW04808 i_pad_gpiob4 (
    .PAD(pad_pad_gpiob4_pad),
    .IE(mux_to_pads_i.pad_gpiob4.rx_en),
    .OE((mux_to_pads_i.pad_gpiob4.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob4.chip2pad),
    .O(pads_to_mux_o.pad_gpiob4.pad2chip)
  );
   PDDW04808 i_pad_gpiob5 (
    .PAD(pad_pad_gpiob5_pad),
    .IE(mux_to_pads_i.pad_gpiob5.rx_en),
    .OE((mux_to_pads_i.pad_gpiob5.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob5.chip2pad),
    .O(pads_to_mux_o.pad_gpiob5.pad2chip)
  );
   PDDW04808 i_pad_gpiob6 (
    .PAD(pad_pad_gpiob6_pad),
    .IE(mux_to_pads_i.pad_gpiob6.rx_en),
    .OE((mux_to_pads_i.pad_gpiob6.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob6.chip2pad),
    .O(pads_to_mux_o.pad_gpiob6.pad2chip)
  );
   PDDW04808 i_pad_gpiob7 (
    .PAD(pad_pad_gpiob7_pad),
    .IE(mux_to_pads_i.pad_gpiob7.rx_en),
    .OE((mux_to_pads_i.pad_gpiob7.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob7.chip2pad),
    .O(pads_to_mux_o.pad_gpiob7.pad2chip)
  );
   PDDW04808 i_pad_gpiob8 (
    .PAD(pad_pad_gpiob8_pad),
    .IE(mux_to_pads_i.pad_gpiob8.rx_en),
    .OE((mux_to_pads_i.pad_gpiob8.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob8.chip2pad),
    .O(pads_to_mux_o.pad_gpiob8.pad2chip)
  );
   PDDW04808 i_pad_gpiob9 (
    .PAD(pad_pad_gpiob9_pad),
    .IE(mux_to_pads_i.pad_gpiob9.rx_en),
    .OE((mux_to_pads_i.pad_gpiob9.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob9.chip2pad),
    .O(pads_to_mux_o.pad_gpiob9.pad2chip)
  );
   PDDW04808 i_pad_gpiob10 (
    .PAD(pad_pad_gpiob10_pad),
    .IE(mux_to_pads_i.pad_gpiob10.rx_en),
    .OE((mux_to_pads_i.pad_gpiob10.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob10.chip2pad),
    .O(pads_to_mux_o.pad_gpiob10.pad2chip)
  );
   PDDW04808 i_pad_gpiob11 (
    .PAD(pad_pad_gpiob11_pad),
    .IE(mux_to_pads_i.pad_gpiob11.rx_en),
    .OE((mux_to_pads_i.pad_gpiob11.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob11.chip2pad),
    .O(pads_to_mux_o.pad_gpiob11.pad2chip)
  );
   PDDW04808 i_pad_gpiob12 (
    .PAD(pad_pad_gpiob12_pad),
    .IE(mux_to_pads_i.pad_gpiob12.rx_en),
    .OE((mux_to_pads_i.pad_gpiob12.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob12.chip2pad),
    .O(pads_to_mux_o.pad_gpiob12.pad2chip)
  );
   PDDW04808 i_pad_gpiob13 (
    .PAD(pad_pad_gpiob13_pad),
    .IE(mux_to_pads_i.pad_gpiob13.rx_en),
    .OE((mux_to_pads_i.pad_gpiob13.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob13.chip2pad),
    .O(pads_to_mux_o.pad_gpiob13.pad2chip)
  );
   PDDW04808 i_pad_gpiob14 (
    .PAD(pad_pad_gpiob14_pad),
    .IE(mux_to_pads_i.pad_gpiob14.rx_en),
    .OE((mux_to_pads_i.pad_gpiob14.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob14.chip2pad),
    .O(pads_to_mux_o.pad_gpiob14.pad2chip)
  );
   PDDW04808 i_pad_gpiob15 (
    .PAD(pad_pad_gpiob15_pad),
    .IE(mux_to_pads_i.pad_gpiob15.rx_en),
    .OE((mux_to_pads_i.pad_gpiob15.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob15.chip2pad),
    .O(pads_to_mux_o.pad_gpiob15.pad2chip)
  );
   PDDW04808 i_pad_gpiob16 (
    .PAD(pad_pad_gpiob16_pad),
    .IE(mux_to_pads_i.pad_gpiob16.rx_en),
    .OE((mux_to_pads_i.pad_gpiob16.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob16.chip2pad),
    .O(pads_to_mux_o.pad_gpiob16.pad2chip)
  );
   PDDW04808 i_pad_gpiob17 (
    .PAD(pad_pad_gpiob17_pad),
    .IE(mux_to_pads_i.pad_gpiob17.rx_en),
    .OE((mux_to_pads_i.pad_gpiob17.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob17.chip2pad),
    .O(pads_to_mux_o.pad_gpiob17.pad2chip)
  );
   PDDW04808 i_pad_gpiob18 (
    .PAD(pad_pad_gpiob18_pad),
    .IE(mux_to_pads_i.pad_gpiob18.rx_en),
    .OE((mux_to_pads_i.pad_gpiob18.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob18.chip2pad),
    .O(pads_to_mux_o.pad_gpiob18.pad2chip)
  );
   PDDW04808 i_pad_gpiob19 (
    .PAD(pad_pad_gpiob19_pad),
    .IE(mux_to_pads_i.pad_gpiob19.rx_en),
    .OE((mux_to_pads_i.pad_gpiob19.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob19.chip2pad),
    .O(pads_to_mux_o.pad_gpiob19.pad2chip)
  );
   PDDW04808 i_pad_gpiob20 (
    .PAD(pad_pad_gpiob20_pad),
    .IE(mux_to_pads_i.pad_gpiob20.rx_en),
    .OE((mux_to_pads_i.pad_gpiob20.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob20.chip2pad),
    .O(pads_to_mux_o.pad_gpiob20.pad2chip)
  );
   PDDW04808 i_pad_gpiob21 (
    .PAD(pad_pad_gpiob21_pad),
    .IE(mux_to_pads_i.pad_gpiob21.rx_en),
    .OE((mux_to_pads_i.pad_gpiob21.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob21.chip2pad),
    .O(pads_to_mux_o.pad_gpiob21.pad2chip)
  );
   PDDW04808 i_pad_gpiob22 (
    .PAD(pad_pad_gpiob22_pad),
    .IE(mux_to_pads_i.pad_gpiob22.rx_en),
    .OE((mux_to_pads_i.pad_gpiob22.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob22.chip2pad),
    .O(pads_to_mux_o.pad_gpiob22.pad2chip)
  );
   PDDW04808 i_pad_gpiob23 (
    .PAD(pad_pad_gpiob23_pad),
    .IE(mux_to_pads_i.pad_gpiob23.rx_en),
    .OE((mux_to_pads_i.pad_gpiob23.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob23.chip2pad),
    .O(pads_to_mux_o.pad_gpiob23.pad2chip)
  );
   PDDW04808 i_pad_gpiob24 (
    .PAD(pad_pad_gpiob24_pad),
    .IE(mux_to_pads_i.pad_gpiob24.rx_en),
    .OE((mux_to_pads_i.pad_gpiob24.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob24.chip2pad),
    .O(pads_to_mux_o.pad_gpiob24.pad2chip)
  );
   PDDW04808 i_pad_gpiob25 (
    .PAD(pad_pad_gpiob25_pad),
    .IE(mux_to_pads_i.pad_gpiob25.rx_en),
    .OE((mux_to_pads_i.pad_gpiob25.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob25.chip2pad),
    .O(pads_to_mux_o.pad_gpiob25.pad2chip)
  );
   PDDW04808 i_pad_gpiob26 (
    .PAD(pad_pad_gpiob26_pad),
    .IE(mux_to_pads_i.pad_gpiob26.rx_en),
    .OE((mux_to_pads_i.pad_gpiob26.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob26.chip2pad),
    .O(pads_to_mux_o.pad_gpiob26.pad2chip)
  );
   PDDW04808 i_pad_gpiob27 (
    .PAD(pad_pad_gpiob27_pad),
    .IE(mux_to_pads_i.pad_gpiob27.rx_en),
    .OE((mux_to_pads_i.pad_gpiob27.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob27.chip2pad),
    .O(pads_to_mux_o.pad_gpiob27.pad2chip)
  );
   PDDW04808 i_pad_gpiob28 (
    .PAD(pad_pad_gpiob28_pad),
    .IE(mux_to_pads_i.pad_gpiob28.rx_en),
    .OE((mux_to_pads_i.pad_gpiob28.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob28.chip2pad),
    .O(pads_to_mux_o.pad_gpiob28.pad2chip)
  );
   PDDW04808 i_pad_gpiob29 (
    .PAD(pad_pad_gpiob29_pad),
    .IE(mux_to_pads_i.pad_gpiob29.rx_en),
    .OE((mux_to_pads_i.pad_gpiob29.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob29.chip2pad),
    .O(pads_to_mux_o.pad_gpiob29.pad2chip)
  );
   PDDW04808 i_pad_gpiob30 (
    .PAD(pad_pad_gpiob30_pad),
    .IE(mux_to_pads_i.pad_gpiob30.rx_en),
    .OE((mux_to_pads_i.pad_gpiob30.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob30.chip2pad),
    .O(pads_to_mux_o.pad_gpiob30.pad2chip)
  );
   PDDW04808 i_pad_gpiob31 (
    .PAD(pad_pad_gpiob31_pad),
    .IE(mux_to_pads_i.pad_gpiob31.rx_en),
    .OE((mux_to_pads_i.pad_gpiob31.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpiob31.chip2pad),
    .O(pads_to_mux_o.pad_gpiob31.pad2chip)
  );
   PDDW04808 i_pad_gpioc0 (
    .PAD(pad_pad_gpioc0_pad),
    .IE(mux_to_pads_i.pad_gpioc0.rx_en),
    .OE((mux_to_pads_i.pad_gpioc0.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioc0.chip2pad),
    .O(pads_to_mux_o.pad_gpioc0.pad2chip)
  );
   PDDW04808 i_pad_gpioc1 (
    .PAD(pad_pad_gpioc1_pad),
    .IE(mux_to_pads_i.pad_gpioc1.rx_en),
    .OE((mux_to_pads_i.pad_gpioc1.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioc1.chip2pad),
    .O(pads_to_mux_o.pad_gpioc1.pad2chip)
  );
   PDDW04808 i_pad_gpioc2 (
    .PAD(pad_pad_gpioc2_pad),
    .IE(mux_to_pads_i.pad_gpioc2.rx_en),
    .OE((mux_to_pads_i.pad_gpioc2.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioc2.chip2pad),
    .O(pads_to_mux_o.pad_gpioc2.pad2chip)
  );
   PDDW04808 i_pad_gpioc3 (
    .PAD(pad_pad_gpioc3_pad),
    .IE(mux_to_pads_i.pad_gpioc3.rx_en),
    .OE((mux_to_pads_i.pad_gpioc3.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioc3.chip2pad),
    .O(pads_to_mux_o.pad_gpioc3.pad2chip)
  );
   PDDW04808 i_pad_gpioc4 (
    .PAD(pad_pad_gpioc4_pad),
    .IE(mux_to_pads_i.pad_gpioc4.rx_en),
    .OE((mux_to_pads_i.pad_gpioc4.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioc4.chip2pad),
    .O(pads_to_mux_o.pad_gpioc4.pad2chip)
  );
   PDDW04808 i_pad_gpioc5 (
    .PAD(pad_pad_gpioc5_pad),
    .IE(mux_to_pads_i.pad_gpioc5.rx_en),
    .OE((mux_to_pads_i.pad_gpioc5.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioc5.chip2pad),
    .O(pads_to_mux_o.pad_gpioc5.pad2chip)
  );
   PDDW04808 i_pad_gpioc6 (
    .PAD(pad_pad_gpioc6_pad),
    .IE(mux_to_pads_i.pad_gpioc6.rx_en),
    .OE((mux_to_pads_i.pad_gpioc6.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioc6.chip2pad),
    .O(pads_to_mux_o.pad_gpioc6.pad2chip)
  );
   PDDW04808 i_pad_gpioc7 (
    .PAD(pad_pad_gpioc7_pad),
    .IE(mux_to_pads_i.pad_gpioc7.rx_en),
    .OE((mux_to_pads_i.pad_gpioc7.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioc7.chip2pad),
    .O(pads_to_mux_o.pad_gpioc7.pad2chip)
  );
   PDDW04808 i_pad_gpioc8 (
    .PAD(pad_pad_gpioc8_pad),
    .IE(mux_to_pads_i.pad_gpioc8.rx_en),
    .OE((mux_to_pads_i.pad_gpioc8.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioc8.chip2pad),
    .O(pads_to_mux_o.pad_gpioc8.pad2chip)
  );
   PDDW04808 i_pad_gpioc9 (
    .PAD(pad_pad_gpioc9_pad),
    .IE(mux_to_pads_i.pad_gpioc9.rx_en),
    .OE((mux_to_pads_i.pad_gpioc9.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioc9.chip2pad),
    .O(pads_to_mux_o.pad_gpioc9.pad2chip)
  );
   PDDW04808 i_pad_gpioc10 (
    .PAD(pad_pad_gpioc10_pad),
    .IE(mux_to_pads_i.pad_gpioc10.rx_en),
    .OE((mux_to_pads_i.pad_gpioc10.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioc10.chip2pad),
    .O(pads_to_mux_o.pad_gpioc10.pad2chip)
  );
   PDDW04808 i_pad_gpioc11 (
    .PAD(pad_pad_gpioc11_pad),
    .IE(mux_to_pads_i.pad_gpioc11.rx_en),
    .OE((mux_to_pads_i.pad_gpioc11.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioc11.chip2pad),
    .O(pads_to_mux_o.pad_gpioc11.pad2chip)
  );
   PDDW04808 i_pad_gpioc12 (
    .PAD(pad_pad_gpioc12_pad),
    .IE(mux_to_pads_i.pad_gpioc12.rx_en),
    .OE((mux_to_pads_i.pad_gpioc12.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioc12.chip2pad),
    .O(pads_to_mux_o.pad_gpioc12.pad2chip)
  );
   PDDW04808 i_pad_gpioc13 (
    .PAD(pad_pad_gpioc13_pad),
    .IE(mux_to_pads_i.pad_gpioc13.rx_en),
    .OE((mux_to_pads_i.pad_gpioc13.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioc13.chip2pad),
    .O(pads_to_mux_o.pad_gpioc13.pad2chip)
  );
   PDDW04808 i_pad_gpioc14 (
    .PAD(pad_pad_gpioc14_pad),
    .IE(mux_to_pads_i.pad_gpioc14.rx_en),
    .OE((mux_to_pads_i.pad_gpioc14.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioc14.chip2pad),
    .O(pads_to_mux_o.pad_gpioc14.pad2chip)
  );
   PDDW04808 i_pad_gpioc15 (
    .PAD(pad_pad_gpioc15_pad),
    .IE(mux_to_pads_i.pad_gpioc15.rx_en),
    .OE((mux_to_pads_i.pad_gpioc15.output_en)|(override_signals_i.s_enable_all_outputs)),
    .DS(3'b0),
    .I(mux_to_pads_i.pad_gpioc15.chip2pad),
    .O(pads_to_mux_o.pad_gpioc15.pad2chip)
  );

endmodule : low_power_padframe_always_on_pads_pads
