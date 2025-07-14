#pragma once

#include <ELECHOUSE_CC1101_SRC_DRV.h>

#include "esphome/core/component.h"
#include "esphome/components/gpio/gpio.h"
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
  void set_clock_pin(GPIOPin *pin) { this->clk_pin_ = pin; }
  void set_miso_pin(GPIOPin *pin) { this->sdi_pin_ = pin; }
  void set_mosi_pin(GPIOPin *pin) { this->sdo_pin_ = pin; }
  void set_select_pin(GPIOPin *pin) { this->cs_ = pin; }

  void set_gdo0_pin(GPIOPin *pin) { this->gdo0_ = pin; }
  void set_gdo2_pin(GPIOPin *pin) { this->gdo2_ = pin; }
  void set_frequency(float freq) { this->frequency_ = freq; }

  // Api
  void beginTransmission();
  void endTransmission();
  void setMhz(float freq);

 protected:
  GPIOPin *clk_pin_ {nullptr};
  GPIOPin *sdi_pin_ {nullptr};
  GPIOPin *sdo_pin_ {nullptr};
  GPIOPin *cs_ {nullptr};
  GPIOPin *gdo0_ {nullptr};
  GPIOPin *gdo2_ {nullptr};
  float frequency_ {868.35};
};

} // namespace cc1101
} // namespace esphome