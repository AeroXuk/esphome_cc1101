from esphome import automation, pins
from esphome.components import spi
import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import (
    CONF_ID,
    CONF_CLK_PIN,
    CONF_CS_PIN,
    CONF_MISO_PIN,
    CONF_MOSI_PIN,
    CONF_FREQUENCY
)

CONF_GDO0_PIN = "gdo0_pin"
CONF_GDO2_PIN = "gdo2_pin"

DEPENDENCIES = ["spi"]
CODEOWNERS = ["@AeroXuk"]

cc1101_ns = cg.esphome_ns.namespace("cc1101")
CC1101Component = cc1101_ns.class_(
    "CC1101Component", cg.Component, spi.SPIDevice
)

CONFIG_SCHEMA = cv.All(
    cv.Schema(
        {
            cv.GenerateID(CONF_ID): cv.declare_id(CC1101Component),
            cv.Optional(CONF_GDO0_PIN): pins.gpio_output_pin_schema,
            cv.Optional(CONF_GDO2_PIN): pins.gpio_input_pin_schema
        }
    )
    .extend(cv.COMPONENT_SCHEMA)
    .extend(spi.spi_device_schema(False, "200kHz"))
)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.gpio_pin_expression(config[CONF_GDO0_PIN])
    await cg.gpio_pin_expression(config[CONF_GDO2_PIN])
    await spi.register_spi_device(var, config)
    await cg.register_component(var, config)
