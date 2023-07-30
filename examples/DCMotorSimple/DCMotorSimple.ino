/**
 * @brief Demonstrates control of a DC motor.
 *
 * This sketch demonstrates simple control of a DC motor – CW and CCW rotation.
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

typedef enum {
    IDLE = 0,
    RUN_CW,
    RUN_CCW,
    BRAKE
} MOTOR_STATE;

MOTOR_STATE ms = IDLE;

void setup() {
    // Initialize serial communication.
    Serial.begin(9600);

    // Initialize motor outputs.
    pinMode(MOTOR_DRIVER::DIGITAL_OUTPUT::PIN_NSLEEP, OUTPUT);
    pinMode(MOTOR_DRIVER::ANALOG_OUTPUT::PIN_IN1, OUTPUT);
    pinMode(MOTOR_DRIVER::ANALOG_OUTPUT::PIN_IN2, OUTPUT);

    // Put motor into IDLE.
    digitalWrite(MOTOR_DRIVER::DIGITAL_OUTPUT::PIN_NSLEEP, LOW);
    digitalWrite(MOTOR_DRIVER::ANALOG_OUTPUT::PIN_IN1, LOW);
    digitalWrite(MOTOR_DRIVER::ANALOG_OUTPUT::PIN_IN2, LOW);
}

void loop() {
    /* Control mode logic table
    * nSLEEP    IN1     IN2     OUT1    OUT2    DESCRIPTION
    *   0       X       X       Hi-Z    Hi-Z    Low-power sleep mode
    *   1       0       0       Hi-Z    Hi-Z    Coasting
    *   1       0       1       L       H       CW
    *   1       1       0       H       L       CCW
    *   1       1       1       L       L       Brake (low-side slow decay)
    */
    switch (ms) {
        case IDLE: {
            Serial.println("IDLE");
            digitalWrite(MOTOR_DRIVER::DIGITAL_OUTPUT::PIN_NSLEEP, LOW);
            digitalWrite(MOTOR_DRIVER::ANALOG_OUTPUT::PIN_IN1, LOW);
            digitalWrite(MOTOR_DRIVER::ANALOG_OUTPUT::PIN_IN2, LOW);
            ms = RUN_CW;
            break;
        }
        case RUN_CW: {
            Serial.println("Run CW");
            digitalWrite(MOTOR_DRIVER::DIGITAL_OUTPUT::PIN_NSLEEP, HIGH);
            digitalWrite(MOTOR_DRIVER::ANALOG_OUTPUT::PIN_IN1, HIGH);
            digitalWrite(MOTOR_DRIVER::ANALOG_OUTPUT::PIN_IN2, LOW);
            ms = BRAKE;
            break;
        }
        case RUN_CCW: {
            Serial.println("Run CCW");
            digitalWrite(MOTOR_DRIVER::DIGITAL_OUTPUT::PIN_NSLEEP, HIGH);
            digitalWrite(MOTOR_DRIVER::ANALOG_OUTPUT::PIN_IN1, LOW);
            digitalWrite(MOTOR_DRIVER::ANALOG_OUTPUT::PIN_IN2, HIGH);
            ms = IDLE;
            break;
        }

        case BRAKE: {
            Serial.println("BRAKE");
            digitalWrite(MOTOR_DRIVER::DIGITAL_OUTPUT::PIN_NSLEEP, HIGH);
            digitalWrite(MOTOR_DRIVER::ANALOG_OUTPUT::PIN_IN1, HIGH);
            digitalWrite(MOTOR_DRIVER::ANALOG_OUTPUT::PIN_IN2, HIGH);
            ms = RUN_CCW;
            break;
        }
    }
    delay(3000);
}