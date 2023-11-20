#ifndef Motors_h
#define Motors_h

#include "CytronMotorDriver.h"

class Motors
{
public:
    Motors(int rightSpeedPin, int rightDirPin, int leftSpeedPin, int leftDirPin);
    void motorsOn();
    void motorsOff();
    void turnRight();
    void turnLeft();

private:
    CytronMD motorRight;
    CytronMD motorLeft;
};

#endif
