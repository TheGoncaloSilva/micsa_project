#include <Servo.h> // Include the Servo library 

const int servoPin = D7; // Declare the Servo pin 
const int buzzerPin = D8; // Declare the buzzer
const int auxPin = D2;

Servo Servo1; // Create a servo object 
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 
   pinMode(buzzerPin, OUTPUT); // Set buzzer as an output
   pinMode(LED_BUILTIN, OUTPUT);
   pinMode(auxPin, OUTPUT);
}
void loop(){ 
   // Make servo go to 0 degrees 
   digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
   tone(buzzerPin, 1000); // Send 1KHz sound signal...
   digitalWrite(auxPin, HIGH);
   Servo1.write(0); 
   delay(1000); 
   digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
   noTone(buzzerPin);     // Stop sound...
   digitalWrite(auxPin, LOW);
   // Make servo go to 90 degrees 
   Servo1.write(90); 
   delay(1000); 
   digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
   tone(buzzerPin, 1000); // Send 1KHz sound signal...
   digitalWrite(auxPin, HIGH);
   // Make servo go to 180 degrees 
   Servo1.write(180); 
   delay(1000); 
   digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
   digitalWrite(auxPin, LOW);
   noTone(buzzerPin);     // Stop sound...
}
