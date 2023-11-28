#include "Motors.h"

// Motors *Motors::motorsInstance = nullptr;

#define SPEED 100

Motors::Motors(int rightSpeedPin, int rightDirPin, int leftSpeedPin, int leftDirPin) : motorRight(PWM_DIR, rightSpeedPin, rightDirPin), motorLeft(PWM_DIR, leftSpeedPin, leftDirPin)
{
    // motorsInstance = this;
}

void Motors::motorsOn()
{
    motorRight.setSpeed(-SPEED);
    motorLeft.setSpeed(SPEED);
}

void Motors::motorsOff()
{
    motorRight.setSpeed(0);
    motorLeft.setSpeed(0);
}

void Motors::turnRight()
{
    motorRight.setSpeed(SPEED+50);
    motorLeft.setSpeed(SPEED+50);
}

void Motors::turnLeft()
{
    motorRight.setSpeed(-SPEED-50);
    motorLeft.setSpeed(-SPEED-50);
}
