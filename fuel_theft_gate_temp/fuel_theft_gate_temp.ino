
#include <ArduinoJson.h>
StaticJsonDocument<1000> FuelTempTheft;
int fuel = A1;
#include<dht.h>
dht DHT;
int DHT11_PIN=A2;
//int theft =3;
//int gate =4;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(fuel,INPUT);
pinMode(theft,OUTPUT);
//pinMode(gate,OUTPUT);
}

void loop() {
    int chk=DHT.read11(DHT11_PIN);
    int val =DHT.humidity;
    int c   = analogRead(fuel);
    c = map(c,0,1023,1,7);
    FuelTempTheft["Fuel"] =c;

    //Serial.println(DHT.temperature,1);
    FuelTempTheft["H"] =val;
    FuelTempTheft["T"] =DHT.temperature;
   
  
  
    delay(2000);
    
    serializeJson(FuelTempTheft, Serial);
    Serial.println();  
  
  // put your main code here, to run repeatedly:

}
