int sen = A0;
int val = 0;
int per = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  val = analogRead(sen);
  //per= convertToPercent(val);
  Serial.println(val);
  delay(1000);

}
