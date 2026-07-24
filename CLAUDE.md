# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What Padrick is

Padrick generates padframe (IO pad multiplexer) controllers for SoC designs from a YAML
configuration: SystemVerilog RTL, C drivers, SDC constraints, and documentation. It is a
PULP-platform tool, packaged as the `padrick` CLI.

## Setup and common commands

Use **uv**; the repo has a committed `uv.lock` and a `dev` dependency group:

```sh
uv sync --locked               # .venv with padrick (editable) + pytest/pytest-cov
uv sync --locked --extra peakrdl   # additionally the PeakRDL register backend
uv run padrick --help
```

```sh
padrick validate <config.yml>              # parse + validate (--format json for machines)
padrick schema -o padrick_schema.json      # JSON Schema of the config format (editor LSP)
padrick generate rtl -o <dir> <config.yml> [--register-backend reggen|peakrdl]
padrick generate driver|constraints|padlist|mux-graph ...
padrick generate template-customization -o <dir>  # export Mako templates + settings YAML
```

Example configs live in `examples/` (all carry a `yaml-language-server: $schema` line;
`padrick_schema.json` at the repo root is guarded by a freshness test — regenerate it
whenever model fields change).

- **Tests:** `uv run pytest tests/characterization` (~65 tests + peakrdl skips). They run
  the CLI in subprocesses (the `PARSE_CONTEXT` singleton is not reentrant) and byte-compare
  generator output against goldens in `tests/characterization/goldens/`. After an
  *intentional* output change: `UPDATE_GOLDENS=1 uv run pytest tests/characterization`,
  then review the golden diff. Coverage is opt-in (`--cov=padrick`; subprocess coverage
  works via `patch = ["subprocess"]` in pyproject) and reported in CI (~84%).
  `tests/rtl_tests/` is legacy simulator collateral (manifest v1 config — stale).
- **Parallel agents:** never share `.venv`/`uv.lock` between concurrent agents — give each
  a worktree or `UV_PROJECT_ENVIRONMENT=<scratch>/venv`.
- **Docs:** Sphinx 9 + autodoc-pydantic — `uv pip install -e '.[doc]'` (needs Python
  ≥3.11), then `sphinx-build -b html docs <out>`.
- **Release:** version comes from git tags via setuptools-scm (`v0.4.0` → 0.4.0); the next
  release is 0.4.0 (breaking: mux_sel field rename, see CHANGELOG "Unreleased").
  `./update_changelog.py CHANGELOG.rst <version>` stamps the changelog;
  `.github/workflows/release.yml` builds PyInstaller one-file binaries
  (linux x86_64/aarch64 on manylinux_2_28, macos-arm64; entry `src/padrick/__main__.py`;
  reggen/topgen need `--collect-submodules` — their Mako templates import at render time).

## Architecture

Pipeline: YAML config → pydantic **v2** models → Mako templates → RTL/driver/docs.

1. **Parsing** (`src/padrick/ConfigParser.py`): ruamel.yaml round-trip loader (line info
   for error messages) + in-house `src/padrick/YamlInclude.py` for `!include` (glob
   support included). Structured errors are collected for `validate --format json`.
2. **Model** (`src/padrick/Model/`): pydantic v2 — `Padframe` → `PadDomain` →
   `PadType`/`PadInstance`/`PadSignal`, `PortGroup`/`Port`. Cross-field checks via
   `model_validator(mode='after')`; every config field carries a `description=` (feeds
   the JSON Schema and autodoc). Two Lark grammars: templated identifiers (`gpio{i:2d}`,
   expansion via `multiple:`) and `SignalExpressionType` (Verilog-like expressions).
   Custom types implement `__get_pydantic_core_schema__` with str json-schema input.
3. **Generation** (`src/padrick/Generators/`): `PadrickTemplate` wraps Mako templates
   (package resources); a `GeneratorSettings` YAML (`-s`) can override any template, so
   template names/locations are user-facing interface.
4. **Register backends** (`--register-backend`): both describe the identical register map
   (mux_sel field is named `sel` in both); the muxer reads registers through a helper with
   two dialects (reggen `reg2hw.*.q` vs peakrdl `hwif.*.value`), so the muxing logic is
   backend-agnostic. Byte-identical reggen output is the acceptance test for that refactor.
   - `reggen` (default, **frozen** to `config_interface: regbus` + `config_port_topology:
     shared` for backwards compatibility): templates emit `regfile.hjson` fed to the
     vendored lowRISC reggen (`src/reggen/`, `src/topgen/`; re-vendor via `util/vendor.py`,
     never hand-edit). The padframe top demuxes a single reg_interface port to a per-domain
     `reg_top`. Selecting a frontend or `per_domain` here is a hard error.
   - `peakrdl` (integrated; the path for config frontends): `regfile.rdl.mako` emits
     SystemRDL, compiled with systemrdl-compiler + peakrdl-regblock/-cheader
     (`Generators/PeakRDLBackend.py`, lazy imports, `peakrdl` extra). Requires
     `config_interface != regbus` (apb/axilite/obi → the regblock's native apb4/axi4lite/obi
     cpuif; no regbus cpuif exists). `shared` topology → one flattened regblock at the
     padframe top (registers retained across domain power-cycling), each domain a sub-addrmap
     at the reggen-compatible offset, hwif routed into the domains; `per_domain` → a regblock
     inside each domain module. The PULP frontend structs are unpacked onto the flat cpuif
     signals by a shim in `Generators/RTLGenerator/PeakRDLShim.py` (kept procedural so the
     padframe top elaborates in Fusion Compiler/Presto). `generate driver --register-backend
     peakrdl` emits peakrdl-cheader headers; the driver `.c`/`.h` macro dialect is not yet
     parameterized for those names.

CLI: click via `rich_click`, entry `src/padrick/CLIEntryPoint.py:cli`, generate
subcommands in `src/padrick/Generators/CLIGeneratorCommands.py`, logging/verbosity via
`src/padrick/Logging.py` (`configure_logging`, `@verbosity_option`).

## Code style conventions

- **File headers** (short SPDX form, REUSE-compliant — CI runs `reuse lint`):
  ```
  # Copyright <years> ETH Zurich.
  # Licensed under the Apache License, Version 2.0, see LICENSE for details.
  # SPDX-License-Identifier: Apache-2.0
  # Author: <Name>, ETH Zurich
  ```
  Mako templates use `##` (stripped at render). Keep original authors on files you edit.
- **Naming:** modules/packages PascalCase after their primary class; functions/variables
  snake_case.
- **Docstrings/comments:** minimal and one-line where possible — what, not how; never
  change-tracking notes. Click command docstrings double as `--help` text.
- **Typing:** annotated signatures, Python 3.9 compatible (`typing` List/Optional, no
  `X | Y`); pydantic v2 `Annotated[..., Field(...)]` with `description=` on config fields.
- **Commits:** conventional commits (`test: add ...` — lowercase subject, no body, no
  trailers; `!` for breaking), granular, signed. Never commit without explicit approval.
- **Edits:** prefer the Edit tool for one-off changes; scripted replaces only for bulk
  sweeps and then `assert` every pattern matched.

## Non-obvious constraints

- **Manifest versioning** (`Model/Constants.py`): `MANIFEST_VERSION = 5`
  (compatibility [2,3,4,5]); schema-visible model changes require a bump. Examples stay
  at manifest 4 deliberately (goldens). `HARDWARE_VERSION = 2` is baked into the INFO
  register — a bump is pending for the quasi-static `hardwired` mode at release time.
- **`PARSE_CONTEXT` singleton** (`Model/ParseContext.py`): reset by a `mode='before'`
  validator on PadDomain (do NOT reintroduce a custom `__init__` — pydantic v2 would
  validate the model twice). Parsing is not reentrant; tests use subprocesses.
- **Quasi-static pads:** `quasi_static: true|muxed` keeps the 1-bit mux + register
  fallback; `hardwired` elides mux and registers entirely (tie-offs = reset defaults).
  Open follow-ups: constraints specs referencing hardwired pads are not yet rejected.
- The `validate`/`config`/`generate custom` commands exit nonzero on failure; JSON mode
  reserves stdout for data (logs go to stderr).
