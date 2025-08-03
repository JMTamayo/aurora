#ifndef LED_H
#define LED_H

namespace leds {

class Led {
private:
  const unsigned int pin;
  const unsigned int channel;
  const unsigned int frequency;
  const unsigned int resolution;

  const unsigned int getPin() const;

  const unsigned int getChannel() const;

  const unsigned int getFrequency() const;

  const unsigned int getResolution() const;

  const unsigned int highValue() const;

  const unsigned int lowValue() const;

public:
  Led(unsigned int pin, unsigned int channel, unsigned int frequency,
      unsigned int resolution, unsigned int initial_value);

  ~Led();

  void On();

  void Off();

  void Set(unsigned int value);
};

} // namespace leds

#endif // LED_H