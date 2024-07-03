// Two pin definition techniques
#define motorA 5
#define motorB 6

int OLDCp = 8;
int OLDCm = 9;

void setup() {
  pinMode(motorA,OUTPUT);
  pinMode(motorB,OUTPUT);
  pinMode(OLDCp,OUTPUT);
  pinMode(OLDCm,OUTPUT);
}

void loop() {
  
  // Encoder motor clockwise
  analogWrite(motorB,255);
  digitalWrite(motorA,LOW);
  
  delay(700);
  // Encoder motor counterclockwise
  analogWrite(motorA,255);
  digitalWrite(motorB,LOW);
  
  delay(700);
  // OLDC motor clockwise
  digitalWrite(OLDCp,HIGH);
  digitalWrite(OLDCm,LOW);
  
  delay(700);
  // OLDC motor counterclockwise
  digitalWrite(OLDCp,LOW);
  digitalWrite(OLDCm,HIGH);
  
  
}