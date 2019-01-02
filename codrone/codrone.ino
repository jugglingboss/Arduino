#include <CoDrone.h>

unsigned long StartTime;
int StartFlag;
 
void setup() {
 
  CoDrone.begin(115200);
  CoDrone.pair();

 // CoDrone.Set_TrimFlight(-20,0,0,0);


}

void loop() {
  byte bt12 = digitalRead(12); //button to do routine
  byte bt17 = digitalRead(17);
  byte bt18 = digitalRead(18); //emegerncy stop

    
  }
  if (bt12) {
    CoDrone.Buzz(1000,2);  
    //CoDrone.takeoff();
    CoDrone.setThrottle(100); //Thrust off the ground
    CoDrone.move(1.3);  //wait a little bit
    StartTime = millis();
    StartFlag = 1;
    
  }

 //as time increases, the CoDrone will go up-> forward-> right-> landing
 if (StartFlag == 1) {
  if (millis() - StartTime < 2450) { //as long as the time is belowe 2.45 seconds do this routine
    CoDrone.setThrottle(-14); //slowly go downwards
    delay(1);
    CoDrone.setPitch(31);  //go foward
    delay(1);
    CoDrone.setRoll(-30); // go left
    delay(1);
  //  delay(1);
    CoDrone.move();
  }
  
    
  
  else {
    CoDrone.land(); //land at the end
    StartFlag = 0;
  }
  }
 
  if (bt18) {
  CoDrone.emergencyStop();  //emegency stop if needed
  StartFlag = 0;
  }
}
