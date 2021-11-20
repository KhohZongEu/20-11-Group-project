#include <dht.h>
dht DHT;
#define DHT11_PIN 7

String statusTemp;
String statusHumd;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);

  statusTemp = "Normal";
  statusHumd = "Normal";
  
  if (DHT.temperature >= 35){
   statusTemp = "High temperature";
   }

  if  (DHT.humidity >= 50){
    statusHumd = "High humidity";
  }

  if (DHT.temperature <= 23){
    statusTemp = "Low temperature";
  }

  if (DHT.humidity <= 30){
    statusHumd = "Low humidity";
  }

  String p1 = ";";
  Serial.println(DHT.temperature + p1 + DHT.humidity + p1 + statusTemp + p1 + statusHumd);
  delay(1000);
}

  
//  if (digitalRead(buttonPin) == LOW) {
//    Serial.println("Change");
//    delay(150);
  
