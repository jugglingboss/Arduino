#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server;
int pin_led = 2;
const char* ssid = "e46f139a4405";
const char* password = "H38A3S8B2WA732LB";



void setup() 
{
  pinMode(pin_led, OUTPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.begin(115200);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.print(WiFi.localIP());
  Serial.println();
  Serial.print("MAC: ");
  Serial.println(WiFi.macAddress());

  server.on("/",[](){server.send(200,"text/plain","It works");});
  server.on("/toggle",toggleLED);
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}

void toggleLED()
{
  digitalWrite(pin_led,!digitalRead(pin_led));
  server.send(200,"text/plain","Switching the light");
}

