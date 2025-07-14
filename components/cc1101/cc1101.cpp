#include "cc1101.h"
#include "esphome/core/log.h"

namespace esphome {
namespace cc1101 {

static const char *const TAG = "cc1101";

void CC1101Component::beginTransmission() {
  ELECHOUSE_cc1101.SetTx();
};

void CC1101Component::endTransmission() {
  ELECHOUSE_cc1101.setSidle();
};

void CC1101Component::beginReception() {
  ELECHOUSE_cc1101.SetRx();
};

void CC1101Component::endReception() {
  ELECHOUSE_cc1101.setSidle();
};

void CC1101Component::setPa(int power) {
  ELECHOUSE_cc1101.setPA(power);
};

void CC1101Component::setMhz(float freq) {
  ELECHOUSE_cc1101.setMHZ(freq);
};

void CC1101Component::setup() {
  ESP_LOGD(TAG, "Setting up CC1101...");

  // Register with ESPHome runtime
  App.register_component(this);

  // Setup Pins
  ELECHOUSE_cc1101.setSpiPin(this->clk_pin_, this->sdi_pin_, this->sdo_pin_, this->cs_);
  if (this->gdo0_ != 0 && this->gdo2_ != 0) {
    ELECHOUSE_cc1101.setGDO(this->gdo0_, this->gdo2_);
  } else if(this->gdo0_ != 0) {
    ELECHOUSE_cc1101.setGDO0(this->gdo0_);
  }

  // Test Chip
  if (ELECHOUSE_cc1101.getCC1101()) {
    ESP_LOGD("custom", "CC1101 Connection OK.");
  }
  else {
    ESP_LOGD("custom", "CC1101 Connection Error.");
  }
  
  // Init Chip
  ELECHOUSE_cc1101.Init();
  ELECHOUSE_cc1101.setPA(10);
  ELECHOUSE_cc1101.setMHZ(this->frequency_);
  ELECHOUSE_cc1101.setModulation(2); // 2 = ASK/OOK
  ELECHOUSE_cc1101.setPktFormat(3); // 3 = Async Serial
  ELECHOUSE_cc1101.setSidle();
  ELECHOUSE_cc1101.SetRx();

  ESP_LOGD(TAG, "CC1101 started!");
};

void CC1101Component::loop() {
  // Not currently used
};

void CC1101Component::dump_config() {
  ESP_LOGCONFIG(TAG, "CC1101:");
  ESP_LOGCONFIG(TAG, "  CLK  Pin:  ", this->clk_pin_);
  ESP_LOGCONFIG(TAG, "  SDI  Pin:  ", this->sdi_pin_);
  ESP_LOGCONFIG(TAG, "  SDO  Pin:  ", this->sdo_pin_);
  ESP_LOGCONFIG(TAG, "  CSN  Pin:  ", this->cs_);
  ESP_LOGCONFIG(TAG, "  GDO0 Pin:  ", this->gdo0_);
  ESP_LOGCONFIG(TAG, "  GDO2 Pin:  ", this->gdo2_);
  ESP_LOGCONFIG(TAG, "  Frequency: %.2f MHz", this->frequency_);
};

} // namespace cc1101
} // namespace esphome