#include "pch.h"
#include "CppUnitTest.h"
#include <string>
using namespace std;
#include "../BLE_App_Connection/BLEAppConnection.cpp"
#include "../BLE_App_Connection/EEPROM.h"
#include "../BLE_App_Connection/WiFi.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestBLEAppConnection
{
	TEST_CLASS(TestBLEAppConnection)
	{
	public:
		TEST_METHOD(TestGetValueEqualSSID)
		{
			string expected = "LeCloud";
			string result = getValue("LeCloud,Cloud_Duck", ',', 0);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestGetValueEqualPass)
		{
			string expected = "Cloud_Duck";
			string result = getValue("LeCloud,Cloud_Duck", ',', 1);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestGetValueNotEqual)
		{
			string expected = "LeCloud";
			string falseResult = getValue("LeCloud,Cloud_Duck", ',', 1);
			Assert::AreNotEqual(expected, falseResult);
		}
		TEST_METHOD(TestGetValueNotFound)
		{
			string expected = "";
			string result = getValue("LeCloud,Cloud_Duck", ',', 3);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestReadString)
		{
			EEPROM.data = "LeCloud,Cloud_Duck" + '\0';
			string expected = "LeCloud,Cloud_Duck";
			string result = read_String(0);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestWifiTaskNoReceivedData)
		{
			EEPROM.data = "";
			bool expected = false;
			bool result = wifiTask();
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestWifiTaskNoReceivedSSID)
		{
			EEPROM.data = ",CloudDuck";
			bool expected = false;
			bool result = wifiTask();
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestWifiTaskNoReceivedPass)
		{
			EEPROM.data = "LeCloud,";
			bool expected = false;
			bool result = wifiTask();
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestWifiTaskFailedConnection)
		{
			EEPROM.data = "LeCloud,Cloud_Duck";
			WiFi.connected = false;
			bool expected = false;
			bool result = wifiTask();
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestWifiTaskSuccess)
		{
			EEPROM.data = "LeCloud,Cloud_Duck";
			WiFi.connected = true;
			bool expected = true;
			bool result = wifiTask();
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestMyCallbacksOnWriteNoData)
		{
			MyCallbacks myCallbacks;
			bool expected = false;
			bool result = myCallbacks.onWrite("");
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestMyCallbacksOnWriteSuccess)
		{
			MyCallbacks myCallbacks;
			bool expected = true;
			bool result = myCallbacks.onWrite("LeCloud,Cloud_Duck");
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestMyCallbacksWriteString)
		{
			MyCallbacks myCallbacks;
			string expected = "LeCloud,Cloud_Duck" + '\0';
			EEPROM.data = "";
			myCallbacks.writeString(0, "LeCloud,Cloud_Duck");
			string result = EEPROM.data;
			Assert::AreEqual(expected.c_str(), result.c_str());
		}
		TEST_METHOD(TestSetupMode0)
		{
			modeIdx = 0;
			isSetup = false;
			bool expected = true;
			setup();
			bool result = isSetup;
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestSetupMode1)
		{
			modeIdx = 1;
			isSetup = false;
			bool expected = true;
			setup();
			bool result = isSetup;
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TestSetupSkipDelay)
		{
			EEPROM.canBegin = true;
			modeIdx = 1;
			isSetup = false;
			bool expected = true;
			setup();
			bool result = isSetup;
			Assert::AreEqual(expected, result);
		}

	};
}
