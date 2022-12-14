from enum import Enum
from pathlib import Path
from typing import Optional, List, Union

from typing_extensions import Literal, Annotated

from pydantic import BaseModel, Field, Extra

from padrick.Generators.GeneratorSettings import GeneratorSettings
from padrick.Model.Padframe import Padframe

class GeneratorKind(str, Enum):
    rtl = "rtl"
    driver = "driver"
    padlist = "padlist"
    constraints = "constraints"
    custom = "custom"


class GenerateStep(BaseModel):
    kind: str

    def __str__(self):
        return f"step generate {self.kind}"


class RTLGenerateStep(GenerateStep):
    kind: Literal[GeneratorKind.rtl]


class DriverGenerateStep(GenerateStep):
    kind: Literal[GeneratorKind.driver]


class PadlistGenerateStep(GenerateStep):
    kind: Literal[GeneratorKind.padlist]


class ConstraintsGenerateStep(GenerateStep):
    kind: Literal[GeneratorKind.constraints]


class CustomGenerateStep(GenerateStep):
    kind: Literal[GeneratorKind.custom]
    template_file: Path
    output_filename: Path

    def __str__(self):
        return f"step generate custom template {self.template_file}"


GenerateStepType = Annotated[Union[
    RTLGenerateStep,
    CustomGenerateStep
    #DriverGenerateStep, # Currently not supported
    #PadlistGenerateStep, # Currently not supported
    #ConstraintsGenerateStep, # Currently not supported
], Field(discriminator='kind')]


class ConfigFileParameters(BaseModel):
    generator_settings: Optional[Path]
    padframe_manifest: Path
    generate_steps: List[GenerateStepType]
    padrick_cmd: Optional[str]


class ConfigFileModel(BaseModel):
    """
    A pydantic data validation class to validate the generator config files supplied by FuseSoC to padrick's 'fusesoc_gen' command.
    """
    files_root: Path
    gapi: Literal['1.0']
    vlnv: str
    parameters: ConfigFileParameters

    class Config:
        extra = Extra.allow
