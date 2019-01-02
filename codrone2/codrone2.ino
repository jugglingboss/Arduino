#include <CoDrone.h> 

unsigned long StartTime; 
int StartFlag; 

void setup() {
  CoDrone.begin(115200); 
  CoDrone.pair(); 
}

void loop() {
  byte bt12 = digitalRead(12); 
  byte bt18 = digitalRead(18); 
  byte bt14 = digitalRead(14); 
  
if (bt12){
   CoDrone.setThrottle(60); 
   CoDrone.goToHeight(400); 
   StartFlag = 1 ;
}

 if (StartFlag = 1){
  CoDrone.setPitch(35); 
  delay(1) ;
  CoDrone.setRoll(-30);
  CoDrone.move(1.5);
  CoDrone.land(); 
  if (bt18){
    CoDrone.emergencyStop(); 
    StartFlag = 0;
  }
 }

}
