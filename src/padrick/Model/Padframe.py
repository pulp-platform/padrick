# Copyright 2021-2022 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Manuel Eggimann, ETH Zurich

import json
import logging
from itertools import count

from mako.template import Template

import padrick
from padrick.Model.Constants import MANIFEST_VERSION, SYSTEM_VERILOG_IDENTIFIER, \
    OLD_MANIFEST_VERSION_COMPATIBILITY_TABLE, MANIFEST_VERSION_COMPATIBILITY
from padrick.Model.PadDomain import PadDomain
from pydantic import field_validator, Field, StringConstraints, ConfigDict, BaseModel, conint
from typing import List, Optional, Dict, Union

from padrick.Model.PadSignal import PadSignal, Signal
from padrick.Model.SignalExpressionType import SignalExpressionType
from padrick.Model.UserAttrs import UserAttrs
from typing_extensions import Annotated

logger = logging.getLogger("padrick.Configparser")

class Padframe(BaseModel):
    """
    Padframe class that represents the padframe configuration parsed from the configuration file.

    Attributes:
        manifest_version (int): The manifest version used by the parsed configuration file.
        name (str): Name of the pad_frame module.
        description (str): An optional short description of the padframes.
        pad_domains (List[PadDomain): A list of PadDomains within this padframe.
    """
    manifest_version: int
    name: Annotated[str, StringConstraints(pattern=SYSTEM_VERILOG_IDENTIFIER)]
    description: Optional[str] = None
    pad_domains: Annotated[List[PadDomain], Field(min_length=1)]
    user_attr: Optional[UserAttrs] = None
    model_config = ConfigDict(title="Padframe Config", json_encoders={
        Template: lambda v: v.source,
        SignalExpressionType: lambda v: v.expression,
        PadSignal: lambda v: v.name,
        Signal: lambda  v: v.name
    })


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
