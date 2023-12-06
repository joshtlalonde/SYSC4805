#include "Motors.h"

// Motors *Motors::motorsInstance = nullptr;

Motors::Motors(int rightSpeedPin, int rightDirPin, int leftSpeedPin, int leftDirPin) : motorRight(PWM_DIR, rightSpeedPin, rightDirPin), motorLeft(PWM_DIR, leftSpeedPin, leftDirPin)
{
    this->forward = false;
    this->right = false;
    this->left = false;
}

void Motors::motorsOn()
{
  if (!this->forward) {
    motorRight.setSpeed(-128);
    motorLeft.setSpeed(128);
  }

  this->forward = true;
  this->right = false;
  this->left = false;
}

void Motors::motorsOff()
{
  if (this->forward) {
    motorRight.setSpeed(0);
    motorLeft.setSpeed(0);
  }

  this->forward = false;
  this->right = false;
  this->left = false;
}

void Motors::turnRight()
{
  if (!this->right) {
    motorRight.setSpeed(255);
    motorLeft.setSpeed(255);
  }

  this->forward = false;
  this->right = true;
  this->left = false;
}

void Motors::turnLeft()
{
  if (!this->left) {
    motorRight.setSpeed(-255);
    motorLeft.setSpeed(-255);
  }

  this->forward = false;
  this->right = false;
  this->left = true;
}
