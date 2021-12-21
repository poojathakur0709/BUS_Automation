
#include <HardwareSerial.h>

HardwareSerial MySerial(1);
void setup() {
  // initialize both serial ports:
   MySerial.begin(9600, SERIAL_8N1,  32, 33);     // RX TX
   Serial.begin(9600);
   Serial2.begin(9600);
}

void loop() {
  // read from port 1, send to port 0:
  
  if (Serial2.available()) {
    int inByte = Serial2.read();
    
    Serial.write(inByte);
    
  }


 if (MySerial.available()) {
    int inByte = MySerial.read();
    Serial.write(inByte);
  } 



  
if (Serial.available()) {
    int inByte = Serial.read();
   Serial.write(inByte);
 }
}
