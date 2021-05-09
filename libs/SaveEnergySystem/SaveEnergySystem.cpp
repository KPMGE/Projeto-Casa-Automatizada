#include "Arduino.h"
#include "SaveEnergySystem.h"

SaveEnergySystem::SaveEnergySystem(int ldrPin, int maxLightLevel, int *ledsPin, int amountLeds) {
  pinMode(ldrPin, OUTPUT);

  for (int i = 0; i < amountLeds; i++) {
    pinMode(ledsPin[i], OUTPUT);
    _ledsPin[i] = ledsPin[i];
  }

  _ldrPin = ldrPin;
  _maxLightLevel = maxLightLevel;
  _amountLeds = amountLeds;
}

void SaveEnergySystem::turnOnAllLeds() {
  for (int i = 0; i < _amountLeds; i++) {
    digitalWrite(_ledsPin[i], HIGH);
  }
}

void SaveEnergySystem::turnOffAllLeds() {
  for (int i = 0; i < _amountLeds; i++) {
    digitalWrite(_ledsPin[i], LOW);
  }
}

void SaveEnergySystem::lightsAutomaticManager() {
  int value = analogRead(_ldrPin);

  if (value > _maxLightLevel) {
    turnOffAllLeds();
  } else {
    turnOnAllLeds();
  }
}

