void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(150); // Wait for 90 milliseconds
    digitalWrite(LED_BUILTIN, LOW);
    delay(850); // Wait for 910 milliseconds
}
