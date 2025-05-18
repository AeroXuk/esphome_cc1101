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

void CC1101Component::setMhz(float freq) {
  ELECHOUSE_cc1101.setMHZ(freq);
};

void CC1101Component::setup() {
  ESP_LOGD(TAG, "Setting up CC1101...");
  this->spi_setup();

  // ELECHOUSE_cc1101.setMHZ(freq);

  ESP_LOGD(TAG, "CC1101 started!");
};

void CC1101Component::dump_config() {
  ESP_LOGCONFIG(TAG, "CC1101:");

  LOG_PIN("  SCK  Pin:  ", this->sck_pin_);
  LOG_PIN("  MISO Pin:  ", this->miso_pin_);
  LOG_PIN("  MOSI Pin:  ", this->mosi_pin_);

  LOG_PIN("  CSN  Pin:  ", this->cs_pin_);
  LOG_PIN("  GDO0 Pin:  ", this->gdo0_pin_);
  LOG_PIN("  GDO2 Pin:  ", this->gdo2_pin_);

  ESP_LOGCONFIG(TAG, "  Frequency: %.2f MHz", this->frequency_);
  
  if (this->data_rate_ >= spi::DATA_RATE_1MHZ) {
    ESP_LOGCONFIG(TAG, "  Data rate: %uMHz", (unsigned) (this->data_rate_ / 1000000));
  } else {
    ESP_LOGCONFIG(TAG, "  Data rate: %ukHz", (unsigned) (this->data_rate_ / 1000));
  }
};

} // namespace cc1101
} // namespace esphome