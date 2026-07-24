# Copyright 2026 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Kai Berszin, ETH Zurich

import subprocess
import sys
from pathlib import Path
from typing import List

REPO_ROOT = Path(__file__).parent.parent.parent
GOLDEN_DIR = Path(__file__).parent / "goldens"

PADRICK = Path(sys.executable).parent / "padrick"


def run_padrick(args: List[str], cwd: Path = REPO_ROOT) -> subprocess.CompletedProcess:
    """
    Run the padrick CLI in a fresh subprocess (parsing is not reentrant).
    """
    return subprocess.run(
        [str(PADRICK), *args],
        cwd=cwd,
        capture_output=True,
        text=True,
    )
