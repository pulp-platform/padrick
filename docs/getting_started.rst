===============
Getting Started
===============

Installing Padrick
------------------
Padrick is  a CLI tool that you invoke on a configuration file that
describes the structure of your SoCs pad multiplexing and IO mapping scheme. The
very first step of ussing padrick is thus installing it. There are two ways to
install padrick on your system;

Installing Padrick as a Python Package
.......................................

If you have python3.6 or newer available on your system, you can directly
install padrick using ``pip``::

  pip install git+ssh://git@github.com:pulp-platform/padrick.git

Or if you prefer https over ssh::

  pip install git+https://github.com/pulp-platform/padrick.git

If you plan to modify or frequently update padrick you might want to install it
with the pip editable flag so changes to the source code of padrick take effect
immediately to all Python environments were you installed padrick::

  git clone https://github.com/pulp-platform/padrick.git
  pip install -e ./padrick

These approaches will install all the required python dependencies automatically
and make the command line tool ``padrick`` available for your shell.


Downloading a Binary Distribution/Using Padrick without Python
..............................................................

If your development environment does not provide a reccent Python 3 installation
or you are unable to install any additional python dependencies you can use
binary appimage distribution of Padrick. The binary wraps its own python
interpreter in a Rust executable to interpret the padrick python source code
embedded within the binary itself (this is enabled by a project called
`Pyoxidizer <https://pyoxidizer.readthedocs.io>`_). Any Linux distribution with
glibc version 2.3.3 or newer should be able to run the Appimage binary. This
includes but is not limited to the following or newer LInux Distributions:

* Debian 6
* Fedora 16
* OpenSUSE 11.4
* RHEL/CentOS 6
* Ubuntu 12.04


.. note:: Once the Padrick is open-sourced, you can find these binaries in the
          release section. Until then, please ask the author for the binaries
          directly.


Writing a Padframe Configuration File
-------------------------------------

The next step after installing Padrick is to write a configuration file for your
padframe. The configuration file captures all information about the padframe
required for your SoC, from IO cell specifications, IO peripheral signal
declaration to multiplexing strategy. The config file is written in YAML, a
powerful, human readable markup language. The following listing shows you a
minimal padframe configuration file to generate a simple padframe for an SoC
with 4 pads an SPI and a UART peripheral where each signals of the UART or SPI
peripheral can be routed to anyone of the four available pads. 

.. code-block:: yaml

   manifest_version: 2
   name: my_padframe
   pad_domains:
     - name: my_domain
       pad_types:
         - name: iocell_xy
           template: |
             IOLIB_IOCELL_XY ${instance_name} (
               .PAD(${conn["pad"]}),
               .I(${conn["chip2pad"]}),
               .O(${conn["pad2chip"]}),
               .OUT_EN(${conn["tx_en"]})
             );
           pad_signals:
             - name: pad
               size: 1
               kind: pad
             - name: chip2pad
               size: 1
               kind: input
               conn_type: dynamic
               default_reset_value: 0
               default_static_value: 1'b0
             - name: pad2chip
               description: "The signal that connects to the pads RX buffer"
               size: 1
               kind: output
               conn_type: dynamic
             - name: tx_en
               description: "Active high RX driver enable "
               size: 1
               kind: input
               conn_type: dynamic
               # by default, the output driver is disabled
               default_reset_value: 1
               default_static_value: 1'b1
       pad_list:
         - name: iopad_{i}
           multiple: 4
           pad_type: iocell_xy
       port_groups:
         - name: SPIM
           output_defaults: 1'b0
           ports:
             - name: miso
               connections:
                 miso: pad2chip
                 tx_e: 1'b0
             - name: mosi
               connections:
                 chip2pad: mosi
                 tx_en: 1'b1
             - name: sck
               connections:
                 chip2pad: sck
                 tx_en: 1'b1
             - name: cs
               connections:
                 chip2pad: cs
                 tx_en: 1'b1
         - name: UART
           output_defaults: 1'b0
           ports:
             - name: rx
               connections:
                 uart_rx: pad2chip
                 tx_en: 1'b0
             - name: tx
               connections:
                 chip2pad: uart_tx
                 tx_en: 1'b1

The different keys and settings in this example might seem confusing at the
moment, but they are all explained in detail in chapter :ref:`Padframe Configuration
File<chapter_padframe_config_file>`. For the purpose of this introductionary
tutorial, just copy the content of the example to a new file and give it the
name my_padrame_config.yaml

Validating the Configuration File
---------------------------------

Now that we wrote our first configuration file, it is time to validate it.
Padrick contains extensive validation checks. Not only does it make sure that
the configuration file is properly formated and contains all required keys with
corresponding value of the right type, it also runs a number of sanity checks on
your configuration to detect semantic mistakes e.g. IO signals without
corresponding pads or naming conflicts. While padrick always validates your
config file before rendering any output there is a dedicated CLI command to run
validation only::

  padrick validate my_padframe_config.yaml

If you copied the example above you will see a user friendly error message
pointing out a typo in your config file. On line 46 there is a type: The
connection entry should be `tx_en: 1'b0` instead of `tx_e: 1'b0`. Correct the
mistake and validate the config file once again. Now you should not encounter
any errors.

Generating the RTL for the Padframe IP
--------------------------------------

Now that we validated the syntactic (and to some degree semantic) correctness of
our configuration file it is time to generate the padframe. To do so, type the following command::

  padrick generate rtl my_padframe_config.yaml -o my_padframe_ip


This will generate a new folder called `my_padframe_ip` in your current
directory and renders the complete padframe IP. The generated IP instantiates
our IO pads using our specified IO cells, generated the multiplexing logic to
route our IO peripheral signals (SPI and UART) to one of those pads and
instantiates a register file to configure the connectivity and the configuration
of the IO pads through some configuration interface.

A closer inspection of the
folder content reveals the following folder structure:

|  my_padframe_ip
|  ├── Bender.yml
|  ├── ips_list.yml
|  ├── src
|  │   ├── my_padframe_my_domain_config_reg_pkg.sv
|  │   ├── my_padframe_my_domain_config_reg_top.sv
|  │   ├── my_padframe_my_domain_muxer.sv
|  │   ├── my_padframe_my_domain_pads.sv
|  │   ├── my_padframe_my_domain_regs.hjson
|  │   ├── my_padframe_my_domain.sv
|  │   ├── my_padframe.sv
|  │   ├── pkg_internal_my_padframe_my_domain.sv
|  │   └── pkg_my_padframe.sv
|  └── src_files.yml

At the top-level, there are some IP manifest files that simplify the integration
of our IP in an SoC using an IP dependency management tool.

.. hint::

   `Bender.yml` is used for the more modern PULP IP management tool
   `Bender <https://github.com/pulp-platform/bender>`_ while `src_files.yml` and
   `ips_list.yml` are required for usage with the legacy pulp IP tool `IPApproX
   <https://https://github.com/pulp-platform/IPApproX>`_.

The `src` directory contains all the generated SystemVerilog source files where
`my_padframe.sv` contains the toplevel module. Let's have a look at the interface of this module:

.. code-block:: verilog

   module my_padframe
     import pkg_my_padframe::*;
   #(
     parameter int unsigned   AW = 32,
     parameter int unsigned   DW = 32,
     parameter type req_t = logic, // reg_interface request type
     parameter type resp_t = logic, // reg_interface response type
     parameter logic [DW-1:0] DecodeErrRespData = 32'hdeadda7a
   )(
     input logic                                clk_i,
     input logic                                rst_ni,
     output port_signals_pad2soc_t              port_signals_pad2soc,
     input port_signals_soc2pad_t               port_signals_soc2pad,
     // Landing Pads
     inout wire logic                           pad_my_domain_iopad_0_pad,
     inout wire logic                           pad_my_domain_iopad_1_pad,
     inout wire logic                           pad_my_domain_iopad_2_pad,
     inout wire logic                           pad_my_domain_iopad_3_pad,
     // Config Interface
     input req_t                                config_req_i,
     output resp_t                              config_rsp_o
     );

     ...

Apart from a clock and reset signal, the module exposes the IO peripheral
signals for UART and SPI peripheral (`port_signals_pad2soc`and
`port_signals_soc2pad`, the inout wire signals for the instantiated IO cell
landing pad signals (which you will probably want to route to the toplevel
interface of your chip) and a configuration interface so the SoC can change the
padframe configuration at runtime.

.. note::

   At the moment, the only supported configuration interface protocol is the
   lightweight `Register Interface Protocol
   <https://github.com/pulp-platform/register_interface>`_. The linked github
   repository contains easy to use protocol converters to various other
   protocols like AXI, AXI-lite or APB. In the near future, Padricks `generate
   rtl` will command will provide a flag to directly embed the required protocol
   converters within the generated module exposing the protocol of your liking
   to the toplevel.

Next Steps
----------

You now should be a bit more familiar what Padrick is, what it can do for you
and how to run it. In order to actually use it, you need to get familiar with
the details of the configuration file syntax and the available CLI commands. We
suggest you to proceed as follows:

* Read the chapter about the :ref:`Configuration File Format<chapter_padframe_config_file>`.
* Check the `examples` folder and have a look at the sample configuration files.
  They showcase various of Padricks capabilites.
* Read the chapter :ref:`Generated Hardware Overview and
  Integration<hw_overview_and_integration>` to get a better understanding of the
  RTL that padrick generates and how to integrate it in your SoC project.
* Have a look at the RTL that padrick generates from these examples to better
  understand the structure of the generated pad multiplexer
* Check the options available with the various CLI commands (either :ref:`online
  <chapter_cli_reference>` or directly in your terminal with the `-h` option).
* If you are unsure how to specify a certain aspect of your padframe or if you
  think that there must be a more efficient way to specify it, have a look at
  the :ref:`Configuration Cookbook Chapter <chapter_config_cookbook>` for tipps
  and tricks on how to specify various common pad multiplexing strategies.
* Once you have your configuration ready, have a look at the generated source code.
* In case something is unclear, state your question on `Github Discussions Forum
  <https://github.com/pulp-platform/padrick/discussions>`_
* If you find a bug or want to request file an `issue
  <https://github.com/pulp-platform/padrick/issues>`_ or if you already have a
  solution, file a `pull-request
  <https://github.com/pulp-platform/padrick/pulls>`_.
