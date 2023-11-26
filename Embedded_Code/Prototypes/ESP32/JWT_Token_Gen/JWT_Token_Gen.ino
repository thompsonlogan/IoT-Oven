#include <CustomJWT.h>

char key[] = "tester";
char string[] = "{\"temp\":22.5,\"speed\":25.1}";
CustomJWT jwt(key);

// Note: JWT not working since it depends on sha.cpp which relies on avr/pgmspace and avr/io
// which are apparently written for other microcontrollers
// Currently looking into crytosuite2 for sha reference
// https://github.com/daknuett/cryptosuite2#what-is-cryptosuite2

void setup() 
{
  Serial.begin(115200);
  Serial.println("Hello");
  EncodeJWT();
}
void EncodeJWT()
{
  jwt.changeSecret("eee");
  jwt.encodeJWT(string);
  
  Serial.print("Token: ");
  Serial.println(jwt.out);
  Serial.print("Header: ");
  Serial.println(jwt.header);
  Serial.print("Payload: "); 
  Serial.println(jwt.payload);
  Serial.print("Signature: ");
  Serial.println(jwt.signature);
}
void loop() {

}
