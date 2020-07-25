 
 
#include <Servo.h>
/* After including the corresponding libraries,
   we can use the "class" like "Servo" created by the developer for us.
   We can use the functions and variables created in the libraries by creating 
   objects like the following "myservo" to refer to the members in ".".*/

Servo myservo;
//it created an object called myservo.
/*  you can see Servo as a complex date type(Including functions and various data types)
    and see myservo as variables.               */

void setup(){
  /*"attach" and "write" are both functions,
     and they are members contained in the complex structure of "Servo". 
     We can only use them if we create the object "myservo" for the complex structure of "Servo".
  */
  myservo.attach(9);//connect pin 9 with the control line(the middle line of Servo) 
  myservo.write(90);// move servos to center position -> 90°
} 
void loop(){
 
  myservo.write(180);// move servos to center position -> 180°
  delay(1000);
  myservo.write(160);// move servos to center position -> 160°
  delay(1000);
  myservo.write(140);// move servos to center position -> 140°
  delay(1000);
  myservo.write(130);// move servos to center position -> 130°
  delay(1000);
  myservo.write(110);// move servos to center position -> 110°
  delay(1000);
  myservo.write(90);// move servos to center position -> 90°
  delay(1000);
  myservo.write(70);// move servos to center position -> 70°
  delay(1000);
  myservo.write(50);// move servos to center position -> 50°
  delay(1000);
  myservo.write(30);// move servos to center position -> 30°
  delay(1000);
 myservo.write(10);// move servos to center position -> 10°
  delay(1000);
}
