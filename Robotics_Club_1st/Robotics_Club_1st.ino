#include <NewPing.h>

int trig=10;
int echo=11;
//int motor1A = 3;
//int motor1B = 4;
int motor2A = 10;
int motor2B = 11;
int distance=0;
int max_dist=200;
NewPing sonar(trig,echo,max_dist);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(motor1A,OUTPUT);
  //pinMode(motor1B,OUTPUT);
  pinMode(motor2A,OUTPUT);
  pinMode(motor2B,OUTPUT);
  delay(1000);
} 

void loop() {
  // put your main code here, to run repeatedly:
//distance=sonar.ping_cm();
//
//if (20>distance and 0!=distance)
//{
//  //digitalWrite(motor1A,LOW);
//  //digitalWrite(motor1B,LOW);
//  digitalWrite(motor2A,LOW);
//  analogWrite(motor2B,100);
//  //digitalWrite(motor2B,LOW);
//}

//Serial.println(distance);
//digitalWrite(motor1A,HIGH);
//digitalWrite(motor1B,LOW);
digitalWrite(motor2A,HIGH);
digitalWrite(motor2B,LOW);
}
