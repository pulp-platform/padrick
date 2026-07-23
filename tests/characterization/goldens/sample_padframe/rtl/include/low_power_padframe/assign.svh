

// Assignment Macros
// Assigns all members of port struct to another struct with same names but potentially different order

`define ASSIGN_ALWAYS_ON_PADS_SPI_PAD2SOC(load, driver) \
  assign load.miso = driver.miso; \

`define ASSIGN_ALWAYS_ON_PADS_SPI_SOC2PAD(load, driver) \
  assign load.csn = driver.csn; \
  assign load.mosi = driver.mosi; \
  assign load.oen = driver.oen; \
  assign load.sck = driver.sck; \
  assign load.spi_en = driver.spi_en; \

`define ASSIGN_ALWAYS_ON_PADS_I2C_PAD2SOC(load, driver) \
  assign load.sda_i = driver.sda_i; \

`define ASSIGN_ALWAYS_ON_PADS_I2C_SOC2PAD(load, driver) \
  assign load.out_en = driver.out_en; \
  assign load.scl = driver.scl; \
  assign load.sda_o = driver.sda_o; \

`define ASSIGN_ALWAYS_ON_PADS_GPIO_A_PAD2SOC(load, driver) \
  assign load.gpio0_o = driver.gpio0_o; \
  assign load.gpio1_o = driver.gpio1_o; \
  assign load.gpio2_o = driver.gpio2_o; \
  assign load.gpio3_o = driver.gpio3_o; \
  assign load.gpio4_o = driver.gpio4_o; \
  assign load.gpio5_o = driver.gpio5_o; \
  assign load.gpio6_o = driver.gpio6_o; \
  assign load.gpio7_o = driver.gpio7_o; \
  assign load.gpio8_o = driver.gpio8_o; \
  assign load.gpio9_o = driver.gpio9_o; \
  assign load.gpio10_o = driver.gpio10_o; \
  assign load.gpio11_o = driver.gpio11_o; \
  assign load.gpio12_o = driver.gpio12_o; \
  assign load.gpio13_o = driver.gpio13_o; \
  assign load.gpio14_o = driver.gpio14_o; \
  assign load.gpio15_o = driver.gpio15_o; \
  assign load.gpio16_o = driver.gpio16_o; \
  assign load.gpio17_o = driver.gpio17_o; \
  assign load.gpio18_o = driver.gpio18_o; \
  assign load.gpio19_o = driver.gpio19_o; \
  assign load.gpio20_o = driver.gpio20_o; \
  assign load.gpio21_o = driver.gpio21_o; \
  assign load.gpio22_o = driver.gpio22_o; \
  assign load.gpio23_o = driver.gpio23_o; \
  assign load.gpio24_o = driver.gpio24_o; \
  assign load.gpio25_o = driver.gpio25_o; \
  assign load.gpio26_o = driver.gpio26_o; \
  assign load.gpio27_o = driver.gpio27_o; \
  assign load.gpio28_o = driver.gpio28_o; \
  assign load.gpio29_o = driver.gpio29_o; \
  assign load.gpio30_o = driver.gpio30_o; \
  assign load.gpio31_o = driver.gpio31_o; \

`define ASSIGN_ALWAYS_ON_PADS_GPIO_A_SOC2PAD(load, driver) \
  assign load.dir0_i = driver.dir0_i; \
  assign load.dir1_i = driver.dir1_i; \
  assign load.dir2_i = driver.dir2_i; \
  assign load.dir3_i = driver.dir3_i; \
  assign load.dir4_i = driver.dir4_i; \
  assign load.dir5_i = driver.dir5_i; \
  assign load.dir6_i = driver.dir6_i; \
  assign load.dir7_i = driver.dir7_i; \
  assign load.dir8_i = driver.dir8_i; \
  assign load.dir9_i = driver.dir9_i; \
  assign load.dir10_i = driver.dir10_i; \
  assign load.dir11_i = driver.dir11_i; \
  assign load.dir12_i = driver.dir12_i; \
  assign load.dir13_i = driver.dir13_i; \
  assign load.dir14_i = driver.dir14_i; \
  assign load.dir15_i = driver.dir15_i; \
  assign load.dir16_i = driver.dir16_i; \
  assign load.dir17_i = driver.dir17_i; \
  assign load.dir18_i = driver.dir18_i; \
  assign load.dir19_i = driver.dir19_i; \
  assign load.dir20_i = driver.dir20_i; \
  assign load.dir21_i = driver.dir21_i; \
  assign load.dir22_i = driver.dir22_i; \
  assign load.dir23_i = driver.dir23_i; \
  assign load.dir24_i = driver.dir24_i; \
  assign load.dir25_i = driver.dir25_i; \
  assign load.dir26_i = driver.dir26_i; \
  assign load.dir27_i = driver.dir27_i; \
  assign load.dir28_i = driver.dir28_i; \
  assign load.dir29_i = driver.dir29_i; \
  assign load.dir30_i = driver.dir30_i; \
  assign load.dir31_i = driver.dir31_i; \
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
  assign load.gpio26_i = driver.gpio26_i; \
  assign load.gpio27_i = driver.gpio27_i; \
  assign load.gpio28_i = driver.gpio28_i; \
  assign load.gpio29_i = driver.gpio29_i; \
  assign load.gpio30_i = driver.gpio30_i; \
  assign load.gpio31_i = driver.gpio31_i; \

`define ASSIGN_ALWAYS_ON_PADS_GPIO_C_PAD2SOC(load, driver) \
  assign load.gpio0_o = driver.gpio0_o; \
  assign load.gpio1_o = driver.gpio1_o; \
  assign load.gpio2_o = driver.gpio2_o; \
  assign load.gpio3_o = driver.gpio3_o; \
  assign load.gpio4_o = driver.gpio4_o; \
  assign load.gpio5_o = driver.gpio5_o; \
  assign load.gpio6_o = driver.gpio6_o; \
  assign load.gpio7_o = driver.gpio7_o; \
  assign load.gpio8_o = driver.gpio8_o; \
  assign load.gpio9_o = driver.gpio9_o; \
  assign load.gpio10_o = driver.gpio10_o; \
  assign load.gpio11_o = driver.gpio11_o; \
  assign load.gpio12_o = driver.gpio12_o; \
  assign load.gpio13_o = driver.gpio13_o; \
  assign load.gpio14_o = driver.gpio14_o; \
  assign load.gpio15_o = driver.gpio15_o; \

`define ASSIGN_ALWAYS_ON_PADS_GPIO_C_SOC2PAD(load, driver) \
  assign load.dir0_i = driver.dir0_i; \
  assign load.dir1_i = driver.dir1_i; \
  assign load.dir2_i = driver.dir2_i; \
  assign load.dir3_i = driver.dir3_i; \
  assign load.dir4_i = driver.dir4_i; \
  assign load.dir5_i = driver.dir5_i; \
  assign load.dir6_i = driver.dir6_i; \
  assign load.dir7_i = driver.dir7_i; \
  assign load.dir8_i = driver.dir8_i; \
  assign load.dir9_i = driver.dir9_i; \
  assign load.dir10_i = driver.dir10_i; \
  assign load.dir11_i = driver.dir11_i; \
  assign load.dir12_i = driver.dir12_i; \
  assign load.dir13_i = driver.dir13_i; \
  assign load.dir14_i = driver.dir14_i; \
  assign load.dir15_i = driver.dir15_i; \
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


