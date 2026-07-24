

#ifndef MODULAR_PADFRAME_H
#define MODULAR_PADFRAME_H
#include <stdint.h>

#ifndef MODULAR_PADFRAME_BASE_ADDRESS
#error "MODULAR_PADFRAME_BASE_ADDRESS is not defined. Set this token to the configuration base address of your padframe before you include this header file."
#endif



/**
 * Sets the chip2pad pad signal for the pad: pad_io00
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io00_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io00
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io00_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io00
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io00_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io00
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io00_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO00_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO00_group_GPIO_port_GPIO00 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO00_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO00_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO00_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO00_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO00_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO00_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO00_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO00_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO00_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO00_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO00_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO00_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO00_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io00_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io00.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io00_mux_set(modular_padframe_domain_pad_io00_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io00.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io00_mux_sel_t modular_padframe_domain_pad_io00_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io01
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io01_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io01
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io01_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io01
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io01_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io01
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io01_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO01_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO01_group_GPIO_port_GPIO01 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO01_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO01_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO01_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO01_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO01_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO01_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO01_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO01_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO01_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO01_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO01_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO01_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO01_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io01_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io01.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io01_mux_set(modular_padframe_domain_pad_io01_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io01.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io01_mux_sel_t modular_padframe_domain_pad_io01_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io02
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io02_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io02
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io02_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io02
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io02_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io02
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io02_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO02_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO02_group_GPIO_port_GPIO02 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO02_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO02_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO02_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO02_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO02_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO02_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO02_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO02_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO02_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO02_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO02_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO02_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO02_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io02_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io02.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io02_mux_set(modular_padframe_domain_pad_io02_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io02.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io02_mux_sel_t modular_padframe_domain_pad_io02_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io03
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io03_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io03
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io03_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io03
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io03_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io03
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io03_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO03_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO03_group_GPIO_port_GPIO03 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO03_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO03_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO03_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO03_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO03_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO03_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO03_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO03_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO03_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO03_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO03_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO03_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO03_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io03_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io03.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io03_mux_set(modular_padframe_domain_pad_io03_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io03.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io03_mux_sel_t modular_padframe_domain_pad_io03_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io04
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io04_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io04
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io04_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io04
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io04_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io04
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io04_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO04_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO04_group_GPIO_port_GPIO04 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO04_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO04_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO04_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO04_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO04_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO04_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO04_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO04_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO04_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO04_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO04_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO04_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO04_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io04_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io04.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io04_mux_set(modular_padframe_domain_pad_io04_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io04.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io04_mux_sel_t modular_padframe_domain_pad_io04_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io05
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io05_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io05
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io05_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io05
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io05_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io05
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io05_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO05_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO05_group_GPIO_port_GPIO05 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO05_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO05_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO05_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO05_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO05_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO05_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO05_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO05_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO05_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO05_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO05_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO05_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO05_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io05_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io05.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io05_mux_set(modular_padframe_domain_pad_io05_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io05.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io05_mux_sel_t modular_padframe_domain_pad_io05_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io06
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io06_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io06
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io06_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io06
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io06_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io06
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io06_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO06_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO06_group_GPIO_port_GPIO06 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO06_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO06_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO06_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO06_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO06_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO06_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO06_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO06_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO06_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO06_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO06_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO06_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO06_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io06_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io06.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io06_mux_set(modular_padframe_domain_pad_io06_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io06.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io06_mux_sel_t modular_padframe_domain_pad_io06_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io07
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io07_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io07
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io07_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io07
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io07_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io07
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io07_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO07_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO07_group_GPIO_port_GPIO07 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO07_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO07_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO07_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO07_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO07_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO07_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO07_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO07_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO07_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO07_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO07_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO07_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO07_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io07_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io07.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io07_mux_set(modular_padframe_domain_pad_io07_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io07.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io07_mux_sel_t modular_padframe_domain_pad_io07_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io08
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io08_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io08
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io08_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io08
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io08_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io08
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io08_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO08_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO08_group_GPIO_port_GPIO08 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO08_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO08_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO08_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO08_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO08_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO08_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO08_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO08_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO08_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO08_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO08_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO08_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO08_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io08_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io08.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io08_mux_set(modular_padframe_domain_pad_io08_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io08.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io08_mux_sel_t modular_padframe_domain_pad_io08_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io09
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io09_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io09
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io09_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io09
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io09_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io09
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io09_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO09_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO09_group_GPIO_port_GPIO09 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO09_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO09_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO09_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO09_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO09_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO09_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO09_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO09_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO09_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO09_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO09_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO09_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO09_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io09_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io09.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io09_mux_set(modular_padframe_domain_pad_io09_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io09.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io09_mux_sel_t modular_padframe_domain_pad_io09_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io10_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io10
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io10_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io10_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io10
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io10_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO10_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO10_group_GPIO_port_GPIO10 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO10_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO10_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO10_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO10_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO10_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO10_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO10_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO10_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO10_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO10_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO10_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO10_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO10_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io10_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io10.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io10_mux_set(modular_padframe_domain_pad_io10_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io10.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io10_mux_sel_t modular_padframe_domain_pad_io10_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io11_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io11
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io11_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io11_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io11
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io11_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO11_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO11_group_GPIO_port_GPIO11 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO11_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO11_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO11_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO11_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO11_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO11_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO11_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO11_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO11_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO11_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO11_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO11_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO11_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io11_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io11.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io11_mux_set(modular_padframe_domain_pad_io11_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io11.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io11_mux_sel_t modular_padframe_domain_pad_io11_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io12_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io12
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io12_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io12_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io12
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io12_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO12_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO12_group_GPIO_port_GPIO12 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO12_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO12_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO12_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO12_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO12_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO12_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO12_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO12_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO12_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO12_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO12_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO12_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO12_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io12_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io12.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io12_mux_set(modular_padframe_domain_pad_io12_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io12.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io12_mux_sel_t modular_padframe_domain_pad_io12_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io13_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io13
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io13_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io13_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io13
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io13_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO13_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO13_group_GPIO_port_GPIO13 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO13_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO13_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO13_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO13_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO13_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO13_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO13_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO13_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO13_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO13_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO13_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO13_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO13_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io13_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io13.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io13_mux_set(modular_padframe_domain_pad_io13_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io13.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io13_mux_sel_t modular_padframe_domain_pad_io13_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io14_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io14
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io14_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io14_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io14
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io14_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO14_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO14_group_GPIO_port_GPIO14 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO14_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO14_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO14_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO14_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO14_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO14_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO14_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO14_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO14_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO14_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO14_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO14_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO14_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io14_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io14.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io14_mux_set(modular_padframe_domain_pad_io14_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io14.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io14_mux_sel_t modular_padframe_domain_pad_io14_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io15_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io15
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io15_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io15_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io15
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io15_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO15_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO15_group_GPIO_port_GPIO15 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO15_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO15_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO15_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO15_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO15_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO15_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO15_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO15_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO15_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO15_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO15_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO15_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO15_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io15_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io15.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io15_mux_set(modular_padframe_domain_pad_io15_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io15.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io15_mux_sel_t modular_padframe_domain_pad_io15_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io16
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io16_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io16
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io16_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io16
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io16_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io16
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io16_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO16_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO16_group_GPIO_port_GPIO16 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO16_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO16_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO16_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO16_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO16_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO16_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO16_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO16_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO16_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO16_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO16_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO16_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO16_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io16_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io16.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io16_mux_set(modular_padframe_domain_pad_io16_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io16.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io16_mux_sel_t modular_padframe_domain_pad_io16_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io17
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io17_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io17
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io17_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io17
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io17_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io17
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io17_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO17_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO17_group_GPIO_port_GPIO17 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO17_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO17_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO17_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO17_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO17_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO17_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO17_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO17_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO17_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO17_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO17_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO17_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO17_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io17_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io17.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io17_mux_set(modular_padframe_domain_pad_io17_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io17.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io17_mux_sel_t modular_padframe_domain_pad_io17_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io18
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io18_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io18
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io18_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io18
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io18_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io18
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io18_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO18_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO18_group_GPIO_port_GPIO18 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO18_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO18_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO18_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO18_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO18_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO18_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO18_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO18_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO18_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO18_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO18_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO18_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO18_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io18_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io18.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io18_mux_set(modular_padframe_domain_pad_io18_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io18.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io18_mux_sel_t modular_padframe_domain_pad_io18_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io19
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io19_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io19
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io19_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io19
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io19_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io19
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io19_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO19_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO19_group_GPIO_port_GPIO19 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO19_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO19_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO19_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO19_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO19_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO19_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO19_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO19_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO19_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO19_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO19_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO19_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO19_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io19_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io19.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io19_mux_set(modular_padframe_domain_pad_io19_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io19.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io19_mux_sel_t modular_padframe_domain_pad_io19_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io20
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io20_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io20
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io20_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io20
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io20_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io20
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io20_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO20_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO20_group_GPIO_port_GPIO20 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO20_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO20_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO20_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO20_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO20_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO20_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO20_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO20_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO20_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO20_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO20_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO20_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO20_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io20_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io20.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io20_mux_set(modular_padframe_domain_pad_io20_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io20.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io20_mux_sel_t modular_padframe_domain_pad_io20_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io21
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io21_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io21
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io21_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io21
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io21_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io21
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io21_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO21_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO21_group_GPIO_port_GPIO21 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO21_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO21_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO21_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO21_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO21_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO21_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO21_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO21_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO21_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO21_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO21_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO21_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO21_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io21_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io21.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io21_mux_set(modular_padframe_domain_pad_io21_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io21.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io21_mux_sel_t modular_padframe_domain_pad_io21_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io22
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io22_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io22
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io22_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io22
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io22_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io22
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io22_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO22_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO22_group_GPIO_port_GPIO22 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO22_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO22_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO22_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO22_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO22_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO22_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO22_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO22_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO22_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO22_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO22_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO22_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO22_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io22_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io22.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io22_mux_set(modular_padframe_domain_pad_io22_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io22.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io22_mux_sel_t modular_padframe_domain_pad_io22_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io23
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io23_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io23
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io23_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io23
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io23_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io23
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io23_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO23_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO23_group_GPIO_port_GPIO23 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO23_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO23_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO23_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO23_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO23_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO23_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO23_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO23_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO23_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO23_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO23_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO23_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO23_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io23_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io23.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io23_mux_set(modular_padframe_domain_pad_io23_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io23.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io23_mux_sel_t modular_padframe_domain_pad_io23_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io24
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io24_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io24
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io24_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io24
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io24_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io24
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io24_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO24_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO24_group_GPIO_port_GPIO24 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO24_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO24_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO24_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO24_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO24_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO24_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO24_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO24_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO24_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO24_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO24_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO24_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO24_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io24_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io24.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io24_mux_set(modular_padframe_domain_pad_io24_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io24.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io24_mux_sel_t modular_padframe_domain_pad_io24_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io25
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io25_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io25
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io25_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io25
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io25_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io25
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io25_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO25_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO25_group_GPIO_port_GPIO25 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO25_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO25_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO25_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO25_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO25_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO25_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO25_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO25_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO25_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO25_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO25_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO25_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO25_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io25_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io25.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io25_mux_set(modular_padframe_domain_pad_io25_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io25.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io25_mux_sel_t modular_padframe_domain_pad_io25_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io26
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io26_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io26
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io26_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io26
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io26_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io26
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io26_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO26_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO26_group_GPIO_port_GPIO26 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO26_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO26_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO26_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO26_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO26_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO26_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO26_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO26_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO26_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO26_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO26_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO26_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO26_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io26_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io26.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io26_mux_set(modular_padframe_domain_pad_io26_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io26.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io26_mux_sel_t modular_padframe_domain_pad_io26_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io27
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io27_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io27
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io27_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io27
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io27_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io27
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io27_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO27_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO27_group_GPIO_port_GPIO27 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO27_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO27_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO27_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO27_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO27_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO27_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO27_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO27_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO27_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO27_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO27_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO27_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO27_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io27_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io27.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io27_mux_set(modular_padframe_domain_pad_io27_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io27.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io27_mux_sel_t modular_padframe_domain_pad_io27_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io28
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io28_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io28
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io28_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io28
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io28_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io28
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io28_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO28_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO28_group_GPIO_port_GPIO28 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO28_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO28_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO28_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO28_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO28_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO28_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO28_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO28_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO28_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO28_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO28_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO28_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO28_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io28_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io28.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io28_mux_set(modular_padframe_domain_pad_io28_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io28.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io28_mux_sel_t modular_padframe_domain_pad_io28_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io29
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io29_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io29
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io29_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io29
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io29_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io29
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io29_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO29_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO29_group_GPIO_port_GPIO29 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO29_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO29_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO29_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO29_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO29_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO29_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO29_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO29_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO29_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO29_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO29_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO29_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO29_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io29_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io29.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io29_mux_set(modular_padframe_domain_pad_io29_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io29.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io29_mux_sel_t modular_padframe_domain_pad_io29_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io30
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io30_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io30
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io30_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io30
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io30_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io30
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io30_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO30_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO30_group_GPIO_port_GPIO30 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO30_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO30_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO30_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO30_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO30_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO30_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO30_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO30_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO30_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO30_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO30_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO30_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO30_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io30_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io30.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io30_mux_set(modular_padframe_domain_pad_io30_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io30.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io30_mux_sel_t modular_padframe_domain_pad_io30_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io31
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io31_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io31
 *
 * @return The value of the chip2pad field
 */
uint8_t modular_padframe_domain_pad_io31_cfg_chip2pad_get();

/**
 * Sets the tx_en pad signal for the pad: pad_io31
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void modular_padframe_domain_pad_io31_cfg_tx_en_set(uint8_t value);

/**
 * Get the currently configured tx_en value for the pad: pad_io31
 *
 * @return The value of the tx_en field
 */
uint8_t modular_padframe_domain_pad_io31_cfg_tx_en_get();

typedef enum {
  MODULAR_PADFRAME_DOMAIN_PAD_IO31_REGISTER = 0,
  MODULAR_PADFRAME_DOMAIN_PAD_IO31_group_GPIO_port_GPIO31 = 1,
  MODULAR_PADFRAME_DOMAIN_PAD_IO31_group_I2C0_port_SCL = 2,
  MODULAR_PADFRAME_DOMAIN_PAD_IO31_group_I2C0_port_SDA = 3,
  MODULAR_PADFRAME_DOMAIN_PAD_IO31_group_QSPIM0_port_CSN0 = 4,
  MODULAR_PADFRAME_DOMAIN_PAD_IO31_group_QSPIM0_port_CSN1 = 5,
  MODULAR_PADFRAME_DOMAIN_PAD_IO31_group_QSPIM0_port_CSN2 = 6,
  MODULAR_PADFRAME_DOMAIN_PAD_IO31_group_QSPIM0_port_CSN3 = 7,
  MODULAR_PADFRAME_DOMAIN_PAD_IO31_group_QSPIM0_port_SCK = 8,
  MODULAR_PADFRAME_DOMAIN_PAD_IO31_group_QSPIM0_port_SDIO0 = 9,
  MODULAR_PADFRAME_DOMAIN_PAD_IO31_group_QSPIM0_port_SDIO1 = 10,
  MODULAR_PADFRAME_DOMAIN_PAD_IO31_group_QSPIM0_port_SDIO2 = 11,
  MODULAR_PADFRAME_DOMAIN_PAD_IO31_group_QSPIM0_port_SDIO3 = 12,
  MODULAR_PADFRAME_DOMAIN_PAD_IO31_group_UART0_port_RX = 13,
  MODULAR_PADFRAME_DOMAIN_PAD_IO31_group_UART0_port_TX = 14,
} modular_padframe_domain_pad_io31_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io31.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void modular_padframe_domain_pad_io31_mux_set(modular_padframe_domain_pad_io31_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io31.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 modular_padframe_domain_pad_io31_mux_sel_t modular_padframe_domain_pad_io31_mux_get();




#endif /*  MODULAR_PADFRAME_H */
