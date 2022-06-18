#include <Servo.h> // Include the Servo library 

// Declare the Servo pin 
const int servoPin = D8;
const int switchPin = D7;
// Create a servo object 

Servo Servo1; 
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 
   pinMode(switchPin, INPUT);
   //Serial.begin(9600); 
}
void loop(){ 

   if(digitalRead(switchPin) == HIGH){
    Servo1.write(0);
   }else{
    Servo1.write(180);
   }
   /*Servo1.write(5); 
   delay(1000);
   Servo1.write(180); 
   delay(1000);*/
  
   /*Serial.print("Pin1: ");
   Serial.print(digitalRead(switchPin));  
   Serial.println();
   delay(1000);*/

}
