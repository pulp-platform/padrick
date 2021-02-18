${padframe.name}:
  files:
    - src/pkg_${padframe.name}.sv
% for pad_domain in padframe.pad_domains:
    - src/pkg_internal_${padframe.name}_${pad_domain.name}.sv
    - src/${padframe.name}_${pad_domain.name}_config_reg_pkg.sv
    - src/${padframe.name}_${pad_domain.name}_config_reg_top.sv
    - src/${padframe.name}_${pad_domain.name}_pads.sv
    - src/${padframe.name}_${pad_domain.name}.sv
% endfor
    - src/${padframe.name}.sv
  vlog_opts:
    - -L axi_lib