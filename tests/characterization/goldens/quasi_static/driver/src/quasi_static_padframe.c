

#include "quasi_static_padframe.h"
#define  QUASI_STATIC_PADFRAME_AON_CONFIG0_BASE_ADDR QUASI_STATIC_PADFRAME_BASE_ADDRESS
#include "quasi_static_padframe_aon_regs.h"
#include "bitfield.h"

#define REG_WRITE32(addr, value) *((volatile uint32_t*) addr) = (uint32_t) value;
#define REG_READ32(addr) *((volatile uint32_t*) addr)


void quasi_static_padframe_aon_pad_qs_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_QS_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_QS_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t quasi_static_padframe_aon_pad_qs_cfg_chip2pad_get() {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_QS_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_QS_CFG_CHIP2PAD_BIT);
}

void quasi_static_padframe_aon_pad_qs_cfg_driving_strength_set(uint8_t value) {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_QS_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_QS_CFG_DRIVING_STRENGTH_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t quasi_static_padframe_aon_pad_qs_cfg_driving_strength_get() {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_QS_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_QS_CFG_DRIVING_STRENGTH_FIELD);
}

void quasi_static_padframe_aon_pad_qs_cfg_output_en_set(uint8_t value) {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_QS_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_QS_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t quasi_static_padframe_aon_pad_qs_cfg_output_en_get() {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_QS_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_QS_CFG_OUTPUT_EN_BIT);
}

void quasi_static_padframe_aon_pad_qs_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_QS_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_QS_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t quasi_static_padframe_aon_pad_qs_cfg_pull_up_en_get() {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_QS_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_QS_CFG_PULL_UP_EN_BIT);
}

void quasi_static_padframe_aon_pad_qs_mux_set(quasi_static_padframe_aon_pad_qs_mux_sel_t mux_sel) {
  const uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_QS_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 1);
}

quasi_static_padframe_aon_pad_qs_mux_sel_t quasi_static_padframe_aon_pad_qs_mux_get() {
  const uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_QS_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 1;
}

void quasi_static_padframe_aon_pad_io0_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO0_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t quasi_static_padframe_aon_pad_io0_cfg_chip2pad_get() {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO0_CFG_CHIP2PAD_BIT);
}

void quasi_static_padframe_aon_pad_io0_cfg_driving_strength_set(uint8_t value) {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO0_CFG_DRIVING_STRENGTH_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t quasi_static_padframe_aon_pad_io0_cfg_driving_strength_get() {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO0_CFG_DRIVING_STRENGTH_FIELD);
}

void quasi_static_padframe_aon_pad_io0_cfg_output_en_set(uint8_t value) {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO0_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t quasi_static_padframe_aon_pad_io0_cfg_output_en_get() {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO0_CFG_OUTPUT_EN_BIT);
}

void quasi_static_padframe_aon_pad_io0_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO0_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t quasi_static_padframe_aon_pad_io0_cfg_pull_up_en_get() {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO0_CFG_PULL_UP_EN_BIT);
}

void quasi_static_padframe_aon_pad_io0_mux_set(quasi_static_padframe_aon_pad_io0_mux_sel_t mux_sel) {
  const uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO0_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

quasi_static_padframe_aon_pad_io0_mux_sel_t quasi_static_padframe_aon_pad_io0_mux_get() {
  const uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO0_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}

void quasi_static_padframe_aon_pad_io1_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO1_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t quasi_static_padframe_aon_pad_io1_cfg_chip2pad_get() {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO1_CFG_CHIP2PAD_BIT);
}

void quasi_static_padframe_aon_pad_io1_cfg_driving_strength_set(uint8_t value) {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO1_CFG_DRIVING_STRENGTH_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t quasi_static_padframe_aon_pad_io1_cfg_driving_strength_get() {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO1_CFG_DRIVING_STRENGTH_FIELD);
}

void quasi_static_padframe_aon_pad_io1_cfg_output_en_set(uint8_t value) {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO1_CFG_OUTPUT_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t quasi_static_padframe_aon_pad_io1_cfg_output_en_get() {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO1_CFG_OUTPUT_EN_BIT);
}

void quasi_static_padframe_aon_pad_io1_cfg_pull_up_en_set(uint8_t value) {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO1_CFG_PULL_UP_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t quasi_static_padframe_aon_pad_io1_cfg_pull_up_en_get() {
  uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO1_CFG_PULL_UP_EN_BIT);
}

void quasi_static_padframe_aon_pad_io1_mux_set(quasi_static_padframe_aon_pad_io1_mux_sel_t mux_sel) {
  const uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO1_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 3);
}

quasi_static_padframe_aon_pad_io1_mux_sel_t quasi_static_padframe_aon_pad_io1_mux_get() {
  const uint32_t address = QUASI_STATIC_PADFRAME_BASE_ADDRESS + QUASI_STATIC_PADFRAME_AON_CONFIG_PAD_IO1_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 3;
}
