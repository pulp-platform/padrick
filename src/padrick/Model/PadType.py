from typing import Optional, List

from Model.Constants import SYSTEM_VERILOG_IDENTIFIER
from Model.ParseContext import PARSE_CONTEXT
from Model.PadSignal import PadSignal
from mako import exceptions
from mako.template import Template
from pydantic import BaseModel, constr, validator, conlist, Extra


class PadType(BaseModel):
    name: constr(regex=SYSTEM_VERILOG_IDENTIFIER)
    description: Optional[str]
    template: str
    pad_signals: conlist(PadSignal, min_items=1)

    #pydantic model config
    class Config:
        extra = Extra.forbid

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        PARSE_CONTEXT.register_pad_type(self)

    @validator('template')
    def check_valid_mako_template(cls, v):
        try:
            return Template(v)
        except:
            raise ValueError(f"Illegal Mako template provided: {exceptions.text_error_template().render()}")

    @validator('name')
    def check_unique_padtype_name(cls, v):
        if PARSE_CONTEXT.find_pad_type(v):
#        if v in PARSE_CONTEXT.pad_type_registry:
            raise ValueError(f"Double declaration of pad_type {v}. PadType names must be unique.")
        else:
            return v

    def get_pad_signal(self, name: str) -> PadSignal:
        for pad_signal in self.pad_signals:
            if pad_signal.name == name:
                return pad_signal
        raise ValueError(f"Did not find  Pad Signal {name} in scope of Pad Type {self.name}")
