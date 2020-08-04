//Defining ports
const int ledPin = 5;
const int buttonPin = 2;  

//Defining button pressed states
bool prev = HIGH; //High means that button is not pressed 
bool curr = HIGH;
bool led = LOW;

void setup() {
  
  //Setting up Serial monitor
  Serial.begin(9600);
  
  //Setting up pin modes
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  //Get current pressed date from switch
  curr = debounce(prev);

  if (curr == LOW && prev == HIGH){
    led = !led;
    digitalWrite(ledPin, led);
  }
  
  //Previous state is changed to current button state.
  //This state only changes when 
  prev = curr;
}

bool debounce(bool prev){
  bool current = digitalRead(buttonPin);

  
  if (prev != current){
    delay(5); //5 milliseconds
    current = digitalRead(buttonPin);
  }
  return current; 
}
