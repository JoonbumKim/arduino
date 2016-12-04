#include "pitches.h"
#include <MsTimer2.h>
static int distance = 1;
int speakerpin = 8;
int lastCm = 5;

int ms1[] = {
  NOTE_E4, NOTE_E4, NOTE_FS4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_E4,
  NOTE_NO, NOTE_D4, NOTE_D4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_B3
};

int ms2[] = {
  3,8,8,8,4,4,8,8,8,4, 8, 6,8,8,8,8,8,8,1
  };
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, INPUT);
  pinMode(2, OUTPUT);

  MsTimer2::set(100, getDistance); // 100ms period
  MsTimer2::start();
}

void loop() {
  // put your main code here, to run repeatedly:
   sound();
}

void sound(){
  for(int i = 0 ; i < 18 ; i++){
    int ms = 2000/ms2[i];
    //tone(speakerpin, ms1[i], ms);
    tone(speakerpin, ms1[i], ms/distance);
    int j = ms * 1.30;
    delay(j);
    // noTone(8);
  }
}

void getDistance(){
  long duration, cm;
  
  digitalWrite(2, HIGH); // 센서에 Trig 신호 입력
  delayMicroseconds(10); // 10us 정도 유지
  digitalWrite(2, LOW); // 센서에 Trig 신호 off

  duration = pulseIn(3, HIGH); // Echo pin: HIGH > LOW 간격을 측정
  cm = microsecondsToCentimeters(duration); // 거리(cm)로 변환
  Serial.println(cm);
  
  if(cm > 0 && cm <= 5){
    lastCm = 9;
  }else if(cm > 5 && cm <= 10){
    lastCm = 7;
  }else if(cm > 10 && cm <= 15){
    lastCm = 5;
  }else if(cm > 15 && cm <= 20){
    lastCm = 3;
  }else if(cm > 20 && cm <= 100){
    lastCm = 1;
  }else{
    // 노이즈 제거
  }
  distance = lastCm;
//  return lastCm;
}
long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}
