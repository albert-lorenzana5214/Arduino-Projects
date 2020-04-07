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
  
  digitalWrite(CW, LOW);
  digitalWrite(CCW, HIGH);
  
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

}

void loop() { //Loop runs forever//
  
    // Read button - Debounce
  if (digitalRead(buttonPin) == false) {
    buttonState = !buttonState;
  }
  while (digitalRead(buttonPin) == false);
  delay(20);

 

  if (buttonState== true  & rotDirection == 0){
  
    Serial.println("CW");  // prints hello with ending line break
    digitalWrite(CW,HIGH); //Motor runs clockwise//
    digitalWrite(CCW, LOW); //Motor stops// 
    Serial.println(rotDirection);  // prints hello with ending line break
    rotDirection = 1;
    delay(20);
  }
  
  if (buttonState == false  & rotDirection == 1){
    Serial.println("CCW");  // prints hello with ending line break 
    digitalWrite(CCW, HIGH);//Motor runs counter-clockwise//
    digitalWrite(CW, LOW); //Motor stops// 
    Serial.println(rotDirection);
    rotDirection = 0;
    delay(20);
  }


} 
