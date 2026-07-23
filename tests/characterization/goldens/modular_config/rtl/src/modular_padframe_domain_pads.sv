
module modular_padframe_domain_pads
  import pkg_modular_padframe::*;
  import pkg_internal_modular_padframe_domain::*;
(
  output pad_domain_domain_static_connection_signals_pad2soc_t static_connection_signals_pad2soc,
  input  pad_domain_domain_static_connection_signals_soc2pad_t static_connection_signals_soc2pad,
 // Dynamic Pad control signals, these signals are controlled by the multiplexer in the correpsongin pad_controller module
  input mux_to_pads_t mux_to_pads_i,
  output pads_to_mux_t pads_to_mux_o,
  // Landing Pads
  inout wire logic pad_pad_ref_clk_pad_p,
  inout wire logic pad_pad_ref_clk_pad_n,
  inout wire logic pad_pad_clk_byp_pad,
  inout wire logic pad_pad_reset_n_pad,
  inout wire logic pad_pad_debug_en_pad,
  inout wire logic pad_pad_jtag_tck_pad,
  inout wire logic pad_pad_jtag_trst_pad,
  inout wire logic pad_pad_jtag_tms_pad,
  inout wire logic pad_pad_jtag_tdi_pad,
  inout wire logic pad_pad_jtag_tdo_pad,
  inout wire logic pad_pad_io00_pad,
  inout wire logic pad_pad_io01_pad,
  inout wire logic pad_pad_io02_pad,
  inout wire logic pad_pad_io03_pad,
  inout wire logic pad_pad_io04_pad,
  inout wire logic pad_pad_io05_pad,
  inout wire logic pad_pad_io06_pad,
  inout wire logic pad_pad_io07_pad,
  inout wire logic pad_pad_io08_pad,
  inout wire logic pad_pad_io09_pad,
  inout wire logic pad_pad_io10_pad,
  inout wire logic pad_pad_io11_pad,
  inout wire logic pad_pad_io12_pad,
  inout wire logic pad_pad_io13_pad,
  inout wire logic pad_pad_io14_pad,
  inout wire logic pad_pad_io15_pad,
  inout wire logic pad_pad_io16_pad,
  inout wire logic pad_pad_io17_pad,
  inout wire logic pad_pad_io18_pad,
  inout wire logic pad_pad_io19_pad,
  inout wire logic pad_pad_io20_pad,
  inout wire logic pad_pad_io21_pad,
  inout wire logic pad_pad_io22_pad,
  inout wire logic pad_pad_io23_pad,
  inout wire logic pad_pad_io24_pad,
  inout wire logic pad_pad_io25_pad,
  inout wire logic pad_pad_io26_pad,
  inout wire logic pad_pad_io27_pad,
  inout wire logic pad_pad_io28_pad,
  inout wire logic pad_pad_io29_pad,
  inout wire logic pad_pad_io30_pad,
  inout wire logic pad_pad_io31_pad
  );

   // Pad instantiations
   IBUFGDS i_pad_ref_clk (
    .I(pad_pad_ref_clk_pad_p),
    .IB(pad_pad_ref_clk_pad_n),
    .O(static_connection_signals_pad2soc.ref_clk)
  );
   IBUF i_pad_clk_byp (
    .O(static_connection_signals_pad2soc.clk_byp),
    .I(pad_pad_clk_byp_pad)
  );
   // Dummy input pad i_pad_reset_n
  assign static_connection_signals_pad2soc.rst_n = pad_pad_reset_n_pad;
   IBUF i_pad_debug_en (
    .O(static_connection_signals_pad2soc.debug_mode_en),
    .I(pad_pad_debug_en_pad)
  );
   // Dummy input pad i_pad_jtag_tck
  assign static_connection_signals_pad2soc.jtag_tck = pad_pad_jtag_tck_pad;
   // Dummy input pad i_pad_jtag_trst
  assign static_connection_signals_pad2soc.jtag_trst = pad_pad_jtag_trst_pad;
   // Dummy input pad i_pad_jtag_tms
  assign static_connection_signals_pad2soc.jtag_tms = pad_pad_jtag_tms_pad;
   // Dummy input pad i_pad_jtag_tdi
  assign static_connection_signals_pad2soc.jtag_tdi = pad_pad_jtag_tdi_pad;
   // Dummy output pad i_pad_jtag_tdo
  assign pad_pad_jtag_tdo_pad = static_connection_signals_soc2pad.jtag_tdo;
   IOBUF i_pad_io00 (
    .T(~mux_to_pads_i.pad_io00.tx_en),
    .I(mux_to_pads_i.pad_io00.chip2pad),
    .O(pads_to_mux_o.pad_io00.pad2chip),
    .IO(pad_pad_io00_pad)
  );
   IOBUF i_pad_io01 (
    .T(~mux_to_pads_i.pad_io01.tx_en),
    .I(mux_to_pads_i.pad_io01.chip2pad),
    .O(pads_to_mux_o.pad_io01.pad2chip),
    .IO(pad_pad_io01_pad)
  );
   IOBUF i_pad_io02 (
    .T(~mux_to_pads_i.pad_io02.tx_en),
    .I(mux_to_pads_i.pad_io02.chip2pad),
    .O(pads_to_mux_o.pad_io02.pad2chip),
    .IO(pad_pad_io02_pad)
  );
   IOBUF i_pad_io03 (
    .T(~mux_to_pads_i.pad_io03.tx_en),
    .I(mux_to_pads_i.pad_io03.chip2pad),
    .O(pads_to_mux_o.pad_io03.pad2chip),
    .IO(pad_pad_io03_pad)
  );
   IOBUF i_pad_io04 (
    .T(~mux_to_pads_i.pad_io04.tx_en),
    .I(mux_to_pads_i.pad_io04.chip2pad),
    .O(pads_to_mux_o.pad_io04.pad2chip),
    .IO(pad_pad_io04_pad)
  );
   IOBUF i_pad_io05 (
    .T(~mux_to_pads_i.pad_io05.tx_en),
    .I(mux_to_pads_i.pad_io05.chip2pad),
    .O(pads_to_mux_o.pad_io05.pad2chip),
    .IO(pad_pad_io05_pad)
  );
   IOBUF i_pad_io06 (
    .T(~mux_to_pads_i.pad_io06.tx_en),
    .I(mux_to_pads_i.pad_io06.chip2pad),
    .O(pads_to_mux_o.pad_io06.pad2chip),
    .IO(pad_pad_io06_pad)
  );
   IOBUF i_pad_io07 (
    .T(~mux_to_pads_i.pad_io07.tx_en),
    .I(mux_to_pads_i.pad_io07.chip2pad),
    .O(pads_to_mux_o.pad_io07.pad2chip),
    .IO(pad_pad_io07_pad)
  );
   IOBUF i_pad_io08 (
    .T(~mux_to_pads_i.pad_io08.tx_en),
    .I(mux_to_pads_i.pad_io08.chip2pad),
    .O(pads_to_mux_o.pad_io08.pad2chip),
    .IO(pad_pad_io08_pad)
  );
   IOBUF i_pad_io09 (
    .T(~mux_to_pads_i.pad_io09.tx_en),
    .I(mux_to_pads_i.pad_io09.chip2pad),
    .O(pads_to_mux_o.pad_io09.pad2chip),
    .IO(pad_pad_io09_pad)
  );
   IOBUF i_pad_io10 (
    .T(~mux_to_pads_i.pad_io10.tx_en),
    .I(mux_to_pads_i.pad_io10.chip2pad),
    .O(pads_to_mux_o.pad_io10.pad2chip),
    .IO(pad_pad_io10_pad)
  );
   IOBUF i_pad_io11 (
    .T(~mux_to_pads_i.pad_io11.tx_en),
    .I(mux_to_pads_i.pad_io11.chip2pad),
    .O(pads_to_mux_o.pad_io11.pad2chip),
    .IO(pad_pad_io11_pad)
  );
   IOBUF i_pad_io12 (
    .T(~mux_to_pads_i.pad_io12.tx_en),
    .I(mux_to_pads_i.pad_io12.chip2pad),
    .O(pads_to_mux_o.pad_io12.pad2chip),
    .IO(pad_pad_io12_pad)
  );
   IOBUF i_pad_io13 (
    .T(~mux_to_pads_i.pad_io13.tx_en),
    .I(mux_to_pads_i.pad_io13.chip2pad),
    .O(pads_to_mux_o.pad_io13.pad2chip),
    .IO(pad_pad_io13_pad)
  );
   IOBUF i_pad_io14 (
    .T(~mux_to_pads_i.pad_io14.tx_en),
    .I(mux_to_pads_i.pad_io14.chip2pad),
    .O(pads_to_mux_o.pad_io14.pad2chip),
    .IO(pad_pad_io14_pad)
  );
   IOBUF i_pad_io15 (
    .T(~mux_to_pads_i.pad_io15.tx_en),
    .I(mux_to_pads_i.pad_io15.chip2pad),
    .O(pads_to_mux_o.pad_io15.pad2chip),
    .IO(pad_pad_io15_pad)
  );
   IOBUF i_pad_io16 (
    .T(~mux_to_pads_i.pad_io16.tx_en),
    .I(mux_to_pads_i.pad_io16.chip2pad),
    .O(pads_to_mux_o.pad_io16.pad2chip),
    .IO(pad_pad_io16_pad)
  );
   IOBUF i_pad_io17 (
    .T(~mux_to_pads_i.pad_io17.tx_en),
    .I(mux_to_pads_i.pad_io17.chip2pad),
    .O(pads_to_mux_o.pad_io17.pad2chip),
    .IO(pad_pad_io17_pad)
  );
   IOBUF i_pad_io18 (
    .T(~mux_to_pads_i.pad_io18.tx_en),
    .I(mux_to_pads_i.pad_io18.chip2pad),
    .O(pads_to_mux_o.pad_io18.pad2chip),
    .IO(pad_pad_io18_pad)
  );
   IOBUF i_pad_io19 (
    .T(~mux_to_pads_i.pad_io19.tx_en),
    .I(mux_to_pads_i.pad_io19.chip2pad),
    .O(pads_to_mux_o.pad_io19.pad2chip),
    .IO(pad_pad_io19_pad)
  );
   IOBUF i_pad_io20 (
    .T(~mux_to_pads_i.pad_io20.tx_en),
    .I(mux_to_pads_i.pad_io20.chip2pad),
    .O(pads_to_mux_o.pad_io20.pad2chip),
    .IO(pad_pad_io20_pad)
  );
   IOBUF i_pad_io21 (
    .T(~mux_to_pads_i.pad_io21.tx_en),
    .I(mux_to_pads_i.pad_io21.chip2pad),
    .O(pads_to_mux_o.pad_io21.pad2chip),
    .IO(pad_pad_io21_pad)
  );
   IOBUF i_pad_io22 (
    .T(~mux_to_pads_i.pad_io22.tx_en),
    .I(mux_to_pads_i.pad_io22.chip2pad),
    .O(pads_to_mux_o.pad_io22.pad2chip),
    .IO(pad_pad_io22_pad)
  );
   IOBUF i_pad_io23 (
    .T(~mux_to_pads_i.pad_io23.tx_en),
    .I(mux_to_pads_i.pad_io23.chip2pad),
    .O(pads_to_mux_o.pad_io23.pad2chip),
    .IO(pad_pad_io23_pad)
  );
   IOBUF i_pad_io24 (
    .T(~mux_to_pads_i.pad_io24.tx_en),
    .I(mux_to_pads_i.pad_io24.chip2pad),
    .O(pads_to_mux_o.pad_io24.pad2chip),
    .IO(pad_pad_io24_pad)
  );
   IOBUF i_pad_io25 (
    .T(~mux_to_pads_i.pad_io25.tx_en),
    .I(mux_to_pads_i.pad_io25.chip2pad),
    .O(pads_to_mux_o.pad_io25.pad2chip),
    .IO(pad_pad_io25_pad)
  );
   IOBUF i_pad_io26 (
    .T(~mux_to_pads_i.pad_io26.tx_en),
    .I(mux_to_pads_i.pad_io26.chip2pad),
    .O(pads_to_mux_o.pad_io26.pad2chip),
    .IO(pad_pad_io26_pad)
  );
   IOBUF i_pad_io27 (
    .T(~mux_to_pads_i.pad_io27.tx_en),
    .I(mux_to_pads_i.pad_io27.chip2pad),
    .O(pads_to_mux_o.pad_io27.pad2chip),
    .IO(pad_pad_io27_pad)
  );
   IOBUF i_pad_io28 (
    .T(~mux_to_pads_i.pad_io28.tx_en),
    .I(mux_to_pads_i.pad_io28.chip2pad),
    .O(pads_to_mux_o.pad_io28.pad2chip),
    .IO(pad_pad_io28_pad)
  );
   IOBUF i_pad_io29 (
    .T(~mux_to_pads_i.pad_io29.tx_en),
    .I(mux_to_pads_i.pad_io29.chip2pad),
    .O(pads_to_mux_o.pad_io29.pad2chip),
    .IO(pad_pad_io29_pad)
  );
   IOBUF i_pad_io30 (
    .T(~mux_to_pads_i.pad_io30.tx_en),
    .I(mux_to_pads_i.pad_io30.chip2pad),
    .O(pads_to_mux_o.pad_io30.pad2chip),
    .IO(pad_pad_io30_pad)
  );
   IOBUF i_pad_io31 (
    .T(~mux_to_pads_i.pad_io31.tx_en),
    .I(mux_to_pads_i.pad_io31.chip2pad),
    .O(pads_to_mux_o.pad_io31.pad2chip),
    .IO(pad_pad_io31_pad)
  );

endmodule : modular_padframe_domain_pads
