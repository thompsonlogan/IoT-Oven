#define RXD2 16
#define TXD2 17
String w ="";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  Serial2.begin(57600,SERIAL_8N1,RXD2, TXD2);
  pinMode(2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial2.available())
  {
    char data_rcvd = Serial2.read();
    //Serial.println(data_rcvd);
    if(data_rcvd != '\r' && data_rcvd != '\n')
    {
      w += data_rcvd;
    }
    else
    {
      Serial.println(w);
      w = "";
    }
    Serial2.write('h');
    Serial2.print('h');
  }
}
