void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int value = analogRead(A0);
  Serial.println(value);
  if(value < 800){
    digitalWrite(13, HIGH);
  }else{
    digitalWrite(13, LOW);
  }
//  analogWrite(9,value/8);
  delay(100);
}
