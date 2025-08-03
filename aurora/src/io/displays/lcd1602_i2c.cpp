#include "lcd1602_i2c.h"
#include <Wire.h>

namespace displays {

LiquidCrystal_I2C *Lcd1602I2c::getLcd() const { return this->lcd; }

Lcd1602I2c::Lcd1602I2c(unsigned int address, unsigned int cols,
                       unsigned int rows) {
  this->lcd = new LiquidCrystal_I2C(address, cols, rows);

  this->getLcd()->init();
  this->getLcd()->clear();
  this->getLcd()->backlight();
}

Lcd1602I2c::~Lcd1602I2c() { delete lcd; }

void Lcd1602I2c::DisplayStatus(float set_point, float process_value) {
  this->getLcd()->setCursor(0, 0);
  this->getLcd()->print("SP: ");
  this->getLcd()->print(set_point);

  this->getLcd()->setCursor(0, 1);
  this->getLcd()->print("PV: ");
  this->getLcd()->print(process_value);
}

} // namespace displays