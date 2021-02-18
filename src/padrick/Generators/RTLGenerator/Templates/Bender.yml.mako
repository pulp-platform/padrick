package:
  name: ${padframe.name}
  authors:
    - "Padrick"

dependencies:
  register_interface:     { git: "https://github.com/pulp-platform/register_interface.git", version: 0.2.1 }
  axi:                    { git: "https://github.com/pulp-platform/axi.git", version: 0.27.0 }
  common_cells:           { git: "https://github.com/pulp-platform/common_cells.git", version: 1.21.0 }

sources:
  - src/pkg_${padframe.name}.sv
% for pad_domain in padframe.pad_domains:
  - src/pkg_internal_${padframe.name}_${pad_domain.name}.sv
  - src/${padframe.name}_${pad_domain.name}_config_reg_pkg.sv
  - src/${padframe.name}_${pad_domain.name}_config_reg_top.sv
  - src/${padframe.name}_${pad_domain.name}_pads.sv
  - src/${padframe.name}_${pad_domain.name}.sv
% endfor
  - src/${padframe.name}.sv

