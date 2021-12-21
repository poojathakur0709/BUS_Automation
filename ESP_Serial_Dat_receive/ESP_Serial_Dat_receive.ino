#include <SoftwareSerial.h>


/*#define D5 (18)
#define D6 (19)
#define D7 (23)
#define D8 (5) for serial defibe
SoftwareSerial mySerial1;
SoftwareSerial mySerial2;

mySerial2.begin(9600,  SWSERIAL_8N1, D5, D6,, false);
*/
SoftwareSerial myPort;

void setup() {

Serial.begin(9600); // Standard hardware serial port

Serial2.begin(9600);
myPort.begin(9600, SWSERIAL_8N1, 32, 33, false);
//mySerial2.begin(9600,  SWSERIAL_8N1, D32, D33, false);
Serial.println("Connection established");
} 

void loop() {

  if (Serial.available() > 0) {
    String data3 = Serial.readStringUntil('\n');
    Serial.println(data3);
  }
  if (myPort.available() > 0) {
    String data1 = myPort.readStringUntil('\n');
    Serial.println(data1);
  }
   if (Serial2.available() > 0) {
    String data2 = Serial2.readStringUntil('\n');
    Serial.println(data2);
  }


}
