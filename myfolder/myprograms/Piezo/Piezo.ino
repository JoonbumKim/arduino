////옥타브 C (도)
////1옥타브 32.7
////2 65.4
////3 130.8
////4 261.6
////5 523.3
////6 1046.6
//
//int speakerPin = 9;
//int numTones = 10;
//// mid C C# D D# E F F# G G# A
//int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//
//void setup() {
//  // put your setup code here, to run once:
//  for(int i = 0 ; i < numTones; i++){
//    tone(speakerPin, tones[i]);
//    delay(500);
//  }
//  noTone(speakerPin);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//
//}




//  https://www.arduino.cc/en/Tutorial/melody

int speakerPin = 8;
int length = 15; // the number of notes
char notes[] = "ccggaagffeeddc "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration, int loopNum) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      int newTone = notes[i];
      for(int j = 0 ; j < loopNum ; j++){
        newTone = newTone / 2;
      }
      playTone(newTone, duration);
    }
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(speakerPin, OUTPUT);
}

int getBrightness(){
  int value = analogRead(A0);
  int result = 0;
  if(value > 120){
    result = 4;
  }else{
    result = map(value, 0, 120, 0, 4);  
  }
  return result;
}

void loop() {
  Serial.println(analogRead(A0));
  for (int i = 0; i < length; i++) {
    
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      
//      int value = analogRead(A0);
//      int result = 0;
//      result = map(value, 30, 120, 0, 4);
//
//      playNote(notes[i], beats[i] * tempo, result);
      
      playNote(notes[i], beats[i] * tempo, 5-getBrightness());
      
    }

    // pause between notes
    delay(tempo / 2); 
  }
}





