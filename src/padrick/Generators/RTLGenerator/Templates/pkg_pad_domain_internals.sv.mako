package pkg_internal_${padframe.name}_${pad_domain.name};
% for pad in pad_domain.pad_list:
% for i in range(pad.multiple):
<% pad_suffix = i if pad.multiple > 1 else "" %>
    % if pad.dynamic_pad_signals_soc2pad:
  typedef struct {
      % for signal in pad.dynamic_pad_signals_soc2pad:
    logic ${f"[{signal.size-1}:0]" if signal.size > 1 else ""} ${signal.name};
      % endfor
  } mux_to_pad_${pad.name}${pad_suffix}_t;

    % endif
    % if pad.dynamic_pad_signals_pad2soc:
  typedef struct {
      % for signal in pad.dynamic_pad_signals_pad2soc:
    logic ${f"[{signal.size-1}:0]" if signal.size > 1 else ""} ${signal.name};
   % endfor
  } pad_to_mux_${pad.name}${pad_suffix}_t;

    % endif
  % endfor
% endfor
% if any([pad.dynamic_pad_signals_soc2pad for pad in pad_domain.pad_list]):
  typedef struct {
  % for pad in pad_domain.pad_list:
    % if pad.dynamic_pad_signals_soc2pad:
      % for i in range(pad.multiple):
        <% pad_suffix = i if pad.multiple > 1 else "" %> \
    mux_to_pad_${pad.name}${pad_suffix}_t ${pad.name}${pad_suffix};
      % endfor
    % endif
  % endfor
  } mux_to_pads_t;

% endif
% if any([pad.dynamic_pad_signals_pad2soc for pad in pad_domain.pad_list]):
  typedef struct {
  % for pad in pad_domain.pad_list:
    % if pad.dynamic_pad_signals_pad2soc:
      % for i in range(pad.multiple):
        <% pad_suffix = i if pad.multiple > 1 else "" %> \
    pad_to_mux_${pad.name}${pad_suffix}_t ${pad.name}${pad_suffix};
      % endfor
    % endif
  % endfor
  } pads_to_mux_t;

% endif
endpackage : pkg_internal_${padframe.name}_${pad_domain.name}
