
package pkg_internal_quasi_static_padframe_aon;
  typedef struct packed{
    logic  chip2pad;
    logic [1:0] driving_strength;
    logic  output_en;
    logic  pull_up_en;
  } mux_to_pad_pad_hw_t;

  typedef struct packed{
    logic  pad2chip;
  } pad_to_mux_pad_hw_t;

  typedef struct packed{
    logic  chip2pad;
    logic [1:0] driving_strength;
    logic  output_en;
    logic  pull_up_en;
  } mux_to_pad_pad_qs_t;

  typedef struct packed{
    logic  pad2chip;
  } pad_to_mux_pad_qs_t;

  typedef struct packed{
    logic  chip2pad;
    logic [1:0] driving_strength;
    logic  output_en;
    logic  pull_up_en;
  } mux_to_pad_pad_io0_t;

  typedef struct packed{
    logic  pad2chip;
  } pad_to_mux_pad_io0_t;

  typedef struct packed{
    logic  chip2pad;
    logic [1:0] driving_strength;
    logic  output_en;
    logic  pull_up_en;
  } mux_to_pad_pad_io1_t;

  typedef struct packed{
    logic  pad2chip;
  } pad_to_mux_pad_io1_t;

  typedef struct packed{
    mux_to_pad_pad_hw_t pad_hw;
    mux_to_pad_pad_qs_t pad_qs;
    mux_to_pad_pad_io0_t pad_io0;
    mux_to_pad_pad_io1_t pad_io1;
  } mux_to_pads_t;

  typedef struct packed{
    pad_to_mux_pad_hw_t pad_hw;
    pad_to_mux_pad_qs_t pad_qs;
    pad_to_mux_pad_io0_t pad_io0;
    pad_to_mux_pad_io1_t pad_io1;
  } pads_to_mux_t;



  // Indices definitions

  parameter PAD_MUX_GROUP_GPIO_SEL_WIDTH = 2;
  parameter logic[1:0] PAD_MUX_GROUP_GPIO_SEL_DEFAULT = 2'd0;
  parameter logic[1:0] PAD_MUX_GROUP_GPIO_SEL_GPIO_IO0 = 2'd1;
  parameter logic[1:0] PAD_MUX_GROUP_GPIO_SEL_GPIO_IO1 = 2'd2;

  parameter PAD_MUX_GROUP_PAD_HW_SEL_WIDTH = 1;
  parameter logic[0:0] PAD_MUX_GROUP_PAD_HW_SEL_DEFAULT = 1'd0;
  parameter logic[0:0] PAD_MUX_GROUP_PAD_HW_SEL_UART_TX = 1'd1;

  parameter PAD_MUX_GROUP_PAD_QS_SEL_WIDTH = 1;
  parameter logic[0:0] PAD_MUX_GROUP_PAD_QS_SEL_DEFAULT = 1'd0;
  parameter logic[0:0] PAD_MUX_GROUP_PAD_QS_SEL_UART_RX = 1'd1;

  // Dynamic Pad  instance index

  parameter PORT_MUX_GROUP_GPIO_SEL_WIDTH = 1;
  parameter logic[0:0] PORT_MUX_GROUP_GPIO_SEL_PAD_IO0 = 1'd0;
  parameter logic[0:0] PORT_MUX_GROUP_GPIO_SEL_PAD_IO1 = 1'd1;

  parameter PORT_MUX_GROUP_PAD_HW_SEL_WIDTH = 1;
  parameter logic[0:0] PORT_MUX_GROUP_PAD_HW_SEL_PAD_HW = 1'd0;

  parameter PORT_MUX_GROUP_PAD_QS_SEL_WIDTH = 1;
  parameter logic[0:0] PORT_MUX_GROUP_PAD_QS_SEL_PAD_QS = 1'd0;
endpackage : pkg_internal_quasi_static_padframe_aon
