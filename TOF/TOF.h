#ifndef TOF_h
#define TOF_h

#include <VL53L1X.h>

class TOF {
    private:
      volatile bool detected;
      uint16_t detectionDistance;
      // width, height of SPAD block
      uint8_t fov[2];

    public:
      TOF(int outPin, uint8_t width, uint8_t height);
      static TOF* TOFInstance;
      uint16_t getDistance();
      void start();
      void stop();
};


#endif