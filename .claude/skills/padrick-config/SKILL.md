---
name: padrick-config
description: Author a padrick padframe YAML config from scratch or modify one. Use when asked to write, extend, or debug a padframe configuration (pads, pad types, port groups, muxing, quasi-static pads). Covers structure, validation rules, and the check workflow.
---

# Authoring a padrick padframe config

## Workflow

1. Draft the YAML (structure below). Put this as line 1 for editor LSP support:
   `# yaml-language-server: $schema=<relpath-to>/padrick_schema.json`
2. Validate: `padrick validate <file>` (human) or `padrick validate --format json <file>`
   (machine-readable errors with line/column). Nonzero exit = invalid.
3. Inspect the parsed result: `padrick config <file>`.
4. Smoke the RTL: `padrick generate rtl -o <tmpdir> <file>`.
5. `uv run padrick schema` dumps the full JSON Schema — authoritative for every field;
   all fields carry descriptions.

## Skeleton

```yaml
# yaml-language-server: $schema=../padrick_schema.json
manifest_version: 5          # current version on this branch
name: my_padframe            # SystemVerilog identifier; prefixes all generated modules
pad_domains:
  - name: aon                # ≥1 domain; one RTL module + register file each
    pad_types:               # technology IO cells available in this domain
      - name: bidir_pad
        template: |          # Mako: instantiation of the actual IO cell
          my_io_cell ${instance_name} (
            .PAD(${conn["pad"]}), .I(${conn["chip2pad"]}),
            .O(${conn["pad2chip"]}), .OE(${conn["output_en"]}) );
        pad_signals:         # every signal of the cell, with kind + defaults
          - name: pad
            kind: pad        # the physical pad wire; no conn_type, no defaults
          - name: chip2pad
            kind: input      # chip -> pad; input-kind NEEDS both defaults
            conn_type: dynamic
            default_reset_value: 0
            default_static_value: 1'b0
          - name: pad2chip
            kind: output     # pad -> chip; output-kind must NOT have reset value
            conn_type: dynamic
          - name: output_en
            kind: input
            conn_type: dynamic
            default_reset_value: 0
            default_static_value: 1'b0
    pad_list:                # concrete pad instances
      - name: pad_gpio{i}    # {i} template + multiple -> pad_gpio0..pad_gpio7
        multiple: 8
        pad_type: bidir_pad
        mux_groups: [all, self]
        default_port: ...    # optional reset-time routing (see below)
    port_groups:             # peripheral-facing ports muxable onto the pads
      - name: spi
        output_defaults: "'0"   # REQUIRED for every pad2chip port signal
        ports:
          - name: mosi
            mux_groups: [all]
            connections:
              chip2pad: mosi_o       # pad signal <- port signal expression
              output_en: ~oen        # expressions: ~ & | literals like 2'b10
          - name: miso
            connections:
              miso_i: pad2chip       # port signal <- pad signal (pad2chip on RHS)
              output_en: 1'b0
```

## The three-plus-one pad flavors

- **Static** (`is_static: true`): `connections:` maps pad signals to fixed
  expressions/wires. No mux, no registers. Use for clocks/analog/test.
- **Dynamic** (default): full runtime muxing via generated `MUX_SEL`/`CFG` registers.
  `connections:` entries on a dynamic pad set the *register reset defaults*.
- **Quasi-static muxed** (`quasi_static: true` or `muxed`): pad constrained to exactly
  one port (typically pad `mux_groups: [self]` + port `mux_groups: ["<pad_name>"]`);
  padrick verifies the 1:1 and sets `default_port` automatically. Keeps a 1-bit mux +
  register fallback (GPIO-over-register escape hatch).
- **Quasi-static hardwired** (`quasi_static: hardwired`): same 1:1 rule but the mux and
  the pad's registers are elided entirely — continuous assignments, tie-offs = the reset
  defaults. Not addressable by software at all.

## Rules the validators enforce (fail early, by design)

- `kind: input` pad signals REQUIRE `default_reset_value` and `default_static_value`;
  `kind: output` must NOT have a reset value and only a single-signal static default;
  `kind: pad` has neither. Non-pad kinds need `conn_type` (`static`/`dynamic`).
- Every pad2chip (chip-input) port signal needs a connection default — per-signal in
  `output_defaults:` or one blanket expression (`output_defaults: "'0"`). Otherwise the
  peripheral input would float when the port is unrouted.
- Mux groups are lowercase-only. `self` expands to the pad's own name (pad side) or
  `<domain>_<port>` (port side). Ports and pads connect iff their mux_groups intersect.
- Names are SystemVerilog identifiers; duplicates (pads, ports, port groups) are errors;
  pad signals sharing a name across pad types must agree in size and direction.
- `{i}` / `{i:2d}` templates are only meaningful with `multiple: N`; index arithmetic like
  `{i*2+1}` is allowed. `default_port` maps support wildcards:
  `default_port: {'*': gpio.GPIO{i:2d}, pad_gpio0: spi.mosi}` (later entries override).
- A domain with dynamic pads must declare port groups; all-static domains must not.
- A `kind: pad` signal produces the toplevel landing-pad port; it is OPTIONAL.
  `pad_signals: []` (or omitted) declares a physical-only cell (supply, corner, tie)
  whose template is emitted verbatim. Padless cells with signals (e.g. PVSENSE supply
  sense) wire those signals to the SoC without exposing a pad.
- Physical-only templates that declare shared wires (e.g. a tie cell declaring
  `wire io_pads_rto;`) must appear in pad_list order BEFORE templates referencing those
  wires — some simulators (Questa vlog-2388) reject the implicit-net redeclaration.
- Unknown/misspelled keys are rejected at every level (`extra=forbid`).
- Padframe-level options: `config_interface: {regbus|apb|axilite|obi}` and
  `config_port_topology: {shared|per_domain}` (both optional; defaults preserve the
  classic single regbus port). The reggen backend supports ONLY the defaults
  (regbus/shared); non-regbus frontends and per_domain require `--register-backend
  peakrdl`, which conversely does not support regbus.

## Reuse mechanisms

- YAML anchors: `gpio_count: &gpio_count 32` under `user_attr:`, then `multiple: *gpio_count`.
- `!include other.yml` splices another file (relative to the top config); glob patterns
  (`!include pads/*.yml`) yield a list. See `examples/modular_config/`.
- `user_attr:` key-values pass through to templates; templated keys/values expand per index.

## Reference material in-repo

- `examples/sample_padframe.yaml` — richly commented, every feature.
- `examples/modular_config/` — include-based modular layout.
- `tests/characterization/configs/` — minimal fixtures (quasi-static variants, etc.).
- `tests/characterization/test_validation_errors.py` — one mutation per validator error,
  useful to see exact failure messages.
