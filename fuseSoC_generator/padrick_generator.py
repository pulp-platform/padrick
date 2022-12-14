#!/usr/bin/env python3

# This is a trampoline script to invoke padrick as a generator. It only parses
# the padrick_cmd parameter of the config file to determine the command to
# invoke. 

from fusesoc.capi2.generator import Generator
import os
import subprocess
import sys
from shutil import which
from pathlib import Path


class CustomGenerator(Generator):
    def run(self):
        padrick_cmd =  self.config.get('padrick_cmd', 'padrick')
        root_files = self.files_root
        if which(padrick_cmd) is None:
            # Could not find the command. We thus assume its the name of a
            # binary relative to root_files
            cmd_split = padrick_cmd.split(maxsplit=1)
            print(Path(root_files)/cmd_split[0])
            cmd_location = which(Path(root_files)/cmd_split[0])
            if not cmd_location:
                print(f"Could not locate padrick executeable {padrick_cmd}", file=sys.stderr)
                exit(1)
            padrick_cmd = str(cmd_location) + (cmd_split[1] if len(cmd_split) > 1 else "")
            print(padrick_cmd)
        if len(sys.argv) == 2:
            subprocess.call([padrick_cmd, 'fusesoc-gen', sys.argv[1]])
        else:
            print("Error: Called the fuseSoC padrick invocation script with the wrong number of arguments.", file=sys.stderr)
            exit(1)

g = CustomGenerator()
g.run()
