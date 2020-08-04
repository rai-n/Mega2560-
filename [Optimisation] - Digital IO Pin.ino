//Example 1 : Power save

void setup() {
  
  //Setting up Serial monitor
  Serial.begin(9600);
  
  //Setting up pin modes
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  //Power Save
  //Setting all the unused digital IO pins to LOW to save power. 
  for (int i = 0; i < 20; i ++){
    if (i != buttonPin){
      pinMode(i, OUTPUT);
      digitalWrite(i, LOW);  
    }
  }
}
