

// Assignment Macros
// Assigns all members of port struct to another struct with same names but potentially different order

`define ASSIGN_DOMAIN_GPIO_PAD2SOC(load, driver) \
  assign load.gpio00_in = driver.gpio00_in; \
  assign load.gpio01_in = driver.gpio01_in; \
  assign load.gpio02_in = driver.gpio02_in; \
  assign load.gpio03_in = driver.gpio03_in; \
  assign load.gpio04_in = driver.gpio04_in; \
  assign load.gpio05_in = driver.gpio05_in; \
  assign load.gpio06_in = driver.gpio06_in; \
  assign load.gpio07_in = driver.gpio07_in; \
  assign load.gpio08_in = driver.gpio08_in; \
  assign load.gpio09_in = driver.gpio09_in; \
  assign load.gpio10_in = driver.gpio10_in; \
  assign load.gpio11_in = driver.gpio11_in; \
  assign load.gpio12_in = driver.gpio12_in; \
  assign load.gpio13_in = driver.gpio13_in; \
  assign load.gpio14_in = driver.gpio14_in; \
  assign load.gpio15_in = driver.gpio15_in; \
  assign load.gpio16_in = driver.gpio16_in; \
  assign load.gpio17_in = driver.gpio17_in; \
  assign load.gpio18_in = driver.gpio18_in; \
  assign load.gpio19_in = driver.gpio19_in; \
  assign load.gpio20_in = driver.gpio20_in; \
  assign load.gpio21_in = driver.gpio21_in; \
  assign load.gpio22_in = driver.gpio22_in; \
  assign load.gpio23_in = driver.gpio23_in; \
  assign load.gpio24_in = driver.gpio24_in; \
  assign load.gpio25_in = driver.gpio25_in; \
  assign load.gpio26_in = driver.gpio26_in; \
  assign load.gpio27_in = driver.gpio27_in; \
  assign load.gpio28_in = driver.gpio28_in; \
  assign load.gpio29_in = driver.gpio29_in; \
  assign load.gpio30_in = driver.gpio30_in; \
  assign load.gpio31_in = driver.gpio31_in; \

`define ASSIGN_DOMAIN_GPIO_SOC2PAD(load, driver) \
  assign load.gpio00_out = driver.gpio00_out; \
  assign load.gpio00_tx_en = driver.gpio00_tx_en; \
  assign load.gpio01_out = driver.gpio01_out; \
  assign load.gpio01_tx_en = driver.gpio01_tx_en; \
  assign load.gpio02_out = driver.gpio02_out; \
  assign load.gpio02_tx_en = driver.gpio02_tx_en; \
  assign load.gpio03_out = driver.gpio03_out; \
  assign load.gpio03_tx_en = driver.gpio03_tx_en; \
  assign load.gpio04_out = driver.gpio04_out; \
  assign load.gpio04_tx_en = driver.gpio04_tx_en; \
  assign load.gpio05_out = driver.gpio05_out; \
  assign load.gpio05_tx_en = driver.gpio05_tx_en; \
  assign load.gpio06_out = driver.gpio06_out; \
  assign load.gpio06_tx_en = driver.gpio06_tx_en; \
  assign load.gpio07_out = driver.gpio07_out; \
  assign load.gpio07_tx_en = driver.gpio07_tx_en; \
  assign load.gpio08_out = driver.gpio08_out; \
  assign load.gpio08_tx_en = driver.gpio08_tx_en; \
  assign load.gpio09_out = driver.gpio09_out; \
  assign load.gpio09_tx_en = driver.gpio09_tx_en; \
  assign load.gpio10_out = driver.gpio10_out; \
  assign load.gpio10_tx_en = driver.gpio10_tx_en; \
  assign load.gpio11_out = driver.gpio11_out; \
  assign load.gpio11_tx_en = driver.gpio11_tx_en; \
  assign load.gpio12_out = driver.gpio12_out; \
  assign load.gpio12_tx_en = driver.gpio12_tx_en; \
  assign load.gpio13_out = driver.gpio13_out; \
  assign load.gpio13_tx_en = driver.gpio13_tx_en; \
  assign load.gpio14_out = driver.gpio14_out; \
  assign load.gpio14_tx_en = driver.gpio14_tx_en; \
  assign load.gpio15_out = driver.gpio15_out; \
  assign load.gpio15_tx_en = driver.gpio15_tx_en; \
  assign load.gpio16_out = driver.gpio16_out; \
  assign load.gpio16_tx_en = driver.gpio16_tx_en; \
  assign load.gpio17_out = driver.gpio17_out; \
  assign load.gpio17_tx_en = driver.gpio17_tx_en; \
  assign load.gpio18_out = driver.gpio18_out; \
  assign load.gpio18_tx_en = driver.gpio18_tx_en; \
  assign load.gpio19_out = driver.gpio19_out; \
  assign load.gpio19_tx_en = driver.gpio19_tx_en; \
  assign load.gpio20_out = driver.gpio20_out; \
  assign load.gpio20_tx_en = driver.gpio20_tx_en; \
  assign load.gpio21_out = driver.gpio21_out; \
  assign load.gpio21_tx_en = driver.gpio21_tx_en; \
  assign load.gpio22_out = driver.gpio22_out; \
  assign load.gpio22_tx_en = driver.gpio22_tx_en; \
  assign load.gpio23_out = driver.gpio23_out; \
  assign load.gpio23_tx_en = driver.gpio23_tx_en; \
  assign load.gpio24_out = driver.gpio24_out; \
  assign load.gpio24_tx_en = driver.gpio24_tx_en; \
  assign load.gpio25_out = driver.gpio25_out; \
  assign load.gpio25_tx_en = driver.gpio25_tx_en; \
  assign load.gpio26_out = driver.gpio26_out; \
  assign load.gpio26_tx_en = driver.gpio26_tx_en; \
  assign load.gpio27_out = driver.gpio27_out; \
  assign load.gpio27_tx_en = driver.gpio27_tx_en; \
  assign load.gpio28_out = driver.gpio28_out; \
  assign load.gpio28_tx_en = driver.gpio28_tx_en; \
  assign load.gpio29_out = driver.gpio29_out; \
  assign load.gpio29_tx_en = driver.gpio29_tx_en; \
  assign load.gpio30_out = driver.gpio30_out; \
  assign load.gpio30_tx_en = driver.gpio30_tx_en; \
  assign load.gpio31_out = driver.gpio31_out; \
  assign load.gpio31_tx_en = driver.gpio31_tx_en; \

`define ASSIGN_DOMAIN_I2C0_PAD2SOC(load, driver) \
  assign load.scl_i = driver.scl_i; \
  assign load.sda_i = driver.sda_i; \

`define ASSIGN_DOMAIN_I2C0_SOC2PAD(load, driver) \
  assign load.scl_o = driver.scl_o; \
  assign load.scl_oe = driver.scl_oe; \
  assign load.sda_o = driver.sda_o; \
  assign load.sda_oe = driver.sda_oe; \

`define ASSIGN_DOMAIN_UART0_PAD2SOC(load, driver) \
  assign load.rx_i = driver.rx_i; \

`define ASSIGN_DOMAIN_UART0_SOC2PAD(load, driver) \
  assign load.tx_o = driver.tx_o; \

`define ASSIGN_DOMAIN_QSPIM0_PAD2SOC(load, driver) \
  assign load.sd0_i = driver.sd0_i; \
  assign load.sd1_i = driver.sd1_i; \
  assign load.sd2_i = driver.sd2_i; \
  assign load.sd3_i = driver.sd3_i; \

`define ASSIGN_DOMAIN_QSPIM0_SOC2PAD(load, driver) \
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


