#include "SevSeg.h"

SevSeg sevseg; //Initiate a seven segment controller object

void setup() {

byte numDigits = 4;

byte digitPins[] = {3, 7, 2, 6};

byte segmentPins[] = {12, 3, 9, 8, 13, 11, 5, 4};

sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);

sevseg.setBrightness(90);

}

void loop() {

sevseg.setNumber(3141, 3);

sevseg.refreshDisplay(); // Must run repeatedly

}
