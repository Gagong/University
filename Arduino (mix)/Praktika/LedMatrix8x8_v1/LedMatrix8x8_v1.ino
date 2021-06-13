#include "Stepper.h"
#define STEPS  32
int Steps2Take;
int xPin = A1;
int yPin = A0;
int buttonPin = 2;
int xPosition = 0;
int yPosition = 0;
int buttonState = 0;

Stepper small_stepper(STEPS, 8, 10, 9, 11);

void setup() { 
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  if (yPosition < 500) {
    small_stepper.setSpeed(1000);
    Steps2Take  =  100;
    small_stepper.step(Steps2Take);
  }
  if (yPosition > 600) {
    small_stepper.setSpeed(1000);
    Steps2Take  =  -100;
    small_stepper.step(Steps2Take);
  }
  Serial.print("X: "); //X: 12 | Y: 123 | Bsdas
  Serial.println(xPosition);
  Serial.print("Y: ");
  Serial.println(yPosition);
    /*switch(yPosition) {
      case 0:
               small_stepper.setSpeed(1000);
               Steps2Take  =  2048;
               small_stepper.step(Steps2Take);
               delay(2000); 
               break;
      case 1023:
               small_stepper.setSpeed(1000);
               Steps2Take  =  -2048;
               small_stepper.step(Steps2Take);
               delay(2000); 
               break;            
      }*/
}  




