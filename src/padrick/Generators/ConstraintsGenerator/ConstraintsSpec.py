import logging
import re

import click_log
from pydantic import BaseModel, conint, constr, validator, root_validator
from typing import List, Union, Optional, Tuple, Mapping

from padrick.Model.Constants import MANIFEST_VERSION, OLD_MANIFEST_VERSION_COMPATIBILITY_TABLE
from padrick.Model.PadDomain import PadDomain
from padrick.Model.PadInstance import PadInstance
from padrick.Model.PadSignal import PadSignal
from padrick.Model.Padframe import Padframe
from padrick.Model.Port import Port
from padrick.Model.PortGroup import PortGroup
from padrick.Model.SignalExpressionType import SignalExpressionType
from padrick.Model.TemplatedIdentifier import TemplatedIdentifierType
from padrick.Model.TemplatedString import TemplatedStringType

logger = logging.getLogger("padrick.ConstraintsGenerator")
click_log.basic_config(logger)

class ConstraintsGenException(Exception):
    pass


class ConstraintsPadMode(BaseModel):
    pad_inst: Union[TemplatedIdentifierType, PadInstance]
    port_sel: Optional[Union[TemplatedStringType, Tuple[PortGroup, Port]]]
    pad_cfg: Optional[Mapping[Union[PadSignal, str], Union[constr(regex=r"(0x|0b)?[0-9a-f]+"), int]]]
    multiple: conint(gt=1) = 1

    @validator("pad_cfg")
    def validate_pad_cfg_expression_valid(cls, pad_cfg: Mapping[Union[PadSignal, str], str]):
        for key, value in pad_cfg.items():
            try:
                pad_cfg[key] = int(value)
            except ValueError:
                raise ValueError(f"{value} is not a valid literal. You must only use hex (0x...), binary (0b) or decimal literals (42).")
        return pad_cfg

    def expand_pad_mode(self) -> List['ConstraintsPadMode']:
        expanded_pad_configs = []
        for i in range(self.multiple):
            pc: ConstraintsPadMode = self.copy()
            pc.pad_inst = pc.pad_inst.evaluate_template(i) if isinstance(pc.pad_inst, TemplatedIdentifierType) else pc.pad_inst
            pc.multiple = 1
            pc.port_sel = pc.port_sel.evaluate_template(i) if isinstance(pc.port_sel, TemplatedStringType) else pc.port_sel
            expanded_pad_configs.append(pc)
        return expanded_pad_configs

    def link_with_pad_domain(self, pad_domain: PadDomain):
        p: PadInstance = next(p for p in pad_domain.pad_list if p.name == self.pad_inst and not p.is_static)
        if not p:
            raise ConstraintsGenException(f"Cannot find pad instance {self.pad_inst} in Pad Domain {pad_domain.name}.")
        else:
            self.pad_inst = p
        if self.port_sel:
            if not(re.match("^[_a-zA-Z](?:[_a-zA-Z0-9])*\.[_a-zA-Z](?:[_a-zA-Z0-9])*", self.port_sel)):
                raise ConstraintsGenException(f"Illegal port_sel specifier {self.port_sel}. Must be of the form <port_group>.<port_name>.")
            (port_group_name, port_name) = self.port_sel.split(".", maxsplit=1)
            port_group = next((pg for pg in pad_domain.port_groups if pg.name == port_group_name), None)
            if not port_group:
                raise ConstraintsGenException(f"Unknown port group '{port_group_name}'")
            port = next((port for port in port_group.ports if port.name == port_name), None)
            if not port:
                raise ConstraintsGenException(f"Cannot find port '{port_name}' in port_group {port_group.name}")
            if port not in pad_domain.get_ports_in_mux_groups(self.pad_inst.mux_groups):
                raise ConstraintsGenException(f"Port {self.port_sel} is not connectable to pad {self.pad_inst.name}")
            self.port_sel = (port_group, port)
        linked_pad_cfgs = {}
        for ps_name, expression in self.pad_cfg.items():
            ps = next((ps for ps in self.pad_inst.pad_type.pad_signals if ps.name == ps_name), None)
            if not ps:
                raise ConstraintsGenException(f"Unknown pad signal {ps_name}")
            if ps not in self.pad_inst.dynamic_pad_signals_soc2pad:
                raise ConstraintsGenException(f"Pad signal {ps_name} is not dynamic or has the wrong directionality. You can only constrain dynamic pad signals with direction chip2pad.")
            linked_pad_cfgs[ps] = expression
        self.pad_cfg = linked_pad_cfgs

class ConstraintsMode(BaseModel):
    name: str
    pad_domain: str
    pad_mode: List[ConstraintsPadMode]

    @validator("pad_mode")
    def expand_multi_pad_modes(cls, pad_configs: List[ConstraintsPadMode]):
        expanded_pad_modes = []
        for pc in pad_configs:
            expanded_pad_modes.extend(pc.expand_pad_mode())
        return expanded_pad_modes

    def link_with_pad_domain(self, padframe: Padframe):
        pad_domain = next((pad_domain for pad_domain in padframe.pad_domains if pad_domain.name == self.pad_domain), None)
        if pad_domain:
            self.pad_domain = pad_domain
            for pm in self.pad_mode:
                pm.link_with_pad_domain(pad_domain)
        else:
            raise ConstraintsGenException(f"Unknown pad_domain name {self.pad_domain}.")

class ConstraintsSpec(BaseModel):
    manifest_version: conint(le=MANIFEST_VERSION)
    modes: List[ConstraintsMode]

    @validator('manifest_version')
    def check_manifest_version(cls, version):
        """ Verifies that the configuration file has the right version number for the current version of padrick."""
        if version != MANIFEST_VERSION:
            raise ValueError(
                f"Manifest version {version} of the padframe config file is incompatible with the current version of padrick ({padrick.__version__}.\n"
                f"Please use Padrick version {OLD_MANIFEST_VERSION_COMPATIBILITY_TABLE[version]} instead.")
        return version

    def link_with_pad_domain(self, padframe: Padframe):
        for mode in self.modes:
            mode.link_with_pad_domain(padframe)
