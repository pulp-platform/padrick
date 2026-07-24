

// Assignment Macros
// Assigns all members of port struct to another struct with same names but potentially different order

`define ASSIGN_AON_UART_PAD2SOC(load, driver) \
  assign load.rx_i = driver.rx_i; \
  assign load.tx_lb_i = driver.tx_lb_i; \

`define ASSIGN_AON_UART_SOC2PAD(load, driver) \
  assign load.tx_o = driver.tx_o; \

`define ASSIGN_AON_GPIO_PAD2SOC(load, driver) \
  assign load.in0 = driver.in0; \
  assign load.in1 = driver.in1; \

`define ASSIGN_AON_GPIO_SOC2PAD(load, driver) \
  assign load.dir0 = driver.dir0; \
  assign load.dir1 = driver.dir1; \
  assign load.out0 = driver.out0; \
  assign load.out1 = driver.out1; \


