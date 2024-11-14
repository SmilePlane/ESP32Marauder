#include <Arduino.h>
//#include "../src_esp32/configs.h"
char receivedChar;
boolean newData = false;
void setup()
{
  Serial.begin(115200);

  SERIAL_AT.begin(115200);
  delay(5000);
  SERIAL_AT.print("reboot");
}
void recvOneChar() {
    if (Serial.available() > 0) {
        receivedChar = Serial.read();
        SERIAL_AT.print(receivedChar);
        newData = true;
    }
}

void showNewData() {
    if (newData == true) {
        Serial.print("This just in ... ");
        Serial.print(receivedChar);
        newData = false;
    }
}

void loop()
{
  //delay(10);
  //Serial.println("WORK");
  // Read messages from ESP32
  if (SERIAL_AT.available()) {
    //Serial.print("ESP32 says: ");
    while (SERIAL_AT.available()) {
      Serial.write(SERIAL_AT.read());
   }
         
      //showNewData();
    
  }
  recvOneChar();
}
