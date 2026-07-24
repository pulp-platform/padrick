

// Assignment Macros
// Assigns all members of port struct to another struct with same names but potentially different order

`define ASSIGN_AON_QSPI0_PAD2SOC(load, driver) \
  assign load.sd0_i = driver.sd0_i; \
  assign load.sd1_i = driver.sd1_i; \
  assign load.sd2_i = driver.sd2_i; \
  assign load.sd3_i = driver.sd3_i; \

`define ASSIGN_AON_QSPI0_SOC2PAD(load, driver) \
  assign load.csn0_o = driver.csn0_o; \
  assign load.csn1_o = driver.csn1_o; \
  assign load.csn2_o = driver.csn2_o; \
  assign load.csn3_o = driver.csn3_o; \
  assign load.sck_o = driver.sck_o; \
  assign load.sd0_o = driver.sd0_o; \
  assign load.sd0_oe = driver.sd0_oe; \
  assign load.sd1_o = driver.sd1_o; \
  assign load.sd1_oe = driver.sd1_oe; \
  assign load.sd2_o = driver.sd2_o; \
  assign load.sd2_oe = driver.sd2_oe; \
  assign load.sd3_o = driver.sd3_o; \
  assign load.sd3_oe = driver.sd3_oe; \

`define ASSIGN_AON_QSPI1_PAD2SOC(load, driver) \
  assign load.sd0_i = driver.sd0_i; \
  assign load.sd1_i = driver.sd1_i; \
  assign load.sd2_i = driver.sd2_i; \
  assign load.sd3_i = driver.sd3_i; \

`define ASSIGN_AON_QSPI1_SOC2PAD(load, driver) \
  assign load.csn0_o = driver.csn0_o; \
  assign load.csn1_o = driver.csn1_o; \
  assign load.csn2_o = driver.csn2_o; \
  assign load.csn3_o = driver.csn3_o; \
  assign load.sck_o = driver.sck_o; \
  assign load.sd0_o = driver.sd0_o; \
  assign load.sd0_oe = driver.sd0_oe; \
  assign load.sd1_o = driver.sd1_o; \
  assign load.sd1_oe = driver.sd1_oe; \
  assign load.sd2_o = driver.sd2_o; \
  assign load.sd2_oe = driver.sd2_oe; \
  assign load.sd3_o = driver.sd3_o; \
  assign load.sd3_oe = driver.sd3_oe; \

`define ASSIGN_AON_QSPI2_PAD2SOC(load, driver) \
  assign load.sd0_i = driver.sd0_i; \
  assign load.sd1_i = driver.sd1_i; \
  assign load.sd2_i = driver.sd2_i; \
  assign load.sd3_i = driver.sd3_i; \

`define ASSIGN_AON_QSPI2_SOC2PAD(load, driver) \
  assign load.csn0_o = driver.csn0_o; \
  assign load.csn1_o = driver.csn1_o; \
  assign load.csn2_o = driver.csn2_o; \
  assign load.csn3_o = driver.csn3_o; \
  assign load.sck_o = driver.sck_o; \
  assign load.sd0_o = driver.sd0_o; \
  assign load.sd0_oe = driver.sd0_oe; \
  assign load.sd1_o = driver.sd1_o; \
  assign load.sd1_oe = driver.sd1_oe; \
  assign load.sd2_o = driver.sd2_o; \
  assign load.sd2_oe = driver.sd2_oe; \
  assign load.sd3_o = driver.sd3_o; \
  assign load.sd3_oe = driver.sd3_oe; \

`define ASSIGN_AON_QSPI3_PAD2SOC(load, driver) \
  assign load.sd0_i = driver.sd0_i; \
  assign load.sd1_i = driver.sd1_i; \
  assign load.sd2_i = driver.sd2_i; \
  assign load.sd3_i = driver.sd3_i; \

`define ASSIGN_AON_QSPI3_SOC2PAD(load, driver) \
  assign load.csn0_o = driver.csn0_o; \
  assign load.csn1_o = driver.csn1_o; \
  assign load.csn2_o = driver.csn2_o; \
  assign load.csn3_o = driver.csn3_o; \
  assign load.sck_o = driver.sck_o; \
  assign load.sd0_o = driver.sd0_o; \
  assign load.sd0_oe = driver.sd0_oe; \
  assign load.sd1_o = driver.sd1_o; \
  assign load.sd1_oe = driver.sd1_oe; \
  assign load.sd2_o = driver.sd2_o; \
  assign load.sd2_oe = driver.sd2_oe; \
  assign load.sd3_o = driver.sd3_o; \
  assign load.sd3_oe = driver.sd3_oe; \

`define ASSIGN_AON_UART0_PAD2SOC(load, driver) \
  assign load.rx_i = driver.rx_i; \

`define ASSIGN_AON_UART0_SOC2PAD(load, driver) \
  assign load.tx_o = driver.tx_o; \

`define ASSIGN_AON_UART1_PAD2SOC(load, driver) \
  assign load.rx_i = driver.rx_i; \

`define ASSIGN_AON_UART1_SOC2PAD(load, driver) \
  assign load.tx_o = driver.tx_o; \


`define ASSIGN_AON_TIMER0_SOC2PAD(load, driver) \
  assign load.out0_o = driver.out0_o; \
  assign load.out1_o = driver.out1_o; \
  assign load.out2_o = driver.out2_o; \
  assign load.out3_o = driver.out3_o; \


`define ASSIGN_AON_TIMER1_SOC2PAD(load, driver) \
  assign load.out0_o = driver.out0_o; \
  assign load.out1_o = driver.out1_o; \
  assign load.out2_o = driver.out2_o; \
  assign load.out3_o = driver.out3_o; \


`define ASSIGN_AON_TIMER2_SOC2PAD(load, driver) \
  assign load.out0_o = driver.out0_o; \
  assign load.out1_o = driver.out1_o; \
  assign load.out2_o = driver.out2_o; \
  assign load.out3_o = driver.out3_o; \


`define ASSIGN_AON_TIMER3_SOC2PAD(load, driver) \
  assign load.out0_o = driver.out0_o; \
  assign load.out1_o = driver.out1_o; \
  assign load.out2_o = driver.out2_o; \
  assign load.out3_o = driver.out3_o; \

`define ASSIGN_AON_I2C0_PAD2SOC(load, driver) \
  assign load.scl_i = driver.scl_i; \
  assign load.sda_i = driver.sda_i; \

`define ASSIGN_AON_I2C0_SOC2PAD(load, driver) \
  assign load.scl_o = driver.scl_o; \
  assign load.scl_oe = driver.scl_oe; \
  assign load.sda_o = driver.sda_o; \
  assign load.sda_oe = driver.sda_oe; \

`define ASSIGN_AON_I2C1_PAD2SOC(load, driver) \
  assign load.scl_i = driver.scl_i; \
  assign load.sda_i = driver.sda_i; \

`define ASSIGN_AON_I2C1_SOC2PAD(load, driver) \
  assign load.scl_o = driver.scl_o; \
  assign load.scl_oe = driver.scl_oe; \
  assign load.sda_o = driver.sda_o; \
  assign load.sda_oe = driver.sda_oe; \

`define ASSIGN_AON_I2C2_PAD2SOC(load, driver) \
  assign load.scl_i = driver.scl_i; \
  assign load.sda_i = driver.sda_i; \

`define ASSIGN_AON_I2C2_SOC2PAD(load, driver) \
  assign load.scl_o = driver.scl_o; \
  assign load.scl_oe = driver.scl_oe; \
  assign load.sda_o = driver.sda_o; \
  assign load.sda_oe = driver.sda_oe; \

`define ASSIGN_AON_I2C3_PAD2SOC(load, driver) \
  assign load.scl_i = driver.scl_i; \
  assign load.sda_i = driver.sda_i; \

`define ASSIGN_AON_I2C3_SOC2PAD(load, driver) \
  assign load.scl_o = driver.scl_o; \
  assign load.scl_oe = driver.scl_oe; \
  assign load.sda_o = driver.sda_o; \
  assign load.sda_oe = driver.sda_oe; \

`define ASSIGN_AON_DVSI0_PAD2SOC(load, driver) \
  assign load.off0_i = driver.off0_i; \
  assign load.off1_i = driver.off1_i; \
  assign load.off2_i = driver.off2_i; \
  assign load.off3_i = driver.off3_i; \
  assign load.on0_i = driver.on0_i; \
  assign load.on1_i = driver.on1_i; \
  assign load.on2_i = driver.on2_i; \
  assign load.on3_i = driver.on3_i; \
  assign load.xydata0_i = driver.xydata0_i; \
  assign load.xydata1_i = driver.xydata1_i; \
  assign load.xydata2_i = driver.xydata2_i; \
  assign load.xydata3_i = driver.xydata3_i; \
  assign load.xydata4_i = driver.xydata4_i; \
  assign load.xydata5_i = driver.xydata5_i; \
  assign load.xydata6_i = driver.xydata6_i; \
  assign load.xydata7_i = driver.xydata7_i; \

`define ASSIGN_AON_DVSI0_SOC2PAD(load, driver) \
  assign load.are_o = driver.are_o; \
  assign load.asa_o = driver.asa_o; \
  assign load.asy_o = driver.asy_o; \
  assign load.cfg0_o = driver.cfg0_o; \
  assign load.cfg1_o = driver.cfg1_o; \
  assign load.cfg2_o = driver.cfg2_o; \
  assign load.cfg3_o = driver.cfg3_o; \
  assign load.cfg4_o = driver.cfg4_o; \
  assign load.cfg5_o = driver.cfg5_o; \
  assign load.cfg6_o = driver.cfg6_o; \
  assign load.cfg7_o = driver.cfg7_o; \
  assign load.sxy_o = driver.sxy_o; \
  assign load.xclk_o = driver.xclk_o; \
  assign load.xnrst_o = driver.xnrst_o; \
  assign load.yclk_o = driver.yclk_o; \
  assign load.ynrst_o = driver.ynrst_o; \

`define ASSIGN_AON_GPIO_A_PAD2SOC(load, driver) \
  assign load.gpio0_i = driver.gpio0_i; \
  assign load.gpio1_i = driver.gpio1_i; \
  assign load.gpio2_i = driver.gpio2_i; \
  assign load.gpio3_i = driver.gpio3_i; \
  assign load.gpio4_i = driver.gpio4_i; \
  assign load.gpio5_i = driver.gpio5_i; \
  assign load.gpio6_i = driver.gpio6_i; \
  assign load.gpio7_i = driver.gpio7_i; \
  assign load.gpio8_i = driver.gpio8_i; \
  assign load.gpio9_i = driver.gpio9_i; \
  assign load.gpio10_i = driver.gpio10_i; \
  assign load.gpio11_i = driver.gpio11_i; \
  assign load.gpio12_i = driver.gpio12_i; \
  assign load.gpio13_i = driver.gpio13_i; \
  assign load.gpio14_i = driver.gpio14_i; \
  assign load.gpio15_i = driver.gpio15_i; \
  assign load.gpio16_i = driver.gpio16_i; \
  assign load.gpio17_i = driver.gpio17_i; \
  assign load.gpio18_i = driver.gpio18_i; \
  assign load.gpio19_i = driver.gpio19_i; \
  assign load.gpio20_i = driver.gpio20_i; \
  assign load.gpio21_i = driver.gpio21_i; \
  assign load.gpio22_i = driver.gpio22_i; \
  assign load.gpio23_i = driver.gpio23_i; \
  assign load.gpio24_i = driver.gpio24_i; \
  assign load.gpio25_i = driver.gpio25_i; \

`define ASSIGN_AON_GPIO_A_SOC2PAD(load, driver) \
  assign load.gpio0_dir = driver.gpio0_dir; \
  assign load.gpio0_o = driver.gpio0_o; \
  assign load.gpio1_dir = driver.gpio1_dir; \
  assign load.gpio1_o = driver.gpio1_o; \
  assign load.gpio2_dir = driver.gpio2_dir; \
  assign load.gpio2_o = driver.gpio2_o; \
  assign load.gpio3_dir = driver.gpio3_dir; \
  assign load.gpio3_o = driver.gpio3_o; \
  assign load.gpio4_dir = driver.gpio4_dir; \
  assign load.gpio4_o = driver.gpio4_o; \
  assign load.gpio5_dir = driver.gpio5_dir; \
  assign load.gpio5_o = driver.gpio5_o; \
  assign load.gpio6_dir = driver.gpio6_dir; \
  assign load.gpio6_o = driver.gpio6_o; \
  assign load.gpio7_dir = driver.gpio7_dir; \
  assign load.gpio7_o = driver.gpio7_o; \
  assign load.gpio8_dir = driver.gpio8_dir; \
  assign load.gpio8_o = driver.gpio8_o; \
  assign load.gpio9_dir = driver.gpio9_dir; \
  assign load.gpio9_o = driver.gpio9_o; \
  assign load.gpio10_dir = driver.gpio10_dir; \
  assign load.gpio10_o = driver.gpio10_o; \
  assign load.gpio11_dir = driver.gpio11_dir; \
  assign load.gpio11_o = driver.gpio11_o; \
  assign load.gpio12_dir = driver.gpio12_dir; \
  assign load.gpio12_o = driver.gpio12_o; \
  assign load.gpio13_dir = driver.gpio13_dir; \
  assign load.gpio13_o = driver.gpio13_o; \
  assign load.gpio14_dir = driver.gpio14_dir; \
  assign load.gpio14_o = driver.gpio14_o; \
  assign load.gpio15_dir = driver.gpio15_dir; \
  assign load.gpio15_o = driver.gpio15_o; \
  assign load.gpio16_dir = driver.gpio16_dir; \
  assign load.gpio16_o = driver.gpio16_o; \
  assign load.gpio17_dir = driver.gpio17_dir; \
  assign load.gpio17_o = driver.gpio17_o; \
  assign load.gpio18_dir = driver.gpio18_dir; \
  assign load.gpio18_o = driver.gpio18_o; \
  assign load.gpio19_dir = driver.gpio19_dir; \
  assign load.gpio19_o = driver.gpio19_o; \
  assign load.gpio20_dir = driver.gpio20_dir; \
  assign load.gpio20_o = driver.gpio20_o; \
  assign load.gpio21_dir = driver.gpio21_dir; \
  assign load.gpio21_o = driver.gpio21_o; \
  assign load.gpio22_dir = driver.gpio22_dir; \
  assign load.gpio22_o = driver.gpio22_o; \
  assign load.gpio23_dir = driver.gpio23_dir; \
  assign load.gpio23_o = driver.gpio23_o; \
  assign load.gpio24_dir = driver.gpio24_dir; \
  assign load.gpio24_o = driver.gpio24_o; \
  assign load.gpio25_dir = driver.gpio25_dir; \
  assign load.gpio25_o = driver.gpio25_o; \

`define ASSIGN_AON_GPIO_B_PAD2SOC(load, driver) \
  assign load.gpio0_i = driver.gpio0_i; \
  assign load.gpio1_i = driver.gpio1_i; \
  assign load.gpio2_i = driver.gpio2_i; \
  assign load.gpio3_i = driver.gpio3_i; \
  assign load.gpio4_i = driver.gpio4_i; \
  assign load.gpio5_i = driver.gpio5_i; \
  assign load.gpio6_i = driver.gpio6_i; \
  assign load.gpio7_i = driver.gpio7_i; \
  assign load.gpio8_i = driver.gpio8_i; \
  assign load.gpio9_i = driver.gpio9_i; \
  assign load.gpio10_i = driver.gpio10_i; \
  assign load.gpio11_i = driver.gpio11_i; \
  assign load.gpio12_i = driver.gpio12_i; \
  assign load.gpio13_i = driver.gpio13_i; \
  assign load.gpio14_i = driver.gpio14_i; \
  assign load.gpio15_i = driver.gpio15_i; \

`define ASSIGN_AON_GPIO_B_SOC2PAD(load, driver) \
  assign load.gpio0_dir = driver.gpio0_dir; \
  assign load.gpio0_o = driver.gpio0_o; \
  assign load.gpio1_dir = driver.gpio1_dir; \
  assign load.gpio1_o = driver.gpio1_o; \
  assign load.gpio2_dir = driver.gpio2_dir; \
  assign load.gpio2_o = driver.gpio2_o; \
  assign load.gpio3_dir = driver.gpio3_dir; \
  assign load.gpio3_o = driver.gpio3_o; \
  assign load.gpio4_dir = driver.gpio4_dir; \
  assign load.gpio4_o = driver.gpio4_o; \
  assign load.gpio5_dir = driver.gpio5_dir; \
  assign load.gpio5_o = driver.gpio5_o; \
  assign load.gpio6_dir = driver.gpio6_dir; \
  assign load.gpio6_o = driver.gpio6_o; \
  assign load.gpio7_dir = driver.gpio7_dir; \
  assign load.gpio7_o = driver.gpio7_o; \
  assign load.gpio8_dir = driver.gpio8_dir; \
  assign load.gpio8_o = driver.gpio8_o; \
  assign load.gpio9_dir = driver.gpio9_dir; \
  assign load.gpio9_o = driver.gpio9_o; \
  assign load.gpio10_dir = driver.gpio10_dir; \
  assign load.gpio10_o = driver.gpio10_o; \
  assign load.gpio11_dir = driver.gpio11_dir; \
  assign load.gpio11_o = driver.gpio11_o; \
  assign load.gpio12_dir = driver.gpio12_dir; \
  assign load.gpio12_o = driver.gpio12_o; \
  assign load.gpio13_dir = driver.gpio13_dir; \
  assign load.gpio13_o = driver.gpio13_o; \
  assign load.gpio14_dir = driver.gpio14_dir; \
  assign load.gpio14_o = driver.gpio14_o; \
  assign load.gpio15_dir = driver.gpio15_dir; \
  assign load.gpio15_o = driver.gpio15_o; \


