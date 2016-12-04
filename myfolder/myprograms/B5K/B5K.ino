int ledPin = 9;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int sensorValue = analogRead(A0);
analogWrite(ledPin, sensorValue / 4);
//digitalWrite(ledPin, sensorValue / 4);
Serial.println(sensorValue);
//delay(1000);
}
