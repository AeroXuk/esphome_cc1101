#pragma once

#include <ELECHOUSE_CC1101_SRC_DRV.h>

#include "esphome/core/component.h"
//#include "esphome/core/gpio.h"
//#include "esphome/components/spi/spi.h"

namespace esphome {
namespace cc1101 {

//public spi::SPIDevice<spi::BIT_ORDER_MSB_FIRST, spi::CLOCK_POLARITY_LOW, spi::CLOCK_PHASE_LEADING, spi::DATA_RATE_1MHZ>
class CC1101Component : public Component {
 public:
  // Overrides
  void setup() override;
  void loop() override;
  void dump_config() override;

  // Setup Methods
  void set_clock_pin(int pin) { this->clk_pin_ = pin; }
  void set_miso_pin(int pin) { this->sdi_pin_ = pin; }
  void set_mosi_pin(int pin) { this->sdo_pin_ = pin; }
  void set_select_pin(int pin) { this->cs_ = pin; }

  void set_gdo0_pin(int pin) { this->gdo0_ = pin; }
  void set_gdo2_pin(int pin) { this->gdo2_ = pin; }
  void set_frequency(float freq) { this->frequency_ = freq; }

  // Api
  void beginTransmission();
  void endTransmission();
  void setMhz(float freq);

 protected:
  int clk_pin_ {0};
  int sdi_pin_ {0};
  int sdo_pin_ {0};
  int cs_ {0};
  int gdo0_ {0};
  int gdo2_ {0};
  float frequency_ {868.35};
};

} // namespace cc1101
} // namespace esphome