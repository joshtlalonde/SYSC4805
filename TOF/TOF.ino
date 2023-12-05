#include "TOF.h"

#define OUT 6
#define THRESHOLD 100
#define WIDTH 16
#define HEIGHT 16

// Initialize TOF sensor
TOF tof(OUT, THRESHOLD, WIDTH, HEIGHT);

void setup(){
  while (!Serial) {}
  Serial.begin(115200);
  tof.start();
}

void loop(){
  // Serial.print("Distance (mm): ");
  // Serial.println(tof.getDistance());
  Serial.print("Detection Status: ");
  Serial.println(tof.getDetectionStatus());
  delay(500);
}