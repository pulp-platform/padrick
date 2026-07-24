
package pkg_quasi_static_padframe;

  //Structs for aon

  // Port Group signals
   typedef struct packed {
      logic        tx_o;
     } pad_domain_aon_port_group_uart_soc2pad_t;

   typedef struct packed {
      logic        rx_i;
      logic        tx_lb_i;
     } pad_domain_aon_port_group_uart_pad2soc_t;

   typedef struct packed {
      logic        dir0;
      logic        dir1;
      logic        out0;
      logic        out1;
     } pad_domain_aon_port_group_gpio_soc2pad_t;

   typedef struct packed {
      logic        in0;
      logic        in1;
     } pad_domain_aon_port_group_gpio_pad2soc_t;

   typedef struct packed {
     pad_domain_aon_port_group_uart_soc2pad_t uart;
     pad_domain_aon_port_group_gpio_soc2pad_t gpio;
     } pad_domain_aon_ports_soc2pad_t;

   typedef struct packed {
     pad_domain_aon_port_group_uart_pad2soc_t uart;
     pad_domain_aon_port_group_gpio_pad2soc_t gpio;
     } pad_domain_aon_ports_pad2soc_t;


  //Toplevel structs

  typedef struct packed {
    pad_domain_aon_ports_pad2soc_t aon;
  } port_signals_pad2soc_t;

  typedef struct packed {
    pad_domain_aon_ports_soc2pad_t aon;
  } port_signals_soc2pad_t;


endpackage : pkg_quasi_static_padframe
