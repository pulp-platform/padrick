# Copyright 2021-2022 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Manuel Eggimann, ETH Zurich

import logging
from enum import Enum

import padrick
from padrick.Model.Constants import MANIFEST_VERSION, SYSTEM_VERILOG_IDENTIFIER, \
    OLD_MANIFEST_VERSION_COMPATIBILITY_TABLE, MANIFEST_VERSION_COMPATIBILITY
from padrick.Model.PadDomain import PadDomain
from padrick.Model.UserAttrs import UserAttrs
from pydantic import field_validator, Field, StringConstraints, ConfigDict, BaseModel
from typing import List, Optional
from typing_extensions import Annotated

logger = logging.getLogger("padrick.Configparser")


class ConfigInterface(str, Enum):
    """Config-bus protocol exposed at the padframe toplevel. A protocol converter in front of the
    unchanged internal register_interface fabric adapts the selected frontend."""
    regbus = "regbus"
    apb = "apb"
    axilite = "axilite"
    obi = "obi"


class ConfigPortTopology(str, Enum):
    """Whether the padframe exposes a single shared config port or one config port per pad domain."""
    shared = "shared"
    per_domain = "per_domain"

class Padframe(BaseModel):
    """
    Padframe class that represents the padframe configuration parsed from the configuration file.

    Attributes:
        manifest_version (int): The manifest version used by the parsed configuration file.
        name (str): Name of the pad_frame module.
        description (str): An optional short description of the padframes.
        pad_domains (List[PadDomain): A list of PadDomains within this padframe.
    """
    manifest_version: int = Field(description="Configuration file syntax version. Must match the manifest "
        "version supported by the padrick version you are using.")
    name: Annotated[str, StringConstraints(pattern=SYSTEM_VERILOG_IDENTIFIER), Field(description="Name of "
        "the generated padframe module. Used as the prefix for all auto-generated modules to avoid naming "
        "collisions when several padframes are generated.")]
    description: Optional[str] = Field(default=None, description="Optional short description of the padframe.")
    pad_domains: Annotated[List[PadDomain], Field(min_length=1, description="List of pad domains that make "
        "up this padframe. Pad domains do not interact with each other and are generated as separate RTL "
        "modules, which simplifies power intent for power-gated IO.")]
    config_interface: ConfigInterface = Field(default=ConfigInterface.regbus, description="Config-bus "
        "protocol exposed at the padframe toplevel. 'regbus' (the default) is the PULP register_interface. "
        "'apb', 'axilite' and 'obi' instantiate a protocol converter in front of the internal "
        "register_interface fabric. Non-regbus frontends currently require the reggen register backend.")
    config_port_topology: ConfigPortTopology = Field(default=ConfigPortTopology.shared, description="How the "
        "config bus is exposed. 'shared' (the default) keeps a single toplevel config port with an internal "
        "address demux to the pad domains; this interconnect is always on and can defeat power gating of "
        "individual pad domains. 'per_domain' exposes one config port per pad domain with no shared "
        "interconnect and is recommended for power-gated multi-domain designs.")
    user_attr: Optional[UserAttrs] = Field(default=None, description="Optional custom key-value pairs that "
        "are also exposed during template rendering; handy for parametrizing the config with YAML anchors.")
    model_config = ConfigDict(title="Padframe Config", extra="forbid")


    @field_validator('manifest_version')
    @classmethod
    def check_manifest_version(cls, version):
        """ Verifies that the configuration file has the right version number for the current version of padrick."""
        if version != MANIFEST_VERSION:
            if version in MANIFEST_VERSION_COMPATIBILITY:
                logger.warning(
                    f"Your padframe config file is using the outdated manifest version {version}. This version of padrick "
                    f"is still compatible but newer versions of padrick might eventually drop support for it. "
                    f"Consider upgrading your config files to version {MANIFEST_VERSION}.")
            else:
                if version > MANIFEST_VERSION:
                    raise ValueError(f"Manifest version {version} of the padframe config file is newer than this version "
                                     f"of padrick support. Either upgrade to the latest padrick version or change to an"
                                     f" older manifest version. This padrick version supports the following Manifests versions: "
                                     f"{', '.join([str(v) for v in MANIFEST_VERSION_COMPATIBILITY])}")
                if version < MANIFEST_VERSION:
                    raise ValueError(f"Manifest version {version} of the padframe config file is incompatible with the current version of padrick ({padrick.__version__}.\n"
                                     f"Please use Padrick version {OLD_MANIFEST_VERSION_COMPATIBILITY_TABLE[version]} instead.")
        return version
