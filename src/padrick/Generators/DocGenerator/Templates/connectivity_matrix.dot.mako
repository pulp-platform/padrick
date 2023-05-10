## Manuel Eggimann <meggimann@iis.ee.ethz.ch>
##
## Copyright (C) 2021-2022 ETH Zürich
##
## Licensed under the Apache License, Version 2.0 (the "License");
## you may not use this file except in compliance with the License.
## You may obtain a copy of the License at
##
##     http://www.apache.org/licenses/LICENSE-2.0
##
## Unless required by applicable law or agreed to in writing, software
## distributed under the License is distributed on an "AS IS" BASIS,
## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
## See the License for the specific language governing permissions and
## limitations under the License.
% for line in header_text.splitlines():
# ${line}
% endfor

graph g {
	node[shape=box]
	ranksep=5
	nodesep=0.25
	rankdir="LR"

	label = "${padframe.name}"
% for pad_domain in padframe.pad_domains:
<% prefix = f"PadDomain_{pad_domain.name}" %>
	subgraph cluster_${prefix}{
		label = "${pad_domain.name}"

        subgraph cluster_${prefix}_Ports {
            label = "Port Groups"
            margin=20
% for port_group in pad_domain.port_groups:
            subgraph cluster_${prefix}_PortGroup_${port_group.name}{
                margin=10
                label = "${port_group.name}"
% for port in port_group.ports:
                "${prefix}_port_${port_group.name}.${port.name}" [label = "${port.name}"]
% endfor
            }
% endfor
        }

        subgraph cluster_${prefix}_Pads {
            label = "IO-Pads"
% for pad in pad_domain.pad_list:
% if not pad.is_static:
             "${prefix}_pad_${pad.name}" [label = ${pad.name}]
% endif
% endfor
        }
	    # Dynamic Connections
% for port_group in pad_domain.port_groups:
% for port in port_group.ports:
<% port_node = f"{prefix}_port_{port_group.name}.{port.name}" %>
% for connected_pad in pad_domain.get_dynamic_pads_in_mux_groups(port.mux_groups):
% if connected_pad.default_port and connected_pad.default_port[0].name == port_group.name and port.name == connected_pad.default_port[1].name:
        "${port_node}" -- "${prefix}_pad_${connected_pad.name}" [color = green]
% else:
        "${port_node}" -- "${prefix}_pad_${connected_pad.name}"
% endif
% endfor

% endfor


% endfor
	}

% endfor
	# Legend
	a [label="Port xy"]
	b [label="Pad xy"]
	a -- b [label="default port (after reset)", color=green]
}
