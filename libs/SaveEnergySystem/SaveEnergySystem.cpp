#include "Arduino.h"
#include "SaveEnergySystem.h"

SaveEnergySystem::SaveEnergySystem(int maxLightLevel, int *ledsPin, int amountLeds) {
  for (int i = 0; i < amountLeds; i++) {
    pinMode(ledsPin[i], OUTPUT);
    _ledsPin[i] = ledsPin[i];
  }

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

void SaveEnergySystem::lightsAutomaticManager(int value) {
  if (value > _maxLightLevel) {
    turnOffAllLeds();
  } else {
    turnOnAllLeds();
  }
}

