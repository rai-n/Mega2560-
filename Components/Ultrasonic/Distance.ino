#include "SR04.h"

const int TRIG_PIN = 12;
const int ECHO_PIN = 11;

SR04 ray = SR04(ECHO_PIN,TRIG_PIN);
long distance;

void setup() {
   Serial.begin(9600);//Initialization of Serial Port
   delay(1000);
}

void loop() {
   distance = ray.Distance();
   Serial.print(distance);
   Serial.println("cm"); 
   delay(1000);
}
