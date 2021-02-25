package pkg_internal_${padframe.name}_${pad_domain.name};
% for pad in pad_domain.pad_list:
% if pad.dynamic_pad_signals_soc2pad:
  typedef struct {
% for signal in pad.dynamic_pad_signals_soc2pad:
    logic ${f"[{signal.size-1}:0]" if signal.size > 1 else ""} ${signal.name};
% endfor
  } mux_to_pad_${pad.name}_t;

% endif
% if pad.dynamic_pad_signals_pad2soc:
  typedef struct {
% for signal in pad.dynamic_pad_signals_pad2soc:
    logic ${f"[{signal.size-1}:0]" if signal.size > 1 else ""} ${signal.name};
% endfor
  } pad_to_mux_${pad.name}_t;

% endif
% endfor
% if any([pad.dynamic_pad_signals_soc2pad for pad in pad_domain.pad_list]):
  typedef struct {
% for pad in pad_domain.pad_list:
% if pad.dynamic_pad_signals_soc2pad:
% for i in range(pad.multiple):
        <% pad_suffix = i if pad.multiple > 1 else "" %> \
    mux_to_pad_${pad.name}_t ${pad.name}${pad_suffix};
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
    pad_to_mux_${pad.name}_t ${pad.name}${pad_suffix};
% endfor
% endif
% endfor
  } pads_to_mux_t;

% endif


  // Indices definitions
% for mux_group in pad_domain.pad_mux_groups:
<%
import math
all_ports = [port for port_group in pad_domain.port_groups for port in port_group.ports if port.mux_group == mux_group]
sel_bitwidth = max(1,math.ceil(math.log2(len(all_ports)+1))) # +1 since the sel == 0 in this case means "use config register value" which is the default
idx = 1
%>\
  parameter PAD_MUX_GROUP_${mux_group.upper()}_SEL_WIDTH = ${sel_bitwidth};
  parameter logic[${sel_bitwidth-1}:0] PAD_MUX_GROUP_${mux_group.upper()}_SEL_DEFAULT = ${sel_bitwidth}'d0;
% for port_group in pad_domain.port_groups:
% for port in port_group.ports:
% if port.mux_group == mux_group:
  parameter logic[${sel_bitwidth-1}:0] PAD_MUX_GROUP_${mux_group.upper()}_SEL_${port_group.name.upper()}_${port.name.upper()} = ${sel_bitwidth}'d${idx};
<% idx += 1 %>\
% endif
% endfor
% endfor
% endfor

  // Dynamic Pad  instance index
% for mux_group in pad_domain.port_mux_groups:
<%
  dynamic_pads = [pad for pad in pad_domain.pad_list if pad.dynamic_pad_signals_pad2soc and pad.mux_group == mux_group]
  sel_bitwidth = max(1, math.ceil(math.log2(sum([pad.multiple for pad in dynamic_pads])))) # no +1 here since the default is activate if the empty_o signal of the leading zero counter is asserted.
  idx = 0
%>
  parameter PORT_MUX_GROUP_${mux_group.upper()}_SEL_WIDTH = ${sel_bitwidth};
% for pad in dynamic_pads:
% if pad.mux_group == mux_group:
% for i in range(pad.multiple):
<% pad_suffix = i if pad.multiple > 1 else "" %>\
  parameter logic[${sel_bitwidth-1}:0] PORT_MUX_GROUP_${mux_group.upper()}_SEL_${pad.name.upper()}${pad_suffix} = ${sel_bitwidth}'d${idx};
<% idx += 1 %>\
% endfor
% endif
% endfor
% endfor
endpackage : pkg_internal_${padframe.name}_${pad_domain.name}
