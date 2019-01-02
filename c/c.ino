#include <CoDrone.h>

unsigned long StartTime;
int StartFlag;
 
void setup() {
  CoDrone.begin(115200);
  CoDrone.pair();

  CoDrone.takeoff();   //take off and hover for 3 seconds
  CoDrone.move(3);
}

void loop() {
  byte bt1 = digitalRead(11);
  byte bt4 = digitalRead(14);
  byte bt8 = digitalRead(18);
    
  //button trigger timer
  if (bt1) {
  StartTime = millis();
  StartFlag = 1;
  }

 //as time increases, the CoDrone will go up-> forward-> right-> landing
 if (StartFlag == 1) {
  if (millis() - StartTime < 200) {
    CoDrone.setPitch(70);
    CoDrone.setThrottle(0);
    CoDrone.move();
  }
  else if (millis() - StartTime < 400) {
    CoDrone.setRoll(40);
    CoDrone.setPitch(0);
    CoDrone.move();
  }

  
  else {
    CoDrone.land();
    StartFlag = 0;
  }
  }
 
  if (bt8) {
  CoDrone.emergencyStop();
  StartFlag = 0;
  }
}
