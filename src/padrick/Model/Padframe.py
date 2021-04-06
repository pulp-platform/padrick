import json
from itertools import count

from mako.template import Template

from padrick.Model.Constants import MANIFEST_VERSION, SYSTEM_VERILOG_IDENTIFIER
from padrick.Model.PadDomain import PadDomain
from pydantic import BaseModel, constr, conint, conlist, validator
from typing import List, Optional

from padrick.Model.PadSignal import PadSignal, Signal
from padrick.Model.SignalExpressionType import SignalExpressionType


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



