## Copyright 2021-2022 ETH Zurich.
## Licensed under the Apache License, Version 2.0, see LICENSE for details.
## SPDX-License-Identifier: Apache-2.0
## Author: Manuel Eggimann, ETH Zurich

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
  - src/${templates.toplevel_sv_package.target_file_name.format(padframe=padframe)}
% for pad_domain in padframe.pad_domains:
  - src/${templates.internal_pkg.target_file_name.format(padframe=padframe, pad_domain = pad_domain)}
  - src/${padframe.name}_${pad_domain.name}_config_reg_pkg.sv
  - src/${padframe.name}_${pad_domain.name}_config_reg_top.sv
  - src/${templates.pad_inst_module.target_file_name.format(padframe=padframe, pad_domain = pad_domain)}
  - src/${templates.pad_mux_module.target_file_name.format(padframe=padframe, pad_domain = pad_domain)}
  - src/${templates.pad_domain_top.target_file_name.format(padframe=padframe, pad_domain = pad_domain)}
% endfor
  - src/${templates.toplevel_module.target_file_name.format(padframe=padframe)}

