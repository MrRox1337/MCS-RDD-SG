// Week 1 Post Demo
// Aman Mishra
// 30/06/2024

#include<Servo.h>

// Pin init
int LEDS[3] = {6,7,8};
int TRIG = 11;
int ECHO = 10;
int SERVO = 3;

// Object init
Servo myServo;

void setup()
{
  for (int led : LEDS) {
  	pinMode(led, OUTPUT);
  }
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  
  myServo.attach(SERVO);
  
  Serial.begin(9600);
}

void loop()
{
  // Calculate distance
  int distance = ping_cm();
  
  // Calculate servo angle
  int angle = 0;
  if(distance > 100){
    angle = 180;
  } else if (distance >=25) {
    angle = map(distance, 25, 100, 0, 179);
  }
  
  // Set servo angle
  myServo.write(angle);
  
  // Set LEDs
  (distance > 100)? digitalWrite(LEDS[2], LOW) : digitalWrite(LEDS[2],HIGH);
  (distance > 63 )? digitalWrite(LEDS[1], LOW) : digitalWrite(LEDS[1],HIGH);
  (distance > 25 )? digitalWrite(LEDS[0], LOW) : digitalWrite(LEDS[0],HIGH);
}

int ping_cm()
{
  // Send trigger pulse
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Calculate Time of Flight
  long duration = pulseIn(ECHO, HIGH);
  
  return duration * 0.034 / 2;
}





