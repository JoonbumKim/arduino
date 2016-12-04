int JoyStick_X = 0;
int JoyStick_Y = 1;
int JoyStick_Z = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(JoyStick_X, INPUT);
  pinMode(JoyStick_Y, INPUT);
  pinMode(JoyStick_Z, INPUT);
  Serial.begin(9600);

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x, y, z;
  x = analogRead(JoyStick_X);
  y = analogRead(JoyStick_Y);
  z = analogRead(JoyStick_Z);

// x 중간값 514
if(x < 504){
  digitalWrite(3, HIGH);
}else if(x > 524){
  digitalWrite(5, HIGH);
}else{
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
}

// y 중간값 524
if(y < 514){
  digitalWrite(4, HIGH);
}else if(y > 534){
  digitalWrite(6, HIGH);
}else{
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
}

//Serial.print("x:");
//Serial.print(x);
//Serial.println();
//Serial.print("y:");
//Serial.print(y);
//Serial.println();
//
  Serial.print(x, DEC);
  Serial.print(", ");
  Serial.print(y, DEC);
  Serial.println();
  Serial.print("=====================");
  Serial.println();
  delay(100);
}
