<%
  import math
  import string
  from padrick.Model.PadSignal import SignalDirection

%>
{
% for line in header_text.splitlines():
    # ${line}
% endfor
    name: "${padframe.name}_${pad_domain.name}_config"
    clock_primary: "clk_i"
    reset_primary: "rst_ni"
    bus_device: "reg",
    bus_host: "",
    regwidth: 32,
    registers: [
        {skipto: "${start_address_offset}"},
% for pad in pad_domain.pad_list:
% if pad.dynamic_pad_signals_soc2pad:
<%
  # Calculate how many config registers we need to accomodate all dynamic
  # pad signals that need a register.
  total_dynamic_padsignal_bits = sum([signal.size for signal in pad.dynamic_pad_signals])
  num_cfg_regs = total_dynamic_padsignal_bits//32 + 1

  # Group pad_signals by config register
  pad_signals_grouping = []
  current_signal_grouping = []
  current_group_size = 0
  for pad_signal in pad.dynamic_pad_signals_soc2pad:
      if current_group_size + pad_signal.size > 32:
          # Start new grouping
          pad_signals_grouping.append(current_signal_grouping)
          current_group_size = 0
          current_signal_grouping = [(pad_signal, (pad_signal.size-1,0))]
      else:
          current_signal_grouping.append((pad_signal, (current_group_size + pad_signal.size-1, current_group_size)))
          current_group_size = current_group_size + pad_signal.size
  pad_signals_grouping.append(current_signal_grouping)

  # Convert the config register index to a capital letter index e.g. 1 -> A, 2 -> B, 3->C
  # If there are more then 26 config registers needed, use another character
  def cfg_suffix(idx: int):
      cfg_suffix = ""
      if num_cfg_regs > 1:
          num_cfg_reg_chars = math.ceil(math.log(num_cfg_regs, 26))
          for k in range(num_cfg_reg_chars):
              cfg_suffix = string.ascii_uppercase[idx % 26]+cfg_suffix
              idx = idx // 26
      return cfg_suffix
%> \
% for i, pad_signals in enumerate(pad_signals_grouping):
     {
          name: ${pad.name.upper()}_CFG${cfg_suffix(i)}
          desc: '''
            Pad signal configuration.
          '''
          swaccess: "rw"
          fields: [
% for pad_signal, (msb, lsb) in pad_signals:
            {
                bits: "${str(msb)+':'+str(lsb) if msb != lsb else lsb}"
                name: ${pad_signal.name}
                desc: '''
                     ${pad_signal.description if pad_signal.description else ""}
                '''
                swaccess: "rw"
                hwaccess: "hro"
                resval: "${pad.connections.get(pad_signal, pad_signal.default_reset_value) if pad.connections else pad_signal.default_reset_value}"
            },
% endfor
          ]
      }
% endfor
% endif
% if pad.dynamic_pad_signals:
       {
          name: ${pad.name.upper()}_MUX_SEL
          desc: '''
              Pad signal port multiplex selection for pad ${pad.name}. The programmed value defines which port
              is connected to the pad.
          '''
          swaccess: "rw"
          hwaccess: "hro"
          resval: 0
          fields: [
              {
                  bits: "${max(0,math.ceil(math.log2(len(pad_domain.get_ports_in_mux_groups(pad.mux_groups))+1))-1)}:0"
                  enum: [
                      { value: "0", name: "register", desc: "Connects the Pad to the internal configuration register. This is the default value."}
<% idx = 0 %>\
% for port_group in pad_domain.port_groups:
% for port in port_group.ports:
% if port.mux_groups.intersection(pad.mux_groups):
                      { value: "${idx+1}", name: "port_${port_group.name}_${port.name.lower()}", desc: "Connect port ${port.name} from port group ${port_group.name} to this pad." }
<% idx += 1 %>\
% endif
% endfor
% endfor
                  ]
              }
          ]
      }
% endif

% endfor
    ]
}
