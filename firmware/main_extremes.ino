//(Scenario 2 – Extreme T/H without compensation)
#include <Arduino.h>
#include "config.h"

long duration;
float distance;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  distance = duration * SPEED_OF_SOUND / 2;

  Serial.print("Distance (Extreme Env, cm): ");
  Serial.println(distance);

  delay(1000);
}
