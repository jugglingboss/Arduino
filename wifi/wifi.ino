




#include <ESP8266WiFi.h>
#include <time.h>

const char* ssid = "e46f139a4405";
const char* password = "H38A3S8B2WA732LB";

int timezone = 8;
int dst = 0;
int minute;
int hour;


void setup() {
  pinMode(2, OUTPUT);
  pinMode(0, OUTPUT);

  //ESP.wdtDisable();

  
  Serial.begin(115200);
  Serial.setDebugOutput(true);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("\nConnecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  configTime(timezone * 3600, 0, "pool.ntp.org", "time.nist.gov");
  Serial.println("\nWaiting for time");
  while (!time(nullptr)) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("");
  
}

void loop() {
  time_t now;
  struct tm *now_tm;

  
  now = time(nullptr);
  now_tm = localtime(&now);
  hour = now_tm->tm_hour;
  minute = now_tm->tm_min;

  if (hour==7)
  {
    if (minute==02)
    {
      Serial.println("forward");
      digitalWrite(2, HIGH);
      digitalWrite(0, HIGH);
      Serial.println("almost");
      delay(22000);

      Serial.println("stop");
      digitalWrite(2,LOW);
      delay(30000);

      Serial.println("reverse");
      digitalWrite(0, LOW);
      digitalWrite(2, HIGH);
      delay(13200);

      Serial.println("stop");
      digitalWrite(2, LOW);
    }
  }
  
  Serial.println(hour);
  Serial.println(minute);
  //Serial.println(ctime(&now));
  delay(1000);
}
