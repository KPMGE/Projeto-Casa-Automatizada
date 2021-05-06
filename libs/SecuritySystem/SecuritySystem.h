// class definition for security system 

#ifndef SECURITY_H
#define SECURITY_H

#include "Arduino.h"

class SecuritySystem {
  private: 
    int _ldrPin, _buzzerPin, _maxValueLdr;

  public:
    SecuritySystem(int ldrPin, int buzzerPin, int maxValueLdr);
    bool wasLaserInterrupted();
    void triggerAlarm();
};

#endif