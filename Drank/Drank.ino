#include <Servo.h>

Servo servo;

int posA = 0;
int posB = 150;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("In setup");
  servo.attach(9);
  //servo.write(0);
  delay(2000);


}

void loop() {
  Serial.println("In loop");
  // put your main code here, to run repeatedly:
  servo.write(posA);
  Serial.println(posA);
  delay(2000);
  servo.write(posB);
  Serial.println(posB);
  delay(2000);

}
