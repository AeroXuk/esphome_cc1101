#include "cc1101.h"
#include "esphome/core/log.h"

namespace esphome {
namespace cc1101 {

static const char *const TAG = "cc1101";

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

CC1101Component::CC1101Component() {

};


} // namespace cc1101
} // namespace esphome