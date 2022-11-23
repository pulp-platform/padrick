# Manuel Eggimann <meggimann@iis.ee.ethz.ch>
#
# Copyright (C) 2021-2022 ETH Zürich
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from pydantic import BaseModel, conint, validator
from pydantic.dataclasses import dataclass

import padrick
from padrick.Generators.PadrickTemplate import PadrickTemplate
from padrick.Model.Constants import MANIFEST_VERSION, OLD_MANIFEST_VERSION_COMPATIBILITY_TABLE

RTLTemplatePackage = 'padrick.Generators.RTLGenerator.Templates'
DriverTemplatePackage = 'padrick.Generators.DriverGenerator.Templates'
DocTemplatePackage = 'padrick.Generators.DocGenerator.Templates'
ConstraintsTemplatePackage = 'padrick.Generators.ConstraintsGenerator.Templates'


class RTLTemplates(BaseModel):
    toplevel_sv_package = PadrickTemplate(
        name='SV package',
        target_file_name='pkg_{padframe.name}.sv',
        template=(RTLTemplatePackage, 'pkg_padframe.sv.mako')
    )
    pad_domain_top = PadrickTemplate(
        name='Paddomain module {pad_domain.name}',
        target_file_name='{padframe.name}_{pad_domain.name}.sv',
        template=(RTLTemplatePackage, 'pad_domain.sv.mako')
    )
    pad_inst_module = PadrickTemplate(
        name='Pad instantiation module {pad_domain.name}',
        target_file_name='{padframe.name}_{pad_domain.name}_pads.sv',
        template=(RTLTemplatePackage, 'pads.sv.mako')
    )
    internal_pkg = PadrickTemplate(
        name='Internal package for {pad_domain.name}',
        target_file_name='pkg_internal_{padframe.name}_{pad_domain.name}.sv',
        template=(RTLTemplatePackage, 'pkg_pad_domain_internals.sv.mako')
    )
    pad_mux_module = PadrickTemplate(
        name='Pad Multiplexer for {pad_domain.name}',
        target_file_name='{padframe.name}_{pad_domain.name}_muxer.sv',
        template=(RTLTemplatePackage, 'pad_multiplexer.sv.mako')
    )
    regfile_hjson = PadrickTemplate(
        name='Register File Specification for {pad_domain.name}',
        target_file_name='{padframe.name}_{pad_domain.name}_regs.hjson',
        template=(RTLTemplatePackage, 'regfile.hjson.mako')
    )
    toplevel_module = PadrickTemplate(
        name='Padframe Top Module',
        target_file_name='{padframe.name}.sv',
        template=(RTLTemplatePackage, 'padframe.sv.mako')
    )
    assign_header_file = PadrickTemplate(
        name='Padframe assignment header file',
        target_file_name='assign.svh',
        template=(RTLTemplatePackage, 'assign.svh.mako')
    )
    bender_project_file = PadrickTemplate(
        name='Bender.yml Project file',
        target_file_name="Bender.yml",
        template=(RTLTemplatePackage, 'Bender.yml.mako')
    )
    ipapprox_src_files_yml = PadrickTemplate(
        name='IPApprox src_files.yml',
        target_file_name="src_files.yml",
        template=(RTLTemplatePackage, 'src_files.yml.mako')
    )
    ipapprox_ips_list_yml = PadrickTemplate(
        name=f'IPApprox ips_list.yml',
        target_file_name="ips_list.yml",
        template=(RTLTemplatePackage, 'ips_list.yml.mako')
    )

class DriverTemplates(BaseModel):
    regfile_hjson = PadrickTemplate(
        name='Register File Specification for {pad_domain.name}',
        target_file_name='{padframe.name}_{pad_domain.name}_regs.hjson',
        template=(RTLTemplatePackage, 'regfile.hjson.mako')
    )
    driver_header = PadrickTemplate(
        name="Driver header file",
        target_file_name="{padframe.name}.h",
        template=(DriverTemplatePackage,'driver.h.mako')
    )
    driver_source = PadrickTemplate(
        name="Driver implementation file",
        target_file_name="{padframe.name}.c",
        template=(DriverTemplatePackage, 'driver.c.mako')
    )


class ConstraintsTemplates(BaseModel):
    case_analysis = PadrickTemplate(
        name='Set Case Analysis statements for padmultiplexer',
        target_file_name='{padframe.name}_mode_{constraints_mode.name}.sdc',
        template=(ConstraintsTemplatePackage, 'set_case_analysis.sdc.mako')
    )

class DocTemplates(BaseModel):
    pass

class GeneratorSettings(BaseModel):
    manifest_version: conint(le=MANIFEST_VERSION) = MANIFEST_VERSION
    rtl_templates = RTLTemplates()
    driver_templates = DriverTemplates()
    doc_templates = DocTemplates()
    constraints_templates = ConstraintsTemplates()

    @validator('manifest_version')
    def check_manifest_version(cls, version):
        """ Verifies that the configuration file has the right version number for the current version of padrick."""
        if version != MANIFEST_VERSION:
            raise ValueError(
                f"Manifest version {version} of the padframe config file is incompatible with the current version of padrick ({padrick.__version__}.\n"
                f"Please use Padrick version {OLD_MANIFEST_VERSION_COMPATIBILITY_TABLE[version]} instead.")
        return version
