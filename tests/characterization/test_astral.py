# Copyright 2026 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Kai Berszin, ETH Zurich

"""
Real-chip regression against the Astral padframe (manifest v3, physical-only
supply/corner pad types). The SoC-facing port list is compared against the RTL
Astral taped out with a released padrick — the backwards-compatibility contract.
"""
import re
from pathlib import Path
from typing import List

import pytest

from conftest import REPO_ROOT, run_padrick

ASTRAL_CONFIG = REPO_ROOT / "tests" / "characterization" / "configs" / "astral_padframe.yml"
ASTRAL_REFERENCE = REPO_ROOT / "tests" / "characterization" / "configs" / "astral_reference"

PORT_RE = re.compile(r"^\s*(?:input|output|inout)\s+.*?(\w+)\s*,?\s*$", re.M)


def module_ports(source: str, module: str) -> List[str]:
    body = source.split(f"module {module}", 1)[1].split(");", 1)[0]
    return PORT_RE.findall(body)


def test_astral_config_validates() -> None:
    result = run_padrick(["validate", str(ASTRAL_CONFIG)])
    assert result.returncode == 0, result.stdout + result.stderr


def test_astral_rtl_port_contract(tmp_path: Path) -> None:
    result = run_padrick(["generate", "rtl", "--no-version-string", "-o", str(tmp_path), str(ASTRAL_CONFIG)])
    assert result.returncode == 0, result.stderr

    generated = (tmp_path / "src" / "astral_padframe.sv").read_text()
    reference = (ASTRAL_REFERENCE / "astral_padframe.sv").read_text()
    assert module_ports(generated, "astral_padframe") == module_ports(reference, "astral_padframe")


def test_astral_physical_only_pads_have_no_ports(tmp_path: Path) -> None:
    result = run_padrick(["generate", "rtl", "--no-version-string", "-o", str(tmp_path), str(ASTRAL_CONFIG)])
    assert result.returncode == 0, result.stderr

    pads = (tmp_path / "src" / "astral_padframe_periph_pads.sv").read_text()
    tie = re.search(r"PDVDDTIE_18_18_NT_DR_V\s+(\w+)\s*\(", pads)
    assert tie, "physical-only tie cell not instantiated"
    top = (tmp_path / "src" / "astral_padframe.sv").read_text()
    assert "PDVDDTIE" not in top.split(");", 1)[0], "physical-only cell leaked a toplevel port"
