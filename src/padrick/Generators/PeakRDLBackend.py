# Copyright 2026 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Kai Berszin, ETH Zurich
"""Optional SystemRDL/PeakRDL register-file backend (alternative to lowRISC reggen).

All PeakRDL imports are performed lazily so that the default padrick install, which
does not depend on the `peakrdl` extra, is unaffected.
"""

import logging
from pathlib import Path

logger = logging.getLogger("padrick.PeakRDLBackend")


class PeakRDLBackendException(Exception):
    """Raised when the PeakRDL backend is unavailable or fails."""


def peakrdl_available() -> bool:
    """Return True if the optional peakrdl dependencies are importable."""
    try:
        import systemrdl  # noqa: F401
        import peakrdl_regblock  # noqa: F401
        return True
    except ImportError:
        return False


def _compile_rdl(rdl_file: Path, top_def_name: str = None):
    """Compile and elaborate an .rdl file, returning the elaborated root node.

    `top_def_name` selects the addrmap to elaborate when the file defines several
    components (the flattened shared layout wraps the per-domain regfiles in a top addrmap).
    """
    try:
        from systemrdl import RDLCompiler
        from peakrdl_regblock.udps import ALL_UDPS
    except ImportError as e:
        raise PeakRDLBackendException(
            "The 'peakrdl' extra is not installed. Install padrick with the "
            "peakrdl extra (e.g. `pip install padrick[peakrdl]`) to use this backend."
        ) from e

    compiler = RDLCompiler()
    # peakrdl-regblock relies on a set of user-defined properties (buffer_writes, ...).
    for udp in ALL_UDPS:
        compiler.register_udp(udp)
    compiler.compile_file(str(rdl_file))
    return compiler.elaborate(top_def_name=top_def_name)


def _cpuif_cls(frontend: str):
    """Map a padframe config_interface onto a flattened PeakRDL-regblock cpuif class.

    The flattened variants expose plain s_<proto>_* signals (no SV interface) so the
    padframe template can wire the PULP request/response structs onto them directly.
    """
    if frontend == "apb":
        from peakrdl_regblock.cpuif.apb4 import APB4_Cpuif_flattened
        return APB4_Cpuif_flattened
    if frontend == "axilite":
        from peakrdl_regblock.cpuif.axi4lite import AXI4Lite_Cpuif_flattened
        return AXI4Lite_Cpuif_flattened
    if frontend == "obi":
        from peakrdl_regblock.cpuif.obi import OBI_Cpuif_flattened
        return OBI_Cpuif_flattened
    from peakrdl_regblock.cpuif.passthrough import PassthroughCpuif
    return PassthroughCpuif


def generate_regblock(rdl_file: Path, output_dir: Path, module_name: str,
                      package_name: str, frontend: str = "passthrough",
                      top_def_name: str = None) -> int:
    """Generate the register-block SV (module + package) and return its byte size."""
    from peakrdl_regblock import RegblockExporter

    root = _compile_rdl(rdl_file, top_def_name=top_def_name)
    RegblockExporter().export(
        root, str(output_dir),
        cpuif_cls=_cpuif_cls(frontend),
        module_name=module_name,
        package_name=package_name,
    )
    return root.top.size


def regblock_size(rdl_file: Path, top_def_name: str = None) -> int:
    """Return the byte size of the register block described by the .rdl file."""
    return _compile_rdl(rdl_file, top_def_name=top_def_name).top.size


def generate_cheader(rdl_file: Path, output_file: Path, top_def_name: str = None) -> None:
    """Generate a C header with register offset/field defines for the driver path."""
    from peakrdl_cheader.exporter import CHeaderExporter

    root = _compile_rdl(rdl_file, top_def_name=top_def_name)
    CHeaderExporter().export(root, str(output_file))
