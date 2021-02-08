import re


def check_sv_literal(literal: str) ->str:
    pattern = re.compile(r"((\d+')?|')?(h[0-9a-fA-F]+|b[01xXzZ]+|(d)\d+|(o)?[0-7]+)")
    if not pattern.match(literal):
        raise ValueError(f"{literal} is not a supported SystemVerilog literal")
    return literal