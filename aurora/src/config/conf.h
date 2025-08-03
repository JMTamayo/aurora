#pragma once

namespace config {

// Serial Configuration parameters:
extern const unsigned long
    DEFAULT_BAUD_RATE; // Default baud rate for serial communication

// LED Configuration parameters:
extern const unsigned int LED_PIN; // LED pin

extern const unsigned int LED_CHANNEL; // LED channel

extern const unsigned int LED_FREQUENCY; // LED frequency

extern const unsigned int LED_RESOLUTION; // LED resolution

extern const unsigned int LED_INITIAL_VALUE; // Initial LED value

// LDR Configuration parameters:
extern const unsigned int LDR_PIN; // LDR pin

extern const unsigned int LDR_FIXED_RESISTANCE; // LDR fixed resistance

extern const float LDR_SUPPLY_VOLTAGE; // LDR supply voltage

extern const unsigned int LDR_RESOLUTION; // LDR resolution

extern const float LDR_GAMMA; // Gamma value for the LDR: R = R_0 * E^gamma

extern const float LDR_RESISTANCE_AT_1_LUX; // LDR resistance at 1 lux: R_0

// LCD Configuration parameters:
extern const unsigned int LCD_ADDRESS; // LCD address

extern const unsigned int LCD_COLS; // LCD columns

extern const unsigned int LCD_ROWS; // LCD rows

// Controller Configuration parameters:

extern const float SET_POINT; // Set point

} // namespace config