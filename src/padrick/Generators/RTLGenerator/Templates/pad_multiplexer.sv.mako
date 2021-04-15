% for line in header_text.splitlines():
// ${line}
% endfor
module ${padframe.name}_${pad_domain.name}_muxer
  import pkg_internal_${padframe.name}_${pad_domain.name}::*;
  import pkg_${padframe.name}::*;
  import ${padframe.name}_${pad_domain.name}_config_reg_pkg::*;
#(
  parameter type              req_t  = logic, // reg_interface request type
  parameter type             resp_t  = logic // reg_interface response type
) (
  input logic clk_i,
  input logic rst_ni,
% if any([port_group.port_signals_soc2pads for port_group in pad_domain.port_groups]):
  input pad_domain_${pad_domain.name}_ports_soc2pad_t port_signals_soc2pad_i,
% endif
% if any([port_group.port_signals_pads2soc for port_group in pad_domain.port_groups]):
  output pad_domain_${pad_domain.name}_ports_pad2soc_t port_signals_pad2soc_o,
% endif
% if any([pad.dynamic_pad_signals_soc2pad for pad in pad_domain.pad_list]):
  output mux_to_pads_t mux_to_pads_o,
% endif
% if any([pad.dynamic_pad_signals_soc2pad for pad in pad_domain.pad_list]):
  input pads_to_mux_t pads_to_mux_i,
% endif
  // Configuration interface using register_interface protocol
  input req_t config_req_i,
  output resp_t config_rsp_o
);
   // Connections between register file and pads
% if pad_domain.dynamic_pad_signals_soc2pad:
     ${padframe.name}_${pad_domain.name}_config_reg2hw_t s_reg2hw;
% endif

  // Register File Instantiation
  ${padframe.name}_${pad_domain.name}_config_reg_top #(
    .reg_req_t(req_t),
    .reg_rsp_t(resp_t)
    ) i_regfile (
    .clk_i,
    .rst_ni,
% if pad_domain.dynamic_pad_signals_soc2pad:
    .reg2hw(s_reg2hw),
% endif
    .reg_req_i(config_req_i),
    .reg_rsp_o(config_rsp_o),
    .devmode_i(1'b1)
  );

<%
all_ports = [port for port_group in pad_domain.port_groups for port in port_group.ports]
# Remap the port signal names to the hierarchical identifier for index the
# signal from the struct
signal_name_remap = {}
for port_group in pad_domain.port_groups:
    signal_name_remap[port_group.name] = {port_signal.name : f"port_signals_soc2pad_i.{port_group.name}.{port_signal.name}" for port_signal in port_group.port_signals_soc2pads}
%>
   // SoC -> Pad Multiplex Logic
% for pad in pad_domain.pad_list:
<%
   import math
   sel_bitwidth = round(math.log2(len(all_ports)+1))
%>\
% if pad.dynamic_pad_signals_soc2pad:
   // Pad ${pad.name}
% for pad_signal in pad.dynamic_pad_signals_soc2pad:
   // Pad Signal ${pad_signal.name}
   always_comb begin
     unique case (s_reg2hw.${pad.name}_mux_sel.q)
       PAD_MUX_GROUP_${pad.mux_group_name}_SEL_DEFAULT: begin
         mux_to_pads_o.${pad.name}.${pad_signal.name} = s_reg2hw.${pad.name}_cfg.${pad_signal.name}.q;
       end
% for port_group in pad_domain.port_groups:
% for port in port_group.get_ports_in_mux_groups(pad.mux_groups):
       PAD_MUX_GROUP_${pad.mux_group_name}_SEL_${port_group.name.upper()}_${port.name.upper()}: begin
% if pad_signal in port.connections and not port.connections[pad_signal].is_empty:
          mux_to_pads_o.${pad.name}.${pad_signal.name} = ${port.connections[pad_signal].get_mapped_expr(signal_name_remap[port_group.name]).expression};
% else:
          mux_to_pads_o.${pad.name}.${pad_signal.name} = s_reg2hw.${pad.name}_cfg.${pad_signal.name}.q;
% endif
       end
% endfor
% endfor
       default: begin
         mux_to_pads_o.${pad.name}.${pad_signal.name} = s_reg2hw.${pad.name}_cfg.${pad_signal.name}.q;
       end
     endcase
   end // always_comb

% endfor
% endif
% endfor

  // Pad -> SoC Multiplex Logic
% if any(port_group.port_signals_pads2soc for port_group in pad_domain.port_groups):
% for port_group in pad_domain.port_groups:
% if port_group.port_signals_pads2soc:
  // Port Group ${port_group.name}
% for port in port_group.ports:
<%
dynamic_pads = pad_domain.get_dynamic_pads_in_mux_groups(port.mux_groups)
%>
% for port_signal in port.port_signals_pad2chip:
  // Port Signal ${port_signal.name}
  logic [${len(dynamic_pads)-1}:0] port_mux_sel_${port_group.name}_${port_signal.name}_req;
  logic [PORT_MUX_GROUP_${port.mux_group_name}_SEL_WIDTH-1:0] port_mux_sel_${port_group.name}_${port_signal.name}_arbitrated;
  logic port_mux_sel_${port_group.name}_${port_signal.name}_no_connection;

% for pad in dynamic_pads:
   assign port_mux_sel_${port_group.name}_${port_signal.name}_req[PORT_MUX_GROUP_${port.mux_group_name}_SEL_${pad.name.upper()}] = s_reg2hw.${pad.name}_mux_sel.q == PAD_MUX_GROUP_${pad.mux_group_name}_SEL_${port_group.name.upper()}_${port.name.upper()} ? 1'b1 : 1'b0;
% endfor

   lzc #(
     .WIDTH(${len(dynamic_pads)}),
     .MODE(1'b0)
   ) i_port_muxsel_${port_group.name}_${port_signal.name}_arbiter (
     .in_i(port_mux_sel_${port_group.name}_${port_signal.name}_req),
     .cnt_o(port_mux_sel_${port_group.name}_${port_signal.name}_arbitrated),
     .empty_o(port_mux_sel_${port_group.name}_${port_signal.name}_no_connection)
   );

   always_comb begin
     if (port_mux_sel_${port_group.name}_${port_signal.name}_no_connection) begin
        port_signals_pad2soc_o.${port_group.name}.${port_signal.name} = ${port_group.output_defaults[port_signal].expression};
     end else begin
        unique case (port_mux_sel_${port_group.name}_${port_signal.name}_arbitrated)
% for pad in dynamic_pads:
<%
  pad_signal_remapping = {pad_signal.name : f"pads_to_mux_i.{pad.name}.{pad_signal.name}" for pad_signal in pad.dynamic_pad_signals_pad2soc}
%>\
          PORT_MUX_GROUP_${port.mux_group_name}_SEL_${pad.name.upper()}: begin
% if port_signal in port.connections:
            port_signals_pad2soc_o.${port_group.name}.${port_signal.name} = ${port.connections[port_signal].get_mapped_expr(pad_signal_remapping).expression};
% else:
            port_signals_pad2soc_o.${port_group.name}.${port_signal.name} = ${port_group.output_defaults[port_signal].expression};
% endif
          end
% endfor
          default: begin
            port_signals_pad2soc_o.${port_group.name}.${port_signal.name} = ${port_group.output_defaults[port_signal].expression};
          end
       endcase
     end
   end

% endfor
% endfor
% endif
% endfor
% endif
endmodule : ${padframe.name}_${pad_domain.name}_muxer
