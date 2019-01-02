int pin3=3;
long int t0;
long int tnow;

void setup() {

  pinMode(pin3,OUTPUT);
  Serial.begin(9600);
  t0=millis();

}

void loop() {
  //Serial.println("here");
  //for(int c=255;c>1;c=c-1){
    
    //analogWrite(pin3,c);
    //delay(50);
    //Serial.println(c);
    
  //
  tnow=millis()-t0;
  if(0==tnow%1000){
    Serial.println(tnow);
  }
 
}



