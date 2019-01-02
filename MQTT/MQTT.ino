#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>

 
// Connect to the WiFi
const char* ssid = "e46f139a4405";
const char* password = "H38A3S8B2WA732LB";
const char* mqtt_server = "192.168.1.9";
int led1 = 4;
int led2 = 5;
int air = 16;
 
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
  if (receivedChar == '0')
  // ESP8266 Huzzah outputs are "reversed"
  {
      Serial.println("forward");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      Serial.println("almost");
      delay(15000);

      Serial.println("stop");
      digitalWrite(led1,LOW);
      digitalWrite(led2, LOW);
      delay(300000);

      Serial.println("reverse");
      digitalWrite(led2, LOW);
      digitalWrite(led1, HIGH);
      delay(11400);

      Serial.println("stop");
      digitalWrite(led2, LOW);
      digitalWrite(led1, LOW);
    }
    if (receivedChar == '1')
    {
      Serial.println("forward");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      Serial.println("almost");
      delay(15000);
      
      digitalWrite(led2, LOW);
      digitalWrite(led1, LOW);
    }
    if (receivedChar == '2')
    {
      Serial.println("reverse");
      digitalWrite(led2, LOW);
      digitalWrite(led1, HIGH);
      delay(12400);

      Serial.println("stop");
      digitalWrite(led1, LOW);
    }
    if (receivedChar == '4')
    {
      Serial.println("AirConditioner");
      digitalWrite(air, LOW);
      delay(900);
      digitalWrite(air, HIGH); 
    }
  }
  Serial.println();
}
 
 
void reconnect() {
 // Loop until we're reconnected
 while (!client.connected()) {
 Serial.print("Attempting MQTT connection...");
 // Attempt to connect
 if (client.connect("ESP8266 Client")) {
  Serial.println("connected");
  // ... and subscribe to topic
  client.subscribe("Blinds");
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
 pinMode(led2, OUTPUT);
 pinMode(led1, OUTPUT);
 pinMode(air, OUTPUT);
 digitalWrite(air, HIGH);
 Serial.begin(115200);
 
 client.setServer(mqtt_server, 1883);
 client.setCallback(callback);
 
 pinMode(ledPin, OUTPUT);


 
}
 
void loop()
{
 if (!client.connected()) {
  Serial.print("Lost connection");
  reconnect();
 }
 client.loop();
}
