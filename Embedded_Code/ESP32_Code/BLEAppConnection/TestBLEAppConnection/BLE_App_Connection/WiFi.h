#pragma once
#include <string>
using namespace std;
class FakeWiFi
{
public:
   bool connected = false;
   string ip = "";
   void begin(string ssid, string pass)
   {

   }
   bool status()
   {
      return connected;
   }
   string localIP()
   {
      return ip;
   }

};
bool WL_CONNECTED = true;
FakeWiFi WiFi;