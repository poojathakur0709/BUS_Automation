 /* Arduino example sketch to control a JSN-SR04T ultrasonic distance sensor with Arduino. No library needed. More info: https://www.makerguides.com */
#include <ArduinoJson.h>
StaticJsonDocument<1000> distance;

// Define Trig and Echo pin:
#define trigPin 2
#define echoPin 3
float duration;
float distance0;
///////////////
#define trigPin1 4
#define echoPin1 5
float duration1;
float distance1;

///////////////
#define trigPin2 6
#define echoPin2 7
float duration2;
float distance2;

///////////////
#define trigPin3 8
#define echoPin3 9
float duration3;
float distance3;

///////////////
#define trigPin4 10
#define echoPin4 11
float duration4;
float distance4;

void setup() {
  // Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

   pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

   pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

   pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

   pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  
  // Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);
}

void loop() {
  //Serial.println("......");
  // Clear the trigPin by setting it LOW:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5); digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // Read the echoPin. pulseIn() returns the duration (length of the pulse) in microseconds:
  duration = pulseIn(echoPin, HIGH); // Calculate the distance:
  duration = duration/1000000.0;
  duration = duration/2;
  distance0= duration*344.32;
distance0= distance0*100;
  // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  digitalWrite(trigPin1, LOW); 
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW); // Read the echoPin. pulseIn() returns the duration (length of the pulse) in microseconds:
  duration1 = pulseIn(echoPin1, HIGH); // Calculate the distance:
  duration1 = duration1/1000000.0;
  duration1 = duration1/2;
  distance1= duration1*344.32;
  
  distance1= distance1*100;
 // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  digitalWrite(trigPin2, LOW); 
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW); // Read the echoPin. pulseIn() returns the duration (length of the pulse) in microseconds:
  duration2 = pulseIn(echoPin2, HIGH); // Calculate the distance:
    duration2 = duration2/1000000.0;
  duration2 = duration2/2;
  distance2= duration2*344.32;
  
  distance2= distance2*100;
 // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  digitalWrite(trigPin3, LOW); 
  delayMicroseconds(5);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW); // Read the echoPin. pulseIn() returns the duration (length of the pulse) in microseconds:
  duration3 = pulseIn(echoPin3, HIGH); // Calculate the distance:
    duration3 = duration3/1000000.0;
  duration3 = duration3/2;
  distance3= duration3*344.32;
   distance3= distance3*100;
  // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  digitalWrite(trigPin4, LOW); 
  delayMicroseconds(5);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW); // Read the echoPin. pulseIn() returns the duration (length of the pulse) in microseconds:
  duration4 = pulseIn(echoPin4, HIGH); // Calculate the distance:
    duration4 = duration4/1000000.0;
  duration4 = duration4/2;
  distance4= duration4*344.32;
 distance4= distance4*100;

  if(distance0 <=50){
    distance["DBU"] ="R";
  }
  else if(distance0 <=150 && distance0 >50 ){
    distance["DBU"] ="O";
  }
  else if(distance0 <=250 && distance0 >150 ){
    distance["DBU"] ="Y";
  }
  if(distance1  <=50){
    distance["DBD"] ="R";
  }
  else if(distance1  <=150 && distance1  >50 ){
    distance["DBD"] ="O";
  }
  else if(distance1  <=250 && distance1  >150 ){
    distance["DBD"] ="Y";
  }
 if(distance2 <50){
    distance["DBC"] ="R";
  }
  else if(distance2  <=150 && distance2  >50 ){
    distance["DBC"] ="O";
  }
  else if(distance2  <=250 && distance2  >150 ){
    distance["DBC"] ="Y";
  }

 if(distance3 <50){
    distance["DBUU"] ="R";
 }
  else if(distance3  <=150 && distance3  >50 ){
    distance["DBUU"] ="O";
  }
  else if(distance3  <=250 && distance3  >150 ){
    distance["DBUU"] ="Y";
  }

 if(distance4 <60){
    distance["DBDD"] ="R";
    }
  else if(distance4  <=150 && distance4  >50 ){
    distance["DBDD"] ="O";
  }
  else if(distance4  <=250 && distance4  >150 ){
    distance["DBDD"] ="Y";
  }
 
  serializeJson(distance, Serial);
  
      Serial.println();
  delay(500);
}
