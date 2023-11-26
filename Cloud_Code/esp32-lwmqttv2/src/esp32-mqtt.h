/******************************************************************************
   Copyright 2018 Google
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 *****************************************************************************/
// This file contains static methods for API requests using Wifi / MQTT
#include <Client.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <string.h>

#include <MQTT.h>
#include <ArduinoJson.h>
#include <CloudIoTCore.h>
#include <CloudIoTCoreMqtt.h>
#include "ciotc_config.h" // Update this file with your configuration
#include "ESP32_AppConnection.h"

#define LED 22

// Initialize WiFi and MQTT for this board
WiFiClientSecure *netClient;
CloudIoTCoreDevice *device;
CloudIoTCoreMqtt *mqtt;
MQTTClient *mqttClient;
unsigned long iat = 0;
String jwt;
bool successful_connect;


// Initialize JSON doc for deserialization
DynamicJsonDocument doc(1024);

///////////////////////////////
// Helpers specific to this board
///////////////////////////////

// calls the device object's function written in CloudIoTCoreDeice.cpp to create and return the JWT
String getJwt() {
  iat = time(nullptr);
  Serial.println(iat);
  Serial.println("Refreshing JWT");
  jwt = device->createJWT(iat, jwt_exp_secs);
  return jwt;
}

// Connects the ESP to WiFi using the SSID and password defined in ciotc_config.h
void setupWifi() {

  bleTask();
  wifiTask();
  Serial.println("Starting wifi");

  WiFi.mode(WIFI_STA);
  // WiFi.setSleep(false); // May help with disconnect? Seems to have been removed from WiFi
  //WiFi.begin(getWifiName().c_str(), getWifiPassword().c_str());
  WiFi.begin(getWifiName().c_str(), getWifiPassword().c_str());
  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
  }

  configTime(0, 0, ntp_primary, ntp_secondary);
  Serial.println("Waiting on time sync...");
  while (time(nullptr) < 1510644967) {
    delay(10);
  }
}

void connectWifi() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
}

///////////////////////////////
// Methods used to make the connection to Google's Cloud IoT Core
///////////////////////////////

void startMQTT() {
  mqttClient->begin("mqtt.googleapis.com", 8883, *netClient);
  //mqttClient->onMessage(messageReceivedUpdateLed);
}


void connect() {
  connectWifi(); // Must first be connected to wifi to make the mqtt connection
  successful_connect = mqtt->mqttConnect(); // update the successful_connect boolean with the return from the mqttConnect method.
}

void setupCloudIoT() {
  device = new CloudIoTCoreDevice(
    project_id, location, registry_id, device_id,
    private_key_str);

  setupWifi();
  netClient = new WiFiClientSecure();
  netClient->setCACert(root_cert);
  mqttClient = new MQTTClient(512);
  mqttClient->setOptions(180, true, 1000); // keepAlive, cleanSession, timeout
  mqtt = new CloudIoTCoreMqtt(mqttClient, netClient, device);
  mqtt->setUseLts(true);
  mqtt->startMQTT();
}

//
// Methods for handling config updates/commands from the cloud. 
//


void parseConfigUpdate(String payload)
{
  bool response = false;              // Default the response as false, if the update is processed successfully it will become true.
  bool on_state = false;              // from incoming cloud function
  String command = "";
  String recipe = "";
  String seperator = " ";
  int temp = 0;
  int cooking_time = 0;
  
  StaticJsonDocument<200> payload_doc;
  deserializeJson(payload_doc, payload);
  Serial.println("Payload: " + payload);
  
  on_state = payload_doc[""];             // from incoming cloud function
  command = payload_doc["command"].as<String>();
  temp = payload_doc["temp"];
  cooking_time = payload_doc["cooking_time"];
  recipe = payload_doc["recipe"].as<String>();
  
  Serial.println(recipe);
  Serial.println(cooking_time);
  Serial.println(temp);
  Serial.println(command);
  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
  String command_to_send = "";
  command_to_send = command + seperator + temp + seperator + cooking_time + seperator + recipe;
  Serial2.println(command_to_send.c_str());

  if (on_state) // from incoming cloud function
  {
    Serial.println("device state turned : on");
    digitalWrite(LED, HIGH);
    response = true;
  }
  else if (!on_state)
  {
    Serial.println("device state turned : off");
    digitalWrite(LED, LOW);
    response = true;
  }

  StaticJsonDocument<64> response_doc;
  char buffer[64];
  response_doc["response"] = response;
  serializeJson(response_doc, buffer);
  mqtt->publishTelemetry("/toaster-oven-response", buffer);
}


void parseCommand(String payload)
{
  bool on_state = false; 
  Serial.print("Payload is: ");
  Serial.println(payload);
  Serial2.println(payload.c_str());
}

// The MQTT callback function for commands and configuration updates.
void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);

  if (topic.indexOf("config") != -1 && topic.indexOf("command") == -1)
  {
    parseConfigUpdate(payload);   // Handle an incoming configuration/state update. Can only happen at most once a second.
  }
  else if (topic.indexOf("config") == -1 && topic.indexOf("command") != -1)
  {
    parseCommand(payload);        // Handle an incoming command. Unlike configuration changes, the most recent one won't go through on startup.
  }
}
