#include <Arduino.h>

#include "ldr.h"

namespace voltage_dividers {

const unsigned int Ldr::getPin() const { return this->pin; }

const unsigned int Ldr::getFixedResistance() const {
  return this->fixed_resistance;
}

const float Ldr::getSupplyVoltage() const { return this->supply_voltage; }

const unsigned int Ldr::getResolution() const { return this->resolution; }

const float Ldr::getResistanceAt1Lux() const {
  return this->resistance_at_1_lux;
}

const float Ldr::getGamma() const { return this->gamma; }

float Ldr::readAnalogValue() const { return analogRead(this->getPin()); }

Ldr::Ldr(unsigned int pin, float supply_voltage, unsigned int resolution,
         unsigned int fixed_resistance, float resistance_at_1_lux, float gamma)
    : pin(pin), supply_voltage(supply_voltage), resolution(resolution),
      fixed_resistance(fixed_resistance),
      resistance_at_1_lux(resistance_at_1_lux), gamma(gamma) {
  pinMode(this->getPin(), INPUT);
}

Ldr::~Ldr() {}

float Ldr::ReadVoltage() const {
  return this->readAnalogValue() * this->getSupplyVoltage() /
         this->getResolution();
}

float Ldr::ReadResistance() const {
  float voltage = this->ReadVoltage();
  return this->getFixedResistance() * (this->getSupplyVoltage() - voltage) /
         voltage;
}

float Ldr::ReadLuminosity() const {
  return pow(this->ReadResistance() / this->getResistanceAt1Lux(),
             1 / this->getGamma());
}

} // namespace voltage_dividers