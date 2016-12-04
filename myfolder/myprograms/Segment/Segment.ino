// common-cathod Type Segment
// http://arduino-makers.tistory.com/25
 
 int segmentLEDs[]={2,3,4,5,6,7,8};
 

 int digits[10][7]={  //[10] 10행으로 1차형 0~9까지 숫자 표현
                      // [7] 7열로 2차형 제어할 LED의 갯수 표현
 
   // 2, 3, 4, 5, 6, 7, 8 핀번호 열
     {0, 0, 0, 0, 0, 0, 1},//0
     {1, 0, 0, 1, 1, 1, 1},//1
     {0, 0, 1, 0, 0, 1, 0},//2
     {0, 0, 0, 0, 1, 1, 0},//3
     {1, 0, 0, 1, 1, 0, 0},//4
     {0, 1, 0, 0, 1, 0, 0},//5
     {0, 1, 0, 0, 0, 0, 0},//6
     {0, 0, 0, 1, 1, 1, 1},//7
     {0, 0, 0, 0, 0, 0, 0},//8
     {0, 0, 0, 1, 1, 0, 0},//9
 }; 
void setup() 
{
  Serial.begin(9600);
   for(int i = 2; i <9; i++)          //  사용할 핀번호 선언
   {
      pinMode(i,OUTPUT);           // 2~8번 핀 OUTPUT 선언
   }
} 
int R = 0;
int no = 0;
void loop()
{ 
//  for(int i= 0; i<10; i++)    //0~9까지 숫자표시를 위한 10번의 반복
//  {

R = analogRead(A0);
Serial.println(R);
no = map(R, 0, 1023, 0, 9);

    for(int j = 0; j<7; j++)   // 7개의 핀을 제어
    {
      digitalWrite(segmentLEDs[j],digits[no][j]); 
      //digitalWrite(segmentLEDs[j],digits[i][j]); 
      //숫자 0출력 cycle
      //세그먼트 핀 2번에 0,0의 값을 넣는다.
      //세그먼트 핀 3번에 0,1의 값을 넣는다.
      //세그먼트 핀 4번에 0,2의 값을 넣는다.
      //세그먼트 핀 5번에 0,3의 값을 넣는다.
      //세그먼트 핀 6번에 0,4의 값을 넣는다.
      //세그먼트 핀 7번에 0,5의 값을 넣는다.
      //세그먼트 핀 8번에 0,6의 값을 넣는다.
    } 
    delay(1000);
//  }
}


// common-anode Type Segment
//int a = 2;
//int b = 3;
//int c = 4;
//int d = 5;
//int e = 6;
//int f = 8;
//int g = 9;
//
//void setup() {
//  Serial.begin(9600);
//  // put your setup code here, to run once:
//  pinMode(a, OUTPUT);
//  pinMode(b, OUTPUT);
//  pinMode(c, OUTPUT);
//  pinMode(d, OUTPUT);
//  pinMode(e, OUTPUT);
//  pinMode(f, OUTPUT);
//  pinMode(g, OUTPUT);
//  
//}
//
//
//
//void displayDigit(int digit){
//  Serial.println("displayDigit Call!!");
//  if(digit != 1 && digit != 4){
//    Serial.println("A ----- HIGH");
//    digitalWrite(a, HIGH);
//  }
//
//  if(digit != 5 && digit != 6){
//    Serial.println("B ----- HIGH");
//    digitalWrite(b, HIGH);
//  }
//
//  if(digit != 2){
//    Serial.println("C ----- HIGH");
//    digitalWrite(c, HIGH);
//  }
//
//  if(digit !=1 && digit != 4 && digit != 7){
//    Serial.println("D ----- HIGH");
//    digitalWrite(d, HIGH);
//  }
//
//  if(digit == 2 || digit == 6 || digit == 8 || digit == 0){
//    Serial.println("E ----- HIGH");
//    digitalWrite(e, HIGH);
//  }
//
//  if(digit != 1 && digit != 2 && digit != 3 && digit != 7){
//    Serial.println("F ----- HIGH");
//    digitalWrite(f, HIGH);
//  }
//
//  if(digit != 0 && digit != 1 && digit != 7){
//    Serial.println("G ----- HIGH");
//    digitalWrite(g, HIGH);
//  }
//}
//
//void turnOff(){
//  Serial.println("-------------- Turn OFF");
//  digitalWrite(a, LOW);
//  digitalWrite(b, LOW);
//  digitalWrite(c, LOW);
//  digitalWrite(d, LOW);
//  digitalWrite(e, LOW);
//  digitalWrite(f, LOW);
//  digitalWrite(g, LOW);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  for(int i = 0 ; i < 10 ; i++){
//    Serial.print("=================== [");
//    Serial.print(i);
//    Serial.print("]");
//    Serial.println();
//    
//    displayDigit(i);
//    delay(1000);
//    turnOff();
//  }
//}

