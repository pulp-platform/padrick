% for line in header_text.splitlines():
# ${line}
% endfor

# Use current_instance <pad_mux_inst> to set the correct scope for applying the constraints

<%
from typing import Generator
from natsort import natsorted
from math import ceil, log2

def as_bin(value:int, width:int):
   for c in "{value:0{width}b}".format(value=value, width=width):
     yield c

def sort_by_name(seq):
    return natsorted(seq, lambda x: x.name)

def get_sel_index_width(pad, port_group, port, pad_domain):
    idx = 1
    sel_value = 0
    mux_groups = pad.mux_groups
    for p_group in sort_by_name(pad_domain.port_groups):
      for p in sort_by_name(p_group.ports):
        if p.mux_groups.intersection(mux_groups):
          if p_group.name == port_group.name and p.name == port.name:
            sel_value = idx
          idx += 1
    return sel_value, ceil(log2(idx))
%>
# Mode: ${constraints_mode.name}
# Pad Domain: ${constraints_mode.pad_domain.name}

% for pad_mode in constraints_mode.pad_mode:
% if pad_mode.port_sel:
# Pad ${pad_mode.pad_inst.name} -> ${pad_mode.port_sel[0].name}.${pad_mode.port_sel[1].name}
<%
    sel_value, width = get_sel_index_width(pad_mode.pad_inst, pad_mode.port_sel[0], pad_mode.port_sel[1], constraints_mode.pad_domain)
%>
% for i, bit in enumerate(as_bin(sel_value, width)):
set_case_analysis ${bit} i_${constraints_mode.pad_domain.name}/i_${constraints_mode.pad_domain.name}_muxer/i_regfile/u_${pad_mode.pad_inst.name}_mux_sel/q${f"\[{i}\]" if width > 1 else ""}
% endfor

% else:
# Pad ${pad_mode.pad_inst.name}
% endif
% if pad_mode.pad_cfg:
# Pad Signal Config (${pad_mode.pad_inst.name})
% for ps, value in pad_mode.pad_cfg.items():
# ${ps.name} -> ${value}
% for i, bit in enumerate(as_bin(value, ps.size)):
set_case_analysis ${bit} i_${constraints_mode.pad_domain.name}/i_${constraints_mode.pad_domain.name}_muxer/i_regfile/u_${pad_mode.pad_inst.name}_cfg_${ps.name}/q${f"\[{i}\]" if ps.size > 1 else ""}
%endfor

% endfor
% endif
% endfor