#include "LineDetector.h"

#define OUT1RIGHT 54
#define OUT2RIGHT 55
#define OUT3RIGHT 56
#define OUT1LEFT 57
#define OUT2LEFT 58
#define OUT3LEFT 59

// Initialize Line Detectors
LineDetector lineDetectorL(OUT1LEFT, OUT2LEFT, OUT3LEFT);
LineDetector lineDetectorR(OUT1RIGHT, OUT2RIGHT, OUT3RIGHT);

void setup() {
  // Your setup code here
  Serial.begin(115200);
}

void loop() {
  printf("RightLineDetector: %d, LeftLineDetector: %d\n", lineDetectorR.getDetected(), lineDetectorL.getDetected());

  Serial.print(analogRead(OUT1LEFT));
  Serial.print(" ");
  Serial.print(analogRead(OUT2LEFT));
  Serial.print(" ");
  Serial.print(analogRead(OUT3LEFT));
  Serial.println();

  Serial.print(analogRead(OUT1RIGHT));
  Serial.print(" ");
  Serial.print(analogRead(OUT2RIGHT));
  Serial.print(" ");
  Serial.print(analogRead(OUT3RIGHT));
  Serial.println();

  delay(500);
}
