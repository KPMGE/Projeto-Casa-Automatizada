// class definition for security system 

#ifndef SECURITY_H
#define SECURITY_H

#include "Arduino.h"

class SecuritySystem {
  private: 
    int ldrPin, buzzerPin, maxValueLdr;

  public:
    SecuritySystem(int buzzerPin, int maxValueLdr);
    bool wasLaserInterrupted(int value);
    void triggerAlarm();
};

#endif
