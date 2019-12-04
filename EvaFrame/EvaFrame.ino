#include <LiquidCrystal.h>


LiquidCrystal lcd (2,3,4,5,6,7);
int motion = 8;
int ran = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(motion,INPUT);

  
  lcd.begin(16,2);
  lcd.noCursor();
  lcd.print("Welcome to the");
  lcd.setCursor(0,1);
  lcd.print("Bebe Displayer!");
  delay(8000);
}

// the loop function runs over and over again forever
void loop() {  
  if(digitalRead(motion) == 1){
    lcd.clear();
    lcd.setCursor(0,0);
    ran = random(1,12);
    
    if (1 == ran) {
      lcd.print("I Love Bebe");
      delay(4000);
    }
    if (2 == ran) {
      lcd.print("Bebe Loves Bebe");
      delay(4000);
    }
    if (3 == ran) {
      lcd.print("I Love You");
      delay(4000);
    }
    if (4 == ran) {
      lcd.print("Michael Loves");
      lcd.setCursor(0,1);
      lcd.print("Eva");
      delay(4000);
    }
    if (5 == ran) {
      lcd.print("Big Bebe Loves");
      lcd.setCursor(0,1);
      lcd.print("Little Bebe");
      delay(4000);
    }
    if (6 == ran) {
      lcd.print("You Are My Best");
      lcd.setCursor(0,1);
      lcd.print("Friend");
      delay(4000);
    }
    if (7 == ran) {
      lcd.print("Bebe + Bebe =");
      lcd.setCursor(0,1);
      lcd.print("Bebebebe");
      delay(4000);
    }
    if (8 == ran) {
      lcd.print("8/7/16");
      delay(4000);
    }
    if (9 == ran) {
      lcd.print("Bebe + Bebe =");
      lcd.setCursor(0,1);
      lcd.print("True Love");
      delay(4000);
    }
    if (10 == ran) {
      lcd.print("Bebe + Bebe =");
      lcd.setCursor(0,1);
      lcd.print("Two Bebes");
      delay(4000);
    }
    if (11 == ran) {
      lcd.print("Eva Loves");
      lcd.setCursor(0,1);
      lcd.print("Michael");
      delay(4000);
    }
  }
}
