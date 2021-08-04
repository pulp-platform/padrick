import logging
from dataclasses import dataclass
from importlib import resources
from pathlib import Path
from typing import Union, Optional, Tuple, NamedTuple
from pydantic import BaseModel

from padrick.Model.Padframe import Padframe
from mako import exceptions
from mako.template import Template


class TemplateRenderException(Exception):
    pass

class TemplatePackageResource(NamedTuple):
    package: str
    resource: str

class PadrickTemplate(BaseModel):
    name: str
    target_file_name: str
    template: Union[TemplatePackageResource, Path]
    skip_generation = False

    def render(self, output_dir: Path, logger: logging.Logger, padframe: Padframe, debug_render=False, **kwargs):
        if self.skip_generation:
            logger.debug(f"Skipping generation of {self.name}.")
        else:
            logger.debug(f"Generating {self.name}")
            output_file_path = output_dir / self.target_file_name.format(padframe=padframe, **kwargs)
            with output_file_path.open(mode='w') as f:
                if isinstance(self.template, TemplatePackageResource):
                    tp = Template(resources.read_text(self.template.package, self.template.resource))
                else:
                    tp = Template(filename=str(self.template))
                try:
                    f.write(tp.render(padframe=padframe, **kwargs))
                    if debug_render:
                        logger.debug(tp.render(padframe=padframe, **kwargs))
                except Exception as e:
                    logger.error(f"Error while rendering {self.name} template for padframe {padframe.name}:\
                    n{exceptions.text_error_template().render()}")
                    raise TemplateRenderException(f"Rendering of template {self.name} failed") from e