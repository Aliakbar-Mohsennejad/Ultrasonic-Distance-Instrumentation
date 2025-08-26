//(Scenario 1 – Normal Conditions)
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
  // Send a 10µs pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure pulse duration
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance (cm)
  distance = duration * SPEED_OF_SOUND / 2;

  Serial.print("Distance (cm): ");
  Serial.println(distance);

  delay(1000);
}
