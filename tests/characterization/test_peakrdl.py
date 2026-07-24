# Copyright 2026 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Kai Berszin, ETH Zurich

"""Smoke test for the integrated SystemRDL/PeakRDL register-file backend.

The peakrdl backend requires a non-regbus config_interface, so the example configs are
copied with config_interface set to apb before generation. Skips cleanly when the peakrdl
extra is not installed in the running venv.
"""
from pathlib import Path

import pytest
import ruamel.yaml

from conftest import REPO_ROOT, run_padrick

SAMPLE_CONFIG = REPO_ROOT / "examples" / "sample_padframe.yaml"
QUASI_STATIC_CONFIG = Path(__file__).parent / "configs" / "quasi_static_padframe.yml"


def _peakrdl_installed() -> bool:
    try:
        import systemrdl  # noqa: F401
        import peakrdl_regblock  # noqa: F401
        import peakrdl_cheader  # noqa: F401
        return True
    except ImportError:
        return False


pytestmark = pytest.mark.skipif(not _peakrdl_installed(),
                                reason="peakrdl extra not installed")


def _as_apb(base: Path, dest: Path) -> Path:
    """Copy a config with config_interface set to apb (peakrdl rejects regbus)."""
    yaml = ruamel.yaml.YAML()
    with base.open() as f:
        cfg = yaml.load(f)
    cfg["config_interface"] = "apb"
    dest.parent.mkdir(parents=True, exist_ok=True)
    with dest.open("w") as f:
        yaml.dump(cfg, f)
    return dest


def test_peakrdl_rtl_backend(tmp_path: Path):
    """The peakrdl RTL backend emits an .rdl file and a PeakRDL-regblock SV module."""
    cfg = _as_apb(SAMPLE_CONFIG, tmp_path / "cfg.yml")
    result = run_padrick(["generate", "rtl", "--register-backend", "peakrdl",
                          "-o", str(tmp_path), str(cfg)])
    assert result.returncode == 0, result.stderr

    src = tmp_path / "src"
    rdl_files = list(src.glob("*_regs.rdl"))
    reg_top_files = list(src.glob("*_config_reg_top.sv"))
    assert rdl_files, "no .rdl file was generated"
    assert reg_top_files, "no PeakRDL-regblock reg_top SV was generated"

    rdl_text = rdl_files[0].read_text()
    assert "addrmap" in rdl_text
    assert "INFO" in rdl_text
    assert "MUX_SEL_e" in rdl_text  # mux_sel enum type


def test_peakrdl_driver_backend(tmp_path: Path):
    """The peakrdl driver backend emits an .rdl file and a C header with register defines."""
    cfg = _as_apb(SAMPLE_CONFIG, tmp_path / "cfg.yml")
    result = run_padrick(["generate", "driver", "--register-backend", "peakrdl",
                          "-o", str(tmp_path), str(cfg)])
    assert result.returncode == 0, result.stderr

    rdl_files = list(tmp_path.glob("*_regs.rdl"))
    header_files = list((tmp_path / "include").glob("*_regs.h"))
    assert rdl_files, "no .rdl file was generated"
    assert header_files, "no C header was generated"


def test_peakrdl_rtl_omits_hardwired_pad(tmp_path: Path):
    """The hardwired quasi-static pad has no cfg/mux_sel registers in the .rdl, the
    muxed quasi-static pad's are present (mirrors the reggen hjson behaviour)."""
    cfg = _as_apb(QUASI_STATIC_CONFIG, tmp_path / "cfg.yml")
    result = run_padrick(["generate", "rtl", "--register-backend", "peakrdl",
                          "--no-version-string", "-o", str(tmp_path), str(cfg)])
    assert result.returncode == 0, result.stderr
    rdl = (tmp_path / "src" / "quasi_static_padframe_regs.rdl").read_text()
    assert "PAD_HW_CFG" not in rdl
    assert "PAD_HW_MUX_SEL" not in rdl
    assert "PAD_QS_CFG" in rdl
    assert "PAD_QS_MUX_SEL" in rdl


def test_peakrdl_driver_omits_hardwired_pad(tmp_path: Path):
    """The peakrdl C header has no registers for the hardwired pad but keeps them for
    the muxed quasi-static pad."""
    cfg = _as_apb(QUASI_STATIC_CONFIG, tmp_path / "cfg.yml")
    result = run_padrick(["generate", "driver", "--register-backend", "peakrdl",
                          "--no-version-string", "-o", str(tmp_path), str(cfg)])
    assert result.returncode == 0, result.stderr
    regs_header = (tmp_path / "include" / "quasi_static_padframe_aon_regs.h").read_text()
    assert "PAD_HW" not in regs_header
    assert "PAD_QS_MUX_SEL" in regs_header
