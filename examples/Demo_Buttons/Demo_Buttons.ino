// Demo code to Test onboard Buttons with RGB LEDs
/*
  Interfacing: 
  | ESP32 | Hardware | Function |
  |---|---|---|
  |IO0 | BOOT |Boot button |
  |IO4 | BT1 | Programmable Button |
  |IO5 | BT2 | Programmable Button |
  |IO17 | DIN | Data In of WS2812 RGBLed Array |

*/

#include <FastLED.h>

#define DATA_PIN    17
#define NUM_LEDS    4
#define BRIGHTNESS  64
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

// Define the array of leds
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

const int BootBTN = 0; // button connect to GPIO 0
const int BT1 = 4; // button connect to GPIO 4
const int BT2 = 5;// button connect to GPIO 15

void setup() {
  Serial.begin(115200); // Initialize Serial communication, Enable CDC mode to view serial OUTPUT
  pinMode(BootBTN, INPUT_PULLUP);
  pinMode(BT1, INPUT_PULLUP);
  pinMode(BT2, INPUT_PULLUP);
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  
  Serial.println("Press Any Button");
}

void loop() 
{
  // read button value
  int value1 = digitalRead(BootBTN);
  int value2 = digitalRead(BT1);
  int value3 = digitalRead(BT2);
  
  if (value1 == LOW || value2 == LOW || value3 == LOW) //if any of button is pressed then led will glow
  {
    // Turn the LED on
    leds[0] = CRGB::Red;
    leds[1] = CRGB::Green;
    leds[2] = CRGB::Blue;
    leds[3] = CRGB::Yellow;
    FastLED.show();
    Serial.printf("BootBTN = %d BT1 = %d BT2 = %d\n", value1, value2, value3);
    delay(500);
  }
  else {
    // Turn OFF LED
    leds[0] = CRGB::Black;
    leds[1] = CRGB::Black;
    leds[2] = CRGB::Black;
    leds[3] = CRGB::Black;
    FastLED.show();
  }
  delay(10);
}
