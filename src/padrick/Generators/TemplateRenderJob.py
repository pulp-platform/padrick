import logging
from dataclasses import dataclass
from pathlib import Path

from padrick.Model.Padframe import Padframe
from mako import exceptions
from mako.template import Template


class TemplateRenderException(Exception):
    pass

@dataclass
class TemplateRenderJob:
    name: str
    target_file_name: str
    template: str

    def render(self, output_dir: Path, logger: logging.Logger, padframe: Padframe, debug_render=False, **kwargs):
        logger.debug(f"Generating {self.name}")
        output_file_path = output_dir / self.target_file_name.format(padframe=padframe, **kwargs)
        with output_file_path.open(mode='w') as f:
            tp = Template(self.template)
            try:
                f.write(tp.render(padframe=padframe, **kwargs))
                if debug_render:
                    logger.debug(tp.render(padframe=padframe, **kwargs))
            except Exception as e:
                logger.error(f"Error while rendering {self.name} template for padframe {padframe.name}:\
                n{exceptions.text_error_template().render()}")
                raise TemplateRenderException(f"Rendering of template {self.name} failed") from e
