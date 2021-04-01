<%
  import math
  from natsort import natsorted
%>
#include "${padframe.name}.h"
% for pad_domain in padframe.pad_domains:
#define  ${padframe.name.upper()}_${pad_domain.name.upper()}_CONFIG0_BASE_ADDR ${padframe.name.upper()}_BASE_ADDRESS
#include "${padframe.name}_${pad_domain.name}_regs.h"
% endfor

#define REG_WRITE32(addr, value) *((volatile uint32_t*) addr) = (uint32_t) value;
#define REG_READ32(addr) *((volatile uint32_t*) addr)
#define REG_SET(FIELD, v) ((v & FIELD##_MASK) << FIELD##_LSB)
#define REG_CLR(FIELD)    ((FIELD##_MASK) << FIELD##_LSB)
#define REG_GET(FIELD, v) ((v >> FIELD##_LSB) & FIELD##_MASK)

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
  address = f"{padframe.name.upper()}_{pad_domain.name.upper()}_CONFIG_{pad.name.upper()}_CFG(0)"
  all_ports_in_mux_group = pad_domain.get_ports_in_mux_groups(pad.mux_groups)
  sel_size = max(1,math.ceil(math.log2(len(all_ports_in_mux_group)+1)))
  field_name = f"{padframe.name.upper()}_{pad_domain.name.upper()}_CONFIG_{pad.name.upper()}_CFG_0_{ps.name.upper()}"
%>
void ${padframe.name}_${pad_domain.name}_${pad.name}_cfg_${ps.name}_set(${field_type} value) {
  uint32_t address = ${address};
  uint32_t v = REG_READ32(address);
  v &= ~REG_CLR(${field_name});
  v |= REG_SET(${field_name}, value);
  REG_WRITE32(address, v);
}

${field_type} ${padframe.name}_${pad_domain.name}_${pad.name}_cfg_${ps.name}_get() {
  uint32_t address = ${address};
  return REG_GET(${field_name}, REG_READ32(address));
}
% endfor
% if pad.dynamic_pad_signals_soc2pad:
<%
  address = f"{padframe.name.upper()}_{pad_domain.name.upper()}_CONFIG_{pad.name.upper()}_MUX_SEL(0)"
%>
void ${padframe.name}_${pad_domain.name}_${pad.name}_mux_set(${padframe.name}_${pad_domain.name}_${pad.name}_mux_sel_t mux_sel) {
  const uint32_t address = ${address};
  const uint32_t sel_size = ${sel_size};
  uint32_t field_mask = 1<<sel_size-1;
  REG_WRITE32(address, value & field_mask);
}

${padframe.name}_${pad_domain.name}_${pad.name}_mux_sel_t ${padframe.name}_${pad_domain.name}_${pad.name}_mux_get() {
  const uint32_t address = ${address};
  const uint32_t sel_size = ${sel_size};

  uint32_t field_mask = 1<<sel_size-1;
  return REG_READ32(address) & field_mask;
}
% endif
% endfor
% endfor
