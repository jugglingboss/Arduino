/*
  ESP8266 Blink by Simon Peter
  Blink the blue LED on the ESP-01 module
  This example code is in the public domain

  The blue LED on the ESP-01 module is connected to GPIO1
  (which is also the TXD pin; so we cannot use Serial.print() at the same time)

  Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/

int relay=5;
int button=4;
int current=1;
int light=1;
long int c;

void setup() {
 
  pinMode(relay,OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
  digitalWrite(relay,light);
  Serial.println("starting relay");
}


// the loop function runs over and over again forever
void loop() {

  current = digitalRead(button);
  c=0;
  while (1!=current){
              //change relay
              Serial.println(c);
              if (0==c){
                Serial.println("switch pressed");
                if (light==1){
                  light=0;
                  Serial.println("light on");
                  digitalWrite(relay,light);
                  
                }
                else if (light==0){
                  light=1;
                  Serial.println("light off");
                  digitalWrite(relay,light);
                  
                }
               
              }
              current = digitalRead(button);
              delay(20);
              c=c+1;
              
              
  }

}
