/**
 * @brief Demonstrates control of a DC motor with PWM.
 *
 * This sketch demonstrates control of a DC motor (CW and CCW rotation) with PWM and fading.
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
 
#include <Arduino.h>
#include <esp32-hal-ledc.h>
#include <acdu.h>

#define PWM_CHANNEL_0 0
#define PWM_CHANNEL_1 1
#define PWM_FREQUENCY 500
#define PWM_RESOLUTION 8

// Define the motor control pins.
#define MOTOR_IN1 MOTOR_DRIVER::ANALOG_OUTPUT::PIN_IN1
#define MOTOR_IN2 MOTOR_DRIVER::ANALOG_OUTPUT::PIN_IN2
#define MOTOR_EN  MOTOR_DRIVER::DIGITAL_OUTPUT::PIN_NSLEEP

void setup() {
    // Initialize the LEDC peripheral.
    ledcSetup(PWM_CHANNEL_0, PWM_FREQUENCY, PWM_RESOLUTION);
    ledcSetup(PWM_CHANNEL_1, PWM_FREQUENCY, PWM_RESOLUTION);

    // Attach the motor control pins to the LEDC peripheral.
    ledcAttachPin(MOTOR_IN1, PWM_CHANNEL_0);
    ledcAttachPin(MOTOR_IN2, PWM_CHANNEL_1);

    pinMode(MOTOR_EN, OUTPUT);
    digitalWrite(MOTOR_EN, LOW);
}

void loop() {
    // Increase motor speed, CW.
    digitalWrite(MOTOR_EN, HIGH);
    for (int i = 0; i < 255; i++) {
        ledcWrite(PWM_CHANNEL_0, i);
        ledcWrite(PWM_CHANNEL_1, 0);
        delay(10);
    }
    delay(3000);

    // Brake.
    ledcWrite(PWM_CHANNEL_0, 255);
    ledcWrite(PWM_CHANNEL_1, 255); 
    delay(3000);

    // Increase motor speed, CCW.
    for (int i = 0; i < 255; i++) {
        ledcWrite(PWM_CHANNEL_0, 0);
        ledcWrite(PWM_CHANNEL_1, i);
        delay(10);
    }
    delay(1000);

    // Decrease motor speed, CCW.
    for (int i = 255; i >= 0; i--) {
        ledcWrite(PWM_CHANNEL_0, 0);
        ledcWrite(PWM_CHANNEL_1, i);
        delay(10);
    }
}