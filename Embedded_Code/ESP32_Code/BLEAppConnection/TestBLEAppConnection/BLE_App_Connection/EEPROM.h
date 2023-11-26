#pragma once
#include <string>
using namespace std;
class FakeEEPROM
{
public:
   string data = "";
   bool canBegin = false;
   unsigned char read(int index)
   {
      unsigned char result = data[index];
      
      return result;
   }
   void write(int addr, char character)
   {
      data += character;
   }
   void commit()
   {

   }
   bool begin(int size)
   {
      return canBegin;
   }
};

FakeEEPROM EEPROM;