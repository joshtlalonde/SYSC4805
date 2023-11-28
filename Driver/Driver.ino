#include "LineDetector.h"
#include "Motors.h"
#include "TOF.h"

// Initialize Line Detectors
#define OUT1RIGHT 54
#define OUT2RIGHT 55
#define OUT3RIGHT 56
#define OUT1LEFT 57
#define OUT2LEFT 58
#define OUT3LEFT 59
LineDetector lineDetectorL(OUT1LEFT, OUT2LEFT, OUT3LEFT);
LineDetector lineDetectorR(OUT1RIGHT, OUT2RIGHT, OUT3RIGHT);

// Initialize TOF sensor
#define OUT 6
#define THRESHOLD 100
#define WIDTH 16
#define HEIGHT 16
TOF tof(OUT, THRESHOLD, WIDTH, HEIGHT);

// Initialize Motors
#define RIGHT_SPEED_PIN 3
#define RIGHT_DIR_PIN 2
#define LEFT_SPEED_PIN 5
#define LEFT_DIR_PIN 4
Motors motors(RIGHT_SPEED_PIN, RIGHT_DIR_PIN, LEFT_SPEED_PIN, LEFT_DIR_PIN);

const int outPin = 9;
volatile int detected = LOW;
const int DELAY = 10;

// Initialize States
enum State {
  DETECTING,
  FORWARD,
  TURN_RIGHT,
  TURN_LEFT,
  DETECTED
};
State currentState = DETECTING;
State nextState = currentState;

void setup() {
  // Your setup code here
  Serial.begin(115200);
  pinMode(outPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(outPin), detecting, CHANGE);

  // Start TOF sensor
  // tof.start();
}

int stopped = 0, forward = 0, turning = 0;

void loop() {
  currentState = nextState;

  if (currentState == DETECTING) {
    Serial.println("STATE: DETECTING");

    // Poll the TOF and Line Sensors
    // If line or object detected move to DETECTED
    if (detected) { //|| lineDetectorL.getDetected() || lineDetectorR.getDetected()) { //|| tof.getDetectionStatus()) {
      nextState = DETECTED;
      forward = 0;
    }
    // Else move to FORWARD
    else {
      nextState = FORWARD;
    }
    
  }

  if (currentState == FORWARD) {
    Serial.println("STATE: FORWARD");

    Serial.println("Driving Forward");
    if (!forward) {
      motors.motorsOn();
    }
    forward = 1;

    // Move back to DETECTING
    nextState = DETECTING;
    delay(DELAY);
  }

  if (currentState == DETECTED) {
    Serial.println("STATE: DETECTED");

    // Stop Driving
    Serial.println("Stop Driving");
    if (!stopped) {
      motors.motorsOff();
    }
    stopped = 1;
    
    // Always turns right
    nextState = TURN_RIGHT;
    delay(DELAY);
  }

  if (currentState == TURN_RIGHT) {
    Serial.println("STATE: TURN_RIGHT");

    // Check RIGHT Ultrasonic Sensor
    // If the sensor detects something; move to TURN_LEFT

    // Else Turn right
    Serial.println("Turn Right");
    if (!turning) {
      motors.turnRight();
    }
    turning = 1;

    // When TOF does not detect an object move back to DETECTING
    if (!detected) {
      nextState = DETECTING;
      turning = 0;
      stopped = 0;
    }
    delay(DELAY);
  }

 // delay(100); // FOR DEBUGGING
}

void detecting() {
  if (!digitalRead(outPin)) {
    detected = true;
  } 
  // Check if  HIGH
  else {
    detected = false;
  }
}
