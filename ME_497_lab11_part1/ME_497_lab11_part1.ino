#include <RedBot.h>
RedBotMotors motors;
int irf = A0;
int irb = A4;

float leftPower = 50;  // variable for setting the drive power
float rightPower =55;

int irfreading;
int irfchange;
int irbreading;
int irbchange;
int irtotal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  irfreading = analogRead(irf);
  //goal of 245
  irbreading = analogRead(irb);
  //goal of 260
  Serial.println(irfreading);
  Serial.println(irbreading);
  Serial.println("");

 irbchange=irbreading-260;
 irfchange=irfreading-245;
 //irtotal=irbchange+irfchange;
 Serial.println(irbchange);
  
  //delay(200);

  leftPower = leftPower-irbchange/40;
  rightPower = rightPower+irbchange/40;
  
  motors.leftMotor(leftPower);
  motors.rightMotor(rightPower);
  Serial.print("Left Motor: ");
  Serial.println(leftPower);
  Serial.print("Right Motor: ");
  Serial.println(rightPower);
  //motors.leftMotor(100);
  //motors.rightMotor(110);
}


