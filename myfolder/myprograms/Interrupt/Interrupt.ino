#include "pitches.h" //헤더파일
#include <MsTimer2.h>
int ms1[] = {
  NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, 
  NOTE_E4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4, 
  NOTE_G4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_E4, 
  NOTE_C4, NOTE_C4, NOTE_C4};
int ms2[] = {
  4,8,8,4,4,4,8,8,4,4,8,8,4,8,8,4,4,4,2 };  //3은 1.5박자, 8은 8분음표 길이
void sound(){
  for (int i = 0; i < 19; i++) {
    int ms = 1000/ms2[i];
    tone(8, ms1[i],ms);
    int j = ms * 1.30;
    delay(j);
    //noTone(8);
  }
}
void light() {
  static boolean output = HIGH;

  digitalWrite(12, output);
  digitalWrite(11, !output);
  output = !output;
}
void setup() {
  pinMode(13, OUTPUT);
  MsTimer2::set(100, light); // 100ms period
  MsTimer2::start();
}
void loop() { 
  sound();
}



