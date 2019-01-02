/*
  Showing number 0-9 on a Common Anode 7-segment LED display
  Displays the numbers 0-9 on the display, with one second inbetween.
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
  This example code is in the public domain.
 */
 
// Pin 2-8 is connected to the 7 segments of the display.

int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;

int dec = 13;

int hallSensorPin = 0;     
   
int state = 0;     
float time;
float prev;
float vel;
float mile;
float mm;

int one;
int pretwo;
int two;
int prethree;
int three;
int prefour;
int four;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);  
  pinMode(dec, OUTPUT);
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);  
  Serial.begin(9600);
  
  pinMode(hallSensorPin, INPUT);    
  Serial.begin(9600);
  prev =0;
  mile = 3600000;
  mm = .15;
}

// the loop routine runs over and over again forever:
void loop() {
 
  

  state = digitalRead(hallSensorPin);
  time = millis(); 
  while (state == LOW) {        

    if (prev != time){
      
       Serial.println(time-prev); 
       vel = ((3600000*.0011652)/(time-prev));
       Serial.println(vel);
       /*
       prefour = vel*100;
       four = (prefour)%10;
       light(4);
       number(four);

       prethree = vel*10;
       three = (prethree)%10;
       light(3);
       number(three);

       pretwo= vel;
       two = pretwo%10;
       light(2);
       digitalWrite(dec,HIGH);
       number(two);
       digitalWrite(dec,LOW);
      
       one= vel/10;
       
       if (one!=0){
        light(1);
        number(one);
       }
       */
       digitalWrite(D1, HIGH);
       digitalWrite(D2, HIGH);
       digitalWrite(D3, HIGH);
       digitalWrite(D4, HIGH); 
    }

    prev = time;
    state = digitalRead(hallSensorPin);
    
  } 
prefour = vel*100;
four = (prefour)%10;
light(4);
number(four);

prethree = vel*10;
three = (prethree)%10;
light(3);
number(three);

pretwo= vel;
two = pretwo%10;
light(2);
digitalWrite(dec,HIGH);
number(two);
digitalWrite(dec,LOW);

one= vel/10;

if (one!=0){
  light(1);
  number(one);
  }
}
void light(int numlight){
  if (numlight==1){
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH); 
  }
  if (numlight==2){
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
  }
  if (numlight==3){
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH); 
  }
  if (numlight==4){
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW); 
  }

}
 void number(int num){
  if (num==0){
      digitalWrite(pinA, HIGH);   
      digitalWrite(pinB, HIGH);   
      digitalWrite(pinC, HIGH);   
      digitalWrite(pinD, HIGH);   
      digitalWrite(pinE, HIGH);   
      digitalWrite(pinF, HIGH);   
      digitalWrite(pinG, LOW);   
      delay(4);
  }
  if (num==1){
      digitalWrite(pinA, LOW);   
      digitalWrite(pinB, HIGH);   
      digitalWrite(pinC, HIGH);   
      digitalWrite(pinD, LOW);   
      digitalWrite(pinE, LOW);   
      digitalWrite(pinF, LOW);   
      digitalWrite(pinG, LOW);   
      delay(4); 
  }
   if (num==2){
      digitalWrite(pinA, HIGH);   
      digitalWrite(pinB, HIGH);   
      digitalWrite(pinC, LOW);   
      digitalWrite(pinD, HIGH);   
      digitalWrite(pinE, HIGH);   
      digitalWrite(pinF, LOW);   
      digitalWrite(pinG, HIGH);     
      delay(4);  
  }
  if (num==3){
      digitalWrite(pinA, HIGH);   
      digitalWrite(pinB, HIGH);   
      digitalWrite(pinC, HIGH);   
      digitalWrite(pinD, HIGH);   
      digitalWrite(pinE, LOW);   
      digitalWrite(pinF, LOW);   
      digitalWrite(pinG, HIGH);     
      delay(4);  
  }
  if (num==4){
      digitalWrite(pinA, LOW);   
      digitalWrite(pinB, HIGH);   
      digitalWrite(pinC, HIGH);   
      digitalWrite(pinD, LOW);   
      digitalWrite(pinE, LOW);   
      digitalWrite(pinF, HIGH);   
      digitalWrite(pinG, HIGH);     
      delay(4);  
  }
  if (num==5){
      digitalWrite(pinA, HIGH);   
      digitalWrite(pinB, LOW);   
      digitalWrite(pinC, HIGH);   
      digitalWrite(pinD, HIGH);   
      digitalWrite(pinE, LOW);   
      digitalWrite(pinF, HIGH);   
      digitalWrite(pinG, HIGH);     
      delay(4);  
  }
  if (num==6){
      digitalWrite(pinA, HIGH);   
      digitalWrite(pinB, LOW);   
      digitalWrite(pinC, HIGH);   
      digitalWrite(pinD, HIGH);   
      digitalWrite(pinE, HIGH);   
      digitalWrite(pinF, HIGH);   
      digitalWrite(pinG, HIGH);     
      delay(4); 
  }
  if (num==7){
      digitalWrite(pinA, HIGH);   
      digitalWrite(pinB, HIGH);   
      digitalWrite(pinC, HIGH);   
      digitalWrite(pinD, LOW);   
      digitalWrite(pinE, LOW);   
      digitalWrite(pinF, LOW);   
      digitalWrite(pinG, LOW);     
      delay(4);   
  }
  if (num==8){
      digitalWrite(pinA, HIGH);   
      digitalWrite(pinB, HIGH);   
      digitalWrite(pinC, HIGH);   
      digitalWrite(pinD, HIGH);   
      digitalWrite(pinE, HIGH);   
      digitalWrite(pinF, HIGH);   
      digitalWrite(pinG, HIGH);     
      delay(4);  
  }
  if (num==9){
      digitalWrite(pinA, HIGH);   
      digitalWrite(pinB, HIGH);   
      digitalWrite(pinC, HIGH);   
      digitalWrite(pinD, HIGH);   
      digitalWrite(pinE, LOW);   
      digitalWrite(pinF, HIGH);   
      digitalWrite(pinG, HIGH);     
      delay(4);  
  }



 }

