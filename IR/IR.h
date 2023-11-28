#ifndef IR_h
#define IR_h

#include "Arduino.h"

#define MAX_NUM_IR 1

class IR {
    private:
      volatile bool detected;
      int outPin;
      static int whichInstance;

    public:
      IR(int outPin);
      int getDetectionStatus();
      void detecting();

      // Setup Interrupt functions to call a function in the class
      static IR* irInstance[MAX_NUM_IR];
      static void interrupt0() {
        if (IR::irInstance[0] != NULL) {
          IR::irInstance[0]->detecting();
        }
      }
};
#endif