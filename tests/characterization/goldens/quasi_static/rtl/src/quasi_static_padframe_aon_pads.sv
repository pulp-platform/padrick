
module quasi_static_padframe_aon_pads
  import pkg_quasi_static_padframe::*;
  import pkg_internal_quasi_static_padframe_aon::*;
(
 // Dynamic Pad control signals, these signals are controlled by the multiplexer in the correpsongin pad_controller module
  input mux_to_pads_t mux_to_pads_i,
  output pads_to_mux_t pads_to_mux_o,
  // Landing Pads
  inout wire logic pad_pad_hw_pad,
  inout wire logic pad_pad_qs_pad,
  inout wire logic pad_pad_io0_pad,
  inout wire logic pad_pad_io1_pad
  );

   // Pad instantiations
   PULL_PAD i_pad_hw (
    .PAD(pad_pad_hw_pad),
    .OE(mux_to_pads_i.pad_hw.output_en),
    .PEN(mux_to_pads_i.pad_hw.pull_up_en),
    .DS(mux_to_pads_i.pad_hw.driving_strength),
    .I(mux_to_pads_i.pad_hw.chip2pad),
    .O(pads_to_mux_o.pad_hw.pad2chip)
  );
   PULL_PAD i_pad_qs (
    .PAD(pad_pad_qs_pad),
    .OE(mux_to_pads_i.pad_qs.output_en),
    .PEN(mux_to_pads_i.pad_qs.pull_up_en),
    .DS(mux_to_pads_i.pad_qs.driving_strength),
    .I(mux_to_pads_i.pad_qs.chip2pad),
    .O(pads_to_mux_o.pad_qs.pad2chip)
  );
   PULL_PAD i_pad_io0 (
    .PAD(pad_pad_io0_pad),
    .OE(mux_to_pads_i.pad_io0.output_en),
    .PEN(mux_to_pads_i.pad_io0.pull_up_en),
    .DS(mux_to_pads_i.pad_io0.driving_strength),
    .I(mux_to_pads_i.pad_io0.chip2pad),
    .O(pads_to_mux_o.pad_io0.pad2chip)
  );
   PULL_PAD i_pad_io1 (
    .PAD(pad_pad_io1_pad),
    .OE(mux_to_pads_i.pad_io1.output_en),
    .PEN(mux_to_pads_i.pad_io1.pull_up_en),
    .DS(mux_to_pads_i.pad_io1.driving_strength),
    .I(mux_to_pads_i.pad_io1.chip2pad),
    .O(pads_to_mux_o.pad_io1.pad2chip)
  );

endmodule : quasi_static_padframe_aon_pads
