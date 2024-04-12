#include <Arduino.h>

//setup library for wifi functionality
#include "WiFi.h"

// wifi parameter
const char* ssid = "XXX"; //wifi name
const char* password = "XXX"; //wifi password

//intialize wifi connection function
void initWiFi();

void setup() {

  //setup serial monitor for debuging
  Serial.begin(115200);

  initWiFi();

  //indicator for completing setup
  Serial.println("Setup done");
}

void loop() {
  
}

void initWiFi() {

  //set esp32 as station (to connect to access point)
  WiFi.mode(WIFI_STA);

  //start to connect to wifi
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi ..");

  //try to connect to access point
  while (WiFi.status() != WL_CONNECTED) {

    Serial.print('.');
    delay(250);
  }

  Serial.println(WiFi.localIP());
}