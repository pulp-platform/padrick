# Copyright 2026 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Kai Berszin, ETH Zurich

"""Stdlib logging setup and a reusable click verbosity option for padrick."""

import logging
from typing import Any, Callable

import click

_ROOT_LOGGER_NAME = "padrick"
_LEVELS = ["CRITICAL", "ERROR", "WARNING", "INFO", "DEBUG"]


class _ClickHandler(logging.Handler):
    """Logging handler routing records to stdout (info/debug) or stderr (warnings and above)."""

    def emit(self, record: logging.LogRecord) -> None:
        try:
            message = self.format(record)
            click.echo(message, err=record.levelno >= logging.WARNING)
        except Exception:
            self.handleError(record)


class _LevelPrefixFormatter(logging.Formatter):
    """Prefixes every non-INFO line with its lowercased level name (e.g. 'error: msg')."""

    def format(self, record: logging.LogRecord) -> str:
        message = record.getMessage()
        if record.levelno == logging.INFO:
            return message
        prefix = "{}: ".format(record.levelname.lower())
        return "\n".join(prefix + line for line in message.splitlines())


def configure_logging(level: int = logging.INFO) -> None:
    """Attach a single click-based handler to the 'padrick' logger hierarchy (idempotent)."""
    logger = logging.getLogger(_ROOT_LOGGER_NAME)
    if not any(isinstance(handler, _ClickHandler) for handler in logger.handlers):
        handler = _ClickHandler()
        handler.setFormatter(_LevelPrefixFormatter())
        logger.addHandler(handler)
        logger.propagate = False
    logger.setLevel(level)


def verbosity_option(func: Callable[..., Any]) -> Callable[..., Any]:
    """Reusable -v/--verbosity option setting the padrick log level (default INFO, case-insensitive)."""

    def _set_level(ctx: click.Context, param: click.Parameter, value: str) -> None:
        configure_logging(logging.getLevelName(value.upper()))

    return click.option(
        "-v", "--verbosity",
        type=click.Choice(_LEVELS, case_sensitive=False),
        default="INFO",
        callback=_set_level,
        expose_value=False,
        is_eager=True,
        help="Set the log verbosity level.",
    )(func)
