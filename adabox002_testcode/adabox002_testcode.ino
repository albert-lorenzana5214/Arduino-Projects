/* 
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

For use with the Adafruit Motor Shield v2 
---->	http://www.adafruit.com/products/1438
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Set up the left motor on port M4
Adafruit_DCMotor *leftMotor = AFMS.getMotor(4);
// Set up the right motor on port M3
Adafruit_DCMotor *rightMotor = AFMS.getMotor(3);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - Robot Test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
}

void loop() {
  // Set the speed to start, from 0 (off) to 255 (max speed)
  leftMotor->setSpeed(100);
  rightMotor->setSpeed(100);
  
  leftMotor->run(FORWARD); //LEFT MOTOR FULL STEAM AHEAD!
  rightMotor->run(FORWARD); //RIGHT MOTOR FULL STEAM AHEAD!
}