
#define GREEN 19
#define RED 21
#define LED 22
#define RXD2 16
#define TXD2 17
#define LAST_ARG 6

#include <Arduino.h>
#include <ArduinoJson.h>
#include "src/esp32-mqttv2.h"

char cmdBuffer [3] = "";
char buffer[1024] = {0};
unsigned long lastMillis = 0;

void setup() 
{
  // put your setup code here, to run once:
  #define LED 22
  #define BUTTON 21
  Serial.begin(115200);
  pinMode(BUTTON, INPUT); // push button
  pinMode(LED, OUTPUT); // LED used in visualizing the reception of basic config updates and commands.
  Serial.begin(115200);
  Serial2.begin(57600, SERIAL_8N1, RXD2, TXD2);
  pinMode(GREEN, OUTPUT); // green pin of RGB led. Used to show online status.
  pinMode(RED, OUTPUT); // red pin of the RBG led. Used to show offline status.
  pinMode(LED, INPUT); // push button
  pinMode(22, OUTPUT); // LED used in visualizing the reception of basic config updates and commands.
  pinMode(2, OUTPUT);
  
  wifiTask();
  bleTask();
  setupCloudIoT();
}


void loop() {
  mqtt->loop();
  if (!mqttClient->connected()) 
  {
    wifiTask();
    connect();
  }
  
  /*
   * The following is an example of having some trigger (i.e. button push)
   * cause a JSON doc to be serialized with some information and published
   * to a subscription in Iot Core.
   */
  // button press
  if (digitalRead(BUTTON) == HIGH)
  {
    StaticJsonDocument<16> doc1;
    
    Serial.println("Sending button press to state topic");

    doc1["oven-state"] = "button press";
    serializeJson(doc1, buffer);
    mqtt->publishState(buffer); // ex. Sends a state update to the deafult device state subscription with the contents 

    delay(1000);                                                  
  }

  checkToasterCommand();
}
/*
 * Takes in paramters and places them within a JSON that is published to IOT core.
 */
void jsonToIOT(int timerRemaining, int ovenCurrentTemp, int ovenSetToTemp, String ovenCookingMode, bool isOvenOn, bool isOvenStarted)
{
    StaticJsonDocument<500> root;

    root["currentCookingMode"] = ovenCookingMode;
    root["temperatureAmbientCelsius"] = ovenSetToTemp;
    root["temperatureSetpointCelsius"] = ovenCurrentTemp;
    root["timerRemainingSec"] = timerRemaining;
    root["on"] = isOvenOn;
    root["start"] = isOvenStarted;
    
    Serial.println("Sending JSON to IOT core");
    /*
    Serial.println("currentCookingMode: " + ovenCookingMode);
    Serial.println("temperatureAmbientCelsius: " + String(ovenSetToTemp));
    Serial.println("temperatureSetpointCelsius: " + String(ovenCurrentTemp));
    Serial.println("timerRemainingSec: " + String(timerRemaining));
    Serial.println("start: " + String(isOvenStarted));
    Serial.println("on: " + String(isOvenOn));
    */
    serializeJson(root, buffer);
    mqtt->publishState(buffer); // publishes the serialized Json doc2 to the topic named "toaster-oven-topic"  
    Serial.println("MSG Sent!");   
    Serial.println(); 
}
/*
 * Checks Serial2 for characters. If valid command start is shown, start parsing command. 
 * Currently reads in oventemp, elapsed time, oven status and a checksum.
 */
void checkToasterCommand()
{
  if(Serial2.available())
  {
    //Read in last char to buffer
    cmdBuffer[2] = (char)Serial2.read();
    if(cmdBuffer[0] == 'C' && cmdBuffer[1] == ':' && cmdBuffer[2] == ':')
    {
        int cmdIndex = 0;
        bool cmdFound = false;
        bool invalidCmd = false;
        
        String currentCookingMode = "";
        int timerRemainingSec = 0;
        int temperatureAmbientCelsius = 0;
        int temperatureSetpointCelsius = 0;
        bool isOvenOn = false;
        bool isOvenStarted = false;
        int checksum = -1;

 
        while(!invalidCmd && !cmdFound)
        {
          int length = Serial2.readBytesUntil(':', buffer, sizeof(buffer) - 1);
          
          
          if(cmdIndex == LAST_ARG)
          {
            length = Serial2.readBytesUntil(':', buffer, sizeof(buffer) - 1);
          }
          
          buffer[length] = '\0';            
          cmdIndex++;
          
          if(cmdIndex == 1)
            timerRemainingSec = ((String)buffer).toInt();
          else if(cmdIndex == 2)
            temperatureAmbientCelsius = ((String)buffer).toInt();
          else if(cmdIndex == 3)
            currentCookingMode = (String)buffer;
          else if(cmdIndex == 4)
            temperatureSetpointCelsius = ((String)buffer).toInt();
          else if(cmdIndex == 5)
            isOvenOn = ((String)buffer[0]).toInt();
          else if(cmdIndex == 6)
            isOvenStarted = ((String)buffer[0]).toInt();
          else if(cmdIndex == LAST_ARG + 1)
          {
            checksum = ((String)buffer).toInt();
            int ovenInfoSum = 0;
            for(int j = 0; j < currentCookingMode.length(); j++)
            {
              ovenInfoSum += currentCookingMode.charAt(j);
            }
            ovenInfoSum += temperatureAmbientCelsius + timerRemainingSec + temperatureSetpointCelsius + (int)isOvenStarted + (int)isOvenOn;
            
            Serial.println("Oven Checksum should be: " + (String)ovenInfoSum);
            if(ovenInfoSum == checksum)
              cmdFound = true;
            else
              invalidCmd = true;

            if(invalidCmd)
            {
                Serial.println("currentCookingMode: " + currentCookingMode);
                Serial.println("temperatureAmbientCelsius: " + String(temperatureAmbientCelsius));
                Serial.println("temperatureSetpointCelsius: " + String(temperatureSetpointCelsius));
                Serial.println("timerRemainingSec: " + String(timerRemainingSec));
                Serial.println("start: " + String(isOvenStarted));
                Serial.println("on: " + String(isOvenOn));
                Serial.println("checksum: " + String(checksum));
                Serial.println("--------------------------------------------");
            }
            else if(cmdFound)
            {
              jsonToIOT(timerRemainingSec, temperatureAmbientCelsius, temperatureSetpointCelsius, currentCookingMode, isOvenOn, isOvenStarted);
            }
          }
        }
        cmdBuffer[0] = ' ';
        cmdBuffer[1] = ' ';
        cmdBuffer[2] = ' ';
    }
    else
    {
      //Else shift buffer
      cmdBuffer[0] = cmdBuffer[1];
      cmdBuffer[1] = cmdBuffer[2];
      cmdBuffer[2] = ' ';
    }
  }
}
