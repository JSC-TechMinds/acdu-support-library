/**
 * @brief Analog and digital inputs example. 
 *
 * Reads state of three pushbuttons, two 12V digital inputs and one analog input.
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

#include <acdu.h>

void setup() {
    // Initialize serial communication.
    Serial.begin(115200);

    // Initialize pushbuttons.
    pinMode(BUTTON::PIN_LEFT, INPUT);
    pinMode(BUTTON::PIN_MIDDLE, INPUT);
    pinMode(BUTTON::PIN_RIGHT, INPUT);

    // Initialize 12V inputs.
    pinMode(DIGITAL_INPUT::PIN_IN1, INPUT);
    pinMode(DIGITAL_INPUT::PIN_IN2, INPUT);

    // Initialize 12V analog input intended for photoresistor, etc.
    pinMode(ANALOG_INPUT::PIN_IN1, INPUT);
}

void loop() {
    // Check state of pushbuttons, inverted logic.
    if (!digitalRead(BUTTON::PIN_LEFT)) Serial.println("Left button pressed.");
    if (!digitalRead(BUTTON::PIN_MIDDLE)) Serial.println("Middle button pressed.");
    if (!digitalRead(BUTTON::PIN_RIGHT)) Serial.println("Right button pressed.");

    // Check state of 12V digital inputs.
    if (digitalRead(DIGITAL_INPUT::PIN_IN1)) Serial.println("12V IN1 activated");
    if (digitalRead(DIGITAL_INPUT::PIN_IN2)) Serial.println("12V IN2 activated");

    // Check analog input.
    Serial.print("Analog input ADC value: "); Serial.println(analogRead(ANALOG_INPUT::PIN_IN1));
    Serial.println();

    delay(3000);
}
