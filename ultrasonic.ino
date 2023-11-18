int RED_LED = 2;
int GREEN_LED = 4;
int TRIG = 7; //Trigger Pin to Ultrasonic Sensor
int ECHO = 8; //echo pin to read from

unsigned long pulseWidth; //pulseWidth in microseconds
int distance; //distance

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  pulseWidth = pulseIn(ECHO, 50000); //Checks if the ECHO pin is pulled to HIGH. timeout = 50000us. pulse width is in us
  Serial.println(pulseWidth);

  distance = 343.0 * 100.0 * (pulseWidth/2000000.0) ; //in cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  //Based on distance to obstacle - turn on/off motor driver for 4 wheels
  //Downside fo this approach - constant polling. Constant computation on Arduino

  delay(60);
}
