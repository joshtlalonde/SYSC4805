#ifndef LINEDETECTOR_h
#define LINEDETECTOR_h

#include "Arduino.h"

#define MAX_NUM_LINE_DETECTORS 2

class LineDetector {
    private:
      volatile bool detected;
      int sensorLeft;
      int sensorRight;
      int sensorMiddle;
      static int whichInstance;

    public:
      LineDetector(int out1Pin, int out2Pin, int out3Pin);
      void detecting();
      int getDetected();

      // Setup Interrupt functions to call a function in the class
      static LineDetector* lineDetectorInstance[MAX_NUM_LINE_DETECTORS];
      static void interrupt0() {
        if (LineDetector::lineDetectorInstance[0] != NULL) {
          LineDetector::lineDetectorInstance[0]->detecting();
        }
      }
      static void interrupt1() {
        if (LineDetector::lineDetectorInstance[1] != NULL) {
          LineDetector::lineDetectorInstance[1]->detecting();
        }
      }
};

#endif