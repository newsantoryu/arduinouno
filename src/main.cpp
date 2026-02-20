#include <Arduino.h>
/*
const int redpostion = 9;
const int yellow = 8; 
const int green = 7;
const int buttonposition = 2;
const int redPedestrian = 10;
const int greenPedestrian = 11;
int phase;
int stateButton;
int tempStateButton;
int blinkState;
int blinkTimer;
*/
int myLeds[5] = {7, 8, 9, 10, 11};


void setup(){
  for (int i = 0; i < 5; i++)
  {
    pinMode(myLeds[i], OUTPUT);
  }
  

}



void loop(){
  for (int i = 0; i <= 5; i++)
  {
    digitalWrite(myLeds[i], HIGH);
      delay(300);

  }

  for (int i = 5; i >= 0; i--)
  {
    digitalWrite(myLeds[i], LOW);
      delay(300);

  }
}