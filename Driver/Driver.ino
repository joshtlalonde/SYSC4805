#include "LineDetector.h"
#include "Motors.h"
#include "TOF.h"
#include "IRSensor.h"

// Defines the time for the watchdog in ms
int watchdogTime = 1000;

// Must be present for watchdog timer to work
void watchdogSetup(void) 
{
// Optional setup
}

// Initialize Line Detectors
#define OUT1RIGHT 54
#define OUT2RIGHT 55
#define OUT3RIGHT 56
#define OUT1LEFT 57
#define OUT2LEFT 58
#define OUT3LEFT 59
// LineDetector lineDetectorL(OUT1LEFT, OUT2LEFT, OUT3LEFT);
// LineDetector lineDetectorR(OUT1RIGHT, OUT2RIGHT, OUT3RIGHT);

// Initialize TOF sensor
#define OUT 6
#define THRESHOLD 100
#define WIDTH 16
#define HEIGHT 16
// TOF tof(OUT, THRESHOLD, WIDTH, HEIGHT);

// Initialize Motors
#define RIGHT_SPEED_PIN 3
#define RIGHT_DIR_PIN 2
#define LEFT_SPEED_PIN 5
#define LEFT_DIR_PIN 4
Motors motors(RIGHT_SPEED_PIN, RIGHT_DIR_PIN, LEFT_SPEED_PIN, LEFT_DIR_PIN);

// INitialize IR Sensors
#define IR_LEFT_SENSOR_OUTPIN 10
#define IR_RIGHT_SENSOR_OUTPIN 9
void ir_detecting_L();
void ir_detecting_R();
IRSensor irL(IR_LEFT_SENSOR_OUTPIN, &ir_detecting_L);
IRSensor irR(IR_RIGHT_SENSOR_OUTPIN, &ir_detecting_R);

// Initialize States
enum State {
  FORWARD,
  TURN_RIGHT,
  TURN_LEFT,
  DETECTED
};
State currentState = FORWARD;
State nextState = currentState;

void setup() {
  // Your setup code here
  Serial.begin(115200);
}

void loop() {
  // Reset watchdog
  watchdogReset();

  currentState = nextState;

  if (currentState == FORWARD) {
    Serial.println("STATE: FORWARD");

    // Poll the TOF and Line Sensors
    // If line or object detected move to DETECTED
    if (analogRead(OUT1RIGHT) > 900 || analogRead(OUT2RIGHT) > 900 || analogRead(OUT3RIGHT) > 900 || 
        analogRead(OUT2LEFT) > 900 || analogRead(OUT3LEFT) > 900 ||
        irL.getDetected() || irR.getDetected())
    {
      nextState = DETECTED;
    }
    // Else continue FORWARD
    else {
      Serial.println("Driving Forward");
      motors.motorsOn();

      nextState = FORWARD;
    }
  }

  if (currentState == DETECTED) {
    Serial.println("STATE: DETECTED");

    // Stop Driving
    Serial.println("Stop Driving");
    motors.motorsOff();

    // Always turns right
    nextState = TURN_RIGHT;
  }

  if (currentState == TURN_RIGHT) {
    Serial.println("STATE: TURN_RIGHT");

    // Check RIGHT Ultrasonic Sensor
    // If the sensor detects something; move to TURN_LEFT

    Serial.println("Turn Right");
    motors.turnRight();

    // When TOF does not detect an object move back to FORWARD
    if ((analogRead(OUT1RIGHT) < 900 && analogRead(OUT2RIGHT) < 900 && analogRead(OUT3RIGHT) < 900 && 
        analogRead(OUT2LEFT) < 900 && analogRead(OUT3LEFT) < 900) &&
        !irL.getDetected() && !irR.getDetected())  
    {
      // Move to the FORWARD state
      nextState = FORWARD;
    }
    else {
      // Else Turn right
      nextState = TURN_RIGHT;
    }
    nextState = FORWARD;
  }

  delay(100); // FOR DEBUGGING
}

volatile unsigned long last_interrupt_time_L = 0;
volatile unsigned long last_interrupt_time_R = 0;

void ir_detecting_L() {
  unsigned long interrupt_time = millis(); 
  if (interrupt_time - last_interrupt_time_L > 100) {  
    if (!digitalRead(IR_LEFT_SENSOR_OUTPIN)) {
      irL.setDetected(true);
    } 
    // Check if  HIGH
    else if (digitalRead(IR_LEFT_SENSOR_OUTPIN)) {
      irL.setDetected(false);
    }
    last_interrupt_time_L = interrupt_time;  // Save the interrupt time
  }
}

void ir_detecting_R() {
  unsigned long interrupt_time = millis(); 
  if (interrupt_time - last_interrupt_time_R > 100) {  
    if (!digitalRead(IR_RIGHT_SENSOR_OUTPIN)) {
      irR.setDetected(true);
    } 
    // Check if  HIGH
    else if (digitalRead(IR_RIGHT_SENSOR_OUTPIN)) {
      irR.setDetected(false);
    }
    last_interrupt_time_R = interrupt_time;  // Save the interrupt time
  }
}