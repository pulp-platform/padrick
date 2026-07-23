# Kai Berszin <kberszin@iis.ee.ethz.ch>
#
# Copyright (C) 2026 ETH Zürich
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

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
