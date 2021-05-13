// implementation of class security system 

#include "Arduino.h"
#include "SecuritySystem.h"

#define AMOUNT_NOTES 7 
#define DELAY_BUZZER 1000 
const int notes[] = { 524, 588, 660, 699, 785, 881, 989 }; // notes for buzzer

SecuritySystem::SecuritySystem(int buzzerPin, int maxValueLdr) {
  pinMode(buzzerPin, OUTPUT);

  this->ldrPin = ldrPin;
  this->buzzerPin = buzzerPin;
  this->maxValueLdr = maxValueLdr;
}

bool SecuritySystem::wasLaserInterrupted(int value) {
  return (value < this->maxValueLdr);
}

void SecuritySystem::triggerAlarm() {
  for (int i = 0; i < AMOUNT_NOTES; i++) {
    tone(this->buzzerPin, notes[i], DELAY_BUZZER);
    delay(2000);
  }
}
