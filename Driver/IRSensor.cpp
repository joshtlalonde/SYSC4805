#include "IRSensor.h"

// Constructor definition
IRSensor::IRSensor(int outPin, void(*detectingISR)()) {
  detected = false;

  // Set PIN Mode
  pinMode(outPin, INPUT);

  // Attach Interrupt
  attachInterrupt(digitalPinToInterrupt(outPin), detectingISR, CHANGE);
}

int IRSensor::getDetected() {
  return detected;
}

void IRSensor::setDetected(int detected) {
  this->detected = detected;
}