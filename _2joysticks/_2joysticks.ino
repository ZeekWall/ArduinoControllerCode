// Program used to test the Dual Simple USB Joystick object 
// on the Arduino Leonardo or Arduino Micro.
//
// Matthew Heironimus
// 2015-04-05
//------------------------------------------------------------

#include "Joystick2.h"

// Define macros here
#define NUM_BUTTONS 4
#define NUM_ANALOGS 4

// Declare global variables here
int buttons[NUM_BUTTONS] = {9, 10, 11, 12};
int analogs[NUM_ANALOGS] = {A2, A3, A4, A5};


void setup() {
  // Do setup code here. Setup runs ONCE, at the beginning of execution.
  // After setup, the code proceeds down to loop(), where it will loop (hence the name)
  // indefinitely until it is told to stop.


  // Digital pins must be initialized as either input (pullup or not) or output before being used
  // Then, to read from them, use digitalRead(#);
  pinMode(buttons[0], INPUT_PULLUP);  // pin  9 == far left button
  pinMode(buttons[1], INPUT_PULLUP); // pin 10 == far right button
  pinMode(buttons[2], INPUT_PULLUP); // pin 11 == third  button from left
  pinMode(buttons[3], INPUT_PULLUP); // pin 12 == second button from left

  // Analog input pins do not need to be initialized with pinMode. They are analog inputs by default.
  // They simply need to be read with analogRead(A#);
  // see the above declaration of the global variable arrray "analogs" to see the analog input names.
  
  Joystick[0].begin();
  Joystick[1].begin();
  
}

void loop() {
  // This section will loop indefinitely until it is told to stop, or the board is powered off
  // that means anything that you put in here will execute repeatedly, really fast.
  
  int buttonState = !digitalRead(buttons[0]);
  Joystick[0].setButton(0, buttonState);

  int buttonState2 = !digitalRead(buttons[3]);
  Joystick[0].setButton(1, buttonState2);

  int buttonState3 = !digitalRead(buttons[2]);
  Joystick[0].setButton(2, buttonState3);

  int buttonState4 = !digitalRead(buttons[1]);
  Joystick[0].setButton(3, buttonState4);

  int analogState = analogRead(analogs[0]);
  int analogStateMap = map(analogState, 0, 1024, -127, 127); 
  Joystick[0].setXAxis(analogStateMap);

  int analogState2 = analogRead(analogs[1]);
  int analogStateMap2 = map(analogState2, 0, 1024, 127, -127); 
  Joystick[0].setYAxis(analogStateMap2);

    int analogState3 = analogRead(analogs[2]);
  int analogStateMap3 = map(analogState3, 0, 1024, 127, -127); 
  Joystick[1].setYAxis(analogStateMap3);

  int analogState4 = analogRead(analogs[3]);
  int analogStateMap4 = map(analogState4, 0, 1024, -127, 127); 
  Joystick[1].setXAxis(analogStateMap4);

}

