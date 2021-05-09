#ifndef WEATHER_H
#define WEATHER_H

#include "Arduino.h"
#include <idDHT11.h>

class WeatherSystem {
  private:
  int _dhtPin, _dhtInterrupt;
  float _temperatureC, _humidity;

  void dht11_wrapper();    
  void loopDHT();     
  idDHT11 _dhtSensor;

  public:
    WeatherSystem(int dhtPin, int dhtInterrupt);
    float getTemperature();
    float getHumidity();
};

#endif 