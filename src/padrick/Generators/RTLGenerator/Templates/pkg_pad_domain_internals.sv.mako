package pkg_internal_${padframe.name}_${pad_domain.name};
% for pad in pad_domain.pad_list:
% for i in range(pad.multiple):
<% pad_suffix = i if pad.multiple > 1 else "" %>
    % if pad.dynamic_pad_signals_soc2pad:
  typedef struct {
      % for signal in pad.dynamic_pad_signals_soc2pad:
    logic ${f"[{signal.size-1}:0]" if signal.size > 1 else ""} ${signal.name};
      % endfor
  } mux_to_pad_${pad.name}${pad_suffix}_t;

    % endif
    % if pad.dynamic_pad_signals_pad2soc:
  typedef struct {
      % for signal in pad.dynamic_pad_signals_pad2soc:
    logic ${f"[{signal.size-1}:0]" if signal.size > 1 else ""} ${signal.name};
   % endfor
  } pad_to_mux_${pad.name}${pad_suffix}_t;

    % endif
  % endfor
% endfor
% if any([pad.dynamic_pad_signals_soc2pad for pad in pad_domain.pad_list]):
  typedef struct {
  % for pad in pad_domain.pad_list:
    % if pad.dynamic_pad_signals_soc2pad:
      % for i in range(pad.multiple):
        <% pad_suffix = i if pad.multiple > 1 else "" %> \
    mux_to_pad_${pad.name}${pad_suffix}_t ${pad.name}${pad_suffix};
      % endfor
    % endif
  % endfor
  } mux_to_pads_t;

% endif
% if any([pad.dynamic_pad_signals_pad2soc for pad in pad_domain.pad_list]):
  typedef struct {
  % for pad in pad_domain.pad_list:
    % if pad.dynamic_pad_signals_pad2soc:
      % for i in range(pad.multiple):
        <% pad_suffix = i if pad.multiple > 1 else "" %> \
    pad_to_mux_${pad.name}${pad_suffix}_t ${pad.name}${pad_suffix};
      % endfor
    % endif
  % endfor
  } pads_to_mux_t;

% endif


  // Port Indices
<%
import math
all_ports = [port for port_group in pad_domain.port_groups for port in port_group.ports]
sel_bitwidth = math.ceil(math.log2(len(all_ports)+1))
idx = 1
%>\
  parameter PAD_MUX_SEL_WIDTH = ${sel_bitwidth};
  parameter logic[${sel_bitwidth-1}:0] PAD_MUX_SEL_DEFAULT = ${sel_bitwidth-1}'d0;
% for port_group in pad_domain.port_groups:
% for port in port_group.ports:
  parameter logic[${sel_bitwidth-1}:0] PAD_MUX_SEL_${port_group.name.upper()}_${port.name.upper()} = ${sel_bitwidth-1}'d${idx};
<% idx += 1 %>\
% endfor
% endfor

  // Dynamic Pad  instance index
<%
  dynamic_pads = [pad for pad in pad_domain.pad_list if pad.dynamic_pad_signals_pad2soc]
  sel_bitwidth = math.ceil(math.log2(sum([pad.multiple for pad in dynamic_pads])+1))
  idx = 0
%>
  parameter PORT_MUX_SEL_WIDTH = ${sel_bitwidth};
% for pad in dynamic_pads:
% for i in range(pad.multiple):
<% pad_suffix = i if pad.multiple > 1 else "" %>\
  parameter logic[${sel_bitwidth-1}:0] PORT_MUX_SEL_${pad.name}${pad_suffix} = ${sel_bitwidth-1}'d${idx};
<% idx += 1 %>\
% endfor
% endfor
endpackage : pkg_internal_${padframe.name}_${pad_domain.name}
