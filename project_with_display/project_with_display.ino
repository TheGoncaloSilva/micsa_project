#include <Servo.h> // Include the Servo library 4
#include <Wire.h> // Librare used to locate the display
#include <LiquidCrystal_I2C.h>  // Used to interact with the display

const int servoPin = D8;
const int buzzerPin = D2; // Declare the buzzer
const int buzzerAuxPin = D4;
const int switchPin = D7;
int angryLevel = 0;
int lastValue = LOW;


Servo Servo1; // Create a servo object
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  Servo1.attach(servoPin);  // Bind pin to Servo
  pinMode(buzzerPin, OUTPUT); // Set buzzer as an output
  pinMode(buzzerAuxPin, OUTPUT);
  pinMode(switchPin, INPUT);  // Configure Pin to activate
  Serial.begin(9600); 
  lastValue = -1; // Value to be used on the switch

  lcd.begin();  // initialize the LCD
  
}

void loop() {
  int sValue = digitalRead(switchPin);  // Read switch value
  Serial.print("Switch: ");
  Serial.print(sValue);
  Serial.print("; LastValue: ");
  Serial.println(lastValue);
  showScreen(); 
  if(sValue == HIGH && lastValue == 0){ // only operate if switch value was changed
    increaseAnger();
    closeButton();
    buzz();
  }else{
    hide();
  }

  if(lastValue != sValue) // find if switch was altered
    lastValue = sValue;
}


/* Manage Anger */
void increaseAnger(){
  if(angryLevel < 10)
    angryLevel++;
}

/* Update info on the screen */
void showScreen(){
  lcd.backlight();
  static int efect = 0; // static variable to produce effects
  
  if(angryLevel == 0){
     if(efect) // different lines to produce a sleeping result
      lcd.print("ZzzZZzZ!");
     else
      lcd.print("zZzzZZzz!");

     efect = !efect;
  }else if(angryLevel >=1 && angryLevel <= 7 || angryLevel == 9){
     lcd.clear();
     lcd.print("Estás-me a chatear!");
     lcd.setCursor(0, 1); // change lines 
     int i;
     for(i=1;i<=angryLevel;i++)
      lcd.print("!");
  }
  else if(angryLevel == 8){
    lcd.clear();
    lcd.print("PARA!");
    lcd.setCursor(0, 1);
    lcd.print("Deixa-me!");
  }
  else if(angryLevel == 10){
    lcd.clear();
    lcd.print("Já chega, estou zangado!");
    lcd.setCursor(0, 1);
    lcd.print("Agora vais levar!");
  }
}

/* Turn off the switch */
void closeButton(){
  Servo1.write(0);
}

/* Hide the arm */
void hide(){
  Servo1.write(180);
}

/* Buzz or Alert anger */
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
