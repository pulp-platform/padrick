## Copyright 2021-2022 ETH Zurich.
## Licensed under the Apache License, Version 2.0, see LICENSE for details.
## SPDX-License-Identifier: Apache-2.0
## Author: Manuel Eggimann, ETH Zurich
## Author: Kai Berszin, ETH Zurich
<%!
from padrick.Generators.RTLGenerator.PeakRDLShim import (
    cfg_base, frontend_param_ports, frontend_signal_ports,
    regblock_inst_params, regblock_cpuif_connections, cpuif_intermediate_decls,
    cpuif_unpack_lines, obi_id_width_expr)
%>\
<%
  backend = register_backend
  frontend = padframe.config_interface.value
  topology = padframe.config_port_topology.value
  hwif_type = f"{padframe.name}_{pad_domain.name}_config__out_t"
  if backend == "peakrdl" and topology == "shared":
      reg_pkg = f"{padframe.name}_config_reg_pkg"
  else:
      reg_pkg = f"{padframe.name}_{pad_domain.name}_config_reg_pkg"
  # per_domain: this domain owns a regblock; its cpuif hangs off the domain's frontend port.
  domain_base = cfg_base("per_domain", pad_domain.name, frontend)
  reg_module = f"{padframe.name}_{pad_domain.name}_config_reg_top"
  addr_width_param = f"{reg_pkg}::{reg_module.upper()}_MIN_ADDR_WIDTH"
  if backend == "reggen":
      mux_handle = None
  elif topology == "shared":
      mux_handle = "hwif_i"
  else:
      mux_handle = "s_hwif"
%>\

% for line in header_text.splitlines():
// ${line}
% endfor
module ${padframe.name}_${pad_domain.name}
  import pkg_${padframe.name}::*;
  import pkg_internal_${padframe.name}_${pad_domain.name}::*;
% if backend == "peakrdl":
  import ${reg_pkg}::*;
% endif
% if backend == "reggen":
#(
  parameter type              req_t  = logic, // reg_interface request type
  parameter type             resp_t  = logic // reg_interface response type
) (
% elif topology != "shared":
#(
${",\n".join(frontend_param_ports(frontend))}
) (
% else:
(
% endif
  input logic clk_i,
  input logic rst_ni,
% if pad_domain.override_signals:
  input pad_domain_${pad_domain.name}_override_signals_t override_signals_i,
% endif
% if pad_domain.static_connection_signals_pad2soc:
  output pad_domain_${pad_domain.name}_static_connection_signals_pad2soc_t static_connection_signals_pad2soc,
% endif
% if pad_domain.static_connection_signals_soc2pad:
  input pad_domain_${pad_domain.name}_static_connection_signals_soc2pad_t static_connection_signals_soc2pad,
% endif
% if any([port_group.port_signals_pads2soc for port_group in pad_domain.port_groups]):
  output pad_domain_${pad_domain.name}_ports_pad2soc_t port_signals_pad2soc_o,
% endif
% if any([port_group.port_signals_soc2pads for port_group in pad_domain.port_groups]):
  input pad_domain_${pad_domain.name}_ports_soc2pad_t port_signals_soc2pad_i,
% endif
% for pad in pad_domain.pad_list:
% for i in range(pad.multiple):
<% pad_suffix = i if pad.multiple > 1 else "" %>\
% for signal in pad.landing_pads:
  inout wire logic pad_${pad.name}${pad_suffix}_${signal.name},
% endfor
% endfor
% endfor
% if backend == "reggen":
  input req_t config_req_i,
  output resp_t config_rsp_o
% elif topology == "shared":
  // Configuration interface: register block hardware interface (PeakRDL hwif) routed from the top
  input ${hwif_type} hwif_i
% else:
  // Configuration interface: native ${frontend} cpuif of this domain's register block
${",\n".join(frontend_signal_ports(frontend, domain_base))}
% endif
);

% if any([pad.dynamic_pad_signals_soc2pad for pad in pad_domain.pad_list]):
   mux_to_pads_t s_mux_to_pads;
% endif
% if any([pad.dynamic_pad_signals_pad2soc for pad in pad_domain.pad_list]):
   pads_to_mux_t s_pads_to_mux;

% endif
   ${padframe.name}_${pad_domain.name}_pads i_${pad_domain.name}_pads (
% if pad_domain.override_signals:
     .override_signals_i,
% endif
% if pad_domain.static_connection_signals_pad2soc:
     .static_connection_signals_pad2soc,
% endif
% if pad_domain.static_connection_signals_soc2pad:
     .static_connection_signals_soc2pad,
% endif
% if any([pad.dynamic_pad_signals_soc2pad for pad in pad_domain.pad_list]):
     .mux_to_pads_i(s_mux_to_pads),
% endif
% if any([pad.dynamic_pad_signals_pad2soc for pad in pad_domain.pad_list]):
     .pads_to_mux_o(s_pads_to_mux),
% endif
<%
  port_list = []
  for pad in pad_domain.pad_list:
      for i in range(pad.multiple):
          pad_suffix = i if pad.multiple > 1 else ""
          for signal in pad.landing_pads:
              port_list.append(f".pad_{pad.name}{pad_suffix}_{signal.name}")
  ports = ",\n".join(port_list)
%>\
% for line in ports.splitlines():
     ${line}
% endfor

  );
% if backend == "peakrdl" and topology != "shared":
<%
  req = f"{domain_base}_req_i"
  rsp = f"{domain_base}_rsp_o"
  inst_params = regblock_inst_params(frontend)
  param_block = " #(\n" + ",\n".join(inst_params) + "\n   ) " if inst_params else " "
  decls = cpuif_intermediate_decls(frontend, addr_width_param)
  unpack = cpuif_unpack_lines(frontend, req, rsp, addr_width_param)
  cpuif = regblock_cpuif_connections(frontend)
%>\

   // Per-domain register block with its native ${frontend} cpuif. Registers live inside the
   // domain module (power-gated together with the domain). PeakRDL wants an active-high sync
   // reset, so invert the active-low rst_ni here.
   ${hwif_type} s_hwif;
% if frontend == "obi":
   localparam int unsigned CpuifObiIdWidth = ${obi_id_width_expr(req)};
% endif
   // Fusion Compiler (Presto) cannot member-select a parameter-type signal in a port
   // connection, so unpack the cpuif structs into plain signals procedurally first.
${"\n".join(decls)}
   always_comb begin
${"\n".join(unpack)}
   end
   ${reg_module}${param_block}i_regfile (
     .clk(clk_i),
     .rst(~rst_ni),
${",\n".join(cpuif)},
     .hwif_out(s_hwif)
   );
% endif

   ${padframe.name}_${pad_domain.name}_muxer ${"#(\n     .req_t(req_t),\n     .resp_t(resp_t)\n   )" if backend == "reggen" else ""}i_${pad_domain.name}_muxer (
     .clk_i,
     .rst_ni,
% if any([port_group.port_signals_soc2pads for port_group in pad_domain.port_groups]):
     .port_signals_soc2pad_i,
% endif
% if any([port_group.port_signals_pads2soc for port_group in pad_domain.port_groups]):
     .port_signals_pad2soc_o,
% endif
% if any([pad.dynamic_pad_signals_soc2pad for pad in pad_domain.pad_list]):
     .mux_to_pads_o(s_mux_to_pads),
% endif
% if any([pad.dynamic_pad_signals_soc2pad for pad in pad_domain.pad_list]):
     .pads_to_mux_i(s_pads_to_mux),
% endif
% if backend == "reggen":
     // Configuration interface using register_interface protocol
     .config_req_i,
     .config_rsp_o
% else:
     // Configuration interface: register block hardware interface (PeakRDL hwif)
     .hwif_i(${mux_handle})
% endif
   );

endmodule : ${padframe.name}_${pad_domain.name}
