#include "Servo.h"

Servo mysv;
int po=0;
int val;
int buttonpin0 = 7;
int buttonpin45 = 6;
int buttonpin90 = 5;

int trig = 4;
int echo = 3;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  mysv.attach(9);

//  pinMode(buttonpin0, INPUT);
//  digitalWrite(buttonpin0, HIGH);
//  
//  pinMode(buttonpin45, INPUT);
//  digitalWrite(buttonpin45, HIGH);
//  
//  pinMode(buttonpin90, INPUT);
//  digitalWrite(buttonpin90, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

for(po = 40 ; po < 150 ; po += 1){
  mysv.write(po);
  //getDistance();
  delay(10);
}
for(po = po ; po > 40 ; po -= 1){
  mysv.write(po);
  //getDistance();
  delay(10);
}
//mysv.write(0);
//delay(1000);
//mysv.write(90);
//delay(1000);


// 아날로그 A0 값(0~1023)을 읽어 0~90도 매핑
//int anal = analogRead(A0);
//mysv.write(map(anal, 0, 1023, 0, 180));

//  val = digitalRead(buttonpin0);
//  Serial.println(val);
//  if(val != 1){
//      
//      mysv.write(0);
//      delay(15);
//    }
//
//      val = digitalRead(buttonpin45);
//  Serial.println(val);
//  if(val != 1){
//      
//      mysv.write(45);
//      delay(15);
//    }
//
//      val = digitalRead(buttonpin90);
//  Serial.println(val);
//  if(val != 1){
//      
//      mysv.write(90);
//      delay(15);
//    }

}

long getDistance(){
  long duration, cm;

  digitalWrite(trig, HIGH); // 센서에 Trig 신호 입력
  delayMicroseconds(10); // 10us 정도 유지
  digitalWrite(trig, LOW); // 센서에 Trig 신호 off
  
  duration = pulseIn(echo, HIGH); // Echo pin: HIGH > LOW 간격을 측정
  cm = microsecondsToCentimeters(duration);

  Serial.println(cm);
  return cm;
}
long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}
