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

<% config_interface = padframe.config_interface.value %>\
dependencies:
% if config_interface == "regbus":
  register_interface:     { git: "https://github.com/pulp-platform/register_interface.git", version: 0.3.1 }
% else:
  register_interface:     { git: "https://github.com/pulp-platform/register_interface.git", version: 0.4.7 }
% endif
  common_cells:           { git: "https://github.com/pulp-platform/common_cells.git", version: 1.21.0 }
% if config_interface == "apb":
  apb:                    { git: "https://github.com/pulp-platform/apb.git", version: 0.2.4 }
% elif config_interface == "axilite":
  axi:                    { git: "https://github.com/pulp-platform/axi.git", version: 0.39.10 }
% elif config_interface == "obi":
  obi:                    { git: "https://github.com/pulp-platform/obi.git", version: 0.1.7 }
% endif

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

