#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// And connect 2 DC motors to port M3 & M4 !
Adafruit_DCMotor *L_MOTOR = AFMS.getMotor(3);
Adafruit_DCMotor *R_MOTOR = AFMS.getMotor(4);

// And connect the Sharp distance sensors
int leftSensor = A4;
int rightSensor = A5;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  pinMode(leftSensor, INPUT); // set up distance sensor pins
  pinMode(rightSensor, INPUT);

  AFMS.begin();  // create with the default frequency 1.6KHz

}

void loop() {
  L_MOTOR->setSpeed(100); 
  R_MOTOR->setSpeed(100);
  L_MOTOR->run(FORWARD);
  R_MOTOR->run(FORWARD);

  Serial.print("right sensor:");
  Serial.println(digitalRead(rightSensor));

  Serial.print("left sensor:");
  Serial.println(digitalRead(leftSensor));
  
  while (digitalRead(rightSensor) == LOW){
    L_MOTOR->setSpeed(100); 
    R_MOTOR->setSpeed(100);
    L_MOTOR->run(BACKWARD);
    R_MOTOR->run(RELEASE);
  }

  while (digitalRead(leftSensor) == LOW){
    L_MOTOR->setSpeed(100); 
    R_MOTOR->setSpeed(100);
    L_MOTOR->run(RELEASE);
    R_MOTOR->run(BACKWARD);
  }
  
}
