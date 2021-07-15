% for line in header_text.splitlines():
// ${line}
% endfor

// Assignment Macros
// Assigns all members of port struct to another struct with same names but potentially different order

%for pad_domain in padframe.pad_domains:
%for port_group in pad_domain.port_groups:
%if port_group.port_signals_pads2soc:
`define ASSIGN_${pad_domain.name.upper()}_${port_group.name.upper()}_PAD2SOC(load, driver) ${"\\"}
%for signal in port_group.port_signals_pads2soc:
  assign load.${signal.name} = driver.${signal.name}; ${"\\"}
%endfor
%endif

%if port_group.port_signals_pads2soc:
`define ASSIGN_${pad_domain.name.upper()}_${port_group.name.upper()}_SOC2PAD(load, driver) ${"\\"}
%for signal in port_group.port_signals_soc2pads:
  assign load.${signal.name} = driver.${signal.name}; ${"\\"}
%endfor
%endif
%endfor
%endfor
