.. _chapter_padframe_config_file:

===========================
Padframe Configuration File
===========================

In the getting started guide you got a first grasp on how to use Padrick and
already saw a brief example of a configuration file that tells padrick what to
generate. In this chapter, we will deep dive into the configuration file syntax.
After you familiarized yourself with the basic Padrick config structure, have a
look at the `exhaustive syntax reference <Syntax Reference_>`_.

Concepts and Terminology
========================

The basic idea behind padricks configuration file structure is to separate the
specification into three different parts:

- A technology dependent section that defines the IO cells and its configuration signals
- An IO peripheral dependent section that defines the peripheral signals present in this SoC
- A chip specific mapping that glues the above two domains together

This separation of concerns allows to easily port an existing SoC to a new
technology by only adapting the technology dependent configuration file section.
Similarly, reusing same peripherals in a new SoC with different numbers of pads
and multiplexing scheme but same target technology just requires a change of the
mapping sections while the technology specific section and parts of the IO
peripheral section can be reused.

To better understand the remaining parts of this chapter, lets first start with
some terminology:

Pad:
  RTL instance of an IO pad. Each Pad instance will typically have several
  pad signals to control the funcionality of the TX Buffer, driving strength and
  the actual pad -> SoC and SoC -> pad signals.

Port:
  Throughout this document and in the scope of padrick, a Port denotes a
  set of signals from an SoC peripheral that can be routed to *one* of the
  available pads within the same Pad Domain. E.g. an I2C peripheral would expose
  the I2C_SCL and I2C_SDA port. The Port I2C_SDA for example could consist of
  the *Port signals* sda_tx, sda_rx and out_enable which all correspond (through
  some logic mapping) to the pad signals of a single IO pad.


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



Pad Domains
-----------

A Pad Domain incorporates a collection of IO Pads, corresponding configuration
registers and multiplexing logic. Pad Domains do not interact with each other
and are generated in individual RTL modules for simplified Power Intent
description (i.e. Power Gating of High-performance IO pads).

Pad Domains also define the scope of IO signal to IO pad routing. Every
pad_domain contains its own crossbar that by **default** allows mapping of every
*Port* to every *Pad* within the same pad domain. In combination with the
possibility to define staticly controlled pads (pads that are controlled by one
set of external signals only) this approach allows to map any existing PULP SoC
padframe multiplexing scheme and much more advanced ones to the configuration
file. While for many SoCs a single pad domain might be enough, multiple pad
domains are most usefull for chips where IO pads are partially power gated. The
clear separtion between pad domains makes it very easy to specify the power
intent for such power gating schemes.

Each pad_domain in the configuration file contains 3 entries:
- A list of pad_types (technology specific)
- A list of pad_instances (technology agnostic but chip specific)
- A list of Port Groups (technology and chip agnostic)

Declaration of IO Cells (Pad Types)
...................................

A Pad Type defines an available pad cell from your IO cell library that your are
going to use in your design. One design might use several differ IO pad cells
e.g. low-power ones and high-speed pads, pads with integrated pull-down or pads
dedicated for differential signalling. Each ``pad_type`` is characterized by
it's ``name`` and optional ``description`` key and most importantly the
``template`` key:

.. code-block:: yaml

     pad_types: # This section contains a list of pads
     - name: pull_down_pad # user defined name of the pad. Used to reference it
                           # in the pad_list
       description: TSCM65 pad with controllable integrated 1kOhm pull down resistor
       # The template value is a Mako template (https://www.makotemplates.org/)
       # that specifies how to instantiate this partuclar pad. The '|' in the
       # beginning is YAML syntax to allow multiline strings without the need
       # for manual character escaping
       template: |
         PDDW04808 ${instance_name} (
         .PAD(${conn["pad"]}),
         .IE(${conn["enable_rx"]}),
         .DS(${conn["driving_strength"]}),
         .I(${conn["chip2pad"]}),
         .O(${conn["pad2chip"]})
         );
       pad_signals:
         .... # See below for example

The Instantiation Template
,,,,,,,,,,,,,,,,,,,,,,,,,,

The template is a multiline string that describes how this particular pad shall
be instantiated within the autogenerated RTL in the form of a *Mako* template.
While most of the string will probably be just a single SystemVerilog Module
instantiation it also contains special markers that the *Mako* template library
will replace with the appropriate content. The syntax of these template markers
is quite simple if you are already familiar with Python. Check the quickstart
guide on their webpage for more information `<https://www.makotemplates.org>`_.
For the sake of understanding the above examples it suffices to know that
``${...}`` is special Mako syntax to mark a python expression. When rendering a
Mako template, the template render function is supplied with some user variables
which are then available in the scope of such expression markers. The template
render function will evaluate the python expression and replace the marker with
the expressions value during template. 

During instantiation of the pads, padrick renders each template by supplying it
with two python variables that can be referenced within the Mako markers:

``instance_name``:
  A string containing the instance name that should be used for
  this particular instantiation of the Pad Type.
``conn``:
  A dictionary containing the wiring signals corresponding to the
  declared Pad Signals for this Pad Type that should be connected to this IO Pad
  during instantiation. E.g. when rendering the instantiation of IO pad
  "pad_gpio3", ${conn[enable_rx]} will be replaced with something like
  ``s_pad_gpio3_rx_en`` which is an autogenerated internal SystemVerilog wiring
  signal.

The ``conn`` variable is used to connect the wiring signals to your IO pad
during instantiation. You can define arbitraring IO cell wiring signals in the
``pad_signals`` section of your ``pad_type`` configuration (see next section).

Pad Signals
,,,,,,,,,,,

Padrick must not only know how to instantiate your pads, it must also be aware
of all pad config signals like tx buffer enable, driving strenths, i/o signal,
landing pads etc. Padrick does not contain a list of hardcoded IO config signals
but leaves full control to the user.

Each pad_type has a set of associated pad signals that are required to control
the pad. For a typical IO pad, there are at least three signals:

- The signal connecting to the pads TX-buffer (SoC -> pad signal)
- The signal connecting to the pads RX-buffer (pad -> SoC signal)
- The pad signal itself which connectes to the toplevel of the RTL and is wired
  to the bonding pads/bumps of the chip. In addition to these signals there are most
  often numerous additional signals that control additional features of the pad
  like driving strength, optional schmidt-triggers etc.

Here is a (well documented) example of a ``pad_signals`` section for a very rudimentary IO pad:

.. code-block:: YAML

       pad_signals: &default_pad_signals #This is a YAML anchor to reuse a subblock somewhere else. Use it to avoid copy paste hell!
       # The pad signals section specifies a list of all pad signald used in
       # this particular pad_domain. This include the rx signal, tx signal, the
       # actual pad signal as well as all pad configuration signals. These are
       # the signals that can be referenced by name in the pad instantiation
       # templates within the pad_types sections, the connections of each pad
       # within the pad_list as well as the connections section in the
       # port_list.
         - name: output_en
           description: "Enables the output driver of the pad" #optional description
                                                        #of the signal
           size: 1 # The number of bits
           kind: input # The signal is an input signal to the pad i.e. a signal
                       # driven by the chip that controls the pad.
           conn_type: dynamic # This means, the signal value is dynamic. It can
                              # either be controlled by an autogenerated
                              # configuration register or (at runtime
                              # configurable) an IO signal (if any IO signal
                              # within the pad_domain is referencing it).
           and_override_signal: s_enable_all_outputs # Optional override signal
                                                     # that is and-gated with
                                                     # the control signal
           default_reset_value: 0 # The default reset value of the pad signal
                                  # if not overriden in the "connections"
                                  # section of a particular pad instance
         - name: driving_strength
           description: "Driving strength of the output driver"
           size: 3
           kind: input
           conn_type: static # This means, the signal has a static value that
                             # is either driven by a single signal or a
                             # constant value. The difference between the
                             # dynamic type is, that this pad_signal is not
                             # arbitrary connectable with IO signals in a
                             # crossbar fashion but tied to one dedicated
                             # signal only. The actual signal or value assigned
                             # is defined individually for each pad in the
                             # padlist or described globally with the
                             # default_static_value.
           default_static_value: 0 # The default static value of the signal if
                                   # not overriden in the "connections" section
                                   # of a particular pad instance
         - name: enable_rx
           description: "Input buffer enable"
           size: 1
           kind: input
           conn_type: dynamic
           default_reset_value: 1
         - name: pad2chip
           description: "The signal that connects to the pads RX buffer"
           size: 1
           kind: output
           conn_type: dynamic # In case of static output pad_signals, literal
                              # value assignments are illegal since the signal
                              # is not drivable from the outside. Only the name
                              # for a dedicated padframe output signal can be
                              # specified.
         - name: chip2pad
           description: "The signal that connects to the pads TX driver"
           size: 1
           kind: input
           conn_type: dynamic
           default_reset_value: 1
         - name: pad # The name of the signal can be chosen arbitrarily but for
                     # the actual pad signal (the signal that connects to the
                     # bonding pads) the name "pad" is a good choice. It is
                     # legal to specify more than one signal of type pad (e.g.
                     # if you want to instantiate a special differential
                     # signaling pads ). However, at least one siganl of kind
                     # pad is required
           size: 1
           kind: pad # Pad signals are handled specially. They are always exposed
                     # directly to the toplevel of the generated padframe module and no
                     # connection type, override signals or default values are allowed.

Pad Signal ``kind``
^^^^^^^^^^^^^^^^^^^

Padrick does not make any assumption about the particular features
controlled by a pad signal and does not do a distinction between the actual
I and O signal or configuration signals. Padrick knows only three *kinds*
of padsignals:

``input``:
  Signals that are inputs to the pad_instance cell e.g. chip->pad
  signal or driving_strength signal
``output``:
  Signals that are outputs to the pad_instance cell. E.g.
  pad->chip signal or power_up_ack signal.
``pad``:
  Signals that correspond to a bonding pad and should be routed to
  the toplevel of the RTL. While typically an  IO pad contains only one Pad
  signal of this kind, padrick can perfectly handle pads with more than one landing pad signal
  (e.g. for differential signaling pads).

Connection Types
^^^^^^^^^^^^^^^^

The connection type of a pad_signal determines, whether this particular signal
is later-on to be controlled statically or dynamically.

Pad signals of type static do not have an input-multiplexer and thus cannot be
controlled by the routable Port signals. Instead, they are either tied to a
constant logic level (e.g. 1'b0 to tie it to zero) or a logic expression of
external signals consisting of unary or binary operators and signal identifiers.
This connection type is usefull for pad_signals you don't need to control at
runtime but should be hardwired to instance specific values or connected to
external signals. E.g. a static pad signal could be controlled
by a single external signal e.g. "~``global_power_down``" connected to RX_en and
TX_en.

For each **dynamic** pad signal, a configuration register is auto-generated for
**every pad instance**. This provides the user with control over the
signal in the default case, where no *Port* is routed to this particular pad
instance's pad_signal. Thus, pad_signals of type dynamic can be controlled by
all connectable (more on how to control connectivity in chapter `Port
Multiplexing <Port Multiplexing_>`_) ports within the same pad_domain that
referencec them. In other words; if you connect some port (e.g. ``I2C_SDA``) to
your pad instance, that port might take over control over the ``output_en`` and
``enable_rx`` pad signals. Other dynamic pad_signals like a
``schmitt_trigger_en`` are not controlled by the I2C peripheral. In such a
case (and also if no port is connected to the pad instance at all) the pad
signal is driven (for signals of ``kind: input``) or accessible (for signals of
``kind: output``) via the auto-generated config register file.

Dynamic pad_signals of kind ``input`` require you to specify a
default_reset_value for the auto generated register. If not overriden during pad
instantiation, the value you specify here will become the reset value of the
corresponding configuration register. On the other hand, static pad_signals of
kind ``input`` require you to specify a ``default_static_value``; a static
expression connected to the pad_signal if not overriden during pad
instantiation.

Pad Instance List
.................

The pad list contains a list of concrete pad instantiations. This is the place
where you actually define, how many pads there are within your design. Each pad
instance specifies a name for the pad, references the particular Pad Type to use
(you might have multiple IO cell flavors to choose from) and a *static signal
connection list*.

Here is an example:

.. code-block:: yaml

      pad_list:
        - name: pad_ref_clk # The instance name of the pad. 
          description: "32kHz reference clock" #Optional description of the pads function
          pad_type: pull_down_pad
          is_static: true # Declaring a whole pad as static overrides every single
                          # pad signal's conn_type for that particular pad
                          # instance to "static".
          connections: # A list of static pad signal connections (for static
                       # signals) or default config register values (for dynamic
                       # pad signals)
            pad2chip: ref_clk
            chip2pad: ~ #Leave unconnected, only legal for pad signals of kind
                        #"input"
            enable_rx: 1 #pad signals of kind "input" any SystemVerilog literal is
                     #valid.
            driving_strength: 0
        - name: pad_gpio
          description: "General Purpose Input and Outpud pads. These pads can be configured to connect to any peripheral pad port."
          multiple: 32 #Generate 32 instances of this pad. Each instance will have
                       #its instance name postfixed with the index
                       #number.
          pad_type: pull_down_pad
          is_static: false #False is the default value, thus explicitly specifying
                           #static as false is optional. With this option, each
                           #pad_signal assumes the declared conn_type.
        - name: pad_high_speed
          description: "High-speed IO pads for fast IO signals. "
          multiple: 10
          pad_type: high_speed_pad_gf22
          mux_group: hs_pads # An optional string that specifies a custom multiplexing
                             # group. All pads and ports within the same pad_domain
                             # and multiplexing group can be connected to each other.
                             # Default value: "all" By default all pads and ports
                             # end-up in the "all" multiplexing group and thus by
                             # default, every port can be connected to every pad
                             # within the same domain.

.. hint:: You will learn more about generating multiple pad/port instances in
   `Generating Multiple Ports/Pads with Regular Structure <Generating Multiple
   Ports/Pads with Regular Structure_>`_.

Static Signal Connections and Config Register Reset Values
,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

For each pad instance, the user can supply a ``connections`` list entry that
overrides how static pad signals of this particular pad instance are to be
connected or what the reset value of the corresponding configuration register
shall be. The ``connections`` field contains a mapping of *Pad Signal names* to
*expressions*. The pad signal name is just a reference to a **static** or
**dynamic** pad_signal declared for the chosen pad type. The expression on the
other hand must be a simplified subset of a SystemVerilog expression.

Expression may consist of simple SystemVerilog literals (e.g. ``45``, ``8'h0a``, ``'0``
etc.), unary and binary operators and signal identifiers without subscripting
(e.g. ``out_en_i`` is legal, ``out_en[45]`` *is not legal*).

*For pad_signals of kind ~output~ only single signal identifiers or the empty
expression are allowed. After all, an output signal cannot be connected to an
expression.*

*For dynamic pad_signals only constant expressions are allowed since this value
is used as the reset value when asynchronously resetting the auto-generated
register file.*

The pad instance will be wired with the supplied expression and the generated
pad_frame SystemVerilog module will expose each static signal used within any of
the expressions within the pad_domain in its port_list for the user to connect
these signal with the appropriate SoC logic. E.g.:

.. code-block:: yaml

   ...
     connections:
       pad2chip: scan_en_i
       chip2pad: ~ # '~' is YAML syntax for 'None'. In this context it means leave
                   # the signal unconnected, only legal for pad signals of kind
                   # "input"
       enable_rx: 1 #pad signals of kind "input" any SystemVerilog literal is
                    #valid.
       enable_tx: ~test_en_i & gpio1_en_rx
   ...

This will cause the pad_frame to expose the signals ``scan_en_i``, ``test_en_i`` and
``gpio1_en_rx``.

The direction and size of each of those static signals is inferred from the size
and directionality defined for the particular pad_signal they are connecting to.
If a static signal (signal identifiers on the right-hand-side of the connections
list) is used in expressions for multiple pad_signals with different sizes an
error is issued since size inference would be ambiguous.

Static signal identifiers with identical name within the same pad_domain denote
the same signals. Thus if you have several pad instances whith connections
entries like:

.. code-block:: yaml

   connections:
     enable_rx: input_buffers_en_i

They will all be connected to the same input signal ``input_buffers_en_i``.

Ports and Port Groups
.....................

*Port groups* provide logical grouping of *ports* and *peripheral signals* which
are muxed on you pad instances. Peripheral signals are the signals your IO
facing peripheral exposes (e.g. ``i2c_sda_tx_en`` or ``uart_rx``). *Ports* on
the other hand are roles assigned to an IO pad when muxed to it. A *port* might
make have to make use of multiple peripheral signals when it is connected to a
pad. E.g. when connecting an I2C ``sda`` port to some particular pad, you need
not only to connect the ``i2c_sda`` signal to the pad but also some
``i2c_sda_tx_en`` to control the pads directionality. The **ports** within a
port group thus need to specify a logical mapping between peripheral signals and the
**pad signals** defined in the ``pad_types`` section.

.. hint:: Static pads define their connected signals directly, see `<Static Signal Connections and Config Register Reset Values_>`_

A concrete example should make things clearer. Here we define a port group for an I2C peripheral which consists of two ports (SDA and SCL):

.. code-block:: yaml

   port_groups:
     - name: i2c_0
       mux_groups: [all] # You will learn about mux_groups in the next section.
       output_defaults: 1'b0
       ports:
         - name: i2c_scl
           description: "Bidirectional I2C clock signal"
           connections:
             chip2pad: scl_out
             scl_in: pad2chip
             enable_tx: ~oen & i2c_en #You can use verilog expression combining multiple peripheral signals in your connections
             enable_rx: oen & i2c_en
     
         - name: i2c_sda
           description: "Bidirection I2C data signal"
           connections:
             chip2pad: sda_out
             sda_in: pad2chip
             pull_up_en: 1'b1 # You can also use literals if e.g. I2C pad requires pull-ups to beautomatically enabled if I2C_SDA is connected to a pad.
             enable_tx: ~oen & i2c_en #You can use verilog expression combining multiple peripheral signals in your connections
             enable_rx: oen & i2c_en

Each ``port_group`` must be defined with a ``name``, some optional
``description`` and a list of ports (we will elaborate more on the
``mux_groups`` key in chapter `Port Multiplexing <Port Multiplexing_>`_). Each
port again is defined with a name and optional description and a ``connections``
block. The connections block tells padrick how to connect the peripheral signals
to the target pad when the user configures the port to be connected to a
particular pad (muxing configuration registers). The individual connections can
be read like assignments i.e. the signal on the left-hand-side is assigned the
value of the expression on the right-hand-side. The identifiers used are either
``pad_signal`` names or *implicitly* defined peripheral signals.

Considering the example I2C port group above. Let's assume connected (by writing
to the auto-generated config register) the ``i2c_scl`` port to some pad
``mypad_08`` whose pad instance uses the same ``pad_signals`` as defined in our
earlier example. In that case the connection block instructs padrick to connect
mypad_08's ``chip2pad`` signal to the ``scl_out`` peripheral signal. The IO pads
``pad2chip`` drives the peripheral signal ``scl_in``. The ``enable_tx``
pad_signal is driven with a logic expression that consists of the two peripheral
signals ``oen`` (an active low output-enable) and ``i2c_en`` (some global
peripheral enable signal). The right hand side of a port connection can also be
a literal e.g. if certain pad configuration signals should be tied to constant
values when the peripheral is connected to the pad (e.g. ``enable_tx: 1'b0`` if
a port is always an output as would be the case for ``uart_rx``).

.. important:: Note that we didn't explicitly define our *peripheral signals*
   anywhere. Merely specifying a signal name in the connections block of a port
   implicitly defines the peripheral signal and causes padrick to generate the
   necessary module ports and muxing logic in the generated pad multiplexer.
   *The scope of the implicitly defined peripheral signals is the whole port
   group.* Thus in our above example, the ``enable_rx`` signals used in the
   ports ``i2c_scl`` and ``i2c_sda`` reference the exact same signal. Therefore,
   peripheral signals may be shared amongst ports within the same port group.

From the example before it should have become clear, that your peripheral can
control any pad signal you defined for your ``pad_type``. If you're peripheral
needs to control driving strenghts, schmidt-triggers or whatever control signal
your IO library exposes this is all possible. The more interesting question is
however, what happens with the pad signals that you're *port* does **not** use?
E.g. we didn't specify a connection for the ``driving_strenght`` signal. What
driving strenght is used when our ``mypad_08`` is used as ``i2c_scl`` port? The
answer is pretty simple:

.. important:: Every (dynamic) ``pad_signal`` that is not mentioned in your
               *port's* connection block will be controlled by an auto-generated
               pad configuration register whose reset value is specifed in the
               pad instance's ``connection`` block (see `<Static Signal
               Connections and Config Register Reset Values_>`_). E.g. since we
               did not specify any connection for the ``driving_strength``
               signal, the driving strenght of ``mypad_08`` will remain
               controlled by ``mypad_08``'s pad configuration registers.

Generating Multiple Ports/Pads with Regular Structure
=====================================================

Generating pad instances or ports of a regular structure can become quite
verbose if every instance is explicitly described in the YAML config file.
Therefore, Padrick contains a feature for templated vectorization of **pad
instances**, **port_groups** and **ports**. Each of these entities accepts the
optional ``multiple`` key to instruct Padrick to generate multiple copies of the
entity. During vector expansion, padrick looks for special text markers containing a
mini expression language to generate the names, descriptions etc. of the
vectorized entity. An example should make the explanation much easier:

.. code-block:: yaml

   pad_list:
     - name: gpio{i:2d}
       description: "GPIO No {i}"
       is_static: false
       pad_type: high_speed_pad_gf22
       multiple: 32

While parsing the config file, padrick will expand this vectorized pad_instance
to 32 copies. Padrick will replace the name of each pad with ``gpio00``,
``gpio01`` until ``gpio31``. The description is handled similarly.


Mini Expression language
........................


During expansion of the vectorized entity, padrick scans ``name``,
``description``, ``mux_groups``, ``connections`` etc. for occurence of mini
expressions (e.g. ``{i:2d}``).

Each mini expression has the following format:

``{<expression>:<format>}`` or ``{<expression>}`` (if you want to use the default format ``d``)

``expression`` can be any expression consisting of:

* the binary operators '+', '-', '*' (multiply), '/' (integer divide), '%' (modulo)
* the unary operators '+', '-'
* braces '()' to indicate associativity
* integer literals
* the loop variable ``i`` (a variable that starts counting from 0 during vector expansion and increments by one for every instance copy).

E.g.

.. code-block:: yaml
   name: gpio{i/2}_{i%2+1}
   multiple: 4

Will be expaned to ``gpio0_1``, ``gpio0_2``, ``gpio1_1`` and ``gpio1_2``.

The format specifier consists of ``[<lenght>]<format_class>``.

Format Class ``d``:
  Format result of the expression in decimal representation. The optional ``length`` specifies the amount of **zero padding**.

Format Class ``o``:
  Same as ``d`` but format expression in octal representation.

Format Class ``b``:
  Same as ``d`` but format expression in binary representation.

Format Class ``x``:
  Same as ``d`` but format expression in hexa decimal representation.

Format Class ``c``:
  Format expression in Base26 and map the individual 'digits' to the lowercase letters of the latin alphabet.
  Supplying the optional ``length`` forces padding with the letter `a`.
  E.g. ``pad_{i:c}`` will be mapped to ``pad_a``, ``pad_b``, ``pad_c``, ..., ``pad_aa``, ``pad_ab``, ``pad_ac`` and so forth.
  E.g. ``pad_{i:2c}`` will be mapped to ``pad_aa``, ``pad_ab``, ``pad_ac`` etc.

Format Class ``C``:
  Same as ``c`` but use upper-case letters.

Here is another example:

.. code-block:: yaml

   name: pad_{i/4:C}{i%4:2d}

Expands to ``pad_a00``, ``pad_a01``, ``pad_a02``, ``pad_a03``, ``pad_b00``, ``pad_b01`` etc.

.. hint:: You can use the padrick command ``padrick config <your_padrame.yml>``
           to parse the config file and print it in expanded form. This will
           resolve all cross links in your config file (e.g. references to
           ``pad_types``) and will expand all vectorized ``port``,
           ``pad_instance`` etc. This is quite helpfull to debug how padrick is treating your vectorized config files.

Port Multiplexing
=================

By default, Padrick allows routing any *Port* to any (non-static) *Pad
Instance*. However, the degree of routability can be adjusted very finely.
Padrick uses so called *mux groups* to configure the connectivity between ports
and pad instances. Every pad instance and every port is a member of *one or
several* mux groups. Ports can be dynamically connected to all pad instances
which are contained in any of the port's mux groups. I.e. ``port_xy`` can be
connected to ``pad_123`` if ``pad_123`` is part of one (or multiple) of
``port_xy``'s mux groups.
In more mathematical terms; Each pad_instance and each port specify a set of
labels (mux_groups), whenever there is set-intersection between a pad_instance
and a port, they can be connected with each other.

A mux group is denoted by a simple string identifier and declared with the
`mux_groups` key in the config file. E.g. the following config snippet declares
a pad called ``my_pad`` that is member of the mux_groups ``mux1``, ``my_pads``,
and ``all``:

.. code-block:: yaml

   pad_list:
     - name: my_pad
       mux_groups: # some examples use the more compact notation [mux1 my_pads self]. Both styles are valid YAML lists.
         - mux1
         - my_pads
         - all
       connections:
         ...


Similar to *peripheral signals* or *static connection signals* you don't have to
explicitly declare *mux groups*. The first usage of an identifier creates the
new mux group. You can use any C-identifier-like string as the mux group name.

You probably noticed, that our previous config example snippets most of the time did not specify
the ``mux_groups`` key. The key is optional and has the default value ``[all]``.
I.e. by default, all ports and all pads are member of a mux group called
``all``. If you followed our explanation so far you should realize now, why by
default, all ports can be connected to all pads with this default value.

Apart from ports and pad instances, mux_groups can also be applied to a complete
port group. In that case the declared mux_group acts as a default for any port
within the port group that doesn't explicitly specify its own port group.

Lets have a look at small example with a couple of pads and a couple of ports:

.. code-block:: yaml

   pad_list:
     - name: pad1
       mux_groups: [mx1]
       ...
     - name: pad2
       mux_groups: [mx1, mx2]
       ...
     - name: pad3
       mux_groups: [mx2]

   port_groups:
     - name: spi
       mux_groups: [mx1]
       ports:
         - name: sck
           mux_groups: [mx2]
           ...
         - name: mosi
           mux_groups: [mx1, mx2]
           ...
         - name: miso
           ... # No mux_groups specified for mosi thus the port_group's default (mx1) applies

In this small example, we used 2 different mux groups called ``mx1`` and
``mx2``. We have the following connectivity for the 3 ports:

* Port ``sck`` can be connected to ``pad2`` and ``pad3`` since both are member of the ``mx2``  group.
* Port ``mosi`` can be connected to all three pads since all pads are member of either ``mx1`` or ``mx2``.
* Port ``miso`` does not specify a mux group, thus the default value of the *mux group* applies (if the mux group doesn't specify one, ``[all]`` is used). Therefore, ``miso`` can be routed to either ``pad1`` or ``pad2``.

Mux Group Templating
....................

Combining this chapter with the knowledge from `mini expression language <Mini
Expression language>`_ we now have all the ingredients to define more complex
IO multiplexing schemes. The key realization is, that mux_groups can be templated using the
mini expression language like we templated the port/pad instance names and
descriptions in the examples on `<Generating Multiple Ports/Pads with Regular
Structure_>`_.

Lets consider the following example:

.. code-block:: yaml

   ...
   pad_list:
     - name: hs_pad{i}
       multiple: 4
       pad_type: highspeed_pad
       mux_groups: [hs_pads, hs_pad{i}]
       ...
     - name: ls_pad{i}
       multiple: 4
       pad_type: lowspeed_pad
       mux_groups: [ls_pads, ls_pad{i}]
       ...

   port_groups:
     - name: hs_gpio
       ports:
         - name: gpio{i}
           multiple: 4
           mux_groups: [hs_pad{i}]
     - name: ls_gpio
       ports:
         - name: gpio{i}
           multiple: 4
           mux_groups: [ls_pad{i}]
     - name: i2c
       mux_groups: [ls_pads]
       ports:
         ...
     - name: hyerflash
       mux_groups: [hs_pads]
       ports:
         ...

In this example, we have instantiate 4 highspeed (hs) and 4 low speed (ls)
pads. After vector expansion the pad ``hs_pad0``, will be member of the
mux_group ``hs_pads`` and ``hs_pad0``, the pad ``hs_pad1`` will be member of
mux groups ``hs_pads`` and ``hs_pad1`` and so forth.

On the port side, we declare a low-speed gpio port group, a high speed gpio
port group, an i2c port group and a hyperflash port group.

Since the individual ports of a GPIO peripheral are usually all identical, it
doesn't make much sense to waste the routing resources to allow routing e.g.
``GPIO0`` to ``pad4``, you just use ``GPIO4`` instead. To allow for such a
routing scenario, each port in the ``hs_gpios`` port group is member of the
corresponding pad's mux group. E.g. port ``gpio0`` of the ``hs_gpio`` port group
is member of the ``hs_pad0`` mux group, port ``gpio1`` is member of ``hs_pad1``
and so forth. This results in the intended scenario. Since the i2c port group
specifies the default mux group ``ls_pads``, every port within ``i2c`` can be
routed to any of the 4 low-speed pads, while any port of the hyperflash
peripheral can be routed to any of the high_speed pads.

..
   Syntax Reference
   ================

   Data Types
   ----------

   String
     An arbitrary string literal


   Identifier
     Any string that would pass as a legal SystemVerilog signal/module identifier.


   Signal Expression
     A string consisting of a combination of:
     - SystemVerilog logic literals (e.g. ``8'h1f``)
     - Any SystemVerilog binary or unary operator
     - `Identifiers`
     - Braces ('(' and ')') to indicate associativiy.

   Mini Expression
     A string consisting of the form ``{<expression>:<format>}``. (See `<Mini Expression language_>`_ for reference)

   Number
     Any legal YAML number


   Config File Structure
   ---------------------

   Root level keys
   ...............

   ``pad_domain``
   .............
   ``name``: required, ``string``



Config File Schema
==================

The following table contains an auto-generated schema reference of the
configuration file format.

.. pydantic:: padrick.Model.Padframe.Padframe
