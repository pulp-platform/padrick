# Copyright 2026 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Kai Berszin, ETH Zurich

"""
cocotb config-bus drivers for the padframe simulation suite. Each driver adapts
one toplevel config-bus frontend to the same ``reg_read``/``reg_write``
abstraction so the config-driven checks in cocotb_padframe.py stay
protocol-agnostic: only the register-access layer varies between frontends.

A driver owns the flattened bus scalars of its variant wrapper (see hw/*.sv) and
exposes:
  * ``idle_signals``  - inputs it drives, zeroed by the common reset routine
  * ``reset_idle``    - park the bus in its inactive state
  * ``reg_write``     - 32-bit register write, full byte-strobe
  * ``reg_read``      - 32-bit register read -> (data, error)

New frontends plug in by adding a driver class here and a wrapper in hw/; the
DUT-specific signal names live only in the driver + its wrapper, nowhere in the
common checks. Backend (reggen vs peakrdl) is orthogonal and can become a second
selection axis without touching this layer.
"""
from cocotb.triggers import RisingEdge, Timer


async def _settle(dut):
    await Timer(1, units="ns")


def _rd(sig):
    return int(sig.value)


# Watchdog so a stuck converter handshake fails the test fast instead of spinning
# the simulation forever. Every response is expected within a couple of cycles.
_TIMEOUT_CYCLES = 64


async def _await_high(dut, sig_name, what):
    """
    Advance clocks until *sig_name* reads high (sampled after a settle delay),
    then return with the signal still high on the current settle. Raises rather
    than looping unbounded if the handshake never completes.
    """
    for _ in range(_TIMEOUT_CYCLES):
        await _settle(dut)
        if _rd(getattr(dut, sig_name)):
            return
        await RisingEdge(dut.clk_i)
    raise AssertionError(f"timeout waiting for {what} ({sig_name})")


class RegBusDriver:
    """PULP register_interface: ready is combinational 1'b1, so one cycle/access."""

    idle_signals = ["reg_valid", "reg_write", "reg_addr", "reg_wdata", "reg_wstrb"]

    async def reset_idle(self, dut):
        dut.reg_valid.value = 0
        dut.reg_write.value = 0
        dut.reg_addr.value = 0
        dut.reg_wdata.value = 0
        dut.reg_wstrb.value = 0

    async def reg_write(self, dut, offset, data):
        dut.reg_addr.value = offset
        dut.reg_wdata.value = data
        dut.reg_wstrb.value = 0xF
        dut.reg_write.value = 1
        dut.reg_valid.value = 1
        await RisingEdge(dut.clk_i)
        dut.reg_valid.value = 0
        dut.reg_write.value = 0
        await _settle(dut)

    async def reg_read(self, dut, offset):
        dut.reg_addr.value = offset
        dut.reg_write.value = 0
        dut.reg_valid.value = 1
        await _settle(dut)
        data, err = _rd(dut.reg_rdata), _rd(dut.reg_error)
        await RisingEdge(dut.clk_i)
        dut.reg_valid.value = 0
        await _settle(dut)
        return data, err


class ApbDriver:
    """
    APB4 subordinate, two-phase (SETUP then ACCESS). The converter runs in
    feedthrough mode (combinational pready = reg ready = 1), so the ACCESS phase
    completes in a single cycle, but we still honour the pready handshake.
    """

    idle_signals = ["apb_psel", "apb_penable", "apb_pwrite", "apb_paddr", "apb_pwdata", "apb_pstrb"]

    async def reset_idle(self, dut):
        dut.apb_psel.value = 0
        dut.apb_penable.value = 0
        dut.apb_pwrite.value = 0
        dut.apb_paddr.value = 0
        dut.apb_pwdata.value = 0
        dut.apb_pstrb.value = 0

    async def _xfer(self, dut, offset, write, data):
        dut.apb_paddr.value = offset
        dut.apb_pwrite.value = 1 if write else 0
        dut.apb_pwdata.value = data
        dut.apb_pstrb.value = 0xF
        dut.apb_psel.value = 1
        dut.apb_penable.value = 0
        await RisingEdge(dut.clk_i)  # SETUP phase
        dut.apb_penable.value = 1
        # ACCESS phase: sample the transfer on the cycle pready is high.
        await _await_high(dut, "apb_pready", "APB pready")
        rdata, err = _rd(dut.apb_prdata), _rd(dut.apb_pslverr)
        await RisingEdge(dut.clk_i)
        dut.apb_psel.value = 0
        dut.apb_penable.value = 0
        await _settle(dut)
        return rdata, err

    async def reg_write(self, dut, offset, data):
        await self._xfer(dut, offset, True, data)

    async def reg_read(self, dut, offset):
        return await self._xfer(dut, offset, False, 0)


class AxiLiteDriver:
    """
    AXI4-Lite subordinate: independent AW/W/B and AR/R handshakes, no bursts.
    Address and data are launched together and their (possibly out-of-order)
    ready handshakes are collected before waiting on the response channel.
    """

    idle_signals = [
        "axi_aw_valid", "axi_aw_addr", "axi_w_valid", "axi_w_data", "axi_w_strb",
        "axi_b_ready", "axi_ar_valid", "axi_ar_addr", "axi_r_ready",
    ]

    async def reset_idle(self, dut):
        for name in self.idle_signals:
            getattr(dut, name).value = 0

    async def _await_handshake(self, dut, valid_name, ready_name):
        """Deassert *valid* on the first edge where the peer's *ready* is high."""
        await _await_high(dut, ready_name, f"AXI-Lite {ready_name}")
        await RisingEdge(dut.clk_i)
        getattr(dut, valid_name).value = 0

    async def reg_write(self, dut, offset, data):
        dut.axi_aw_addr.value = offset
        dut.axi_aw_valid.value = 1
        dut.axi_w_data.value = data
        dut.axi_w_strb.value = 0xF
        dut.axi_w_valid.value = 1
        dut.axi_b_ready.value = 1
        # axi_lite_to_reg couples the AW/W accept (aw_ready = w_ready = aw_valid &
        # w_valid & ~full), so both valids must stay asserted until both channels
        # are taken -- dropping aw_valid first would pull w_ready low forever. Track
        # each channel's accept independently to also cover a decoupled subordinate.
        aw_done = w_done = False
        for _ in range(_TIMEOUT_CYCLES):
            await _settle(dut)
            take_aw = not aw_done and _rd(dut.axi_aw_ready)
            take_w = not w_done and _rd(dut.axi_w_ready)
            await RisingEdge(dut.clk_i)
            if take_aw:
                dut.axi_aw_valid.value = 0
                aw_done = True
            if take_w:
                dut.axi_w_valid.value = 0
                w_done = True
            if aw_done and w_done:
                break
        else:
            raise AssertionError("timeout on AXI-Lite AW/W accept")
        await _await_high(dut, "axi_b_valid", "AXI-Lite B response")
        err = 1 if _rd(dut.axi_b_resp) else 0
        await RisingEdge(dut.clk_i)
        dut.axi_b_ready.value = 0
        await _settle(dut)
        return None, err

    async def reg_read(self, dut, offset):
        dut.axi_ar_addr.value = offset
        dut.axi_ar_valid.value = 1
        dut.axi_r_ready.value = 1
        await self._await_handshake(dut, "axi_ar_valid", "axi_ar_ready")
        await _await_high(dut, "axi_r_valid", "AXI-Lite R response")
        data = _rd(dut.axi_r_data)
        err = 1 if _rd(dut.axi_r_resp) else 0
        await RisingEdge(dut.clk_i)
        dut.axi_r_ready.value = 0
        await _settle(dut)
        return data, err


class ObiDriver:
    """
    OBI subordinate in its implicit-ready subset. The internal register interface
    is always ready, so periph_to_reg grants the address phase combinationally and
    returns rvalid the cycle after the grant, unconditionally: it never inspects
    the manager's rready. We therefore pin rready = 1 for the whole run and assert
    that rvalid is accepted immediately (exactly one cycle after grant); if a
    future subordinate started gating rvalid on rready this assertion would fail.
    """

    idle_signals = ["obi_req", "obi_addr", "obi_we", "obi_be", "obi_wdata", "obi_aid", "obi_rready"]

    async def reset_idle(self, dut):
        dut.obi_req.value = 0
        dut.obi_addr.value = 0
        dut.obi_we.value = 0
        dut.obi_be.value = 0
        dut.obi_wdata.value = 0
        dut.obi_aid.value = 0
        dut.obi_rready.value = 1  # implicit-ready subset: always accept responses

    async def _xfer(self, dut, offset, we, data):
        dut.obi_rready.value = 1
        dut.obi_addr.value = offset
        dut.obi_we.value = 1 if we else 0
        dut.obi_be.value = 0xF
        dut.obi_wdata.value = data
        dut.obi_req.value = 1
        # Address phase: gnt is combinational here, so it is high this same cycle.
        await _await_high(dut, "obi_gnt", "OBI gnt")
        await RisingEdge(dut.clk_i)  # grant taken; address phase done
        dut.obi_req.value = 0
        # Implicit-ready invariant: rvalid must be up exactly now, with rready held
        # high the whole time. No polling loop -- if it is not immediate the
        # subordinate is gating on rready, which this subset forbids.
        await _settle(dut)
        assert _rd(dut.obi_rvalid) == 1, "OBI rvalid not accepted immediately (implicit-ready broken)"
        data, err = _rd(dut.obi_rdata), _rd(dut.obi_err)
        await RisingEdge(dut.clk_i)
        await _settle(dut)
        return data, err

    async def reg_write(self, dut, offset, data):
        await self._xfer(dut, offset, True, data)

    async def reg_read(self, dut, offset):
        return await self._xfer(dut, offset, False, 0)


DRIVERS = {
    "regbus": RegBusDriver,
    "apb": ApbDriver,
    "axilite": AxiLiteDriver,
    "obi": ObiDriver,
}


def make_driver(frontend):
    return DRIVERS[frontend]()
