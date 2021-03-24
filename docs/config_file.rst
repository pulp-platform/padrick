===========================
Padframe Configuration File
===========================

Concepts and Terminology
========================

Configuration File Syntax
=========================
  The configuration file is written in YAML syntax. If you are unfamiliar with
  YAML or only sporadically used it so far, please take 2-3 minutes to read up
  on its most important featues since this will allow you to write cleaner
  configuration files. Especially the "anchor" and "reference" feature is quite
  usefull for this particular tool since it avoids copy-paste hell.

  At the root, the configuration file contains three key-value pairs:

  - name: The name of the pad_frame to generate (usefull if there is more than
    one and you want to avoid naming collision of the generated RTL)
  - manifest_version: The current configuration file syntax version used for
    this particular file (at the moment, this is always the value 1)
  - pad_domains: A yaml list of Pad Domains (see next subsection)

Pad Domain List
---------------

Pad Type Declarations
.....................

The Instantiation Template
,,,,,,,,,,,,,,,,,,,,,,,,,,

Pad Signals
,,,,,,,,,,,

Pad Instance List
.................

Ports and Port Groups
.....................


Port Multiplexing
=================





Schema Reference
================
The following table contains an auto-generated schema reference of the configuration file format.

.. pydantic:: padrick.Model.Padframe.Padframe
