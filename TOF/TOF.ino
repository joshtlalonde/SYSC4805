#include "TOF.h"

#define OUT 6
#define WIDTH 16
#define HEIGHT 16

// Initialize TOF sensor
TOF tof(OUT, WIDTH, HEIGHT);

void setup(){
  while (!Serial) {}
  Serial.begin(115200);
}

void loop(){
  printf("Distance (mm): %d\n", tof.getDistance());
  delay(500);
}