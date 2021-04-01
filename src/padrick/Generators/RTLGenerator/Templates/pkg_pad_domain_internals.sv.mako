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
    mux_to_pad_${pad.name}_t ${pad.name};
% endif
% endfor
  } mux_to_pads_t;

% endif
% if any([pad.dynamic_pad_signals_pad2soc for pad in pad_domain.pad_list]):
  typedef struct {
% for pad in pad_domain.pad_list:
% if pad.dynamic_pad_signals_pad2soc:
    pad_to_mux_${pad.name}_t ${pad.name};
% endif
% endfor
  } pads_to_mux_t;

% endif


  // Indices definitions
% for mux_groups in pad_domain.pad_mux_group_sets:
<%
import math
from natsort import natsorted
mux_group_name = "_".join(natsorted(mux_groups)).upper()
all_ports_in_mux_group = pad_domain.get_ports_in_mux_groups(mux_groups)
sel_bitwidth = max(1,math.ceil(math.log2(len(all_ports_in_mux_group)+1))) # +1 since the sel == 0 in this case means "use config register value" which is the default
idx = 1
def sort_by_name(seq):
    return natsorted(seq, lambda x: x.name)
%>\
  parameter PAD_MUX_GROUP_${mux_group_name}_SEL_WIDTH = ${sel_bitwidth};
  parameter logic[${sel_bitwidth-1}:0] PAD_MUX_GROUP_${mux_group_name}_SEL_DEFAULT = ${sel_bitwidth}'d0;
% for port_group in sort_by_name(pad_domain.port_groups):
% for port in sort_by_name(port_group.ports):
% if port.mux_groups.intersection(mux_groups):
  parameter logic[${sel_bitwidth-1}:0] PAD_MUX_GROUP_${mux_group_name}_SEL_${port_group.name.upper()}_${port.name.upper()} = ${sel_bitwidth}'d${idx};
<% idx += 1 %>\
% endif
% endfor
% endfor
% endfor

  // Dynamic Pad  instance index
% for mux_groups in pad_domain.port_mux_group_sets:
<%
  mux_group_name = "_".join(natsorted(mux_groups)).upper()
  dynamic_pads = pad_domain.get_dynamic_pads_in_mux_groups(mux_groups)
  sel_bitwidth = max(1, math.ceil(math.log2(len(dynamic_pads)))) # no +1 here since the default is activate if the empty_o signal of the leading zero counter is asserted.
  idx = 0
%>
  parameter PORT_MUX_GROUP_${mux_group_name}_SEL_WIDTH = ${sel_bitwidth};
% for pad in dynamic_pads:
  parameter logic[${sel_bitwidth-1}:0] PORT_MUX_GROUP_${mux_group_name}_SEL_${pad.name.upper()} = ${sel_bitwidth}'d${idx};
<% idx += 1 %>\
% endfor
% endfor
endpackage : pkg_internal_${padframe.name}_${pad_domain.name}
