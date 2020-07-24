//Defining colour constants to chip pins
#define RED 3 
#define GREEN 5
#define BLUE 6

//Assigning default pin modes and type
void setup(){
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

int red;
int green;
int blue; 

void loop()
{
  red = 0;
  green = 255;
  blue = 0;

  //Slowly turns green light into blue light
  for (int i = 0; i < 255; i += 1){
      green --;
      blue ++; 
      
      analogWrite(BLUE, blue);
      analogWrite(GREEN, green);
      delay(10);
  }
  
}
