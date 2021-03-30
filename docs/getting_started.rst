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

  pip install git+ssh://git@iis-git.ee.ethz.ch/utilities/padrick.git

Or if you prefer https over ssh::

  pip install git+https://iis-git.ee.ethz.ch/utilities/padrick

If you plan to modify or frequently update padrick you might want to install it
with the pip editable flag so changes to the source code of padrick take effect
immediately to all Python environments were you installed padrick::

  git clone https://iis-git.ee.ethz.ch/utilities/padrick
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

