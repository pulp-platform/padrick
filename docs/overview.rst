=======================================================
Padrick - A flexible Pad Multiplexer Generator for SoCs
=======================================================

.. warning::

   Padrick is still in it's very early stage of development and might still
   experience refactoring and breaking changes in the future. Also, while we do
   our best to test and verify the padrick generated IPs and have successfully
   used it in actual silicon tapeouts we do not provide any guarantees for the
   correctness of the generated RTL. You should always verify the generated IP
   yourself.


Modern SoCs contain a large number of peripherals and functional blocks that
need to communicate with the outside world. Most of the time, the number of IO
pins required to map every IO facing port of the whole SoC to dedicated IO
pads is infeasible due to limited available area dedicated for IO pads.
Instead, most modern SoCs use multiplexing logic to use a single IO pad for
several different functionalities according to some user-programmable
configuration register. While some SoCs (e.g. Nordic nRF52 series  of BLE
chips) allow mapping of every module port (e.g. SPI MOSI signal) to every
available IO pad in a full crossbar fashion, traditionally the PULP chips
taped out so far only used the approach to assign 2-3 Module ports to one
dedicated IO pad. I.e. the user can chose to use e.g. IO Pad 43 as either
GPIO4 or I2C_SCK but the SPI_MOSI signal for example cannot be routed to IO
Pad 43. While the full-crossbar like approach can have its demerits (e.g.
routing can become trickier if very fast IO signals are involfed), the
full-crossbar routing approach makes the resulting SoC way more flexible for
dynamic adaptation to the workload and simplifies a lot the PCB design process
and repurposing of existing PCBs by means of rerouting the IO signals.

Since the padframe is always a custom tailored component for one particular
SoCs, a lot of time has been spent in the past writing this padframe
multiplexing and routing logic. This design process is very labouruos and
extremely error prone which is where Padrick enters the stage;

Padrick is command line tool written in Pyhton3 aims to solve the problem of
painstakingly writing the multiplexing logic and interconnection logic for
padframes by hand. Not only does it (optionally) allow full-crossbar like
routing of every periphery port to every IO pad it also generates C-drivers
and Documentation to interact with the auto-generated IP.

How does it work? The user provides a YAML description of the desired Padrame
configuration. The configuration file's syntax is tailored in a way such that
large portions of it can be copy pasted or even entirely reused from one SoC
to the other while only minor modifications of e.g. the involved IO pads need
to be performed. After parsing and internaly validating the configuration file
with a couple of sanity checks, Padrick generates several SystemVerilog
modules that instantiate the desired IO Pads, implements the IO Multiplexing
logic and exposes the SoC facing IO signal and either an AXI-lite or APB
interface to be attached to the SoC configuration bus for at-runtime control
over the IO Pads.

