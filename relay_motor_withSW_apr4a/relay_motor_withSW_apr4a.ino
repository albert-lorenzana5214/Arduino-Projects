//#define CW 7 //CW is defined as pin #7//

//#define CCW 8 //CCW is defined as pin #8//

int CW = 7; //controls relay 2
int CCW = 8; //controls relay 1
int buttonPin = 4;
int buttonState = false;       // variable for reading the pushbutton status
int rotDirection = 0; // 0 is CW

void setup() { //Setup runs once//

  pinMode(CW, OUTPUT); //Set CW as an output//
  
  pinMode(CCW, OUTPUT); //Set CCW as an output//
  
  pinMode(buttonPin, INPUT); // initialize the pushbutton pin as an input:
  
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

}

void loop() { //Loop runs forever//

  buttonState = digitalRead(buttonPin);

  if (buttonState == false){
  
    Serial.println("CW");  // prints hello with ending line break
    digitalWrite(CCW, LOW); //Motor stops// 
    digitalWrite(CW,HIGH); //Motor runs clockwise//
    delay(20);
  }
  
  else{
    Serial.println("CCW");  // prints hello with ending line break 
    digitalWrite(CCW, HIGH);//Motor runs counter-clockwise//
    digitalWrite(CW, LOW); //Motor stops//
    delay(20); 
  }


} 
