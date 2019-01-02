void setup() {
  // put your setup code here, to run once:
#define BLUE 3
#define GREEN 5
#define RED 6

pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
digitalWrite(RED, HIGH);
digitalWrite(GREEN, LOW);
digitalWrite(BLUE, LOW);

int redValue;
int greenValue;
int blueValue;
#define delayTime 20

redValue = 255; // choose a value between 1 and 255 to change the color.
greenValue = 0;
blueValue = 0;

for(int i = 0; i < 255; i += 1) // fades out red bring green full when i=255
{
redValue -= 1;
greenValue += 1;
blueValue += 1;
// The following was reversed, counting in the wrong directions
// analogWrite(RED, 255 - redValue);
// analogWrite(GREEN, 255 - greenValue);
analogWrite(RED, redValue);
analogWrite(GREEN, greenValue);
analogWrite(BLUE, blueValue);
delay(delayTime);
}
analogWrite(RED, 255);
analogWrite(GREEN, 0);
analogWrite(BLUE, 255);
}

void loop() {
  // put your main code here, to run repeatedly:

}
