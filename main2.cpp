#include <Arduino.h>
 
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


void setup() {
  pinMode(redpostion, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(redPedestrian, OUTPUT);
  pinMode(greenPedestrian,OUTPUT);
  pinMode(buttonposition, INPUT);
  phase = 7;
  tempStateButton = stateButton;
  blinkState = HIGH;
  blinkTimer = 0;
}

void loop() {

  stateButton = digitalRead(buttonposition);

//se inverter os estados do botao, a funcionalidade do botao é ao soltar... 
  if (stateButton == HIGH && tempStateButton == LOW) {
    if (phase < 10) {
       phase = phase + 1;
    } else {
      phase = 7;
    }
  }
    tempStateButton = stateButton;

      if(phase == 7){
      digitalWrite(green,HIGH);
      digitalWrite(yellow,LOW);
      digitalWrite(redpostion,LOW);

      digitalWrite(redPedestrian,HIGH);
      digitalWrite(greenPedestrian,LOW);
    }
    if(phase == 8){
      digitalWrite(green,LOW);
      digitalWrite(yellow,HIGH);
      digitalWrite(redpostion,LOW);
      
      digitalWrite(redPedestrian,HIGH);
      digitalWrite(greenPedestrian,LOW);
    } if(phase == 9){
      digitalWrite(green,LOW);
      digitalWrite(yellow,LOW);
      digitalWrite(redpostion,HIGH);

      digitalWrite(redPedestrian,LOW);
      digitalWrite(greenPedestrian,HIGH);


    }
     if(phase == 10){
      digitalWrite(green,LOW);
      digitalWrite(yellow,LOW);
      digitalWrite(redpostion,HIGH);


      blinkTimer = blinkTimer + 1;
      if (blinkTimer == 400)
      {
        blinkState = !blinkState;
        blinkTimer = 0;
      }
      

      digitalWrite(redPedestrian,blinkState);
      digitalWrite(greenPedestrian,LOW);


    }
    delay(1);

}

