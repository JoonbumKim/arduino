int sensorPin = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(sensorPin);
  float voltage = (5.0 * reading * 100) / 1024;

  // float temperatureC = (voltage - 0.5) * 100; // for tmp36 only
  Serial.println(voltage);
  delay(1000);
}
