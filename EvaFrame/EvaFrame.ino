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

    lcd.setCursor(0,0);
    ran = random(1,61);
    
    if (1 == ran) {
      lcd.clear();
      lcd.print("I Love Bebe");
      delay(2000);
    }
    else if (2 == ran) {
      lcd.clear();
      lcd.print("Bebe Loves Bebe");
      delay(2000);
    }
    else if (3 == ran) {
      lcd.clear();
      lcd.print("I Love You");
      delay(2000);
    }
    else if (4 == ran) {
      lcd.clear();
      lcd.print("Michael Loves");
      lcd.setCursor(0,1);
      lcd.print("Eva");
      delay(2000);
    }
    else if (5 == ran) {
      lcd.clear();
      lcd.print("Big Bebe Loves");
      lcd.setCursor(0,1);
      lcd.print("Little Bebe");
      delay(2000);
    }
    else if (6 == ran) {
      lcd.clear();
      lcd.print("You Are My Best");
      lcd.setCursor(0,1);
      lcd.print("Friend");
      delay(2000);
    }
    else if (7 == ran) {
      lcd.clear();
      lcd.print("Bebe + Bebe =");
      lcd.setCursor(0,1);
      lcd.print("Bebebebe");
      delay(2000);
    }
    else if (8 == ran) {
      lcd.clear();
      lcd.print("8/7/16");
      delay(2000);
    }
    else if (9 == ran) {
      lcd.clear();
      lcd.print("Bebe + Bebe =");
      lcd.setCursor(0,1);
      lcd.print("True Love");
      delay(2000);
    }
    else if (10 == ran) {
      lcd.clear();
      lcd.print("Bebe + Bebe =");
      lcd.setCursor(0,1);
      lcd.print("Two Bebes");
      delay(2000);
    }
    else if (11 == ran) {
      lcd.clear();
      lcd.print("Eva Loves");
      lcd.setCursor(0,1);
      lcd.print("Michael");
      delay(2000);
    }
     else if (12 == ran) {
      lcd.clear();
      lcd.print("Michael Loves");
      lcd.setCursor(0,1);
      lcd.print("Evapizzelle");
      delay(2000);
   }
   else if (13 == ran) {
      lcd.clear();
      lcd.print("Eva is the ");
      lcd.setCursor(0,1);
      lcd.print("prettiest girl");
      delay(2000);
    }
    else if (14 == ran) {
      lcd.clear();
      lcd.print("Evapizzelle is");
      lcd.setCursor(0,1);
      lcd.print("the best");
      delay(2000);
    }
    else if (15 == ran) {
      lcd.clear();
      lcd.print("My Bebe is");
      lcd.setCursor(0,1);
      lcd.print("super smart");
      delay(2000);
    }
    else if (16 == ran) {
      lcd.clear();
      lcd.print("You are");
      lcd.setCursor(0,1);
      lcd.print("awesome");
      delay(2000);
    }
    else if (17 == ran) {
      lcd.clear();
      lcd.print("I love you with");
      lcd.setCursor(0,1);
      lcd.print("all my heart");
      delay(2000);
    }
    else if (18 == ran) {
      lcd.clear();
      lcd.print("I think about");
      lcd.setCursor(0,1);
      lcd.print("you everyday");
      delay(2000);
    }
    else if (19 == ran) {
      lcd.clear();
      lcd.print("<3<3<3<3<3<3<3<3");
      lcd.setCursor(0,1);
      lcd.print("<3<3<3<3<3<3<3<3");
      delay(2000);
    }
    else if (20 == ran) {
      lcd.clear();
      lcd.print("Hey Boobie");
      delay(2000);
    }
    else if (21 == ran) {
      lcd.clear();
      lcd.print("You are my");
      lcd.setCursor(0,1);
      lcd.print("polynesian");
      delay(2000);
    }
    else if (22 == ran) {
      lcd.clear();
      lcd.print("How are you");
      lcd.setCursor(0,1);
      lcd.print("doing today?");
      delay(2000);
    }
    else if (23 == ran) {
      lcd.clear();
      lcd.print("Bebe + Bebe =");
      lcd.setCursor(0,1);
      lcd.print("<3<3<3<3<3<3<3<3<3");
      delay(2000);
    }
     else if (24 == ran) {
      lcd.clear();
      lcd.print(":)");
      lcd.setCursor(0,1);
    }
    else if (25 == ran) {
      lcd.clear();
      lcd.print(";)");
      delay(2000);
    }
    else if (26 == ran) {
      lcd.clear();
      lcd.print(":P");
      delay(2000);
    }
    else if (27 == ran) {
      lcd.clear();
      lcd.print("Bebes love golf");
      delay(2000);
    }
    else if (28 == ran) {
      lcd.clear();
      lcd.print("Bebes love");
      lcd.setCursor(0,1);
      lcd.print("racket ball");
      delay(2000);
    }
    else if (29 == ran) {
      lcd.clear();
      lcd.print("Bebes love pico");
      delay(2000);
    }
    else if (30 == ran) {
      lcd.clear();
      lcd.print("Bebes love");
      lcd.setCursor(0,1);
      lcd.print("wrestling");
      delay(2000);
    }
    else if (31 == ran) {
      lcd.clear();
      lcd.print("Bebebebebebebebe");
      lcd.setCursor(0,1);
      lcd.print("bebebebebebebebe");
      delay(2000);
    }
    else if (32 == ran) {
      lcd.clear();
      lcd.print("What's up Bebe?");
      delay(2000);
    }
    else if (33 == ran) {
      lcd.clear();
      lcd.print("Bebes love Jesus");
      delay(2000);
    }
    else if (34 == ran) {
      lcd.clear();
      lcd.print("Evapizzelle");
      lcd.setCursor(0,1);
      lcd.print("loves pizzelles");
      delay(2000);
    }
    else if (35 == ran) {
      lcd.clear();
      lcd.print("Bebes love");
      lcd.setCursor(0,1);
      lcd.print("Disney");
      delay(2000);
    }
    else if (36 == ran) {
      lcd.clear();
      lcd.print("I am in love");
      lcd.setCursor(0,1);
      lcd.print("with all of you");
      delay(2000);
    }
    else if (37 == ran) {
      lcd.clear();
      lcd.print("I am lucky you");
      lcd.setCursor(0,1);
      lcd.print("fell for me");
      delay(2000);
    }
    else if (38 == ran) {
      lcd.clear();
      lcd.print("I love you so");
      lcd.setCursor(0,1);
      lcd.print("much");
      delay(2000);
    }
    else if (39 == ran) {
      lcd.clear();
      lcd.print("You changed my");
      lcd.setCursor(0,1);
      lcd.print("world");
      delay(2000);
    }
    else if (40 == ran) {
      lcd.clear();
      lcd.print("My favorite time");
      lcd.setCursor(0,1);
      lcd.print("is bebe time");
      delay(2000);
    }
    else if (41 == ran) {
      lcd.clear();
      lcd.print("I am excited for");
      lcd.setCursor(0,1);
      lcd.print("our future");
      delay(2000);
    }
    else if (42 == ran) {
      lcd.clear();
      lcd.print("You look cute in");
      lcd.setCursor(0,1);
      lcd.print("this picture");
      delay(2000);
    }
    else if (43 == ran) {
      lcd.clear();
      lcd.print("I know what love");
      lcd.setCursor(0,1);
      lcd.print("because of you");
      delay(2000);
    }
    else if (44 == ran) {
      lcd.clear();
      lcd.print("You're my happy");
      lcd.setCursor(0,1);
      lcd.print("place");
      delay(2000);
    }
    else if (45 == ran) {
      lcd.clear();
      lcd.print("I love watching");
      lcd.setCursor(0,1);
      lcd.print("movies with you");
      delay(2000);
    }
    else if (46 == ran) {
      lcd.clear();
      lcd.print("I <3 you");
      delay(2000);
    }
    else if (47 == ran) {
      lcd.clear();
      lcd.print("Thinking about");
      lcd.setCursor(0,1);
      lcd.print("you");
      delay(2000);
    }
    else if (48 == ran) {
      lcd.clear();
      lcd.print("You're very");
      lcd.setCursor(0,1);
      lcd.print("special");
      delay(2000);
    }
    else if (49 == ran) {
      lcd.clear();
      lcd.print("My heart is");
      lcd.setCursor(0,1);
      lcd.print("yours");
      delay(2000);
    }
    else if (50 == ran) {
      lcd.clear();
      lcd.print("You motivate me");
      lcd.setCursor(0,1);
      lcd.print("to be better");
      delay(2000);
    }
    else if (51 == ran) {
      lcd.clear();
      lcd.print("Two bebes are ");
      lcd.setCursor(0,1);
      lcd.print("better than one");
      delay(2000);
    }
    else if (52 == ran) {
      lcd.clear();
      lcd.print("I love your");
      lcd.setCursor(0,1);
      lcd.print("squishy tummy");
      delay(2000);
    }
    else if (53 == ran) {
      lcd.clear();
      lcd.print("I gonna eat ya");
      lcd.setCursor(0,1);
      lcd.print("one day");
      delay(2000);
    }
    else if (54 == ran) {
      lcd.clear();
      lcd.print("Remember the");
      lcd.setCursor(0,1);
      lcd.print("Kmart party?");
      delay(2000);
    }
    else if (55 == ran) {
      lcd.clear();
      lcd.print("I love our");
      lcd.setCursor(0,1);
      lcd.print("annual pedicure");
      delay(2000);
    }
    else if (56 == ran) {
      lcd.clear();
      lcd.print("I'm ready for");
      lcd.setCursor(0,1);
      lcd.print("the bike trip");
      delay(2000);
    }
    else if (57 == ran) {
      lcd.clear();
      lcd.print("Can we get ");
      lcd.setCursor(0,1);
      lcd.print("sushi tonight?");
      delay(2000);
    }
    else if (58 == ran) {
      lcd.clear();
      lcd.print("Loki is the");
      lcd.setCursor(0,1);
      lcd.print("chonk");
      delay(2000);
    }
    else if (59 == ran) {
      lcd.clear();
      lcd.print("Where is the");
      lcd.setCursor(0,1);
      lcd.print("closest Goodwill");
      delay(2000);
    }
    else if (60 == ran) {
      lcd.clear();
      lcd.print("Yaaaaa I love");
      lcd.setCursor(0,1);
      lcd.print("bebe everyday");
      delay(2000);
    }
  }
}
