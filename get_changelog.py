#!/usr/bin/env python3
import fileinput
from datetime import datetime
from pathlib import Path
from click

import click
import semver
import re


def validate_parse_version_string(ctx, param, value) -> semver.VersionInfo:
    if value[0] == 'v':
        value = value[1:]
    if not semver.VersionInfo.isvalid(value):
        raise  click.BadParameter("version must be a valid semantic version string")
    return semver.VersionInfo.parse(value)

@click.command()
@click.argument("changelog", type=click.Path(file_okay=True, dir_okay=False, exists=True))
@click.argument("version", type=click.STRING, callback=validate_parse_version_string)
def get_changelog(changelog: Path, version: semver.VersionInfo):
    """
    Extracts the CHANGELOG section for the given version string and prints it to stdout
    """
    skip_line = False
    version_section = []
    in_unreleased_section = False
    matcher = re.compile(f"v?{re.escape(str(version))} - ")
    with open(changelog, "r") as f:
        for line in f:
            if matcher.match(line.strip()):
                skip_line = True
                in_unreleased_section = True
                version_section.append(line)
            elif not skip_line:
                if line.startswith("==="):
                    in_unreleased_section = False
                if in_unreleased_section:
                    version_section.append(line)
            else:
                skip_line = False
                if in_unreleased_section:
                    version_section.append(line)
    del version_section[-1]
    print(*version_section)
    if not version_section:
        raise click.BadParameter(f"Failed to get the release section for {version}. Did you forget to update the changelog file before tagging?")

if __name__ == '__main__':
    get_changelog(["CHANGELOG.rst", "v0.2.0"])
