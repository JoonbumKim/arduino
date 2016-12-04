int PIN_RED_LED = 10;
int PIN_GREEN_LED = 9;
int PIN_BLUE_LED = 8;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(PIN_RED_LED, OUTPUT);
  pinMode(PIN_GREEN_LED, OUTPUT);
  pinMode(PIN_BLUE_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

//  int value = analogRead(A0);
//
//  int result = map(value, 20, 130, 0, 255);
//Serial.println(result);
//  if(result >= 0 && result < 50){
//    setColor(255, 0, 0);
//  }else if(result >= 0 && result < 50){
//    setColor(0, 255, 0);
//  }else if(result >= 50 && result < 100){
//    setColor(0, 0, 255);
//  }else if(result >= 150 && result < 200){
//    setColor(255, 0, 255);
//  }else {
//    setColor(255, 255, 0);
//  }
//   delay(1000);
  //setColor(result, 0, 0);

//lightNotification();
//  setColor(HIGH, HIGH, HIGH);
//  setColor(0, 255, 0);
//  delay(1000);
//
//  setColor(0, 255, 0);
//  delay(1000);
//
//  setColor(0, 0, 255);
//  delay(1000);

//  setColor(255, 255, 0); // blue
//  delay(1000);
//
//  setColor(255, 0, 255); // green
//  delay(1000);
//
//  setColor(0, 255, 255); // red
//  delay(1000);
//
//  setColor(255, 255, 255);
//  delay(1000);
}

void setColor(int red, int green, int blue){
  analogWrite(PIN_RED_LED, 255-red);
  analogWrite(PIN_GREEN_LED, 255-green);
  analogWrite(PIN_BLUE_LED, 255-blue);
//    digitalWrite(PIN_RED_LED, red);
//    digitalWrite(PIN_GREEN_LED, green);
//    digitalWrite(PIN_BLUE_LED, blue);
}

void lightNotification(){
  
  for(int cycle = 0; cycle < 3; cycle++){
    setColor(255, 220, 0);
    delay(100);
    allLightOff();
    delay(100);
  }
  delay(1000);
}

void allLightOff(){
  setColor(0, 0, 0);
}

