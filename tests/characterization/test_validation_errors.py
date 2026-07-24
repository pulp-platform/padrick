# Copyright 2026 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Kai Berszin, ETH Zurich

"""
Table-driven error-path tests: pin the human-readable messages produced by
padrick's pydantic validators when parsing invalid padframe configs.

`padrick validate` reports parse failures on its output but always exits 0
(known behavior), so these tests assert on output content, not exit code.
"""
import copy
import io
from pathlib import Path
from typing import Any, Callable, Dict

import pytest
import ruamel.yaml

from conftest import run_padrick

# A minimal, known-good padframe. Every error case is a mutation of this base;
# test_base_config_is_valid guards that the base itself parses.
BASE_CONFIG: Dict[str, Any] = {
    "manifest_version": 4,
    "name": "minimal_padframe",
    "pad_domains": [
        {
            "name": "domain0",
            "pad_types": [
                {
                    "name": "gpio_pad",
                    "template": (
                        'PAD ${instance_name} (.PAD(${conn["pad"]}), '
                        '.I(${conn["chip2pad"]}), .O(${conn["pad2chip"]}), '
                        '.OE(${conn["out_en"]}));\n'
                    ),
                    "pad_signals": [
                        {"name": "pad", "size": 1, "kind": "pad"},
                        {"name": "chip2pad", "size": 1, "kind": "input",
                         "conn_type": "dynamic", "default_reset_value": 0,
                         "default_static_value": "1'b0"},
                        {"name": "out_en", "size": 1, "kind": "input",
                         "conn_type": "dynamic", "default_reset_value": 0,
                         "default_static_value": "1'b0"},
                        {"name": "pad2chip", "size": 1, "kind": "output",
                         "conn_type": "dynamic", "default_static_value": None},
                    ],
                }
            ],
            "pad_list": [
                {"name": "pad0", "pad_type": "gpio_pad", "mux_groups": ["all"]},
            ],
            "port_groups": [
                {
                    "name": "gpio",
                    "output_defaults": {"data_o": "1'b0"},
                    "ports": [
                        {"name": "gpio0", "mux_groups": ["all"],
                         "connections": {"chip2pad": "data_i", "out_en": "en_i",
                                         "data_o": "pad2chip"}},
                    ],
                }
            ],
        }
    ],
}


def _domain(config: Dict[str, Any]) -> Dict[str, Any]:
    return config["pad_domains"][0]


def _pad_signal(config: Dict[str, Any], name: str) -> Dict[str, Any]:
    for signal in _domain(config)["pad_types"][0]["pad_signals"]:
        if signal["name"] == name:
            return signal
    raise KeyError(name)


def _port(config: Dict[str, Any]) -> Dict[str, Any]:
    return _domain(config)["port_groups"][0]["ports"][0]


def _validate(config: Dict[str, Any], tmp_path: Path) -> str:
    """Write config to tmp_path, run `padrick validate`, return combined output."""
    config_file = tmp_path / "padframe.yaml"
    buffer = io.StringIO()
    ruamel.yaml.YAML().dump(config, buffer)
    config_file.write_text(buffer.getvalue())
    result = run_padrick(["validate", str(config_file)])
    return result.stdout + result.stderr


def test_base_config_is_valid(tmp_path: Path) -> None:
    """The unmutated base config parses successfully."""
    output = _validate(copy.deepcopy(BASE_CONFIG), tmp_path)
    assert "Successfully parsed configuration file." in output


# --- Mutations: each takes the config dict and modifies it in place ----------

def _mut_future_manifest(c): c["manifest_version"] = 99
def _mut_old_manifest(c): c["manifest_version"] = 1
def _mut_unknown_field(c): _pad_signal(c, "pad")["bogus_field"] = 1
def _mut_missing_required_field(c): del c["name"]
def _mut_missing_conn_type(c): del _pad_signal(c, "chip2pad")["conn_type"]
def _mut_reset_on_pad(c): _pad_signal(c, "pad")["default_reset_value"] = 1
def _mut_static_on_pad(c): _pad_signal(c, "pad")["default_static_value"] = "1'b0"
def _mut_reset_on_output(c): _pad_signal(c, "pad2chip")["default_reset_value"] = 0
def _mut_input_missing_reset(c): del _pad_signal(c, "chip2pad")["default_reset_value"]
def _mut_input_missing_static(c): del _pad_signal(c, "chip2pad")["default_static_value"]
def _mut_output_complex_default(c): _pad_signal(c, "pad2chip")["default_static_value"] = "a & b"


def _mut_duplicate_pad_name(c):
    _domain(c)["pad_list"].append(
        {"name": "pad0", "pad_type": "gpio_pad", "mux_groups": ["all"]})


def _mut_duplicate_port_group(c):
    _domain(c)["port_groups"].append(copy.deepcopy(_domain(c)["port_groups"][0]))


def _mut_duplicate_port_name(c):
    _domain(c)["port_groups"][0]["ports"].append(copy.deepcopy(_port(c)))


def _mut_duplicate_pad_signal(c):
    _domain(c)["pad_types"].append({
        "name": "gpio_pad2",
        "template": 'X ${instance_name}(.PAD(${conn["pad"]}));\n',
        "pad_signals": [
            {"name": "pad", "size": 1, "kind": "pad"},
            {"name": "chip2pad", "size": 2, "kind": "input",
             "conn_type": "dynamic", "default_reset_value": 0,
             "default_static_value": "2'b0"},
        ],
    })


def _mut_unknown_pad_type(c):
    _domain(c)["pad_list"][0]["pad_type"] = "nonexistent"


def _mut_connection_unknown_pad_signal(c):
    _domain(c)["pad_list"][0]["is_static"] = True
    _domain(c)["pad_list"][0]["connections"] = {"nope": "1'b0"}


def _mut_output_default_unknown_signal(c):
    _domain(c)["port_groups"][0]["output_defaults"]["nonexistent"] = "1'b0"


def _mut_output_default_nonconstant(c):
    _domain(c)["port_groups"][0]["output_defaults"] = {"data_o": "some_sig"}


def _mut_missing_pad2soc_default(c):
    _domain(c)["port_groups"][0]["output_defaults"] = {}


def _mut_mux_group_uppercase(c):
    _domain(c)["pad_list"][0]["mux_groups"] = ["ALL"]


def _mut_invalid_identifier(c): c["name"] = "1invalid"
def _mut_invalid_signal_expression(c): _pad_signal(c, "chip2pad")["default_static_value"] = "1'b0 @@ x"


def _mut_invalid_templated_identifier(c):
    _domain(c)["pad_list"][0]["name"] = "pad{i"
    _domain(c)["pad_list"][0]["multiple"] = 2


def _mut_output_signal_on_lhs(c):
    _port(c)["connections"]["pad2chip"] = "data_o"


CASES = [
    pytest.param(_mut_future_manifest,
                 "Manifest version 99 of the padframe config file is newer",
                 id="future_manifest_version"),
    pytest.param(_mut_old_manifest,
                 "Manifest version 1 of the padframe config file is incompatible",
                 id="unsupported_old_manifest_version"),
    pytest.param(_mut_unknown_field,
                 "Unknown field bogus_field. Did you mispell the field name?",
                 id="unknown_field"),
    pytest.param(_mut_missing_required_field,
                 "Missing field 'name'",
                 id="missing_required_field"),
    pytest.param(_mut_missing_conn_type,
                 "All Padsignals except the ones of kind 'pad' must contain a 'conn_type'",
                 id="padsignal_missing_conn_type"),
    pytest.param(_mut_reset_on_pad,
                 "Padsignals of kind 'pad' must not contain a default reset value.",
                 id="padsignal_reset_value_on_kind_pad"),
    pytest.param(_mut_static_on_pad,
                 "Padsignals of kind 'pad' must not contain a default static value.",
                 id="padsignal_static_value_on_kind_pad"),
    pytest.param(_mut_reset_on_output,
                 "Padsignals of kind 'output' must not contain a reset value.",
                 id="padsignal_reset_value_on_output"),
    pytest.param(_mut_input_missing_reset,
                 "Padsignals of kind 'input' must specify a default reset value",
                 id="padsignal_input_missing_reset"),
    pytest.param(_mut_input_missing_static,
                 "Padsignals of kind 'input' must specify a default static value",
                 id="padsignal_input_missing_static"),
    pytest.param(_mut_output_complex_default,
                 "Padsignals of kind 'output' must not have complex expression as "
                 "default_static_value",
                 id="padsignal_output_complex_default"),
    pytest.param(_mut_duplicate_pad_name,
                 "Duplicate pad instance name pad0. Pad instance names must be unique.",
                 id="duplicate_pad_name"),
    pytest.param(_mut_duplicate_port_group,
                 "Found duplicate port_group gpio. Port Group names must be unique.",
                 id="duplicate_port_group_name"),
    pytest.param(_mut_duplicate_port_name,
                 "Duplicate port name gpio0. Ports within a port group must be unique.",
                 id="duplicate_port_name"),
    pytest.param(_mut_duplicate_pad_signal,
                 "Duplicate pad signal chip2pad for pad domain0",
                 id="pad_signal_same_name_different_size"),
    pytest.param(_mut_unknown_pad_type,
                 "Unknown pad_type nonexistent. Did you mispell the pad_type or forgot to declare it?",
                 id="unknown_pad_type_reference"),
    pytest.param(_mut_connection_unknown_pad_signal,
                 "Pad Signal nope in scope of Pad Type gpio_pad",
                 id="connection_to_unknown_pad_signal"),
    pytest.param(_mut_output_default_unknown_signal,
                 "Found unknown port signal nonexistent in connetion_defaults section",
                 id="output_default_unknown_signal"),
    pytest.param(_mut_output_default_nonconstant,
                 "Expression some_sig for connection_default of port signal data_o is not constant.",
                 id="output_default_nonconstant_expression"),
    pytest.param(_mut_missing_pad2soc_default,
                 "Found port signal data_o with direction pad2soc that does not specify a "
                 "connection default.",
                 id="missing_pad2soc_connection_default"),
    pytest.param(_mut_mux_group_uppercase,
                 "Mux groups must not contain upper-case letters.",
                 id="mux_group_uppercase_letters"),
    pytest.param(_mut_invalid_identifier,
                 "String should match pattern",
                 id="invalid_systemverilog_identifier"),
    pytest.param(_mut_invalid_signal_expression,
                 "Illegal signal expresion: No terminal matches '@'",
                 id="invalid_signal_expression"),
    pytest.param(_mut_invalid_templated_identifier,
                 "Illegal identifier: Unexpected token",
                 id="invalid_templated_identifier"),
    pytest.param(_mut_output_signal_on_lhs,
                 "Output pad signal pad2chip must not appear on the left hand side in the "
                 "connections section.",
                 id="output_signal_on_connection_lhs"),
]


@pytest.mark.parametrize("mutate, expected_message", CASES)
def test_invalid_config_is_rejected(
    mutate: Callable[[Dict[str, Any]], None],
    expected_message: str,
    tmp_path: Path,
) -> None:
    """A mutated config fails to parse and reports the expected validator message."""
    config = copy.deepcopy(BASE_CONFIG)
    mutate(config)
    output = _validate(config, tmp_path)
    assert "Error while parsing configuration file" in output
    assert expected_message in output
