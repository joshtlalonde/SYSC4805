#include "IR.h"

IR* IR::irInstance[MAX_NUM_IR] = {NULL};
int IR::whichInstance = 0;

// Constructor definition
IR::IR(int outPin) {
  detected = false;

  // Set PIN Mode
  pinMode(outPin, INPUT);

  // Attach Interrupt
  attachInterrupt(digitalPinToInterrupt(outPin), interrupt0, CHANGE);

  // Needed to handle interupts in a class
  irInstance[whichInstance] = this;
  whichInstance++;
}

void IR::detecting() {
  if (!digitalRead(outPin)) {
    detected = true;
  } 
  // Check if  HIGH
  else {
    detected = false;
  }
}

int IR::getDetectionStatus() {
  return detected;
}
