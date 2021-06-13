#include "Stepper.h"
#define STEPS 32
Stepper stepp(STEPS, 8, 10, 9, 11);

void setup() {
  pinMode(2, INPUT);
}

void loop() {
   if (digitalRead(2) == HIGH ) {
    stepp.setSpeed(1000);
    stepp.step(1);
  }
}





