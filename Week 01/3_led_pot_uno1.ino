// Initialize Potentiometer
int potpin = 5;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

// Initialize LED pins
int leds[3] = {2,3,4};

void setup()
{
  for (int led : leds) {
  	pinMode(led, OUTPUT);
  }
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 100);	   // scale it to get a percentage value
  
  (val > 70)? digitalWrite(leds[2], HIGH):digitalWrite(leds[2],LOW);
  (val > 30)? digitalWrite(leds[1], HIGH):digitalWrite(leds[1],LOW);
  (val > 5 )? digitalWrite(leds[0], HIGH):digitalWrite(leds[0],LOW);
  
  Serial.println(val);
  
  delay(10); // Delay a little bit to improve simulation performance
}