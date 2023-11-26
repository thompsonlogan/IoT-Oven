#ifndef BLE_WIFI_INIT_H
#define BLE_WIFI_INI_H
bool WiFiConnected();
std::string GetPSWD();
std::string GetSSID();
bool ConnectToWiFi();
void SetupGATTServer();
const char* GetConnectedIP();

#endif
