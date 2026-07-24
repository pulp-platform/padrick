## Copyright 2021-2022 ETH Zurich.
## Licensed under the Apache License, Version 2.0, see LICENSE for details.
## SPDX-License-Identifier: Apache-2.0
## Author: Manuel Eggimann, ETH Zurich
## Author: Kai Berszin, ETH Zurich
<%!
from padrick.Generators.RTLGenerator.PeakRDLShim import (
    cfg_base, frontend_param_ports, frontend_param_connections, frontend_signal_ports,
    regblock_inst_params, regblock_cpuif_connections, cpuif_intermediate_decls,
    cpuif_unpack_lines, obi_id_width_expr)
%>\
<%def name="domain_signal_connections(pad_domain)">\
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
</%def>\

% for line in header_text.splitlines():
// ${line}
% endfor
<%
  backend = register_backend
  frontend = padframe.config_interface.value
  topology = padframe.config_port_topology.value
%>\
module ${padframe.name}
  import pkg_${padframe.name}::*;
% if backend == "peakrdl" and topology == "shared":
  import ${padframe.name}_config_reg_pkg::*;
% endif
#(
  parameter int unsigned   AW = 32,
  parameter int unsigned   DW = 32,
% if backend == "reggen":
  parameter type req_t = logic, // reg_interface request type
  parameter type resp_t = logic, // reg_interface response type
% else:
${",\n".join(frontend_param_ports(frontend))},
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
% if backend == "reggen":
  input req_t                                config_req_i,
  output resp_t                              config_rsp_o
% else:
<%
  cfg_lines = []
  if topology == "shared":
      cfg_lines = frontend_signal_ports(frontend, cfg_base("shared", None, frontend))
  else:
      for pad_domain in padframe.pad_domains:
          cfg_lines += frontend_signal_ports(frontend, cfg_base("per_domain", pad_domain.name, frontend))
%>\
${",\n".join(cfg_lines)}
% endif
  );
% if backend == "reggen":


% for pad_domain in padframe.pad_domains:
  req_t ${pad_domain.name}_config_req;
  resp_t ${pad_domain.name}_config_resp;
  ${padframe.name}_${pad_domain.name} #(
    .req_t(req_t),
    .resp_t(resp_t)
  ) i_${pad_domain.name} (
${domain_signal_connections(pad_domain)}\
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
   // Fusion Compiler (Presto) cannot member-select the parameter-type config_req_i in a
   // port connection, so hoist the address slice into a procedural signal first.
   logic [REG_ADDR_WIDTH-1:0] config_req_addr;
   always_comb config_req_addr = config_req_i.addr[REG_ADDR_WIDTH-1:0];
   addr_decode #(
       .NoIndices(NUM_PAD_DOMAINS+1),
       .NoRules(NUM_PAD_DOMAINS),
       .addr_t(logic[REG_ADDR_WIDTH-1:0]),
       .rule_t(addr_rule_t)
     ) i_addr_decode(
       .addr_i(config_req_addr),
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
       .in_req_i(config_req_i),
       .in_rsp_o(config_rsp_o),
       .out_req_o({error_slave_req, ${config_req_o_collection}}),
       .out_rsp_i({error_slave_rsp, ${config_resp_i_collection}})
     );

     // Procedural for the same Presto reason as config_req_addr above.
     always_comb begin
       error_slave_rsp.error = 1'b1;
       error_slave_rsp.rdata = DecodeErrRespData;
       error_slave_rsp.ready = 1'b1;
     end

endmodule
% elif topology == "shared":
<%
  reg_module = f"{padframe.name}_config_reg_top"
  reg_pkg = f"{padframe.name}_config_reg_pkg"
  addr_param = f"{reg_pkg}::{reg_module.upper()}_MIN_ADDR_WIDTH"
  base = cfg_base("shared", None, frontend)
  req = f"{base}_req_i"
  rsp = f"{base}_rsp_o"
  inst_params = regblock_inst_params(frontend)
  param_block = " #(\n" + ",\n".join(inst_params) + "\n  ) " if inst_params else " "
  decls = cpuif_intermediate_decls(frontend, addr_param)
  unpack = cpuif_unpack_lines(frontend, req, rsp, addr_param)
  cpuif = regblock_cpuif_connections(frontend)
%>
  // Single flattened register block for the whole padframe. Registers live at the top level so
  // they retain their configuration across power cycling of individual pad domains. PeakRDL wants
  // an active-high sync reset, so invert the active-low rst_ni here.
  ${padframe.name}_config__out_t s_hwif;
% if frontend == "obi":
  localparam int unsigned CpuifObiIdWidth = ${obi_id_width_expr(req)};
% endif
  // Fusion Compiler (Presto) cannot member-select a parameter-type signal in a port
  // connection, so unpack the cpuif structs into plain signals procedurally first.
${"\n".join(decls)}
  always_comb begin
${"\n".join(unpack)}
  end
  ${reg_module}${param_block}i_config_regfile (
    .clk(clk_i),
    .rst(~rst_ni),
${",\n".join(cpuif)},
    .hwif_out(s_hwif)
  );

% for pad_domain in padframe.pad_domains:
  ${padframe.name}_${pad_domain.name} i_${pad_domain.name} (
${domain_signal_connections(pad_domain)}\
   .hwif_i(s_hwif.${pad_domain.name})
  );

% endfor
endmodule
% else:

% for pad_domain in padframe.pad_domains:
<% base = cfg_base("per_domain", pad_domain.name, frontend) %>\
  ${padframe.name}_${pad_domain.name} #(
${",\n".join(frontend_param_connections(frontend))}
  ) i_${pad_domain.name} (
${domain_signal_connections(pad_domain)}\
   .${base}_req_i(${base}_req_i),
   .${base}_rsp_o(${base}_rsp_o)
  );

% endfor
endmodule
% endif
