int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT);  
 }

void loop() 
{
  if (digitalRead(buttonApin) == LOW)
  {
    digitalWrite(ledPin, HIGH);
  } 

    if (digitalRead(buttonBpin) == HIGH)
  {
    digitalWrite(ledPin, LOW);
  } 
 
 
  
}
