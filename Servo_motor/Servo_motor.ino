#include <Servo.h> // Include the Servo library 

// Declare the Servo pin 
int servoPin = D8; 
// Create a servo object 

Servo Servo1; 
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 
   pinMode(LED_BUILTIN, OUTPUT);
}
void loop(){ 
   // Make servo go to 0 degrees 
   digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
   Servo1.write(0); 
   delay(1000); 
   digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
   // Make servo go to 90 degrees 
   Servo1.write(90); 
   delay(1000); 
   digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
   // Make servo go to 180 degrees 
   Servo1.write(180); 
   delay(1000); 
   digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}
