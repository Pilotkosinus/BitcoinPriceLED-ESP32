<p align="center">
  <img src="https://purepng.com/public/uploads/medium/under-construction-xmt.png" />
  <br>
  <strong>Under Construction</strong>
</p>




# ESP32 Crypto Ticker with LED Display

This project enables an ESP32 to fetch cryptocurrency information from the Bitstamp API and display the 24-hour percentage change value on a WS2812B LED strip.

## Functionality
- The ESP32 connects to WiFi and retrieves data from the Bitstamp API.
- It reads the 24-hour percentage change (`percent_change_24`) for BTC/USD.
- Based on the `percent_change_24` value, the LEDs light up in different colors:
  - **Green:** for a change of more than 5%
  - **Red:** for a change of less than -5%
  - **White:** for a change between -5% and 5%

## Hardware Requirements
- An ESP32 microcontroller
- WS2812B LED strip
- Power supply for both the LED strip and ESP32

## Software Requirements
- Arduino IDE
- FastLED library
- ArduinoJson library
- WiFi library

## Installation
1. Install the FastLED and ArduinoJson libraries via the Arduino IDE.
2. Upload the code to your ESP32.
3. Change the `ssid` and `password` variables to your WiFi credentials.
4. If necessary, adjust the number of LEDs (`NUM_LEDS`) and the connected pin (`LED_PIN`).

## Code Structure
```cpp
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <FastLED.h>

// ... (Code shortened for documentation)

void updateLEDColor(float percentChange) {
  // Change LED colors based on the percentage value
}

void setAllLEDs(CRGB color) {
  // Sets the color of all LEDs in the strip
}
```

## Contributors
- [Pilotkosinus] - Project initiator and main developer


