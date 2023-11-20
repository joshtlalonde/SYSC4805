#include "TOF.h"

VL53L1X sensor;

// Constructor definition
TOF::TOF(int outPin, uint16_t threshold, uint8_t width, uint8_t height) {
    this->detected = false;
    this->threshold = threshold;
    this->detectionDistance = 4000;
    // set to 4x4 for FOV to be 15 degrees
    // set to 16x16 for FOV to be 27 degrees
    this->fov[0] = width;
    this->fov[1] = height;
}

// Start sensor
void TOF::start() {

    Wire.begin();
    Wire.setClock(400000); // use 400 kHz I2C

    sensor.setTimeout(500);
    if (!sensor.init()) {
        Serial.println("Failed to detect and initialize sensor!");
        while (1);
    }

    // Set FOV
    sensor.setROISize(fov[0], fov[1]);

    // Use long distance mode and allow up to 50000 us (50 ms) for a measurement.
    // You can change these settings to adjust the performance of the sensor, but
    // the minimum timing budget is 20 ms for short distance mode and 33 ms for
    // medium and long distance modes. See the VL53L1X datasheet for more
    // information on range and timing limits.
    sensor.setDistanceMode(VL53L1X::Long);
    sensor.setMeasurementTimingBudget(33000);

    // Start continuous readings at a rate of one measurement every 50 ms (the
    // inter-measurement period). This period should be at least as long as the
    // timing budget.
    sensor.startContinuous(50);
}

// Stop sensor
void TOF::stop() {
    sensor.stopContinuous();
}

// Get distance measurement
uint16_t TOF::getDistance() {
    // Read sensor values
    sensor.read();
    this->detectionDistance = sensor.ranging_data.range_mm;
    if (this->detectionDistance <= this->threshold) {
      this->detected = true;
    } else {
      this->detected = false;
    }
    
    return this->detectionDistance;
}

// Get detection status
bool TOF::getDetectionStatus() {
  // Read sensor values
  sensor.read();
  this->detectionDistance = sensor.ranging_data.range_mm;
  if (this->detectionDistance <= this->threshold) {
    this->detected = true;
  } else {
    this->detected = false;
  }

  return this->detected;
}
