# Copyright 2026 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Kai Berszin, ETH Zurich

"""
cocotb tests for the generated sim_padframe. Expectations are derived from the
same YAML config (parsed through padrick's own model) and from the generated
register description (offsets and field/enum layout), so the checks track the
config rather than hard-coded magic.

The same checks run against every (config-bus frontend x register backend) point
in the matrix: the register-access layer is abstracted behind a bus driver
selected by PADRICK_SIM_FRONTEND (see bus_drivers.py), and the register-map
introspection source is selected by PADRICK_SIM_BACKEND. Only the driver and the
introspection source -- not the checks -- vary across the matrix. The two backends
describe the same register map at the same offsets:
  * reggen  (regbus)          -- reg_pkg OFFSET params + regfile hjson.
  * peakrdl (apb/axilite/obi) -- flattened regblock reg_top decode + the .rdl.
"""
import os
import re
from pathlib import Path

import hjson

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer

from padrick.ConfigParser import parse_config
from padrick.Model.Padframe import Padframe

from bus_drivers import make_driver

GEN_DIR = Path(os.environ["PADRICK_SIM_GEN_DIR"])
CONFIG = Path(os.environ["PADRICK_SIM_YAML"])
FRONTEND = os.environ.get("PADRICK_SIM_FRONTEND", "regbus")
BACKEND = os.environ.get("PADRICK_SIM_BACKEND", "reggen")
DRIVER = make_driver(FRONTEND)

SRC = GEN_DIR / "src"


# Config / register-map introspection (done once at import time). Each backend
# emits a different set of artifacts describing the same map at the same offsets.
def _reggen_offsets():
    """reg_pkg CONFIG_<REG>_OFFSET localparams -> {reg_name: byte_offset}."""
    pkg = (SRC / "sim_padframe_core_config_reg_pkg.sv").read_text()
    offsets = {}
    for m in re.finditer(r"CONFIG_(\w+?)_OFFSET\s*=\s*\d+'h\s*([0-9a-fA-F]+)", pkg):
        offsets[m.group(1).lower()] = int(m.group(2), 16)
    return offsets


def _reggen_layout():
    """regfile hjson -> {reg: {fields: {name: (lsb, width)}, enum: {name: value}}}."""
    doc = hjson.loads((SRC / "sim_padframe_core_regs.hjson").read_text())
    layout = {}
    for reg in doc["registers"]:
        if not isinstance(reg, dict) or "name" not in reg:
            continue
        name = reg["name"].lower()
        fields = {}
        enum = {}
        for fld in reg.get("fields", []):
            bits = str(fld["bits"])
            if ":" in bits:
                hi, lo = (int(x) for x in bits.split(":"))
            else:
                hi = lo = int(bits)
            fields[fld.get("name", name)] = (lo, hi - lo + 1)
            for e in fld.get("enum", []):
                enum[e["name"]] = int(e["value"])
        layout[name] = {"fields": fields, "enum": enum}
    return layout


def _peakrdl_offsets():
    """Flattened regblock reg_top address decode -> {reg_name: byte_offset}. The
    decode lines (`decoded_reg_strb.<blk>.<REG> = ... cpuif_addr == N'hX`) are the
    authoritative offset source; the peakrdl reg_pkg has no per-register offsets."""
    top = (SRC / "sim_padframe_config_reg_top.sv").read_text()
    offsets = {}
    for m in re.finditer(r"decoded_reg_strb\.\w+\.(\w+)\s*=[^\n]*?cpuif_addr == \d+'h([0-9a-fA-F]+)", top):
        offsets[m.group(1).lower()] = int(m.group(2), 16)
    return offsets


def _peakrdl_layout():
    """SystemRDL source -> {reg: {fields: {name: (lsb, width)}, enum: {name: value}}}.
    Parsed line-based (the .rdl nests braces inside enum bodies, so a naive regex
    over the whole file would mis-balance)."""
    layout = {}
    fields, enum, in_enum = {}, {}, False
    for raw in (SRC / "sim_padframe_regs.rdl").read_text().splitlines():
        s = raw.strip()
        if s.startswith("reg {"):
            fields, enum, in_enum = {}, {}, False
        elif s.startswith("enum "):
            in_enum = True
        elif in_enum and s == "};":
            in_enum = False
        elif in_enum:
            m = re.match(r"(\w+)\s*=\s*(\d+)", s)
            if m:
                enum[m.group(1)] = int(m.group(2))
        elif s.startswith("field"):
            m = re.search(r"\}\s*(\w+)\s*\[(\d+):(\d+)\]", s)
            if m:
                hi, lo = int(m.group(2)), int(m.group(3))
                fields[m.group(1)] = (lo, hi - lo + 1)
        elif s.startswith("}"):
            m = re.match(r"\}\s*(\w+)", s)  # reg close: `} REG;` / `} INFO @ 0x0;`
            if m:
                layout[m.group(1).lower()] = {"fields": fields, "enum": enum}
    return layout


if BACKEND == "peakrdl":
    OFFSETS = _peakrdl_offsets()
    LAYOUT = _peakrdl_layout()
    # The peakrdl regblock is generated without an address-validity check, so an
    # access to an unmapped address returns rdata=0 with no error (the reggen
    # reg_top instead routes unmapped accesses to an error slave). Reflected in
    # the unmapped-address check below.
    UNMAPPED_ERRORS = False
else:
    OFFSETS = _reggen_offsets()
    LAYOUT = _reggen_layout()
    UNMAPPED_ERRORS = True

PADFRAME = parse_config(Padframe, CONFIG)
PADS = {p.name: p for p in PADFRAME.pad_domains[0].pad_list}


def mux_value(pad, group, port):
    return LAYOUT[f"{pad}_mux_sel"]["enum"][f"port_{group}_{port}"]


def cfg_field(pad, field):
    return LAYOUT[f"{pad}_cfg"]["fields"][field]


# Wiring of each (port_group, port) to the flattened wrapper signals. This is
# inherent to sim_padframe_tb_top.sv, so it is intentionally explicit here.
PORT_WIRING = {
    ("periph", "p_out"): {"kind": "out", "soc": "periph_pout_o"},
    ("periph", "p_in"): {"kind": "in", "soc": "periph_pin_i"},
    ("periph", "p_bidir"): {"kind": "bidir", "o": "periph_bo", "oe": "periph_boe", "i": "periph_bi"},
    ("qs", "qs_p"): {"kind": "bidir", "o": "qs_qso", "oe": "qs_qsoe", "i": "qs_qsi"},
    ("hw", "hw_p"): {"kind": "bidir", "o": "hw_hwo", "oe": "hw_hwoe", "i": "hw_hwi"},
}

# Frontend-agnostic inputs (port-group SoC-side + landing-pad drivers). The
# config-bus inputs are owned by the selected driver (DRIVER.reset_idle).
PORT_INPUTS = [
    "periph_pout_o", "periph_bo", "periph_boe", "qs_qso", "qs_qsoe", "hw_hwo", "hw_hwoe",
    "pad_clk_drv", "pad_clk_drv_en", "pad_io0_drv", "pad_io0_drv_en",
    "pad_io1_drv", "pad_io1_drv_en", "pad_io2_drv", "pad_io2_drv_en",
    "pad_qs_drv", "pad_qs_drv_en", "pad_hw_drv", "pad_hw_drv_en",
]


# Bench helpers
def rd(sig):
    return int(sig.value)


async def settle(dut):
    await Timer(1, units="ns")


async def reset(dut):
    await cocotb.start(Clock(dut.clk_i, 10, units="ns").start())
    for name in PORT_INPUTS:
        getattr(dut, name).value = 0
    await DRIVER.reset_idle(dut)
    dut.rst_ni.value = 0
    for _ in range(5):
        await RisingEdge(dut.clk_i)
    dut.rst_ni.value = 1
    for _ in range(2):
        await RisingEdge(dut.clk_i)


async def reg_write(dut, offset, data):
    await DRIVER.reg_write(dut, offset, data)


async def reg_read(dut, offset):
    return await DRIVER.reg_read(dut, offset)


def drive_pad(dut, pad, value):
    getattr(dut, f"pad_{pad}_drv").value = value
    getattr(dut, f"pad_{pad}_drv_en").value = 1


def release_pad(dut, pad):
    getattr(dut, f"pad_{pad}_drv_en").value = 0


# Tests
@cocotb.test()
async def test_info_register(dut):
    """Smoke test: config-bus connectivity via the read-only INFO register."""
    await reset(dut)
    data, err = await reg_read(dut, OFFSETS["info"])
    assert err == 0, "INFO read raised a bus error"
    assert data & 0xFFFF == 2, f"unexpected HW_VERSION {data & 0xFFFF}"
    assert (data >> 16) & 0xFFFF == 4, f"unexpected PADCOUNT {(data >> 16) & 0xFFFF}"


async def check_default_route(dut, pad):
    """Check (a): after reset a pad routes its default_port in the right direction."""
    group, port = PADS[pad].default_port[0].name, PADS[pad].default_port[1].name
    wiring = PORT_WIRING[(group, port)]
    short = pad.replace("pad_", "")

    if wiring["kind"] == "out":
        for v in (1, 0, 1):
            getattr(dut, wiring["soc"]).value = v
            await settle(dut)
            assert rd(getattr(dut, f"pad_{short}_val")) == v, f"{pad} out mismatch"
    elif wiring["kind"] == "in":
        for v in (1, 0, 1):
            drive_pad(dut, short, v)
            await settle(dut)
            assert rd(getattr(dut, wiring["soc"])) == v, f"{pad} in mismatch"
        release_pad(dut, short)
    else:  # bidirectional
        getattr(dut, wiring["oe"]).value = 1
        for v in (1, 0):
            getattr(dut, wiring["o"]).value = v
            await settle(dut)
            assert rd(getattr(dut, f"pad_{short}_val")) == v, f"{pad} bidir-out mismatch"
        getattr(dut, wiring["oe"]).value = 0
        for v in (1, 0):
            drive_pad(dut, short, v)
            await settle(dut)
            assert rd(getattr(dut, wiring["i"])) == v, f"{pad} bidir-in mismatch"
        release_pad(dut, short)


@cocotb.test()
async def test_default_port_routing(dut):
    """Check (a): every dynamic/quasi-static pad with a default_port routes it after reset."""
    await reset(dut)
    routed = [n for n, p in PADS.items()
              if p.default_port and not p.is_hardwired and (p.default_port[0].name, p.default_port[1].name) in PORT_WIRING]
    assert routed, "no default-port pads discovered from config"
    for pad in routed:
        await check_default_route(dut, pad)


@cocotb.test()
async def test_mux_sel_reprogram(dut):
    """Check (b): reprogramming a dynamic pad's MUX_SEL over the bus re-routes it."""
    await reset(dut)
    # pad_io0 defaults to periph.p_out; re-route it to periph.p_in.
    new_val = mux_value("pad_io0", "periph", "p_in")
    await reg_write(dut, OFFSETS["pad_io0_mux_sel"], new_val)

    readback, err = await reg_read(dut, OFFSETS["pad_io0_mux_sel"])
    assert err == 0 and readback == new_val, f"MUX_SEL readback {readback} != {new_val}"

    # pad_io0 is now an input arbitrated onto periph.p_in (lowest index wins).
    for v in (1, 0, 1):
        drive_pad(dut, "io0", v)
        await settle(dut)
        assert rd(dut.periph_pin_i) == v, "re-routed pad_io0 did not drive periph.p_in"
    release_pad(dut, "io0")


@cocotb.test()
async def test_hardwired_pad(dut):
    """Check (c): the hardwired pad routes its port with no config registers present."""
    await reset(dut)
    assert PADS["pad_hw"].is_hardwired
    assert "pad_hw_mux_sel" not in OFFSETS and "pad_hw_cfg" not in OFFSETS, \
        "hardwired pad unexpectedly has config registers"

    # Output direction (hwoe = 1) then input direction (hwoe = 0).
    dut.hw_hwoe.value = 1
    for v in (1, 0):
        dut.hw_hwo.value = v
        await settle(dut)
        assert rd(dut.pad_hw_val) == v, "hardwired pad did not drive from hw.hw_p"
    dut.hw_hwoe.value = 0
    for v in (1, 0):
        drive_pad(dut, "hw", v)
        await settle(dut)
        assert rd(dut.hw_hwi) == v, "hardwired pad did not feed hw.hw_p"
    release_pad(dut, "hw")

    # An unmapped register address (past the last mapped offset). The reggen
    # reg_top routes it to an error slave; the peakrdl regblock is generated
    # without an address check and returns no error (UNMAPPED_ERRORS).
    _, err = await reg_read(dut, max(OFFSETS.values()) + 4)
    assert err == (1 if UNMAPPED_ERRORS else 0), \
        f"unmapped register address error {err} != {int(UNMAPPED_ERRORS)}"


@cocotb.test()
async def test_static_pad(dut):
    """Check (d): the static pad reflects its static connection expression."""
    await reset(dut)
    assert PADS["pad_clk"].is_static
    # pad_clk: rx_en tied 1, output_en tied 0 -> refclk follows the external pad.
    for v in (1, 0, 1):
        drive_pad(dut, "clk", v)
        await settle(dut)
        assert rd(dut.refclk) == v, "static pad_clk did not forward to refclk"
    release_pad(dut, "clk")


@cocotb.test()
async def test_register_mode_fallback(dut):
    """Check (e): forcing a quasi-static pad's mux_sel to 0 drives it from its CFG register."""
    await reset(dut)
    assert PADS["pad_qs"].quasi_static == "muxed"
    await reg_write(dut, OFFSETS["pad_qs_mux_sel"], 0)  # register mode

    c2p_lsb, _ = cfg_field("pad_qs", "chip2pad")
    oe_lsb, _ = cfg_field("pad_qs", "output_en")
    dut.qs_qsoe.value = 0  # port must not drive in register mode

    for v in (1, 0, 1):
        await reg_write(dut, OFFSETS["pad_qs_cfg"], (1 << oe_lsb) | (v << c2p_lsb))
        await settle(dut)
        assert rd(dut.pad_qs_val) == v, "register-mode pad_qs did not drive from CFG"
