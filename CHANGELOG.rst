=========
Changelog
=========

All notable changes to this project will be documented in this file.

The format is based on `Keep a Changelog <http://keepachangelog.com/en/1.0.0/>`_
and this project adheres to `Semantic Versioning <http://semver.org/spec/v2.0.0.html>`_.




Unreleased
==========

**Breaking**: the ``MUX_SEL`` register's single field is now explicitly named
``sel`` (previously anonymous). The register offsets and bit layout are
unchanged, but the reggen-generated SystemVerilog ``reg2hw`` struct gains a
``.sel`` level and the C field macros in ``*_regs.h`` are renamed (e.g.
``..._MUX_SEL_PAD_X_MUX_SEL_MASK`` becomes ``..._MUX_SEL_SEL_MASK``). This
aligns the reggen and PeakRDL register backends. The next release will be
0.4.0 accordingly.

Added
-----
* Added a selectable config-bus frontend via the padframe-level ``config_interface``
  field: ``regbus`` (default, the PULP register_interface), ``apb`` (APB4), ``axilite``
  (AXI4-Lite) and ``obi`` (OBI). The non-regbus frontends are implemented on the PeakRDL
  register backend (``--register-backend peakrdl``): the padframe instantiates a
  PeakRDL-regblock with the frontend's native cpuif (apb4 / axi4-lite / obi) instead of
  the reggen address demux, exposing the protocol as ``parameter type`` request/response
  struct ports (the OBI frontend uses the official pulp-platform ``obi`` structs) and
  pulling in the ``apb``/``axi``/``obi`` Bender dependency as needed. The reggen backend
  remains available for backwards compatibility but is frozen to ``regbus`` + ``shared``;
  selecting a frontend or the per-domain topology requires the peakrdl backend.
* Added a padframe-level ``config_port_topology`` field (peakrdl backend): ``shared``
  (default) instantiates a single flattened register block at the padframe top level, so
  the configuration is retained even when individual pad domains are power-cycled;
  ``per_domain`` instantiates one register block inside each pad domain module with its own
  cpuif port and no shared interconnect. Recommended for power-gated multi-domain designs.
* Added a ``hardwired`` mode for quasi-static pads (``quasi_static: hardwired``):
  the pad is directly tied to its single port with no multiplexer and no
  config/mux_sel registers. ``quasi_static: true`` keeps the previous behavior
  (now also expressible as ``quasi_static: muxed``).
* Integrated the PeakRDL/SystemRDL register backend into the generated padframe
  (``--register-backend peakrdl`` on ``generate rtl`` and ``generate driver``, requires the
  ``peakrdl`` extra). The register accesses in the pad multiplexer now route through a
  register block hardware interface (hwif) instead of the reggen ``reg2hw`` struct; reggen
  output is byte-for-byte unchanged. The flattened shared layout places each pad domain at
  the same offset the reggen address demux assigns. The ``generate driver`` peakrdl path
  emits PeakRDL-cheader register headers whose macro names differ from the reggen
  ``*_regs.h`` naming; the driver ``.c``/``.h`` accessor macros are not yet parameterized
  for that dialect, so the peakrdl driver headers are informational for now.
* Added a ``padrick schema`` command exporting the config file JSON Schema for
  editor completion/validation, and a ``--format json`` option on ``validate``
  for machine-readable results.
* Added experimental feature to mark dynamic pads as quasi_static. If this flag
  is set on a pad_instance, the config file parser will verify that there is
  exactly one and only one port connected to this pad_instance and will
  automatically set the default_port value to it.
* The constraints specification file for the ``generate constraints`` now
  supports the special token `res_val` to specify the default reset value for
  ``port_sel`` and ``pad_cfg`` entries (see the newly written docs section `Case
  Analysis Generator for Timing Constraints`
* Added a new ``generate mux-graph`` command to generate a PDF containing a
  schematic with the configured multiplexing structure.

Changed
-------
* Add documentation for ``generate constraints`` command.
* The reggen register backend is now frozen to its historical scope (``regbus``
  config_interface + ``shared`` topology). Selecting a config frontend or the
  ``per_domain`` topology with the reggen backend is rejected with a clear message
  pointing at ``--register-backend peakrdl``; the peakrdl backend in turn rejects the
  ``regbus`` frontend (it has no regbus cpuif by design).

Fixed
-----
* Fix a bug in the generated SDC case analysis constraints. The bit assignments
  where in reversed order.
* The generated padframe top module now elaborates in Synopsys Fusion Compiler
  (Presto). Member selects of a ``parameter type``-typed config signal in a port
  connection or continuous assign (which Presto rejects with VER-264 because the
  default ``req_t = logic`` has no members) are hoisted into procedural
  ``always_comb`` blocks. This changes only the generated padframe ``<name>.sv``
  top file; the rest of the generated output is unchanged.

v0.3.6 - 2022-12-14
===================

Changed
-------
* Prepare Metadata for Pypi release


v0.3.5 - 2022-12-14
===================

Added
-----
* Support for FuseSoC. Padrick now generated core files and can be invoked
  natively as a FuseSoC Generator.

v0.3.4 - 2022-12-06
===================

Added
-----
* User attributes now support nested dictionaries i.e. besides a string, boolean
  or an integer the value of an attribute can be another dictionary.
* The ``default_port`` field of pad_instances now support dictionaries of pad_name
  to port mappings. See the correspondingly updated ``default_port`` section in
  the docs.

Changed
-------
* User Attributes of ports, port_groups and pad_instances are now
  expanded as well when instantiated multiple times. The same mini
  expression languages applies.
* Improved manifest version warning messages
* Bumped manifest version to 3.

Fixed
-----


v0.3.3 - 2022-12-05
===================

Added
-----
* Added support for modular config file using pyyaml !include directives.

Changed
-------

Fixed
-----


v0.3.2 - 2022-10-21
===================

Added
-----
Added support for templated ``default_port`` in vectorized pad instances (pads with ``multiple`` > 1).

Changed
-------
Removed now obsolete hint about ``default_port`` with vectorized pad instances compatibility.


v0.3.1 - 2022-10-19
===================

Added
-----

Changed
-------

Fixed
-----
* Regression in driver template rendering that caused an error during the register file generation.


v0.3.0 - 2022-10-18
===================

Added
-----
* Added read-only IP info register with version id and pad count values to RTL template

Changed
-------
* Allow padframe generation without any muxed pads

Fixed
-----
* Fix address width bug in address demux rules when generating padframes with power's of two number of registers

v0.2.0 - 2022-25-04
===================

Added
-----
* Added support for multiple multiplex groups per pad/port. Each
  pad/port/port_group can now be member of severa mux_groups. This causes the
  union of all specified groups to be muxable to the pad,port or port_group in
  question.
* Add support for multi-ports. Ports now accept the new optional `multiple` key
  that allows to specify several port with similar structure without copy-paste-hell
* Add support for templated names, description and mux_groups to
  multi-pads/multi-ports using the '{i}' token. This feature simplifies the
  definition of GPIO ports. Check the example config file for an example on how
  to use the feature.
* Add version flag to CLI to print version information
* Add validation of manifest version. The CLI now prints out an error message if
  the manifest version is not supported anymore with a help message which
  version of Padrick supports the out-dated manifest version.
* Add mini expression language for template tokens.
* Render assignment macros in systemverilog package to simplify hierarchical assignements of port groups.
* Add optional format code feature to index templates.
* RTL generate command now supports supplying file headers to insert into the auto-generated files
* Auto-generate SystemVerilog header files with struct assignment macros
* Added optional key `default_port` to pad_instances of the form
  "<port_group_name>.<port_name>". This allows to specify a port that should be
  connected to the pad by default after reset. An error is raised if the
  specified default_port is not actually connectable to the pad (not in the same
  mux group).
* Added new CLI commands to customize internal Mako templates.
* Add optional user_attr key to padframe specification format. This allows users
  to tag pads, ports etc. with additional metadata and potentially use it within
  the custom templates.
* Add 'generate constraints' command to auto-generate SDC constraints for set_case_analysis of pad_mux config registers.
* Add new CLI generate command to render custom templates to support completely customized output formats
* Add more documentation on usage and structure of generated padrick output

Changed
-------
* Manifest version was increased to 2.
* Renamed `mux_group` key to `mux_groups` which now accepts a list of string instead of a single string.
* Updated  sample config files to be compatible with new manifest format.
* Switched to reg_interface version 3.1 and updated internal reggen version.
* Config file types of various fields to support expression language (makes fields like `default_static_value` incompatible with YAML integers)

Fixed
-----
* Fixed bug in toplevel padfram struct generation

0.1.0 - 2021-03-30
==================
Very first *alpha* release of Padrick with support for RTL Generation and Driver Generation.
