//(Scenario 3 – Compensated with DHT22)
#include <Arduino.h>
#include "config.h"
#include <DHT.h>

#define DHTTYPE DHT22
DHT dht(DHT_PIN, DHTTYPE);

long duration;
float distance;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  dht.begin();
}

void loop() {
  // Read temperature and humidity
  float temperature = dht.readTemperature(); // °C
  float humidity = dht.readHumidity();       // %

  // Fallback in case of NaN
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT22!");
    delay(2000);
    return;
  }

  // Adjusted speed of sound (m/s) formula
  // v ≈ 331.4 + (0.6 × T) + (0.0124 × H)
  float v = 331.4 + (0.6 * temperature) + (0.0124 * humidity);

  // Convert to cm/µs
  float v_cm_per_us = v / 10000.0; 

  // Trigger ultrasonic
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure duration
  duration = pulseIn(ECHO_PIN, HIGH);

  // Distance using compensated speed of sound
  distance = duration * v_cm_per_us / 2;

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.print(" %, Distance (cm): ");
  Serial.println(distance);

  delay(2000);
}
