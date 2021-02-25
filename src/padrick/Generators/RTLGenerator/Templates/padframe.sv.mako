module ${padframe.name}
  import pkg_${padframe.name}::*;
(
  input logic                                clk_i,
  input logic                                rst_ni,
% if any([pad_domain.override_signals for pad_domain in padframe.pad_domains]):
  input override_signals_t                   override_signals,
% endif
% if any([pad_domain.static_connection_signals_pad2soc for pad_domain in padframe.pad_domains]):
  output static_connection_signals_pad2soc_t static_connection_signals_pad2soc,
% endif
% if any([pad_domain.static_connection_signals_soc2pad for pad_domain in padframe.pad_domains]):  
  input  static_connection_signals_soc2pad_t static_connection_signals_soc2pad,
% endif
% if any([port_group.port_signals_soc2pads for pad_domain in padframe.pad_domains for port_group in pad_domain.port_groups]):
  output port_signals_pad2soc_t              port_signals_pad2soc,
% endif
% if any([port_group.port_signals_soc2pads for pad_domain in padframe.pad_domains for port_group in pad_domain.port_groups]):
  input port_signals_soc2pad_t               port_signals_soc2pad,
% endif
  inout landing_pads_t                       pads,
  input req_t                                config_req_i,
  output resp_t                              config_rsp_o
  );


% for pad_domain in padframe.pad_domains:
  ${padframe.name}_${pad_domain.name} i_${pad_domain.name} (
   .clk_i,
   .rst_ni,
% if pad_domain.override_signals:
   .override_signals_i(override_signals.${pad_domain.name}),
% endif
% if pad_domain.static_connection_signals_pad2soc:
   .static_connection_signals_pad2soc(static_connection_signals_pad2soc.${pad_domain.name}),
% endif
% if pad_domain.static_connection_signals_soc2pad:
   .static_connection_signals_soc2pad(static_connection_signals_soc2pad.${pad_domain.name}),
% endif
% if any([port_group.port_signals_pads2soc for port_group in pad_domain.port_groups]):
   .port_signals_pad2soc(port_signals_pad2soc.${pad_domain.name}),
% endif
% if any([port_group.port_signals_soc2pads for port_group in pad_domain.port_groups]):
   .port_signals_soc2pad(port_signals_soc2pad.${pad_domain.name}),
% endif
   .pads(pads.${pad_domain.name}),
   .config_req_i (),
   .config_rsp_o ()
  );

 % endfor

     // Config Interface demultiplexing
     reg_demux #(
       .NoPorts(${len(padframe.pad_domains)}),
       .req_t(req_t),
       .rsp_t(resp_t)
     ) i_config_demuxer (
       .clk_i,
       .rst_ni,
       .in_select_i(),
       .in_req_i(config_req_i),
       .in_rsp_o(config_rsp_o),
       .out_req_o()
     );



endmodule
