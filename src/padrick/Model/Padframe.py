from Model.Constants import MANIFEST_VERSION, SYSTEM_VERILOG_IDENTIFIER
from Model.PadDomain import PadDomain
from pydantic import BaseModel, constr, conint, conlist
from typing import List, Optional


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