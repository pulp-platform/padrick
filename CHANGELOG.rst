=========
Changelog
=========

All notable changes to this project will be documented in this file.

The format is based on `Keep a Changelog <http://keepachangelog.com/en/1.0.0/>`_
and this project adheres to `Semantic Versioning <http://semver.org/spec/v2.0.0.html>`_.


Unreleased
==========

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

Changed
-------
* Manifest version was increased to 2.
* Renamed `mux_group` key to `mux_groups` which now accepts a list of string instead of a single string.
* Updated  sample config files to be compatible with new manifest format.
* Switched to reg_interface version 3.1 and updated internal reggen version.

Fixed
-----
* Fixed bug in toplevel padfram struct generation

0.1.0 - 2021-03-30
==================
Very first *alpha* release of Padrick with support for RTL Generation and Driver Generation.
