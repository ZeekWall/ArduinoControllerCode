#include <Joystick2.h>

// Define macros here
#define NUM_BUTTONS 5
#define NUM_ANALOGS 4

// Declare global variables here
int buttons[NUM_BUTTONS] = {9, 10, 11, 12, 5};
int analogs[NUM_ANALOGS] = {A2, A3, A4, A5};

void setup() {
  // put your setup code here, to run once:

  pinMode(buttons[0], INPUT_PULLUP);  // pin  9 == far left button
  pinMode(buttons[1], INPUT_PULLUP); // pin 10 == far right button
  pinMode(buttons[2], INPUT_PULLUP); // pin 11 == third  button from left
  pinMode(buttons[3], INPUT_PULLUP); // pin 12 == second button from left
  pinMode(buttons[4], INPUT_PULLUP);

  Joystick[0].begin();
  Joystick[1].begin();

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int buttonState = !digitalRead(buttons[0]);
  Joystick[0].setButton(0, buttonState);

  int buttonState2 = !digitalRead(buttons[3]);
  Joystick[0].setButton(1, buttonState2);

  int buttonState3 = !digitalRead(buttons[2]);
  Joystick[0].setButton(2, buttonState3);

  int buttonState4 = !digitalRead(buttons[1]);
  Joystick[0].setButton(3, buttonState4);
  
  int buttonState5 = !digitalRead(buttons[4]);
  Joystick[0].setButton(4, buttonState5);

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

  Serial.println(analogState);
  Serial.println(analogState2);
  
  

}
