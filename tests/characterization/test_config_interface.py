# Copyright 2026 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Kai Berszin, ETH Zurich

"""
Structural tests for the selectable config-bus frontend (config_interface) and
the shared vs per_domain config port topology. Stage-1 prototype: the non-regbus
frontends have no byte-goldens, so these assert on the generated top module's port
list and converter instantiation rather than exact bytes. regbus/shared must stay
byte-identical to the field-omitted default (that path is pinned by the
characterization goldens).
"""
from pathlib import Path

import pytest
import ruamel.yaml

from conftest import run_padrick

CONFIG_DIR = Path(__file__).parent / "configs"
BASE_CONFIG = CONFIG_DIR / "config_interface_padframe.yml"
TWO_DOMAIN_CONFIG = CONFIG_DIR / "two_domain_padframe.yml"

BASE_TOP = "cfgif_padframe.sv"
TWO_DOMAIN_TOP = "twodom_padframe.sv"

# Per frontend: signals that must appear in the (shared) toplevel port list and
# the converter module that must be instantiated in front of the internal fabric.
FRONTENDS = {
    "regbus": {"ports": ["config_req_i", "config_rsp_o"], "converter": None},
    "apb": {"ports": ["apb_req_t", "config_apb_req_i", "config_apb_rsp_o"],
            "converter": "apb_to_reg_v2"},
    "axilite": {"ports": ["axi_lite_req_t", "config_axi_req_i", "config_axi_rsp_o"],
                "converter": "axi_lite_to_reg"},
    "obi": {"ports": ["obi_req_t", "obi_rsp_t", "config_obi_req_i", "config_obi_rsp_o"],
            "converter": "periph_to_reg"},
}


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
    result = run_padrick(["generate", "rtl", "--no-version-string", *extra,
                          "-o", str(out_dir), str(config)])
    return result


@pytest.mark.parametrize("frontend", list(FRONTENDS))
def test_frontend_generates_expected_ports(frontend: str, tmp_path: Path):
    """Each frontend generates and exposes its protocol ports plus its converter."""
    cfg = _write_variant(tmp_path / "cfg.yml", config_interface=frontend)
    result = _generate_rtl(tmp_path / "rtl", cfg)
    assert result.returncode == 0, result.stderr
    top = (tmp_path / "rtl" / "src" / BASE_TOP).read_text()
    for signal in FRONTENDS[frontend]["ports"]:
        assert signal in top, f"{frontend}: expected port signal {signal} missing from top"
    converter = FRONTENDS[frontend]["converter"]
    if converter:
        assert converter in top, f"{frontend}: converter {converter} not instantiated"


def test_obi_inverts_write_enable(tmp_path: Path):
    """OBI's write-high `we` is inverted into periph_to_reg's write-enable-low `wen`."""
    cfg = _write_variant(tmp_path / "cfg.yml", config_interface="obi")
    result = _generate_rtl(tmp_path / "rtl", cfg)
    assert result.returncode == 0, result.stderr
    top = (tmp_path / "rtl" / "src" / BASE_TOP).read_text()
    assert ".wen_i(~config_obi_req_i.a.we)" in top


def test_obi_uses_struct_ports(tmp_path: Path):
    """OBI exposes `parameter type obi_req_t`/`obi_rsp_t` struct ports, not flat signals."""
    cfg = _write_variant(tmp_path / "cfg.yml", config_interface="obi")
    result = _generate_rtl(tmp_path / "rtl", cfg)
    assert result.returncode == 0, result.stderr
    top = (tmp_path / "rtl" / "src" / BASE_TOP).read_text()
    assert "parameter type obi_req_t" in top
    assert "parameter type obi_rsp_t" in top
    # The old flattened OBI port style must be gone.
    for flat in ("config_obi_addr_i", "config_obi_we_i", "config_obi_wdata_i",
                 "config_obi_err_o", "config_obi_gnt_o"):
        assert flat not in top, f"stale flat OBI port {flat} still present"


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


def test_per_domain_exposes_one_port_per_domain(tmp_path: Path):
    """per_domain exposes a config port per pad domain and drops the shared demux."""
    result = _generate_rtl(tmp_path / "rtl", TWO_DOMAIN_CONFIG)
    assert result.returncode == 0, result.stderr
    top = (tmp_path / "rtl" / "src" / TWO_DOMAIN_TOP).read_text()
    assert "domain0_config_req_i" in top and "domain1_config_req_i" in top
    assert "reg_demux" not in top and "addr_decode" not in top


def test_per_domain_driver_emits_per_domain_base_tokens(tmp_path: Path):
    """The per_domain C driver guards and uses a base-address token per pad domain."""
    out = tmp_path / "drv"
    result = run_padrick(["generate", "driver", "--no-version-string",
                          "-o", str(out), str(TWO_DOMAIN_CONFIG)])
    assert result.returncode == 0, result.stderr
    header = (out / "include" / "twodom_padframe.h").read_text()
    assert "TWODOM_PADFRAME_DOMAIN0_BASE_ADDRESS" in header
    assert "TWODOM_PADFRAME_DOMAIN1_BASE_ADDRESS" in header
    assert "#ifndef TWODOM_PADFRAME_BASE_ADDRESS" not in header


def test_peakrdl_rejects_non_regbus_frontend(tmp_path: Path):
    """The peakrdl backend refuses a non-regbus frontend with a clear message."""
    cfg = _write_variant(tmp_path / "cfg.yml", config_interface="apb")
    result = _generate_rtl(tmp_path / "rtl", cfg, extra=["--register-backend", "peakrdl"])
    assert result.returncode != 0
    assert "config_interface handling for the peakrdl" in result.stdout + result.stderr


def test_peakrdl_rejects_per_domain_topology(tmp_path: Path):
    """The peakrdl backend refuses the per_domain topology with a clear message."""
    cfg = _write_variant(tmp_path / "cfg.yml", config_port_topology="per_domain")
    result = _generate_rtl(tmp_path / "rtl", cfg, extra=["--register-backend", "peakrdl"])
    assert result.returncode != 0
    assert "config_port_topology handling for the peakrdl" in result.stdout + result.stderr


def test_unknown_frontend_value_is_rejected(tmp_path: Path):
    """An unknown config_interface value fails to parse with an enum error."""
    cfg = _write_variant(tmp_path / "cfg.yml", config_interface="bogus")
    result = run_padrick(["validate", str(cfg)])
    output = result.stdout + result.stderr
    assert "Error while parsing configuration file" in output
    assert "'regbus', 'apb', 'axilite' or 'obi'" in output
