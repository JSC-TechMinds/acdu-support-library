/**
 *  @file       acdu.h
 *  Project     ACDU (automatic cover drive unit)
 *  @brief      Pin layout for the ACDU unit (HW revision 1 and 2).
 *  @author     JSC TechMinds
 *  License     Apache-2.0 - Copyright (c) 2023 JSC TechMinds
 *
 *  @section License
 *
 *  Copyright (c) 2023 JSC TechMinds
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


#ifndef ACDU_H
#define ACDU_H
#include <Arduino.h>

namespace I2C {
    namespace OLED_DISPLAY {
        // Not defined
        static constexpr const uint8_t ADDRESS = 0x00;
        static constexpr const uint8_t SDA_PIN = 25;
        static constexpr const uint8_t SCL_PIN = 26;
    }
}

namespace ONEWIRE {
    // Usually used to fetch temperatures from 1-Wire
    // sensors but any compatible device can be attached.
    // You can connect up to 4 external devices to the
    // ports on the right side of ACDU.
    static constexpr const uint8_t PIN_ONEWIRE  = 18;
}

namespace SDCARD {
    // MISO
    static constexpr const uint8_t PIN_DATA0 = 2;
    static constexpr const uint8_t PIN_DATA1 = 4;
    // No HW pullup
    static constexpr const uint8_t PIN_DATA2 = 12;
    // CS
    static constexpr const uint8_t PIN_DATA3 = 13;
     // SCK
    static constexpr const uint8_t PIN_CLK = 14;
    // MOSI
    static constexpr const uint8_t PIN_CMD = 15;
    static constexpr const uint8_t PIN_CD = 5;  
}

// Pins to DRV8220 motor driver if you decide to use motor.
// Motor is attached to pins 3 and 4 on the physical bus.
// https://www.ti.com/product/DRV8220

// Control mode logic table
// nSLEEP    IN1     IN2     OUT1    OUT2    DESCRIPTION
//   0       X       X       Hi-Z    Hi-Z    Low-power sleep mode
//   1       0       0       Hi-Z    Hi-Z    Coasting
//   1       0       1       L       H       CW
//   1       1       0       H       L       CCW
//   1       1       1       L       L       Brake (low-side slow decay)
namespace MOTOR_DRIVER {
    namespace INPUT {
        namespace ANALOG {
            static constexpr const uint8_t PIN_CURRENT = A0;
        }
    }

    namespace OUTPUT {
        namespace DIGITAL {
            static constexpr const uint8_t PIN_NSLEEP = 0;
        }

        namespace ANALOG {
            // Supports speed regulation using PWM. See examples.
            // Naming reflects port names from datasheet. ESP32
            // uses these ports for output.
            static constexpr const uint8_t PIN_IN1 = 27;
            static constexpr const uint8_t PIN_IN2 = 19;
        }
    }
}

namespace BUTTON {
    static constexpr const uint8_t PIN_LEFT = 23;
    static constexpr const uint8_t PIN_MIDDLE = 22;
    static constexpr const uint8_t PIN_RIGHT = 21;
}

namespace INPUT {
    namespace DIGITAL {
        // 12V digital inputs.
        // Usually used for limit switches.
        // Pin 6 and 8 on the physical bus.
        static constexpr const uint8_t PIN_IN1 = 34;
        static constexpr const uint8_t PIN_IN2 = 35;
    }
    namespace ANALOG {
        // 12V analog input.
        // Usually used for photoresistor.
        // Pin 10 on the physical bus.
        static constexpr const uint8_t PIN_IN1 = A3;
    }
}

#endif // ACDU_H