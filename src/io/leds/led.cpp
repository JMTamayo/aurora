#include <Arduino.h>

#include "led.h"

namespace leds {

const unsigned int Led::getPin() const { return this->pin; }

const unsigned int Led::getChannel() const { return this->channel; }

const unsigned int Led::getFrequency() const { return this->frequency; }

const unsigned int Led::getResolution() const { return this->resolution; }

const unsigned int Led::highValue() const {
  return (1 << this->resolution) - 1;
}

const unsigned int Led::lowValue() const { return 0; }

Led::Led(unsigned int pin, unsigned int channel, unsigned int frequency,
         unsigned int resolution, unsigned int initial_value)
    : pin(pin), channel(channel), frequency(frequency), resolution(resolution) {
  ledcSetup(this->getChannel(), this->getFrequency(), this->getResolution());
  ledcAttachPin(this->getPin(), this->getChannel());

  this->Set(initial_value);
}

Led::~Led() {}

void Led::High() { ledcWrite(this->getChannel(), this->highValue()); }

void Led::Low() { ledcWrite(this->getChannel(), this->lowValue()); }

void Led::Set(float value) {
  if (value < 0) {
    value = 0;
  } else if (value > 1) {
    value = 1;
  }

  unsigned int clamped_value = value * this->highValue();
  ledcWrite(this->getChannel(), clamped_value);
}

} // namespace leds