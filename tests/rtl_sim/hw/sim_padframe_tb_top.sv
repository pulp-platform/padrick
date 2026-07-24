// Copyright 2026 ETH Zurich.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
// Author: Kai Berszin, ETH Zurich

// cocotb-facing wrapper around the generated `sim_padframe`. It binds the
// `parameter type req_t/resp_t` config-bus ports to concrete register_interface
// structs and flattens both the register bus and the packed port structs into
// plain scalar ports that the Verilator VPI (and thus cocotb) can drive/observe.
//
// Each bidirectional landing pad is exposed as three two-state signals:
//   <pad>_drv     value the testbench drives onto the pad
//   <pad>_drv_en  testbench driver enable (open-drain style; z when low)
//   <pad>_val     resolved pad value for observation
// The tristate net (DUT driver vs. testbench driver) is resolved inside this
// module so Verilator never sees a top-level inout.
module sim_padframe_tb_top (
  input  logic        clk_i,
  input  logic        rst_ni,

  // Flattened register_interface bus
  input  logic [31:0] reg_addr,
  input  logic        reg_write,
  input  logic [31:0] reg_wdata,
  input  logic [3:0]  reg_wstrb,
  input  logic        reg_valid,
  output logic [31:0] reg_rdata,
  output logic        reg_error,
  output logic        reg_ready,

  // Static connection outputs
  output logic        refclk,

  // periph port group (soc2pad inputs)
  input  logic        periph_pout_o,
  input  logic        periph_bo,
  input  logic        periph_boe,
  // periph port group (pad2soc outputs)
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

  // Concrete register_interface request/response types (field layout matches the
  // pulp-platform register_interface REG_BUS typedef consumed by the reg file).
  typedef struct packed {
    logic [31:0] addr;
    logic        write;
    logic [31:0] wdata;
    logic [3:0]  wstrb;
    logic        valid;
  } reg_req_t;

  typedef struct packed {
    logic [31:0] rdata;
    logic        error;
    logic        ready;
  } reg_rsp_t;

  reg_req_t config_req;
  reg_rsp_t config_rsp;

  assign config_req.addr  = reg_addr;
  assign config_req.write = reg_write;
  assign config_req.wdata = reg_wdata;
  assign config_req.wstrb = reg_wstrb;
  assign config_req.valid = reg_valid;
  assign reg_rdata = config_rsp.rdata;
  assign reg_error = config_rsp.error;
  assign reg_ready = config_rsp.ready;

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
    .req_t(reg_req_t),
    .resp_t(reg_rsp_t)
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
    .config_req_i(config_req),
    .config_rsp_o(config_rsp)
  );
endmodule
