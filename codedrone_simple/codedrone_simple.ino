#include <CoDrone.h>

unsigned long StartTime;
int StartFlag;
 
void setup() {
 
  CoDrone.begin(115200);
  CoDrone.pair();

  //CoDrone.takeoff();   //take off and hover for 3 seconds
  //CoDrone.goToHeight(300);
  CoDrone.setThrottle(50);
  CoDrone.move(2);
  CoDrone.setThrottle(0);
  //CoDrone.hover(.4);
  
  
}

void loop() {
  byte bt12 = digitalRead(12);
  byte bt14 = digitalRead(14);
  byte bt18 = digitalRead(18);
    
  //button trigger timer
  if (bt12) {
    CoDrone.Buzz(1000,2);
    
    CoDrone.setPitch(50);
    CoDrone.setThrottle(0);
    CoDrone.move(1);

    CoDrone.setRoll(-50);
    CoDrone.setPitch(0);
    CoDrone.move(1);

    CoDrone.land();
    
  }
    if (bt14) {
    CoDrone.Buzz(500,2);

    
    CoDrone.setPitch(35);
    CoDrone.setRoll(-45);
    CoDrone.setThrottle(0);
    CoDrone.move(1.8);

    CoDrone.land();
    
  }

 
 
  if (bt18) {
  CoDrone.emergencyStop();
  StartFlag = 0;
  }
}
