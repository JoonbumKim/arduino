//#include "LedControl.h" //  need the library
//LedControl lc=LedControl(12,11,10,2); // 
//
//// pin 12 is connected to the MAX7219 pin 1
//// pin 11 is connected to the CLK pin 13
//// pin 10 is connected to LOAD pin 12
//// 1 as we are only using 1 MAX7219
//
//void setup()
//{
//  // the zero refers to the MAX7219 number, it is zero for 1 chip
//  lc.shutdown(0,false);// turn off power saving, enables display
//  lc.setIntensity(0,8);// sets brightness (0~15 possible values)
//  lc.clearDisplay(0);// clear screen
//  
//}
//void loop()
//{
////col = 0;
////row = 0;
////  lc.setLed(0,col,row,true);
////  delay(500);
////  lc.setLed(0,col,row,false);
//  for (int row=0; row<8; row++)
//  {
//    for (int col=0; col<8; col++)
//    {
//      lc.setLed(0,col,row,true); // turns on LED at col, row
//      delay(25);
//    }
//  }
//
//  for (int row=0; row<8; row++)
//  {
//    for (int col=0; col<8; col++)
//    {
//      lc.setLed(0,col,row,false); // turns off LED at col, row
//      delay(25);
//    }
//  }
//}


//#include "LedControl.h" //  need the library
//LedControl lc=LedControl(12,11,10,2); // 
//
//// pin 12 is connected to the MAX7219 pin 1
//// pin 11 is connected to the CLK pin 13
//// pin 10 is connected to LOAD pin 12
//// 1 as we are only using 1 MAX7219
//
//void setup()
//{
//  lc.shutdown(0,false);// turn off power saving, enables display
//  lc.setIntensity(0,8);// sets brightness (0~15 possible values)
//  lc.clearDisplay(0);// clear screen
//
//  lc.shutdown(1,false);// turn off power saving, enables display
//  lc.setIntensity(1,8);// sets brightness (0~15 possible values)
//  lc.clearDisplay(1);// clear screen
//}
//
//void loop()
//{
//  for (int row=0; row<8; row++)
//  {
//    for (int col=0; col<8; col++)
//    {
//      lc.setLed(0,col,row,true); // turns on LED at col, row
//      lc.setLed(1,col,row,false); // turns on LED at col, row
//      delay(25);
//    }
//  }
//
//  for (int row=0; row<8; row++)
//  {
//    for (int col=0; col<8; col++)
//    {
//      lc.setLed(0,col,row,false); // turns off LED at col, row
//      lc.setLed(1,col,row,true); // turns on LED at col, row      
//      delay(25);
//    }
//  }
//}

//int ANIMDELAY = 100;  // animation delay, deafault value is 100
//int INTENSITYMIN = 0; // minimum brightness, valid range [0,15]
//int INTENSITYMAX = 8; // maximum brightness, valid range [0,15]
////// pin 12 is connected to the MAX7219 pin 1
////// pin 11 is connected to the CLK pin 13
////// pin 10 is connected to LOAD pin 12
////// 1 as we are only using 1 MAX7219
//int DIN_PIN = 12;      // data in pin
//int CS_PIN = 10;       // load (CS) pin
//int CLK_PIN = 11;      // clock pin
//
//// MAX7219 registers
//byte MAXREG_DECODEMODE = 0x09;
//byte MAXREG_INTENSITY  = 0x0a;
//byte MAXREG_SCANLIMIT  = 0x0b;
//byte MAXREG_SHUTDOWN   = 0x0c;
//byte MAXREG_DISPTEST   = 0x0f;
//
//const unsigned char heart[] =
//{
//  B01100110,
//  B11111111,
//  B11111111,
//  B11111111,
//  B01111110,
//  B00111100,
//  B00011000,
//  B00000000
//};
//
//
//
//void setup ()
//{
//  pinMode(DIN_PIN, OUTPUT);
//  pinMode(CLK_PIN, OUTPUT);
//  pinMode(CS_PIN, OUTPUT);
//
//  // initialization of the MAX7219
//  setRegistry(MAXREG_SCANLIMIT, 0x07);
//  setRegistry(MAXREG_DECODEMODE, 0x00);  // using an led matrix (not digits)
//  setRegistry(MAXREG_SHUTDOWN, 0x01);    // not in shutdown mode
//  setRegistry(MAXREG_DISPTEST, 0x00);    // no display test
//  setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMIN);
//
//  // draw hearth
//  setRegistry(1, heart[0]);
//  setRegistry(2, heart[1]);
//  setRegistry(3, heart[2]);
//  setRegistry(4, heart[3]);
//  setRegistry(5, heart[4]);
//  setRegistry(6, heart[5]);
//  setRegistry(7, heart[6]);
//  setRegistry(8, heart[7]);
//}
//
//
//void loop ()
//{
//  // second beat
//  setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMAX);
//  delay(ANIMDELAY);
//  
//  // switch off
//  setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMIN);
//  delay(ANIMDELAY);
//  
//  // second beat
//  setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMAX);
//  delay(ANIMDELAY);
//  
//  // switch off
//  setRegistry(MAXREG_INTENSITY, 0x0f & INTENSITYMIN);
//  delay(ANIMDELAY*6);
//}
//
//
//void setRegistry(byte reg, byte value)
//{
//  digitalWrite(CS_PIN, LOW);
//
//  putByte(reg);   // specify register
//  putByte(value); // send data
//
//  digitalWrite(CS_PIN, LOW);
//  digitalWrite(CS_PIN, HIGH);
//}
//
//void putByte(byte data)
//{
//  byte i = 8;
//  byte mask;
//  while (i > 0)
//  {
//    mask = 0x01 << (i - 1);        // get bitmask
//    digitalWrite( CLK_PIN, LOW);   // tick
//    if (data & mask)               // choose bit
//      digitalWrite(DIN_PIN, HIGH); // send 1
//    else
//      digitalWrite(DIN_PIN, LOW);  // send 0
//    digitalWrite(CLK_PIN, HIGH);   // tock
//    --i;                           // move to lesser bit
//  }
//}


#include "LedControl.h"
//#include "SoftwareSerial.h"

// 12 DATA IN
// 11 CLK
// 10 CS
LedControl lc = LedControl(12,11,10,1); 
//SoftwareSerial BTSerial(1, 0);
void setup(){
  Serial.begin(9600);
  //BTSerial.begin(9600);
  //pinMode(13, OUTPUT);


  pinMode(3, INPUT);
  pinMode(2, OUTPUT);

  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}
int flag = 1;
void loop(){

////while(BTSerial.available()){
//  char myChar = (char)BTSerial.read();
//  BTSerial.println(myChar);
////}
//int bt = BTSerial.read();
//Serial.println(bt);
    byte data;
    data = Serial.read();
    
    if(data=='a'){
      Serial.println(data);
      digitalWrite(13, HIGH);   // set the LED on
    }
    if(data=='b'){
      Serial.println(data);
      digitalWrite(13, LOW);    // set the LED off
    }

  long duration, cm;

  digitalWrite(2, HIGH); // 센서에 Trig 신호 입력
  delayMicroseconds(10); // 10us 정도 유지
  digitalWrite(2, LOW); // 센서에 Trig 신호 off
  
  duration = pulseIn(3, HIGH); // Echo pin: HIGH > LOW 간격을 측정
  cm = microsecondsToCentimeters(duration); // 거리(cm)로 변환

  lc.clearDisplay(0);
  if(cm < 5){
    flag = 0;
    smileFace();
  }else if(cm >= 5 && cm < 30){
    flag = 1;
    sadFace();
  }else{
    if(flag == 1){
      sadFace();
    }else{
      smileFace();
    }
  }
  delay(100);
  
//  myName();
//  delay(500);
//  lc.clearDisplay(0);
//  delay(500);
//
//  heart();
//  delay(500);
//  lc.clearDisplay(0);
//  delay(500);
//
//  herName();
//  delay(500);
//  lc.clearDisplay(0);
//  delay(500);
//
//  heart();
//  delay(500);
//  lc.clearDisplay(0);
//  delay(500);
}

long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}

void myName(){
  lc.setRow(0, 0, B11110101);
  lc.setRow(0, 1, B01011111);
  lc.setRow(0, 2, B10110101);
  lc.setRow(0, 3, B00011101);
  lc.setRow(0, 4, B11100000);
  lc.setRow(0, 5, B01001111);
  lc.setRow(0, 6, B10001001);
  lc.setRow(0, 7, B11101111);
}

void herName(){
  lc.setRow(0, 0, B01001001);
  lc.setRow(0, 1, B10110111);
  lc.setRow(0, 2, B10110101);
  lc.setRow(0, 3, B01010111);
  lc.setRow(0, 4, B00001001);
  lc.setRow(0, 5, B11100000);
  lc.setRow(0, 6, B01001000);
  lc.setRow(0, 7, B10101111);
}

void heart(){
  lc.setRow(0, 0, B01100110);
  lc.setRow(0, 1, B11111111);
  lc.setRow(0, 2, B11111111);
  lc.setRow(0, 3, B11111111);
  lc.setRow(0, 4, B01111110);
  lc.setRow(0, 5, B00111100);
  lc.setRow(0, 6, B00011000);
  lc.setRow(0, 7, B00000000);
}

void sadFace(){
  lc.setRow(0, 0, B10000001);
  lc.setRow(0, 1, B01000010);
  lc.setRow(0, 2, B00100100);
  lc.setRow(0, 3, B01000010);
  lc.setRow(0, 4, B00000000);
  lc.setRow(0, 5, B00000000);
  lc.setRow(0, 6, B01111110);
  lc.setRow(0, 7, B00000000);
}


void smileFace(){
  lc.setRow(0, 0, B00000000);
  lc.setRow(0, 1, B01000010);
  lc.setRow(0, 2, B10100101);
  lc.setRow(0, 3, B00000000);
  lc.setRow(0, 4, B01000010);
  lc.setRow(0, 5, B00111100);
  lc.setRow(0, 6, B00000000);
  lc.setRow(0, 7, B00000000);
}
