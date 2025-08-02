#include <Arduino.h>

#include "config/conf.h"
#include "logging/logger.h"

#include "io/leds/led.h"

leds::Led *led;

void setup() {
  logging::logger->Initialize();
  logging::logger->Info("Setting up system");

  led = new leds::Led(config::LED_PIN, config::LED_CHANNEL,
                      config::LED_FREQUENCY, config::LED_RESOLUTION);

  logging::logger->Info("System initialized successfully");
}

void loop() {
  for (int i = 0; i < 255; i++) {
    led->Set(i);
    delay(15);
  }

  for (int i = 255; i >= 0; i--) {
    led->Set(i);
    delay(15);
  }
}
