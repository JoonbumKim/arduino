/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 10, on MKR1000 on pin 6. LED_BUILTIN takes care 
  of use the correct LED pin whatever is the board used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
*/
int LED_NO = 10;
long randomNumber;
unsigned long time;
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_NO, OUTPUT);
  
}

// the loop function runs over and over again forever
void loop() {
Serial.println("LED on, off");
time = millis();
if(time % 2 == 0){
  randomNumber = 100;
}else{
  randomNumber = 1000;
}
  //prints time since program started
  Serial.println(time);
  //digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_NO, HIGH);
  delay(randomNumber);                       // wait for a second
  digitalWrite(LED_NO, LOW);    // turn the LED off by making the voltage LOW
  delay(randomNumber);                       // wait for a second
}
