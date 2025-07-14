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

  //ELECHOUSE_cc1101.setMHZ(this->frequency_);

  ESP_LOGD(TAG, "CC1101 started!");
};

void CC1101Component::dump_config() {
  this->parent_->dump_config();

  ESP_LOGCONFIG(TAG, "CC1101:");
  LOG_PIN("  CSN  Pin:  ", this->cs_);
  LOG_PIN("  GDO0 Pin:  ", this->gdo0_);
  LOG_PIN("  GDO2 Pin:  ", this->gdo2_);
  ESP_LOGCONFIG(TAG, "  Frequency: %.2f MHz", this->frequency_);
  
  ESP_LOGCONFIG(TAG, "  SPI Settings:");
  ESP_LOGCONFIG(TAG, "    Bit Order: %s",
    (this->bit_order == spi::BIT_ORDER_MSB_FIRST ? "MSB First" : "LSB First"));
  ESP_LOGCONFIG(TAG, "    Clock Polarity: %s",
    (this->clock_polarity == spi::CLOCK_POLARITY_LOW ? "Low (Idle Low)" : "High (Idle High)"));
  ESP_LOGCONFIG(TAG, "    Clock Phase: %s",
    (this->clock_phase == spi::CLOCK_PHASE_LEADING ? "Leading Edge (Mode 0/2)" : "Trailing Edge (Mode 1/3)"));
    
  if (this->data_rate_ >= spi::DATA_RATE_1MHZ) {
    ESP_LOGCONFIG(TAG, "    Data Rate: %uMHz", (unsigned) (this->data_rate_ / 1000000));
  } else {
    ESP_LOGCONFIG(TAG, "    Data Rate: %ukHz", (unsigned) (this->data_rate_ / 1000));
  }
};

} // namespace cc1101
} // namespace esphome