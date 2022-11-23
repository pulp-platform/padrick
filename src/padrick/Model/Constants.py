# Manuel Eggimann <meggimann@iis.ee.ethz.ch>
#
# Copyright (C) 2021-2022 ETH Zürich
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

import re

MANIFEST_VERSION = 2
# The version id baked into the INFO register of the pad mux config register file.
# This version shall be bumped whenever the RTL templates or generator logic influencing the RTL generation process is modified.
HARDWARE_VERSION = 2
OLD_MANIFEST_VERSION_COMPATIBILITY_TABLE = { # A mapping between manifest version and most recent supported padrick version.
    1: 0.1
}

SYSTEM_VERILOG_IDENTIFIER = r'^[_a-zA-Z](?:[_a-zA-Z0-9])*'
LOWERCASE_IDENTIFIER = r'^[_a-z][_a-z0-9]*'

