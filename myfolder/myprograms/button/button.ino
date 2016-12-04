int buttonpin = 2;
int LED = 13;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(buttonpin, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttoninput = digitalRead(buttonpin);
  
  if(buttoninput == 1){
    Serial.println(buttoninput);
    digitalWrite(LED, HIGH);
  }else{
    Serial.println(buttoninput);
    digitalWrite(LED, LOW);
  }
}
