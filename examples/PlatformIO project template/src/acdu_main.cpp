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
        u8g2.nextPage()
    );
}

void loop() {
    // Your code.
}
