#include "EEPROM.h"
#include <WiFi.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#define SERVICE_UUID         "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define SERVICE2_UUID        "5500ec34-a9c1-40c3-b7ab-e3cdd1b13733"
#define CHARACTERISTIC_UUID  "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define CHARACTERISTIC2_UUID "2f5c9894-aad6-11ec-b909-0242ac120002"
#define CHARACTERISTIC3_UUID "9d500f20-d2f1-4725-92d1-f6fe17c0cb87"

//call bleTask to setup the ble server which includes the characteristics that the app can write to
//to send ssid and pass which are stored in wifiName and wifiPassword
//call wifitask to update ssid an pass from characteristics
BLEServer* pServer = NULL;
BLECharacteristic* pCharacteristic = NULL;
bool deviceConnected = false;
bool oldDeviceConnected = false;
const int modeAddr = 0;
const int wifiAddr = 10;

String wifiName; //wifi ssid
String wifiPassword;
std::string publicKey = public_key_str;//change this to the public key that needs to be sent
std::string deviceID = "Ryan-Test-Device";

String getWifiName()
{
  Serial.println("Getting wifi name...");
  return wifiName;
}

String getWifiPassword()
{
  Serial.println("Getting wifi password...");
  return wifiPassword;
}

void setWifiName(String newWifiName)
{
  wifiName = newWifiName;
}

void setWifiPassword(String newWifiPassword)
{
  wifiPassword = newWifiPassword;
}

class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
      BLEDevice::startAdvertising();
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
    }
};

class MyCallbacks: public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic){
    std::string value = pCharacteristic->getValue();

    if(value.length() > 0){
      Serial.print("Value : ");
      Serial.println(value.c_str());
      writeString(wifiAddr, value.c_str());
    }
  }

  void writeString(int add, String data){
    int _size = data.length();
    for(int i=0; i<_size; i++){
      EEPROM.write(add+i, data[i]);
    }
    EEPROM.write(add+_size, '\0');
    EEPROM.commit();
  }
};

String read_String(int add){
  char data[100];
  int len = 0;
  unsigned char k;
  k = EEPROM.read(add);
  while(k != '\0' && len< 500){
    k = EEPROM.read(add+len);
    data[len] = k;
    len++;
  }
  data[len] = '\0';
  return String(data);
}

String getValue(String data, char separator, int index){
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found <=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
      found++;
      strIndex[0] = strIndex[1]+1;
      strIndex[1] = (i==maxIndex) ? i+1 : i;
    }
  }
  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}

//call this method at start to set private key for ble server to send to app
void setPublicKey(std::string newKey)
{
  publicKey = newKey;
}

void setDeviceID(std::string newDevID)
{
	deviceID = newDevID;
}

//method to get wifiName and wifiPassword from ble server
//also tries to connect to wifi
void wifiTask() {
  Serial.println("Starting wifiTask()...");
  String receivedData;
  receivedData = read_String(wifiAddr);

  if(receivedData.length() > 0){
    wifiName = getValue(receivedData, ',', 0);
    wifiPassword = getValue(receivedData, ',', 1);
  }
}

//method to set up ble server
//only needs to be called once?
void bleTask(){
  Serial.println("Starting bleTask()");
  // Create the BLE Device
  BLEDevice::init("Spectrum Brands Toaster");

  // Create the BLE Server
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a BLE Characteristic
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );
  //BLE characteristic to store key
  BLECharacteristic *pCharacteristic2 = pService->createCharacteristic(
                      CHARACTERISTIC2_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    ); 
					
  pCharacteristic2->setValue(publicKey);//change this to send actual public key

  pCharacteristic->setCallbacks(new MyCallbacks());
  // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.descriptor.gatt.client_characteristic_configuration.xml
  // Create a BLE Descriptor
  pCharacteristic->addDescriptor(new BLE2902());

  // Start the service
  pService->start();
  
  // second service
  BLEService *pService2 = pServer->createService(SERVICE2_UUID);
  
  //BLE characteristic to store device_id
  BLECharacteristic *pCharacteristic3 = pService2->createCharacteristic(
                      CHARACTERISTIC3_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    ); 
					
  pCharacteristic3->setValue(deviceID);
  
  // Start the second service
  pService2->start();

  // Start advertising
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(false);
  pAdvertising->setMinPreferred(0x0);  // set value to 0x00 to not advertise this parameter
  BLEDevice::startAdvertising();
  Serial.println("Waiting a client connection to notify...");
}
