#ifndef TOF_h
#define TOF_h

#include <VL53L1X.h>

class TOF {
    private:
      volatile bool detected;
      uint16_t detectionDistance;
      uint16_t threshold;
      // width, height of SPAD block
      uint8_t fov[2];

    public:
      TOF(int outPin, uint16_t threshold, uint8_t width, uint8_t height);
      uint16_t getDistance();
      bool getDetectionStatus();
      void start();
      void stop();
};


#endif