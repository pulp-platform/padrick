% for line in header_text.splitlines():
# ${line}
% endfor
package:
  name: ${padframe.name}
  authors:
    - "Padrick"

dependencies:
  register_interface:     { git: "https://github.com/pulp-platform/register_interface.git", version: 0.3.1 }
  common_cells:           { git: "https://github.com/pulp-platform/common_cells.git", version: 1.21.0 }

export_include_dirs:
- include

sources:
  - src/pkg_${padframe.name}.sv
% for pad_domain in padframe.pad_domains:
  - src/pkg_internal_${padframe.name}_${pad_domain.name}.sv
  - src/${padframe.name}_${pad_domain.name}_config_reg_pkg.sv
  - src/${padframe.name}_${pad_domain.name}_config_reg_top.sv
  - src/${padframe.name}_${pad_domain.name}_pads.sv
  - src/${padframe.name}_${pad_domain.name}_muxer.sv
  - src/${padframe.name}_${pad_domain.name}.sv
% endfor
  - src/${padframe.name}.sv

