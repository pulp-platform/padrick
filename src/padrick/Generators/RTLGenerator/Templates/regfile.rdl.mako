## Copyright 2026 ETH Zurich.
## Licensed under the Apache License, Version 2.0, see LICENSE for details.
## SPDX-License-Identifier: Apache-2.0
## Author: Kai Berszin, ETH Zurich
##
## SystemRDL description of the padframe configuration register file. This is the
## PeakRDL-backend equivalent of regfile.hjson.mako (lowRISC reggen backend).
<%
  import math
  import string
  from padrick.Model.PadSignal import SignalDirection
  from natsort import natsorted

  def sort_by_name(seq):
    return natsorted(seq, lambda x: x.name)

  def rdl_desc(text):
    # Collapse a (possibly multi-line) description into a single escaped RDL string literal body.
    if not text:
      return ""
    collapsed = " ".join(str(text).split())
    return collapsed.replace("\\", "\\\\").replace('"', '\\"')

  addrmap_name = f"{padframe.name}_{pad_domain.name}_config"
%>\
% for line in header_text.splitlines():
// ${line}
% endfor
//
// SystemRDL configuration register file for pad domain '${pad_domain.name}' of padframe '${padframe.name}'.
// Consumed by the PeakRDL register backend (systemrdl-compiler + peakrdl-regblock / peakrdl-cheader).
// Layout mirrors the lowRISC-reggen hjson backend: an INFO register, one or more
// per-pad *_CFG registers holding the SoC->pad signal defaults, and a *_MUX_SEL register
// selecting which port (or the config register itself) drives each dynamically muxable pad.
addrmap ${addrmap_name} {
    name = "${addrmap_name}";
    // 32-bit registers; software read/write and hardware read-only unless overridden per field.
    default regwidth = 32;
    default sw = rw;
    default hw = r;

    // INFO: read-only IP identification register (HW version + number of muxable pads).
    reg {
        name = "INFO";
        desc = "Read-only IP Information register";
        field { sw = r; hw = r; } HW_VERSION[15:0] = ${hw_version};
        field { sw = r; hw = r; } PADCOUNT[31:16] = ${len([pad for pad in pad_domain.pad_list if not pad.is_static and not pad.is_hardwired])};
    } INFO @ ${start_address_offset};

% for pad in pad_domain.pad_list:
## Hardwired quasi-static pads are directly connected to their port and thus have
## neither config nor mux_sel registers.
% if pad.dynamic_pad_signals_soc2pad and not pad.is_hardwired:
<%
  # Group the soc2pad signals into 32-bit config registers, identical to the hjson backend.
  total_dynamic_padsignal_bits = sum([signal.size for signal in pad.dynamic_pad_signals])
  num_cfg_regs = total_dynamic_padsignal_bits//32 + 1

  pad_signals_grouping = []
  current_signal_grouping = []
  current_group_size = 0
  for pad_signal in pad.dynamic_pad_signals_soc2pad:
      if current_group_size + pad_signal.size > 32:
          pad_signals_grouping.append(current_signal_grouping)
          current_group_size = 0
          current_signal_grouping = [(pad_signal, (pad_signal.size-1,0))]
      else:
          current_signal_grouping.append((pad_signal, (current_group_size + pad_signal.size-1, current_group_size)))
          current_group_size = current_group_size + pad_signal.size
  pad_signals_grouping.append(current_signal_grouping)

  def cfg_suffix(idx: int):
      cfg_suffix = ""
      if num_cfg_regs > 1:
          num_cfg_reg_chars = math.ceil(math.log(num_cfg_regs, 26))
          for k in range(num_cfg_reg_chars):
              cfg_suffix = string.ascii_uppercase[idx % 26]+cfg_suffix
              idx = idx // 26
      return cfg_suffix
%>\
% for i, pad_signals in enumerate(pad_signals_grouping):
    // Configuration register(s) holding the register-driven default values for pad '${pad.name}'.
    reg {
        name = "${pad.name.upper()}_CFG${cfg_suffix(i)}";
        desc = "Pad signal configuration.";
% for pad_signal, (msb, lsb) in pad_signals:
        field { sw = rw; hw = r; desc = "${rdl_desc(pad_signal.description)}"; } ${pad_signal.name}[${msb}:${lsb}] = ${pad.connections.get(pad_signal, pad_signal.default_reset_value) if pad.connections else pad_signal.default_reset_value};
% endfor
    } ${pad.name.upper()}_CFG${cfg_suffix(i)};
% endfor
% endif
% if pad.dynamic_pad_signals and not pad.is_hardwired:
<%
    connectable_ports = []
    idx = 0
    reset_value = 0
    for port_group in sort_by_name(pad_domain.port_groups):
      for port in sort_by_name(port_group.ports):
        if port.mux_groups.intersection(pad.mux_groups):
          connectable_ports.append((port_group, port))
          idx += 1
          if pad.default_port and pad.default_port[0].name == port_group.name and pad.default_port[1].name == port.name:
            reset_value = idx
    sel_msb = max(0, math.ceil(math.log2(len(pad_domain.get_ports_in_mux_groups(pad.mux_groups))+1))-1)
%>\
    reg {
        name = "${pad.name.upper()}_MUX_SEL";
        desc = "Pad signal port multiplex selection for pad ${pad.name}. The programmed value defines which port is connected to the pad.";
        enum ${pad.name.upper()}_MUX_SEL_e {
            register = 0 { desc = "Connects the Pad to the internal configuration register."; };
% for idx, (port_group, port) in enumerate(connectable_ports):
            port_${port_group.name}_${port.name.lower()} = ${idx+1} { desc = "Connect port ${port.name} from port group ${port_group.name} to this pad."; };
% endfor
        };
        field { sw = rw; hw = r; encode = ${pad.name.upper()}_MUX_SEL_e; } sel[${sel_msb}:0] = ${reset_value};
    } ${pad.name.upper()}_MUX_SEL;
% endif
% endfor
};
