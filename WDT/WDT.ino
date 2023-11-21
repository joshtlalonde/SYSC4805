int counter = 0;

// Defines the time for the watchdog in ms
int watchdogTime = 1000;

// Must be present for watchdog timer to work
void watchdogSetup(void) 
{
// Optional setup
}

void setup() 
{
  // Enable watchdog
  watchdogEnable(watchdogTime);
  Serial.begin(115200);
}


void loop() 
{
  // Reset watchdog
  watchdogReset();

  Serial.println(counter);
  delay(500);

  // Enter into an infinite loop where the WDT is the only way to exit
  if(counter >= 10) { 
    while(true) {
      Serial.println("inside infinite loop");
      delay(100);
    }
  }

  // The value of counter will be reset by the WDT, only need to increment here
  counter++;
}