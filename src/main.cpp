#include "Arduino.h"

#define pinUp 7
#define pinDown 8
#define trigPin 13
#define echoPin 12

void setup(){
  pinMode(pinUp, OUTPUT);
  pinMode(pinDown, OUTPUT);
  digitalWrite(pinUp, HIGH);
  digitalWrite(pinDown, HIGH);
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void DistanceMeasure(){
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance > 3000) {
    Serial.println ("error");
  }
  else{
     Serial.print(distance);
     Serial.println("cm");
  }
  delay(1000);

}

void loop(){

  /* Lifting the table up */
  Serial.println("Down");
  digitalWrite(pinDown, LOW);
  delay(2000);
  digitalWrite(pinDown, HIGH);
  delay(2000);
  DistanceMeasure();

  /* Pushing the table down */
  Serial.println("UP");
  digitalWrite(pinUp, LOW);
  delay(2000);
  digitalWrite(pinUp, HIGH);
  delay(2000);
  DistanceMeasure();
}
