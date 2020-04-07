#include "blinkSlow.h"
/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

void blinkSlow(int led1);

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {

    blinkSlow bs;

}


void blinkFast(int led2){
  digitalWrite(led2, HIGH);
  delay(10);
  digitalWrite(led2,LOW);
  delay(100);
}
