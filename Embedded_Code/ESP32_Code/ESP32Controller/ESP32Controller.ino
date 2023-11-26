#include "BLE_WIFI_INIT.h"
#include <stdio.h>
#include <string.h>
void setup() 
{
  Serial.begin(115200);
  SetupGATTServer();
  Serial.println("BLE Server is setup!"); 
}


void loop()
{
  delay(10000);
  Serial.print("SSID: ");
  Serial.println(GetSSID().c_str());
  Serial.print("Password: ");
  Serial.println(GetPSWD().c_str());
  if(!WiFiConnected() && strlen(GetPSWD().c_str()) > 0 && strlen(GetSSID().c_str()) > 0)
  {
    Serial.println("Attempting to connect to the wifi");
    ConnectToWiFi();
  }
  Serial.println(GetConnectedIP());
  
}
