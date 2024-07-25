/* Demo Code for onboard WS2812 RGB LED Testing 
  Interfacing :
  | ESP32 | RGB LED | Function |
  |---|---|---|
  |IO17 | DIN | Data In of WS2812 RGBLed Array |
  
 */
#include <FastLED.h>

// define RGB LED pins and control
#define DATA_PIN    17
#define NUM_LEDS    4
#define BRIGHTNESS  64
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

// Define the array of leds
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

void setup() {
  Serial.begin(115200);
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS); 
}

void loop() {
  Serial.println("Turn ON LED");
  leds[0] = CRGB::Red;
  leds[1] = CRGB::Green;
  leds[2] = CRGB::Blue;
  leds[3] = CRGB::Yellow;
  FastLED.show();
  delay(500);
  
  Serial.println("Turn OFF LED");
  leds[0] = CRGB::Black;
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  FastLED.show();
  delay(500);
}
