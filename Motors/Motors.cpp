#include "Motors.h"

Motors *Motors::motorsInstance = nullptr;

Motors::Motors(int rightSpeedPin, int rightDirPin, int leftSpeedPin, int leftDirPin) : motorRight(PWM_DIR, rightSpeedPin, rightDirPin), motorLeft(PWM_DIR, leftSpeedPin, leftDirPin)
{
    motorsInstance = this;
}

int Motors::motorsOn()
{
    motorRight.setSpeed(255);
    motorLeft.setSpeed(255);
}

void Motors::motorsOff()
{
    motorRight.setSpeed(0);
    motorLeft.setSpeed(0);
}

void Motors::turn(int side)
{
    if (side == 0)
    { // 0 for right turn, 1 for left turn
        motorRight.setSpeed(255);
        motorLeft.setSpeed(0);
    }
    else
    {
        motorRight.setSpeed(0);
        motorLeft.setSpeed(255);
    }
}
