#include <Servo.h>

// servo initializers
Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

// sonic1 initializers
const int trigPin = 10;
const int echoPin = 9;
long duration;
int distance;

void setup() {
  // servo
  myservo.attach(5);  // attaches the servo on pin 9 to the servo object
  
  // sonic1
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
  
  digitalWrite(trigPin, LOW);		   // Clears the trigPin
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);		   // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);   // Reads the echoPin, returns the sound wave travel time in microseconds
  
  distance = duration * 0.034 / 2;	   // Calculating the distance
  
  Serial.print("Distance: ");          // Prints the distance on the Serial Monitor
  Serial.println(distance);

}