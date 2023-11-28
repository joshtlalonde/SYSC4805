#include "IR.h"

#define OUT 9

IR ir(OUT);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Detection Status: ");
  Serial.println(ir.getDetectionStatus());
  Serial.println(digitalRead(OUT));
}
