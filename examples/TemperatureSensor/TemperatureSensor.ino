/**
 * @brief Example for DS18B20 temperature sensor.
 *
 * This example measures temperature once per second using the DallasTemperature library.
 * 
 * Copyright 2023 JSC TechMinds
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// The ESP32 boards platform developers decided to treat compiler warnings as errors.
// The OneWire library has a few unused variables, which causes
// this example to fail. The fix is already in OneWire master branch.
// We just have to wait until a new release is made. Until then
// we have disabled this test.
//
// To run this example, comment out the #define TEST_BLACKLISTED line.
//
// Related issues:
// https://github.com/arduino/arduino-cli/issues/2252
// https://github.com/Arduino-CI/arduino_ci/issues/331
// https://github.com/PaulStoffregen/OneWire/issues/74
// https://github.com/PaulStoffregen/OneWire/pull/118

#define TEST_BLACKLISTED

#ifndef TEST_BLACKLISTED
#include <acdu.h>

#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(ONEWIRE::PIN_ONEWIRE);
DallasTemperature tempSensor(&oneWire);

void setup() {
    // Initialize serial communication.
    Serial.begin(115200);

    // Initialize temperature sensor.
    tempSensor.begin();
}

void loop() {
    if (tempSensor.getDeviceCount() == 1) {
        tempSensor.requestTemperatures();
        Serial.println(tempSensor.getTempCByIndex(0));
    } else {
        Serial.println("No sensor connected.");
    }
    delay(3000);
}
#else
void setup() {}
void loop() {}
#endif
