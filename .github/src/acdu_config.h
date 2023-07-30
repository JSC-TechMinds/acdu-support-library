/**
 * @brief ACDU pinout configuration. 
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

#ifndef ACDU_CONFIG_H
#define ACDU_CONFIG_H
#include <Arduino.h>

namespace I2C {
    namespace OLED_DISPLAY {
        static constexpr const uint8_t ADDRESS = 0x00; // not defined
        static constexpr const uint8_t SDA_PIN = 25;
        static constexpr const uint8_t SCL_PIN = 26;
    }
}

namespace SDCARD {
    static constexpr const uint8_t PIN_DATA0 = 2;    // MISO
    static constexpr const uint8_t PIN_DATA1 = 4;
    static constexpr const uint8_t PIN_DATA2 = 12;   // no HW pullup
    static constexpr const uint8_t PIN_DATA3 = 13;   // CS
    static constexpr const uint8_t PIN_CLK = 14;   // SCK
    static constexpr const uint8_t PIN_CMD = 15;   // MOSI
    static constexpr const uint8_t PIN_CD = 5;  
}

namespace BUTTON {
    static constexpr const uint8_t PIN_L = 23; // Up
    static constexpr const uint8_t PIN_M = 22; // Down
    static constexpr const uint8_t PIN_R = 21; // OK
}

namespace LIMIT_SWITCH {
    static constexpr const uint8_t PIN_LS1 = 34;
    static constexpr const uint8_t PIN_LS2 = 35;
}

namespace IN_ANALOG {
    static constexpr const uint8_t PIN_CURRENT = A0;
    static constexpr const uint8_t PIN_PHOTORESISTOR = A3;
}

namespace TEMP_SENSORS {
    static constexpr const uint8_t PIN_ONEWIRE = 18;
}

namespace MOTOR {
    static constexpr const uint8_t PIN_NSLEEP = 0;
    static constexpr const uint8_t PIN_IN1 = 27;
    static constexpr const uint8_t PIN_IN2 = 19;    
}

#endif // ACDU_CONFIG_H