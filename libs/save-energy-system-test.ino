#include <SaveEnergySystem.h>

#define LDR_PIN A1
#define MAX_LIGHT_LEVEL 200
#define AMOUNT_LEDS 4

int ledsPin[] = { 7, 8, 12, 13 };

SaveEnergySystem lights(LDR_PIN, MAX_LIGHT_LEVEL, ledsPin, AMOUNT_LEDS);


void setup() {
}

void loop() {
  lights.lightsAutomaticManager();
}
