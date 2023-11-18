#include "Motors.h"

#define RIGHT_SPEED_PIN 3
#define RIGHT_DIR_PIN 2
#define LEFT_SPEED_PIN 5
#define LEFT_DIR_PIN 4

Motors motors(RIGHT_SPEED_PIN, RIGHT_DIR_PIN, LEFT_SPEED_PIN, LEFT_DIR_PIN);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
  motors.motorsOn();
  delay(2000);
  motors.motorsOff();
  delay(2000);
  motors.turn(0); // Turn Right
  delay(2000);
  motors.turn(1); // Turn Left
  delay(2000);
}
