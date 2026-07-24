## Copyright 2021-2022 ETH Zurich.
## Licensed under the Apache License, Version 2.0, see LICENSE for details.
## SPDX-License-Identifier: Apache-2.0
## Author: Manuel Eggimann, ETH Zurich

% for line in header_text.splitlines():
# ${line}
% endfor
# IPApprox dependencies for ${padframe.name}
common_cells:
  commit: v1.21.0
  domain: [cluster, soc]
  server: https://github.com
  group: pulp-platform
register_interface:
  commit: v0.2.1
  domain: [soc]
  server: https://github.com
  group: pulp-platform
axi/axi:
  commit: v0.27.0
  domain: [cluster, soc]
  server: https://github.com
  group: pulp-platform
