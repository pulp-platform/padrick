

#include "modular_padframe.h"
#define  MODULAR_PADFRAME_DOMAIN_CONFIG0_BASE_ADDR MODULAR_PADFRAME_BASE_ADDRESS
#include "modular_padframe_domain_regs.h"
#include "bitfield.h"

#define REG_WRITE32(addr, value) *((volatile uint32_t*) addr) = (uint32_t) value;
#define REG_READ32(addr) *((volatile uint32_t*) addr)


void modular_padframe_domain_pad_io00_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO00_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO00_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io00_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO00_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO00_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io00_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO00_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO00_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io00_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO00_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO00_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io00_mux_set(modular_padframe_domain_pad_io00_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO00_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io00_mux_sel_t modular_padframe_domain_pad_io00_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO00_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io01_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO01_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO01_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io01_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO01_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO01_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io01_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO01_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO01_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io01_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO01_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO01_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io01_mux_set(modular_padframe_domain_pad_io01_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO01_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io01_mux_sel_t modular_padframe_domain_pad_io01_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO01_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io02_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO02_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO02_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io02_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO02_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO02_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io02_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO02_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO02_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io02_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO02_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO02_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io02_mux_set(modular_padframe_domain_pad_io02_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO02_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io02_mux_sel_t modular_padframe_domain_pad_io02_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO02_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io03_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO03_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO03_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io03_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO03_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO03_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io03_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO03_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO03_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io03_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO03_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO03_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io03_mux_set(modular_padframe_domain_pad_io03_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO03_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io03_mux_sel_t modular_padframe_domain_pad_io03_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO03_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io04_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO04_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO04_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io04_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO04_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO04_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io04_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO04_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO04_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io04_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO04_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO04_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io04_mux_set(modular_padframe_domain_pad_io04_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO04_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io04_mux_sel_t modular_padframe_domain_pad_io04_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO04_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io05_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO05_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO05_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io05_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO05_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO05_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io05_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO05_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO05_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io05_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO05_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO05_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io05_mux_set(modular_padframe_domain_pad_io05_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO05_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io05_mux_sel_t modular_padframe_domain_pad_io05_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO05_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io06_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO06_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO06_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io06_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO06_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO06_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io06_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO06_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO06_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io06_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO06_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO06_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io06_mux_set(modular_padframe_domain_pad_io06_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO06_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io06_mux_sel_t modular_padframe_domain_pad_io06_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO06_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io07_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO07_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO07_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io07_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO07_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO07_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io07_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO07_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO07_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io07_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO07_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO07_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io07_mux_set(modular_padframe_domain_pad_io07_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO07_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io07_mux_sel_t modular_padframe_domain_pad_io07_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO07_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io08_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO08_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO08_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io08_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO08_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO08_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io08_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO08_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO08_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io08_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO08_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO08_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io08_mux_set(modular_padframe_domain_pad_io08_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO08_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io08_mux_sel_t modular_padframe_domain_pad_io08_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO08_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io09_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO09_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO09_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io09_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO09_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO09_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io09_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO09_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO09_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io09_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO09_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO09_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io09_mux_set(modular_padframe_domain_pad_io09_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO09_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io09_mux_sel_t modular_padframe_domain_pad_io09_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO09_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io10_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO10_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io10_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO10_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io10_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO10_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io10_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO10_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO10_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io10_mux_set(modular_padframe_domain_pad_io10_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO10_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io10_mux_sel_t modular_padframe_domain_pad_io10_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO10_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io11_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO11_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io11_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO11_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io11_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO11_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io11_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO11_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO11_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io11_mux_set(modular_padframe_domain_pad_io11_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO11_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io11_mux_sel_t modular_padframe_domain_pad_io11_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO11_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io12_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO12_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io12_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO12_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io12_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO12_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io12_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO12_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO12_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io12_mux_set(modular_padframe_domain_pad_io12_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO12_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io12_mux_sel_t modular_padframe_domain_pad_io12_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO12_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io13_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO13_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io13_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO13_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io13_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO13_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io13_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO13_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO13_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io13_mux_set(modular_padframe_domain_pad_io13_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO13_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io13_mux_sel_t modular_padframe_domain_pad_io13_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO13_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io14_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO14_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io14_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO14_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io14_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO14_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io14_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO14_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO14_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io14_mux_set(modular_padframe_domain_pad_io14_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO14_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io14_mux_sel_t modular_padframe_domain_pad_io14_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO14_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io15_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO15_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io15_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO15_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io15_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO15_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io15_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO15_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO15_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io15_mux_set(modular_padframe_domain_pad_io15_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO15_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io15_mux_sel_t modular_padframe_domain_pad_io15_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO15_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io16_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO16_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io16_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO16_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io16_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO16_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io16_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO16_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO16_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io16_mux_set(modular_padframe_domain_pad_io16_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO16_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io16_mux_sel_t modular_padframe_domain_pad_io16_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO16_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io17_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO17_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io17_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO17_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io17_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO17_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io17_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO17_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO17_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io17_mux_set(modular_padframe_domain_pad_io17_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO17_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io17_mux_sel_t modular_padframe_domain_pad_io17_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO17_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io18_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO18_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io18_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO18_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io18_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO18_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io18_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO18_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO18_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io18_mux_set(modular_padframe_domain_pad_io18_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO18_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io18_mux_sel_t modular_padframe_domain_pad_io18_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO18_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io19_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO19_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io19_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO19_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io19_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO19_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io19_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO19_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO19_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io19_mux_set(modular_padframe_domain_pad_io19_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO19_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io19_mux_sel_t modular_padframe_domain_pad_io19_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO19_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io20_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO20_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io20_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO20_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io20_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO20_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io20_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO20_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO20_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io20_mux_set(modular_padframe_domain_pad_io20_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO20_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io20_mux_sel_t modular_padframe_domain_pad_io20_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO20_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io21_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO21_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io21_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO21_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io21_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO21_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io21_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO21_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO21_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io21_mux_set(modular_padframe_domain_pad_io21_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO21_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io21_mux_sel_t modular_padframe_domain_pad_io21_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO21_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io22_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO22_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io22_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO22_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io22_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO22_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io22_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO22_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO22_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io22_mux_set(modular_padframe_domain_pad_io22_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO22_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io22_mux_sel_t modular_padframe_domain_pad_io22_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO22_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io23_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO23_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io23_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO23_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io23_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO23_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io23_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO23_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO23_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io23_mux_set(modular_padframe_domain_pad_io23_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO23_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io23_mux_sel_t modular_padframe_domain_pad_io23_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO23_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io24_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO24_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io24_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO24_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io24_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO24_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io24_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO24_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO24_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io24_mux_set(modular_padframe_domain_pad_io24_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO24_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io24_mux_sel_t modular_padframe_domain_pad_io24_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO24_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io25_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO25_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io25_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO25_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io25_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO25_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io25_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO25_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO25_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io25_mux_set(modular_padframe_domain_pad_io25_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO25_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io25_mux_sel_t modular_padframe_domain_pad_io25_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO25_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io26_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO26_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO26_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io26_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO26_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO26_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io26_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO26_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO26_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io26_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO26_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO26_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io26_mux_set(modular_padframe_domain_pad_io26_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO26_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io26_mux_sel_t modular_padframe_domain_pad_io26_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO26_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io27_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO27_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO27_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io27_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO27_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO27_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io27_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO27_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO27_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io27_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO27_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO27_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io27_mux_set(modular_padframe_domain_pad_io27_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO27_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io27_mux_sel_t modular_padframe_domain_pad_io27_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO27_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io28_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO28_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO28_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io28_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO28_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO28_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io28_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO28_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO28_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io28_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO28_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO28_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io28_mux_set(modular_padframe_domain_pad_io28_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO28_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io28_mux_sel_t modular_padframe_domain_pad_io28_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO28_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io29_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO29_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO29_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io29_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO29_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO29_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io29_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO29_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO29_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io29_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO29_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO29_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io29_mux_set(modular_padframe_domain_pad_io29_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO29_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io29_mux_sel_t modular_padframe_domain_pad_io29_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO29_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io30_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO30_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO30_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io30_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO30_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO30_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io30_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO30_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO30_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io30_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO30_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO30_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io30_mux_set(modular_padframe_domain_pad_io30_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO30_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io30_mux_sel_t modular_padframe_domain_pad_io30_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO30_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}

void modular_padframe_domain_pad_io31_cfg_chip2pad_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO31_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO31_CFG_CHIP2PAD_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io31_cfg_chip2pad_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO31_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO31_CFG_CHIP2PAD_BIT);
}

void modular_padframe_domain_pad_io31_cfg_tx_en_set(uint8_t value) {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO31_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  reg = bitfield_bit32_write(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO31_CFG_TX_EN_BIT, value);
  REG_WRITE32(address, reg);
}

uint8_t modular_padframe_domain_pad_io31_cfg_tx_en_get() {
  uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO31_CFG_REG_OFFSET;
  uint32_t reg = REG_READ32(address);
  return bitfield_bit32_read(reg, MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO31_CFG_TX_EN_BIT);
}

void modular_padframe_domain_pad_io31_mux_set(modular_padframe_domain_pad_io31_mux_sel_t mux_sel) {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO31_MUX_SEL_REG_OFFSET;
  REG_WRITE32(address, mux_sel & 15);
}

modular_padframe_domain_pad_io31_mux_sel_t modular_padframe_domain_pad_io31_mux_get() {
  const uint32_t address = MODULAR_PADFRAME_BASE_ADDRESS + MODULAR_PADFRAME_DOMAIN_CONFIG_PAD_IO31_MUX_SEL_REG_OFFSET;

  return REG_READ32(address) & 15;
}
