#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUM_LEDS 57
#define VIBE_PIN 9

Adafruit_NeoPixel strip(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

// Correct NeoPixel indexes for your hand path (DO NOT USE RGB#, INDEX OF WIRING FROM ARDUINO)
int handPath[] = {
  0,1,2,//Countdown to start (Zero Index)
  3,4,5,6,7, //Inhale
  8,9,10,11,12,//Exhale
  13,14,15,16,17,//I
  18,19,20,21,22,//E
  23,24,25,26,27,//I
  28,29,30,31,32,//E
  33,34,35,36,37,//I
  38,39,40,41,42,//E
  43,44,45,46,47,//I
  48,49,50,51,52,//E
  53,54,55,56//FINISH
};

int delayTime = 300;//time each LED takes

void setup() {
  strip.begin();
  strip.show();
  pinMode(VIBE_PIN, OUTPUT);
}

void loop() {

  // Countdown (first 3 LEDs)
  for (int i = 0; i < 3; i++) {
    strip.setPixelColor(handPath[i], strip.Color(255,255,255));
    strip.show();
    delay(400);
  }

  delay(1000);
  strip.clear();

  bool inhale = true;

  // Breathing animation
  for (int i = 3; i < 50; i= i + 5) {
    for (int j = 0; j < 5; j++) {
      strip.clear();

      if (inhale) {
        strip.setPixelColor(handPath[i + j], strip.Color(0,255,0)); // green = inhale
        digitalWrite(VIBE_PIN, HIGH);
      } else {
        strip.setPixelColor(handPath[i + j], strip.Color(0,0,255)); // blue = exhale
        digitalWrite(VIBE_PIN, LOW);
      }
      strip.show();
      delay(delayTime);
    }

    inhale = !inhale;
  }

  // Finish: light up entire hand white
  //pauses for a couple seconds to decide to turn off or run again
  strip.clear();
  setHandColor(255, 255, 255);
  strip.show();
  delay(2000);
  strip.clear();
  setHandColor(0, 0, 0);
  strip.show();
  delay(4000);
}

// Function to set the whole hand to a color
void setHandColor(int r, int g, int b) {
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(handPath[i], strip.Color(r, g, b));
  }
}
