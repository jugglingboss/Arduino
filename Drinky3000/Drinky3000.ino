#include <Keypad.h>
#include <Servo.h>
Servo servo;

const byte ROWS = 4; 
const byte COLS = 4; 
char customKey  = 'E';
String gamemode = "";
String drank;
char enteredvalue;
int opened = 0;
int closed = 150;
int sip = 200;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {5, 4, 3, 2}; 
byte colPins[COLS] = {9, 8, 7, 6}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  Serial.println("In setup");
  servo.attach(10);
  servo.write(closed);
  randomSeed(analogRead(0));
}
  
void loop(){
  Serial.println("in loop");
  while (gamemode == ""){
    customKey  = customKeypad.getKey();
    if (customKey == 'A')
      {
        Serial.println("You Typed A");
        gamemode = "regular";     
      }
    if (customKey == 'B')
      {
        Serial.println("You Typed B");
        gamemode="tilted";
      }
    if (customKey == 'C')
      {
        Serial.println("You Typed C");
        gamemode = "risky";
      }
    if (customKey == 'D')
      {
        Serial.println("You Typed D");
        gamemode = "hardcore";
      } 
    //Serial.println(customKey);
    }
  while (enteredvalue != '*')
  {
    Serial.println("In game");
    customKey  = customKeypad.getKey();
    while (!customKey){
      customKey  = customKeypad.getKey();
      if (customKey){
        enteredvalue = customKey;
      }
    }
    if (enteredvalue == '#')
    {
      if (gamemode == "risky"){
        drank = random(0, 9);
      }
      else if (gamemode == "hardcore"){
        drank = random(0, 21);
      } 
      else if (gamemode == "tilted"){
        float tilt = drank.toInt()/2;
        Serial.println("ran");
        float ran = random(-tilt, tilt+1);
        Serial.println(ran);
        drank = ran + drank.toFloat();
      }
      Serial.println("Release the LIQUID");
      ReleaseTheLiquid(drank.toFloat());
      drank = "";
    }
    else if (enteredvalue == '*')
    {
      Serial.println("* pressed");
      gamemode = "";
      enteredvalue = 'E';
      break;
      
    }
    else if (enteredvalue == 'C')
    {
      Serial.println("cleared");
      drank = ""; 
    }
    else if ((gamemode == "regular" || gamemode == "tilted") && enteredvalue != '*' && enteredvalue != '#' && enteredvalue != 'A' && enteredvalue != 'B' && enteredvalue != 'D')
    {
      drank += enteredvalue;
      Serial.println("drank's value is");
      Serial.println(drank);
    }  
  }
}

void ReleaseTheLiquid(float drank){
  if (0 == drank){drank = .3;}
  if (25 < drank){drank = 25;}
  Serial.println(drank);
  servo.write(opened);
  Serial.println(opened);
  delay(sip*drank);
  servo.write(closed);
  Serial.println(closed);  
}
