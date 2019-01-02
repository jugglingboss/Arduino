int sensor =0;
void setup() {
  // put your setup code here, to run once:
    pinMode(sensor, INPUT);
    Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(sensor));
  delay(50);

}
