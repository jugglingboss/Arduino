#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>

// Connect to the WiFi
const char* ssid = "e46f139a4405";
const char* password = "H38A3S8B2WA732LB";
const char* mqtt_server = "192.168.1.9";

int relay=5;
int button=4;
int current=1;
int light=1;
long int c;

WiFiClient espClient;
PubSubClient client(espClient);
 
const byte ledPin = 2; // Pin with LED on Adafruit Huzzah
 
void callback(char* topic, byte* payload, unsigned int length) {
 Serial.print("Message arrived [");
 Serial.print(topic);
 Serial.print("] ");
 for (int i=0;i<length;i++) {
  char receivedChar = (char)payload[i];
  Serial.print(receivedChar);
  if (receivedChar == '6')
  // ESP8266 Huzzah outputs are "reversed"
  {
    light=0;
    Serial.println("light on");
    digitalWrite(relay,light);
      
     
    }
  if (receivedChar == '7')
  {
    light=1;
    Serial.println("light off");
    digitalWrite(relay,light);

     
  
    }
  }
  Serial.println();
}
 
 
void reconnect() {
 // Loop until we're reconnected
 while (!client.connected()) {

 Serial.print("Attempting MQTT connection...");
 // Attempt to connect
 if (client.connect("ESP8266 Client2")) {
  Serial.println("connected");
  // ... and subscribe to topic
  client.subscribe("relay");
 } else {
  Serial.print("failed, rc=");
  Serial.print(client.state());
  Serial.println(" try again in 5 seconds");
  // Wait 5 seconds before retrying
  delay(5000);
  }

 }
}
 
void setup()
{

 
 Serial.begin(115200);
 
 client.setServer(mqtt_server, 1883);
 client.setCallback(callback);
 
  pinMode(relay,OUTPUT);
  pinMode(button, INPUT_PULLUP);

  digitalWrite(relay,light);
  Serial.println("starting relay");


 
}
 
void loop()
{
 if (!client.connected()) {
  Serial.print("Lost connection");
  reconnect();
 }
 client.loop();
 current = digitalRead(button);
  c=0;
  while (1!=current){
              //change relay
              Serial.println(c);
              if (0==c){
                Serial.println("switch pressed");
                if (light==1){
                  light=0;
                  Serial.println("light on");
                  digitalWrite(relay,light);
                  
                }
                else if (light==0){
                  light=1;
                  Serial.println("light off");
                  digitalWrite(relay,light);
                  
                }
               
              }
              current = digitalRead(button);
              delay(20);
              c=c+1;
              
              
  }
 
}
