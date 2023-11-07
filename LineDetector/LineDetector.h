#ifndef LINEDETECTOR_h
#define LINEDETECTOR_h

#include "Arduino.h"

class LineDetector {
    private:
      volatile bool detected;
      int sensorLeft;
      int sensorRight;
      int sensorMiddle;

    public:
      LineDetector(int out1Pin, int out2Pin, int out3Pin);
      static LineDetector* lineDetectorInstance;

      static void detecting();
      int getDetected();
};


#endif