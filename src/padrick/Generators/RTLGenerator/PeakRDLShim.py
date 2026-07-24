# Copyright 2026 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Kai Berszin, ETH Zurich
"""Template helpers wiring the padframe config frontend structs to a PeakRDL-regblock
native cpuif.

The peakrdl backend instantiates a regblock generated with the *flattened* cpuif variant
of the selected frontend (apb4/axi4lite/obi), i.e. the register block exposes plain
`s_<proto>_*` signals instead of a SystemVerilog interface. These helpers emit the toplevel
port declarations (identical struct-typed ports to the ones the reggen frontends documented)
and the dot-connections from the PULP request/response structs onto those flat cpuif signals.
Shared between padframe.sv.mako (shared topology, one regblock at the top) and pad_domain.sv.mako
(per_domain topology, one regblock per domain module).
"""
from typing import List, Optional


def cfg_base(topology: str, domain: Optional[str], frontend: str) -> str:
    """Toplevel config-port base name, e.g. 'config_apb' (shared) or '<domain>_apb'."""
    proto = "axi" if frontend == "axilite" else frontend
    if topology == "shared":
        return f"config_{proto}"
    return f"{domain}_{proto}"


def frontend_type_names(frontend: str) -> List[str]:
    """The [request, response] struct type-parameter names for the selected frontend."""
    if frontend == "apb":
        return ["apb_req_t", "apb_resp_t"]
    if frontend == "axilite":
        return ["axi_lite_req_t", "axi_lite_resp_t"]
    return ["obi_req_t", "obi_rsp_t"]


def frontend_param_ports(frontend: str) -> List[str]:
    """Module parameter-type declarations for the selected frontend's request/response structs.

    Bare declarations without a trailing comma; the caller joins them (and adds a separator
    comma only where another parameter follows in the module header).
    """
    return [f"  parameter type {name} = logic" for name in frontend_type_names(frontend)]


def frontend_param_connections(frontend: str) -> List[str]:
    """`.apb_req_t(apb_req_t)`-style parameter forwardings for a submodule instantiation."""
    return [f"    .{name}({name})" for name in frontend_type_names(frontend)]


def frontend_signal_ports(frontend: str, base: str) -> List[str]:
    """Toplevel config request/response port declarations for the selected frontend."""
    if frontend == "apb":
        return [f"  input apb_req_t                            {base}_req_i",
                f"  output apb_resp_t                          {base}_rsp_o"]
    if frontend == "axilite":
        return [f"  input axi_lite_req_t                       {base}_req_i",
                f"  output axi_lite_resp_t                     {base}_rsp_o"]
    # obi
    return [f"  input obi_req_t                            {base}_req_i",
            f"  output obi_rsp_t                           {base}_rsp_o"]


# Per-frontend cpuif signal table used to build a Presto-safe wiring shim. Each row is
# (flat regblock signal, direction, width-key, struct member path relative to req/rsp).
# direction 'i': PULP request -> regblock input; 'o': regblock output -> PULP response.
# Synopsys Fusion Compiler (Presto) rejects member selects of a `parameter type`-typed signal
# in a port connection (VER-264), so instead of connecting the struct members directly we
# unpack them into plain intermediate signals inside an always_comb and wire those.
_CPUIF_FIELDS = {
    "apb": ("s_apb_", [
        ("psel", "i", "bit", ".psel"),
        ("penable", "i", "bit", ".penable"),
        ("pwrite", "i", "bit", ".pwrite"),
        ("pprot", "i", "prot", ".pprot"),
        ("paddr", "i", "ADDR", ".paddr"),
        ("pwdata", "i", "DATA", ".pwdata"),
        ("pstrb", "i", "STRB", ".pstrb"),
        ("pready", "o", "bit", ".pready"),
        ("prdata", "o", "DATA", ".prdata"),
        ("pslverr", "o", "bit", ".pslverr"),
    ]),
    "axilite": ("s_axil_", [
        ("awvalid", "i", "bit", ".aw_valid"),
        ("awaddr", "i", "ADDR", ".aw.addr"),
        ("awprot", "i", "prot", ".aw.prot"),
        ("wvalid", "i", "bit", ".w_valid"),
        ("wdata", "i", "DATA", ".w.data"),
        ("wstrb", "i", "STRB", ".w.strb"),
        ("bready", "i", "bit", ".b_ready"),
        ("arvalid", "i", "bit", ".ar_valid"),
        ("araddr", "i", "ADDR", ".ar.addr"),
        ("arprot", "i", "prot", ".ar.prot"),
        ("rready", "i", "bit", ".r_ready"),
        ("awready", "o", "bit", ".aw_ready"),
        ("wready", "o", "bit", ".w_ready"),
        ("bvalid", "o", "bit", ".b_valid"),
        ("bresp", "o", "resp", ".b.resp"),
        ("arready", "o", "bit", ".ar_ready"),
        ("rvalid", "o", "bit", ".r_valid"),
        ("rdata", "o", "DATA", ".r.data"),
        ("rresp", "o", "resp", ".r.resp"),
    ]),
    "obi": ("s_obi_", [
        ("req", "i", "bit", ".req"),
        ("addr", "i", "ADDR", ".a.addr"),
        ("we", "i", "bit", ".a.we"),
        ("be", "i", "STRB", ".a.be"),
        ("wdata", "i", "DATA", ".a.wdata"),
        ("aid", "i", "ID", ".a.aid"),
        ("rready", "i", "bit", ".rready"),
        ("gnt", "o", "bit", ".gnt"),
        ("rvalid", "o", "bit", ".rvalid"),
        ("rdata", "o", "DATA", ".r.rdata"),
        ("err", "o", "bit", ".r.err"),
        ("rid", "o", "ID", ".r.rid"),
    ]),
}


def _width_decl(wkey: str, addr_width: str, id_width: str) -> str:
    return {"bit": "", "prot": "[2:0] ", "resp": "[1:0] ",
            "DATA": "[31:0] ", "STRB": "[3:0] ",
            "ADDR": f"[{addr_width}-1:0] ", "ID": f"[{id_width}-1:0] "}[wkey]


def obi_id_width_expr(req: str) -> str:
    """Elaboration-time OBI transaction-id width (used for a localparam, not a port select)."""
    return f"$bits({req}.a.aid)"


def regblock_inst_params(frontend: str, id_width: str = "CpuifObiIdWidth") -> List[str]:
    """Parameter overrides for the regblock instance (OBI needs its transaction ID width)."""
    if frontend == "obi":
        return [f"    .ID_WIDTH({id_width})"]
    return []


def cpuif_intermediate_decls(frontend: str, addr_width: str,
                             id_width: str = "CpuifObiIdWidth") -> List[str]:
    """Plain-signal declarations that mirror the regblock's flat cpuif ports."""
    prefix, fields = _CPUIF_FIELDS[frontend]
    return [f"   logic {_width_decl(w, addr_width, id_width)}{prefix}{name}_i;"
            for (name, _d, w, _p) in fields]


def cpuif_unpack_lines(frontend: str, req: str, rsp: str, addr_width: str) -> List[str]:
    """always_comb body unpacking the request struct into, and packing the response struct
    from, the intermediate signals."""
    prefix, fields = _CPUIF_FIELDS[frontend]
    lines = []
    for (name, d, w, path) in fields:
        sig = f"{prefix}{name}_i"
        if d == "i":
            src = f"{req}{path}[{addr_width}-1:0]" if w == "ADDR" else f"{req}{path}"
            lines.append(f"     {sig} = {src};")
        else:
            lines.append(f"     {rsp}{path} = {sig};")
    return lines


def regblock_cpuif_connections(frontend: str) -> List[str]:
    """Dot-connections from the regblock's flat cpuif ports onto the intermediate signals."""
    prefix, fields = _CPUIF_FIELDS[frontend]
    return [f"    .{prefix}{name}({prefix}{name}_i)" for (name, _d, _w, _p) in fields]
