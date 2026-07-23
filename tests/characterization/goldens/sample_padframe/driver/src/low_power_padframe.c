

#include "low_power_padframe.h"
#define  LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG0_BASE_ADDR LOW_POWER_PADFRAME_BASE_ADDRESS
#include "low_power_padframe_always_on_pads_regs.h"
#include "bitfield.h"

#define REG_WRITE32(addr, value) *((volatile uint32_t*) addr) = (uint32_t) value;
#define REG_READ32(addr) *((volatile uint32_t*) addr)


void low_power_padframe_always_on_pads_pad_gpioa0_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA0_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa0_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA0_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa0_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA0_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa0_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA0_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa0_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA0_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa0_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA0_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa0_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA0_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa0_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA0_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa0_mux_set(low_power_padframe_always_on_pads_pad_gpioa0_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA0_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa0_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa0_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA0_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa1_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA1_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa1_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA1_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa1_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA1_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa1_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA1_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa1_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA1_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa1_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA1_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa1_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA1_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa1_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA1_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa1_mux_set(low_power_padframe_always_on_pads_pad_gpioa1_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA1_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa1_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa1_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA1_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa2_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA2_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa2_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA2_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa2_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA2_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa2_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA2_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa2_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA2_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa2_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA2_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa2_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA2_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa2_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA2_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa2_mux_set(low_power_padframe_always_on_pads_pad_gpioa2_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA2_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa2_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa2_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA2_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa3_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA3_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa3_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA3_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa3_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA3_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa3_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA3_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa3_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA3_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa3_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA3_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa3_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA3_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa3_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA3_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa3_mux_set(low_power_padframe_always_on_pads_pad_gpioa3_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA3_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa3_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa3_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA3_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa4_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA4_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa4_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA4_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa4_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA4_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa4_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA4_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa4_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA4_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa4_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA4_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa4_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA4_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa4_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA4_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa4_mux_set(low_power_padframe_always_on_pads_pad_gpioa4_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA4_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa4_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa4_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA4_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa5_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA5_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa5_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA5_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa5_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA5_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa5_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA5_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa5_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA5_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa5_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA5_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa5_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA5_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa5_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA5_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa5_mux_set(low_power_padframe_always_on_pads_pad_gpioa5_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA5_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa5_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa5_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA5_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa6_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA6_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa6_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA6_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa6_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA6_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa6_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA6_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa6_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA6_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa6_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA6_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa6_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA6_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa6_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA6_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa6_mux_set(low_power_padframe_always_on_pads_pad_gpioa6_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA6_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa6_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa6_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA6_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa7_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA7_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa7_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA7_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa7_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA7_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa7_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA7_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa7_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA7_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa7_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA7_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa7_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA7_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa7_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA7_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa7_mux_set(low_power_padframe_always_on_pads_pad_gpioa7_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA7_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa7_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa7_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA7_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa8_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA8_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa8_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA8_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa8_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA8_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa8_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA8_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa8_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA8_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa8_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA8_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa8_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA8_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa8_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA8_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa8_mux_set(low_power_padframe_always_on_pads_pad_gpioa8_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA8_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa8_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa8_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA8_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa9_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA9_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa9_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA9_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa9_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA9_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa9_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA9_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa9_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA9_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa9_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA9_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa9_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA9_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa9_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA9_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa9_mux_set(low_power_padframe_always_on_pads_pad_gpioa9_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA9_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa9_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa9_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA9_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa10_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA10_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa10_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA10_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa10_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA10_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa10_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA10_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa10_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA10_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa10_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA10_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa10_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA10_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa10_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA10_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa10_mux_set(low_power_padframe_always_on_pads_pad_gpioa10_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA10_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa10_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa10_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA10_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa11_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA11_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa11_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA11_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa11_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA11_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa11_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA11_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa11_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA11_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa11_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA11_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa11_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA11_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa11_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA11_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa11_mux_set(low_power_padframe_always_on_pads_pad_gpioa11_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA11_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa11_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa11_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA11_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa12_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA12_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa12_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA12_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa12_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA12_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa12_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA12_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa12_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA12_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa12_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA12_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa12_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA12_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa12_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA12_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa12_mux_set(low_power_padframe_always_on_pads_pad_gpioa12_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA12_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa12_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa12_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA12_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa13_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA13_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa13_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA13_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa13_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA13_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa13_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA13_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa13_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA13_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa13_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA13_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa13_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA13_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa13_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA13_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa13_mux_set(low_power_padframe_always_on_pads_pad_gpioa13_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA13_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa13_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa13_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA13_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa14_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA14_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa14_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA14_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa14_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA14_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa14_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA14_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa14_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA14_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa14_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA14_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa14_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA14_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa14_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA14_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa14_mux_set(low_power_padframe_always_on_pads_pad_gpioa14_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA14_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa14_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa14_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA14_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa15_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA15_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa15_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA15_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa15_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA15_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa15_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA15_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa15_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA15_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa15_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA15_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa15_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA15_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa15_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA15_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa15_mux_set(low_power_padframe_always_on_pads_pad_gpioa15_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA15_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa15_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa15_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA15_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa16_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA16_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa16_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA16_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa16_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA16_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa16_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA16_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa16_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA16_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa16_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA16_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa16_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA16_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa16_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA16_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa16_mux_set(low_power_padframe_always_on_pads_pad_gpioa16_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA16_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa16_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa16_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA16_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa17_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA17_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa17_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA17_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa17_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA17_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa17_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA17_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa17_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA17_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa17_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA17_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa17_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA17_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa17_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA17_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa17_mux_set(low_power_padframe_always_on_pads_pad_gpioa17_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA17_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa17_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa17_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA17_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa18_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA18_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa18_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA18_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa18_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA18_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa18_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA18_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa18_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA18_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa18_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA18_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa18_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA18_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa18_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA18_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa18_mux_set(low_power_padframe_always_on_pads_pad_gpioa18_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA18_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa18_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa18_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA18_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa19_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA19_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa19_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA19_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa19_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA19_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa19_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA19_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa19_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA19_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa19_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA19_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa19_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA19_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa19_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA19_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa19_mux_set(low_power_padframe_always_on_pads_pad_gpioa19_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA19_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa19_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa19_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA19_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa20_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA20_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa20_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA20_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa20_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA20_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa20_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA20_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa20_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA20_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa20_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA20_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa20_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA20_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa20_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA20_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa20_mux_set(low_power_padframe_always_on_pads_pad_gpioa20_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA20_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa20_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa20_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA20_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa21_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA21_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa21_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA21_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa21_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA21_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa21_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA21_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa21_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA21_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa21_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA21_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa21_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA21_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa21_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA21_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa21_mux_set(low_power_padframe_always_on_pads_pad_gpioa21_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA21_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa21_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa21_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA21_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa22_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA22_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa22_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA22_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa22_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA22_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa22_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA22_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa22_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA22_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa22_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA22_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa22_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA22_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa22_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA22_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa22_mux_set(low_power_padframe_always_on_pads_pad_gpioa22_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA22_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa22_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa22_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA22_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa23_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA23_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa23_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA23_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa23_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA23_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa23_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA23_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa23_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA23_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa23_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA23_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa23_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA23_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa23_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA23_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa23_mux_set(low_power_padframe_always_on_pads_pad_gpioa23_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA23_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa23_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa23_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA23_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa24_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA24_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa24_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA24_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa24_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA24_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa24_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA24_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa24_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA24_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa24_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA24_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa24_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA24_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa24_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA24_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa24_mux_set(low_power_padframe_always_on_pads_pad_gpioa24_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA24_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa24_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa24_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA24_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa25_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA25_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa25_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA25_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa25_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA25_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa25_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA25_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa25_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA25_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa25_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA25_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa25_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA25_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa25_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA25_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa25_mux_set(low_power_padframe_always_on_pads_pad_gpioa25_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA25_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa25_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa25_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA25_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa26_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA26_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA26_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa26_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA26_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA26_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa26_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA26_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA26_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa26_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA26_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA26_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa26_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA26_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA26_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa26_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA26_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA26_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa26_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA26_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA26_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa26_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA26_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA26_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa26_mux_set(low_power_padframe_always_on_pads_pad_gpioa26_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA26_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa26_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa26_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA26_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa27_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA27_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA27_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa27_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA27_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA27_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa27_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA27_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA27_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa27_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA27_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA27_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa27_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA27_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA27_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa27_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA27_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA27_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa27_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA27_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA27_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa27_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA27_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA27_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa27_mux_set(low_power_padframe_always_on_pads_pad_gpioa27_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA27_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa27_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa27_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA27_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa28_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA28_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA28_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa28_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA28_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA28_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa28_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA28_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA28_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa28_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA28_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA28_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa28_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA28_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA28_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa28_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA28_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA28_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa28_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA28_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA28_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa28_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA28_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA28_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa28_mux_set(low_power_padframe_always_on_pads_pad_gpioa28_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA28_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa28_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa28_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA28_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa29_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA29_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA29_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa29_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA29_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA29_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa29_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA29_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA29_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa29_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA29_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA29_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa29_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA29_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA29_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa29_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA29_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA29_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa29_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA29_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA29_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa29_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA29_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA29_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa29_mux_set(low_power_padframe_always_on_pads_pad_gpioa29_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA29_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa29_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa29_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA29_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa30_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA30_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA30_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa30_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA30_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA30_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa30_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA30_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA30_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa30_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA30_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA30_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa30_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA30_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA30_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa30_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA30_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA30_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa30_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA30_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA30_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa30_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA30_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA30_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa30_mux_set(low_power_padframe_always_on_pads_pad_gpioa30_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA30_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa30_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa30_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA30_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpioa31_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA31_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA31_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa31_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA31_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA31_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa31_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA31_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA31_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa31_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA31_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA31_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa31_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA31_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA31_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa31_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA31_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA31_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa31_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA31_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA31_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioa31_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA31_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA31_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioa31_mux_set(low_power_padframe_always_on_pads_pad_gpioa31_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA31_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 7);
}

low_power_padframe_always_on_pads_pad_gpioa31_mux_sel_t low_power_padframe_always_on_pads_pad_gpioa31_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOA31_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 7;
}

void low_power_padframe_always_on_pads_pad_gpiob0_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB0_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob0_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB0_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob0_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB0_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob0_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB0_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob0_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB0_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob0_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB0_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob0_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB0_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob0_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB0_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob0_mux_set(low_power_padframe_always_on_pads_pad_gpiob0_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB0_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob0_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob0_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB0_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob1_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB1_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob1_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB1_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob1_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB1_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob1_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB1_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob1_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB1_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob1_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB1_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob1_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB1_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob1_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB1_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob1_mux_set(low_power_padframe_always_on_pads_pad_gpiob1_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB1_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob1_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob1_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB1_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob2_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB2_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob2_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB2_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob2_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB2_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob2_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB2_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob2_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB2_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob2_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB2_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob2_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB2_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob2_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB2_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob2_mux_set(low_power_padframe_always_on_pads_pad_gpiob2_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB2_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob2_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob2_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB2_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob3_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB3_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob3_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB3_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob3_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB3_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob3_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB3_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob3_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB3_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob3_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB3_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob3_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB3_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob3_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB3_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob3_mux_set(low_power_padframe_always_on_pads_pad_gpiob3_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB3_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob3_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob3_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB3_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob4_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB4_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob4_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB4_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob4_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB4_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob4_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB4_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob4_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB4_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob4_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB4_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob4_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB4_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob4_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB4_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob4_mux_set(low_power_padframe_always_on_pads_pad_gpiob4_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB4_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob4_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob4_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB4_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob5_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB5_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob5_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB5_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob5_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB5_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob5_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB5_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob5_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB5_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob5_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB5_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob5_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB5_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob5_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB5_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob5_mux_set(low_power_padframe_always_on_pads_pad_gpiob5_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB5_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob5_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob5_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB5_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob6_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB6_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob6_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB6_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob6_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB6_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob6_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB6_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob6_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB6_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob6_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB6_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob6_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB6_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob6_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB6_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob6_mux_set(low_power_padframe_always_on_pads_pad_gpiob6_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB6_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob6_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob6_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB6_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob7_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB7_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob7_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB7_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob7_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB7_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob7_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB7_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob7_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB7_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob7_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB7_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob7_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB7_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob7_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB7_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob7_mux_set(low_power_padframe_always_on_pads_pad_gpiob7_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB7_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob7_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob7_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB7_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob8_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB8_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob8_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB8_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob8_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB8_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob8_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB8_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob8_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB8_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob8_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB8_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob8_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB8_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob8_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB8_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob8_mux_set(low_power_padframe_always_on_pads_pad_gpiob8_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB8_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob8_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob8_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB8_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob9_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB9_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob9_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB9_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob9_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB9_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob9_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB9_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob9_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB9_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob9_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB9_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob9_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB9_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob9_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB9_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob9_mux_set(low_power_padframe_always_on_pads_pad_gpiob9_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB9_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob9_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob9_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB9_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob10_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB10_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob10_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB10_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob10_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB10_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob10_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB10_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob10_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB10_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob10_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB10_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob10_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB10_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob10_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB10_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob10_mux_set(low_power_padframe_always_on_pads_pad_gpiob10_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB10_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob10_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob10_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB10_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob11_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB11_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob11_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB11_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob11_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB11_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob11_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB11_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob11_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB11_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob11_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB11_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob11_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB11_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob11_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB11_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob11_mux_set(low_power_padframe_always_on_pads_pad_gpiob11_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB11_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob11_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob11_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB11_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob12_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB12_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob12_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB12_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob12_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB12_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob12_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB12_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob12_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB12_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob12_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB12_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob12_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB12_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob12_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB12_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob12_mux_set(low_power_padframe_always_on_pads_pad_gpiob12_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB12_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob12_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob12_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB12_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob13_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB13_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob13_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB13_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob13_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB13_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob13_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB13_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob13_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB13_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob13_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB13_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob13_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB13_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob13_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB13_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob13_mux_set(low_power_padframe_always_on_pads_pad_gpiob13_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB13_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob13_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob13_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB13_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob14_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB14_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob14_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB14_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob14_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB14_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob14_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB14_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob14_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB14_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob14_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB14_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob14_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB14_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob14_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB14_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob14_mux_set(low_power_padframe_always_on_pads_pad_gpiob14_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB14_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob14_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob14_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB14_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob15_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB15_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob15_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB15_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob15_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB15_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob15_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB15_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob15_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB15_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob15_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB15_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob15_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB15_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob15_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB15_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob15_mux_set(low_power_padframe_always_on_pads_pad_gpiob15_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB15_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob15_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob15_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB15_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob16_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB16_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob16_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB16_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob16_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB16_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob16_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB16_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob16_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB16_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob16_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB16_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob16_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB16_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob16_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB16_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob16_mux_set(low_power_padframe_always_on_pads_pad_gpiob16_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB16_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob16_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob16_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB16_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob17_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB17_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob17_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB17_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob17_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB17_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob17_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB17_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob17_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB17_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob17_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB17_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob17_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB17_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob17_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB17_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob17_mux_set(low_power_padframe_always_on_pads_pad_gpiob17_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB17_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob17_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob17_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB17_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob18_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB18_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob18_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB18_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob18_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB18_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob18_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB18_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob18_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB18_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob18_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB18_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob18_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB18_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob18_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB18_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob18_mux_set(low_power_padframe_always_on_pads_pad_gpiob18_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB18_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob18_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob18_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB18_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob19_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB19_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob19_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB19_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob19_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB19_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob19_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB19_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob19_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB19_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob19_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB19_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob19_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB19_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob19_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB19_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob19_mux_set(low_power_padframe_always_on_pads_pad_gpiob19_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB19_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob19_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob19_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB19_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob20_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB20_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob20_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB20_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob20_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB20_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob20_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB20_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob20_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB20_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob20_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB20_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob20_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB20_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob20_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB20_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob20_mux_set(low_power_padframe_always_on_pads_pad_gpiob20_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB20_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob20_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob20_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB20_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob21_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB21_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob21_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB21_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob21_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB21_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob21_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB21_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob21_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB21_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob21_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB21_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob21_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB21_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob21_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB21_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob21_mux_set(low_power_padframe_always_on_pads_pad_gpiob21_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB21_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob21_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob21_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB21_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob22_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB22_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob22_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB22_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob22_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB22_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob22_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB22_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob22_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB22_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob22_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB22_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob22_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB22_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob22_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB22_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob22_mux_set(low_power_padframe_always_on_pads_pad_gpiob22_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB22_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob22_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob22_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB22_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob23_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB23_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob23_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB23_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob23_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB23_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob23_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB23_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob23_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB23_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob23_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB23_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob23_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB23_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob23_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB23_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob23_mux_set(low_power_padframe_always_on_pads_pad_gpiob23_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB23_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob23_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob23_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB23_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob24_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB24_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob24_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB24_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob24_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB24_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob24_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB24_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob24_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB24_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob24_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB24_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob24_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB24_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob24_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB24_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob24_mux_set(low_power_padframe_always_on_pads_pad_gpiob24_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB24_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob24_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob24_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB24_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob25_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB25_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob25_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB25_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob25_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB25_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob25_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB25_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob25_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB25_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob25_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB25_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob25_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB25_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob25_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB25_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob25_mux_set(low_power_padframe_always_on_pads_pad_gpiob25_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB25_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob25_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob25_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB25_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob26_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB26_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB26_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob26_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB26_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB26_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob26_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB26_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB26_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob26_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB26_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB26_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob26_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB26_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB26_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob26_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB26_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB26_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob26_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB26_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB26_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob26_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB26_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB26_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob26_mux_set(low_power_padframe_always_on_pads_pad_gpiob26_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB26_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob26_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob26_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB26_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob27_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB27_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB27_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob27_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB27_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB27_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob27_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB27_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB27_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob27_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB27_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB27_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob27_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB27_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB27_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob27_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB27_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB27_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob27_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB27_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB27_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob27_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB27_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB27_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob27_mux_set(low_power_padframe_always_on_pads_pad_gpiob27_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB27_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob27_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob27_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB27_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob28_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB28_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB28_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob28_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB28_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB28_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob28_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB28_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB28_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob28_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB28_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB28_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob28_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB28_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB28_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob28_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB28_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB28_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob28_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB28_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB28_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob28_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB28_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB28_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob28_mux_set(low_power_padframe_always_on_pads_pad_gpiob28_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB28_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob28_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob28_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB28_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob29_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB29_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB29_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob29_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB29_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB29_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob29_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB29_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB29_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob29_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB29_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB29_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob29_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB29_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB29_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob29_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB29_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB29_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob29_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB29_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB29_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob29_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB29_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB29_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob29_mux_set(low_power_padframe_always_on_pads_pad_gpiob29_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB29_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob29_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob29_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB29_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob30_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB30_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB30_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob30_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB30_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB30_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob30_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB30_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB30_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob30_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB30_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB30_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob30_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB30_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB30_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob30_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB30_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB30_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob30_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB30_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB30_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob30_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB30_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB30_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob30_mux_set(low_power_padframe_always_on_pads_pad_gpiob30_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB30_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob30_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob30_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB30_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpiob31_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB31_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB31_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob31_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB31_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB31_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob31_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB31_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB31_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob31_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB31_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB31_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob31_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB31_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB31_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob31_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB31_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB31_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob31_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB31_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB31_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpiob31_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB31_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB31_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpiob31_mux_set(low_power_padframe_always_on_pads_pad_gpiob31_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB31_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

low_power_padframe_always_on_pads_pad_gpiob31_mux_sel_t low_power_padframe_always_on_pads_pad_gpiob31_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOB31_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void low_power_padframe_always_on_pads_pad_gpioc0_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC0_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc0_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC0_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc0_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC0_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc0_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC0_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc0_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC0_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc0_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC0_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc0_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC0_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc0_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC0_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc0_mux_set(low_power_padframe_always_on_pads_pad_gpioc0_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC0_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 1);
}

low_power_padframe_always_on_pads_pad_gpioc0_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc0_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC0_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 1;
}

void low_power_padframe_always_on_pads_pad_gpioc1_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC1_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc1_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC1_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc1_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC1_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc1_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC1_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc1_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC1_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc1_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC1_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc1_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC1_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc1_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC1_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc1_mux_set(low_power_padframe_always_on_pads_pad_gpioc1_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC1_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 1);
}

low_power_padframe_always_on_pads_pad_gpioc1_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc1_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC1_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 1;
}

void low_power_padframe_always_on_pads_pad_gpioc2_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC2_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc2_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC2_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc2_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC2_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc2_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC2_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc2_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC2_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc2_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC2_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc2_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC2_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc2_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC2_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc2_mux_set(low_power_padframe_always_on_pads_pad_gpioc2_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC2_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 1);
}

low_power_padframe_always_on_pads_pad_gpioc2_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc2_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC2_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 1;
}

void low_power_padframe_always_on_pads_pad_gpioc3_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC3_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc3_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC3_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc3_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC3_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc3_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC3_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc3_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC3_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc3_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC3_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc3_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC3_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc3_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC3_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc3_mux_set(low_power_padframe_always_on_pads_pad_gpioc3_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC3_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 1);
}

low_power_padframe_always_on_pads_pad_gpioc3_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc3_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC3_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 1;
}

void low_power_padframe_always_on_pads_pad_gpioc4_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC4_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc4_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC4_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc4_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC4_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc4_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC4_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc4_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC4_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc4_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC4_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc4_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC4_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc4_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC4_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc4_mux_set(low_power_padframe_always_on_pads_pad_gpioc4_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC4_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 1);
}

low_power_padframe_always_on_pads_pad_gpioc4_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc4_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC4_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 1;
}

void low_power_padframe_always_on_pads_pad_gpioc5_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC5_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc5_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC5_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc5_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC5_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc5_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC5_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc5_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC5_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc5_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC5_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc5_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC5_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc5_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC5_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc5_mux_set(low_power_padframe_always_on_pads_pad_gpioc5_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC5_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 1);
}

low_power_padframe_always_on_pads_pad_gpioc5_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc5_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC5_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 1;
}

void low_power_padframe_always_on_pads_pad_gpioc6_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC6_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc6_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC6_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc6_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC6_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc6_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC6_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc6_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC6_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc6_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC6_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc6_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC6_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc6_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC6_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc6_mux_set(low_power_padframe_always_on_pads_pad_gpioc6_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC6_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 1);
}

low_power_padframe_always_on_pads_pad_gpioc6_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc6_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC6_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 1;
}

void low_power_padframe_always_on_pads_pad_gpioc7_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC7_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc7_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC7_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc7_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC7_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc7_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC7_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc7_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC7_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc7_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC7_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc7_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC7_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc7_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC7_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc7_mux_set(low_power_padframe_always_on_pads_pad_gpioc7_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC7_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 1);
}

low_power_padframe_always_on_pads_pad_gpioc7_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc7_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC7_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 1;
}

void low_power_padframe_always_on_pads_pad_gpioc8_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC8_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc8_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC8_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc8_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC8_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc8_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC8_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc8_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC8_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc8_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC8_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc8_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC8_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc8_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC8_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc8_mux_set(low_power_padframe_always_on_pads_pad_gpioc8_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC8_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 1);
}

low_power_padframe_always_on_pads_pad_gpioc8_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc8_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC8_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 1;
}

void low_power_padframe_always_on_pads_pad_gpioc9_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC9_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc9_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC9_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc9_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC9_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc9_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC9_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc9_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC9_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc9_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC9_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc9_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC9_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc9_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC9_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc9_mux_set(low_power_padframe_always_on_pads_pad_gpioc9_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC9_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 1);
}

low_power_padframe_always_on_pads_pad_gpioc9_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc9_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC9_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 1;
}

void low_power_padframe_always_on_pads_pad_gpioc10_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC10_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc10_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC10_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc10_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC10_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc10_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC10_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc10_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC10_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc10_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC10_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc10_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC10_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc10_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC10_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc10_mux_set(low_power_padframe_always_on_pads_pad_gpioc10_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC10_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 1);
}

low_power_padframe_always_on_pads_pad_gpioc10_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc10_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC10_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 1;
}

void low_power_padframe_always_on_pads_pad_gpioc11_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC11_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc11_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC11_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc11_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC11_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc11_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC11_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc11_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC11_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc11_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC11_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc11_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC11_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc11_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC11_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc11_mux_set(low_power_padframe_always_on_pads_pad_gpioc11_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC11_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 1);
}

low_power_padframe_always_on_pads_pad_gpioc11_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc11_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC11_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 1;
}

void low_power_padframe_always_on_pads_pad_gpioc12_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC12_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc12_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC12_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc12_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC12_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc12_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC12_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc12_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC12_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc12_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC12_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc12_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC12_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc12_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC12_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc12_mux_set(low_power_padframe_always_on_pads_pad_gpioc12_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC12_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 1);
}

low_power_padframe_always_on_pads_pad_gpioc12_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc12_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC12_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 1;
}

void low_power_padframe_always_on_pads_pad_gpioc13_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC13_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc13_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC13_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc13_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC13_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc13_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC13_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc13_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC13_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc13_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC13_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc13_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC13_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc13_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC13_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc13_mux_set(low_power_padframe_always_on_pads_pad_gpioc13_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC13_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 1);
}

low_power_padframe_always_on_pads_pad_gpioc13_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc13_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC13_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 1;
}

void low_power_padframe_always_on_pads_pad_gpioc14_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC14_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc14_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC14_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc14_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC14_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc14_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC14_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc14_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC14_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc14_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC14_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc14_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC14_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc14_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC14_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc14_mux_set(low_power_padframe_always_on_pads_pad_gpioc14_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC14_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 1);
}

low_power_padframe_always_on_pads_pad_gpioc14_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc14_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC14_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 1;
}

void low_power_padframe_always_on_pads_pad_gpioc15_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC15_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc15_cfg_chip2pad_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC15_CFG_CHIP2PAD_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc15_cfg_output_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC15_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc15_cfg_output_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC15_CFG_OUTPUT_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc15_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC15_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc15_cfg_pull_up_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC15_CFG_PULL_UP_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc15_cfg_rx_en_set(uint8_t value) {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC15_CFG_RX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t low_power_padframe_always_on_pads_pad_gpioc15_cfg_rx_en_get() {
  uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC15_CFG_RX_EN_BIT);
}

void low_power_padframe_always_on_pads_pad_gpioc15_mux_set(low_power_padframe_always_on_pads_pad_gpioc15_mux_sel_t mux_sel) {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC15_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 1);
}

low_power_padframe_always_on_pads_pad_gpioc15_mux_sel_t low_power_padframe_always_on_pads_pad_gpioc15_mux_get() {
  const uint32_t address = LOW_POWER_PADFRAME_BASE_ADDRESS + LOW_POWER_PADFRAME_ALWAYS_ON_PADS_CONFIG_PAD_GPIOC15_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 1;
}
