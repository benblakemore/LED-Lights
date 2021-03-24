#include <FastLED.h>

#define NUM_LEDS 39
#define DATA_PIN 2
#define BRIGHTNESS 255;
#define SATURATION 255;

boolean increment = true;

uint8_t hue = 0;
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
}

void loop() {
//  Serial.println(hue);
  rainbowWave();
}

void solidColour() {
  // Change first value to change hue value
  fill_solid(leds, NUM_LEDS, CHSV(90, 255, 255));
  FastLED.show();
}

void rainbowWave() {
  int colourChangeRate = 50; // Number of ms between each shade change. Higher = more gradual change
  
  fill_solid(leds, NUM_LEDS, CHSV(hue, 255, 255));
  if (increment && hue != 255) {
    hue++;
  } else if (hue != 0) {
    hue--;
  }
  if (hue == 255) {
    increment = false;
  }
  if (hue == 0) {
    increment = true;
  }
  FastLED.show();
  delay(colourChangeRate);
}
