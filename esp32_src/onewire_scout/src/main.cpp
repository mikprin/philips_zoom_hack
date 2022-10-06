#include <Arduino.h>
// #include <EEPROM.h>
#include <stdio.h>
#include <OneWire.h>
#include "pin_defines.h"


OneWire  ds(ONE_WIRE_PIN);  // on pin ONE_WIRE_PIN

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Setup started");

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Loop started");
  
}