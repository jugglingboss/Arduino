/***********************************************************************

 * 8 Oct 2013 M. Hord
 * Revised, 31 Oct 2014 B. Huang 
 * edited by Zach Newcome and Michael Babilya
 ***********************************************************************/

#include <RedBot.h> //Includes the functions to easliy control the robot
RedBotMotors motors;// Initializing the motors

RedBotEncoder encoder = RedBotEncoder(A2, 10);  // initializes encoder on pins A2 and 10
int countsPerRev = 192;   // 4 pairs of N-S x 48:1 gearbox = 192 ticks per wheel rev

// variables used to store the left and right encoder counts.
int lCount;  //left encoder count
int rCount; //right encoder count
long int t1; //start time
long int t2; //current time
void setup()
{

  Serial.begin(9600);  //Serial monitor rate
  Serial.println("left    right"); //setting up printing for the monitor
  Serial.println("================"); //formatting
  t1=millis(); //Gets the start time
}

void loop(void)
{

  motors.drive(255); //Motors full orce forward
  t2=(millis()-t1); //gets the current time
  if (0==(t2%15)){ //poling loop every 15 millisecs
    // store the encoder counts to a variable.
    lCount = encoder.getTicks(LEFT);    // read the left motor encoder
    rCount = encoder.getTicks(RIGHT);   // read the right motor encoder
  
    // print out to Serial Monitor the left and right encoder counts.
    Serial.print(lCount); //prints left count
    Serial.print("\t");  //tab
    Serial.print(rCount); //prints right count
    Serial.print("\t"); //tab
    Serial.println(millis()-t1); //prints the current minus the start time
    delay(1); //small delay to stop poling loop from repeating on the same time
    
  
    // if either left or right motor are more than 5 revolutions, stop
    if ((lCount >= 5*countsPerRev) || (rCount >= 5*countsPerRev) ) //stops the numbers from getting too high
    {
      motors.brake(); ///stops the motors
    }
    
  }
  
}




