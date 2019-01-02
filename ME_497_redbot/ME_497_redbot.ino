/***********************************************************************
 *
 * 18 Feb 2015 B. Huang edited by Zach Newcome and Michael Babilya
 ***********************************************************************/
#include "notes.h"  //Defines all the notes that will be called
#include <RedBot.h>  //Includes all the fucnctions that we call to easier control items like the motors
RedBotSensor left = RedBotSensor(A3);   // initialize a left sensor object on A3
RedBotSensor center = RedBotSensor(A6); // initialize a center sensor object on A6
RedBotSensor right = RedBotSensor(A7);  // initialize a right sensor object on A7

// constants that are used in the code. LINETHRESHOLD is the level to detect 
// if the sensor is on the line or not. If the sensor value is greater than this
// the sensor is above a DARK line.
//
// SPEED sets the nominal speed

#define LINETHRESHOLD 900  //Vary this number the changed the sensor's range
#define SPEED 100  // sets the nominal speed. Set to any number from 0 - 255.

RedBotMotors motors;  //Initailizes the motors
RedBotAccel accelerometer;  //Initalizes the accelerometer

RedBotBumper lBumper = RedBotBumper(3);  // initialzes bumper object on pin 3
RedBotBumper rBumper = RedBotBumper(11); // initialzes bumper object on pin 11
int buttonPin = 12; // variable to store the button Pin 

int lBumperState;  // state variable to store the bumper value
int rBumperState;  // state variable to store the bumper value

int leftSpeed;   // variable used to store the leftMotor speed
int rightSpeed;  // variable used to store the rightMotor speed

int start =0;  //Used to make the robot only start if you hit buttonPin
const int buzzerPin = 9; //Initailizes the buzzer for use

// variables used to store the left and right encoder counts.
int lCount;  //left count
int rCount;  //right count

RedBotEncoder encoder = RedBotEncoder(A2, 10);  // initializes encoder on pins A2 and 10
int countsPerRev = 192;   // 4 pairs of N-S x 48:1 gearbox = 192 ticks per wheel rev

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP); // configures the button as an INPUT
  // INPUT_PULLUP defaults it to HIGH.
  pinMode(buzzerPin, OUTPUT);  // configures the buzzerPin as an OUTPUT

  Serial.begin(9600);  //Serial monitor rate
  

  Serial.print("left    right     ");  //formatting the serial monitor for left and right encoder
  Serial.println("(X, Y, Z) -- [X-Z, Y-Z, X-Y]");  //formatting for accelerometer
  Serial.println("==============================================");  //formatting 
}

void loop()
{
  
if(digitalRead(buttonPin) == start)  //checks to see if buttonPin has been pressed to start the rover
{
  start = 1; //Once buttonPin is pressed once you have to hit the reset button to get it to stop

  // if on the line drive left and right at the same speed (left is CCW / right is CW)
  if(center.read() > LINETHRESHOLD) //if only center sensor sees the line
  {
    leftSpeed = -SPEED; //Left and right the same speed
    rightSpeed = SPEED; //Left and right the same speed
  }
  
  // if the line is under the right sensor, adjust relative speeds to turn to the right
  else if(right.read() > LINETHRESHOLD) //if only the right sensor sees the line
  {
    leftSpeed = -(SPEED + 80);  //left motor very fast
    rightSpeed = SPEED - 80; //right motor very slow
  }

  // if the line is under the left sensor, adjust relative speeds to turn to the left
  else if(left.read() > LINETHRESHOLD)//if only the right sensor sees the line
  {
    leftSpeed = -(SPEED - 80);//left motor very slow
    rightSpeed = SPEED + 80; //right motor very fast
  }
  // if the line is under the right sensor, adjust relative speeds to turn to the right
  else if((center.read() > LINETHRESHOLD) && (right.read() > LINETHRESHOLD)) //if the center and right sensors see the line
  {
    leftSpeed = -(SPEED + 40);  //left motor a little faster
    rightSpeed = SPEED - 40; //right motor a little slower
  }

  // if the line is under the left sensor, adjust relative speeds to turn to the left
  else if((left.read() > LINETHRESHOLD) && (center.read() > LINETHRESHOLD))  //if the center and left sensors see the line
  {
    leftSpeed = -(SPEED - 40);  //left motor a little slower
    rightSpeed = SPEED + 40;  //right motor a little faster
  }
  
  // if all sensors are on black or up in the air, stop the motors.
  // otherwise, run motors given the control speeds above.
  if((left.read() > LINETHRESHOLD) && (center.read() > LINETHRESHOLD) && (right.read() > LINETHRESHOLD) )  //if the rover is up in the air
  {
    motors.stop();  //stop the motors
  }
  else //catch all
  {
    motors.leftMotor(leftSpeed);  //keeping the speed the same
    motors.rightMotor(rightSpeed); //keeping the speed the same
    
  }
  delay(0);  // add a delay to decrease sensitivity.
  lBumperState = lBumper.read();  // default INPUT state is HIGH, it is LOW when bumped
  rBumperState = rBumper.read();  // default INPUT state is HIGH, it is LOW when bumped

    if (lBumperState == LOW) // left side is bumped
  { 
    Serial.print("left bumper"); //prints to left to monitor
    scream(0); //calls scream and sends a 0 for a certain sound
  }

  if (rBumperState == LOW) // right side is bumped/
  { 
     Serial.print("right bumper"); //prints right to monitor
     scream(1);  //calls scream and sends a 1 for a different sounds
  }
 if (digitalRead(buttonPin) == LOW)  //if button pin is pressed
  {
    encoder.clearEnc(BOTH);  // Reset the counters.
    motors.drive(150);        // Start driving forward.
  }

  // store the encoder counts to a variable.
  lCount = encoder.getTicks(LEFT);    // read the left motor encoder
  rCount = encoder.getTicks(RIGHT);   // read the right motor encoder

  // print out to Serial Monitor the left and right encoder counts.
  Serial.print(lCount); //prints left counts
  Serial.print("\t"); //tab
  Serial.print(rCount); //prints right counts
  Serial.print("\t"); //tab

  accelerometer.read(); // updates the x, y, and z axis readings on the acceleromter

  Serial.print("(");  //spacing
  Serial.print(accelerometer.x);  //accelerometer x translational data
  Serial.print(", ");  // tab

  Serial.print(accelerometer.y); //accelerometer y translational data
  Serial.print(", ");  // tab

  Serial.print(accelerometer.z); //accelerometer z translational data
  Serial.print(") -- ");  // tab

  Serial.print("[");  //spacing 
  Serial.print(accelerometer.angleXZ);  //accelerometer xz rotational data
  Serial.print(", ");  //spacing
  Serial.print(accelerometer.angleYZ);  //accelerometer yz rotational data
  Serial.print(", ");  //spacing
  Serial.print(accelerometer.angleXY); //accelerometer xy rotational data
  Serial.println("]"); //spacing
}

}

void scream(int value){ //music function
  if (0==value){ //if left bumper is triggered
    playNote(noteG5, QN); //play a note
     motors.drive(-255); //put the motors in reverse
     delay(200); //keep it in reverse for a small delay
    
     motors.drive(255); //go forward as fast as it can and ram down the obstacle
     delay(1500); //keep it in forward to destory the obstacle

  }
  else{  //if right bumber is triggered
    playNote(noteB5, HN); //play a different note
     motors.drive(-255); //put the motors in reverse
     delay(200); //keep it in reverse for a small delay
    
     motors.drive(255); //go forward as fast as it can and ram down the obstacle
     delay(1500); //keep it in forward to destory the obstacle

  }
}

void playNote(int note, int duration) //note function
// This custom function takes two parameters, note and duration to make playing songs easier.
// Each of the notes have been #defined in the notes.h file. The notes are broken down by 
// octave and sharp (s) / flat (b).
{
  tone(buzzerPin, note, duration); //specifies the pin, pitch, and length of note
  delay(duration); //delays the code for the length of tthe note
}




