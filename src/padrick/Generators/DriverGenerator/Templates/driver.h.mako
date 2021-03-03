<%
  import math
%>
#ifndef ${padframe.name.upper()}_H
#define ${padframe.name.upper()}_H
#include <stdint.h>

#ifndef ${padframe.name.upper()}_BASE_ADDRESS
#error "${padframe.name.upper()}_BASE_ADDRESS is not defined. Set this token to the configuration base address of your padframe before you include this header file."
#endif


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
%>
/**
 * Sets the ${ps.name} pad signal for the pad: ${pad.name}
 *
% if pad.multiple > 1:
 * @param idx The instance index of the pad to configure (< ${pad.multiple})
 % endif
 * @param value The value to program into the pad configuration register. A value smaller than ${2**ps.size-1}.
 */
void ${padframe.name}_${pad_domain.name}_${pad.name}_cfg_${ps.name}_set(${"uint32_t idx, " if pad.multiple > 1 else ""}${field_type} value);

/**
 * Get the currently configured ${ps.name} value for the pad: ${pad.name}
 *
% if pad.multiple > 1:
 * @param idx The instance index of the pad to configure (< ${pad.multiple})
% endif
 * @return The value of the ${ps.name} field
 */
${field_type} ${padframe.name}_${pad_domain.name}_${pad.name}_cfg_${ps.name}_get(${"uint32_t idx" if pad.multiple > 1 else ""});
% endfor
% if pad.dynamic_pad_signals_soc2pad:

typedef enum {
  ${padframe.name.upper()}_${pad_domain.name.upper()}_${pad.name.upper()}_REGISTER = 0,
<% idx = 1 %>\
% for port_group in pad_domain.port_groups:
% for port in port_group.ports:
% if port.mux_group == pad.mux_group:
  ${padframe.name.upper()}_${pad_domain.name.upper()}_${pad.name.upper()}_port_${port.name.upper()} = ${idx},
<% idx += 1 %>\
% endif
% endfor
% endfor
} ${padframe.name}_${pad_domain.name}_${pad.name}_mux_sel_t;

/**
 * Choose the entity (a port or the dedicated configuration register) that controls ${pad.name}.
 *
% if pad.multiple > 1:
 * @param idx The instance index of the pad to configure (< ${pad.multiple})
% endif
 * @param mux_sel Port or configuration register to connect to the pad.
 */
void ${padframe.name}_${pad_domain.name}_${pad.name}_mux_set(${"uint32_t idx, " if pad.multiple > 1 else ""}${padframe.name}_${pad_domain.name}_${pad.name}_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for ${pad.name}.
 *
 % if pad.multiple > 1:
 * @param idx The instance index of the pad to configure (< ${pad.multiple})
 % endif
 * @return Port or configuration register currently connected to the pad.
 */
 ${padframe.name}_${pad_domain.name}_${pad.name}_mux_sel_t ${padframe.name}_${pad_domain.name}_${pad.name}_mux_get(${"uint32_t idx" if pad.multiple > 1 else ""});


% endif
% endfor
% endfor


#endif /*  ${padframe.name.upper()}_H */
