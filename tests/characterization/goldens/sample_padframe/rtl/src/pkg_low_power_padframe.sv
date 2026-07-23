
package pkg_low_power_padframe;

  //Structs for always_on_pads

  //Override signals
  typedef struct packed {
     logic  s_enable_all_outputs;
  } pad_domain_always_on_pads_override_signals_t;

  //Static connections signals
   typedef struct packed {
      logic        ref_clk;
     } pad_domain_always_on_pads_static_connection_signals_pad2soc_t;

  // Port Group signals
   typedef struct packed {
      logic        csn;
      logic        mosi;
      logic        oen;
      logic        sck;
      logic        spi_en;
     } pad_domain_always_on_pads_port_group_spi_soc2pad_t;

   typedef struct packed {
      logic        miso;
     } pad_domain_always_on_pads_port_group_spi_pad2soc_t;

   typedef struct packed {
      logic        out_en;
      logic        scl;
      logic        sda_o;
     } pad_domain_always_on_pads_port_group_i2c_soc2pad_t;

   typedef struct packed {
      logic        sda_i;
     } pad_domain_always_on_pads_port_group_i2c_pad2soc_t;

   typedef struct packed {
      logic        dir0_i;
      logic        dir1_i;
      logic        dir2_i;
      logic        dir3_i;
      logic        dir4_i;
      logic        dir5_i;
      logic        dir6_i;
      logic        dir7_i;
      logic        dir8_i;
      logic        dir9_i;
      logic        dir10_i;
      logic        dir11_i;
      logic        dir12_i;
      logic        dir13_i;
      logic        dir14_i;
      logic        dir15_i;
      logic        dir16_i;
      logic        dir17_i;
      logic        dir18_i;
      logic        dir19_i;
      logic        dir20_i;
      logic        dir21_i;
      logic        dir22_i;
      logic        dir23_i;
      logic        dir24_i;
      logic        dir25_i;
      logic        dir26_i;
      logic        dir27_i;
      logic        dir28_i;
      logic        dir29_i;
      logic        dir30_i;
      logic        dir31_i;
      logic        gpio0_i;
      logic        gpio1_i;
      logic        gpio2_i;
      logic        gpio3_i;
      logic        gpio4_i;
      logic        gpio5_i;
      logic        gpio6_i;
      logic        gpio7_i;
      logic        gpio8_i;
      logic        gpio9_i;
      logic        gpio10_i;
      logic        gpio11_i;
      logic        gpio12_i;
      logic        gpio13_i;
      logic        gpio14_i;
      logic        gpio15_i;
      logic        gpio16_i;
      logic        gpio17_i;
      logic        gpio18_i;
      logic        gpio19_i;
      logic        gpio20_i;
      logic        gpio21_i;
      logic        gpio22_i;
      logic        gpio23_i;
      logic        gpio24_i;
      logic        gpio25_i;
      logic        gpio26_i;
      logic        gpio27_i;
      logic        gpio28_i;
      logic        gpio29_i;
      logic        gpio30_i;
      logic        gpio31_i;
     } pad_domain_always_on_pads_port_group_gpio_a_soc2pad_t;

   typedef struct packed {
      logic        gpio0_o;
      logic        gpio1_o;
      logic        gpio2_o;
      logic        gpio3_o;
      logic        gpio4_o;
      logic        gpio5_o;
      logic        gpio6_o;
      logic        gpio7_o;
      logic        gpio8_o;
      logic        gpio9_o;
      logic        gpio10_o;
      logic        gpio11_o;
      logic        gpio12_o;
      logic        gpio13_o;
      logic        gpio14_o;
      logic        gpio15_o;
      logic        gpio16_o;
      logic        gpio17_o;
      logic        gpio18_o;
      logic        gpio19_o;
      logic        gpio20_o;
      logic        gpio21_o;
      logic        gpio22_o;
      logic        gpio23_o;
      logic        gpio24_o;
      logic        gpio25_o;
      logic        gpio26_o;
      logic        gpio27_o;
      logic        gpio28_o;
      logic        gpio29_o;
      logic        gpio30_o;
      logic        gpio31_o;
     } pad_domain_always_on_pads_port_group_gpio_a_pad2soc_t;

   typedef struct packed {
      logic        dir0_i;
      logic        dir1_i;
      logic        dir2_i;
      logic        dir3_i;
      logic        dir4_i;
      logic        dir5_i;
      logic        dir6_i;
      logic        dir7_i;
      logic        dir8_i;
      logic        dir9_i;
      logic        dir10_i;
      logic        dir11_i;
      logic        dir12_i;
      logic        dir13_i;
      logic        dir14_i;
      logic        dir15_i;
      logic        gpio0_i;
      logic        gpio1_i;
      logic        gpio2_i;
      logic        gpio3_i;
      logic        gpio4_i;
      logic        gpio5_i;
      logic        gpio6_i;
      logic        gpio7_i;
      logic        gpio8_i;
      logic        gpio9_i;
      logic        gpio10_i;
      logic        gpio11_i;
      logic        gpio12_i;
      logic        gpio13_i;
      logic        gpio14_i;
      logic        gpio15_i;
     } pad_domain_always_on_pads_port_group_gpio_c_soc2pad_t;

   typedef struct packed {
      logic        gpio0_o;
      logic        gpio1_o;
      logic        gpio2_o;
      logic        gpio3_o;
      logic        gpio4_o;
      logic        gpio5_o;
      logic        gpio6_o;
      logic        gpio7_o;
      logic        gpio8_o;
      logic        gpio9_o;
      logic        gpio10_o;
      logic        gpio11_o;
      logic        gpio12_o;
      logic        gpio13_o;
      logic        gpio14_o;
      logic        gpio15_o;
     } pad_domain_always_on_pads_port_group_gpio_c_pad2soc_t;

   typedef struct packed {
     pad_domain_always_on_pads_port_group_spi_soc2pad_t spi;
     pad_domain_always_on_pads_port_group_i2c_soc2pad_t i2c;
     pad_domain_always_on_pads_port_group_gpio_a_soc2pad_t gpio_a;
     pad_domain_always_on_pads_port_group_gpio_c_soc2pad_t gpio_c;
     } pad_domain_always_on_pads_ports_soc2pad_t;

   typedef struct packed {
     pad_domain_always_on_pads_port_group_spi_pad2soc_t spi;
     pad_domain_always_on_pads_port_group_i2c_pad2soc_t i2c;
     pad_domain_always_on_pads_port_group_gpio_a_pad2soc_t gpio_a;
     pad_domain_always_on_pads_port_group_gpio_c_pad2soc_t gpio_c;
     } pad_domain_always_on_pads_ports_pad2soc_t;


  //Toplevel structs

  typedef struct packed{
    pad_domain_always_on_pads_override_signals_t always_on_pads;
  } override_signals_t;

  typedef struct packed {
    pad_domain_always_on_pads_static_connection_signals_pad2soc_t always_on_pads;
  } static_connection_signals_pad2soc_t;

  typedef struct packed {
    pad_domain_always_on_pads_ports_pad2soc_t always_on_pads;
  } port_signals_pad2soc_t;

  typedef struct packed {
    pad_domain_always_on_pads_ports_soc2pad_t always_on_pads;
  } port_signals_soc2pad_t;


endpackage : pkg_low_power_padframe
