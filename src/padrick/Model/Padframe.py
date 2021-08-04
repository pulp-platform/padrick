import json
import logging
from itertools import count

from mako.template import Template

import padrick
from padrick.Model.Constants import MANIFEST_VERSION, SYSTEM_VERILOG_IDENTIFIER, OLD_MANIFEST_VERSION_COMPATIBILITY_TABLE
from padrick.Model.PadDomain import PadDomain
from pydantic import BaseModel, constr, conint, conlist, validator
from typing import List, Optional, Dict, Union

from padrick.Model.PadSignal import PadSignal, Signal
from padrick.Model.SignalExpressionType import SignalExpressionType

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
    manifest_version: conint(le=MANIFEST_VERSION)
    name: constr(regex=SYSTEM_VERILOG_IDENTIFIER)
    description: Optional[str]
    pad_domains: conlist(PadDomain, min_items=1)
    user_attr: Optional[Dict[str, Union[str, int, bool]]]

    #Pydantic Model Config
    class Config:
        title =  "Padframe Config"
        json_encoders = {
            Template: lambda v: v.source,
            SignalExpressionType: lambda v: v.expression,
            PadSignal: lambda v: v.name,
            Signal: lambda  v: v.name
        }
        underscore_attrs_are_private = True


    @validator('manifest_version')
    def check_manifest_version(cls, version):
        """ Verifies that the configuration file has the right version number for the current version of padrick."""
        if version != MANIFEST_VERSION:
            raise ValueError(f"Manifest version {version} of the padframe config file is incompatible with the current version of padrick ({padrick.__version__}.\n"
                             f"Please use Padrick version {OLD_MANIFEST_VERSION_COMPATIBILITY_TABLE[version]} instead.")
        return version
