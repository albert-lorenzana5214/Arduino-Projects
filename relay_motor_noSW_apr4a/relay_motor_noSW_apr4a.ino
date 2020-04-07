//#define CW 7 //CW is defined as pin #7//

//#define CCW 8 //CCW is defined as pin #8//

int CW = 7; //controls relay 2
int CCW = 8; //controls relay 1

void setup() { //Setup runs once//

pinMode(CW, OUTPUT); //Set CW as an output//

pinMode(CCW, OUTPUT); //Set CCW as an output//

Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

}

void loop() { //Loop runs forever//

Serial.println("CW");  // prints hello with ending line break 

digitalWrite(CW,HIGH); //Motor runs clockwise//

delay(2500); //for 1 second//

digitalWrite(CW, LOW); //Motor stops//


Serial.println("CCW");  // prints hello with ending line break 

digitalWrite(CCW, HIGH);//Motor runs counter-clockwise//

delay(2500); //For 1 second//

digitalWrite(CCW, LOW); //Motor stops//

} 
