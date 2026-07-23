
package pkg_kraken_padframe;

  //Structs for aon

  //Static connections signals
   typedef struct packed {
      logic        st_hyper_ck_no;
      logic        st_hyper_ck_o;
      logic        st_hyper_cs0_no;
      logic        st_hyper_cs1_no;
      logic        st_hyper_dq0_o;
      logic        st_hyper_dq1_o;
      logic        st_hyper_dq2_o;
      logic        st_hyper_dq3_o;
      logic        st_hyper_dq4_o;
      logic        st_hyper_dq5_o;
      logic        st_hyper_dq6_o;
      logic        st_hyper_dq7_o;
      logic        st_hyper_dq_oe;
      logic        st_hyper_reset_no;
      logic        st_hyper_rwds_o;
      logic        st_hyper_rwds_oe;
      logic        st_jtag_tdo;
     } pad_domain_aon_static_connection_signals_soc2pad_t;

   typedef struct packed {
      logic        st_boot_sel0;
      logic        st_boot_sel1;
      logic        st_bypass;
      logic        st_bypass_fll;
      logic        st_ext_clk;
      logic        st_hyper_dq0_i;
      logic        st_hyper_dq1_i;
      logic        st_hyper_dq2_i;
      logic        st_hyper_dq3_i;
      logic        st_hyper_dq4_i;
      logic        st_hyper_dq5_i;
      logic        st_hyper_dq6_i;
      logic        st_hyper_dq7_i;
      logic        st_hyper_rwds_i;
      logic        st_jtag_tck;
      logic        st_jtag_tdi;
      logic        st_jtag_tms;
      logic        st_jtag_trstn;
      logic        st_ref_clk;
      logic        st_rst_n;
     } pad_domain_aon_static_connection_signals_pad2soc_t;

  // Port Group signals
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
     } pad_domain_aon_port_group_qspi0_soc2pad_t;

   typedef struct packed {
      logic        sd0_i;
      logic        sd1_i;
      logic        sd2_i;
      logic        sd3_i;
     } pad_domain_aon_port_group_qspi0_pad2soc_t;

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
     } pad_domain_aon_port_group_qspi1_soc2pad_t;

   typedef struct packed {
      logic        sd0_i;
      logic        sd1_i;
      logic        sd2_i;
      logic        sd3_i;
     } pad_domain_aon_port_group_qspi1_pad2soc_t;

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
     } pad_domain_aon_port_group_qspi2_soc2pad_t;

   typedef struct packed {
      logic        sd0_i;
      logic        sd1_i;
      logic        sd2_i;
      logic        sd3_i;
     } pad_domain_aon_port_group_qspi2_pad2soc_t;

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
     } pad_domain_aon_port_group_qspi3_soc2pad_t;

   typedef struct packed {
      logic        sd0_i;
      logic        sd1_i;
      logic        sd2_i;
      logic        sd3_i;
     } pad_domain_aon_port_group_qspi3_pad2soc_t;

   typedef struct packed {
      logic        tx_o;
     } pad_domain_aon_port_group_uart0_soc2pad_t;

   typedef struct packed {
      logic        rx_i;
     } pad_domain_aon_port_group_uart0_pad2soc_t;

   typedef struct packed {
      logic        tx_o;
     } pad_domain_aon_port_group_uart1_soc2pad_t;

   typedef struct packed {
      logic        rx_i;
     } pad_domain_aon_port_group_uart1_pad2soc_t;

   typedef struct packed {
      logic        out0_o;
      logic        out1_o;
      logic        out2_o;
      logic        out3_o;
     } pad_domain_aon_port_group_timer0_soc2pad_t;

   typedef struct packed {
      logic        out0_o;
      logic        out1_o;
      logic        out2_o;
      logic        out3_o;
     } pad_domain_aon_port_group_timer1_soc2pad_t;

   typedef struct packed {
      logic        out0_o;
      logic        out1_o;
      logic        out2_o;
      logic        out3_o;
     } pad_domain_aon_port_group_timer2_soc2pad_t;

   typedef struct packed {
      logic        out0_o;
      logic        out1_o;
      logic        out2_o;
      logic        out3_o;
     } pad_domain_aon_port_group_timer3_soc2pad_t;

   typedef struct packed {
      logic        scl_o;
      logic        scl_oe;
      logic        sda_o;
      logic        sda_oe;
     } pad_domain_aon_port_group_i2c0_soc2pad_t;

   typedef struct packed {
      logic        scl_i;
      logic        sda_i;
     } pad_domain_aon_port_group_i2c0_pad2soc_t;

   typedef struct packed {
      logic        scl_o;
      logic        scl_oe;
      logic        sda_o;
      logic        sda_oe;
     } pad_domain_aon_port_group_i2c1_soc2pad_t;

   typedef struct packed {
      logic        scl_i;
      logic        sda_i;
     } pad_domain_aon_port_group_i2c1_pad2soc_t;

   typedef struct packed {
      logic        scl_o;
      logic        scl_oe;
      logic        sda_o;
      logic        sda_oe;
     } pad_domain_aon_port_group_i2c2_soc2pad_t;

   typedef struct packed {
      logic        scl_i;
      logic        sda_i;
     } pad_domain_aon_port_group_i2c2_pad2soc_t;

   typedef struct packed {
      logic        scl_o;
      logic        scl_oe;
      logic        sda_o;
      logic        sda_oe;
     } pad_domain_aon_port_group_i2c3_soc2pad_t;

   typedef struct packed {
      logic        scl_i;
      logic        sda_i;
     } pad_domain_aon_port_group_i2c3_pad2soc_t;

   typedef struct packed {
      logic        are_o;
      logic        asa_o;
      logic        asy_o;
      logic        cfg0_o;
      logic        cfg1_o;
      logic        cfg2_o;
      logic        cfg3_o;
      logic        cfg4_o;
      logic        cfg5_o;
      logic        cfg6_o;
      logic        cfg7_o;
      logic        sxy_o;
      logic        xclk_o;
      logic        xnrst_o;
      logic        yclk_o;
      logic        ynrst_o;
     } pad_domain_aon_port_group_dvsi0_soc2pad_t;

   typedef struct packed {
      logic        off0_i;
      logic        off1_i;
      logic        off2_i;
      logic        off3_i;
      logic        on0_i;
      logic        on1_i;
      logic        on2_i;
      logic        on3_i;
      logic        xydata0_i;
      logic        xydata1_i;
      logic        xydata2_i;
      logic        xydata3_i;
      logic        xydata4_i;
      logic        xydata5_i;
      logic        xydata6_i;
      logic        xydata7_i;
     } pad_domain_aon_port_group_dvsi0_pad2soc_t;

   typedef struct packed {
      logic        gpio0_dir;
      logic        gpio0_o;
      logic        gpio1_dir;
      logic        gpio1_o;
      logic        gpio2_dir;
      logic        gpio2_o;
      logic        gpio3_dir;
      logic        gpio3_o;
      logic        gpio4_dir;
      logic        gpio4_o;
      logic        gpio5_dir;
      logic        gpio5_o;
      logic        gpio6_dir;
      logic        gpio6_o;
      logic        gpio7_dir;
      logic        gpio7_o;
      logic        gpio8_dir;
      logic        gpio8_o;
      logic        gpio9_dir;
      logic        gpio9_o;
      logic        gpio10_dir;
      logic        gpio10_o;
      logic        gpio11_dir;
      logic        gpio11_o;
      logic        gpio12_dir;
      logic        gpio12_o;
      logic        gpio13_dir;
      logic        gpio13_o;
      logic        gpio14_dir;
      logic        gpio14_o;
      logic        gpio15_dir;
      logic        gpio15_o;
      logic        gpio16_dir;
      logic        gpio16_o;
      logic        gpio17_dir;
      logic        gpio17_o;
      logic        gpio18_dir;
      logic        gpio18_o;
      logic        gpio19_dir;
      logic        gpio19_o;
      logic        gpio20_dir;
      logic        gpio20_o;
      logic        gpio21_dir;
      logic        gpio21_o;
      logic        gpio22_dir;
      logic        gpio22_o;
      logic        gpio23_dir;
      logic        gpio23_o;
      logic        gpio24_dir;
      logic        gpio24_o;
      logic        gpio25_dir;
      logic        gpio25_o;
     } pad_domain_aon_port_group_gpio_a_soc2pad_t;

   typedef struct packed {
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
     } pad_domain_aon_port_group_gpio_a_pad2soc_t;

   typedef struct packed {
      logic        gpio0_dir;
      logic        gpio0_o;
      logic        gpio1_dir;
      logic        gpio1_o;
      logic        gpio2_dir;
      logic        gpio2_o;
      logic        gpio3_dir;
      logic        gpio3_o;
      logic        gpio4_dir;
      logic        gpio4_o;
      logic        gpio5_dir;
      logic        gpio5_o;
      logic        gpio6_dir;
      logic        gpio6_o;
      logic        gpio7_dir;
      logic        gpio7_o;
      logic        gpio8_dir;
      logic        gpio8_o;
      logic        gpio9_dir;
      logic        gpio9_o;
      logic        gpio10_dir;
      logic        gpio10_o;
      logic        gpio11_dir;
      logic        gpio11_o;
      logic        gpio12_dir;
      logic        gpio12_o;
      logic        gpio13_dir;
      logic        gpio13_o;
      logic        gpio14_dir;
      logic        gpio14_o;
      logic        gpio15_dir;
      logic        gpio15_o;
     } pad_domain_aon_port_group_gpio_b_soc2pad_t;

   typedef struct packed {
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
     } pad_domain_aon_port_group_gpio_b_pad2soc_t;

   typedef struct packed {
     pad_domain_aon_port_group_qspi0_soc2pad_t qspi0;
     pad_domain_aon_port_group_qspi1_soc2pad_t qspi1;
     pad_domain_aon_port_group_qspi2_soc2pad_t qspi2;
     pad_domain_aon_port_group_qspi3_soc2pad_t qspi3;
     pad_domain_aon_port_group_uart0_soc2pad_t uart0;
     pad_domain_aon_port_group_uart1_soc2pad_t uart1;
     pad_domain_aon_port_group_timer0_soc2pad_t timer0;
     pad_domain_aon_port_group_timer1_soc2pad_t timer1;
     pad_domain_aon_port_group_timer2_soc2pad_t timer2;
     pad_domain_aon_port_group_timer3_soc2pad_t timer3;
     pad_domain_aon_port_group_i2c0_soc2pad_t i2c0;
     pad_domain_aon_port_group_i2c1_soc2pad_t i2c1;
     pad_domain_aon_port_group_i2c2_soc2pad_t i2c2;
     pad_domain_aon_port_group_i2c3_soc2pad_t i2c3;
     pad_domain_aon_port_group_dvsi0_soc2pad_t dvsi0;
     pad_domain_aon_port_group_gpio_a_soc2pad_t gpio_a;
     pad_domain_aon_port_group_gpio_b_soc2pad_t gpio_b;
     } pad_domain_aon_ports_soc2pad_t;

   typedef struct packed {
     pad_domain_aon_port_group_qspi0_pad2soc_t qspi0;
     pad_domain_aon_port_group_qspi1_pad2soc_t qspi1;
     pad_domain_aon_port_group_qspi2_pad2soc_t qspi2;
     pad_domain_aon_port_group_qspi3_pad2soc_t qspi3;
     pad_domain_aon_port_group_uart0_pad2soc_t uart0;
     pad_domain_aon_port_group_uart1_pad2soc_t uart1;
     pad_domain_aon_port_group_i2c0_pad2soc_t i2c0;
     pad_domain_aon_port_group_i2c1_pad2soc_t i2c1;
     pad_domain_aon_port_group_i2c2_pad2soc_t i2c2;
     pad_domain_aon_port_group_i2c3_pad2soc_t i2c3;
     pad_domain_aon_port_group_dvsi0_pad2soc_t dvsi0;
     pad_domain_aon_port_group_gpio_a_pad2soc_t gpio_a;
     pad_domain_aon_port_group_gpio_b_pad2soc_t gpio_b;
     } pad_domain_aon_ports_pad2soc_t;


  //Toplevel structs

  typedef struct packed {
    pad_domain_aon_static_connection_signals_pad2soc_t aon;
  } static_connection_signals_pad2soc_t;

  typedef struct packed {
    pad_domain_aon_static_connection_signals_soc2pad_t aon;
  } static_connection_signals_soc2pad_t;

  typedef struct packed {
    pad_domain_aon_ports_pad2soc_t aon;
  } port_signals_pad2soc_t;

  typedef struct packed {
    pad_domain_aon_ports_soc2pad_t aon;
  } port_signals_soc2pad_t;


endpackage : pkg_kraken_padframe
