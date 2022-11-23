#!/usr/bin/env python3

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

import fileinput
from datetime import datetime
from pathlib import Path

import click
import semver

UNRELEASED_SECTION_STRING = """
Unreleased
==========

Added
-----

Changed
-------

Fixed
-----

"""

def validate_parse_version_string(ctx, param, value) -> semver.VersionInfo:
    if value[0] == 'v':
        value = value[1:]
    if not semver.VersionInfo.isvalid(value):
        raise  click.BadParameter("version must be a valid semantic version string")
    return semver.VersionInfo.parse(value)

@click.command()
@click.argument("changelog", type=click.Path(file_okay=True, dir_okay=False, exists=True))
@click.argument("version", type=click.STRING, callback=validate_parse_version_string)
def update_changelog(changelog: Path, version: semver.VersionInfo):
    """
    Updates CHANGELOG (an rst changelog file in keepachangelog.com format) by replacing the Unreleased section with the
    given VERSION string + current date and inserting a new 'Unreleased' section. The
    """
    skip_line = False
    unreleased_section = []
    in_unreleased_section = False
    version_string = f'v{str(version)} - {datetime.now().date().strftime("%Y-%m-%d")}'
    for line in fileinput.input(changelog, inplace=True):
        if line.startswith("Unreleased"):
            print(UNRELEASED_SECTION_STRING)
            print(version_string)
            print(len(version_string)*"=")
            skip_line = True
            in_unreleased_section = True
        elif not skip_line:
            if line.startswith("==="):
                in_unreleased_section = False
            if in_unreleased_section:
                unreleased_section.append(line)
            print(line.rstrip())
        else:
            skip_line = False
    del unreleased_section[-1]
    print(version_string)
    print(len(version_string) * "=")
    print(*unreleased_section)

if __name__ == '__main__':
    update_changelog()
