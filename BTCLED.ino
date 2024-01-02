#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <FastLED.h>

const char* ssid = "YOURWLANDSSID";
const char* password = "YOURWLANPW";

// LED-Konfiguration
#define LED_PIN     5  // Der Pin, an dem die LEDs angeschlossen sind
#define NUM_LEDS    60 // Anzahl der LEDs im Strip
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Verbinde mit WiFi...");
  }
  Serial.println("Verbunden mit WiFi");

  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50); // Einstellen der Helligkeit
}

void loop() {
  if ((WiFi.status() == WL_CONNECTED)) {
    HTTPClient http;

    http.begin("https://www.bitstamp.net/api/v2/ticker/btcusd");
    int httpCode = http.GET();

    if (httpCode > 0) {
      String payload = http.getString();
      DynamicJsonDocument doc(1024);
      deserializeJson(doc, payload);

      float percentChange24 = doc["percent_change_24"];
      Serial.print("24-Stunden-Prozentänderung: ");
      Serial.println(percentChange24, 2);

      updateLEDColor(percentChange24);
    }
    else {
      Serial.print("Fehler beim Abrufen der Daten, HTTP-Code: ");
      Serial.println(httpCode);
    }

    http.end();
  }
  delay(10000);
}

void updateLEDColor(float percentChange) {
  if (percentChange > 5) {
    setAllLEDs(CRGB::Green);  // Grün für mehr als 5%
  } else if (percentChange < -5) {
    setAllLEDs(CRGB::Red);    // Rot für weniger als -5%
  } else {
    setAllLEDs(CRGB::White);  // Weiß für alles zwischen -5% und 5%
  }
}

void setAllLEDs(CRGB color) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
  }
  FastLED.show();
}