/**
 * @brief Demonstrates how to measure motor current.
 *
 * This sketch demonstrates the current measurement of a DC motor. The analog value
 * on input A0 (GPIO36) is measured; the ADC value increases with increasing current.
 * The code uses the Ticker library; therefore, it is non-blocking. We recommend
 * using the Serial plotter for this demonstration.
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

// Note: This library uses the Ticker library by JSC TechMinds.
// You can find it at https://github.com/JSC-TechMinds/Ticker.

#include <acdu.h>
#include <Ticker.h>

typedef enum {
    IDLE = 0,
    RUN_CW,
    RUN_CCW,
    BRAKE
} MOTOR_STATE;

MOTOR_STATE ms = IDLE;

jsc::Ticker motorActionTicker;
jsc::Ticker analogMeasTicker;

void motorAction();
void analogMeasurement();

void setup() {
    // Initialize serial communication.
    Serial.begin(115200);

    // Initialize motor outputs.
    pinMode(MOTOR_DRIVER::OUTPUTS::DIGITAL_OUT::PIN_NSLEEP, OUTPUT);
    pinMode(MOTOR_DRIVER::OUTPUTS::ANALOG_OUT::PIN_IN1, OUTPUT);
    pinMode(MOTOR_DRIVER::OUTPUTS::ANALOG_OUT::PIN_IN2, OUTPUT);

    // Put motor to IDLE.
    digitalWrite(MOTOR_DRIVER::OUTPUTS::DIGITAL_OUT::PIN_NSLEEP, LOW);
    digitalWrite(MOTOR_DRIVER::OUTPUTS::ANALOG_OUT::PIN_IN1, LOW);
    digitalWrite(MOTOR_DRIVER::OUTPUTS::ANALOG_OUT::PIN_IN2, LOW);

    // Initialize motor current analog input.
    pinMode(MOTOR_DRIVER::INPUTS::ANALOG_IN::PIN_CURRENT, INPUT);

    // Initialize tickers.
    motorActionTicker.attach_ms(3000, motorAction);
    analogMeasTicker.attach_ms(50, analogMeasurement);
}

void loop() {
    // Your code here.
}

void motorAction() {
    /* control mode logic table
    * nSLEEP    IN1     IN2     OUT1    OUT2    DESCRIPTION
    *   0       X       X       Hi-Z    Hi-Z    Low-power sleep mode
    *   1       0       0       Hi-Z    Hi-Z    Coasting
    *   1       0       1       L       H       CW
    *   1       1       0       H       L       CCW
    *   1       1       1       L       L       Brake (low-side slow decay)
    */
    switch (ms) {
        case IDLE: {
            digitalWrite(MOTOR_DRIVER::OUTPUTS::DIGITAL_OUT::PIN_NSLEEP, LOW);
            digitalWrite(MOTOR_DRIVER::OUTPUTS::ANALOG_OUT::PIN_IN1, LOW);
            digitalWrite(MOTOR_DRIVER::OUTPUTS::ANALOG_OUT::PIN_IN2, LOW);
            ms = RUN_CW;
        }
        break;

        case RUN_CW: {
            digitalWrite(MOTOR_DRIVER::OUTPUTS::DIGITAL_OUT::PIN_NSLEEP, HIGH);
            digitalWrite(MOTOR_DRIVER::OUTPUTS::ANALOG_OUT::PIN_IN1, HIGH);
            digitalWrite(MOTOR_DRIVER::OUTPUTS::ANALOG_OUT::PIN_IN2, LOW);
            ms = BRAKE;
        }
        break;

        case RUN_CCW: {
            digitalWrite(MOTOR_DRIVER::OUTPUTS::DIGITAL_OUT::PIN_NSLEEP, HIGH);
            digitalWrite(MOTOR_DRIVER::OUTPUTS::ANALOG_OUT::PIN_IN1, LOW);
            digitalWrite(MOTOR_DRIVER::OUTPUTS::ANALOG_OUT::PIN_IN2, HIGH);
            ms = IDLE;
        }
        break;

        case BRAKE: {
            digitalWrite(MOTOR_DRIVER::OUTPUTS::DIGITAL_OUT::PIN_NSLEEP, HIGH);
            digitalWrite(MOTOR_DRIVER::OUTPUTS::ANALOG_OUT::PIN_IN1, HIGH);
            digitalWrite(MOTOR_DRIVER::OUTPUTS::ANALOG_OUT::PIN_IN2, HIGH);
            ms = RUN_CCW;
        }
        break;
    }
}

void analogMeasurement() {
    int a1 = analogReadMilliVolts(MOTOR_DRIVER::INPUTS::ANALOG_IN::PIN_CURRENT); 

    // The voltage must be divided by 5, because the gain of the OpAmp on the board is 5.
    // The Rsense value is 0.22 Ohm.
    // Note that the measured current value is approximate; the value 1.05 is used for measurement correction.
    float current = a1*1.05/(5*0.22);
    Serial.println(current);
}
