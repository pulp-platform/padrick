from typing import Optional, List

from Model.Constants import SYSTEM_VERILOG_IDENTIFIER
from Model.Port import Port
from pydantic import BaseModel, constr, conlist


class PortGroup(BaseModel):
    name: constr(regex=SYSTEM_VERILOG_IDENTIFIER)
    description: Optional[str]
    ports: List[Port]

