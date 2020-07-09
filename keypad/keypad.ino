#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 
char customKey  = 'E';
String gamemode;
String drank;


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
}
  
void loop(){
  while (customKey != 'A' || customKey != 'B' || customKey != 'C' || customKey != 'D'){
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
    }
  while (customKey != '*')
  {
    drank = "";
    customKey  = customKeypad.getKey();
    if (customKey != '*' || customKey != '#' || customKey != 'A' || customKey != 'B' || customKey != 'C' || customKey != 'D')
    {
      drank += customKey;
      customKey  = customKeypad.getKey();
      if (customKey != '*' || customKey != '#' || customKey != 'A' || customKey != 'B' || customKey != 'C' || customKey != 'D')
      {
        drank += customKey;
      }
      else if (customKey == '#')
      {
        CallServerMethod(drank.toInt());
      }
    }  
  }
  
  
  if (customKey){
    Serial.println(customKey);

    if (customKey == 'A')
      {
        Serial.println("You Typed A");
      }
  }
}
