#pragma once

#include <ELECHOUSE_CC1101_SRC_DRV.h>

#include "esphome/core/component.h"
#include "esphome/core/automation.h"

namespace esphome {
namespace cc1101 {

class CC1101Component : public Component {
 public:
  CC1101Component();
  //void loop() override;
  //void dump_config() override;
};

} // namespace cc1101
} // namespace esphome