# Copyright 2026 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Kai Berszin, ETH Zurich

"""
pytest entry point for the Verilator + cocotb RTL simulation of the generated
sim_padframe. The heavy lifting (padrick generate -> bender deps -> verilate)
happens in the session-scoped `rtl_build` fixture; here we just launch the
cocotb test module against the built model. Skips cleanly without verilator or
bender so the default suite stays green.
"""
import os
from pathlib import Path

THIS_DIR = Path(__file__).parent


def test_sim_padframe(rtl_build):
    runner = rtl_build["runner"]
    variant = rtl_build["variant"]
    env = dict(os.environ)
    env["PADRICK_SIM_GEN_DIR"] = str(rtl_build["gen_dir"])
    env["PADRICK_SIM_YAML"] = str(rtl_build["config"])
    env["PADRICK_SIM_FRONTEND"] = variant.frontend
    env["PADRICK_SIM_BACKEND"] = variant.backend
    env["PYTHONPATH"] = str(THIS_DIR) + os.pathsep + env.get("PYTHONPATH", "")

    results = runner.test(
        hdl_toplevel=variant.toplevel,
        test_module="cocotb_padframe",
        build_dir=str(rtl_build["work"] / "sim_build"),
        test_dir=str(rtl_build["work"] / "sim_build"),
        extra_env=env,
    )

    from cocotb.runner import get_results

    num_tests, num_failed = get_results(Path(results))
    # Guard against a vacuous pass: a broken sim/import can report zero tests,
    # which get_results would otherwise wave through as num_failed == 0.
    assert num_tests >= 6, f"expected the 6 config-driven checks, got {num_tests}"
    assert num_failed == 0, f"{num_failed}/{num_tests} cocotb tests failed"
