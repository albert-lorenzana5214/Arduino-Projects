/*
  Project: 4-Digit 7-segment display module (common cathode)
  Function: Timer. You can see the number on timer decreases by 1 second from 20 to 0 then timer will flash twice and restart
  in 2 seconds
*/
//*************************************************************
//the pins of 4-digit 7-segment display attached to arduino board digital pins 2 - 13 respectively
const int a = 2;
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 8;
const int DP = 9;// dot is not used in this project
const int D1 = 10;
const int D2 = 11;
const int D3 = 12;
const int D4 = 13;

int dig1 = 0;
int dig2 = 0;
int dig3 = 2;
int dig4 = 0;

const int delayTime = 5;//delay set to 5 ms
int i = 20;        //declare the variable - 20 seconds timer. you can change it to your desired number
long timer = millis() + 1000;//if you put number less then 1000 the counting will be faster
//*************************************************************
void setup()
{
  Serial.begin(9600);//initialize serial communications at 9600 bps
//set all the pins of the LED display as output
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(DP, OUTPUT);
}

void loop()
{
  //the counter
  while (i > 0)
  {
    if (millis() > timer) {
      i--;
      if (i < 1) {
        delay(500);
        digitalWrite(D1, LOW);
        digitalWrite(D2, LOW);
        digitalWrite(D3, LOW);
        digitalWrite(D4, LOW);
        delay(500);
        digitalWrite(D1, HIGH);
        digitalWrite(D2, HIGH);
        digitalWrite(D3, HIGH);
        digitalWrite(D4, HIGH);
        delay(500);
        digitalWrite(D1, LOW);
        digitalWrite(D2, LOW);
        digitalWrite(D3, LOW);
        digitalWrite(D4, LOW);
        delay(500);
        digitalWrite(D1, HIGH);
        digitalWrite(D2, HIGH);
        digitalWrite(D3, HIGH);
        digitalWrite(D4, HIGH);

        
        delay(2000);//delay set for 2 seconds before the timer do reset
        i = 20;                //timer set to 20 seconds.change it to your desired number
        
      }
      dig1 = i / 100;
      dig2 = (i - (dig1 * 100)) / 100;
      dig3 = (i - (dig1 * 100 + dig2 * 100)) / 10;
      dig4 = i % 10;
      timer = millis() + 1000;//if you put number less then 1000 the counting will be faster

    }

    digitalWrite(D4, LOW);    //Digit 4
    pickNumber(dig4);
    delay(delayTime);
    digitalWrite(D4, HIGH);

    digitalWrite(D3, LOW);    //Digit 3
    pickNumber(dig3);
    delay(delayTime);
    digitalWrite(D3, HIGH);

    digitalWrite(D2, LOW);   //Digit 2
    pickNumber(dig2);
    delay(delayTime);
    digitalWrite(D2, HIGH);

    digitalWrite(D1, LOW);   //Digit 1
    pickNumber(dig1);
    delay(delayTime);
    digitalWrite(D1, HIGH);
  }

} 
//*************************************************************
//The function is to control the 7-segment LED display to display numbers. Here x is the number to be displayed. It is an integer from 0 to 9 

void pickNumber(int x) {
  switch (x) {
    case 1: number1(); break;
    case 2: number2(); break;
    case 3: number3(); break;
    case 4: number4(); break;
    case 5: number5(); break;
    case 6: number6(); break;
    case 7: number7(); break;
    case 8: number8(); break;
    case 9: number9(); break;
    default: number0(); break;
  }
}
//*************************************************************
void clearLEDs()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(DP, LOW);
}

void number1()             //Number 1
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void number2()             //Number 2
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void number3()            //Number 3
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void number4()             //Number 4
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void number5()             //Number 5
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void number6()             //Number 6
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void number7()            //Number 7
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void number8()            //Number 8
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void number9()             //Number 9
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void number0()             //Number 0
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}
