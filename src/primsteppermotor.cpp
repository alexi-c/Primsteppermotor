#include "primsteppermotor.h"                               //Part of the library
#include "Arduino.h"                                        //Arduino Library

Stepper::Stepper(int pinA, int pina, int pinB, int pinb) {  //How the sketch determins the 4 pins to use for the Stepper motor
  A = pinA;                                                 //Setting pin for Phase A
  a = pina;                                                 //Setting pin for Phase A Reverse Polarity
  B = pinB;                                                 //Setting pin for Phase B
  b = pinb;                                                 //Setting pin for Phase B Reverse Polarity
}

void Stepper::begin() {
  pinMode(A, OUTPUT);                                       //Setting OUTPUTS for each relay or transistor
  pinMode(a, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(b, OUTPUT);
  digitalWrite(A, LOW);
  digitalWrite(a, LOW);
  digitalWrite(B, LOW);
  digitalWrite(b, LOW);
  Serial.println("Initialized");                            //Bugfixing Serial message
}

void Stepper::halfstep(int x, int y)  //speed, #rotations Setting speed between every step (divide by 4 for a full step), and setting the number of steps. Most stepper motors are 48 steps
{
  Serial.println("Stepping Forward With Half Step");  //Bugfixing Serial message
  for (int i = 0; i < y; i++) {                       //Code for repeating the steps based upon settings
    Serial.println("Stepping");                       //Bugfixing Serial message
    digitalWrite(A, HIGH);                            //Specific instructions to turn pins HIGH and LOW for the stepper to do a step
    digitalWrite(a, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(b, LOW);
    delay(x);                                         //Delay based upon settings

    digitalWrite(A, LOW);
    digitalWrite(a, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(b, LOW);
    delay(x);

    digitalWrite(A, LOW);
    digitalWrite(a, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(b, HIGH);
    delay(x);

    digitalWrite(A, HIGH);
    digitalWrite(a, LOW);
    digitalWrite(B, LOW);
    digitalWrite(b, HIGH);
    delay(x);
  }
}


void Stepper::quarterstep(int x, int y)                  //speed, #rotations Setting speed between every step (divide by 8 for a full step), and setting the number of steps. Most stepper motors are 48 steps
{
  Serial.println("Stepping Forward With Quarter Step");  //Bugfixing Serial message
  for (int i = 0; i < y; i++) {                          //Code for repeating the steps based upon settings
    Serial.println("Stepping");                          //Bugfixing Serial message
    digitalWrite(A, HIGH);
    digitalWrite(a, LOW);
    digitalWrite(B, LOW);
    digitalWrite(b, LOW);
    delay(x);

    digitalWrite(A, HIGH);
    digitalWrite(a, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(b, LOW);
    delay(x);

    digitalWrite(A, LOW);
    digitalWrite(a, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(b, LOW);
    delay(x);

    digitalWrite(A, LOW);
    digitalWrite(a, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(b, LOW);
    delay(x);

    digitalWrite(A, LOW);
    digitalWrite(a, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(b, LOW);
    delay(x);

    digitalWrite(A, LOW);
    digitalWrite(a, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(b, HIGH);
    delay(x);

    digitalWrite(A, LOW);
    digitalWrite(a, LOW);
    digitalWrite(B, LOW);
    digitalWrite(b, HIGH);
    delay(x);

    digitalWrite(A, HIGH);
    digitalWrite(a, LOW);
    digitalWrite(B, LOW);
    digitalWrite(b, HIGH);
    delay(x);
  }
}


void Stepper::quarterbackstep(int x, int y)               //speed, #rotations Setting speed between every step (divide by 8 for a full step), and setting the number of steps. Most stepper motors are 48 steps
{
  Serial.println("Stepping Backward With Quarter Step");  //Bugfixing Serial message
  for (int i = 0; i < y; i++) {                           //Code for repeating the steps based upon settings
    Serial.println("Stepping");                           //Bugfixing Serial message
    digitalWrite(A, HIGH);
    digitalWrite(a, LOW);
    digitalWrite(B, LOW);
    digitalWrite(b, HIGH);
    delay(x);

    digitalWrite(A, LOW);
    digitalWrite(a, LOW);
    digitalWrite(B, LOW);
    digitalWrite(b, HIGH);
    delay(x);

    digitalWrite(A, LOW);
    digitalWrite(a, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(b, HIGH);
    delay(x);

    digitalWrite(A, LOW);
    digitalWrite(a, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(b, LOW);
    delay(x);

    digitalWrite(A, LOW);
    digitalWrite(a, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(b, LOW);
    delay(x);

    digitalWrite(A, LOW);
    digitalWrite(a, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(b, LOW);
    delay(x);

    digitalWrite(A, HIGH);
    digitalWrite(a, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(b, LOW);
    delay(x);

    digitalWrite(A, HIGH);
    digitalWrite(a, LOW);
    digitalWrite(B, LOW);
    digitalWrite(b, LOW);
    delay(x);
  }
}


void Stepper::halfbackstep(int x, int y)               //speed, #rotations Setting speed between every step (divide by 4 for a full step), and setting the number of steps. Most stepper motors are 48 steps
{
  Serial.println("Stepping Backward With Half Step");  //Bugfixing Serial message
  for (int i = 0; i < y; i++) {                        //Code for repeating the steps based upon settings
    Serial.println("Stepping");                        //Bugfixing Serial message
    digitalWrite(A, HIGH);
    digitalWrite(a, LOW);
    digitalWrite(B, LOW);
    digitalWrite(b, HIGH);
    delay(x);

    digitalWrite(A, LOW);
    digitalWrite(a, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(b, HIGH);
    delay(x);

    digitalWrite(A, LOW);
    digitalWrite(a, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(b, LOW);
    delay(x);

    digitalWrite(A, HIGH);
    digitalWrite(a, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(b, LOW);
    delay(x);
  }
}


void Stepper::lock()                                   //Locks Motor
{
  Serial.println("Locking motor");                     //Bugfixing Serial message
  Serial.println("Locking");        //Bugfixing Serial message
  digitalWrite(A, HIGH);
  digitalWrite(a, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(b, LOW);
}

void Stepper::unlock()                                 //Unlocks Motor
{
  Serial.println("Unlocking motor");                   //Bugfixing Serial message
  digitalWrite(A, LOW);
  digitalWrite(a, LOW);
  digitalWrite(B, LOW);
  digitalWrite(b, LOW);
}
