# Copyright 2021-2026 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Kai Berszin, ETH Zurich

from importlib.metadata import PackageNotFoundError, version

try:
    __version__ = version("padrick")
except PackageNotFoundError:
    __version__ = "unknown"
