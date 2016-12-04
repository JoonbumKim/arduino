#include <MsTimer2.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      12

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3);
#include <Wire.h>  // Comes with Arduino IDE
// Get the LCD I2C Library here: 
// www.4tronix.co.uk/arduino/sketches/LiquidCrystal_V1.2.1.zip
// Move any other LCD libraries to another folder or delete them
// See Library "Docs" folder for possible commands etc.
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
char inbyte = 0;
String BTData = "";
int PIN_RED_LED = 11;
int PIN_GREEN_LED = 10;
int PIN_BLUE_LED = 9;
String myString=""; //받는 문자열

static int time = 0;
void setup() {

  Serial.begin(9600);
  Serial.println("Hello!");
 
  BTSerial.begin(9600);  // set the data rate for the BT port


  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
  setColor(255, 100, 50);
  
  lcd.begin(16,2);
  
  // ------- Quick 3 blinks of backlight  -------------
  for(int i = 0; i< 3; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight(); // finish with backlight on
  showLCD("Hello !!♠I am GMOOD ^^/");

  MsTimer2::set(1000, light); // 100ms period
  MsTimer2::start();
}

void light(){
  if(time != 0){
    time = time - 1000;
  }else if(time <= 0){
    setColor(255, 100, 50);
  }
}
void loop() {

  while(BTSerial.available())  //BTSerial에 전송된 값이 있으면
  {
    char myChar = (char)BTSerial.read();  //BTSerial int 값을 char 형식으로 변환
    myString+=myChar;   //수신되는 문자를 myString에 모두 붙임 (1바이트씩 전송되는 것을 연결)
    delay(5);           //수신 문자열 끊김 방지
  }
  
  if(!myString.equals(""))  //myString 값이 있다면
  {
    Serial.println("input value : " + myString);
    
    lightNotification();
    showLCD(myString);
    myString="";
    delay(3000);
  }
}
void setColor(int red, int green, int blue){
  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(red,green,blue)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    //delay(delayval); // Delay for a period of time (in milliseconds).

  }
}

void lightNotification(){
  for(int cycle = 0; cycle < 3; cycle++){
    setColor(255, 255, 0);
    delay(100);
    
    allLightOff();
    delay(100);
  }
  setColor(255, 255, 0);
  time = 5000;
}

void allLightOff(){

  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.
  }

}

void showLCD(String str){
  clearLCD();

  lcd.setCursor(0,0);
  String title = getValue(str, '♠', 0);
  lcd.print(title.substring(0, title.length()-2));
  lcd.setCursor(0,1);
  lcd.print(getValue(str, '♠', 1));
}

String getValue(String data, char separator, int index)
{
 int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;
  for(int i=0; i<=maxIndex && found<=index; i++){
  if(data.charAt(i)==separator || i==maxIndex){
  found++;
  strIndex[0] = strIndex[1]+1;
  strIndex[1] = (i == maxIndex) ? i+1 : i;
  }
 }
  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void clearLCD(){
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
}

