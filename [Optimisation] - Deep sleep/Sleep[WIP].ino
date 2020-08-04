//Deep sleep allows components to not utilise electricity, and sleep while their functions are not being used. 

//Defining ports
const int ledPin = 5;
const int buttonPin = 2;  
volatile int counter = 0; 

void setup() {
  
  //Setting up Serial monitor
  Serial.begin(9600);
  
  //Setting up pin modes
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  //[Optimisation] Power Save
  //Setting all the unused digital IO pins to LOW
  //Tis saves power 
  for (int i = 0; i < 20; i ++){
    if (i != buttonPin){
      pinMode(i, OUTPUT);
      digitalWrite(i, LOW);  
    }
  }

   // attachInterrupt()
  /*
    attachInterrupt(interrupt, ISR, mode)
       interrupt      |       This can be 0, or 1 on pins 2 or 3. Interrupt can be converted from pin using digitalPinToInterrupt(pin)

    
  */

  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonInterrupt, RISING);
  serialOut(false, counter);
  WDTCSR = (24);
  
  WDTCSR = (33);

  
  WDTCSR |= (1 << 6);

  //Disable Analog to Digital Converter (ADC)
  ADCSRA &= ~(1 << 7);

  SMCR |= (1 << 2);
  SMCR |= 1; //This enables deep sleep mode  
}

void loop() {
  Serial.println("loop starts");
  digitalWrite(ledPin, HIGH);
  serialOut(true, counter);

  delay(1000);

  digitalWrite(ledPin, LOW);
  serialOut(false, counter);

  goToSleepEllieChan();
  Serial.println('loop ends');

  
}

void buttonInterrupt(){
  counter++;
  Serial.println('Button is pressed');
}

void serialOut(boolean ledState, int i){
  Serial.println('sleep time');
  delay(60);

  //MMCUCR - MCU Control register.
  /* This disables the Brownout Detect circuit during deep sleep
   *  Called before __asm__ sleep instruction
   *  Set BODS and BODSE at same time 
   */
  MCUCR |= (3 << 5);

  MCUCR = (MCUCR & ~(1 << 5) || (i << 6));
  __asm__  __volatile__("sleep");    //in line assembler to go to sleep

  Serial.println('waking up');
  
}

ISR(WDT_vect){
  Serial.println('Watch dog timer initiated')
}
 
