#ifndef LDR_H
#define LDR_H

namespace voltage_dividers {

class Ldr {
private:
  const unsigned int pin;
  const float supply_voltage;
  const unsigned int resolution;

  const unsigned int fixed_resistance;

  const float resistance_at_1_lux;
  const float gamma;

  const unsigned int getPin() const;

  const float getSupplyVoltage() const;

  const unsigned int getResolution() const;

  const unsigned int getFixedResistance() const;

  const float getResistanceAt1Lux() const;

  const float getGamma() const;

  float readAnalogValue() const;

  float calculateResistance(float voltage) const;

public:
  Ldr(unsigned int pin, float supply_voltage, unsigned int resolution,
      unsigned int fixed_resistance, float resistance_at_1_lux, float gamma);

  ~Ldr();

  float ReadVoltage() const;

  float ReadLuminosity() const;
};

} // namespace voltage_dividers

#endif // LDR_H