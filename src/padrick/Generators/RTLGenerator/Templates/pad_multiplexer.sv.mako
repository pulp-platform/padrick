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
    .reg_rsp_o(config_rsp_o)
  );

<%
all_ports = [port for port_group in pad_domain.port_groups for port in port_group.ports]
%>
   // SoC -> Pad Multiplex Logic
% for pad in pad_domain.pad_list:
% for i in range(pad.multiple):
<%
   import math
   pad_suffix = i if pad.multiple > 1 else ""
   pad_subscript = f"[{i}]" if pad.multiple > 1 else ""
   sel_bitwidth = round(math.log2(len(all_ports)+1))
%>\
% if pad.dynamic_pad_signals_soc2pad:
   // Pad ${pad.name}${pad_suffix}
% for pad_signal in pad.dynamic_pad_signals_soc2pad:
   // Pad Signal ${pad_signal.name}
   always_comb begin
     unique case (s_reg2hw.${pad.name}_mux_sel${pad_subscript}.q)
       PAD_MUX_GROUP_${pad.mux_group.upper()}_SEL_DEFAULT: begin
         mux_to_pads_o.${pad.name}${pad_suffix}.${pad_signal.name} = s_reg2hw.${pad.name}_cfg${pad_subscript}.${pad_signal.name}.q;
       end
<% port_idx = 1 %>\
% for port_group in pad_domain.port_groups:
<%
   # Remap the port signal names to the hierarchical identifier for index the signal from the struct
   signal_name_remap = {port_signal.name : f"port_signals_soc2pad_i.{port_group.name}.{port_signal.name}" for port_signal in port_group.port_signals_soc2pads}
%>\
% for port in port_group.ports:
% if port.mux_group == pad.mux_group:
       PAD_MUX_GROUP_${pad.mux_group.upper()}_SEL_${port_group.name.upper()}_${port.name.upper()}: begin
% if pad_signal in port.connections and not port.connections[pad_signal].is_empty:
          mux_to_pads_o.${pad.name}${pad_suffix}.${pad_signal.name} = ${port.connections[pad_signal].get_mapped_expr(signal_name_remap).expression};
% else:
          mux_to_pads_o.${pad.name}${pad_suffix}.${pad_signal.name} = s_reg2hw.${pad.name}_cfg${pad_subscript}.${pad_signal.name}.q;
% endif
<% port_idx += 1 %>\
       end
% endif
% endfor
% endfor
       default: begin
         mux_to_pads_o.${pad.name}${pad_suffix}.${pad_signal.name} = s_reg2hw.${pad.name}_cfg${pad_subscript}.${pad_signal.name}.q;
       end
     endcase
   end // always_comb

% endfor
% endif
% endfor
% endfor

  // Pad -> SoC Multiplex Logic
% if any(port_group.port_signals_pads2soc for port_group in pad_domain.port_groups):
% for port_group in pad_domain.port_groups:
% if port_group.port_signals_pads2soc:
  // Port Group ${port_group.name}
% for port in port_group.ports:
<%
dynamic_pads = [pad for pad in pad_domain.pad_list if pad.dynamic_pad_signals if pad.mux_group == port.mux_group]
dynamic_pad_count = sum([pad.multiple for pad in dynamic_pads])
%>
% for port_signal in port.port_signals_pad2chip:
  // Port Signal ${port_signal.name}
  logic [${dynamic_pad_count-1}:0] port_mux_sel_req_${port_group.name}_${port_signal.name};
  logic [PORT_MUX_GROUP_${port.mux_group.upper()}_SEL_WIDTH-1:0] port_mux_sel_${port_group.name}_${port_signal.name};
  logic port_mux_sel_${port_group.name}_${port_signal.name}_no_connection;

% for pad in dynamic_pads:
% if pad.mux_group == port.mux_group:
% for i in range(pad.multiple):
<%
   pad_subscript = f"[{i}]" if pad.multiple > 1 else ""
   pad_suffix = i if pad.multiple > 1 else ""
%>\
   assign port_mux_sel_req_${port_group.name}_${port_signal.name}[PORT_MUX_GROUP_${port.mux_group.upper()}_SEL_${pad.name.upper()}${pad_suffix}] = s_reg2hw.${pad.name}_mux_sel${pad_subscript}.q == PAD_MUX_GROUP_${port.mux_group.upper()}_SEL_${port_group.name.upper()}_${port.name.upper()} ? 1'b1 : 1'b0;
% endfor
% endif
% endfor

   lzc #(
     .WIDTH(PORT_MUX_GROUP_${port.mux_group.upper()}_SEL_WIDTH),
     .MODE(1'b0)
   ) i_port_muxsel_${port_group.name}_${port_signal.name}_arbiter (
     .in_i(port_mux_sel_req_${port_group.name}_${port_signal.name}),
     .cnt_o(port_mux_sel_${port_group.name}_${port_signal.name}),
     .empty_o(port_mux_sel_${port_group.name}_${port_signal.name}_no_connection)
   );

   always_comb begin
     if (port_mux_sel_${port_group.name}_${port_signal.name}_no_connection) begin
        port_signals_pad2soc_o.${port_group.name}.${port_signal.name} = ${port_group.output_defaults[port_signal].expression};
     end else begin
        unique case (port_mux_sel_${port_group.name}_${port_signal.name})
% for pad in dynamic_pads:
% if pad.mux_group == port.mux_group:
% for i in range(pad.multiple):
<%
  pad_suffix = i if pad.multiple > 1 else ""
  pad_signal_remapping = {pad_signal.name : f"pads_to_mux_i.{pad.name}{pad_suffix}.{pad_signal.name}" for pad_signal in pad.dynamic_pad_signals_pad2soc}
%>\
          PORT_MUX_GROUP_${port.mux_group.upper()}_SEL_${pad.name.upper()}${pad_suffix}: begin
% if port_signal in port.connections:
            port_signals_pad2soc_o.${port_group.name}.${port_signal.name} = ${port.connections[port_signal].get_mapped_expr(pad_signal_remapping).expression};
% else:
            port_signals_pad2soc_o.${port_group.name}.${port_signal.name} = ${port_group.output_defaults[port_signal].expression};
% endif
          end
% endfor
% endif
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
