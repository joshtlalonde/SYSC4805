#ifndef IRSENSOR_h
#define IRSENSOR_h

#include "Arduino.h"

class IRSensor {
    private:
      volatile bool detected;
      int outPin;

    public:
      IRSensor(int outPin, void(*detectingISR)());
      int getDetected();
      void setDetected(int detected);
};
#endif