#include "WiFi.h"
#include "HTTPClient.h"
#include <iostream>
#include <SPI.h>

]
const int ledX = 6;
const int ledO = 5;
const int buz = 16;

const char * SSID = "Inteli-COLLEGE"; 
const char * PASSWORD = "QazWsx@123"; 

void httpRequest(){
  if (WiFi.status() == WL_CONNECTED) { 
      HTTPClient http;  
      const char* GETCommand = "http://10.128.64.147:5500/win";
      http.begin(GETCommand);  
      int httpCode = http.GET();
      Serial.print("Get command: ");
      Serial.println(GETCommand);
      if (httpCode > 0) { 
        String burden = http.getString();   
        if (burden[8] == '1'){
          digitalWrite(ledX,1);
          tone(buz,450,500);
          delay(1500);
          digitalWrite(ledX,0);
        }else if (burden[8] == '2'){
          digitalWrite(ledO,1);
          tone(buz,900,500);
          delay(1500);
          digitalWrite(ledO,0);
        }else if(burden[8] == '3'){
          digitalWrite(ledO,1);
          digitalWrite(ledX,1);
          tone(buz,300,500);
          delay(1500);
          digitalWrite(ledO,0);
          digitalWrite(ledX,0);
        }else {
          digitalWrite(ledO,0);
          digitalWrite(ledX,0);
          delay(1500);
        }
      } else {
        Serial.println("No response");
      }
      Serial.println("http code: " + String(httpCode));
      http.end();   //Close connection
    }
  else
  {
    Serial.println("--> connection failed");
  }
}

void setup() {
  
  pinMode(ledX, OUTPUT);
  pinMode(ledO, OUTPUT);
  pinMode(buz, OUTPUT);
  Serial.begin(115200);
  Serial.println("Conectando ao Wifi");
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Conectado");
  delay(500);
}

void loop() {
  
  httpRequest();
  delay(1500);
}