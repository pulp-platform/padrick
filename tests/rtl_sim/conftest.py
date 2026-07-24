# Copyright 2026 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Kai Berszin, ETH Zurich

"""
Fixtures for the Verilator + cocotb RTL simulation suite. The whole suite skips
cleanly when verilator (>=5) or bender are unavailable so the default local test
run stays green without an RTL toolchain installed.
"""
import os
import shutil
import subprocess
import sys
from pathlib import Path
from typing import List, Optional, Tuple

import pytest

THIS_DIR = Path(__file__).parent
REPO_ROOT = THIS_DIR.parent.parent
HW_DIR = THIS_DIR / "hw"
CONFIG = THIS_DIR / "sim_padframe.yaml"

PADRICK = Path(sys.executable).parent / "padrick"

# Dependency versions pinned so the hand-picked source file set stays stable.
COMMON_CELLS_VERSION = "1.40.0"
REGISTER_INTERFACE_VERSION = "0.3.9"

# SEPP fallback location on ETH machines when verilator is not already on PATH.
SEPP_VERILATOR = "/usr/sepp/bin/verilator-5.020"


def _verilator_version(binary: str, env: dict) -> Optional[int]:
    try:
        out = subprocess.run([binary, "--version"], capture_output=True, text=True, env=env)
    except (OSError, subprocess.SubprocessError):
        return None
    text = out.stdout + out.stderr
    for tok in text.split():
        if tok.replace(".", "").isdigit() and "." in tok:
            try:
                return int(tok.split(".")[0])
            except ValueError:
                continue
    return None


def find_verilator() -> Optional[Tuple[str, Optional[str]]]:
    """
    Return (bin_dir, verilator_root) for a Verilator >=5, or None. bin_dir is
    prepended to PATH; verilator_root is exported as VERILATOR_ROOT when known.
    """
    on_path = shutil.which("verilator")
    if on_path and (_verilator_version("verilator", os.environ.copy()) or 0) >= 5:
        return str(Path(on_path).parent), os.environ.get("VERILATOR_ROOT")

    if Path(SEPP_VERILATOR).exists():
        # The SEPP wrapper mounts the package and exports VERILATOR_ROOT/PATH.
        probe = subprocess.run(
            [SEPP_VERILATOR, "bash", "-c", "echo $VERILATOR_ROOT"],
            capture_output=True, text=True,
        )
        root = probe.stdout.strip()
        if root and Path(root, "bin", "verilator").exists():
            return str(Path(root) / "bin"), root
    return None


def find_bender() -> Optional[str]:
    return shutil.which("bender") or (
        "/usr/local/bin/bender" if Path("/usr/local/bin/bender").exists() else None
    )


def run_padrick(args: List[str]) -> subprocess.CompletedProcess:
    return subprocess.run([str(PADRICK), *args], capture_output=True, text=True)


def _resolve_dep_sources(work_dir: Path, gen_dir: Path, bender: str) -> Tuple[List[str], List[str]]:
    """
    Fetch the PULP dependencies with bender and return the minimal set of
    (source_files, include_dirs) the generated padframe actually needs. We hand
    pick the files (addr_decode/lzc/reg_demux/prim_subreg) rather than compiling
    the whole transitive tree (axi, apb, tech_cells) which is unnecessary and
    trips a MODDUP clash on mem_to_banks between axi and common_cells.
    """
    (work_dir / "Bender.yml").write_text(
        "package:\n"
        "  name: sim_padframe_deps\n"
        "dependencies:\n"
        f'  common_cells: {{ git: "https://github.com/pulp-platform/common_cells.git", version: {COMMON_CELLS_VERSION} }}\n'
        f'  register_interface: {{ git: "https://github.com/pulp-platform/register_interface.git", version: {REGISTER_INTERFACE_VERSION} }}\n'
    )
    subprocess.run([bender, "update"], cwd=work_dir, check=True, capture_output=True, text=True)

    checkouts = work_dir / ".bender" / "git" / "checkouts"
    cc = next(d for d in checkouts.iterdir() if d.is_dir() and d.name.startswith("common_cells-"))
    ri = next(d for d in checkouts.iterdir() if d.is_dir() and d.name.startswith("register_interface-"))

    dep_sources = [
        cc / "src" / "cf_math_pkg.sv",
        cc / "src" / "lzc.sv",
        cc / "src" / "addr_decode_dync.sv",
        cc / "src" / "addr_decode.sv",
        ri / "vendor" / "lowrisc_opentitan" / "src" / "prim_subreg_arb.sv",
        ri / "vendor" / "lowrisc_opentitan" / "src" / "prim_subreg_ext.sv",
        ri / "vendor" / "lowrisc_opentitan" / "src" / "prim_subreg.sv",
        ri / "src" / "reg_demux.sv",
    ]
    includes = [cc / "include", ri / "include"]

    gen_order = [
        "pkg_sim_padframe.sv",
        "pkg_internal_sim_padframe_core.sv",
        "sim_padframe_core_config_reg_pkg.sv",
        "sim_padframe_core_config_reg_top.sv",
        "sim_padframe_core_pads.sv",
        "sim_padframe_core_muxer.sv",
        "sim_padframe_core.sv",
        "sim_padframe.sv",
    ]
    gen_sources = [gen_dir / "src" / f for f in gen_order]
    tb_sources = [HW_DIR / "behav_pads.sv", HW_DIR / "sim_padframe_tb_top.sv"]

    sources = [str(p) for p in (dep_sources + gen_sources + tb_sources)]
    return sources, [str(p) for p in includes]


@pytest.fixture(scope="session")
def rtl_build(tmp_path_factory):
    pytest.importorskip("cocotb", reason="cocotb not installed (use the 'sim' extra)")
    verilator = find_verilator()
    if verilator is None:
        pytest.skip("Verilator >=5 not found (install verilator or SEPP verilator-5.020)")
    bender = find_bender()
    if bender is None:
        pytest.skip("bender not found (needed to resolve PULP RTL dependencies)")

    bin_dir, root = verilator
    os.environ["PATH"] = bin_dir + os.pathsep + os.environ.get("PATH", "")
    if root:
        os.environ["VERILATOR_ROOT"] = root

    work = tmp_path_factory.mktemp("rtl_sim")
    gen_dir = work / "generated"
    result = run_padrick(["generate", "rtl", "--no-version-string", "-o", str(gen_dir), str(CONFIG)])
    assert result.returncode == 0, f"padrick generate rtl failed:\n{result.stderr}"

    sources, includes = _resolve_dep_sources(work, gen_dir, bender)

    from cocotb.runner import get_runner

    runner = get_runner("verilator")
    runner.build(
        sources=sources,
        includes=includes,
        hdl_toplevel="sim_padframe_tb_top",
        build_dir=str(work / "sim_build"),
        build_args=["-Wno-fatal", "-Wno-WIDTHTRUNC", "-Wno-WIDTHEXPAND"],
        always=True,
    )
    return {"runner": runner, "gen_dir": gen_dir, "work": work, "config": CONFIG}
