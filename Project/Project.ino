#include <Servo.h> // Include the Servo library 

const int servoPin = D8;
const int buzzerPin = D2; // Declare the buzzer
const int buzzerAuxPin = D4;
const int switchPin = D7;
int angryLevel = 0;
int lastValue = LOW;


Servo Servo1; // Create a servo object 

void setup() {
  // put your setup code here, to run once:
  Servo1.attach(servoPin); 
  pinMode(buzzerPin, OUTPUT); // Set buzzer as an output
  pinMode(buzzerAuxPin, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600); 
  lastValue = -1;
}

void loop() {
  int sValue = digitalRead(switchPin);
  Serial.print("Switch: ");
  Serial.print(sValue);
  Serial.print("; LastValue: ");
  Serial.println(lastValue);
  if(sValue == HIGH && lastValue == 0){
    increaseAnger();
    closeButton();
    buzz();
  }else{
    hide();
  }

  if(lastValue != sValue)
    lastValue = sValue;
}

void increaseAnger(){
  if(angryLevel < 10)
    angryLevel++;
}

void showScreen(){

}

void detectHand(){
  /*if(angryLevel > 5 && (rand() % 1) == 0){
    continue;
  }*/
}

void closeButton(){
  Servo1.write(15);
}

void hide(){
  Servo1.write(180);
}

void buzz(){
  if(angryLevel <= 0) return; // pre-condition
  Serial.println(angryLevel);
  if(angryLevel < 8 || angryLevel == 9){
    tone(buzzerPin, (400*angryLevel));
    digitalWrite(buzzerAuxPin, HIGH);
    delay(500);
  }else if(angryLevel == 8){
    for(int i=1000 ; i<(2000 + angryLevel * 100) ; i+=angryLevel){ // loop for to increase the sound frequency
         tone(buzzerPin, i);
         digitalWrite(buzzerAuxPin, HIGH);
         delay(10); //You can change the delay if you want to make it longer or shorter
    }
  }else{ // angryLevel 10
    int i;
    for(i=1000 ; i<(3000 + angryLevel * 100) ; i+=angryLevel){ // loop for to increase the sound frequency
         tone(buzzerPin, i);
         digitalWrite(buzzerAuxPin, HIGH);
         delay(10); //You can change the delay if you want to make it longer or shorter
    }
    for(; i>1000 ; i-=angryLevel){ // loop for to increase the sound frequency
         tone(buzzerPin, i);
         digitalWrite(buzzerAuxPin, HIGH);
         delay(10); //You can change the delay if you want to make it longer or shorter
    } 
  }
  noTone(buzzerPin);     // Stop sound...
  digitalWrite(buzzerAuxPin, LOW);
  
}
