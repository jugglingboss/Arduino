#include <CoDrone.h>

unsigned long StartTime;
int StartFlag;
 
void setup() {
 
  CoDrone.begin(115200);
  CoDrone.pair();

  CoDrone.takeoff();   //take off and hover for 3 seconds
  CoDrone.setThrottle(-20);
  CoDrone.move(.5);
  CoDrone.setPitch(30);
  CoDrone.setRoll(-45);
  CoDrone.setThrottle(0);
  CoDrone.move(1);

  CoDrone.land();
 
  
  
}

void loop() {

    
 
 
  if (bt18) {
  CoDrone.emergencyStop();
  StartFlag = 0;
  }
}
