

#include "kraken_padframe.h"
#define  KRAKEN_PADFRAME_AON_CONFIG0_BASE_ADDR KRAKEN_PADFRAME_BASE_ADDRESS
#include "kraken_padframe_aon_regs.h"
#include "bitfield.h"

#define REG_WRITE32(addr, value) *((volatile uint32_t*) addr) = (uint32_t) value;
#define REG_READ32(addr) *((volatile uint32_t*) addr)


void kraken_padframe_aon_pad_gpioa0_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa0_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa0_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa0_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa0_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa0_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa0_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa0_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa0_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa0_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa0_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa0_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa0_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa0_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa0_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa0_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa0_mux_set(kraken_padframe_aon_pad_gpioa0_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa0_mux_sel_t kraken_padframe_aon_pad_gpioa0_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA0_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa1_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa1_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa1_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa1_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa1_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa1_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa1_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa1_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa1_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa1_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa1_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa1_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa1_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa1_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa1_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa1_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa1_mux_set(kraken_padframe_aon_pad_gpioa1_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa1_mux_sel_t kraken_padframe_aon_pad_gpioa1_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA1_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa2_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa2_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa2_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa2_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa2_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa2_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa2_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa2_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa2_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa2_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa2_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa2_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa2_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa2_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa2_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa2_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa2_mux_set(kraken_padframe_aon_pad_gpioa2_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa2_mux_sel_t kraken_padframe_aon_pad_gpioa2_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA2_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa3_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa3_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa3_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa3_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa3_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa3_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa3_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa3_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa3_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa3_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa3_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa3_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa3_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa3_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa3_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa3_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa3_mux_set(kraken_padframe_aon_pad_gpioa3_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa3_mux_sel_t kraken_padframe_aon_pad_gpioa3_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA3_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa4_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa4_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa4_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa4_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa4_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa4_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa4_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa4_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa4_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa4_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa4_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa4_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa4_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa4_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa4_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa4_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa4_mux_set(kraken_padframe_aon_pad_gpioa4_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa4_mux_sel_t kraken_padframe_aon_pad_gpioa4_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA4_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa5_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa5_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa5_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa5_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa5_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa5_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa5_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa5_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa5_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa5_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa5_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa5_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa5_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa5_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa5_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa5_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa5_mux_set(kraken_padframe_aon_pad_gpioa5_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa5_mux_sel_t kraken_padframe_aon_pad_gpioa5_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA5_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa6_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa6_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa6_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa6_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa6_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa6_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa6_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa6_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa6_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa6_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa6_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa6_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa6_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa6_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa6_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa6_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa6_mux_set(kraken_padframe_aon_pad_gpioa6_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa6_mux_sel_t kraken_padframe_aon_pad_gpioa6_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA6_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa7_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa7_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa7_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa7_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa7_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa7_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa7_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa7_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa7_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa7_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa7_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa7_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa7_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa7_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa7_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa7_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa7_mux_set(kraken_padframe_aon_pad_gpioa7_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa7_mux_sel_t kraken_padframe_aon_pad_gpioa7_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA7_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa8_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa8_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa8_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa8_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa8_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa8_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa8_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa8_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa8_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa8_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa8_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa8_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa8_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa8_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa8_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa8_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa8_mux_set(kraken_padframe_aon_pad_gpioa8_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa8_mux_sel_t kraken_padframe_aon_pad_gpioa8_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA8_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa9_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa9_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa9_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa9_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa9_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa9_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa9_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa9_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa9_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa9_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa9_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa9_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa9_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa9_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa9_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa9_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa9_mux_set(kraken_padframe_aon_pad_gpioa9_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa9_mux_sel_t kraken_padframe_aon_pad_gpioa9_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA9_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa10_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa10_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa10_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa10_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa10_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa10_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa10_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa10_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa10_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa10_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa10_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa10_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa10_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa10_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa10_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa10_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa10_mux_set(kraken_padframe_aon_pad_gpioa10_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa10_mux_sel_t kraken_padframe_aon_pad_gpioa10_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA10_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa11_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa11_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa11_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa11_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa11_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa11_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa11_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa11_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa11_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa11_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa11_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa11_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa11_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa11_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa11_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa11_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa11_mux_set(kraken_padframe_aon_pad_gpioa11_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa11_mux_sel_t kraken_padframe_aon_pad_gpioa11_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA11_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa12_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa12_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa12_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa12_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa12_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa12_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa12_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa12_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa12_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa12_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa12_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa12_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa12_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa12_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa12_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa12_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa12_mux_set(kraken_padframe_aon_pad_gpioa12_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa12_mux_sel_t kraken_padframe_aon_pad_gpioa12_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA12_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa13_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa13_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa13_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa13_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa13_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa13_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa13_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa13_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa13_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa13_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa13_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa13_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa13_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa13_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa13_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa13_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa13_mux_set(kraken_padframe_aon_pad_gpioa13_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa13_mux_sel_t kraken_padframe_aon_pad_gpioa13_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA13_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa14_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa14_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa14_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa14_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa14_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa14_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa14_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa14_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa14_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa14_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa14_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa14_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa14_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa14_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa14_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa14_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa14_mux_set(kraken_padframe_aon_pad_gpioa14_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa14_mux_sel_t kraken_padframe_aon_pad_gpioa14_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA14_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa15_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa15_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa15_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa15_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa15_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa15_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa15_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa15_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa15_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa15_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa15_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa15_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa15_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa15_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa15_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa15_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa15_mux_set(kraken_padframe_aon_pad_gpioa15_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa15_mux_sel_t kraken_padframe_aon_pad_gpioa15_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA15_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa16_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa16_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa16_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa16_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa16_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa16_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa16_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa16_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa16_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa16_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa16_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa16_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa16_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa16_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa16_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa16_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa16_mux_set(kraken_padframe_aon_pad_gpioa16_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa16_mux_sel_t kraken_padframe_aon_pad_gpioa16_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA16_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa17_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa17_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa17_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa17_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa17_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa17_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa17_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa17_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa17_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa17_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa17_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa17_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa17_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa17_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa17_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa17_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa17_mux_set(kraken_padframe_aon_pad_gpioa17_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa17_mux_sel_t kraken_padframe_aon_pad_gpioa17_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA17_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa18_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa18_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa18_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa18_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa18_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa18_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa18_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa18_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa18_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa18_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa18_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa18_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa18_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa18_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa18_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa18_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa18_mux_set(kraken_padframe_aon_pad_gpioa18_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa18_mux_sel_t kraken_padframe_aon_pad_gpioa18_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA18_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa19_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa19_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa19_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa19_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa19_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa19_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa19_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa19_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa19_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa19_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa19_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa19_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa19_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa19_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa19_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa19_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa19_mux_set(kraken_padframe_aon_pad_gpioa19_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa19_mux_sel_t kraken_padframe_aon_pad_gpioa19_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA19_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa20_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa20_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa20_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa20_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa20_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa20_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa20_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa20_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa20_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa20_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa20_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa20_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa20_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa20_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa20_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa20_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa20_mux_set(kraken_padframe_aon_pad_gpioa20_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa20_mux_sel_t kraken_padframe_aon_pad_gpioa20_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA20_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa21_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa21_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa21_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa21_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa21_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa21_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa21_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa21_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa21_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa21_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa21_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa21_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa21_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa21_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa21_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa21_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa21_mux_set(kraken_padframe_aon_pad_gpioa21_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa21_mux_sel_t kraken_padframe_aon_pad_gpioa21_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA21_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa22_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa22_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa22_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa22_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa22_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa22_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa22_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa22_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa22_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa22_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa22_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa22_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa22_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa22_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa22_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa22_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa22_mux_set(kraken_padframe_aon_pad_gpioa22_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa22_mux_sel_t kraken_padframe_aon_pad_gpioa22_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA22_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa23_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa23_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa23_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa23_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa23_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa23_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa23_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa23_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa23_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa23_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa23_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa23_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa23_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa23_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa23_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa23_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa23_mux_set(kraken_padframe_aon_pad_gpioa23_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa23_mux_sel_t kraken_padframe_aon_pad_gpioa23_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA23_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa24_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa24_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa24_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa24_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa24_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa24_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa24_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa24_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa24_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa24_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa24_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa24_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa24_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa24_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa24_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa24_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa24_mux_set(kraken_padframe_aon_pad_gpioa24_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa24_mux_sel_t kraken_padframe_aon_pad_gpioa24_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA24_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpioa25_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa25_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpioa25_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa25_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpioa25_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa25_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpioa25_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa25_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpioa25_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa25_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpioa25_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa25_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpioa25_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa25_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpioa25_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpioa25_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpioa25_mux_set(kraken_padframe_aon_pad_gpioa25_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpioa25_mux_sel_t kraken_padframe_aon_pad_gpioa25_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOA25_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpiob0_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob0_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpiob0_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob0_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpiob0_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob0_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpiob0_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob0_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpiob0_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob0_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpiob0_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob0_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpiob0_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob0_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpiob0_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob0_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpiob0_mux_set(kraken_padframe_aon_pad_gpiob0_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpiob0_mux_sel_t kraken_padframe_aon_pad_gpiob0_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB0_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpiob1_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob1_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpiob1_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob1_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpiob1_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob1_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpiob1_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob1_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpiob1_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob1_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpiob1_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob1_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpiob1_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob1_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpiob1_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob1_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpiob1_mux_set(kraken_padframe_aon_pad_gpiob1_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpiob1_mux_sel_t kraken_padframe_aon_pad_gpiob1_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB1_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpiob2_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob2_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpiob2_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob2_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpiob2_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob2_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpiob2_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob2_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpiob2_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob2_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpiob2_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob2_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpiob2_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob2_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpiob2_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob2_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpiob2_mux_set(kraken_padframe_aon_pad_gpiob2_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpiob2_mux_sel_t kraken_padframe_aon_pad_gpiob2_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB2_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpiob3_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob3_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpiob3_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob3_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpiob3_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob3_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpiob3_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob3_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpiob3_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob3_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpiob3_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob3_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpiob3_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob3_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpiob3_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob3_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpiob3_mux_set(kraken_padframe_aon_pad_gpiob3_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpiob3_mux_sel_t kraken_padframe_aon_pad_gpiob3_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB3_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpiob4_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob4_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpiob4_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob4_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpiob4_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob4_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpiob4_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob4_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpiob4_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob4_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpiob4_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob4_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpiob4_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob4_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpiob4_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob4_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpiob4_mux_set(kraken_padframe_aon_pad_gpiob4_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpiob4_mux_sel_t kraken_padframe_aon_pad_gpiob4_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB4_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpiob5_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob5_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpiob5_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob5_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpiob5_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob5_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpiob5_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob5_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpiob5_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob5_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpiob5_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob5_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpiob5_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob5_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpiob5_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob5_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpiob5_mux_set(kraken_padframe_aon_pad_gpiob5_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpiob5_mux_sel_t kraken_padframe_aon_pad_gpiob5_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB5_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpiob6_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob6_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpiob6_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob6_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpiob6_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob6_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpiob6_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob6_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpiob6_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob6_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpiob6_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob6_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpiob6_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob6_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpiob6_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob6_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpiob6_mux_set(kraken_padframe_aon_pad_gpiob6_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpiob6_mux_sel_t kraken_padframe_aon_pad_gpiob6_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB6_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpiob7_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob7_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpiob7_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob7_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpiob7_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob7_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpiob7_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob7_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpiob7_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob7_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpiob7_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob7_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpiob7_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob7_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpiob7_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob7_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpiob7_mux_set(kraken_padframe_aon_pad_gpiob7_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpiob7_mux_sel_t kraken_padframe_aon_pad_gpiob7_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB7_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpiob8_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob8_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpiob8_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob8_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpiob8_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob8_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpiob8_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob8_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpiob8_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob8_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpiob8_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob8_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpiob8_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob8_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpiob8_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob8_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpiob8_mux_set(kraken_padframe_aon_pad_gpiob8_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpiob8_mux_sel_t kraken_padframe_aon_pad_gpiob8_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB8_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpiob9_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob9_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpiob9_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob9_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpiob9_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob9_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpiob9_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob9_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpiob9_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob9_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpiob9_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob9_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpiob9_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob9_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpiob9_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob9_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpiob9_mux_set(kraken_padframe_aon_pad_gpiob9_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpiob9_mux_sel_t kraken_padframe_aon_pad_gpiob9_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB9_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpiob10_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob10_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpiob10_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob10_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpiob10_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob10_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpiob10_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob10_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpiob10_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob10_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpiob10_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob10_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpiob10_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob10_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpiob10_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob10_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpiob10_mux_set(kraken_padframe_aon_pad_gpiob10_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpiob10_mux_sel_t kraken_padframe_aon_pad_gpiob10_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB10_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpiob11_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob11_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpiob11_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob11_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpiob11_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob11_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpiob11_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob11_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpiob11_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob11_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpiob11_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob11_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpiob11_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob11_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpiob11_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob11_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpiob11_mux_set(kraken_padframe_aon_pad_gpiob11_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpiob11_mux_sel_t kraken_padframe_aon_pad_gpiob11_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB11_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpiob12_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob12_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpiob12_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob12_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpiob12_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob12_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpiob12_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob12_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpiob12_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob12_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpiob12_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob12_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpiob12_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob12_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpiob12_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob12_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpiob12_mux_set(kraken_padframe_aon_pad_gpiob12_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpiob12_mux_sel_t kraken_padframe_aon_pad_gpiob12_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB12_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpiob13_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob13_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpiob13_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob13_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpiob13_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob13_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpiob13_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob13_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpiob13_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob13_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpiob13_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob13_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpiob13_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob13_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpiob13_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob13_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpiob13_mux_set(kraken_padframe_aon_pad_gpiob13_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpiob13_mux_sel_t kraken_padframe_aon_pad_gpiob13_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB13_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpiob14_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob14_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpiob14_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob14_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpiob14_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob14_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpiob14_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob14_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpiob14_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob14_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpiob14_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob14_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpiob14_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob14_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpiob14_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob14_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpiob14_mux_set(kraken_padframe_aon_pad_gpiob14_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpiob14_mux_sel_t kraken_padframe_aon_pad_gpiob14_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB14_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}

void kraken_padframe_aon_pad_gpiob15_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob15_cfg_chip2pad_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_CHIP2PAD_BIT);
}

void kraken_padframe_aon_pad_gpiob15_cfg_drv_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_field32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_DRV_FIELD, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob15_cfg_drv_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_field32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_DRV_FIELD);
}

void kraken_padframe_aon_pad_gpiob15_cfg_pde_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_PDE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob15_cfg_pde_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_PDE_BIT);
}

void kraken_padframe_aon_pad_gpiob15_cfg_pue_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_PUE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob15_cfg_pue_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_PUE_BIT);
}

void kraken_padframe_aon_pad_gpiob15_cfg_rxe_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_RXE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob15_cfg_rxe_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_RXE_BIT);
}

void kraken_padframe_aon_pad_gpiob15_cfg_slw_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_SLW_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob15_cfg_slw_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_SLW_BIT);
}

void kraken_padframe_aon_pad_gpiob15_cfg_smt_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_SMT_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob15_cfg_smt_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_SMT_BIT);
}

void kraken_padframe_aon_pad_gpiob15_cfg_trie_set(uint8_t value) {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_TRIE_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t kraken_padframe_aon_pad_gpiob15_cfg_trie_get() {
  uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_CFG_TRIE_BIT);
}

void kraken_padframe_aon_pad_gpiob15_mux_set(kraken_padframe_aon_pad_gpiob15_mux_sel_t mux_sel) {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 63);
}

kraken_padframe_aon_pad_gpiob15_mux_sel_t kraken_padframe_aon_pad_gpiob15_mux_get() {
  const uint32_t address = KRAKEN_PADFRAME_BASE_ADDRESS + KRAKEN_PADFRAME_AON_CONFIG_PAD_GPIOB15_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 63;
}
