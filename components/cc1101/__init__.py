from esphome import pins
#from esphome.components import spi
import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import (
    CONF_ID,
    CONF_CLK_PIN,
    CONF_MISO_PIN,
    CONF_MOSI_PIN,
    CONF_CS_PIN,
    CONF_FREQUENCY
)

CONF_GDO0_PIN = "gdo0_pin"
CONF_GDO2_PIN = "gdo2_pin"

#DEPENDENCIES = ["spi"]
CODEOWNERS = ["@AeroXuk"]

cc1101_ns = cg.esphome_ns.namespace("cc1101")
CC1101Component = cc1101_ns.class_(
    "CC1101Component", cg.Component
)

CONFIG_SCHEMA = cv.All(
    cv.Schema(
        {
            cv.GenerateID(CONF_ID): cv.declare_id(CC1101Component),
            cv.Required(CONF_CLK_PIN): pins.internal_gpio_output_pin_number,
            cv.Required(CONF_MISO_PIN): pins.internal_gpio_input_pin_number,
            cv.Required(CONF_MOSI_PIN): pins.internal_gpio_output_pin_number,
            cv.Required(CONF_CS_PIN): pins.internal_gpio_output_pin_number,
            cv.Optional(CONF_GDO0_PIN): pins.internal_gpio_output_pin_number,
            cv.Optional(CONF_GDO2_PIN): pins.internal_gpio_input_pin_number,
            cv.Required(CONF_FREQUENCY): cv.float_
        }
    )
    .extend(cv.COMPONENT_SCHEMA)
    #.extend(spi.spi_device_schema(False, "1MHz"))
)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])

    cg.add(var.set_clock_pin(config[CONF_CLK_PIN]))
    cg.add(var.set_miso_pin(config[CONF_MISO_PIN]))
    cg.add(var.set_mosi_pin(config[CONF_MOSI_PIN]))
    cg.add(var.set_select_pin(config[CONF_CS_PIN]))

    if CONF_GDO0_PIN in config:
        cg.add(var.set_gdo0_pin(config[CONF_GDO0_PIN]))

    if CONF_GDO2_PIN in config:
        cg.add(var.set_gdo2_pin(config[CONF_GDO2_PIN]))

    cg.add(var.set_frequency(config[CONF_FREQUENCY]))

    #await spi.register_spi_device(var, config)
    await cg.register_component(var, config)
