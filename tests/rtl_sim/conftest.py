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
import re
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

# Committed Bender.lock pinning the resolved dependency revisions. Copied into
# the generated package before `bender checkout` so CI resolves the same PULP
# dependency versions every run. Regenerate (when the dependency set changes and
# checkout fails) by running `bender update` in a padrick-generated RTL dir and
# copying its Bender.lock back here.
BENDER_LOCK = THIS_DIR / "Bender.lock"

PADRICK = Path(sys.executable).parent / "padrick"

# SEPP fallback location on ETH machines when verilator is not already on PATH.
SEPP_VERILATOR = "/usr/sepp/bin/verilator-5.020"

# Extra sources are declared with `module <name>` / `package <name>`.
_MODULE_DECL_RE = re.compile(r"^\s*(?:module|package)\s+(\w+)", re.MULTILINE)


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


def _dedup_modules(sources: List[str]) -> List[str]:
    """
    Drop any file that redefines a module/package already declared by an earlier
    file in the (dependency-ordered) list. Bender's transitive closure pulls in
    dependencies whose file sets overlap on module names -- e.g. axi's
    axi_to_mem.sv redefines common_cells' mem_to_banks -- which Verilator rejects
    as MODDUP. Filtering by declared name keeps this working as the dependency
    set grows (new conditional apb/axi frontends) without hand-picking files.
    """
    seen: set = set()
    kept: List[str] = []
    for src in sources:
        try:
            names = set(_MODULE_DECL_RE.findall(Path(src).read_text(errors="ignore")))
        except OSError:
            kept.append(src)
            continue
        if names & seen:
            continue
        seen |= names
        kept.append(src)
    return kept


def _resolve_dep_sources(gen_dir: Path, bender: str) -> Tuple[List[str], List[str], List[str]]:
    """
    Resolve the PULP dependencies from padrick's own generated Bender.yml and
    return (source_files, include_dirs, defines) for the whole package plus the
    testbench. The committed Bender.lock is copied in first so `bender checkout`
    pins the same dependency revisions on every run.
    """
    shutil.copyfile(BENDER_LOCK, gen_dir / "Bender.lock")
    subprocess.run([bender, "checkout"], cwd=gen_dir, check=True, capture_output=True, text=True)

    script = subprocess.run(
        [bender, "script", "verilator"], cwd=gen_dir, check=True, capture_output=True, text=True
    ).stdout

    includes: List[str] = []
    defines: List[str] = []
    sources: List[str] = []
    for line in script.splitlines():
        line = line.strip()
        if not line:
            continue
        if line.startswith("+incdir+"):
            inc = line[len("+incdir+"):]
            if inc not in includes:
                includes.append(inc)
        elif line.startswith("+define+"):
            if line not in defines:
                defines.append(line)
        elif not line.startswith("+"):
            sources.append(line)

    sources = _dedup_modules(sources)
    sources += [str(HW_DIR / "behav_pads.sv"), str(HW_DIR / "sim_padframe_tb_top.sv")]
    return sources, includes, defines


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

    sources, includes, defines = _resolve_dep_sources(gen_dir, bender)

    from cocotb.runner import get_runner

    runner = get_runner("verilator")
    runner.build(
        sources=sources,
        includes=includes,
        hdl_toplevel="sim_padframe_tb_top",
        build_dir=str(work / "sim_build"),
        build_args=["-Wno-fatal", "-Wno-WIDTHTRUNC", "-Wno-WIDTHEXPAND"] + defines,
        always=True,
    )
    return {"runner": runner, "gen_dir": gen_dir, "work": work, "config": CONFIG}
