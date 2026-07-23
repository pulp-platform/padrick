

#ifndef KRAKEN_PADFRAME_H
#define KRAKEN_PADFRAME_H
#include <stdint.h>

#ifndef KRAKEN_PADFRAME_BASE_ADDRESS
#error "KRAKEN_PADFRAME_BASE_ADDRESS is not defined. Set this token to the configuration base address of your padframe before you include this header file."
#endif



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa0_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa0
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa0_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa0_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa0
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa0_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa0_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa0
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa0_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa0_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa0
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa0_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa0_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa0
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa0_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa0_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa0
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa0_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa0_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa0
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa0_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa0_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa0
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa0_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_GPIO_A_port_GPIO0 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA0_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa0_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa0.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa0_mux_set(kraken_padframe_aon_pad_gpioa0_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa0.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa0_mux_sel_t kraken_padframe_aon_pad_gpioa0_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa1_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa1
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa1_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa1_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa1
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa1_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa1_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa1
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa1_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa1_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa1
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa1_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa1_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa1
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa1_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa1_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa1
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa1_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa1_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa1
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa1_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa1_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa1
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa1_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_GPIO_A_port_GPIO1 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA1_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa1_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa1.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa1_mux_set(kraken_padframe_aon_pad_gpioa1_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa1.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa1_mux_sel_t kraken_padframe_aon_pad_gpioa1_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa2_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa2
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa2_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa2_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa2
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa2_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa2_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa2
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa2_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa2_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa2
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa2_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa2_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa2
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa2_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa2_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa2
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa2_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa2_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa2
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa2_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa2_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa2
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa2_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_GPIO_A_port_GPIO2 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA2_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa2_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa2.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa2_mux_set(kraken_padframe_aon_pad_gpioa2_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa2.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa2_mux_sel_t kraken_padframe_aon_pad_gpioa2_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa3_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa3
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa3_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa3_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa3
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa3_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa3_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa3
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa3_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa3_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa3
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa3_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa3_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa3
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa3_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa3_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa3
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa3_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa3_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa3
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa3_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa3_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa3
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa3_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_GPIO_A_port_GPIO3 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA3_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa3_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa3.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa3_mux_set(kraken_padframe_aon_pad_gpioa3_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa3.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa3_mux_sel_t kraken_padframe_aon_pad_gpioa3_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa4_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa4
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa4_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa4_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa4
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa4_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa4_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa4
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa4_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa4_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa4
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa4_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa4_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa4
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa4_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa4_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa4
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa4_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa4_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa4
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa4_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa4_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa4
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa4_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_GPIO_A_port_GPIO4 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA4_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa4_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa4.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa4_mux_set(kraken_padframe_aon_pad_gpioa4_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa4.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa4_mux_sel_t kraken_padframe_aon_pad_gpioa4_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa5_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa5
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa5_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa5_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa5
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa5_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa5_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa5
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa5_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa5_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa5
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa5_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa5_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa5
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa5_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa5_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa5
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa5_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa5_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa5
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa5_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa5_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa5
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa5_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_GPIO_A_port_GPIO5 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA5_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa5_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa5.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa5_mux_set(kraken_padframe_aon_pad_gpioa5_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa5.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa5_mux_sel_t kraken_padframe_aon_pad_gpioa5_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa6_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa6
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa6_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa6_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa6
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa6_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa6_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa6
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa6_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa6_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa6
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa6_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa6_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa6
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa6_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa6_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa6
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa6_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa6_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa6
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa6_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa6_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa6
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa6_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_GPIO_A_port_GPIO6 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA6_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa6_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa6.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa6_mux_set(kraken_padframe_aon_pad_gpioa6_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa6.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa6_mux_sel_t kraken_padframe_aon_pad_gpioa6_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa7_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa7
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa7_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa7_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa7
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa7_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa7_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa7
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa7_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa7_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa7
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa7_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa7_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa7
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa7_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa7_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa7
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa7_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa7_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa7
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa7_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa7_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa7
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa7_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_GPIO_A_port_GPIO7 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA7_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa7_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa7.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa7_mux_set(kraken_padframe_aon_pad_gpioa7_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa7.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa7_mux_sel_t kraken_padframe_aon_pad_gpioa7_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa8_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa8
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa8_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa8_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa8
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa8_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa8_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa8
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa8_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa8_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa8
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa8_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa8_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa8
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa8_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa8_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa8
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa8_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa8_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa8
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa8_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa8_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa8
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa8_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_GPIO_A_port_GPIO8 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA8_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa8_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa8.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa8_mux_set(kraken_padframe_aon_pad_gpioa8_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa8.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa8_mux_sel_t kraken_padframe_aon_pad_gpioa8_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa9_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa9
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa9_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa9_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa9
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa9_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa9_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa9
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa9_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa9_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa9
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa9_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa9_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa9
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa9_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa9_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa9
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa9_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa9_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa9
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa9_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa9_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa9
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa9_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_GPIO_A_port_GPIO9 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA9_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa9_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa9.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa9_mux_set(kraken_padframe_aon_pad_gpioa9_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa9.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa9_mux_sel_t kraken_padframe_aon_pad_gpioa9_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa10_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa10
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa10_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa10_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa10
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa10_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa10_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa10
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa10_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa10_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa10
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa10_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa10_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa10
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa10_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa10_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa10
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa10_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa10_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa10
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa10_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa10_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa10
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa10_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_GPIO_A_port_GPIO10 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA10_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa10_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa10.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa10_mux_set(kraken_padframe_aon_pad_gpioa10_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa10.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa10_mux_sel_t kraken_padframe_aon_pad_gpioa10_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa11_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa11
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa11_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa11_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa11
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa11_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa11_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa11
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa11_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa11_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa11
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa11_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa11_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa11
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa11_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa11_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa11
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa11_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa11_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa11
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa11_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa11_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa11
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa11_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_GPIO_A_port_GPIO11 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA11_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa11_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa11.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa11_mux_set(kraken_padframe_aon_pad_gpioa11_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa11.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa11_mux_sel_t kraken_padframe_aon_pad_gpioa11_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa12_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa12
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa12_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa12_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa12
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa12_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa12_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa12
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa12_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa12_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa12
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa12_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa12_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa12
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa12_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa12_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa12
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa12_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa12_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa12
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa12_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa12_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa12
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa12_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_GPIO_A_port_GPIO12 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA12_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa12_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa12.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa12_mux_set(kraken_padframe_aon_pad_gpioa12_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa12.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa12_mux_sel_t kraken_padframe_aon_pad_gpioa12_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa13_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa13
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa13_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa13_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa13
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa13_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa13_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa13
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa13_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa13_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa13
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa13_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa13_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa13
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa13_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa13_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa13
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa13_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa13_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa13
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa13_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa13_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa13
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa13_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_GPIO_A_port_GPIO13 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA13_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa13_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa13.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa13_mux_set(kraken_padframe_aon_pad_gpioa13_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa13.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa13_mux_sel_t kraken_padframe_aon_pad_gpioa13_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa14_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa14
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa14_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa14_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa14
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa14_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa14_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa14
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa14_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa14_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa14
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa14_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa14_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa14
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa14_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa14_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa14
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa14_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa14_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa14
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa14_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa14_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa14
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa14_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_GPIO_A_port_GPIO14 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA14_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa14_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa14.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa14_mux_set(kraken_padframe_aon_pad_gpioa14_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa14.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa14_mux_sel_t kraken_padframe_aon_pad_gpioa14_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa15_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa15
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa15_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa15_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa15
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa15_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa15_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa15
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa15_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa15_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa15
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa15_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa15_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa15
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa15_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa15_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa15
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa15_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa15_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa15
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa15_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa15_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa15
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa15_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_GPIO_A_port_GPIO15 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA15_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa15_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa15.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa15_mux_set(kraken_padframe_aon_pad_gpioa15_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa15.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa15_mux_sel_t kraken_padframe_aon_pad_gpioa15_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa16
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa16_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa16
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa16_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa16
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa16_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa16
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa16_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa16
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa16_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa16
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa16_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa16
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa16_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa16
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa16_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa16
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa16_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa16
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa16_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa16
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa16_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa16
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa16_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa16
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa16_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa16
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa16_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa16
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa16_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa16
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa16_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_GPIO_A_port_GPIO16 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA16_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa16_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa16.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa16_mux_set(kraken_padframe_aon_pad_gpioa16_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa16.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa16_mux_sel_t kraken_padframe_aon_pad_gpioa16_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa17
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa17_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa17
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa17_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa17
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa17_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa17
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa17_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa17
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa17_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa17
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa17_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa17
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa17_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa17
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa17_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa17
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa17_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa17
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa17_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa17
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa17_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa17
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa17_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa17
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa17_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa17
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa17_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa17
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa17_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa17
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa17_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_GPIO_A_port_GPIO17 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA17_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa17_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa17.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa17_mux_set(kraken_padframe_aon_pad_gpioa17_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa17.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa17_mux_sel_t kraken_padframe_aon_pad_gpioa17_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa18
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa18_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa18
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa18_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa18
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa18_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa18
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa18_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa18
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa18_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa18
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa18_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa18
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa18_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa18
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa18_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa18
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa18_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa18
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa18_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa18
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa18_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa18
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa18_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa18
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa18_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa18
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa18_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa18
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa18_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa18
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa18_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_GPIO_A_port_GPIO18 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA18_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa18_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa18.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa18_mux_set(kraken_padframe_aon_pad_gpioa18_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa18.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa18_mux_sel_t kraken_padframe_aon_pad_gpioa18_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa19
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa19_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa19
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa19_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa19
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa19_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa19
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa19_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa19
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa19_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa19
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa19_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa19
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa19_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa19
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa19_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa19
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa19_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa19
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa19_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa19
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa19_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa19
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa19_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa19
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa19_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa19
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa19_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa19
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa19_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa19
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa19_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_GPIO_A_port_GPIO19 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA19_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa19_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa19.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa19_mux_set(kraken_padframe_aon_pad_gpioa19_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa19.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa19_mux_sel_t kraken_padframe_aon_pad_gpioa19_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa20
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa20_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa20
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa20_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa20
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa20_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa20
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa20_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa20
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa20_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa20
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa20_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa20
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa20_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa20
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa20_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa20
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa20_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa20
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa20_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa20
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa20_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa20
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa20_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa20
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa20_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa20
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa20_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa20
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa20_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa20
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa20_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_GPIO_A_port_GPIO20 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA20_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa20_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa20.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa20_mux_set(kraken_padframe_aon_pad_gpioa20_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa20.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa20_mux_sel_t kraken_padframe_aon_pad_gpioa20_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa21
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa21_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa21
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa21_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa21
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa21_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa21
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa21_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa21
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa21_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa21
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa21_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa21
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa21_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa21
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa21_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa21
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa21_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa21
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa21_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa21
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa21_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa21
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa21_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa21
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa21_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa21
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa21_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa21
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa21_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa21
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa21_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_GPIO_A_port_GPIO21 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA21_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa21_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa21.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa21_mux_set(kraken_padframe_aon_pad_gpioa21_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa21.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa21_mux_sel_t kraken_padframe_aon_pad_gpioa21_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa22
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa22_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa22
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa22_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa22
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa22_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa22
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa22_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa22
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa22_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa22
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa22_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa22
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa22_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa22
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa22_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa22
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa22_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa22
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa22_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa22
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa22_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa22
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa22_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa22
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa22_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa22
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa22_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa22
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa22_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa22
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa22_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_GPIO_A_port_GPIO22 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA22_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa22_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa22.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa22_mux_set(kraken_padframe_aon_pad_gpioa22_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa22.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa22_mux_sel_t kraken_padframe_aon_pad_gpioa22_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa23
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa23_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa23
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa23_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa23
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa23_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa23
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa23_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa23
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa23_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa23
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa23_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa23
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa23_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa23
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa23_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa23
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa23_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa23
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa23_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa23
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa23_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa23
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa23_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa23
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa23_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa23
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa23_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa23
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa23_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa23
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa23_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_GPIO_A_port_GPIO23 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA23_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa23_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa23.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa23_mux_set(kraken_padframe_aon_pad_gpioa23_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa23.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa23_mux_sel_t kraken_padframe_aon_pad_gpioa23_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa24
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa24_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa24
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa24_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa24
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa24_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa24
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa24_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa24
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa24_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa24
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa24_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa24
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa24_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa24
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa24_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa24
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa24_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa24
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa24_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa24
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa24_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa24
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa24_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa24
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa24_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa24
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa24_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa24
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa24_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa24
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa24_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_GPIO_A_port_GPIO24 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA24_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa24_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa24.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa24_mux_set(kraken_padframe_aon_pad_gpioa24_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa24.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa24_mux_sel_t kraken_padframe_aon_pad_gpioa24_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa25
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa25_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa25
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpioa25_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpioa25
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpioa25_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpioa25
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpioa25_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpioa25
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa25_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpioa25
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpioa25_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpioa25
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa25_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpioa25
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpioa25_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpioa25
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa25_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpioa25
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpioa25_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpioa25
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa25_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpioa25
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpioa25_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpioa25
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa25_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpioa25
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpioa25_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpioa25
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpioa25_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpioa25
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpioa25_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_ARE = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_ASA = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_ASY = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_CFG0 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_CFG1 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_CFG2 = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_CFG3 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_CFG4 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_CFG5 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_CFG6 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_CFG7 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_OFF0 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_OFF1 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_OFF2 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_OFF3 = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_ON0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_ON1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_ON2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_ON3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_SXY = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_XCLK = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_XNRST = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_XYDATA0 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_XYDATA1 = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_XYDATA2 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_XYDATA3 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_XYDATA4 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_XYDATA5 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_XYDATA6 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_XYDATA7 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_YCLK = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_DVSI0_port_YNRST = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_GPIO_A_port_GPIO25 = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_I2C0_port_I2C_SCL = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_I2C0_port_I2C_SDA = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_I2C1_port_I2C_SCL = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_I2C1_port_I2C_SDA = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_I2C2_port_I2C_SCL = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_I2C2_port_I2C_SDA = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_I2C3_port_I2C_SCL = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_I2C3_port_I2C_SDA = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_UART0_port_RX = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_UART0_port_TX = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_UART1_port_RX = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOA25_group_UART1_port_TX = 45,
} kraken_padframe_aon_pad_gpioa25_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa25.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpioa25_mux_set(kraken_padframe_aon_pad_gpioa25_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa25.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpioa25_mux_sel_t kraken_padframe_aon_pad_gpioa25_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob0_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob0
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpiob0_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpiob0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpiob0_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpiob0
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpiob0_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpiob0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob0_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpiob0
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpiob0_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpiob0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob0_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpiob0
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpiob0_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpiob0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob0_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpiob0
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpiob0_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpiob0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob0_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpiob0
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpiob0_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpiob0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob0_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpiob0
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpiob0_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpiob0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob0_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpiob0
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpiob0_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_GPIO_B_port_GPIO0 = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI0_port_SPI_CSN0 = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI0_port_SPI_CSN1 = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI0_port_SPI_CSN2 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI0_port_SPI_CSN3 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI0_port_SPI_SCK = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI0_port_SPI_SDIO0 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI0_port_SPI_SDIO1 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI0_port_SPI_SDIO2 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI0_port_SPI_SDIO3 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI1_port_SPI_CSN0 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI1_port_SPI_CSN1 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI1_port_SPI_CSN2 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI1_port_SPI_CSN3 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI1_port_SPI_SCK = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI1_port_SPI_SDIO0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI1_port_SPI_SDIO1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI1_port_SPI_SDIO2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI1_port_SPI_SDIO3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI2_port_SPI_CSN0 = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI2_port_SPI_CSN1 = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI2_port_SPI_CSN2 = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI2_port_SPI_CSN3 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI2_port_SPI_SCK = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI2_port_SPI_SDIO0 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI2_port_SPI_SDIO1 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI2_port_SPI_SDIO2 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI2_port_SPI_SDIO3 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI3_port_SPI_CSN0 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI3_port_SPI_CSN1 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI3_port_SPI_CSN2 = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI3_port_SPI_CSN3 = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI3_port_SPI_SCK = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI3_port_SPI_SDIO0 = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI3_port_SPI_SDIO1 = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI3_port_SPI_SDIO2 = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_QSPI3_port_SPI_SDIO3 = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_TIMER0_port_OUT0 = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_TIMER0_port_OUT1 = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_TIMER0_port_OUT2 = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_TIMER0_port_OUT3 = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_TIMER1_port_OUT0 = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_TIMER1_port_OUT1 = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_TIMER1_port_OUT2 = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_TIMER1_port_OUT3 = 45,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_TIMER2_port_OUT0 = 46,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_TIMER2_port_OUT1 = 47,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_TIMER2_port_OUT2 = 48,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_TIMER2_port_OUT3 = 49,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_TIMER3_port_OUT0 = 50,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_TIMER3_port_OUT1 = 51,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_TIMER3_port_OUT2 = 52,
  KRAKEN_PADFRAME_AON_PAD_GPIOB0_group_TIMER3_port_OUT3 = 53,
} kraken_padframe_aon_pad_gpiob0_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob0.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpiob0_mux_set(kraken_padframe_aon_pad_gpiob0_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob0.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpiob0_mux_sel_t kraken_padframe_aon_pad_gpiob0_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob1_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob1
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpiob1_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpiob1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpiob1_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpiob1
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpiob1_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpiob1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob1_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpiob1
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpiob1_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpiob1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob1_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpiob1
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpiob1_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpiob1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob1_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpiob1
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpiob1_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpiob1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob1_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpiob1
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpiob1_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpiob1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob1_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpiob1
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpiob1_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpiob1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob1_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpiob1
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpiob1_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_GPIO_B_port_GPIO1 = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI0_port_SPI_CSN0 = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI0_port_SPI_CSN1 = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI0_port_SPI_CSN2 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI0_port_SPI_CSN3 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI0_port_SPI_SCK = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI0_port_SPI_SDIO0 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI0_port_SPI_SDIO1 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI0_port_SPI_SDIO2 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI0_port_SPI_SDIO3 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI1_port_SPI_CSN0 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI1_port_SPI_CSN1 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI1_port_SPI_CSN2 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI1_port_SPI_CSN3 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI1_port_SPI_SCK = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI1_port_SPI_SDIO0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI1_port_SPI_SDIO1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI1_port_SPI_SDIO2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI1_port_SPI_SDIO3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI2_port_SPI_CSN0 = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI2_port_SPI_CSN1 = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI2_port_SPI_CSN2 = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI2_port_SPI_CSN3 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI2_port_SPI_SCK = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI2_port_SPI_SDIO0 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI2_port_SPI_SDIO1 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI2_port_SPI_SDIO2 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI2_port_SPI_SDIO3 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI3_port_SPI_CSN0 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI3_port_SPI_CSN1 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI3_port_SPI_CSN2 = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI3_port_SPI_CSN3 = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI3_port_SPI_SCK = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI3_port_SPI_SDIO0 = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI3_port_SPI_SDIO1 = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI3_port_SPI_SDIO2 = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_QSPI3_port_SPI_SDIO3 = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_TIMER0_port_OUT0 = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_TIMER0_port_OUT1 = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_TIMER0_port_OUT2 = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_TIMER0_port_OUT3 = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_TIMER1_port_OUT0 = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_TIMER1_port_OUT1 = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_TIMER1_port_OUT2 = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_TIMER1_port_OUT3 = 45,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_TIMER2_port_OUT0 = 46,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_TIMER2_port_OUT1 = 47,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_TIMER2_port_OUT2 = 48,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_TIMER2_port_OUT3 = 49,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_TIMER3_port_OUT0 = 50,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_TIMER3_port_OUT1 = 51,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_TIMER3_port_OUT2 = 52,
  KRAKEN_PADFRAME_AON_PAD_GPIOB1_group_TIMER3_port_OUT3 = 53,
} kraken_padframe_aon_pad_gpiob1_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob1.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpiob1_mux_set(kraken_padframe_aon_pad_gpiob1_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob1.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpiob1_mux_sel_t kraken_padframe_aon_pad_gpiob1_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob2_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob2
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpiob2_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpiob2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpiob2_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpiob2
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpiob2_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpiob2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob2_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpiob2
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpiob2_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpiob2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob2_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpiob2
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpiob2_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpiob2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob2_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpiob2
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpiob2_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpiob2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob2_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpiob2
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpiob2_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpiob2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob2_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpiob2
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpiob2_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpiob2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob2_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpiob2
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpiob2_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_GPIO_B_port_GPIO2 = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI0_port_SPI_CSN0 = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI0_port_SPI_CSN1 = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI0_port_SPI_CSN2 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI0_port_SPI_CSN3 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI0_port_SPI_SCK = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI0_port_SPI_SDIO0 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI0_port_SPI_SDIO1 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI0_port_SPI_SDIO2 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI0_port_SPI_SDIO3 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI1_port_SPI_CSN0 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI1_port_SPI_CSN1 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI1_port_SPI_CSN2 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI1_port_SPI_CSN3 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI1_port_SPI_SCK = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI1_port_SPI_SDIO0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI1_port_SPI_SDIO1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI1_port_SPI_SDIO2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI1_port_SPI_SDIO3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI2_port_SPI_CSN0 = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI2_port_SPI_CSN1 = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI2_port_SPI_CSN2 = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI2_port_SPI_CSN3 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI2_port_SPI_SCK = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI2_port_SPI_SDIO0 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI2_port_SPI_SDIO1 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI2_port_SPI_SDIO2 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI2_port_SPI_SDIO3 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI3_port_SPI_CSN0 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI3_port_SPI_CSN1 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI3_port_SPI_CSN2 = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI3_port_SPI_CSN3 = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI3_port_SPI_SCK = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI3_port_SPI_SDIO0 = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI3_port_SPI_SDIO1 = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI3_port_SPI_SDIO2 = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_QSPI3_port_SPI_SDIO3 = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_TIMER0_port_OUT0 = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_TIMER0_port_OUT1 = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_TIMER0_port_OUT2 = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_TIMER0_port_OUT3 = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_TIMER1_port_OUT0 = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_TIMER1_port_OUT1 = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_TIMER1_port_OUT2 = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_TIMER1_port_OUT3 = 45,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_TIMER2_port_OUT0 = 46,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_TIMER2_port_OUT1 = 47,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_TIMER2_port_OUT2 = 48,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_TIMER2_port_OUT3 = 49,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_TIMER3_port_OUT0 = 50,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_TIMER3_port_OUT1 = 51,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_TIMER3_port_OUT2 = 52,
  KRAKEN_PADFRAME_AON_PAD_GPIOB2_group_TIMER3_port_OUT3 = 53,
} kraken_padframe_aon_pad_gpiob2_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob2.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpiob2_mux_set(kraken_padframe_aon_pad_gpiob2_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob2.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpiob2_mux_sel_t kraken_padframe_aon_pad_gpiob2_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob3_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob3
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpiob3_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpiob3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpiob3_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpiob3
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpiob3_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpiob3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob3_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpiob3
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpiob3_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpiob3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob3_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpiob3
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpiob3_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpiob3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob3_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpiob3
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpiob3_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpiob3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob3_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpiob3
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpiob3_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpiob3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob3_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpiob3
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpiob3_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpiob3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob3_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpiob3
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpiob3_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_GPIO_B_port_GPIO3 = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI0_port_SPI_CSN0 = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI0_port_SPI_CSN1 = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI0_port_SPI_CSN2 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI0_port_SPI_CSN3 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI0_port_SPI_SCK = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI0_port_SPI_SDIO0 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI0_port_SPI_SDIO1 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI0_port_SPI_SDIO2 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI0_port_SPI_SDIO3 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI1_port_SPI_CSN0 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI1_port_SPI_CSN1 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI1_port_SPI_CSN2 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI1_port_SPI_CSN3 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI1_port_SPI_SCK = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI1_port_SPI_SDIO0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI1_port_SPI_SDIO1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI1_port_SPI_SDIO2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI1_port_SPI_SDIO3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI2_port_SPI_CSN0 = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI2_port_SPI_CSN1 = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI2_port_SPI_CSN2 = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI2_port_SPI_CSN3 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI2_port_SPI_SCK = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI2_port_SPI_SDIO0 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI2_port_SPI_SDIO1 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI2_port_SPI_SDIO2 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI2_port_SPI_SDIO3 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI3_port_SPI_CSN0 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI3_port_SPI_CSN1 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI3_port_SPI_CSN2 = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI3_port_SPI_CSN3 = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI3_port_SPI_SCK = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI3_port_SPI_SDIO0 = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI3_port_SPI_SDIO1 = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI3_port_SPI_SDIO2 = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_QSPI3_port_SPI_SDIO3 = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_TIMER0_port_OUT0 = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_TIMER0_port_OUT1 = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_TIMER0_port_OUT2 = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_TIMER0_port_OUT3 = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_TIMER1_port_OUT0 = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_TIMER1_port_OUT1 = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_TIMER1_port_OUT2 = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_TIMER1_port_OUT3 = 45,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_TIMER2_port_OUT0 = 46,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_TIMER2_port_OUT1 = 47,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_TIMER2_port_OUT2 = 48,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_TIMER2_port_OUT3 = 49,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_TIMER3_port_OUT0 = 50,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_TIMER3_port_OUT1 = 51,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_TIMER3_port_OUT2 = 52,
  KRAKEN_PADFRAME_AON_PAD_GPIOB3_group_TIMER3_port_OUT3 = 53,
} kraken_padframe_aon_pad_gpiob3_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob3.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpiob3_mux_set(kraken_padframe_aon_pad_gpiob3_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob3.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpiob3_mux_sel_t kraken_padframe_aon_pad_gpiob3_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob4_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob4
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpiob4_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpiob4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpiob4_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpiob4
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpiob4_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpiob4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob4_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpiob4
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpiob4_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpiob4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob4_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpiob4
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpiob4_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpiob4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob4_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpiob4
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpiob4_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpiob4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob4_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpiob4
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpiob4_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpiob4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob4_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpiob4
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpiob4_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpiob4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob4_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpiob4
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpiob4_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_GPIO_B_port_GPIO4 = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI0_port_SPI_CSN0 = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI0_port_SPI_CSN1 = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI0_port_SPI_CSN2 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI0_port_SPI_CSN3 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI0_port_SPI_SCK = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI0_port_SPI_SDIO0 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI0_port_SPI_SDIO1 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI0_port_SPI_SDIO2 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI0_port_SPI_SDIO3 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI1_port_SPI_CSN0 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI1_port_SPI_CSN1 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI1_port_SPI_CSN2 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI1_port_SPI_CSN3 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI1_port_SPI_SCK = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI1_port_SPI_SDIO0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI1_port_SPI_SDIO1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI1_port_SPI_SDIO2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI1_port_SPI_SDIO3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI2_port_SPI_CSN0 = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI2_port_SPI_CSN1 = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI2_port_SPI_CSN2 = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI2_port_SPI_CSN3 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI2_port_SPI_SCK = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI2_port_SPI_SDIO0 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI2_port_SPI_SDIO1 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI2_port_SPI_SDIO2 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI2_port_SPI_SDIO3 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI3_port_SPI_CSN0 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI3_port_SPI_CSN1 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI3_port_SPI_CSN2 = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI3_port_SPI_CSN3 = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI3_port_SPI_SCK = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI3_port_SPI_SDIO0 = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI3_port_SPI_SDIO1 = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI3_port_SPI_SDIO2 = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_QSPI3_port_SPI_SDIO3 = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_TIMER0_port_OUT0 = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_TIMER0_port_OUT1 = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_TIMER0_port_OUT2 = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_TIMER0_port_OUT3 = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_TIMER1_port_OUT0 = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_TIMER1_port_OUT1 = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_TIMER1_port_OUT2 = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_TIMER1_port_OUT3 = 45,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_TIMER2_port_OUT0 = 46,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_TIMER2_port_OUT1 = 47,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_TIMER2_port_OUT2 = 48,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_TIMER2_port_OUT3 = 49,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_TIMER3_port_OUT0 = 50,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_TIMER3_port_OUT1 = 51,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_TIMER3_port_OUT2 = 52,
  KRAKEN_PADFRAME_AON_PAD_GPIOB4_group_TIMER3_port_OUT3 = 53,
} kraken_padframe_aon_pad_gpiob4_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob4.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpiob4_mux_set(kraken_padframe_aon_pad_gpiob4_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob4.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpiob4_mux_sel_t kraken_padframe_aon_pad_gpiob4_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob5_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob5
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpiob5_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpiob5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpiob5_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpiob5
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpiob5_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpiob5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob5_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpiob5
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpiob5_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpiob5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob5_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpiob5
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpiob5_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpiob5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob5_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpiob5
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpiob5_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpiob5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob5_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpiob5
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpiob5_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpiob5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob5_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpiob5
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpiob5_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpiob5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob5_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpiob5
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpiob5_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_GPIO_B_port_GPIO5 = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI0_port_SPI_CSN0 = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI0_port_SPI_CSN1 = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI0_port_SPI_CSN2 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI0_port_SPI_CSN3 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI0_port_SPI_SCK = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI0_port_SPI_SDIO0 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI0_port_SPI_SDIO1 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI0_port_SPI_SDIO2 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI0_port_SPI_SDIO3 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI1_port_SPI_CSN0 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI1_port_SPI_CSN1 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI1_port_SPI_CSN2 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI1_port_SPI_CSN3 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI1_port_SPI_SCK = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI1_port_SPI_SDIO0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI1_port_SPI_SDIO1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI1_port_SPI_SDIO2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI1_port_SPI_SDIO3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI2_port_SPI_CSN0 = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI2_port_SPI_CSN1 = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI2_port_SPI_CSN2 = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI2_port_SPI_CSN3 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI2_port_SPI_SCK = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI2_port_SPI_SDIO0 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI2_port_SPI_SDIO1 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI2_port_SPI_SDIO2 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI2_port_SPI_SDIO3 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI3_port_SPI_CSN0 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI3_port_SPI_CSN1 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI3_port_SPI_CSN2 = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI3_port_SPI_CSN3 = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI3_port_SPI_SCK = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI3_port_SPI_SDIO0 = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI3_port_SPI_SDIO1 = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI3_port_SPI_SDIO2 = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_QSPI3_port_SPI_SDIO3 = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_TIMER0_port_OUT0 = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_TIMER0_port_OUT1 = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_TIMER0_port_OUT2 = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_TIMER0_port_OUT3 = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_TIMER1_port_OUT0 = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_TIMER1_port_OUT1 = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_TIMER1_port_OUT2 = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_TIMER1_port_OUT3 = 45,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_TIMER2_port_OUT0 = 46,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_TIMER2_port_OUT1 = 47,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_TIMER2_port_OUT2 = 48,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_TIMER2_port_OUT3 = 49,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_TIMER3_port_OUT0 = 50,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_TIMER3_port_OUT1 = 51,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_TIMER3_port_OUT2 = 52,
  KRAKEN_PADFRAME_AON_PAD_GPIOB5_group_TIMER3_port_OUT3 = 53,
} kraken_padframe_aon_pad_gpiob5_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob5.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpiob5_mux_set(kraken_padframe_aon_pad_gpiob5_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob5.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpiob5_mux_sel_t kraken_padframe_aon_pad_gpiob5_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob6_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob6
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpiob6_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpiob6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpiob6_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpiob6
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpiob6_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpiob6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob6_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpiob6
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpiob6_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpiob6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob6_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpiob6
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpiob6_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpiob6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob6_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpiob6
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpiob6_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpiob6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob6_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpiob6
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpiob6_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpiob6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob6_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpiob6
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpiob6_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpiob6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob6_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpiob6
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpiob6_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_GPIO_B_port_GPIO6 = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI0_port_SPI_CSN0 = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI0_port_SPI_CSN1 = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI0_port_SPI_CSN2 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI0_port_SPI_CSN3 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI0_port_SPI_SCK = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI0_port_SPI_SDIO0 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI0_port_SPI_SDIO1 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI0_port_SPI_SDIO2 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI0_port_SPI_SDIO3 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI1_port_SPI_CSN0 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI1_port_SPI_CSN1 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI1_port_SPI_CSN2 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI1_port_SPI_CSN3 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI1_port_SPI_SCK = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI1_port_SPI_SDIO0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI1_port_SPI_SDIO1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI1_port_SPI_SDIO2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI1_port_SPI_SDIO3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI2_port_SPI_CSN0 = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI2_port_SPI_CSN1 = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI2_port_SPI_CSN2 = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI2_port_SPI_CSN3 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI2_port_SPI_SCK = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI2_port_SPI_SDIO0 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI2_port_SPI_SDIO1 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI2_port_SPI_SDIO2 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI2_port_SPI_SDIO3 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI3_port_SPI_CSN0 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI3_port_SPI_CSN1 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI3_port_SPI_CSN2 = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI3_port_SPI_CSN3 = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI3_port_SPI_SCK = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI3_port_SPI_SDIO0 = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI3_port_SPI_SDIO1 = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI3_port_SPI_SDIO2 = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_QSPI3_port_SPI_SDIO3 = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_TIMER0_port_OUT0 = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_TIMER0_port_OUT1 = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_TIMER0_port_OUT2 = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_TIMER0_port_OUT3 = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_TIMER1_port_OUT0 = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_TIMER1_port_OUT1 = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_TIMER1_port_OUT2 = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_TIMER1_port_OUT3 = 45,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_TIMER2_port_OUT0 = 46,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_TIMER2_port_OUT1 = 47,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_TIMER2_port_OUT2 = 48,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_TIMER2_port_OUT3 = 49,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_TIMER3_port_OUT0 = 50,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_TIMER3_port_OUT1 = 51,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_TIMER3_port_OUT2 = 52,
  KRAKEN_PADFRAME_AON_PAD_GPIOB6_group_TIMER3_port_OUT3 = 53,
} kraken_padframe_aon_pad_gpiob6_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob6.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpiob6_mux_set(kraken_padframe_aon_pad_gpiob6_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob6.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpiob6_mux_sel_t kraken_padframe_aon_pad_gpiob6_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob7_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob7
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpiob7_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpiob7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpiob7_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpiob7
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpiob7_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpiob7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob7_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpiob7
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpiob7_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpiob7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob7_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpiob7
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpiob7_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpiob7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob7_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpiob7
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpiob7_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpiob7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob7_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpiob7
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpiob7_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpiob7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob7_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpiob7
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpiob7_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpiob7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob7_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpiob7
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpiob7_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_GPIO_B_port_GPIO7 = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI0_port_SPI_CSN0 = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI0_port_SPI_CSN1 = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI0_port_SPI_CSN2 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI0_port_SPI_CSN3 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI0_port_SPI_SCK = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI0_port_SPI_SDIO0 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI0_port_SPI_SDIO1 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI0_port_SPI_SDIO2 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI0_port_SPI_SDIO3 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI1_port_SPI_CSN0 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI1_port_SPI_CSN1 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI1_port_SPI_CSN2 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI1_port_SPI_CSN3 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI1_port_SPI_SCK = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI1_port_SPI_SDIO0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI1_port_SPI_SDIO1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI1_port_SPI_SDIO2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI1_port_SPI_SDIO3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI2_port_SPI_CSN0 = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI2_port_SPI_CSN1 = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI2_port_SPI_CSN2 = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI2_port_SPI_CSN3 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI2_port_SPI_SCK = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI2_port_SPI_SDIO0 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI2_port_SPI_SDIO1 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI2_port_SPI_SDIO2 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI2_port_SPI_SDIO3 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI3_port_SPI_CSN0 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI3_port_SPI_CSN1 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI3_port_SPI_CSN2 = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI3_port_SPI_CSN3 = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI3_port_SPI_SCK = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI3_port_SPI_SDIO0 = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI3_port_SPI_SDIO1 = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI3_port_SPI_SDIO2 = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_QSPI3_port_SPI_SDIO3 = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_TIMER0_port_OUT0 = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_TIMER0_port_OUT1 = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_TIMER0_port_OUT2 = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_TIMER0_port_OUT3 = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_TIMER1_port_OUT0 = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_TIMER1_port_OUT1 = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_TIMER1_port_OUT2 = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_TIMER1_port_OUT3 = 45,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_TIMER2_port_OUT0 = 46,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_TIMER2_port_OUT1 = 47,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_TIMER2_port_OUT2 = 48,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_TIMER2_port_OUT3 = 49,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_TIMER3_port_OUT0 = 50,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_TIMER3_port_OUT1 = 51,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_TIMER3_port_OUT2 = 52,
  KRAKEN_PADFRAME_AON_PAD_GPIOB7_group_TIMER3_port_OUT3 = 53,
} kraken_padframe_aon_pad_gpiob7_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob7.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpiob7_mux_set(kraken_padframe_aon_pad_gpiob7_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob7.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpiob7_mux_sel_t kraken_padframe_aon_pad_gpiob7_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob8_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob8
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpiob8_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpiob8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpiob8_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpiob8
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpiob8_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpiob8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob8_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpiob8
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpiob8_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpiob8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob8_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpiob8
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpiob8_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpiob8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob8_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpiob8
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpiob8_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpiob8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob8_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpiob8
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpiob8_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpiob8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob8_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpiob8
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpiob8_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpiob8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob8_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpiob8
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpiob8_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_GPIO_B_port_GPIO8 = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI0_port_SPI_CSN0 = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI0_port_SPI_CSN1 = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI0_port_SPI_CSN2 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI0_port_SPI_CSN3 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI0_port_SPI_SCK = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI0_port_SPI_SDIO0 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI0_port_SPI_SDIO1 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI0_port_SPI_SDIO2 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI0_port_SPI_SDIO3 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI1_port_SPI_CSN0 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI1_port_SPI_CSN1 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI1_port_SPI_CSN2 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI1_port_SPI_CSN3 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI1_port_SPI_SCK = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI1_port_SPI_SDIO0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI1_port_SPI_SDIO1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI1_port_SPI_SDIO2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI1_port_SPI_SDIO3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI2_port_SPI_CSN0 = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI2_port_SPI_CSN1 = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI2_port_SPI_CSN2 = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI2_port_SPI_CSN3 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI2_port_SPI_SCK = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI2_port_SPI_SDIO0 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI2_port_SPI_SDIO1 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI2_port_SPI_SDIO2 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI2_port_SPI_SDIO3 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI3_port_SPI_CSN0 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI3_port_SPI_CSN1 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI3_port_SPI_CSN2 = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI3_port_SPI_CSN3 = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI3_port_SPI_SCK = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI3_port_SPI_SDIO0 = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI3_port_SPI_SDIO1 = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI3_port_SPI_SDIO2 = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_QSPI3_port_SPI_SDIO3 = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_TIMER0_port_OUT0 = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_TIMER0_port_OUT1 = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_TIMER0_port_OUT2 = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_TIMER0_port_OUT3 = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_TIMER1_port_OUT0 = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_TIMER1_port_OUT1 = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_TIMER1_port_OUT2 = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_TIMER1_port_OUT3 = 45,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_TIMER2_port_OUT0 = 46,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_TIMER2_port_OUT1 = 47,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_TIMER2_port_OUT2 = 48,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_TIMER2_port_OUT3 = 49,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_TIMER3_port_OUT0 = 50,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_TIMER3_port_OUT1 = 51,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_TIMER3_port_OUT2 = 52,
  KRAKEN_PADFRAME_AON_PAD_GPIOB8_group_TIMER3_port_OUT3 = 53,
} kraken_padframe_aon_pad_gpiob8_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob8.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpiob8_mux_set(kraken_padframe_aon_pad_gpiob8_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob8.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpiob8_mux_sel_t kraken_padframe_aon_pad_gpiob8_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob9_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob9
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpiob9_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpiob9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpiob9_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpiob9
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpiob9_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpiob9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob9_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpiob9
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpiob9_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpiob9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob9_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpiob9
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpiob9_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpiob9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob9_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpiob9
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpiob9_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpiob9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob9_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpiob9
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpiob9_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpiob9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob9_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpiob9
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpiob9_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpiob9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob9_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpiob9
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpiob9_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_GPIO_B_port_GPIO9 = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI0_port_SPI_CSN0 = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI0_port_SPI_CSN1 = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI0_port_SPI_CSN2 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI0_port_SPI_CSN3 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI0_port_SPI_SCK = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI0_port_SPI_SDIO0 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI0_port_SPI_SDIO1 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI0_port_SPI_SDIO2 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI0_port_SPI_SDIO3 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI1_port_SPI_CSN0 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI1_port_SPI_CSN1 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI1_port_SPI_CSN2 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI1_port_SPI_CSN3 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI1_port_SPI_SCK = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI1_port_SPI_SDIO0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI1_port_SPI_SDIO1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI1_port_SPI_SDIO2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI1_port_SPI_SDIO3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI2_port_SPI_CSN0 = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI2_port_SPI_CSN1 = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI2_port_SPI_CSN2 = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI2_port_SPI_CSN3 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI2_port_SPI_SCK = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI2_port_SPI_SDIO0 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI2_port_SPI_SDIO1 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI2_port_SPI_SDIO2 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI2_port_SPI_SDIO3 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI3_port_SPI_CSN0 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI3_port_SPI_CSN1 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI3_port_SPI_CSN2 = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI3_port_SPI_CSN3 = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI3_port_SPI_SCK = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI3_port_SPI_SDIO0 = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI3_port_SPI_SDIO1 = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI3_port_SPI_SDIO2 = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_QSPI3_port_SPI_SDIO3 = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_TIMER0_port_OUT0 = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_TIMER0_port_OUT1 = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_TIMER0_port_OUT2 = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_TIMER0_port_OUT3 = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_TIMER1_port_OUT0 = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_TIMER1_port_OUT1 = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_TIMER1_port_OUT2 = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_TIMER1_port_OUT3 = 45,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_TIMER2_port_OUT0 = 46,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_TIMER2_port_OUT1 = 47,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_TIMER2_port_OUT2 = 48,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_TIMER2_port_OUT3 = 49,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_TIMER3_port_OUT0 = 50,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_TIMER3_port_OUT1 = 51,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_TIMER3_port_OUT2 = 52,
  KRAKEN_PADFRAME_AON_PAD_GPIOB9_group_TIMER3_port_OUT3 = 53,
} kraken_padframe_aon_pad_gpiob9_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob9.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpiob9_mux_set(kraken_padframe_aon_pad_gpiob9_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob9.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpiob9_mux_sel_t kraken_padframe_aon_pad_gpiob9_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob10_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob10
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpiob10_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpiob10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpiob10_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpiob10
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpiob10_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpiob10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob10_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpiob10
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpiob10_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpiob10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob10_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpiob10
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpiob10_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpiob10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob10_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpiob10
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpiob10_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpiob10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob10_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpiob10
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpiob10_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpiob10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob10_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpiob10
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpiob10_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpiob10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob10_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpiob10
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpiob10_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_GPIO_B_port_GPIO10 = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI0_port_SPI_CSN0 = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI0_port_SPI_CSN1 = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI0_port_SPI_CSN2 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI0_port_SPI_CSN3 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI0_port_SPI_SCK = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI0_port_SPI_SDIO0 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI0_port_SPI_SDIO1 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI0_port_SPI_SDIO2 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI0_port_SPI_SDIO3 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI1_port_SPI_CSN0 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI1_port_SPI_CSN1 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI1_port_SPI_CSN2 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI1_port_SPI_CSN3 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI1_port_SPI_SCK = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI1_port_SPI_SDIO0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI1_port_SPI_SDIO1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI1_port_SPI_SDIO2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI1_port_SPI_SDIO3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI2_port_SPI_CSN0 = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI2_port_SPI_CSN1 = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI2_port_SPI_CSN2 = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI2_port_SPI_CSN3 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI2_port_SPI_SCK = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI2_port_SPI_SDIO0 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI2_port_SPI_SDIO1 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI2_port_SPI_SDIO2 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI2_port_SPI_SDIO3 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI3_port_SPI_CSN0 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI3_port_SPI_CSN1 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI3_port_SPI_CSN2 = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI3_port_SPI_CSN3 = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI3_port_SPI_SCK = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI3_port_SPI_SDIO0 = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI3_port_SPI_SDIO1 = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI3_port_SPI_SDIO2 = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_QSPI3_port_SPI_SDIO3 = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_TIMER0_port_OUT0 = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_TIMER0_port_OUT1 = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_TIMER0_port_OUT2 = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_TIMER0_port_OUT3 = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_TIMER1_port_OUT0 = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_TIMER1_port_OUT1 = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_TIMER1_port_OUT2 = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_TIMER1_port_OUT3 = 45,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_TIMER2_port_OUT0 = 46,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_TIMER2_port_OUT1 = 47,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_TIMER2_port_OUT2 = 48,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_TIMER2_port_OUT3 = 49,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_TIMER3_port_OUT0 = 50,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_TIMER3_port_OUT1 = 51,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_TIMER3_port_OUT2 = 52,
  KRAKEN_PADFRAME_AON_PAD_GPIOB10_group_TIMER3_port_OUT3 = 53,
} kraken_padframe_aon_pad_gpiob10_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob10.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpiob10_mux_set(kraken_padframe_aon_pad_gpiob10_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob10.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpiob10_mux_sel_t kraken_padframe_aon_pad_gpiob10_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob11_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob11
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpiob11_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpiob11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpiob11_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpiob11
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpiob11_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpiob11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob11_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpiob11
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpiob11_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpiob11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob11_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpiob11
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpiob11_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpiob11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob11_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpiob11
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpiob11_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpiob11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob11_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpiob11
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpiob11_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpiob11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob11_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpiob11
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpiob11_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpiob11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob11_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpiob11
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpiob11_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_GPIO_B_port_GPIO11 = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI0_port_SPI_CSN0 = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI0_port_SPI_CSN1 = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI0_port_SPI_CSN2 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI0_port_SPI_CSN3 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI0_port_SPI_SCK = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI0_port_SPI_SDIO0 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI0_port_SPI_SDIO1 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI0_port_SPI_SDIO2 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI0_port_SPI_SDIO3 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI1_port_SPI_CSN0 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI1_port_SPI_CSN1 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI1_port_SPI_CSN2 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI1_port_SPI_CSN3 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI1_port_SPI_SCK = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI1_port_SPI_SDIO0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI1_port_SPI_SDIO1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI1_port_SPI_SDIO2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI1_port_SPI_SDIO3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI2_port_SPI_CSN0 = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI2_port_SPI_CSN1 = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI2_port_SPI_CSN2 = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI2_port_SPI_CSN3 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI2_port_SPI_SCK = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI2_port_SPI_SDIO0 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI2_port_SPI_SDIO1 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI2_port_SPI_SDIO2 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI2_port_SPI_SDIO3 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI3_port_SPI_CSN0 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI3_port_SPI_CSN1 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI3_port_SPI_CSN2 = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI3_port_SPI_CSN3 = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI3_port_SPI_SCK = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI3_port_SPI_SDIO0 = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI3_port_SPI_SDIO1 = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI3_port_SPI_SDIO2 = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_QSPI3_port_SPI_SDIO3 = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_TIMER0_port_OUT0 = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_TIMER0_port_OUT1 = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_TIMER0_port_OUT2 = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_TIMER0_port_OUT3 = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_TIMER1_port_OUT0 = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_TIMER1_port_OUT1 = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_TIMER1_port_OUT2 = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_TIMER1_port_OUT3 = 45,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_TIMER2_port_OUT0 = 46,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_TIMER2_port_OUT1 = 47,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_TIMER2_port_OUT2 = 48,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_TIMER2_port_OUT3 = 49,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_TIMER3_port_OUT0 = 50,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_TIMER3_port_OUT1 = 51,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_TIMER3_port_OUT2 = 52,
  KRAKEN_PADFRAME_AON_PAD_GPIOB11_group_TIMER3_port_OUT3 = 53,
} kraken_padframe_aon_pad_gpiob11_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob11.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpiob11_mux_set(kraken_padframe_aon_pad_gpiob11_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob11.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpiob11_mux_sel_t kraken_padframe_aon_pad_gpiob11_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob12_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob12
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpiob12_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpiob12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpiob12_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpiob12
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpiob12_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpiob12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob12_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpiob12
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpiob12_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpiob12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob12_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpiob12
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpiob12_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpiob12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob12_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpiob12
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpiob12_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpiob12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob12_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpiob12
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpiob12_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpiob12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob12_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpiob12
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpiob12_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpiob12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob12_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpiob12
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpiob12_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_GPIO_B_port_GPIO12 = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI0_port_SPI_CSN0 = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI0_port_SPI_CSN1 = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI0_port_SPI_CSN2 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI0_port_SPI_CSN3 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI0_port_SPI_SCK = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI0_port_SPI_SDIO0 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI0_port_SPI_SDIO1 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI0_port_SPI_SDIO2 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI0_port_SPI_SDIO3 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI1_port_SPI_CSN0 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI1_port_SPI_CSN1 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI1_port_SPI_CSN2 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI1_port_SPI_CSN3 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI1_port_SPI_SCK = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI1_port_SPI_SDIO0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI1_port_SPI_SDIO1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI1_port_SPI_SDIO2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI1_port_SPI_SDIO3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI2_port_SPI_CSN0 = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI2_port_SPI_CSN1 = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI2_port_SPI_CSN2 = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI2_port_SPI_CSN3 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI2_port_SPI_SCK = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI2_port_SPI_SDIO0 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI2_port_SPI_SDIO1 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI2_port_SPI_SDIO2 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI2_port_SPI_SDIO3 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI3_port_SPI_CSN0 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI3_port_SPI_CSN1 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI3_port_SPI_CSN2 = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI3_port_SPI_CSN3 = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI3_port_SPI_SCK = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI3_port_SPI_SDIO0 = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI3_port_SPI_SDIO1 = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI3_port_SPI_SDIO2 = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_QSPI3_port_SPI_SDIO3 = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_TIMER0_port_OUT0 = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_TIMER0_port_OUT1 = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_TIMER0_port_OUT2 = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_TIMER0_port_OUT3 = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_TIMER1_port_OUT0 = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_TIMER1_port_OUT1 = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_TIMER1_port_OUT2 = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_TIMER1_port_OUT3 = 45,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_TIMER2_port_OUT0 = 46,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_TIMER2_port_OUT1 = 47,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_TIMER2_port_OUT2 = 48,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_TIMER2_port_OUT3 = 49,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_TIMER3_port_OUT0 = 50,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_TIMER3_port_OUT1 = 51,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_TIMER3_port_OUT2 = 52,
  KRAKEN_PADFRAME_AON_PAD_GPIOB12_group_TIMER3_port_OUT3 = 53,
} kraken_padframe_aon_pad_gpiob12_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob12.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpiob12_mux_set(kraken_padframe_aon_pad_gpiob12_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob12.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpiob12_mux_sel_t kraken_padframe_aon_pad_gpiob12_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob13_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob13
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpiob13_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpiob13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpiob13_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpiob13
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpiob13_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpiob13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob13_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpiob13
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpiob13_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpiob13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob13_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpiob13
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpiob13_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpiob13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob13_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpiob13
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpiob13_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpiob13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob13_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpiob13
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpiob13_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpiob13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob13_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpiob13
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpiob13_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpiob13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob13_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpiob13
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpiob13_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_GPIO_B_port_GPIO13 = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI0_port_SPI_CSN0 = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI0_port_SPI_CSN1 = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI0_port_SPI_CSN2 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI0_port_SPI_CSN3 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI0_port_SPI_SCK = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI0_port_SPI_SDIO0 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI0_port_SPI_SDIO1 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI0_port_SPI_SDIO2 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI0_port_SPI_SDIO3 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI1_port_SPI_CSN0 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI1_port_SPI_CSN1 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI1_port_SPI_CSN2 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI1_port_SPI_CSN3 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI1_port_SPI_SCK = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI1_port_SPI_SDIO0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI1_port_SPI_SDIO1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI1_port_SPI_SDIO2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI1_port_SPI_SDIO3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI2_port_SPI_CSN0 = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI2_port_SPI_CSN1 = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI2_port_SPI_CSN2 = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI2_port_SPI_CSN3 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI2_port_SPI_SCK = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI2_port_SPI_SDIO0 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI2_port_SPI_SDIO1 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI2_port_SPI_SDIO2 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI2_port_SPI_SDIO3 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI3_port_SPI_CSN0 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI3_port_SPI_CSN1 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI3_port_SPI_CSN2 = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI3_port_SPI_CSN3 = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI3_port_SPI_SCK = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI3_port_SPI_SDIO0 = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI3_port_SPI_SDIO1 = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI3_port_SPI_SDIO2 = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_QSPI3_port_SPI_SDIO3 = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_TIMER0_port_OUT0 = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_TIMER0_port_OUT1 = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_TIMER0_port_OUT2 = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_TIMER0_port_OUT3 = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_TIMER1_port_OUT0 = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_TIMER1_port_OUT1 = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_TIMER1_port_OUT2 = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_TIMER1_port_OUT3 = 45,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_TIMER2_port_OUT0 = 46,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_TIMER2_port_OUT1 = 47,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_TIMER2_port_OUT2 = 48,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_TIMER2_port_OUT3 = 49,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_TIMER3_port_OUT0 = 50,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_TIMER3_port_OUT1 = 51,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_TIMER3_port_OUT2 = 52,
  KRAKEN_PADFRAME_AON_PAD_GPIOB13_group_TIMER3_port_OUT3 = 53,
} kraken_padframe_aon_pad_gpiob13_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob13.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpiob13_mux_set(kraken_padframe_aon_pad_gpiob13_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob13.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpiob13_mux_sel_t kraken_padframe_aon_pad_gpiob13_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob14_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob14
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpiob14_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpiob14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpiob14_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpiob14
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpiob14_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpiob14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob14_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpiob14
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpiob14_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpiob14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob14_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpiob14
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpiob14_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpiob14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob14_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpiob14
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpiob14_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpiob14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob14_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpiob14
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpiob14_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpiob14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob14_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpiob14
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpiob14_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpiob14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob14_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpiob14
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpiob14_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_GPIO_B_port_GPIO14 = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI0_port_SPI_CSN0 = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI0_port_SPI_CSN1 = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI0_port_SPI_CSN2 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI0_port_SPI_CSN3 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI0_port_SPI_SCK = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI0_port_SPI_SDIO0 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI0_port_SPI_SDIO1 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI0_port_SPI_SDIO2 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI0_port_SPI_SDIO3 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI1_port_SPI_CSN0 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI1_port_SPI_CSN1 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI1_port_SPI_CSN2 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI1_port_SPI_CSN3 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI1_port_SPI_SCK = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI1_port_SPI_SDIO0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI1_port_SPI_SDIO1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI1_port_SPI_SDIO2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI1_port_SPI_SDIO3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI2_port_SPI_CSN0 = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI2_port_SPI_CSN1 = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI2_port_SPI_CSN2 = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI2_port_SPI_CSN3 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI2_port_SPI_SCK = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI2_port_SPI_SDIO0 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI2_port_SPI_SDIO1 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI2_port_SPI_SDIO2 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI2_port_SPI_SDIO3 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI3_port_SPI_CSN0 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI3_port_SPI_CSN1 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI3_port_SPI_CSN2 = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI3_port_SPI_CSN3 = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI3_port_SPI_SCK = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI3_port_SPI_SDIO0 = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI3_port_SPI_SDIO1 = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI3_port_SPI_SDIO2 = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_QSPI3_port_SPI_SDIO3 = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_TIMER0_port_OUT0 = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_TIMER0_port_OUT1 = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_TIMER0_port_OUT2 = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_TIMER0_port_OUT3 = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_TIMER1_port_OUT0 = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_TIMER1_port_OUT1 = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_TIMER1_port_OUT2 = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_TIMER1_port_OUT3 = 45,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_TIMER2_port_OUT0 = 46,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_TIMER2_port_OUT1 = 47,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_TIMER2_port_OUT2 = 48,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_TIMER2_port_OUT3 = 49,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_TIMER3_port_OUT0 = 50,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_TIMER3_port_OUT1 = 51,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_TIMER3_port_OUT2 = 52,
  KRAKEN_PADFRAME_AON_PAD_GPIOB14_group_TIMER3_port_OUT3 = 53,
} kraken_padframe_aon_pad_gpiob14_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob14.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpiob14_mux_set(kraken_padframe_aon_pad_gpiob14_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob14.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpiob14_mux_sel_t kraken_padframe_aon_pad_gpiob14_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob15_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob15
 *
 * @return The value of the chip2pad field
 */
uint8_t kraken_padframe_aon_pad_gpiob15_cfg_chip2pad_get();

/**
 * Sets the drv pad signal for the pad: pad_gpiob15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void kraken_padframe_aon_pad_gpiob15_cfg_drv_set(uint8_t value);

/**
 * Get the currently configured drv value for the pad: pad_gpiob15
 *
 * @return The value of the drv field
 */
uint8_t kraken_padframe_aon_pad_gpiob15_cfg_drv_get();

/**
 * Sets the pde pad signal for the pad: pad_gpiob15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob15_cfg_pde_set(uint8_t value);

/**
 * Get the currently configured pde value for the pad: pad_gpiob15
 *
 * @return The value of the pde field
 */
uint8_t kraken_padframe_aon_pad_gpiob15_cfg_pde_get();

/**
 * Sets the pue pad signal for the pad: pad_gpiob15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob15_cfg_pue_set(uint8_t value);

/**
 * Get the currently configured pue value for the pad: pad_gpiob15
 *
 * @return The value of the pue field
 */
uint8_t kraken_padframe_aon_pad_gpiob15_cfg_pue_get();

/**
 * Sets the rxe pad signal for the pad: pad_gpiob15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob15_cfg_rxe_set(uint8_t value);

/**
 * Get the currently configured rxe value for the pad: pad_gpiob15
 *
 * @return The value of the rxe field
 */
uint8_t kraken_padframe_aon_pad_gpiob15_cfg_rxe_get();

/**
 * Sets the slw pad signal for the pad: pad_gpiob15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob15_cfg_slw_set(uint8_t value);

/**
 * Get the currently configured slw value for the pad: pad_gpiob15
 *
 * @return The value of the slw field
 */
uint8_t kraken_padframe_aon_pad_gpiob15_cfg_slw_get();

/**
 * Sets the smt pad signal for the pad: pad_gpiob15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob15_cfg_smt_set(uint8_t value);

/**
 * Get the currently configured smt value for the pad: pad_gpiob15
 *
 * @return The value of the smt field
 */
uint8_t kraken_padframe_aon_pad_gpiob15_cfg_smt_get();

/**
 * Sets the trie pad signal for the pad: pad_gpiob15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void kraken_padframe_aon_pad_gpiob15_cfg_trie_set(uint8_t value);

/**
 * Get the currently configured trie value for the pad: pad_gpiob15
 *
 * @return The value of the trie field
 */
uint8_t kraken_padframe_aon_pad_gpiob15_cfg_trie_get();

typedef enum {
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_REGISTER = 0,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_GPIO_B_port_GPIO15 = 1,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI0_port_SPI_CSN0 = 2,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI0_port_SPI_CSN1 = 3,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI0_port_SPI_CSN2 = 4,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI0_port_SPI_CSN3 = 5,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI0_port_SPI_SCK = 6,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI0_port_SPI_SDIO0 = 7,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI0_port_SPI_SDIO1 = 8,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI0_port_SPI_SDIO2 = 9,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI0_port_SPI_SDIO3 = 10,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI1_port_SPI_CSN0 = 11,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI1_port_SPI_CSN1 = 12,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI1_port_SPI_CSN2 = 13,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI1_port_SPI_CSN3 = 14,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI1_port_SPI_SCK = 15,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI1_port_SPI_SDIO0 = 16,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI1_port_SPI_SDIO1 = 17,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI1_port_SPI_SDIO2 = 18,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI1_port_SPI_SDIO3 = 19,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI2_port_SPI_CSN0 = 20,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI2_port_SPI_CSN1 = 21,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI2_port_SPI_CSN2 = 22,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI2_port_SPI_CSN3 = 23,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI2_port_SPI_SCK = 24,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI2_port_SPI_SDIO0 = 25,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI2_port_SPI_SDIO1 = 26,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI2_port_SPI_SDIO2 = 27,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI2_port_SPI_SDIO3 = 28,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI3_port_SPI_CSN0 = 29,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI3_port_SPI_CSN1 = 30,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI3_port_SPI_CSN2 = 31,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI3_port_SPI_CSN3 = 32,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI3_port_SPI_SCK = 33,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI3_port_SPI_SDIO0 = 34,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI3_port_SPI_SDIO1 = 35,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI3_port_SPI_SDIO2 = 36,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_QSPI3_port_SPI_SDIO3 = 37,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_TIMER0_port_OUT0 = 38,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_TIMER0_port_OUT1 = 39,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_TIMER0_port_OUT2 = 40,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_TIMER0_port_OUT3 = 41,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_TIMER1_port_OUT0 = 42,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_TIMER1_port_OUT1 = 43,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_TIMER1_port_OUT2 = 44,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_TIMER1_port_OUT3 = 45,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_TIMER2_port_OUT0 = 46,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_TIMER2_port_OUT1 = 47,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_TIMER2_port_OUT2 = 48,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_TIMER2_port_OUT3 = 49,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_TIMER3_port_OUT0 = 50,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_TIMER3_port_OUT1 = 51,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_TIMER3_port_OUT2 = 52,
  KRAKEN_PADFRAME_AON_PAD_GPIOB15_group_TIMER3_port_OUT3 = 53,
} kraken_padframe_aon_pad_gpiob15_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob15.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void kraken_padframe_aon_pad_gpiob15_mux_set(kraken_padframe_aon_pad_gpiob15_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob15.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 kraken_padframe_aon_pad_gpiob15_mux_sel_t kraken_padframe_aon_pad_gpiob15_mux_get();




#endif /*  KRAKEN_PADFRAME_H */
