#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <Servo.h>

Servo servo;
 
// Connect to the WiFi
const char* ssid = "e46f139a4405";
const char* password = "H38A3S8B2WA732LB";
const char* mqtt_server = "192.168.1.9";

int light = 16;
int relay =4;
 
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
  if (receivedChar == '4')
  // ESP8266 Huzzah outputs are "reversed"
  {
      Serial.println("on");
      servo.write(95);
      delay(100);
      servo.write(116);
      digitalWrite(relay,LOW);

     
    }
  if (receivedChar == '5')
  {

      Serial.println("off");
      servo.write(179);
      delay(100);
      servo.write(116);
      digitalWrite(relay,LOW);

  
    }
  }
  Serial.println();
}
 
 
void reconnect() {
 // Loop until we're reconnected
 while (!client.connected()) {
  digitalWrite(relay,HIGH);
 Serial.print("Attempting MQTT connection...");
 // Attempt to connect
 if (client.connect("ESP8266 Client1")) {
  Serial.println("connected");
  // ... and subscribe to topic
  client.subscribe("Lights");
 } else {
  Serial.print("failed, rc=");
  Serial.print(client.state());
  Serial.println(" try again in 5 seconds");
  // Wait 5 seconds before retrying
  delay(5000);
  }
  digitalWrite(relay,LOW);
 }
}
 
void setup()
{
 pinMode(relay,OUTPUT);
 
 servo.attach(16);
 servo.write(179);
 delay(2000);
 servo.write(116);
 delay(2000);
 servo.write(179);
 delay(2000);
 servo.write(116);

 Serial.begin(115200);
 
 client.setServer(mqtt_server, 1883);
 client.setCallback(callback);
 



 
}
 
void loop()
{
 if (!client.connected()) {
  Serial.print("Lost connection");
  reconnect();
 }
 client.loop();
}
