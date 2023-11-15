#include "LineDetector.h"

#define OUT1RIGHT 14
#define OUT2RIGHT 4
#define OUT3RIGHT 5
#define OUT1LEFT 12
#define OUT2LEFT 13
#define OUT3LEFT 10

// Initialize Line Detectors
LineDetector lineDetectorL(OUT1LEFT, OUT2LEFT, OUT3LEFT);
LineDetector lineDetectorR(OUT1RIGHT, OUT2RIGHT, OUT3RIGHT);

void setup() {
  // Your setup code here
  Serial.begin(115200);
}

void loop() {
  printf("RightLineDetector: %d, LeftLineDetector: %d\n", lineDetectorR.getDetected(), lineDetectorL.getDetected());
  delay(500);
}
