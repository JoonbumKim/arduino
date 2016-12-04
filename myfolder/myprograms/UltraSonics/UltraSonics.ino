
long lastCm = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(3, INPUT);
pinMode(2, OUTPUT);
pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
long duration, cm;

digitalWrite(2, HIGH); // 센서에 Trig 신호 입력
delayMicroseconds(10); // 10us 정도 유지
digitalWrite(2, LOW); // 센서에 Trig 신호 off

duration = pulseIn(3, HIGH); // Echo pin: HIGH > LOW 간격을 측정
cm = microsecondsToCentimeters(duration); // 거리(cm)로 변환
//if(cm > 0 && cm <= 5){
//  lastCm = 50;
//}else if(cm > 5 && cm <= 10){
//  lastCm = 100;
//}else if(cm > 10 && cm <= 15){
//  lastCm = 150;
//}else if(cm > 15 && cm <= 20){
//  lastCm = 200;
//}else if(cm > 20 && cm <= 100){
//  lastCm = 250;
//}else{
//  // 노이즈 제거
//}

if(cm < 255){
  lastCm = cm * 10;  
}

analogWrite(9, lastCm);

Serial.print(cm);
Serial.print("cm");
Serial.println();

delay(100);
}

long microsecondsToInches(long microseconds){
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}
