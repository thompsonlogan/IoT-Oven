#include <WiFi.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include "String.h"

#define WIFI_SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define WIFI_SSID_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define WIFI_PSWD_UUID "4c451d78-2bd8-4ab0-8580-336800fce65e"

static BLEServer *BLEWiFiServer = NULL;
static BLECharacteristic *SSIDCharacteristic = NULL;
static BLECharacteristic *PSWDCharacteristic = NULL;
static bool DeviceConnected = false;


bool WiFiConnected()
{
  if(WiFi.status() == WL_CONNECTED)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//Inherits all methods/variables from BLEServerCallBacks
/**
 * Responsible for handling how the server reacts when it connects or disconnects
 */
class MyServerCallbacks: public BLEServerCallbacks 
{
    void onConnect(BLEServer* pServer) {
      DeviceConnected = true;
    };

    void onDisconnect(BLEServer* pServer) {
      DeviceConnected = false;
    }
};
/**
 * Responsible for setting up GATT server. First you establish a server to broadcast the information.
 * The a servuce and the characteristics for that service are created. Advertising then has the Serive UUID
 * attached to it and is started to begin broadcasting the service.
 */
void SetupGATTServer()
{
    BLEDevice::init("Spectrum Brands Toaster oven");
    BLEWiFiServer = BLEDevice::createServer();
    BLEService *BLEWiFiService = BLEWiFiServer->createService(WIFI_SERVICE_UUID);
    SSIDCharacteristic = BLEWiFiService->createCharacteristic(
                                         WIFI_SSID_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );
    PSWDCharacteristic = BLEWiFiService->createCharacteristic(
                                         WIFI_PSWD_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );
    BLEWiFiService->start();
    BLEAdvertising *WiFiAdvertising = BLEDevice::getAdvertising();
    WiFiAdvertising->addServiceUUID(WIFI_SERVICE_UUID);
    BLEDevice::startAdvertising();
}   
std::string GetSSID()
{
  return SSIDCharacteristic->getValue();
}
std::string GetPSWD()
{
  return PSWDCharacteristic->getValue();
}
bool ConnectToWiFi()
{
  WiFi.begin(SSIDCharacteristic->getValue().c_str(), PSWDCharacteristic->getValue().c_str());
  int timer = 0;
  while(WiFi.status() != WL_CONNECTED)
  {
    timer++;
    if(timer == 2000)
      return false;
  }
  return true;
}
const char* GetConnectedIP()
{
  if(WiFi.status() != WL_CONNECTED)
    return "No connection.";
  else
  {
    IPAddress ip = WiFi.localIP();
    String ipString = String(ip[0]);
    for (byte octet = 1; octet < 4; ++octet) 
    {
      ipString += '.' + String(ip[octet]);
    }
    return ("Connected to " + ipString).c_str();
  }
 
    
}
