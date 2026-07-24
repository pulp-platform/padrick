# Copyright 2026 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Kai Berszin, ETH Zurich

"""
Backend support-matrix tests for the config-bus frontend (config_interface) and the
shared vs per_domain config port topology.

The reggen backend is frozen to its historical scope (regbus + shared); the selectable
frontends and the per-domain topology are implemented only on the peakrdl backend. These
tests pin the validation guards. The structural assertions on the generated peakrdl RTL
live in test_peakrdl_integration.py (they require the peakrdl extra).
"""
from pathlib import Path

import pytest
import ruamel.yaml

from conftest import run_padrick

CONFIG_DIR = Path(__file__).parent / "configs"
BASE_CONFIG = CONFIG_DIR / "config_interface_padframe.yml"

BASE_TOP = "cfgif_padframe.sv"


def _write_variant(dest: Path, **fields) -> Path:
    """Copy the single-domain base config, set toplevel fields, return the new path."""
    yaml = ruamel.yaml.YAML()
    with BASE_CONFIG.open() as f:
        cfg = yaml.load(f)
    for key, value in fields.items():
        cfg[key] = value
    dest.parent.mkdir(parents=True, exist_ok=True)
    with dest.open("w") as f:
        yaml.dump(cfg, f)
    return dest


def _generate_rtl(out_dir: Path, config: Path, extra=()) -> None:
    return run_padrick(["generate", "rtl", "--no-version-string", *extra,
                        "-o", str(out_dir), str(config)])


@pytest.mark.parametrize("frontend", ["apb", "axilite", "obi"])
def test_reggen_rejects_non_regbus_frontend(frontend: str, tmp_path: Path):
    """The frozen reggen backend refuses a non-regbus frontend with a clear message."""
    cfg = _write_variant(tmp_path / "cfg.yml", config_interface=frontend)
    result = _generate_rtl(tmp_path / "rtl", cfg)
    assert result.returncode != 0
    assert "reggen backend is maintained for backwards compatibility" in result.stdout + result.stderr


def test_reggen_rejects_per_domain_topology(tmp_path: Path):
    """The frozen reggen backend refuses the per_domain topology with a clear message."""
    cfg = _write_variant(tmp_path / "cfg.yml", config_port_topology="per_domain")
    result = _generate_rtl(tmp_path / "rtl", cfg)
    assert result.returncode != 0
    assert "reggen backend is maintained for backwards compatibility" in result.stdout + result.stderr


def test_reggen_driver_rejects_per_domain_topology(tmp_path: Path):
    """The frozen reggen driver path applies the same guard."""
    cfg = _write_variant(tmp_path / "cfg.yml", config_port_topology="per_domain")
    result = run_padrick(["generate", "driver", "--no-version-string",
                          "-o", str(tmp_path / "drv"), str(cfg)])
    assert result.returncode != 0
    assert "reggen backend is maintained for backwards compatibility" in result.stdout + result.stderr


def test_peakrdl_rejects_regbus_frontend(tmp_path: Path):
    """The peakrdl backend has no regbus cpuif and rejects it before any generation."""
    cfg = _write_variant(tmp_path / "cfg.yml", config_interface="regbus")
    result = _generate_rtl(tmp_path / "rtl", cfg, extra=["--register-backend", "peakrdl"])
    assert result.returncode != 0
    assert "no cpuif for the regbus config_interface" in result.stdout + result.stderr


def test_regbus_shared_matches_field_omitted(tmp_path: Path):
    """Explicit regbus/shared produces byte-identical RTL to omitting both fields."""
    omitted = _generate_rtl(tmp_path / "omitted", BASE_CONFIG)
    assert omitted.returncode == 0, omitted.stderr

    explicit_cfg = _write_variant(tmp_path / "explicit.yml",
                                  config_interface="regbus",
                                  config_port_topology="shared")
    explicit = _generate_rtl(tmp_path / "explicit", explicit_cfg)
    assert explicit.returncode == 0, explicit.stderr

    a = (tmp_path / "omitted" / "src" / BASE_TOP).read_bytes()
    b = (tmp_path / "explicit" / "src" / BASE_TOP).read_bytes()
    assert a == b, "explicit regbus/shared drifted from the field-omitted default"


def test_unknown_frontend_value_is_rejected(tmp_path: Path):
    """An unknown config_interface value fails to parse with an enum error."""
    cfg = _write_variant(tmp_path / "cfg.yml", config_interface="bogus")
    result = run_padrick(["validate", str(cfg)])
    output = result.stdout + result.stderr
    assert "Error while parsing configuration file" in output
    assert "'regbus', 'apb', 'axilite' or 'obi'" in output
