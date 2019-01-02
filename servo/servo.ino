#include <Servo.h>

Servo servo;

void setup() {
  // put your setup code here, to run once:
  servo.attach(16);
  servo.write(0);
  delay(2000);

}

void loop() {
  // put your main code here, to run repeatedly:
  servo.write(100);
  delay(1000);
  servo.write(118);
  delay(2000);
  servo.write(145);
  delay(2000);
  servo.write(118);
  delay(1000);

}
