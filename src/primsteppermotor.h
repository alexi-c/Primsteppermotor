/*
primsteppermotor.h - Library for using a stepper motor in a primitive way using relays, or MOSFET's.
Created by Alexander M. Irvine, June 5, 2024
Released into public domain.
*/

#ifndef primsteppermotor_h                          //If library is not defined, define
#define primsteppermotor_h                          //Defines the library
#include <Arduino.h>                                //Includes Arduino Library

class Stepper                                       //Puts name for functions of the library
{
public:                                             //Code available for users of the library
  Stepper(int pinA, int pina, int pinB, int pinb);  //Defining pins based upon user selections
  void halfstep(int y, int x);                      //Preparing a variable to be later used for speed, and # rotations
  void quarterstep(int y, int x);
  void quarterbackstep(int y, int x); 
  void halfbackstep(int y, int x);               
  void lock();
  void unlock();
  void begin();

private:                                            //Code not available for the user
  int A;
  int a;
  int B;
  int b;
};
#endif
                                                    // Thank you to 6v6gt on Arduino Stack Exchange for a bugfix!