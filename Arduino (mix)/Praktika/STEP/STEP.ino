#include "Stepper.h"
#define STEPS 32
int Steps2Take;
int button = 2;
Stepper small_stepper(STEPS, 8, 10, 9, 11);

void setup() {
  pinMode(button, INPUT);
}

void loop() {
  //small_stepper.setSpeed(1000);
  Steps2Take = 0;
   if (digitalRead(button) == HIGH ) {
    small_stepper.setSpeed(1000);
    Steps2Take = 1;
    small_stepper.step(Steps2Take);
  }
}





