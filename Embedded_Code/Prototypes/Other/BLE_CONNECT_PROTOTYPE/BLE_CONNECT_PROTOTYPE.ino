#include "WiFi.h"
#include "BLEDevice.h"
#include <BLEUtils.h>
#include <BLEServer.h>

static BLEUUID serviceUUID("4fafc201-1fb5-459e-8fcc-c5c9c331914b");
static BLEUUID wifipssidcharUUID("beb5483e-36e1-4688-b7f5-ea07361b26a8");
static BLEUUID wifipasswordcharUUID("4c451d78-2bd8-4ab0-8580-336800fce65e");
static BLEUUID connectToPhoneUUID("f42c1df0-5308-11ec-bf63-0242ac130002");
void setup() {
  Serial.begin(57600);
  Serial.println("Prototype for initating a connection between a phone and BLE enabled device and safely passing credentials");
  
}

void setupGATT()
{
  Serial.println("Setting up GATT server to connect to phone");
  BLEDevice::init("ESP GATT SERVER");
  BLEServer *BLEServer = BLEDevice::createServer();
  BLEService *BLEService = BLEServer->createService(serviceUUID);
  BLECharacteristic *BLECharacteristic = BLEService->createCharacteristic(connectToPhoneUUID, BLECharacteristic::PROPERTY_READ);
  pCharacteristic->setValue("bbb21e10e1029292");
  pService->start();
}
/*
 * Connects to Wifi
 */
void initWiFi(std::string ssid, std::string password)
{
  WiFi.begin(ssid.c_str(), password.c_str());
  Serial.println("Attempting to connect to WiFi!");
  Serial.print("SSID is ");
  Serial.println(ssid.c_str());
  Serial.print("Password is ");
  Serial.println(password.c_str());
  int timer = 0;
  while(WiFi.status() != WL_CONNECTED)
  {
    if(timer >= 1000)
    {
      Serial.println("Failed to connect to WiFi!");
    }
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nWifi is connected!");
  Serial.println(WiFi.localIP());
}
void loop() 
{
  
  

}
