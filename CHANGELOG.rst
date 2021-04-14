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

Changed
-------
* Manifest version was increased to 2.
* Renamed `mux_group` key to `mux_groups` which now accepts a list of string instead of a single string.
* Updated  sample config files to be compatible with new manifest format.

Fixed
-----

0.1.0 - 2021-03-30
==================
Very first *alpha* release of Padrick with support for RTL Generation and Driver Generation.
