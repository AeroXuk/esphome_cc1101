#pragma once

#include <ELECHOUSE_CC1101_SRC_DRV.h>

#include "esphome/core/component.h"
#include "esphome/core/automation.h"

namespace esphome {
namespace cc1101 {

/*
src/main.cpp:260:16: error: 'class esphome::cc1101::CC1101Component' has no member named 'set_spi_parent'
  260 |   cc1101_chip->set_spi_parent(spi_spicomponent_id);
      |                ^~~~~~~~~~~~~~
src/main.cpp:265:16: error: 'class esphome::cc1101::CC1101Component' has no member named 'set_cs_pin'
  265 |   cc1101_chip->set_cs_pin(rp2040_rp2040gpiopin_id_4);
      |                ^~~~~~~~~~
src/main.cpp:266:16: error: 'class esphome::cc1101::CC1101Component' has no member named 'set_data_rate'
  266 |   cc1101_chip->set_data_rate(spi::DATA_RATE_200KHZ);
*/

class CC1101Component : public Component,
               public spi::SPIDevice<spi::BIT_ORDER_MSB_FIRST, spi::CLOCK_POLARITY_LOW, spi::CLOCK_PHASE_LEADING,
                                     spi::DATA_RATE_1MHZ> {
 public:
  CC1101Component();
  //void loop() override;
  //void dump_config() override;
};

} // namespace cc1101
} // namespace esphome