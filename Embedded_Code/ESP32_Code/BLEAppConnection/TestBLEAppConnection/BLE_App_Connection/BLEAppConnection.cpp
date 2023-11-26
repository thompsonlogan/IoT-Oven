#define EEPROM_SIZE 128
#include <string>
#include "EEPROM.h"
#include "Serial.h"
#include "WiFi.h"
const char* remote_host = "www.google.com";
using namespace std;

/*#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>*/
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define CHARACTERISTIC2_UUID "2f5c9894-aad6-11ec-b909-0242ac120002"

//BLEServer* pServer = NULL;
//BLECharacteristic* pCharacteristic = NULL;
bool deviceConnected = false;
bool oldDeviceConnected = false;

const int ledPin = 22;
const int modeAddr = 0;
const int wifiAddr = 0;

int modeIdx;

bool isSetup = false;

/*class MyServerCallbacks : public BLEServerCallbacks {
   void onConnect(BLEServer* pServer) {
      deviceConnected = true;
      BLEDevice::startAdvertising();
   };

   void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
   }
};*/

int main() {
   return 0;
}

class MyCallbacks{
public:
   bool onWrite(string data){
      string value = data;

      if (value.length() > 0) {
         Serial.print("Value : ");
         Serial.println(value.c_str());
         writeString(wifiAddr, value.c_str());
         return true;
      }
      else
      {
         return false;
      }
   }

   void writeString(int add, string data) {
      int _size = data.length();
      for (int i = 0; i < _size; i++) {
         EEPROM.write(add + i, data[i]);
      }
      EEPROM.write(add + _size, '\0');
      EEPROM.commit();
   }
};

/*void bleTask() {
   // Create the BLE Device
   BLEDevice::init("Spectrum Brands Toaster");

   // Create the BLE Server
   pServer = BLEDevice::createServer();
   pServer->setCallbacks(new MyServerCallbacks());

   // Create the BLE Service
   BLEService* pService = pServer->createService(SERVICE_UUID);

   // Create a BLE Characteristic
   pCharacteristic = pService->createCharacteristic(
      CHARACTERISTIC_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_WRITE |
      BLECharacteristic::PROPERTY_NOTIFY |
      BLECharacteristic::PROPERTY_INDICATE
   );
   //BLE characteristic to store key
   BLECharacteristic* pCharacteristic2 = pService->createCharacteristic(
      CHARACTERISTIC2_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_WRITE |
      BLECharacteristic::PROPERTY_NOTIFY |
      BLECharacteristic::PROPERTY_INDICATE
   );
   pCharacteristic2->setValue("key was sent!");

   pCharacteristic->setCallbacks(new MyCallbacks());
   // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.descriptor.gatt.client_characteristic_configuration.xml
   // Create a BLE Descriptor
   pCharacteristic->addDescriptor(new BLE2902());

   // Start the service
   pService->start();

   // Start advertising
   BLEAdvertising* pAdvertising = BLEDevice::getAdvertising();
   pAdvertising->addServiceUUID(SERVICE_UUID);
   pAdvertising->setScanResponse(false);
   pAdvertising->setMinPreferred(0x0);  // set value to 0x00 to not advertise this parameter
   BLEDevice::startAdvertising();
   Serial.println("Waiting a client connection to notify...");
}*/

string getValue(string data, char separator, int index) {
   int found = 0;
   int strIndex[] = { 0, -1 };
   int maxIndex = data.length() - 1;

   for (int i = 0; i <= maxIndex && found <= index; i++) {
      if (data[i] == separator || i == maxIndex) {
         found++;
         strIndex[0] = strIndex[1] + 1;
         strIndex[1] = (i == maxIndex) ? i + 1 : i;
      }
   }
   return found > index ? data.substr(strIndex[0], strIndex[1]) : "";
}

string read_String(int add) {
   char data[100];
   int len = 0;
   unsigned char k;
   k = EEPROM.read(add);
   while (k != '\0' && len < 500) {
      k = EEPROM.read(add + len);
      data[len] = k;
      len++;
   }
   data[len] = '\0';
   return string(data);
}

bool wifiTask() {
   string receivedData;
   receivedData = read_String(wifiAddr);

   if (receivedData.length() > 0) {
      string wifiName = getValue(receivedData, ',', 0);
      string wifiPassword = getValue(receivedData, ',', 1);

      if (wifiName.length() > 0 && wifiPassword.length() > 0) {
         Serial.print("WifiName : ");
         Serial.println(wifiName);

         Serial.print("wifiPassword : ");
         Serial.println(wifiPassword);

         WiFi.begin(wifiName.c_str(), wifiPassword.c_str());
         Serial.print("Connecting to Wifi");
         while (WiFi.status() != WL_CONNECTED) {
            Serial.print(".");
            delay(5000);
            return false;
         }
         Serial.println();
         Serial.print("Connected with IP: ");
         Serial.println(WiFi.localIP());


         Serial.print("Ping Host: ");
         Serial.println(remote_host);
         
         return true;

      }
      else
      {
         return false;
      }
   }
   else
   {
      return false;
   }
}
void setup() {

   if (!EEPROM.begin(EEPROM_SIZE)) {
      delay(1000);
   }

   modeIdx = EEPROM.read(modeAddr);
   Serial.print("modeIdx : ");
   Serial.println(modeIdx);

   EEPROM.write(modeAddr, modeIdx != 0 ? 0 : 1);
   EEPROM.commit();

   if (modeIdx != 0) {
      Serial.println("BLE MODE");
      //bleTask();
      isSetup = true;
   }
   else {
      Serial.println("WIFI MODE");
      wifiTask();
      isSetup = true;
   }

}

void loop() {
}