

#ifndef QUASI_STATIC_PADFRAME_H
#define QUASI_STATIC_PADFRAME_H
#include <stdint.h>

#ifndef QUASI_STATIC_PADFRAME_BASE_ADDRESS
#error "QUASI_STATIC_PADFRAME_BASE_ADDRESS is not defined. Set this token to the configuration base address of your padframe before you include this header file."
#endif



/**
 * Sets the chip2pad pad signal for the pad: pad_qs
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void quasi_static_padframe_aon_pad_qs_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_qs
 *
 * @return The value of the chip2pad field
 */
uint8_t quasi_static_padframe_aon_pad_qs_cfg_chip2pad_get();

/**
 * Sets the driving_strength pad signal for the pad: pad_qs
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void quasi_static_padframe_aon_pad_qs_cfg_driving_strength_set(uint8_t value);

/**
 * Get the currently configured driving_strength value for the pad: pad_qs
 *
 * @return The value of the driving_strength field
 */
uint8_t quasi_static_padframe_aon_pad_qs_cfg_driving_strength_get();

/**
 * Sets the output_en pad signal for the pad: pad_qs
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void quasi_static_padframe_aon_pad_qs_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_qs
 *
 * @return The value of the output_en field
 */
uint8_t quasi_static_padframe_aon_pad_qs_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_qs
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void quasi_static_padframe_aon_pad_qs_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_qs
 *
 * @return The value of the pull_up_en field
 */
uint8_t quasi_static_padframe_aon_pad_qs_cfg_pull_up_en_get();

typedef enum {
  QUASI_STATIC_PADFRAME_AON_PAD_QS_REGISTER = 0,
  QUASI_STATIC_PADFRAME_AON_PAD_QS_group_UART_port_RX = 1,
} quasi_static_padframe_aon_pad_qs_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_qs.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void quasi_static_padframe_aon_pad_qs_mux_set(quasi_static_padframe_aon_pad_qs_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_qs.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 quasi_static_padframe_aon_pad_qs_mux_sel_t quasi_static_padframe_aon_pad_qs_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void quasi_static_padframe_aon_pad_io0_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io0
 *
 * @return The value of the chip2pad field
 */
uint8_t quasi_static_padframe_aon_pad_io0_cfg_chip2pad_get();

/**
 * Sets the driving_strength pad signal for the pad: pad_io0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void quasi_static_padframe_aon_pad_io0_cfg_driving_strength_set(uint8_t value);

/**
 * Get the currently configured driving_strength value for the pad: pad_io0
 *
 * @return The value of the driving_strength field
 */
uint8_t quasi_static_padframe_aon_pad_io0_cfg_driving_strength_get();

/**
 * Sets the output_en pad signal for the pad: pad_io0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void quasi_static_padframe_aon_pad_io0_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_io0
 *
 * @return The value of the output_en field
 */
uint8_t quasi_static_padframe_aon_pad_io0_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_io0
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void quasi_static_padframe_aon_pad_io0_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_io0
 *
 * @return The value of the pull_up_en field
 */
uint8_t quasi_static_padframe_aon_pad_io0_cfg_pull_up_en_get();

typedef enum {
  QUASI_STATIC_PADFRAME_AON_PAD_IO0_REGISTER = 0,
  QUASI_STATIC_PADFRAME_AON_PAD_IO0_group_GPIO_port_IO0 = 1,
  QUASI_STATIC_PADFRAME_AON_PAD_IO0_group_GPIO_port_IO1 = 2,
} quasi_static_padframe_aon_pad_io0_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io0.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void quasi_static_padframe_aon_pad_io0_mux_set(quasi_static_padframe_aon_pad_io0_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io0.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 quasi_static_padframe_aon_pad_io0_mux_sel_t quasi_static_padframe_aon_pad_io0_mux_get();



/**
 * Sets the chip2pad pad signal for the pad: pad_io1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void quasi_static_padframe_aon_pad_io1_cfg_chip2pad_set(uint8_t value);

/**
 * Get the currently configured chip2pad value for the pad: pad_io1
 *
 * @return The value of the chip2pad field
 */
uint8_t quasi_static_padframe_aon_pad_io1_cfg_chip2pad_get();

/**
 * Sets the driving_strength pad signal for the pad: pad_io1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 3.
 */
void quasi_static_padframe_aon_pad_io1_cfg_driving_strength_set(uint8_t value);

/**
 * Get the currently configured driving_strength value for the pad: pad_io1
 *
 * @return The value of the driving_strength field
 */
uint8_t quasi_static_padframe_aon_pad_io1_cfg_driving_strength_get();

/**
 * Sets the output_en pad signal for the pad: pad_io1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void quasi_static_padframe_aon_pad_io1_cfg_output_en_set(uint8_t value);

/**
 * Get the currently configured output_en value for the pad: pad_io1
 *
 * @return The value of the output_en field
 */
uint8_t quasi_static_padframe_aon_pad_io1_cfg_output_en_get();

/**
 * Sets the pull_up_en pad signal for the pad: pad_io1
 *
 * @param value The value to program into the pad configuration register. A value smaller than 1.
 */
void quasi_static_padframe_aon_pad_io1_cfg_pull_up_en_set(uint8_t value);

/**
 * Get the currently configured pull_up_en value for the pad: pad_io1
 *
 * @return The value of the pull_up_en field
 */
uint8_t quasi_static_padframe_aon_pad_io1_cfg_pull_up_en_get();

typedef enum {
  QUASI_STATIC_PADFRAME_AON_PAD_IO1_REGISTER = 0,
  QUASI_STATIC_PADFRAME_AON_PAD_IO1_group_GPIO_port_IO0 = 1,
  QUASI_STATIC_PADFRAME_AON_PAD_IO1_group_GPIO_port_IO1 = 2,
} quasi_static_padframe_aon_pad_io1_mux_sel_t;

/**
   * Choose the entity (a port or the dedicated configuration register) that controls pad_io1.
   *
   * @param mux_sel Port or configuration register to connect to the pad.
 */
void quasi_static_padframe_aon_pad_io1_mux_set(quasi_static_padframe_aon_pad_io1_mux_sel_t mux_sel);

/**
 * Read the current multiplexer select value configured for pad_io1.
 *
 * @return Port or configuration register currently connected to the pad.
 */
 quasi_static_padframe_aon_pad_io1_mux_sel_t quasi_static_padframe_aon_pad_io1_mux_get();




#endif /*  QUASI_STATIC_PADFRAME_H */
