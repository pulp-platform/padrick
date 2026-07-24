# Copyright 2026 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Kai Berszin, ETH Zurich

"""
Characterization tests: pin generator output on the example configs against
golden files. After an intentional output change, regenerate the goldens with
`UPDATE_GOLDENS=1 pytest tests/characterization` and review the diff.
"""
import difflib
import filecmp
import os
import shutil
from pathlib import Path
from typing import List

import pytest

from conftest import GOLDEN_DIR, REPO_ROOT, run_padrick

CONFIGS = {
    "sample_padframe": "examples/sample_padframe.yaml",
    "kraken_padframe": "examples/kraken_padframe.yml",
    "modular_config": "examples/modular_config/modular_config_top.yml",
}

GENERATORS = ["rtl", "driver", "padlist"]

UPDATE_GOLDENS = os.environ.get("UPDATE_GOLDENS") == "1"


def relative_files(root: Path) -> List[Path]:
    # PDFs (mux-graph via graphviz) are environment-dependent and not compared
    return sorted(p.relative_to(root) for p in root.rglob("*")
                  if p.is_file() and p.suffix != ".pdf")


def assert_trees_equal(golden: Path, generated: Path) -> None:
    golden_files = relative_files(golden)
    generated_files = relative_files(generated)
    assert generated_files == golden_files, (
        "Generated file set differs from golden.\n"
        f"  missing:    {[str(f) for f in golden_files if f not in generated_files]}\n"
        f"  unexpected: {[str(f) for f in generated_files if f not in golden_files]}"
    )
    mismatches = []
    for rel in golden_files:
        if not filecmp.cmp(golden / rel, generated / rel, shallow=False):
            diff = "".join(
                difflib.unified_diff(
                    (golden / rel).read_text().splitlines(keepends=True),
                    (generated / rel).read_text().splitlines(keepends=True),
                    fromfile=f"golden/{rel}",
                    tofile=f"generated/{rel}",
                    n=2,
                )
            )
            mismatches.append(diff)
    assert not mismatches, "Generated output differs from golden:\n" + "\n".join(mismatches)


@pytest.mark.parametrize("config", CONFIGS.values(), ids=CONFIGS.keys())
def test_validate_succeeds(config: str):
    result = run_padrick(["validate", config])
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("config", CONFIGS.values(), ids=CONFIGS.keys())
def test_config_command_succeeds(config: str):
    result = run_padrick(["config", config])
    assert result.returncode == 0, result.stderr


@pytest.mark.parametrize("generator", GENERATORS)
@pytest.mark.parametrize("config", CONFIGS.values(), ids=CONFIGS.keys())
def test_generate_matches_golden(config: str, generator: str, tmp_path: Path):
    args = ["generate", generator, "-o", str(tmp_path), config]
    if generator != "padlist":
        args.insert(2, "--no-version-string")
    result = run_padrick(args)
    assert result.returncode == 0, result.stderr

    config_id = next(k for k, v in CONFIGS.items() if v == config)
    golden = GOLDEN_DIR / config_id / generator

    if UPDATE_GOLDENS:
        if golden.exists():
            shutil.rmtree(golden)
        shutil.copytree(tmp_path, golden)
        pytest.skip(f"goldens updated in {golden}")

    assert golden.exists(), (
        f"No goldens for {config_id}/{generator}. "
        "Run UPDATE_GOLDENS=1 pytest tests/characterization to create them."
    )
    assert_trees_equal(golden, tmp_path)


def check_golden(generated: Path, golden: Path):
    if UPDATE_GOLDENS:
        if golden.exists():
            shutil.rmtree(golden)
        shutil.copytree(generated, golden)
        pytest.skip(f"goldens updated in {golden}")
    assert golden.exists(), f"No goldens in {golden}; run with UPDATE_GOLDENS=1."
    assert_trees_equal(golden, generated)


def test_generate_constraints_matches_golden(tmp_path: Path):
    result = run_padrick(
        ["generate", "constraints", "--no-version-string", "-o", str(tmp_path),
         "examples/sample_padframe.yaml", "examples/constraints_spec.yml"]
    )
    assert result.returncode == 0, result.stderr
    check_golden(tmp_path, GOLDEN_DIR / "sample_padframe" / "constraints")


def test_generate_mux_graph_matches_golden(tmp_path: Path):
    result = run_padrick(
        ["generate", "mux-graph", "--no-version-string", "-o", str(tmp_path),
         "examples/sample_padframe.yaml"]
    )
    assert result.returncode == 0, result.stderr
    check_golden(tmp_path, GOLDEN_DIR / "sample_padframe" / "mux-graph")


def test_generate_is_deterministic(tmp_path: Path):
    config = CONFIGS["sample_padframe"]
    for out in (tmp_path / "a", tmp_path / "b"):
        result = run_padrick(
            ["generate", "rtl", "--no-version-string", "-o", str(out), config]
        )
        assert result.returncode == 0, result.stderr
    assert_trees_equal(tmp_path / "a", tmp_path / "b")


def test_manifest_v1_config_is_rejected():
    """
    An unsupported manifest_version 1 config fails to parse.
    """
    result = run_padrick(["validate", "tests/rtl_tests/testpadframe.yaml"])
    assert result.returncode != 0
    assert "Error" in result.stdout + result.stderr
