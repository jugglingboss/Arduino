#include <LiquidCrystal.h>


LiquidCrystal lcd (2,3,4,5,6,7);
int motion = 8;
int ran = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(motion,INPUT);

  randomSeed( analogRead(A0));
  
  lcd.begin(16,2);
  lcd.noCursor();
  lcd.print("Welcome to the");
  lcd.setCursor(0,1);
  lcd.print("Bebe Displayer!");
  delay(10000);
}

// the loop function runs over and over again forever
void loop() {  
  if(digitalRead(motion) == 1){

    lcd.setCursor(0,0);
    ran = random(1,78);
    
    if (1 == ran) {
      lcd.clear();
      lcd.print("I Love Bebe");
      
    }
    else if (2 == ran) {
      lcd.clear();
      lcd.print("Bebe Loves Bebe");
      
    }
    else if (3 == ran) {
      lcd.clear();
      lcd.print("I Love You");
      
    }
    else if (4 == ran) {
      lcd.clear();
      lcd.print("Michael Loves");
      lcd.setCursor(0,1);
      lcd.print("Eva");
      
    }
    else if (5 == ran) {
      lcd.clear();
      lcd.print("Big Bebe Loves");
      lcd.setCursor(0,1);
      lcd.print("Little Bebe");
      
    }
    else if (6 == ran) {
      lcd.clear();
      lcd.print("You Are My Best");
      lcd.setCursor(0,1);
      lcd.print("Friend");
      
    }
    else if (7 == ran) {
      lcd.clear();
      lcd.print("Bebe + Bebe =");
      lcd.setCursor(0,1);
      lcd.print("Bebebebe");
      
    }
    else if (8 == ran) {
      lcd.clear();
      lcd.print("8/7/16");
      
    }
    else if (9 == ran) {
      lcd.clear();
      lcd.print("Bebe + Bebe =");
      lcd.setCursor(0,1);
      lcd.print("True Love");
      
    }
    else if (10 == ran) {
      lcd.clear();
      lcd.print("Bebe + Bebe =");
      lcd.setCursor(0,1);
      lcd.print("Two Bebes");
      
    }
    else if (11 == ran) {
      lcd.clear();
      lcd.print("Eva Loves");
      lcd.setCursor(0,1);
      lcd.print("Michael");
      
    }
     else if (12 == ran) {
      lcd.clear();
      lcd.print("Michael Loves");
      lcd.setCursor(0,1);
      lcd.print("Evapizzelle");
      
   }
   else if (13 == ran) {
      lcd.clear();
      lcd.print("Eva is the ");
      lcd.setCursor(0,1);
      lcd.print("prettiest girl");
      
    }
    else if (14 == ran) {
      lcd.clear();
      lcd.print("Evapizzelle is");
      lcd.setCursor(0,1);
      lcd.print("the best");
      
    }
    else if (15 == ran) {
      lcd.clear();
      lcd.print("My Bebe is");
      lcd.setCursor(0,1);
      lcd.print("super smart");
      
    }
    else if (16 == ran) {
      lcd.clear();
      lcd.print("You are");
      lcd.setCursor(0,1);
      lcd.print("awesome");
      
    }
    else if (17 == ran) {
      lcd.clear();
      lcd.print("I love you with");
      lcd.setCursor(0,1);
      lcd.print("all my heart");
      
    }
    else if (18 == ran) {
      lcd.clear();
      lcd.print("I think about");
      lcd.setCursor(0,1);
      lcd.print("you everyday");
      
    }
    else if (19 == ran) {
      lcd.clear();
      lcd.print("<3<3<3<3<3<3<3<3");
      lcd.setCursor(0,1);
      lcd.print("<3<3<3<3<3<3<3<3");
      
    }
    else if (20 == ran) {
      lcd.clear();
      lcd.print("Hey Boobie");
      
    }
    else if (21 == ran) {
      lcd.clear();
      lcd.print("You are my");
      lcd.setCursor(0,1);
      lcd.print("polynesian");
      
    }
    else if (22 == ran) {
      lcd.clear();
      lcd.print("How are you");
      lcd.setCursor(0,1);
      lcd.print("doing today?");
      
    }
    else if (23 == ran) {
      lcd.clear();
      lcd.print("Bebe + Bebe =");
      lcd.setCursor(0,1);
      lcd.print("<3<3<3<3<3<3<3<3<3");
      
    }
     else if (24 == ran) {
      lcd.clear();
      lcd.print(":)");
      lcd.setCursor(0,1);
    }
    else if (25 == ran) {
      lcd.clear();
      lcd.print(";)");
      
    }
    else if (26 == ran) {
      lcd.clear();
      lcd.print(":P");
      
    }
    else if (27 == ran) {
      lcd.clear();
      lcd.print("Bebes love golf");
      
    }
    else if (28 == ran) {
      lcd.clear();
      lcd.print("Bebes love");
      lcd.setCursor(0,1);
      lcd.print("racket ball");
      
    }
    else if (29 == ran) {
      lcd.clear();
      lcd.print("Bebes love pico");
      
    }
    else if (30 == ran) {
      lcd.clear();
      lcd.print("Bebes love");
      lcd.setCursor(0,1);
      lcd.print("wrestling");
      
    }
    else if (31 == ran) {
      lcd.clear();
      lcd.print("Bebebebebebebebe");
      lcd.setCursor(0,1);
      lcd.print("bebebebebebebebe");
      
    }
    else if (32 == ran) {
      lcd.clear();
      lcd.print("What's up Bebe?");
      
    }
    else if (33 == ran) {
      lcd.clear();
      lcd.print("Bebes love Jesus");
      
    }
    else if (34 == ran) {
      lcd.clear();
      lcd.print("Evapizzelle");
      lcd.setCursor(0,1);
      lcd.print("loves pizzelles");
      
    }
    else if (35 == ran) {
      lcd.clear();
      lcd.print("Bebes love");
      lcd.setCursor(0,1);
      lcd.print("Disney");
      
    }
    else if (36 == ran) {
      lcd.clear();
      lcd.print("I am in love");
      lcd.setCursor(0,1);
      lcd.print("with all of you");
      
    }
    else if (37 == ran) {
      lcd.clear();
      lcd.print("I am lucky you");
      lcd.setCursor(0,1);
      lcd.print("fell for me");
      
    }
    else if (38 == ran) {
      lcd.clear();
      lcd.print("I love you so");
      lcd.setCursor(0,1);
      lcd.print("much");
      
    }
    else if (39 == ran) {
      lcd.clear();
      lcd.print("You changed my");
      lcd.setCursor(0,1);
      lcd.print("world");
      
    }
    else if (40 == ran) {
      lcd.clear();
      lcd.print("My favorite time");
      lcd.setCursor(0,1);
      lcd.print("is bebe time");
      
    }
    else if (41 == ran) {
      lcd.clear();
      lcd.print("I am excited for");
      lcd.setCursor(0,1);
      lcd.print("our future");
      
    }
    else if (42 == ran) {
      lcd.clear();
      lcd.print("You look cute in");
      lcd.setCursor(0,1);
      lcd.print("this picture");
      
    }
    else if (43 == ran) {
      lcd.clear();
      lcd.print("I know what love");
      lcd.setCursor(0,1);
      lcd.print("because of you");
      
    }
    else if (44 == ran) {
      lcd.clear();
      lcd.print("You're my happy");
      lcd.setCursor(0,1);
      lcd.print("place");
      
    }
    else if (45 == ran) {
      lcd.clear();
      lcd.print("I love watching");
      lcd.setCursor(0,1);
      lcd.print("movies with you");
      
    }
    else if (46 == ran) {
      lcd.clear();
      lcd.print("I <3 you");
      
    }
    else if (47 == ran) {
      lcd.clear();
      lcd.print("Thinking about");
      lcd.setCursor(0,1);
      lcd.print("you");
      
    }
    else if (48 == ran) {
      lcd.clear();
      lcd.print("You're very");
      lcd.setCursor(0,1);
      lcd.print("special");
      
    }
    else if (49 == ran) {
      lcd.clear();
      lcd.print("My heart is");
      lcd.setCursor(0,1);
      lcd.print("yours");
      
    }
    else if (50 == ran) {
      lcd.clear();
      lcd.print("You motivate me");
      lcd.setCursor(0,1);
      lcd.print("to be better");
      
    }
    else if (51 == ran) {
      lcd.clear();
      lcd.print("Two bebes are ");
      lcd.setCursor(0,1);
      lcd.print("better than one");
      
    }
    else if (52 == ran) {
      lcd.clear();
      lcd.print("I love your");
      lcd.setCursor(0,1);
      lcd.print("squishy tummy");
      
    }
    else if (53 == ran) {
      lcd.clear();
      lcd.print("I gonna eat ya");
      lcd.setCursor(0,1);
      lcd.print("one day");
      
    }
    else if (54 == ran) {
      lcd.clear();
      lcd.print("Remember the");
      lcd.setCursor(0,1);
      lcd.print("Kmart party?");
      
    }
    else if (55 == ran) {
      lcd.clear();
      lcd.print("I love our");
      lcd.setCursor(0,1);
      lcd.print("annual pedicure");
      
    }
    else if (56 == ran) {
      lcd.clear();
      lcd.print("I'm ready for");
      lcd.setCursor(0,1);
      lcd.print("bebe bike trip");
      
    }
    else if (57 == ran) {
      lcd.clear();
      lcd.print("Can we get ");
      lcd.setCursor(0,1);
      lcd.print("sushi tonight?");
      
    }
    else if (58 == ran) {
      lcd.clear();
      lcd.print("Loki is the");
      lcd.setCursor(0,1);
      lcd.print("chonk");
      
    }
    else if (59 == ran) {
      lcd.clear();
      lcd.print("Where is the");
      lcd.setCursor(0,1);
      lcd.print("closest Goodwill");
      
    }
    else if (60 == ran) {
      lcd.clear();
      lcd.print("Yaaaaa I love");
      lcd.setCursor(0,1);
      lcd.print("bebe everyday");
      
    }
    else if (61 == ran) {
      lcd.clear();
      lcd.print("The Force is");
      lcd.setCursor(0,1);
      lcd.print("strong with Bebe");
    }
    else if (62 == ran) {
      lcd.clear();
      lcd.print("I'm at the Pizza");
      lcd.setCursor(0,1);
      lcd.print("Hut");
    }
    else if (63 == ran) {
      lcd.clear();
      lcd.print("I'm at the Taco");
      lcd.setCursor(0,1);
      lcd.print("Bell");
    }      
    else if (64 == ran) {
      lcd.clear();
      lcd.print("Together");
      lcd.setCursor(0,1);
      lcd.print("forever");
    }
    else if (65 == ran) {
      lcd.clear();
      lcd.print("When is the next");
      lcd.setCursor(0,1);
      lcd.print("Lego game?");
    }
    else if (66 == ran) {
      lcd.clear();
      lcd.print("Time for a ");
      lcd.setCursor(0,1);
      lcd.print("Dominos pie!");
    }
    else if (67 == ran) {
      lcd.clear();
      lcd.print("Time to watch");
      lcd.setCursor(0,1);
      lcd.print("Kurzgesagt");
    }
    else if (68 == ran) {
      lcd.clear();
      lcd.print("I hope the glue");
      lcd.setCursor(0,1);
      lcd.print("holds on this");
    }
    else if (69 == ran) {
      lcd.clear();
      lcd.print("Bacon,pineapple,");
      lcd.setCursor(0,1);
      lcd.print("and pepper pie");
    }
    else if (70 == ran) {
      lcd.clear();
      lcd.print("Super bien!");
    }
    else if (71 == ran) {
      lcd.clear();
      lcd.print("Almost time to");
      lcd.setCursor(0,1);
      lcd.print("Skype bebe");
    }
    else if (72 == ran) {
      lcd.clear();
      lcd.print("Gotta keep up");
      lcd.setCursor(0,1);
      lcd.print("the Snapstreak");
    }
    else if (73 == ran) {
      lcd.clear();
      lcd.print("Bebes will");
      lcd.setCursor(0,1);
      lcd.print("travel the world");
    }
    else if (74 == ran) {
      lcd.clear();
      lcd.print("I can always add");
      lcd.setCursor(0,1);
      lcd.print("more messages");
    }
    else if (75 == ran) {
      lcd.clear();
      lcd.print("I am proud of");
      lcd.setCursor(0,1);
      lcd.print("you");
    }
    else if (76 == ran) {
      lcd.clear();
      lcd.print("I love you");
      lcd.setCursor(0,1);
      lcd.print("Thank you");
    }
    else if (77 == ran) {
      lcd.clear();
      lcd.print("Last message,");
      lcd.setCursor(0,1);
      lcd.print("lucky 77");
    }
    delay(20000);
  }
}
