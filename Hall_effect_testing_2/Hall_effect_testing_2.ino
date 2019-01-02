long int t;
int led1 = 4;
int led2 = 5;
int air = 3;
int sensor = 12;
int x;
void setup() {
  // put your setup code here, to run once:
  pinMode(led2, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(air, OUTPUT);
  
  Serial.begin(115200);
  

  
  pinMode(sensor, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("reverse");
  digitalWrite(led2, LOW);
  digitalWrite(led1, HIGH);
  t = millis();
  x=1;
  while((millis()-t<13000) ){
    //Serial.println(digitalRead(sensor));
    if(0==digitalRead(sensor)){
      delay(50);
      if(0==digitalRead(sensor)){
        x=0;
        Serial.println("in if loop");
      }
    }
  }
 
  Serial.println("stop");
  digitalWrite(led1, LOW);

  delay(500);

}
