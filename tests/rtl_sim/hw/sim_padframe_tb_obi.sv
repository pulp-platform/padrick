// Copyright 2026 ETH Zurich.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
// Author: Kai Berszin, ETH Zurich

// OBI variant of the cocotb-facing padframe wrapper. Identical pad/port
// flattening to sim_padframe_tb_top.sv; only the config bus differs: it binds
// the toplevel `parameter type obi_req_t/obi_rsp_t` ports to concrete OBI structs
// (via the obi repo's OBI_TYPEDEF macros, minimal optionals, 1-bit id) and
// flattens the request/response channels to scalars.
//
// The peakrdl obi cpuif is used in its implicit-ready subset: it never inspects
// rready and returns rvalid the cycle after grant. The rready field is still
// present in the request struct (OBI_TYPEDEF_REQ_T) and driven high by the
// testbench; the ObiDriver asserts rvalid is accepted immediately.
`include "obi/typedef.svh"

module sim_padframe_tb_obi (
  input  logic        clk_i,
  input  logic        rst_ni,

  // Flattened OBI config bus (request)
  input  logic        obi_req,
  input  logic [31:0] obi_addr,
  input  logic        obi_we,
  input  logic [3:0]  obi_be,
  input  logic [31:0] obi_wdata,
  input  logic        obi_aid,
  input  logic        obi_rready,
  // Response
  output logic        obi_gnt,
  output logic        obi_rvalid,
  output logic [31:0] obi_rdata,
  output logic        obi_rid,
  output logic        obi_err,

  // Static connection outputs
  output logic        refclk,

  // periph port group
  input  logic        periph_pout_o,
  input  logic        periph_bo,
  input  logic        periph_boe,
  output logic        periph_pin_i,
  output logic        periph_bi,

  // qs port group
  input  logic        qs_qso,
  input  logic        qs_qsoe,
  output logic        qs_qsi,

  // hw port group
  input  logic        hw_hwo,
  input  logic        hw_hwoe,
  output logic        hw_hwi,

  // Landing pad access (TB driver + observation)
  input  logic        pad_clk_drv,  input logic pad_clk_drv_en,  output logic pad_clk_val,
  input  logic        pad_io0_drv,  input logic pad_io0_drv_en,  output logic pad_io0_val,
  input  logic        pad_io1_drv,  input logic pad_io1_drv_en,  output logic pad_io1_val,
  input  logic        pad_io2_drv,  input logic pad_io2_drv_en,  output logic pad_io2_val,
  input  logic        pad_qs_drv,   input logic pad_qs_drv_en,   output logic pad_qs_val,
  input  logic        pad_hw_drv,   input logic pad_hw_drv_en,   output logic pad_hw_val
);
  import pkg_sim_padframe::*;

  // Concrete OBI structs (minimal optionals, 1-bit id) bound to the toplevel ports.
  `OBI_TYPEDEF_MINIMAL_A_OPTIONAL(obi_a_optional_t)
  `OBI_TYPEDEF_A_CHAN_T(obi_a_chan_t, 32, 32, 1, obi_a_optional_t)
  `OBI_TYPEDEF_REQ_T(obi_req_t, obi_a_chan_t)
  `OBI_TYPEDEF_MINIMAL_R_OPTIONAL(obi_r_optional_t)
  `OBI_TYPEDEF_R_CHAN_T(obi_r_chan_t, 32, 1, obi_r_optional_t)
  `OBI_TYPEDEF_RSP_T(obi_rsp_t, obi_r_chan_t)
  obi_req_t config_obi_req;
  obi_rsp_t config_obi_rsp;

  assign config_obi_req.a.addr       = obi_addr;
  assign config_obi_req.a.we         = obi_we;
  assign config_obi_req.a.be         = obi_be;
  assign config_obi_req.a.wdata      = obi_wdata;
  assign config_obi_req.a.aid        = obi_aid;
  assign config_obi_req.a.a_optional = '0;
  assign config_obi_req.req          = obi_req;
  assign config_obi_req.rready       = obi_rready;

  assign obi_gnt    = config_obi_rsp.gnt;
  assign obi_rvalid = config_obi_rsp.rvalid;
  assign obi_rdata  = config_obi_rsp.r.rdata;
  assign obi_rid    = config_obi_rsp.r.rid;
  assign obi_err    = config_obi_rsp.r.err;

  // Flattened SoC-side port structs
  port_signals_soc2pad_t port_soc2pad;
  port_signals_pad2soc_t port_pad2soc;
  static_connection_signals_pad2soc_t static_pad2soc;

  assign port_soc2pad.core.periph.pout_o = periph_pout_o;
  assign port_soc2pad.core.periph.bo     = periph_bo;
  assign port_soc2pad.core.periph.boe    = periph_boe;
  assign port_soc2pad.core.qs.qso        = qs_qso;
  assign port_soc2pad.core.qs.qsoe       = qs_qsoe;
  assign port_soc2pad.core.hw.hwo        = hw_hwo;
  assign port_soc2pad.core.hw.hwoe       = hw_hwoe;

  assign periph_pin_i = port_pad2soc.core.periph.pin_i;
  assign periph_bi    = port_pad2soc.core.periph.bi;
  assign qs_qsi       = port_pad2soc.core.qs.qsi;
  assign hw_hwi       = port_pad2soc.core.hw.hwi;
  assign refclk       = static_pad2soc.core.refclk;

  // Tristate landing-pad nets shared between DUT and testbench driver.
  wire logic pad_clk_net, pad_io0_net, pad_io1_net, pad_io2_net, pad_qs_net, pad_hw_net;

  assign pad_clk_net = pad_clk_drv_en ? pad_clk_drv : 1'bz;
  assign pad_io0_net = pad_io0_drv_en ? pad_io0_drv : 1'bz;
  assign pad_io1_net = pad_io1_drv_en ? pad_io1_drv : 1'bz;
  assign pad_io2_net = pad_io2_drv_en ? pad_io2_drv : 1'bz;
  assign pad_qs_net  = pad_qs_drv_en  ? pad_qs_drv  : 1'bz;
  assign pad_hw_net  = pad_hw_drv_en  ? pad_hw_drv  : 1'bz;

  assign pad_clk_val = pad_clk_net;
  assign pad_io0_val = pad_io0_net;
  assign pad_io1_val = pad_io1_net;
  assign pad_io2_val = pad_io2_net;
  assign pad_qs_val  = pad_qs_net;
  assign pad_hw_val  = pad_hw_net;

  sim_padframe #(
    .AW(32),
    .DW(32),
    .obi_req_t(obi_req_t),
    .obi_rsp_t(obi_rsp_t)
  ) i_dut (
    .clk_i(clk_i),
    .rst_ni(rst_ni),
    .static_connection_signals_pad2soc(static_pad2soc),
    .port_signals_pad2soc(port_pad2soc),
    .port_signals_soc2pad(port_soc2pad),
    .pad_core_pad_clk_pad(pad_clk_net),
    .pad_core_pad_io0_pad(pad_io0_net),
    .pad_core_pad_io1_pad(pad_io1_net),
    .pad_core_pad_io2_pad(pad_io2_net),
    .pad_core_pad_qs_pad(pad_qs_net),
    .pad_core_pad_hw_pad(pad_hw_net),
    .config_obi_req_i(config_obi_req),
    .config_obi_rsp_o(config_obi_rsp)
  );
endmodule
