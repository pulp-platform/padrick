// Copyright 2026 ETH Zurich.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
// Author: Kai Berszin, ETH Zurich

// Trivial technology-independent behavioural bidirectional pad. It matches the
// instantiation template of the `bidir_pad` pad type in sim_padframe.yaml. The
// tristate resolution lives entirely inside SystemVerilog so Verilator handles
// it (V3Tristate); the cocotb-facing top only ever sees two-state ports.
module behav_tristate_pad (
  inout  wire logic pad,
  input       logic oe,  // output (chip -> pad) driver enable
  input       logic ie,  // input (pad -> chip) buffer enable
  input       logic i,   // chip -> pad data
  output      logic o    // pad -> chip data
);
  assign pad = oe ? i : 1'bz;
  assign o   = ie ? pad : 1'b0;
endmodule
