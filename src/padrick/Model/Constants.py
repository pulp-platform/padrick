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

