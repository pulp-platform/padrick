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
from dataclasses import dataclass
from pathlib import Path
from typing import List, Optional, Tuple

import pytest

THIS_DIR = Path(__file__).parent
REPO_ROOT = THIS_DIR.parent.parent
HW_DIR = THIS_DIR / "hw"
CONFIG = THIS_DIR / "sim_padframe.yaml"

# Committed Bender.lock files pinning the resolved dependency revisions. Copied
# into the generated package before `bender checkout` so CI resolves the same
# PULP dependency versions every run. There are two: the regbus frontend (reggen
# backend) pulls register_interface; the peakrdl frontends pull the apb/axi/obi
# protocol repos (native cpuifs, no register_interface), so they share a single
# superset lock (each variant checks out only the subset its generated Bender.yml
# references; the other protocol repos in the lock go unused). Regenerate (when
# the dependency set changes and checkout fails) by running `bender update` in a
# padrick-generated RTL dir of the respective frontend and copying its
# Bender.lock back here.
BENDER_LOCK = THIS_DIR / "Bender.lock"
BENDER_LOCK_NONREGBUS = THIS_DIR / "Bender.nonregbus.lock"


@dataclass(frozen=True)
class Variant:
    """One point in the (config-bus frontend x register backend) matrix."""
    name: str            # pytest id
    frontend: str        # padrick config_interface value + bus_drivers key
    backend: str         # padrick --register-backend value (reggen | peakrdl)
    toplevel: str        # SV testbench wrapper module / verilator toplevel
    wrapper: str         # wrapper source file under hw/
    lock: Path           # committed Bender.lock to pin the dependency set
    slow: bool = False   # heavier build, only run with --run-slow


# reggen only still supports regbus/shared, so the regbus variant stays on reggen;
# the apb/obi/axilite frontends now only exist on the peakrdl backend (native cpuifs
# on a single flattened regblock at the padframe top).
VARIANTS = [
    Variant("regbus", "regbus", "reggen", "sim_padframe_tb_top", "sim_padframe_tb_top.sv", BENDER_LOCK),
    Variant("apb", "apb", "peakrdl", "sim_padframe_tb_apb", "sim_padframe_tb_apb.sv", BENDER_LOCK_NONREGBUS),
    Variant("obi", "obi", "peakrdl", "sim_padframe_tb_obi", "sim_padframe_tb_obi.sv", BENDER_LOCK_NONREGBUS),
    # AXI-Lite drags in the largest dependency closure (the full axi repo, cloned
    # for its typedef macros); keep it off the default run behind --run-slow.
    Variant("axilite", "axilite", "peakrdl", "sim_padframe_tb_axilite", "sim_padframe_tb_axilite.sv",
            BENDER_LOCK_NONREGBUS, slow=True),
]


def _peakrdl_importable() -> bool:
    """The peakrdl variants need the peakrdl extra in the venv that runs padrick
    (same interpreter as this pytest process, since PADRICK is resolved from it)."""
    try:
        import systemrdl  # noqa: F401
        import peakrdl_regblock  # noqa: F401
        return True
    except ImportError:
        return False

PADRICK = Path(sys.executable).parent / "padrick"

# SEPP fallback location on ETH machines when verilator is not already on PATH.
SEPP_VERILATOR = "/usr/sepp/bin/verilator-5.020"

# Extra sources are declared with `module <name>` / `package <name>`.
_MODULE_DECL_RE = re.compile(r"^\s*(?:module|package)\s+(\w+)", re.MULTILINE)


def pytest_addoption(parser):
    parser.addoption("--run-slow", action="store_true", default=False,
                     help="also build/run the slow RTL-sim variants (e.g. axilite)")


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


def _resolve_dep_sources(gen_dir: Path, bender: str, lock: Path,
                         extra_sources: List[str]) -> Tuple[List[str], List[str], List[str]]:
    """
    Resolve the PULP dependencies from padrick's own generated Bender.yml and
    return (source_files, include_dirs, defines) for the whole package plus the
    testbench. The committed Bender.lock is copied in first so `bender checkout`
    pins the same dependency revisions on every run.
    """
    shutil.copyfile(lock, gen_dir / "Bender.lock")
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
    sources += extra_sources
    return sources, includes, defines


def _variant_config(work: Path, variant: Variant) -> Path:
    """
    Materialize the per-variant padframe config: the shared base YAML with the
    selected config_interface appended (regbus is the base default, so it is used
    verbatim). Keeps a single source of truth for the pad/port structure.
    """
    if variant.frontend == "regbus":
        return CONFIG
    cfg = work / f"sim_padframe_{variant.frontend}.yaml"
    cfg.write_text(CONFIG.read_text() + f"\nconfig_interface: {variant.frontend}\n")
    return cfg


@pytest.fixture(scope="session", params=VARIANTS, ids=lambda v: v.name)
def rtl_build(request, tmp_path_factory):
    variant: Variant = request.param
    if variant.slow and not request.config.getoption("--run-slow"):
        pytest.skip(f"{variant.name} is a slow variant (pass --run-slow to enable)")
    if variant.backend == "peakrdl" and not _peakrdl_importable():
        pytest.skip(f"{variant.name} needs the peakrdl extra (install padrick with '.[peakrdl]')")
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

    work = tmp_path_factory.mktemp(f"rtl_sim_{variant.name}")
    gen_dir = work / "generated"
    config = _variant_config(work, variant)
    result = run_padrick(["generate", "rtl", "--no-version-string",
                          "--register-backend", variant.backend, "-o", str(gen_dir), str(config)])
    assert result.returncode == 0, f"padrick generate rtl failed:\n{result.stderr}"

    extra_sources = [str(HW_DIR / "behav_pads.sv"), str(HW_DIR / variant.wrapper)]
    sources, includes, defines = _resolve_dep_sources(gen_dir, bender, variant.lock, extra_sources)

    from cocotb.runner import get_runner

    runner = get_runner("verilator")
    runner.build(
        sources=sources,
        includes=includes,
        hdl_toplevel=variant.toplevel,
        build_dir=str(work / "sim_build"),
        build_args=["-Wno-fatal", "-Wno-WIDTHTRUNC", "-Wno-WIDTHEXPAND"] + defines,
        always=True,
    )
    return {"runner": runner, "gen_dir": gen_dir, "work": work,
            "config": config, "variant": variant}
