#ifndef LCD1602_I2C_H
#define LCD1602_I2C_H

#include <LiquidCrystal_I2C.h>

namespace displays {

class Lcd1602I2c {
private:
  LiquidCrystal_I2C *lcd;

  LiquidCrystal_I2C *getLcd() const;

public:
  Lcd1602I2c(unsigned int address, unsigned int cols, unsigned int rows);

  ~Lcd1602I2c();

  void DisplayProcessStatus(float set_point, float process_value);
};

} // namespace displays

#endif