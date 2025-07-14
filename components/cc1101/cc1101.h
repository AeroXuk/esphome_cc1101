#pragma once

#include <ELECHOUSE_CC1101_SRC_DRV.h>

#include "esphome/core/component.h"
#include "esphome/components/spi/spi.h"

namespace esphome {
namespace cc1101 {

class CC1101Component : public Component,
               public spi::SPIDevice<spi::BIT_ORDER_MSB_FIRST, spi::CLOCK_POLARITY_LOW, spi::CLOCK_PHASE_LEADING,
                                     spi::DATA_RATE_1MHZ> {
 private:
  GPIOPin *gdo0_ {nullptr};
  GPIOPin *gdo2_ {nullptr};
  float frequency_ {868.35};

 public:
  void beginTransmission();
  void endTransmission();
  void setMhz(float freq);

  void setup() override;
  //void loop() override;
  void dump_config() override;

 protected:
  void set_frequency(float freq) { this->frequency_ = freq; }
  void set_gdo0_pin(GPIOPin *pin) { this->gdo0_ = pin; }
  void set_gdo2_pin(GPIOPin *pin) { this->gdo2_ = pin; }
};

} // namespace cc1101
} // namespace esphome