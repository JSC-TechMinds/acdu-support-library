/**
 *  @file       acdu.h
 *  Project     ACDU (automatic cover drive unit)
 *  @brief      Pin layout for the ACDU board (HW revision 1 and 2).
 *  @author     JSC TechMinds
 *  @copyright  2023 JSC TechMinds
 *  License     Apache-2.0
 *
 *  @section License
 *
 *  Copyright 2023 JSC TechMinds
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
        // Not defined.
        static constexpr const uint8_t ADDRESS = 0x00;
        static constexpr const uint8_t SDA_PIN = 25;
        static constexpr const uint8_t SCL_PIN = 26;
    }
}

namespace ONEWIRE {
    // Pin for the 1-Wire bus.
    // Usually used to fetch temperatures from
    // sensors, but any compatible device can be attached.
    // You can connect up to 4 external devices to the
    // ports on the right side of the ACDU board.
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

// Pins for the DRV8220 motor driver if you decide to use a motor.
// The motor is connected to pins 3 and 4 on the physical bus.
// https://www.ti.com/product/DRV8220

// Control mode logic table
// nSLEEP    IN1     IN2     OUT1    OUT2    DESCRIPTION
//   0       X       X       Hi-Z    Hi-Z    Low-power sleep mode
//   1       0       0       Hi-Z    Hi-Z    Coasting
//   1       0       1       L       H       CW
//   1       1       0       H       L       CCW
//   1       1       1       L       L       Brake (low-side slow decay)
namespace MOTOR_DRIVER {
    namespace INPUTS {
        namespace ANALOG_IN {
            static constexpr const uint8_t PIN_CURRENT = A0;
        }
    }

    namespace OUTPUTS {
        namespace DIGITAL_OUT {
            static constexpr const uint8_t PIN_NSLEEP = 0;
        }

        namespace ANALOG_OUT {
            // Supports speed control using PWM. See examples.
            // Naming reflects port names from the datasheet.
            // ESP32 uses these ports for output.
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

namespace INPUTS {
    namespace DIGITAL_IN {
        // Marked as SW1 and SW2 on the board.
        // These are 12V digital inputs primarily used for limit switches.
        // However, you can treat these pins as universal
        // digital inputs.
        static constexpr const uint8_t PIN_SW1 = 34;
        static constexpr const uint8_t PIN_SW2 = 35;
    }

    namespace ANALOG_IN {
        // Marked as PR on the board.
        // This is a 12V analog input primarily used for a photoresistor.
        // However, you can treat this pin as a universal analog
        // or digital input.
        static constexpr const uint8_t PIN_PR = A3;
    }
}

#endif // ACDU_H