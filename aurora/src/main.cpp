#include <Arduino.h>

#include "config/conf.h"
#include "logging/logger.h"

#include "io/displays/lcd1602_i2c.h"
#include "io/leds/led.h"
#include "io/voltage_dividers/ldr.h"

displays::Lcd1602I2c *lcd;
leds::Led *led;
voltage_dividers::Ldr *ldr;

void setup() {
  logging::logger->Initialize();
  logging::logger->Info("Setting up system");

  led =
      new leds::Led(config::LED_PIN, config::LED_CHANNEL, config::LED_FREQUENCY,
                    config::LED_RESOLUTION, config::LED_INITIAL_VALUE);

  ldr = new voltage_dividers::Ldr(
      config::LDR_PIN, config::LDR_SUPPLY_VOLTAGE, config::LDR_RESOLUTION,
      config::LDR_FIXED_RESISTANCE, config::LDR_RESISTANCE_AT_1_LUX,
      config::LDR_GAMMA);

  lcd = new displays::Lcd1602I2c(config::LCD_ADDRESS, config::LCD_COLS,
                                 config::LCD_ROWS);

  logging::logger->Info("System initialized successfully");
}

void loop() {
  lcd->DisplayStatus(config::SET_POINT, ldr->ReadLuminosity());
  // logging::logger->Info(String(ldr->ReadResistance()));
  delay(1000);
}
