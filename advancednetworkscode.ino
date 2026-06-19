#define BLYNK_TEMPLATE_ID "TMPL2bOoFE6zk"
#define BLYNK_TEMPLATE_NAME "Irrigation"
#define BLYNK_AUTH_TOKEN "c0M8EAPRJUUMEWgsYQjHESnNK5CWPjX5"
int t=0;
#include <DHT11.h>
DHT11 dht11(5);
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
const char* ssid = "Mohamed";
const char* password = "12345678";

void setup() {
      pinMode(16, OUTPUT);


  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
   Serial.print(".");
  }
  Serial.println("\nConnected!");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
}
void loop() {
  ////////////////////////////////////////////////////
int t = 0;
    int h = 0;

    int x = 0;

    // Attempt to read the temperature and humidity values from the DHT11 sensor.
    int result = dht11.readTemperatureHumidity(t, h);
  /////////////////////////////////////////////////////////////
  
  delay(1000);
  x = analogRead(A0);
  x = 1023 - x;

  x = x / 10.23;

  if (x < 30) {
    digitalWrite(16, 0);
  }
  else {
    digitalWrite(16, 1);
  }
  
 Blynk.run();
 Blynk.virtualWrite(V2, t);
  Blynk.virtualWrite(V3, x);

 
 Blynk.virtualWrite(V1, h);


}