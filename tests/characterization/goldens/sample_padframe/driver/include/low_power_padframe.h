

#ifndef LOW_POWER_PADFRAME_H
#define LOW_POWER_PADFRAME_H
#include <stdint.h>

#ifndef LOW_POWER_PADFRAME_BASE_ADDRESS
#error "LOW_POWER_PADFRAME_BASE_ADDRESS is not defined. Set this token to the configuration base address of your padframe before you include this header file."
#endif



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa0_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa0
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa0_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa0_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa0
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa0_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa0_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa0
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa0_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa0_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa0
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa0_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA0_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA0_group_GPIO_A_port_GPIO00 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA0_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA0_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA0_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA0_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa0_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa0.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa0_mux_set(low_power_padframe_always_on_pads_pad_gpioa0_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa0.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa0_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa0_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa1_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa1
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa1_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa1_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa1
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa1_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa1_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa1
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa1_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa1_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa1
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa1_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA1_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA1_group_GPIO_A_port_GPIO01 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA1_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA1_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA1_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA1_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa1_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa1.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa1_mux_set(low_power_padframe_always_on_pads_pad_gpioa1_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa1.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa1_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa1_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa2_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa2
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa2_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa2_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa2
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa2_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa2_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa2
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa2_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa2_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa2
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa2_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA2_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA2_group_GPIO_A_port_GPIO02 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA2_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA2_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA2_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA2_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa2_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa2.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa2_mux_set(low_power_padframe_always_on_pads_pad_gpioa2_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa2.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa2_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa2_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa3_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa3
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa3_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa3_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa3
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa3_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa3_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa3
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa3_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa3_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa3
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa3_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA3_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA3_group_GPIO_A_port_GPIO03 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA3_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA3_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA3_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA3_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa3_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa3.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa3_mux_set(low_power_padframe_always_on_pads_pad_gpioa3_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa3.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa3_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa3_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa4_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa4
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa4_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa4_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa4
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa4_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa4_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa4
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa4_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa4_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa4
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa4_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA4_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA4_group_GPIO_A_port_GPIO04 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA4_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA4_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA4_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA4_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa4_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa4.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa4_mux_set(low_power_padframe_always_on_pads_pad_gpioa4_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa4.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa4_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa4_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa5_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa5
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa5_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa5_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa5
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa5_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa5_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa5
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa5_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa5_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa5
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa5_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA5_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA5_group_GPIO_A_port_GPIO05 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA5_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA5_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA5_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA5_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa5_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa5.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa5_mux_set(low_power_padframe_always_on_pads_pad_gpioa5_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa5.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa5_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa5_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa6_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa6
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa6_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa6_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa6
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa6_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa6_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa6
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa6_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa6_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa6
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa6_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA6_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA6_group_GPIO_A_port_GPIO06 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA6_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA6_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA6_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA6_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa6_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa6.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa6_mux_set(low_power_padframe_always_on_pads_pad_gpioa6_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa6.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa6_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa6_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa7_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa7
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa7_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa7_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa7
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa7_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa7_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa7
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa7_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa7_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa7
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa7_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA7_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA7_group_GPIO_A_port_GPIO07 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA7_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA7_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA7_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA7_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa7_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa7.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa7_mux_set(low_power_padframe_always_on_pads_pad_gpioa7_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa7.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa7_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa7_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa8_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa8
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa8_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa8_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa8
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa8_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa8_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa8
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa8_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa8_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa8
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa8_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA8_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA8_group_GPIO_A_port_GPIO08 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA8_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA8_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA8_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA8_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa8_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa8.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa8_mux_set(low_power_padframe_always_on_pads_pad_gpioa8_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa8.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa8_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa8_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa9_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa9
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa9_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa9_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa9
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa9_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa9_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa9
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa9_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa9_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa9
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa9_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA9_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA9_group_GPIO_A_port_GPIO09 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA9_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA9_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA9_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA9_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa9_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa9.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa9_mux_set(low_power_padframe_always_on_pads_pad_gpioa9_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa9.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa9_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa9_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa10_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa10
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa10_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa10_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa10
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa10_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa10_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa10
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa10_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa10_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa10
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa10_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA10_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA10_group_GPIO_A_port_GPIO10 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA10_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA10_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA10_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA10_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa10_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa10.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa10_mux_set(low_power_padframe_always_on_pads_pad_gpioa10_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa10.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa10_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa10_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa11_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa11
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa11_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa11_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa11
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa11_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa11_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa11
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa11_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa11_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa11
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa11_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA11_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA11_group_GPIO_A_port_GPIO11 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA11_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA11_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA11_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA11_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa11_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa11.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa11_mux_set(low_power_padframe_always_on_pads_pad_gpioa11_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa11.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa11_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa11_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa12_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa12
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa12_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa12_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa12
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa12_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa12_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa12
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa12_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa12_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa12
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa12_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA12_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA12_group_GPIO_A_port_GPIO12 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA12_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA12_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA12_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA12_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa12_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa12.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa12_mux_set(low_power_padframe_always_on_pads_pad_gpioa12_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa12.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa12_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa12_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa13_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa13
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa13_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa13_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa13
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa13_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa13_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa13
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa13_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa13_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa13
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa13_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA13_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA13_group_GPIO_A_port_GPIO13 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA13_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA13_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA13_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA13_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa13_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa13.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa13_mux_set(low_power_padframe_always_on_pads_pad_gpioa13_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa13.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa13_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa13_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa14_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa14
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa14_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa14_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa14
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa14_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa14_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa14
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa14_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa14_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa14
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa14_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA14_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA14_group_GPIO_A_port_GPIO14 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA14_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA14_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA14_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA14_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa14_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa14.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa14_mux_set(low_power_padframe_always_on_pads_pad_gpioa14_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa14.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa14_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa14_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa15_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa15
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa15_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa15_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa15
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa15_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa15_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa15
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa15_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa15_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa15
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa15_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA15_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA15_group_GPIO_A_port_GPIO15 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA15_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA15_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA15_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA15_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa15_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa15.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa15_mux_set(low_power_padframe_always_on_pads_pad_gpioa15_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa15.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa15_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa15_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa16
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa16_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa16
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa16_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa16
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa16_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa16
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa16_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa16
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa16_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa16
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa16_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa16
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa16_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa16
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa16_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA16_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA16_group_GPIO_A_port_GPIO16 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA16_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA16_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA16_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA16_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa16_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa16.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa16_mux_set(low_power_padframe_always_on_pads_pad_gpioa16_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa16.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa16_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa16_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa17
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa17_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa17
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa17_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa17
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa17_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa17
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa17_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa17
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa17_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa17
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa17_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa17
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa17_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa17
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa17_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA17_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA17_group_GPIO_A_port_GPIO17 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA17_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA17_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA17_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA17_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa17_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa17.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa17_mux_set(low_power_padframe_always_on_pads_pad_gpioa17_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa17.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa17_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa17_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa18
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa18_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa18
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa18_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa18
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa18_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa18
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa18_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa18
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa18_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa18
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa18_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa18
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa18_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa18
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa18_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA18_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA18_group_GPIO_A_port_GPIO18 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA18_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA18_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA18_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA18_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa18_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa18.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa18_mux_set(low_power_padframe_always_on_pads_pad_gpioa18_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa18.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa18_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa18_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa19
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa19_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa19
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa19_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa19
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa19_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa19
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa19_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa19
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa19_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa19
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa19_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa19
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa19_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa19
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa19_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA19_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA19_group_GPIO_A_port_GPIO19 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA19_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA19_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA19_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA19_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa19_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa19.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa19_mux_set(low_power_padframe_always_on_pads_pad_gpioa19_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa19.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa19_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa19_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa20
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa20_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa20
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa20_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa20
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa20_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa20
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa20_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa20
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa20_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa20
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa20_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa20
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa20_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa20
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa20_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA20_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA20_group_GPIO_A_port_GPIO20 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA20_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA20_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA20_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA20_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa20_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa20.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa20_mux_set(low_power_padframe_always_on_pads_pad_gpioa20_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa20.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa20_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa20_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa21
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa21_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa21
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa21_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa21
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa21_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa21
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa21_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa21
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa21_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa21
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa21_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa21
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa21_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa21
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa21_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA21_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA21_group_GPIO_A_port_GPIO21 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA21_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA21_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA21_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA21_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa21_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa21.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa21_mux_set(low_power_padframe_always_on_pads_pad_gpioa21_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa21.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa21_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa21_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa22
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa22_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa22
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa22_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa22
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa22_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa22
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa22_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa22
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa22_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa22
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa22_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa22
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa22_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa22
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa22_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA22_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA22_group_GPIO_A_port_GPIO22 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA22_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA22_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA22_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA22_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa22_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa22.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa22_mux_set(low_power_padframe_always_on_pads_pad_gpioa22_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa22.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa22_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa22_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa23
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa23_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa23
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa23_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa23
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa23_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa23
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa23_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa23
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa23_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa23
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa23_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa23
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa23_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa23
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa23_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA23_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA23_group_GPIO_A_port_GPIO23 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA23_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA23_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA23_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA23_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa23_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa23.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa23_mux_set(low_power_padframe_always_on_pads_pad_gpioa23_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa23.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa23_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa23_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa24
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa24_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa24
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa24_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa24
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa24_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa24
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa24_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa24
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa24_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa24
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa24_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa24
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa24_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa24
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa24_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA24_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA24_group_GPIO_A_port_GPIO24 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA24_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA24_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA24_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA24_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa24_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa24.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa24_mux_set(low_power_padframe_always_on_pads_pad_gpioa24_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa24.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa24_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa24_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa25
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa25_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa25
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa25_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa25
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa25_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa25
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa25_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa25
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa25_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa25
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa25_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa25
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa25_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa25
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa25_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA25_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA25_group_GPIO_A_port_GPIO25 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA25_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA25_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA25_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA25_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa25_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa25.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa25_mux_set(low_power_padframe_always_on_pads_pad_gpioa25_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa25.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa25_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa25_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa26
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa26_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa26
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa26_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa26
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa26_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa26
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa26_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa26
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa26_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa26
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa26_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa26
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa26_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa26
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa26_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA26_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA26_group_GPIO_A_port_GPIO26 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA26_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA26_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA26_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA26_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa26_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa26.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa26_mux_set(low_power_padframe_always_on_pads_pad_gpioa26_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa26.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa26_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa26_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa27
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa27_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa27
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa27_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa27
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa27_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa27
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa27_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa27
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa27_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa27
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa27_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa27
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa27_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa27
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa27_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA27_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA27_group_GPIO_A_port_GPIO27 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA27_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA27_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA27_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA27_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa27_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa27.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa27_mux_set(low_power_padframe_always_on_pads_pad_gpioa27_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa27.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa27_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa27_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa28
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa28_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa28
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa28_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa28
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa28_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa28
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa28_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa28
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa28_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa28
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa28_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa28
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa28_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa28
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa28_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA28_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA28_group_GPIO_A_port_GPIO28 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA28_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA28_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA28_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA28_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa28_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa28.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa28_mux_set(low_power_padframe_always_on_pads_pad_gpioa28_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa28.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa28_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa28_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa29
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa29_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa29
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa29_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa29
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa29_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa29
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa29_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa29
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa29_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa29
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa29_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa29
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa29_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa29
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa29_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA29_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA29_group_GPIO_A_port_GPIO29 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA29_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA29_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA29_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA29_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa29_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa29.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa29_mux_set(low_power_padframe_always_on_pads_pad_gpioa29_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa29.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa29_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa29_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa30
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa30_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa30
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa30_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa30
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa30_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa30
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa30_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa30
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa30_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa30
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa30_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa30
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa30_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa30
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa30_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA30_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA30_group_GPIO_A_port_GPIO30 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA30_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA30_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA30_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA30_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa30_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa30.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa30_mux_set(low_power_padframe_always_on_pads_pad_gpioa30_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa30.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa30_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa30_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioa31
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa31_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioa31
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa31_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioa31
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa31_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioa31
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa31_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioa31
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa31_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioa31
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa31_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioa31
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioa31_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioa31
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioa31_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA31_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA31_group_GPIO_A_port_GPIO31 = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA31_group_SPI_port_CSN = 2,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA31_group_SPI_port_MISO = 3,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA31_group_SPI_port_MOSI = 4,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOA31_group_SPI_port_SCK = 5,
} low_power_padframe_always_on_pads_pad_gpioa31_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioa31.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioa31_mux_set(low_power_padframe_always_on_pads_pad_gpioa31_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioa31.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioa31_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa31_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob0_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob0
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob0_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob0_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob0
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob0_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob0_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob0
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob0_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob0_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob0
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob0_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB0_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB0_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB0_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob0_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob0.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob0_mux_set(low_power_padframe_always_on_pads_pad_gpiob0_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob0.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob0_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob0_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob1_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob1
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob1_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob1_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob1
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob1_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob1_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob1
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob1_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob1_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob1
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob1_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB1_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB1_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB1_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob1_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob1.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob1_mux_set(low_power_padframe_always_on_pads_pad_gpiob1_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob1.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob1_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob1_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob2_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob2
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob2_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob2_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob2
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob2_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob2_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob2
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob2_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob2_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob2
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob2_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB2_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB2_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB2_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob2_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob2.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob2_mux_set(low_power_padframe_always_on_pads_pad_gpiob2_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob2.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob2_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob2_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob3_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob3
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob3_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob3_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob3
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob3_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob3_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob3
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob3_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob3_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob3
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob3_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB3_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB3_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB3_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob3_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob3.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob3_mux_set(low_power_padframe_always_on_pads_pad_gpiob3_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob3.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob3_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob3_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob4_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob4
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob4_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob4_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob4
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob4_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob4_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob4
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob4_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob4_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob4
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob4_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB4_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB4_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB4_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob4_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob4.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob4_mux_set(low_power_padframe_always_on_pads_pad_gpiob4_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob4.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob4_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob4_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob5_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob5
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob5_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob5_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob5
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob5_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob5_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob5
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob5_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob5_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob5
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob5_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB5_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB5_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB5_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob5_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob5.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob5_mux_set(low_power_padframe_always_on_pads_pad_gpiob5_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob5.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob5_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob5_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob6_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob6
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob6_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob6_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob6
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob6_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob6_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob6
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob6_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob6_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob6
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob6_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB6_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB6_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB6_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob6_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob6.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob6_mux_set(low_power_padframe_always_on_pads_pad_gpiob6_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob6.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob6_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob6_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob7_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob7
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob7_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob7_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob7
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob7_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob7_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob7
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob7_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob7_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob7
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob7_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB7_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB7_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB7_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob7_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob7.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob7_mux_set(low_power_padframe_always_on_pads_pad_gpiob7_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob7.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob7_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob7_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob8_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob8
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob8_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob8_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob8
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob8_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob8_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob8
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob8_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob8_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob8
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob8_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB8_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB8_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB8_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob8_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob8.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob8_mux_set(low_power_padframe_always_on_pads_pad_gpiob8_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob8.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob8_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob8_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob9_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob9
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob9_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob9_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob9
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob9_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob9_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob9
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob9_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob9_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob9
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob9_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB9_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB9_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB9_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob9_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob9.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob9_mux_set(low_power_padframe_always_on_pads_pad_gpiob9_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob9.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob9_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob9_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob10_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob10
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob10_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob10_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob10
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob10_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob10_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob10
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob10_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob10_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob10
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob10_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB10_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB10_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB10_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob10_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob10.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob10_mux_set(low_power_padframe_always_on_pads_pad_gpiob10_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob10.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob10_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob10_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob11_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob11
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob11_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob11_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob11
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob11_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob11_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob11
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob11_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob11_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob11
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob11_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB11_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB11_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB11_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob11_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob11.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob11_mux_set(low_power_padframe_always_on_pads_pad_gpiob11_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob11.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob11_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob11_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob12_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob12
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob12_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob12_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob12
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob12_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob12_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob12
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob12_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob12_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob12
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob12_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB12_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB12_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB12_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob12_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob12.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob12_mux_set(low_power_padframe_always_on_pads_pad_gpiob12_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob12.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob12_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob12_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob13_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob13
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob13_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob13_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob13
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob13_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob13_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob13
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob13_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob13_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob13
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob13_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB13_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB13_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB13_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob13_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob13.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob13_mux_set(low_power_padframe_always_on_pads_pad_gpiob13_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob13.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob13_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob13_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob14_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob14
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob14_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob14_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob14
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob14_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob14_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob14
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob14_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob14_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob14
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob14_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB14_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB14_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB14_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob14_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob14.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob14_mux_set(low_power_padframe_always_on_pads_pad_gpiob14_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob14.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob14_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob14_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob15_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob15
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob15_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob15_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob15
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob15_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob15_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob15
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob15_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob15_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob15
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob15_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB15_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB15_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB15_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob15_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob15.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob15_mux_set(low_power_padframe_always_on_pads_pad_gpiob15_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob15.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob15_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob15_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob16
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob16_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob16
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob16_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob16
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob16_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob16
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob16_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob16
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob16_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob16
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob16_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob16
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob16_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob16
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob16_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB16_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB16_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB16_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob16_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob16.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob16_mux_set(low_power_padframe_always_on_pads_pad_gpiob16_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob16.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob16_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob16_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob17
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob17_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob17
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob17_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob17
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob17_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob17
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob17_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob17
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob17_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob17
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob17_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob17
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob17_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob17
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob17_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB17_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB17_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB17_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob17_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob17.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob17_mux_set(low_power_padframe_always_on_pads_pad_gpiob17_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob17.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob17_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob17_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob18
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob18_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob18
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob18_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob18
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob18_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob18
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob18_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob18
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob18_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob18
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob18_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob18
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob18_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob18
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob18_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB18_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB18_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB18_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob18_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob18.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob18_mux_set(low_power_padframe_always_on_pads_pad_gpiob18_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob18.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob18_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob18_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob19
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob19_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob19
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob19_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob19
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob19_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob19
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob19_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob19
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob19_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob19
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob19_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob19
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob19_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob19
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob19_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB19_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB19_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB19_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob19_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob19.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob19_mux_set(low_power_padframe_always_on_pads_pad_gpiob19_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob19.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob19_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob19_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob20
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob20_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob20
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob20_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob20
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob20_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob20
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob20_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob20
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob20_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob20
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob20_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob20
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob20_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob20
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob20_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB20_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB20_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB20_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob20_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob20.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob20_mux_set(low_power_padframe_always_on_pads_pad_gpiob20_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob20.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob20_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob20_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob21
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob21_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob21
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob21_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob21
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob21_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob21
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob21_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob21
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob21_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob21
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob21_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob21
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob21_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob21
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob21_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB21_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB21_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB21_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob21_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob21.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob21_mux_set(low_power_padframe_always_on_pads_pad_gpiob21_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob21.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob21_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob21_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob22
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob22_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob22
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob22_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob22
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob22_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob22
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob22_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob22
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob22_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob22
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob22_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob22
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob22_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob22
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob22_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB22_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB22_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB22_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob22_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob22.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob22_mux_set(low_power_padframe_always_on_pads_pad_gpiob22_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob22.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob22_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob22_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob23
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob23_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob23
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob23_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob23
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob23_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob23
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob23_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob23
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob23_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob23
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob23_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob23
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob23_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob23
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob23_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB23_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB23_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB23_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob23_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob23.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob23_mux_set(low_power_padframe_always_on_pads_pad_gpiob23_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob23.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob23_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob23_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob24
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob24_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob24
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob24_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob24
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob24_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob24
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob24_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob24
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob24_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob24
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob24_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob24
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob24_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob24
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob24_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB24_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB24_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB24_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob24_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob24.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob24_mux_set(low_power_padframe_always_on_pads_pad_gpiob24_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob24.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob24_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob24_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob25
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob25_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob25
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob25_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob25
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob25_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob25
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob25_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob25
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob25_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob25
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob25_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob25
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob25_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob25
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob25_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB25_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB25_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB25_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob25_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob25.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob25_mux_set(low_power_padframe_always_on_pads_pad_gpiob25_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob25.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob25_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob25_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob26
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob26_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob26
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob26_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob26
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob26_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob26
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob26_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob26
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob26_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob26
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob26_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob26
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob26_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob26
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob26_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB26_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB26_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB26_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob26_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob26.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob26_mux_set(low_power_padframe_always_on_pads_pad_gpiob26_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob26.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob26_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob26_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob27
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob27_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob27
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob27_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob27
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob27_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob27
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob27_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob27
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob27_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob27
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob27_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob27
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob27_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob27
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob27_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB27_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB27_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB27_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob27_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob27.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob27_mux_set(low_power_padframe_always_on_pads_pad_gpiob27_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob27.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob27_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob27_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob28
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob28_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob28
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob28_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob28
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob28_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob28
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob28_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob28
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob28_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob28
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob28_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob28
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob28_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob28
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob28_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB28_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB28_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB28_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob28_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob28.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob28_mux_set(low_power_padframe_always_on_pads_pad_gpiob28_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob28.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob28_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob28_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob29
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob29_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob29
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob29_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob29
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob29_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob29
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob29_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob29
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob29_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob29
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob29_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob29
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob29_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob29
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob29_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB29_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB29_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB29_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob29_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob29.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob29_mux_set(low_power_padframe_always_on_pads_pad_gpiob29_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob29.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob29_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob29_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob30
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob30_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob30
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob30_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob30
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob30_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob30
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob30_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob30
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob30_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob30
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob30_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob30
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob30_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob30
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob30_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB30_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB30_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB30_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob30_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob30.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob30_mux_set(low_power_padframe_always_on_pads_pad_gpiob30_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob30.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob30_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob30_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpiob31
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob31_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpiob31
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob31_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpiob31
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob31_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpiob31
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob31_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpiob31
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob31_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpiob31
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob31_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpiob31
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpiob31_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpiob31
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpiob31_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB31_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB31_group_I2C_port_SCL = 1,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOB31_group_I2C_port_SDA = 2,
} low_power_padframe_always_on_pads_pad_gpiob31_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpiob31.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpiob31_mux_set(low_power_padframe_always_on_pads_pad_gpiob31_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpiob31.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpiob31_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob31_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioc0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc0_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioc0
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc0_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioc0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc0_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioc0
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc0_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioc0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc0_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioc0
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc0_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioc0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc0_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioc0
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc0_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC0_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC0_group_GPIO_C_port_GPIOC00 = 1,
} low_power_padframe_always_on_pads_pad_gpioc0_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioc0.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioc0_mux_set(low_power_padframe_always_on_pads_pad_gpioc0_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioc0.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioc0_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc0_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioc1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc1_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioc1
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc1_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioc1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc1_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioc1
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc1_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioc1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc1_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioc1
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc1_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioc1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc1_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioc1
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc1_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC1_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC1_group_GPIO_C_port_GPIOC01 = 1,
} low_power_padframe_always_on_pads_pad_gpioc1_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioc1.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioc1_mux_set(low_power_padframe_always_on_pads_pad_gpioc1_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioc1.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioc1_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc1_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioc2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc2_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioc2
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc2_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioc2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc2_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioc2
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc2_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioc2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc2_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioc2
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc2_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioc2
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc2_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioc2
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc2_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC2_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC2_group_GPIO_C_port_GPIOC02 = 1,
} low_power_padframe_always_on_pads_pad_gpioc2_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioc2.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioc2_mux_set(low_power_padframe_always_on_pads_pad_gpioc2_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioc2.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioc2_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc2_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioc3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc3_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioc3
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc3_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioc3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc3_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioc3
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc3_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioc3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc3_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioc3
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc3_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioc3
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc3_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioc3
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc3_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC3_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC3_group_GPIO_C_port_GPIOC03 = 1,
} low_power_padframe_always_on_pads_pad_gpioc3_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioc3.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioc3_mux_set(low_power_padframe_always_on_pads_pad_gpioc3_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioc3.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioc3_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc3_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioc4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc4_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioc4
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc4_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioc4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc4_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioc4
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc4_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioc4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc4_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioc4
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc4_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioc4
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc4_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioc4
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc4_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC4_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC4_group_GPIO_C_port_GPIOC04 = 1,
} low_power_padframe_always_on_pads_pad_gpioc4_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioc4.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioc4_mux_set(low_power_padframe_always_on_pads_pad_gpioc4_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioc4.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioc4_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc4_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioc5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc5_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioc5
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc5_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioc5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc5_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioc5
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc5_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioc5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc5_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioc5
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc5_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioc5
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc5_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioc5
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc5_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC5_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC5_group_GPIO_C_port_GPIOC05 = 1,
} low_power_padframe_always_on_pads_pad_gpioc5_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioc5.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioc5_mux_set(low_power_padframe_always_on_pads_pad_gpioc5_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioc5.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioc5_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc5_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioc6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc6_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioc6
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc6_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioc6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc6_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioc6
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc6_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioc6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc6_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioc6
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc6_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioc6
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc6_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioc6
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc6_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC6_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC6_group_GPIO_C_port_GPIOC06 = 1,
} low_power_padframe_always_on_pads_pad_gpioc6_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioc6.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioc6_mux_set(low_power_padframe_always_on_pads_pad_gpioc6_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioc6.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioc6_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc6_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioc7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc7_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioc7
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc7_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioc7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc7_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioc7
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc7_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioc7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc7_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioc7
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc7_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioc7
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc7_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioc7
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc7_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC7_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC7_group_GPIO_C_port_GPIOC07 = 1,
} low_power_padframe_always_on_pads_pad_gpioc7_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioc7.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioc7_mux_set(low_power_padframe_always_on_pads_pad_gpioc7_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioc7.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioc7_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc7_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioc8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc8_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioc8
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc8_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioc8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc8_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioc8
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc8_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioc8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc8_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioc8
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc8_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioc8
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc8_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioc8
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc8_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC8_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC8_group_GPIO_C_port_GPIOC08 = 1,
} low_power_padframe_always_on_pads_pad_gpioc8_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioc8.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioc8_mux_set(low_power_padframe_always_on_pads_pad_gpioc8_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioc8.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioc8_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc8_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioc9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc9_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioc9
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc9_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioc9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc9_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioc9
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc9_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioc9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc9_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioc9
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc9_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioc9
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc9_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioc9
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc9_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC9_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC9_group_GPIO_C_port_GPIOC09 = 1,
} low_power_padframe_always_on_pads_pad_gpioc9_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioc9.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioc9_mux_set(low_power_padframe_always_on_pads_pad_gpioc9_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioc9.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioc9_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc9_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioc10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc10_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioc10
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc10_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioc10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc10_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioc10
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc10_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioc10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc10_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioc10
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc10_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioc10
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc10_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioc10
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc10_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC10_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC10_group_GPIO_C_port_GPIOC10 = 1,
} low_power_padframe_always_on_pads_pad_gpioc10_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioc10.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioc10_mux_set(low_power_padframe_always_on_pads_pad_gpioc10_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioc10.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioc10_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc10_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioc11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc11_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioc11
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc11_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioc11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc11_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioc11
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc11_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioc11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc11_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioc11
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc11_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioc11
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc11_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioc11
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc11_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC11_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC11_group_GPIO_C_port_GPIOC11 = 1,
} low_power_padframe_always_on_pads_pad_gpioc11_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioc11.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioc11_mux_set(low_power_padframe_always_on_pads_pad_gpioc11_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioc11.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioc11_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc11_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioc12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc12_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioc12
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc12_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioc12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc12_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioc12
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc12_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioc12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc12_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioc12
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc12_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioc12
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc12_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioc12
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc12_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC12_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC12_group_GPIO_C_port_GPIOC12 = 1,
} low_power_padframe_always_on_pads_pad_gpioc12_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioc12.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioc12_mux_set(low_power_padframe_always_on_pads_pad_gpioc12_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioc12.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioc12_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc12_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioc13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc13_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioc13
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc13_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioc13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc13_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioc13
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc13_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioc13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc13_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioc13
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc13_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioc13
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc13_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioc13
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc13_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC13_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC13_group_GPIO_C_port_GPIOC13 = 1,
} low_power_padframe_always_on_pads_pad_gpioc13_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioc13.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioc13_mux_set(low_power_padframe_always_on_pads_pad_gpioc13_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioc13.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioc13_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc13_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioc14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc14_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioc14
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc14_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioc14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc14_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioc14
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc14_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioc14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc14_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioc14
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc14_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioc14
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc14_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioc14
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc14_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC14_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC14_group_GPIO_C_port_GPIOC14 = 1,
} low_power_padframe_always_on_pads_pad_gpioc14_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioc14.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioc14_mux_set(low_power_padframe_always_on_pads_pad_gpioc14_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioc14.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioc14_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc14_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_gpioc15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc15_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_gpioc15
 *
 * @return The value of the chip2pad field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc15_cfg_chip2pad_get();

/**
 * Sets the output_en pad signal for the pad: pad_gpioc15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc15_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_gpioc15
 *
 * @return The value of the output_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc15_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_gpioc15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc15_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_gpioc15
 *
 * @return The value of the pull_up_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc15_cfg_pull_up_en_get();

/**
 * Sets the rx_en pad signal for the pad: pad_gpioc15
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void low_power_padframe_always_on_pads_pad_gpioc15_cfg_rx_en_set(uint8_t value);

/**
 * Get the currently configured rx_en value for the pad: pad_gpioc15
 *
 * @return The value of the rx_en field
 */
uint8_t low_power_padframe_always_on_pads_pad_gpioc15_cfg_rx_en_get();

typedef enum {
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC15_REGISTER = 0,
  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_PAD_GPIOC15_group_GPIO_C_port_GPIOC15 = 1,
} low_power_padframe_always_on_pads_pad_gpioc15_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_gpioc15.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void low_power_padframe_always_on_pads_pad_gpioc15_mux_set(low_power_padframe_always_on_pads_pad_gpioc15_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_gpioc15.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 low_power_padframe_always_on_pads_pad_gpioc15_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc15_mux_get();




#endif /*  LOW_POWER_PADFRAME_H */
