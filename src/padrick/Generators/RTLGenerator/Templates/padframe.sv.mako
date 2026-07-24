<%!
def _cfg_base(topology, domain, frontend):
    proto = "axi" if frontend == "axilite" else frontend
    if topology == "shared":
        return "config" if frontend == "regbus" else f"config_{proto}"
    return f"{domain}_config" if frontend == "regbus" else f"{domain}_{proto}"


def _frontend_port_lines(frontend, base):
    if frontend == "regbus":
        return [f"  input req_t                                {base}_req_i",
                f"  output resp_t                              {base}_rsp_o"]
    if frontend == "apb":
        return [f"  input apb_req_t                            {base}_req_i",
                f"  output apb_resp_t                          {base}_rsp_o"]
    if frontend == "axilite":
        return [f"  input axi_lite_req_t                       {base}_req_i",
                f"  output axi_lite_resp_t                     {base}_rsp_o"]
    # obi: official pulp-platform OBI request/response structs
    return [f"  input obi_req_t                            {base}_req_i",
            f"  output obi_rsp_t                           {base}_rsp_o"]


def _converter_lines(frontend, base, inst, req_wire, rsp_wire):
    """Lines instantiating the selected frontend->register_interface converter."""
    if frontend == "apb":
        return [f"  apb_to_reg_v2 #(",
                f"    .reg_req_t(req_t),",
                f"    .reg_rsp_t(resp_t)",
                f"  ) {inst} (",
                f"    .clk_i,",
                f"    .rst_ni,",
                f"    .penable_i({base}_req_i.penable),",
                f"    .pwrite_i({base}_req_i.pwrite),",
                f"    .paddr_i({base}_req_i.paddr),",
                f"    .psel_i({base}_req_i.psel),",
                f"    .pwdata_i({base}_req_i.pwdata),",
                f"    .prdata_o({base}_rsp_o.prdata),",
                f"    .pready_o({base}_rsp_o.pready),",
                f"    .pslverr_o({base}_rsp_o.pslverr),",
                f"    .reg_req_o({req_wire}),",
                f"    .reg_rsp_i({rsp_wire})",
                f"  );"]
    if frontend == "axilite":
        return [f"  axi_lite_to_reg #(",
                f"    .ADDR_WIDTH(AW),",
                f"    .DATA_WIDTH(DW),",
                f"    .axi_lite_req_t(axi_lite_req_t),",
                f"    .axi_lite_rsp_t(axi_lite_resp_t),",
                f"    .reg_req_t(req_t),",
                f"    .reg_rsp_t(resp_t)",
                f"  ) {inst} (",
                f"    .clk_i,",
                f"    .rst_ni,",
                f"    .axi_lite_req_i({base}_req_i),",
                f"    .axi_lite_rsp_o({base}_rsp_o),",
                f"    .reg_req_o({req_wire}),",
                f"    .reg_rsp_i({rsp_wire})",
                f"  );"]
    # obi via periph_to_reg
    return [f"  // OBI is used here in its implicit-ready subset: the register interface is always",
            f"  // ready, so the OBI rready field is unused and err maps onto periph r_opc.",
            f"  // periph_to_reg's wen_i is write-enable-low, so invert the write-high OBI we.",
            f"  periph_to_reg #(",
            f"    .AW(AW),",
            f"    .DW(DW),",
            f"    .BW(8),",
            f"    .IW($bits({base}_req_i.a.aid)),",
            f"    .req_t(req_t),",
            f"    .rsp_t(resp_t)",
            f"  ) {inst} (",
            f"    .clk_i,",
            f"    .rst_ni,",
            f"    .req_i({base}_req_i.req),",
            f"    .add_i({base}_req_i.a.addr),",
            f"    .wen_i(~{base}_req_i.a.we),",
            f"    .wdata_i({base}_req_i.a.wdata),",
            f"    .be_i({base}_req_i.a.be),",
            f"    .id_i({base}_req_i.a.aid),",
            f"    .gnt_o({base}_rsp_o.gnt),",
            f"    .r_rdata_o({base}_rsp_o.r.rdata),",
            f"    .r_opc_o({base}_rsp_o.r.err),",
            f"    .r_id_o({base}_rsp_o.r.rid),",
            f"    .r_valid_o({base}_rsp_o.rvalid),",
            f"    .reg_req_o({req_wire}),",
            f"    .reg_rsp_i({rsp_wire})",
            f"  );"]


def _converter_inst(prefix, frontend):
    proto = "axi_lite" if frontend == "axilite" else frontend
    return f"i_{prefix}_{proto}_to_reg"
%>\
## Copyright 2021-2022 ETH Zurich.
## Licensed under the Apache License, Version 2.0, see LICENSE for details.
## SPDX-License-Identifier: Apache-2.0
## Author: Manuel Eggimann, ETH Zurich
## Author: Kai Berszin, ETH Zurich

% for line in header_text.splitlines():
// ${line}
% endfor
<%
  config_interface = padframe.config_interface.value
  topology = padframe.config_port_topology.value
  if config_interface == "regbus":
      shared_fabric_req = "config_req_i"
      shared_fabric_rsp = "config_rsp_o"
  else:
      shared_fabric_req = "s_config_req"
      shared_fabric_rsp = "s_config_resp"
%>\
module ${padframe.name}
  import pkg_${padframe.name}::*;
#(
  parameter int unsigned   AW = 32,
  parameter int unsigned   DW = 32,
  parameter type req_t = logic, // reg_interface request type
  parameter type resp_t = logic, // reg_interface response type
% if config_interface == "apb":
  parameter type apb_req_t = logic, // APB4 subordinate request struct type
  parameter type apb_resp_t = logic, // APB4 subordinate response struct type
% elif config_interface == "axilite":
  parameter type axi_lite_req_t = logic, // AXI4-Lite subordinate request struct type
  parameter type axi_lite_resp_t = logic, // AXI4-Lite subordinate response struct type
% elif config_interface == "obi":
  parameter type obi_req_t = logic, // OBI subordinate request struct type
  parameter type obi_rsp_t = logic, // OBI subordinate response struct type
% endif
  parameter logic [DW-1:0] DecodeErrRespData = 32'hdeadda7a
)(
  input logic                                clk_i,
  input logic                                rst_ni,
% if any([pad_domain.override_signals for pad_domain in padframe.pad_domains]):
  input override_signals_t                   override_signals,
% endif
% if any([pad_domain.static_connection_signals_pad2soc for pad_domain in padframe.pad_domains]):
  output static_connection_signals_pad2soc_t static_connection_signals_pad2soc,
% endif
% if any([pad_domain.static_connection_signals_soc2pad for pad_domain in padframe.pad_domains]):
  input  static_connection_signals_soc2pad_t static_connection_signals_soc2pad,
% endif
% if any([port_group.port_signals_soc2pads for pad_domain in padframe.pad_domains for port_group in pad_domain.port_groups]):
  output port_signals_pad2soc_t              port_signals_pad2soc,
% endif
% if any([port_group.port_signals_soc2pads for pad_domain in padframe.pad_domains for port_group in pad_domain.port_groups]):
  input port_signals_soc2pad_t               port_signals_soc2pad,
% endif
  // Landing Pads
% for pad_domain in padframe.pad_domains:
% for pad in pad_domain.pad_list:
% for i in range(pad.multiple):
<% pad_suffix = i if pad.multiple > 1 else "" %>\
% for signal in pad.landing_pads:
  inout wire logic                           pad_${pad_domain.name}_${pad.name}${pad_suffix}_${signal.name},
% endfor
% endfor
% endfor
% endfor
  // Config Interface
<%
  cfg_lines = []
  if topology == "shared":
      cfg_lines = _frontend_port_lines(config_interface, _cfg_base("shared", None, config_interface))
  else:
      for pad_domain in padframe.pad_domains:
          cfg_lines += _frontend_port_lines(config_interface, _cfg_base("per_domain", pad_domain.name, config_interface))
%>\
${",\n".join(cfg_lines)}
  );

% if topology == "shared":

% if config_interface != "regbus":
  req_t ${shared_fabric_req};
  resp_t ${shared_fabric_rsp};
${"\n".join(_converter_lines(config_interface, _cfg_base("shared", None, config_interface), _converter_inst("config", config_interface), shared_fabric_req, shared_fabric_rsp))}

% endif
% for pad_domain in padframe.pad_domains:
  req_t ${pad_domain.name}_config_req;
  resp_t ${pad_domain.name}_config_resp;
  ${padframe.name}_${pad_domain.name} #(
    .req_t(req_t),
    .resp_t(resp_t)
  ) i_${pad_domain.name} (
   .clk_i,
   .rst_ni,
% if pad_domain.override_signals:
   .override_signals_i(override_signals.${pad_domain.name}),
% endif
% if pad_domain.static_connection_signals_pad2soc:
   .static_connection_signals_pad2soc(static_connection_signals_pad2soc.${pad_domain.name}),
% endif
% if pad_domain.static_connection_signals_soc2pad:
   .static_connection_signals_soc2pad(static_connection_signals_soc2pad.${pad_domain.name}),
% endif
% if any([port_group.port_signals_pads2soc for port_group in pad_domain.port_groups]):
   .port_signals_pad2soc_o(port_signals_pad2soc.${pad_domain.name}),
% endif
% if any([port_group.port_signals_soc2pads for port_group in pad_domain.port_groups]):
   .port_signals_soc2pad_i(port_signals_soc2pad.${pad_domain.name}),
% endif
% for pad in pad_domain.pad_list:
% for i in range(pad.multiple):
<% pad_suffix = i if pad.multiple > 1 else "" %>\
% for signal in pad.landing_pads:
   .pad_${pad.name}${pad_suffix}_${signal.name}(pad_${pad_domain.name}_${pad.name}${pad_suffix}_${signal.name}),
% endfor
% endfor
% endfor
   .config_req_i(${pad_domain.name}_config_req),
   .config_rsp_o(${pad_domain.name}_config_resp)
  );

% endfor
<%
  import math
  config_req_o_collection    = ", ".join(f"{pad_domain.name}_config_req" for pad_domain in reversed(padframe.pad_domains))
  config_resp_i_collection = ", ".join(f"{pad_domain.name}_config_resp" for pad_domain in reversed(padframe.pad_domains))
  reg_addr_width = math.ceil(math.log2(address_space_size+1))
  num_pad_domains = len(padframe.pad_domains)
%>
   localparam int unsigned NUM_PAD_DOMAINS = ${num_pad_domains};
   localparam int unsigned REG_ADDR_WIDTH = ${reg_addr_width};
   typedef struct packed {
      int unsigned idx;
      logic [REG_ADDR_WIDTH-1:0] start_addr;
      logic [REG_ADDR_WIDTH-1:0] end_addr;
   } addr_rule_t;

   localparam addr_rule_t[NUM_PAD_DOMAINS-1:0] ADDR_DEMUX_RULES = '{
% for idx, pad_domain in enumerate(padframe.pad_domains):
     '{ idx: ${idx}, start_addr: ${reg_addr_width}'d${address_ranges[pad_domain.name][0]},  end_addr: ${reg_addr_width}'d${address_ranges[pad_domain.name][1]}}${"," if idx != num_pad_domains-1 else ""}
% endfor
     };
   logic[$clog2(NUM_PAD_DOMAINS+1)-1:0] pad_domain_sel; // +1 since there is an additional error slave
   addr_decode #(
       .NoIndices(NUM_PAD_DOMAINS+1),
       .NoRules(NUM_PAD_DOMAINS),
       .addr_t(logic[REG_ADDR_WIDTH-1:0]),
       .rule_t(addr_rule_t)
     ) i_addr_decode(
       .addr_i(${shared_fabric_req}.addr[REG_ADDR_WIDTH-1:0]),
       .addr_map_i(ADDR_DEMUX_RULES),
       .dec_valid_o(),
       .dec_error_o(),
       .idx_o(pad_domain_sel),
       .en_default_idx_i(1'b1),
       .default_idx_i(${math.ceil(math.log2(num_pad_domains+1))}'d${num_pad_domains}) // The last entry is the error slave
     );

     req_t error_slave_req;
     resp_t error_slave_rsp;

     // Config Interface demultiplexing
     reg_demux #(
       .NoPorts(NUM_PAD_DOMAINS+1), //+1 for the error slave
       .req_t(req_t),
       .rsp_t(resp_t)
     ) i_config_demuxer (
       .clk_i,
       .rst_ni,
       .in_select_i(pad_domain_sel),
       .in_req_i(${shared_fabric_req}),
       .in_rsp_o(${shared_fabric_rsp}),
       .out_req_o({error_slave_req, ${config_req_o_collection}}),
       .out_rsp_i({error_slave_rsp, ${config_resp_i_collection}})
     );

     assign error_slave_rsp.error = 1'b1;
     assign error_slave_rsp.rdata = DecodeErrRespData;
     assign error_slave_rsp.ready = 1'b1;

endmodule
% else:
% for pad_domain in padframe.pad_domains:
<%
  d = pad_domain.name
  if config_interface == "regbus":
      reqsig = f"{d}_config_req_i"
      rspsig = f"{d}_config_rsp_o"
  else:
      reqsig = f"{d}_config_req"
      rspsig = f"{d}_config_resp"
%>\
% if config_interface != "regbus":
  req_t ${reqsig};
  resp_t ${rspsig};
${"\n".join(_converter_lines(config_interface, _cfg_base("per_domain", d, config_interface), _converter_inst(d, config_interface), reqsig, rspsig))}
% endif
  ${padframe.name}_${pad_domain.name} #(
    .req_t(req_t),
    .resp_t(resp_t)
  ) i_${pad_domain.name} (
   .clk_i,
   .rst_ni,
% if pad_domain.override_signals:
   .override_signals_i(override_signals.${pad_domain.name}),
% endif
% if pad_domain.static_connection_signals_pad2soc:
   .static_connection_signals_pad2soc(static_connection_signals_pad2soc.${pad_domain.name}),
% endif
% if pad_domain.static_connection_signals_soc2pad:
   .static_connection_signals_soc2pad(static_connection_signals_soc2pad.${pad_domain.name}),
% endif
% if any([port_group.port_signals_pads2soc for port_group in pad_domain.port_groups]):
   .port_signals_pad2soc_o(port_signals_pad2soc.${pad_domain.name}),
% endif
% if any([port_group.port_signals_soc2pads for port_group in pad_domain.port_groups]):
   .port_signals_soc2pad_i(port_signals_soc2pad.${pad_domain.name}),
% endif
% for pad in pad_domain.pad_list:
% for i in range(pad.multiple):
<% pad_suffix = i if pad.multiple > 1 else "" %>\
% for signal in pad.landing_pads:
   .pad_${pad.name}${pad_suffix}_${signal.name}(pad_${pad_domain.name}_${pad.name}${pad_suffix}_${signal.name}),
% endfor
% endfor
% endfor
   .config_req_i(${reqsig}),
   .config_rsp_o(${rspsig})
  );

% endfor
endmodule
% endif
