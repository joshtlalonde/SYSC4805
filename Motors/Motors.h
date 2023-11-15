#ifndef Motors_h
#define Motors_h

#include "CytronMotorDriver.h"

class Motors
{
public:
    Motors(int rightSpeedPin, int rightDirPin, int leftSpeedPin, int leftDirPin);
    void motorsOn();
    void motorsOff();
    void turn(int side);

private:
    CytronMD motorRight;
    CytronMD motorLeft;
};

#endif
