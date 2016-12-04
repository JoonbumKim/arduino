int cnt = 0;
int led = 10;

int LED_RED = 6;
int LED_YELLOW = 5;
int LED_GREEN = 4;
int LED_RED_DELAY = 5000;
int LED_YELLOW_DELAY = 1000;
int LED_GREEN_DELAY = 5000;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("Hello World");
  //delay(1000);

  
//  digitalWrite(LED_RED, HIGH);
//  digitalWrite(LED_YELLOW, LOW);
//  digitalWrite(LED_GREEN, LOW);
//  delay(LED_RED_DELAY);
//  
//  digitalWrite(LED_RED, LOW);
//  digitalWrite(LED_YELLOW, HIGH);
//  digitalWrite(LED_GREEN, LOW);
//  delay(LED_YELLOW_DELAY);
//  
//  digitalWrite(LED_RED, LOW);
//  digitalWrite(LED_YELLOW, LOW);
//  digitalWrite(LED_GREEN, HIGH);
//  delay(LED_GREEN_DELAY);
  
  if(Serial.available() > 0){
    // read incoming serial data;
    char inChar = Serial.read();
    Serial.println(inChar);
    
      if(inChar == '1'){
        digitalWrite(LED_RED, HIGH);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_GREEN, LOW);
//  delay(LED_RED_DELAY);
      }else if(inChar == '2'){
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_YELLOW, HIGH);
        digitalWrite(LED_GREEN, LOW);
//  delay(LED_YELLOW_DELAY);
      }else if(inChar == '3'){
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_GREEN, HIGH);
//  delay(LED_GREEN_DELAY);
      }
      
  }
}

