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


def _compile_rdl(rdl_file: Path):
    """Compile and elaborate an .rdl file, returning the elaborated root node."""
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
    return compiler.elaborate()


def generate_regblock(rdl_file: Path, output_dir: Path, module_name: str,
                      package_name: str) -> int:
    """Generate the register-block SV (module + package) and return its byte size."""
    from peakrdl_regblock import RegblockExporter
    from peakrdl_regblock.cpuif.passthrough import PassthroughCpuif

    root = _compile_rdl(rdl_file)
    RegblockExporter().export(
        root, str(output_dir),
        cpuif_cls=PassthroughCpuif,
        module_name=module_name,
        package_name=package_name,
    )
    return root.top.size


def regblock_size(rdl_file: Path) -> int:
    """Return the byte size of the register block described by the .rdl file."""
    return _compile_rdl(rdl_file).top.size


def generate_cheader(rdl_file: Path, output_file: Path) -> None:
    """Generate a C header with register offset/field defines for the driver path."""
    from peakrdl_cheader.exporter import CHeaderExporter

    root = _compile_rdl(rdl_file)
    CHeaderExporter().export(root, str(output_file))
