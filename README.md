# ACDU (automatic cover drive unit)
[![Arduino_CI](https://github.com/JSC-electronics/acdu-support-library/actions/workflows/arduino_ci.yml/badge.svg)](https://github.com/JSC-electronics/acdu-support-library/actions/workflows/arduino_ci.yml)
[![License: Apache 2.0](https://img.shields.io/badge/license-Apache--2.0-green.svg)](https://github.com/JSC-electronics/acdu-support-library/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/JSC-electronics/acdu-support-library.svg?maxAge=3600)](https://github.com/JSC-electronics/acdu-support-library/releases)
[![JSC TechMinds](https://img.shields.io/badge/JSC-TechMinds-green.svg)](https://www.jsce.cz/)
[![Donate](https://img.shields.io/badge/donate-PayPal-blueviolet.svg)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=SESX9ABM7V8KA&source=url)
![ACDU_V1](https://github.com/JSC-electronics/acdu-hw-design/blob/6864a93f1780622b33f9676721671108bcf07419/documentation/ACDU%20V1.PNG)

## Quick-start guide
1. Connect ESP-PROG programmer to the 6pin connector (blue).
2. Connect peripherals.
   1. Power (9–12 V DC) to - and + terminals.
   2. Motor to "M" terminals (the polarity does not matter).
   3. SW1 (standard switch), polarity does not matter.
   4. SW2 (standard switch), polarity does not matter.
   5. PR – photoresistor. The PR value should be between 30 and 90 kΩ.
3. Attach jumper to GPIO0 (not visible on render image, but it is on the right side of the ESP32 module). It is recommended to leave jumper attached unless user needs to use SD card.
   1. With jumper ON, the flashing/downloading of the SW is possible.
   2. With jumper OFF, the SD card communication is possible. The correct procedure is attaching the jumper for downloading and then detaching once the download starts.
4. (optional) Insert SD card.

## Pinout
| Signal                                   | ESP GPIO |
|------------------------------------------|----------|
| 1-Wire (for DS18B20 temperature sensors) | 18       |
| I2C SDA (for SSD1306 OLED display)       | 25       |
| I2C SCL                                  | 26       |
| SPI MISO (for SD card)                   | 2        |
| SPI MOSI                                 | 15       |
| SPI SCK                                  | 14       |
| SPI CS                                   | 13       |
| PUSHBUTTON LEFT                          | 23       |
| PUSHBUTTON MIDDLE                        | 22       |
| PUSHBUTTON RIGHT                         | 21       |
| LIMIT SWITCH #1                          | 34       |
| LIMIT SWITCH #2                          | 35       |
| ANALOG IN #1 (CURRENT MEASUREMENT)       | A0 (36)  |
| ANALOG IN #2 (LIGHT MEASUREMENT)         | A3 (39)  |
| MOTOR DRIVER NSLEEP                      | 0        |
| MOTOR DRIVER IN1                         | 27       |
| MOTOR DRIVER IN2                         | 19       |

## Custom firmware
We have advanced custom firmware which is really flexible and supports the following features out-of-the-box:<br/>
✅ User interface built using [TcMenu](https://www.thecoderscorner.com/products/arduino-libraries/tc-menu/)<br/>
✅ Motor support<br/>
✅ Temperature support<br/>
✅ Logging to SD card<br/>
✅ Network support (DHCP, static assignment)<br/>
✅ Date and time support (NTP, timezones, RTC time...)<br/>
✅ Automation (various usecases; we add more when needed)<br/>
✅ Internationalization (i18n; currently we support English, Czech, Slovak)<br/>
✅ Custom Android and iOS app for remote control<br/>
✅ ...and more<br/>
❌ Home Assistant support is a work-in-progress

It is likely we can save you significant development time. Feel free to reach out.

## Contributing
If you thing there is some feature missing in our ACDU unit or you encounter issue while using it, feel free to report an issue in this repository. We also offer commercial support. Perhaps if you work on something, we can help you with that.

## License
Copyright (c) 2003 JSC TechMinds. All rights reserved.

Licensed under the [Apache-2.0](LICENSE) license.

## Support
We hope our ACDU unit helped you in your project development. You can support our effort to convert coffe and pizza into a code with a small donation. Any support is much appreciated.

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=SESX9ABM7V8KA&source=url)