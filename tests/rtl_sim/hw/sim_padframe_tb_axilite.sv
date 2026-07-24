// Copyright 2026 ETH Zurich.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
// Author: Kai Berszin, ETH Zurich

// AXI4-Lite variant of the cocotb-facing padframe wrapper. Identical pad/port
// flattening to sim_padframe_tb_top.sv; only the config bus differs: it binds
// the toplevel `parameter type axi_lite_req_t/axi_lite_resp_t` ports to concrete
// AXI4-Lite structs (via the axi repo's AXI_LITE_TYPEDEF macros) and flattens
// the aw/w/b/ar/r channels to scalars.
`include "axi/typedef.svh"

module sim_padframe_tb_axilite (
  input  logic        clk_i,
  input  logic        rst_ni,

  // Flattened AXI4-Lite config bus (write channels)
  input  logic [31:0] axi_aw_addr,
  input  logic        axi_aw_valid,
  output logic        axi_aw_ready,
  input  logic [31:0] axi_w_data,
  input  logic [3:0]  axi_w_strb,
  input  logic        axi_w_valid,
  output logic        axi_w_ready,
  output logic [1:0]  axi_b_resp,
  output logic        axi_b_valid,
  input  logic        axi_b_ready,
  // Read channels
  input  logic [31:0] axi_ar_addr,
  input  logic        axi_ar_valid,
  output logic        axi_ar_ready,
  output logic [31:0] axi_r_data,
  output logic [1:0]  axi_r_resp,
  output logic        axi_r_valid,
  input  logic        axi_r_ready,

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

  // Concrete AXI4-Lite subordinate structs bound to the toplevel ports.
  `AXI_LITE_TYPEDEF_ALL(axi_lite, logic [31:0], logic [31:0], logic [3:0])
  axi_lite_req_t  config_axi_req;
  axi_lite_resp_t config_axi_rsp;

  assign config_axi_req.aw.addr = axi_aw_addr;
  assign config_axi_req.aw.prot = '0;
  assign config_axi_req.aw_valid = axi_aw_valid;
  assign config_axi_req.w.data  = axi_w_data;
  assign config_axi_req.w.strb  = axi_w_strb;
  assign config_axi_req.w_valid = axi_w_valid;
  assign config_axi_req.b_ready = axi_b_ready;
  assign config_axi_req.ar.addr = axi_ar_addr;
  assign config_axi_req.ar.prot = '0;
  assign config_axi_req.ar_valid = axi_ar_valid;
  assign config_axi_req.r_ready = axi_r_ready;

  assign axi_aw_ready = config_axi_rsp.aw_ready;
  assign axi_w_ready  = config_axi_rsp.w_ready;
  assign axi_b_resp   = config_axi_rsp.b.resp;
  assign axi_b_valid  = config_axi_rsp.b_valid;
  assign axi_ar_ready = config_axi_rsp.ar_ready;
  assign axi_r_data   = config_axi_rsp.r.data;
  assign axi_r_resp   = config_axi_rsp.r.resp;
  assign axi_r_valid  = config_axi_rsp.r_valid;

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
    .axi_lite_req_t(axi_lite_req_t),
    .axi_lite_resp_t(axi_lite_resp_t)
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
    .config_axi_req_i(config_axi_req),
    .config_axi_rsp_o(config_axi_rsp)
  );
endmodule
