#include <Servo.h> // Include the Servo library 

const int servoPin = ;
const int buzzerPin = ; // Declare the buzzer
const int buzzerAuxPin = ;
const int switchPin1 = ;
const int switchPin2 = ;
const int switchPin3 = ;
int angryLevel = 1;


Servo Servo1; // Create a servo object 

void setup() {
  // put your setup code here, to run once:
  Servo1.attach(servoPin); 
  pinMode(buzzerPin, OUTPUT); // Set buzzer as an output
  pinMode(auxPin, OUTPUT);
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  pinMode(switchPin3, INPUT);
}

void loop() {
  if(digitalRead(switchPin1) == HIGH && digitalRead(switchPin2) == HIGH){
    increaseAnger();
    closeButton();
    buzz();
  }else if(digitalRead(switchPin2) == HIGH && digitalRead(switchPin3) == HIGH)
    detectHand();
}

void increaseAnger(){
  
}

void showScreen(){

}

void detectHand(){
  if(angryLevel > 5 && (rand() % 1) == 0){
    while()
  }
}

void closeButton(){
  Servo1.write(180);
  delay(100);
}

void buzz(){
  tone(buzzerPin, (100*angryLevel));
  digitalWrite(buzzerAuxPin, HIGH);
  delay(500);
  noTone(buzzerPin);     // Stop sound...
  digitalWrite(buzzerAuxPin, LOW);
}
