# Copyright 2026 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Kai Berszin, ETH Zurich

"""
Tests for the quasi_static pad modes: 'muxed' (legacy, mux + register fallback)
and 'hardwired' (no mux, no config/mux_sel registers, direct port connection).
"""
import copy
import io
from pathlib import Path
from typing import Any, Dict

import pytest
import ruamel.yaml

from conftest import GOLDEN_DIR, run_padrick
from test_characterization import check_golden

CONFIG = Path(__file__).parent / "configs" / "quasi_static_padframe.yml"


def test_validate_succeeds():
    result = run_padrick(["validate", str(CONFIG)])
    assert result.returncode == 0, result.stderr
    assert "Successfully parsed configuration file." in result.stdout + result.stderr


@pytest.mark.parametrize("generator", ["rtl", "driver"])
def test_generate_matches_golden(generator: str, tmp_path: Path):
    result = run_padrick(
        ["generate", generator, "--no-version-string", "-o", str(tmp_path), str(CONFIG)]
    )
    assert result.returncode == 0, result.stderr
    check_golden(tmp_path, GOLDEN_DIR / "quasi_static" / generator)


def test_hardwired_pad_has_no_registers(tmp_path: Path):
    """The hardwired pad's cfg/mux_sel registers are absent from the regfile, the
    muxed quasi-static pad's are present."""
    result = run_padrick(
        ["generate", "rtl", "--no-version-string", "-o", str(tmp_path), str(CONFIG)]
    )
    assert result.returncode == 0, result.stderr
    hjson = (tmp_path / "src" / "quasi_static_padframe_aon_regs.hjson").read_text()
    assert "PAD_HW_CFG" not in hjson
    assert "PAD_HW_MUX_SEL" not in hjson
    assert "PAD_QS_CFG" in hjson
    assert "PAD_QS_MUX_SEL" in hjson


def test_driver_omits_hardwired_pad_accessors(tmp_path: Path):
    """The C driver has no mux/cfg accessors for the hardwired pad but keeps them
    for the muxed quasi-static pad."""
    result = run_padrick(
        ["generate", "driver", "--no-version-string", "-o", str(tmp_path), str(CONFIG)]
    )
    assert result.returncode == 0, result.stderr
    header = (tmp_path / "include" / "quasi_static_padframe.h").read_text()
    source = (tmp_path / "src" / "quasi_static_padframe.c").read_text()
    for text in (header, source):
        assert "pad_hw" not in text
        assert "quasi_static_padframe_aon_pad_qs_mux_set" in text
        assert "quasi_static_padframe_aon_pad_qs_cfg_chip2pad_set" in text
    # The reggen-generated register header contains no offsets for the hardwired pad.
    regs_header = (tmp_path / "include" / "quasi_static_padframe_aon_regs.h").read_text()
    assert "PAD_HW" not in regs_header
    assert "PAD_QS_MUX_SEL" in regs_header


# --- Error paths -------------------------------------------------------------

BASE_CONFIG: Dict[str, Any] = {
    "manifest_version": 5,
    "name": "hw_err_padframe",
    "pad_domains": [
        {
            "name": "domain0",
            "pad_types": [
                {
                    "name": "gpio_pad",
                    "template": (
                        'PAD ${instance_name} (.PAD(${conn["pad"]}), '
                        '.I(${conn["chip2pad"]}));\n'
                    ),
                    "pad_signals": [
                        {"name": "pad", "size": 1, "kind": "pad"},
                        {"name": "chip2pad", "size": 1, "kind": "input",
                         "conn_type": "dynamic", "default_reset_value": 0,
                         "default_static_value": "1'b0"},
                    ],
                }
            ],
            "pad_list": [
                {"name": "pad0", "pad_type": "gpio_pad", "mux_groups": ["all"],
                 "quasi_static": "hardwired"},
            ],
            "port_groups": [
                {
                    "name": "grp",
                    "ports": [
                        {"name": "port0", "mux_groups": ["all"],
                         "connections": {"chip2pad": "data0_i"}},
                    ],
                }
            ],
        }
    ],
}


def _validate(config: Dict[str, Any], tmp_path: Path) -> str:
    """Write config to tmp_path, run `padrick validate`, return combined output."""
    config_file = tmp_path / "padframe.yaml"
    buffer = io.StringIO()
    ruamel.yaml.YAML().dump(config, buffer)
    config_file.write_text(buffer.getvalue())
    result = run_padrick(["validate", str(config_file)])
    return result.stdout + result.stderr


def test_hardwired_base_config_is_valid(tmp_path: Path):
    output = _validate(copy.deepcopy(BASE_CONFIG), tmp_path)
    assert "Successfully parsed configuration file." in output


def test_hardwired_pad_with_two_connectable_ports_is_rejected(tmp_path: Path):
    """A hardwired pad must have exactly one connectable port (same 1:1 rule as muxed)."""
    config = copy.deepcopy(BASE_CONFIG)
    config["pad_domains"][0]["port_groups"][0]["ports"].append(
        {"name": "port1", "mux_groups": ["all"],
         "connections": {"chip2pad": "data1_i"}})
    output = _validate(config, tmp_path)
    assert "more than one muxed port connection" in output


def test_hardwired_pad_with_shared_port_is_rejected(tmp_path: Path):
    """A hardwired pad's port must not be connectable to a second pad."""
    config = copy.deepcopy(BASE_CONFIG)
    config["pad_domains"][0]["pad_list"].append(
        {"name": "pad1", "pad_type": "gpio_pad", "mux_groups": ["all"]})
    output = _validate(config, tmp_path)
    assert "connectable to several pads" in output


def test_bogus_quasi_static_value_is_rejected(tmp_path: Path):
    config = copy.deepcopy(BASE_CONFIG)
    config["pad_domains"][0]["pad_list"][0]["quasi_static"] = "bogus"
    output = _validate(config, tmp_path)
    assert "quasi_static" in output


def test_hardwired_and_is_static_are_mutually_exclusive(tmp_path: Path):
    config = copy.deepcopy(BASE_CONFIG)
    config["pad_domains"][0]["pad_list"][0]["is_static"] = True
    output = _validate(config, tmp_path)
    assert "mutually exclusive" in output
