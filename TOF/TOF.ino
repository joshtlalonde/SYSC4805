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
}

void loop(){
  printf("Distance (mm): %d\n", tof.getDistance());
  printf("Detection Status: %d\n", tof.getDetectionStatus());
  delay(500);
}