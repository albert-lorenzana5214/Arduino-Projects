#include "blinkSlow.h"

blinkSlow::blinkSlow(int led1)
{
         blinkSlow(led1) ;   // wait for a second
}

void blinkSlow::blinkSlow(int led1) {
  digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);             // wait for a second
  digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
}
