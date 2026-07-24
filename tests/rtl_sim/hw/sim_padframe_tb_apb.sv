// Copyright 2026 ETH Zurich.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
// Author: Kai Berszin, ETH Zurich

// APB4 variant of the cocotb-facing padframe wrapper. Identical pad/port
// flattening to sim_padframe_tb_top.sv; only the config bus differs: it binds
// the toplevel `parameter type apb_req_t/apb_resp_t` ports to concrete APB4
// structs (via the apb repo's APB_TYPEDEF macros) and flattens them to scalars.
// The peakrdl DUT consumes the APB4 struct natively (native apb4 cpuif), so
// there is no internal register_interface type to bind.
`include "apb/typedef.svh"

module sim_padframe_tb_apb (
  input  logic        clk_i,
  input  logic        rst_ni,

  // Flattened APB4 config bus
  input  logic [31:0] apb_paddr,
  input  logic        apb_psel,
  input  logic        apb_penable,
  input  logic        apb_pwrite,
  input  logic [31:0] apb_pwdata,
  input  logic [3:0]  apb_pstrb,
  output logic [31:0] apb_prdata,
  output logic        apb_pready,
  output logic        apb_pslverr,

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

  // Concrete APB4 subordinate structs bound to the toplevel `parameter type` ports.
  `APB_TYPEDEF_ALL(apb, logic [31:0], logic [31:0], logic [3:0])
  apb_req_t  config_apb_req;
  apb_resp_t config_apb_rsp;

  assign config_apb_req.paddr   = apb_paddr;
  assign config_apb_req.pprot   = '0;
  assign config_apb_req.psel    = apb_psel;
  assign config_apb_req.penable = apb_penable;
  assign config_apb_req.pwrite  = apb_pwrite;
  assign config_apb_req.pwdata  = apb_pwdata;
  assign config_apb_req.pstrb   = apb_pstrb;
  assign apb_prdata  = config_apb_rsp.prdata;
  assign apb_pready  = config_apb_rsp.pready;
  assign apb_pslverr = config_apb_rsp.pslverr;

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
    .apb_req_t(apb_req_t),
    .apb_resp_t(apb_resp_t)
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
    .config_apb_req_i(config_apb_req),
    .config_apb_rsp_o(config_apb_rsp)
  );
endmodule
