package pkg_${domain.name}_pads;

   % for pad_type in domain.pad_types:
   typedef struct packed {
     %for pad_signal in pad_type.pad_signals:
      logic ${f"[{pad_signal.size-1}:0]" if pad_signal.size > 1 else ""} ${pad_signal.name};
     % endfor
   } ${domain.name}_${pad_type.name}_signals_t;

   % endfor

endpackage : pkg_${domain.name}_pads
