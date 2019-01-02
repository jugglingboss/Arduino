int pin5=5;
int pin6=6;
int pin9=9;
int x=A0;
int y =A1;
int valuex;
int valuey;
int mapx;
int mapy;
int pin2=2;
int button;

void setup() {
  // put your setup code here, to run once:
pinMode(pin5,OUTPUT);
pinMode(pin6,OUTPUT);
pinMode(pin9,OUTPUT);
pinMode(pin2,INPUT);
pinMode(x,INPUT);
pinMode(y,INPUT);
Serial.begin(9600);
digitalWrite(pin2, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  valuex = analogRead(x);
  valuey=analogRead(y);

  delay(20);
  valuex= map(valuex,0,1023,0,255);
  valuey = map(valuey,0,1023,0,255);
  button = digitalRead(pin2)*125;
  //Serial.println(button);
  //Serial.println(valuex);
  //Serial.println(valuey);
  
  
  color(valuex,button,valuey); //red
  
}

void color(int red, int green, int blue){
  
  analogWrite(pin5,red);
  analogWrite(pin6,green);
  analogWrite(pin9,blue);
}

