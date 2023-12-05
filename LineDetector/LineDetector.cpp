#include "LineDetector.h"

LineDetector* LineDetector::lineDetectorInstance[MAX_NUM_LINE_DETECTORS] = {NULL, NULL};
int LineDetector::whichInstance = 0;

// Constructor definition
LineDetector::LineDetector(int out1Pin, int out2Pin, int out3Pin) {
  detected = false;
  sensorRight = out1Pin;
  sensorLeft = out2Pin;
  sensorMiddle = out3Pin;

  // Set PIN Mode
  pinMode(sensorRight, INPUT);
  pinMode(sensorLeft, INPUT);
  pinMode(sensorMiddle, INPUT);

  // Attach Interrupts for each pin
  if (whichInstance == 0) {
    attachInterrupt(digitalPinToInterrupt(sensorRight), interrupt0, CHANGE);
    attachInterrupt(digitalPinToInterrupt(sensorLeft), interrupt0, CHANGE);
    attachInterrupt(digitalPinToInterrupt(sensorMiddle), interrupt0, CHANGE);
  } 
  else if (whichInstance == 1) {
    attachInterrupt(digitalPinToInterrupt(sensorRight), interrupt1, CHANGE);
    attachInterrupt(digitalPinToInterrupt(sensorLeft), interrupt1, CHANGE);
    attachInterrupt(digitalPinToInterrupt(sensorMiddle), interrupt1, CHANGE);
  } 
  else {
    Serial.println("Exceeded MAX_NUM_LINE_DETECTORS (2)");
  }

  // Needed to handle interupts in a class
  lineDetectorInstance[whichInstance] = this;
  whichInstance++;
}


void LineDetector::detecting() {
  // // Check if any pins are logical LOW
  // if (analogRead(sensorRight) > 1000 || analogRead(sensorLeft) > 1000 || analogRead(sensorMiddle) > 1000) {
  //   detected = true;
  // } 
  // // Reset on logical HIGH
  // else {
  //   detected = false;
  // }
}

int LineDetector::getDetected() {
  return detected;
}
