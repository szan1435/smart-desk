#include "Arduino.h"

#define pinUp 7
#define pinDown 8

void setup(){
  pinMode(pinUp, OUTPUT);
  pinMode(pinDown, OUTPUT);
  digitalWrite(pinUp, HIGH);
  digitalWrite(pinDown, HIGH);
}

void loop(){
  /* Lifting the table up */
  digitalWrite(pinDown, LOW);
  delay(2000);

  digitalWrite(pinDown, HIGH);
  delay(2000);

  /* Pushing the table down */
  digitalWrite(pinUp, LOW);
  delay(2000);

  digitalWrite(pinUp, HIGH);
  delay(2000);
}
