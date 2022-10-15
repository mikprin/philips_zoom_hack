#include <Arduino.h>
// #include <EEPROM.h>
#include <stdio.h>
#include <OneWire.h>
#include "pin_defines.h"


// RTOS includes
extern "C"
{
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
#include "freertos/task.h"
}

static SemaphoreHandle_t one_wire_read_mutex;

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
  uint i;
  byte present = 0;
  byte data[12];
  byte addr[8];

  ds.reset();
  ds.select(addr);
  ds.write(0x44,1);         // start conversion, with parasite power on at the end
  
  delay(1000);     // maybe 750ms is enough, maybe not
  // we might do a ds.depower() here, but the reset will take care of it.
  
  present = ds.reset();

  if ( !ds.search(addr)) {
    Serial.print("No more addresses.\n");
    ds.reset_search();
    vTaskDelay(250 / portTICK_PERIOD_MS);
    return;
  }

  Serial.print("R=");
  for( i = 0; i < 8; i++) {
    Serial.print(addr[i], HEX);
    Serial.print(" ");
  }

  // Read onewire memory

  present = ds.reset();
  ds.select(addr);
  
  
}