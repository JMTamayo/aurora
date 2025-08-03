#include "conf.h"

namespace config {

const unsigned long DEFAULT_BAUD_RATE = 115200;

const unsigned int LED_PIN = 23;

const unsigned int LED_CHANNEL = 0;

const unsigned int LED_FREQUENCY = 5000;

const unsigned int LED_RESOLUTION = 8;

const unsigned int LED_INITIAL_VALUE = 0;

const unsigned int LDR_PIN = 34;

const unsigned int LDR_FIXED_RESISTANCE = 5000;

const float LDR_SUPPLY_VOLTAGE = 3.3;

const unsigned int LDR_RESOLUTION = 4095;

const float LDR_GAMMA = -0.6410881977123006;

const float LDR_RESISTANCE_AT_1_LUX = 200501.74243688726;

const unsigned int LCD_ADDRESS = 0x27;

const unsigned int LCD_COLS = 16;

const unsigned int LCD_ROWS = 2;

const float SET_POINT = 350.0;

} // namespace config
