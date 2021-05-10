#ifndef WEATHER_H
#define WEATHER_H

#include "Arduino.h"
#include <idDHT11.h>

class WeatherSystem {
  private:
  int _dhtPin, _dhtInterrupt, _ledPin;
  float _temperatureC, _humidity;

  void dht11_wrapper();    
  void loopDHT();     
  idDHT11 _dhtSensor;

  public:
    WeatherSystem(int dhtPin, int dhtInterrupt, int ledPin);
    void turnOnLed();
    void turnOffLed();
    float getTemperature();
    float getHumidity();
};

#endif 
