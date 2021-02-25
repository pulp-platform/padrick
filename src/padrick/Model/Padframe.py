from padrick.Model.Constants import MANIFEST_VERSION, SYSTEM_VERILOG_IDENTIFIER
from padrick.Model.PadDomain import PadDomain
from pydantic import BaseModel, constr, conint, conlist, validator
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

    @validator('pad_domains')
    def ensure_package_pad_nr_uniqueness(cls, pad_domains):
        package_pad_numbers_seen = {}
        for pad_domain in pad_domains:
            for pad in pad_domain.pad_list:
                if pad.package_pad_nr != None:
                    if pad.package_pad_nr in package_pad_numbers_seen:
                        raise ValueError(f"Found duplicate package pad number {pad.package_pad_nr} for pad instance "
                                         f"{pad.name}. The number is already used for pad "
                                         f"{package_pad_numbers_seen[pad.package_pad_nr].name}")
                    else:
                        package_pad_numbers_seen[pad.package_pad_nr] = pad
        return pad_domains

    @validator('pad_domains')
    def either_all_or_no_package_number_defined(cls, pad_domains):
        all_pads = [pad for pad_domain in pad_domains for pad in pad_domain.pad_list]
        padnr_to_pad_mapping = {pad.package_pad_nr: pad for pad in all_pads}
        if any( pad_nr is not None for pad_nr in padnr_to_pad_mapping.keys()):
            if None in padnr_to_pad_mapping:
                pad = padnr_to_pad_mapping[None]
                raise ValueError(f"Pad instance {pad.name} is missing the "
                                 f"package_pad_nr key. Either all or none of the pad must define a package pad number!")
        return pad_domains

    @validator('pad_domains')
    def no_multiregs_if_package_pad_number_specified(cls, pad_domains):
        all_pads = [pad for pad_domain in pad_domains for pad in pad_domain.pad_list]
        padnr_to_pad_mapping = {pad.package_pad_nr: pad for pad in all_pads}
        if any(pad_nr is not None for pad_nr in padnr_to_pad_mapping.keys()):
            for pad in all_pads:
                if pad.multiple > 1:
                    raise ValueError(f"Found multi reg {pad.name} with package_pad_nr specification. You cannot "
                                     f"combine the usage of multi regs (pad instances with a 'multiple' value > 1)"
                                     f" with package_pad_nr. You have to manually specifiy all pads and assign them"
                                     f" their package_pad_nr or get rid of the package_pad_nr key alltogether.")

        return pad_domains



