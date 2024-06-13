#include "primsteppermotor.h"      //My amazing library

Stepper Stepper(2, 3, 4, 5);       //Stepper motor pins starting with the A loop, then the B loop.

void setup() {
  delay(1000);                     //Delay before the first Serial message
  Serial.begin(9600);              //Begins Serial for bugfixing
  Stepper.begin();                 //Begins Stepper library
}

void loop() {

  Stepper.halfstep(50, 10);        //Setting speed of 50ms per 4 delays, 10 steps total
  Stepper.quarterstep(25, 10);     //Setting speed of 25ms per 8 delays, 10 steps total
  Stepper.quarterbackstep(25, 10); //Setting speed of 25ms per 8 delays, 10 steps total
  Stepper.halfbackstep(50, 10);    //Setting speed of 50ms per 4 delays, 10 steps total
  Stepper.lock();                  //Locking motor
  delay(1000);                     //Keeping lock on for 1 second
  Stepper.unlock();                //Unlocking motor
  delay(1000);                     //Keeping unlock on for 1 second
}