#include "LineDetector.h"

LineDetector* LineDetector::lineDetectorInstance = nullptr;

// Constructor definition
LineDetector::LineDetector(int out1Pin, int out2Pin, int out3Pin) {
  detected = false;
  sensorRight = out1Pin;
  sensorLeft = out2Pin;
  sensorMiddle = out3Pin;

  lineDetectorInstance = this; // Set the global instance pointer

  Serial.println("Setting Input Pins: ");
  Serial.printf("sensorRight: %d, sensorRight: %d, sensorRight: %d\n", sensorRight, sensorLeft, sensorMiddle);

  // Set PIN Mode
  pinMode(out1Pin, INPUT);
  pinMode(out2Pin, INPUT);
  pinMode(out3Pin, INPUT);

  // Attach Interrupts for each pin
  attachInterrupt(digitalPinToInterrupt(out1Pin), LineDetector::detecting, CHANGE);
  attachInterrupt(digitalPinToInterrupt(out2Pin), LineDetector::detecting, CHANGE);
  attachInterrupt(digitalPinToInterrupt(out3Pin), LineDetector::detecting, CHANGE);
}


void ICACHE_RAM_ATTR LineDetector::detecting() {
  if (lineDetectorInstance != nullptr) {
    // Implementation goes here
    // You can access non-static members via the instance pointer, like this:
    if (!digitalRead(lineDetectorInstance->sensorRight) || !digitalRead(lineDetectorInstance->sensorLeft) || !digitalRead(lineDetectorInstance->sensorMiddle)) {
      lineDetectorInstance->detected = true;
    } else {
      lineDetectorInstance->detected = false;
    }
  }
}

int LineDetector::getDetected() {
  return detected;
}
