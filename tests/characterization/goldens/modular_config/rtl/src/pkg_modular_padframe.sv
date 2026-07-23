
package pkg_modular_padframe;

  //Structs for domain

  //Static connections signals
   typedef struct packed {
      logic        jtag_tdo;
     } pad_domain_domain_static_connection_signals_soc2pad_t;

   typedef struct packed {
      logic        clk_byp;
      logic        debug_mode_en;
      logic        jtag_tck;
      logic        jtag_tdi;
      logic        jtag_tms;
      logic        jtag_trst;
      logic        ref_clk;
      logic        rst_n;
     } pad_domain_domain_static_connection_signals_pad2soc_t;

  // Port Group signals
   typedef struct packed {
      logic        gpio00_out;
      logic        gpio00_tx_en;
      logic        gpio01_out;
      logic        gpio01_tx_en;
      logic        gpio02_out;
      logic        gpio02_tx_en;
      logic        gpio03_out;
      logic        gpio03_tx_en;
      logic        gpio04_out;
      logic        gpio04_tx_en;
      logic        gpio05_out;
      logic        gpio05_tx_en;
      logic        gpio06_out;
      logic        gpio06_tx_en;
      logic        gpio07_out;
      logic        gpio07_tx_en;
      logic        gpio08_out;
      logic        gpio08_tx_en;
      logic        gpio09_out;
      logic        gpio09_tx_en;
      logic        gpio10_out;
      logic        gpio10_tx_en;
      logic        gpio11_out;
      logic        gpio11_tx_en;
      logic        gpio12_out;
      logic        gpio12_tx_en;
      logic        gpio13_out;
      logic        gpio13_tx_en;
      logic        gpio14_out;
      logic        gpio14_tx_en;
      logic        gpio15_out;
      logic        gpio15_tx_en;
      logic        gpio16_out;
      logic        gpio16_tx_en;
      logic        gpio17_out;
      logic        gpio17_tx_en;
      logic        gpio18_out;
      logic        gpio18_tx_en;
      logic        gpio19_out;
      logic        gpio19_tx_en;
      logic        gpio20_out;
      logic        gpio20_tx_en;
      logic        gpio21_out;
      logic        gpio21_tx_en;
      logic        gpio22_out;
      logic        gpio22_tx_en;
      logic        gpio23_out;
      logic        gpio23_tx_en;
      logic        gpio24_out;
      logic        gpio24_tx_en;
      logic        gpio25_out;
      logic        gpio25_tx_en;
      logic        gpio26_out;
      logic        gpio26_tx_en;
      logic        gpio27_out;
      logic        gpio27_tx_en;
      logic        gpio28_out;
      logic        gpio28_tx_en;
      logic        gpio29_out;
      logic        gpio29_tx_en;
      logic        gpio30_out;
      logic        gpio30_tx_en;
      logic        gpio31_out;
      logic        gpio31_tx_en;
     } pad_domain_domain_port_group_gpio_soc2pad_t;

   typedef struct packed {
      logic        gpio00_in;
      logic        gpio01_in;
      logic        gpio02_in;
      logic        gpio03_in;
      logic        gpio04_in;
      logic        gpio05_in;
      logic        gpio06_in;
      logic        gpio07_in;
      logic        gpio08_in;
      logic        gpio09_in;
      logic        gpio10_in;
      logic        gpio11_in;
      logic        gpio12_in;
      logic        gpio13_in;
      logic        gpio14_in;
      logic        gpio15_in;
      logic        gpio16_in;
      logic        gpio17_in;
      logic        gpio18_in;
      logic        gpio19_in;
      logic        gpio20_in;
      logic        gpio21_in;
      logic        gpio22_in;
      logic        gpio23_in;
      logic        gpio24_in;
      logic        gpio25_in;
      logic        gpio26_in;
      logic        gpio27_in;
      logic        gpio28_in;
      logic        gpio29_in;
      logic        gpio30_in;
      logic        gpio31_in;
     } pad_domain_domain_port_group_gpio_pad2soc_t;

   typedef struct packed {
      logic        scl_o;
      logic        scl_oe;
      logic        sda_o;
      logic        sda_oe;
     } pad_domain_domain_port_group_i2c0_soc2pad_t;

   typedef struct packed {
      logic        scl_i;
      logic        sda_i;
     } pad_domain_domain_port_group_i2c0_pad2soc_t;

   typedef struct packed {
      logic        tx_o;
     } pad_domain_domain_port_group_uart0_soc2pad_t;

   typedef struct packed {
      logic        rx_i;
     } pad_domain_domain_port_group_uart0_pad2soc_t;

   typedef struct packed {
      logic        csn0_o;
      logic        csn1_o;
      logic        csn2_o;
      logic        csn3_o;
      logic        sck_o;
      logic        sd0_o;
      logic        sd0_oe;
      logic        sd1_o;
      logic        sd1_oe;
      logic        sd2_o;
      logic        sd2_oe;
      logic        sd3_o;
      logic        sd3_oe;
     } pad_domain_domain_port_group_qspim0_soc2pad_t;

   typedef struct packed {
      logic        sd0_i;
      logic        sd1_i;
      logic        sd2_i;
      logic        sd3_i;
     } pad_domain_domain_port_group_qspim0_pad2soc_t;

   typedef struct packed {
     pad_domain_domain_port_group_gpio_soc2pad_t gpio;
     pad_domain_domain_port_group_i2c0_soc2pad_t i2c0;
     pad_domain_domain_port_group_uart0_soc2pad_t uart0;
     pad_domain_domain_port_group_qspim0_soc2pad_t qspim0;
     } pad_domain_domain_ports_soc2pad_t;

   typedef struct packed {
     pad_domain_domain_port_group_gpio_pad2soc_t gpio;
     pad_domain_domain_port_group_i2c0_pad2soc_t i2c0;
     pad_domain_domain_port_group_uart0_pad2soc_t uart0;
     pad_domain_domain_port_group_qspim0_pad2soc_t qspim0;
     } pad_domain_domain_ports_pad2soc_t;


  //Toplevel structs

  typedef struct packed {
    pad_domain_domain_static_connection_signals_pad2soc_t domain;
  } static_connection_signals_pad2soc_t;

  typedef struct packed {
    pad_domain_domain_static_connection_signals_soc2pad_t domain;
  } static_connection_signals_soc2pad_t;

  typedef struct packed {
    pad_domain_domain_ports_pad2soc_t domain;
  } port_signals_pad2soc_t;

  typedef struct packed {
    pad_domain_domain_ports_soc2pad_t domain;
  } port_signals_soc2pad_t;


endpackage : pkg_modular_padframe
