/**
 * @brief Basic OLED example.
 *
 * Shows "Hello world." text on display. Example uses U8G2 library.
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
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2( U8G2_R2, 
                            /* reset=*/ U8X8_PIN_NONE, 
                            /* clock=*/ I2C::OLED_DISPLAY::SCL_PIN, 
                            /* data= */ I2C::OLED_DISPLAY::SDA_PIN);

void setup() {
    // Initialize OLED display.
    u8g2.begin();  

    // Show "hello world".
    u8g2.firstPage();
    do {
        u8g2.setFont(u8g2_font_ncenB10_tr);
        u8g2.setCursor(0,12);
        u8g2.print("Hello world!");
    } while (
        u8g2.nextPage();
    );
}

void loop() {
    // Your code.
}
