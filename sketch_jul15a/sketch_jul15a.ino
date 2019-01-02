
int hallSensorPin = 8;     
int ledPin =  13;    
int state = 0;     
unsigned long time;

void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(hallSensorPin, INPUT);    
  time = millis(); 
}

void loop(){
     
  state = digitalRead(hallSensorPin);
  Serial.println("hello"); 
  if (state == LOW) {        
    digitalWrite(ledPin, HIGH);  

    
  } 
  else {
    digitalWrite(ledPin, LOW); 
  }
}
