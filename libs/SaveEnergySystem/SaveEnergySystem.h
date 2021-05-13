#ifndef SAVE_ENERGY_H
#define SAVE_ENERGY_H

class SaveEnergySystem {
  private:
    int _maxLightLevel, _amountLeds, _ledsPin[4];
    void turnOffAllLeds();
    void turnOnAllLeds();

  public:
    SaveEnergySystem(int maxLightLevel, int *ledsPin, int amountLeds);
    void lightsAutomaticManager(int value);
};

#endif
