# Copyright 2026 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Kai Berszin, ETH Zurich

"""Structural tests for the integrated PeakRDL register backend.

Per (config_interface x config_port_topology) they assert that the generated padframe
top instantiates a PeakRDL regblock with a native cpuif and contains none of the reggen
machinery (reg_top / reg2hw / reg_demux / addr_decode). The flattened shared layout is
also checked to place each domain at the same offset the reggen address demux assigns.

Skips cleanly when the peakrdl extra is not installed.
"""
import re
from pathlib import Path

import pytest
import ruamel.yaml

from conftest import run_padrick

CONFIG_DIR = Path(__file__).parent / "configs"
BASE_CONFIG = CONFIG_DIR / "config_interface_padframe.yml"
TWO_DOMAIN_CONFIG = CONFIG_DIR / "two_domain_padframe.yml"

FRONTENDS = {
    "apb": ("apb_req_t", "config_apb_req_i", "domain0_apb_req_i"),
    "axilite": ("axi_lite_req_t", "config_axi_req_i", "domain0_axi_req_i"),
    "obi": ("obi_req_t", "config_obi_req_i", "domain0_obi_req_i"),
}

CONVERTERS = ("apb_to_reg_v2", "axi_lite_to_reg", "periph_to_reg")
REGGEN_TOKENS = ("reg_demux", "addr_decode", "_config_reg2hw_t", "devmode_i")


def _peakrdl_installed() -> bool:
    try:
        import systemrdl  # noqa: F401
        import peakrdl_regblock  # noqa: F401
        return True
    except ImportError:
        return False


pytestmark = pytest.mark.skipif(not _peakrdl_installed(),
                                reason="peakrdl extra not installed")


def _variant(base: Path, dest: Path, **fields) -> Path:
    yaml = ruamel.yaml.YAML()
    with base.open() as f:
        cfg = yaml.load(f)
    for key, value in fields.items():
        cfg[key] = value
    dest.parent.mkdir(parents=True, exist_ok=True)
    with dest.open("w") as f:
        yaml.dump(cfg, f)
    return dest


def _gen(out_dir: Path, config: Path) -> None:
    result = run_padrick(["generate", "rtl", "--no-version-string",
                          "--register-backend", "peakrdl", "-o", str(out_dir), str(config)])
    assert result.returncode == 0, result.stdout + result.stderr


@pytest.mark.parametrize("frontend", list(FRONTENDS))
def test_shared_flattened_regblock(frontend: str, tmp_path: Path):
    """Shared topology: one flattened regblock at the top, native cpuif, hwif routed to
    the domain, and no reggen machinery or converter."""
    proto_type, shared_port, _ = FRONTENDS[frontend]
    cfg = _variant(BASE_CONFIG, tmp_path / "cfg.yml",
                   config_interface=frontend, config_port_topology="shared")
    _gen(tmp_path / "rtl", cfg)
    src = tmp_path / "rtl" / "src"
    top = (src / "cfgif_padframe.sv").read_text()

    assert f"parameter type {proto_type}" in top
    assert shared_port in top
    assert "cfgif_padframe_config_reg_top" in top       # single flattened regblock instance
    assert ".hwif_out(s_hwif)" in top
    assert ".hwif_i(s_hwif.domain0)" in top             # hwif routed into the domain
    for token in REGGEN_TOKENS + CONVERTERS:
        assert token not in top, f"{frontend}: unexpected reggen/converter token {token}"

    # The flattened regblock package/module exists; no per-domain reggen reg_top.
    assert (src / "cfgif_padframe_config_reg_top.sv").exists()
    assert not list(src.glob("cfgif_padframe_domain0_config_reg_top.sv"))

    # Domain module receives hwif; muxer reads it through the hwif accessor dialect.
    domain = (src / "cfgif_padframe_domain0.sv").read_text()
    assert "input cfgif_padframe_domain0_config__out_t hwif_i" in domain
    muxer = (src / "cfgif_padframe_domain0_muxer.sv").read_text()
    assert "hwif_i.GPIO0_MUX_SEL.sel.value" in muxer
    assert "hwif_i.GPIO0_CFG.chip2pad.value" in muxer
    assert "s_reg2hw" not in muxer


@pytest.mark.parametrize("frontend", list(FRONTENDS))
def test_per_domain_regblock_per_domain(frontend: str, tmp_path: Path):
    """per_domain topology: a regblock inside each domain module, a native cpuif port per
    domain at the top, and no shared flattened regblock or demux."""
    proto_type, _, pd_port = FRONTENDS[frontend]
    cfg = _variant(TWO_DOMAIN_CONFIG, tmp_path / "cfg.yml",
                   config_interface=frontend, config_port_topology="per_domain")
    _gen(tmp_path / "rtl", cfg)
    src = tmp_path / "rtl" / "src"
    top = (src / "twodom_padframe.sv").read_text()

    assert pd_port in top
    assert top.count(proto_type) >= 2  # one request type per domain port at least
    for token in REGGEN_TOKENS + CONVERTERS:
        assert token not in top
    assert "twodom_padframe_config_reg_top" not in top  # no shared flattened regblock

    for d in ("domain0", "domain1"):
        assert (src / f"twodom_padframe_{d}_config_reg_top.sv").exists()
        domain = (src / f"twodom_padframe_{d}.sv").read_text()
        assert f"twodom_padframe_{d}_config_reg_top" in domain  # regblock instantiated inside
        assert ".hwif_i(s_hwif)" in domain


def _reggen_demux_starts(top_text: str):
    return [int(m) for m in re.findall(r"start_addr:\s*\d+'d(\d+)", top_text)]


def _rdl_domain_offsets(rdl_text: str):
    return [int(off, 16) for off in re.findall(r"_config\s+\w+\s*@\s*(0x[0-9a-fA-F]+)\s*;", rdl_text)]


def test_flattened_offsets_match_reggen(tmp_path: Path):
    """The flattened .rdl places each domain at exactly the offset the reggen address
    demux assigns for the same (regbus/shared) multi-domain padframe."""
    # reggen reference: regbus + shared is the only combination reggen still supports.
    reggen_cfg = _variant(TWO_DOMAIN_CONFIG, tmp_path / "reggen.yml",
                          config_interface="regbus", config_port_topology="shared")
    r = run_padrick(["generate", "rtl", "--no-version-string",
                     "-o", str(tmp_path / "reggen"), str(reggen_cfg)])
    assert r.returncode == 0, r.stdout + r.stderr
    demux_starts = _reggen_demux_starts((tmp_path / "reggen" / "src" / "twodom_padframe.sv").read_text())

    # peakrdl flattened layout for the same two-domain padframe.
    peakrdl_cfg = _variant(TWO_DOMAIN_CONFIG, tmp_path / "peakrdl.yml",
                           config_interface="apb", config_port_topology="shared")
    _gen(tmp_path / "peakrdl", peakrdl_cfg)
    rdl_offsets = _rdl_domain_offsets((tmp_path / "peakrdl" / "src" / "twodom_padframe_regs.rdl").read_text())

    assert rdl_offsets == demux_starts, (
        f"flattened .rdl offsets {rdl_offsets} differ from reggen demux starts {demux_starts}")


def test_apb_peakrdl_succeeds(tmp_path: Path):
    """The apb frontend now generates on the peakrdl backend (guard flipped from stage 1)."""
    cfg = _variant(BASE_CONFIG, tmp_path / "cfg.yml", config_interface="apb")
    result = run_padrick(["generate", "rtl", "--no-version-string",
                          "--register-backend", "peakrdl", "-o", str(tmp_path / "rtl"), str(cfg)])
    assert result.returncode == 0, result.stdout + result.stderr
