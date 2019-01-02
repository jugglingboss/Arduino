int pin2=2;
int mag;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin2,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  mag = digitalRead(pin2);
  Serial.println(mag);
  delay(50);

}
