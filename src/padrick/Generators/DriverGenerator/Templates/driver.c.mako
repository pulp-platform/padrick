<%
  import math
%>
#include "${padframe.name}.h"
% for pad_domain in padframe.pad_domains:
#include "${padframe.name}_${pad_domain.name}_regs.h"
% endfor

#define REG_WRITE32(addr, value) *((volatile uint32_t*) addr) = (uint32_t) value;
#define REG_READ32(addr) *((volatile uint32_t*) addr)
#define REG_SET(FIELD, v) ((v & FIELD##_MASK) << FIELD##_LSB)
#define REG_GET(FIELD, v) (((v)&FIELD##_MASK) >> FIELD##_SHIFT)

% for pad_domain in padframe.pad_domains:
% for pad in pad_domain.pad_list:
% for ps in pad.dynamic_pad_signals_soc2pad:
<%
  # Determine appropriate type for field value
  if ps.size <= 8:
      field_type = "uint8_t"
  elif ps.size <= 16:
      field_type = "uint16_t"
  else:
      field_type = "uint32_t"
  if pad.multiple > 1:
      address = f"{padframe.name.upper()}_{pad_domain.name.upper()}_{pad.name.upper()}_CFG_0(0) + 4*idx"
  else:
      address = f"{padframe.name.upper()}_{pad_domain.name.upper()}_{pad.name.upper()}_CFG(0)"
  field_name = f"{padframe.name.upper()}_{pad_domain.name.upper()}_{pad.name.upper()}_CFG_0_{ps.name.upper()}"
%>
void ${padframe.name}_${pad_domain.name}_${pad.name}_cfg_${ps.name}_set(${"uint32_t idx, " if pad.multiple > 1 else ""}${field_type} value) {
  uint32_t address = ${address};
  uint32_t v = REG_READ32(address);
  v |= REG_SET(${field_name}, value);
  REG_WRITE32(address, v);
}

${field_type} ${padframe.name}_${pad_domain.name}_${pad.name}_cfg_${ps.name}_get(${"uint32_t idx" if pad.multiple > 1 else ""}) {
  uint32_t address = ${address};
  return REG_GET(${field_name}, REG_READ32(address));
}
% endfor
% if pad.dynamic_pad_signals_soc2pad:
<%
  if pad.multiple > 1:
      all_ports = [port for port_group in pad_domain.port_groups for port in port_group.ports]
      sel_size = max(1,math.ceil(math.log2(len([port for port in all_ports if port.mux_group == pad.mux_group])+1)))
      pads_per_register = 32//sel_size
      address = f"{padframe.name.upper()}_{pad_domain.name.upper()}_{pad.name.upper()}_MUX_SEL_0(0)+idx/pads_per_register*4"
  else:
      address = f"{padframe.name.upper()}_{pad_domain.name.upper()}_{pad.name.upper()}_MUX_SEL(0)"
%>
void ${padframe.name}_${pad_domain.name}_${pad.name}_mux_set(${"uint32_t idx, " if pad.multiple > 1 else ""}${padframe.name}_${pad_domain.name}_${pad.name}_mux_sel_t mux_sel) {
  const uint32_t pads_per_register = ${pads_per_register};
  const uint32_t address = ${address};
  const uint32_t sel_size = ${sel_size};
% if pad.multiple > 1:
  uint32_t field_offset = idx % pads_per_register * sel_size;
  uint32_t field_mask = 1<<sel_size-1;
  uint32_t v = REG_READ32(address);
  v |= (value & field_mask) << field_offset;
  REG_WRITE32(address, v);
% else:
  uint32_t field_mask = 1<<sel_size-1;
  REG_WRITE32(address, value & field_mask);
% endif
}

${padframe.name}_${pad_domain.name}_${pad.name}_mux_sel_t ${padframe.name}_${pad_domain.name}_${pad.name}_mux_get(${ "uint32_t idx" if pad.multiple > 1 else "" }) {
  const uint32_t pads_per_register = ${pads_per_register};
  const uint32_t address = ${address};
  const uint32_t sel_size = ${sel_size};
% if pad.multiple > 1:
  uint32_t field_offset = idx % pads_per_register * sel_size;
  uint32_t field_mask = 1<<sel_size-1;
  return (REG_READ32(address) >> field_offset) & field_mask;
% else:
  uint32_t field_mask = 1<<sel_size-1;
  return REG_READ32(address) & field_mask;
% endif
}
% endif
% endfor
% endfor
