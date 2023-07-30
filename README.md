# ACDU board

[![Arduino_CI](https://github.com/JSC-electronics/acdu-support-library/actions/workflows/arduino_ci.yml/badge.svg)](https://github.com/JSC-electronics/acdu-support-library/actions/workflows/arduino_ci.yml)
[![License: Apache 2.0](https://img.shields.io/badge/license-Apache--2.0-green.svg)](https://github.com/JSC-electronics/acdu-support-library/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/JSC-electronics/acdu-support-library.svg?maxAge=3600)](https://github.com/JSC-electronics/acdu-support-library/releases)
[![JSC TechMinds](https://img.shields.io/badge/JSC-TechMinds-green.svg)](https://www.jsce.cz/)
[![Donate](https://img.shields.io/badge/donate-PayPal-blueviolet.svg)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=SESX9ABM7V8KA&source=url)
![ACDU_V2](https://github.com/JSC-electronics/acdu-support-library/blob/bcd0f757ce4ca1667f882ca5b78d6a925fbf2f98/documentation/ACDU-V2.png)

The ACDU is a unit that contains one power output for DC motor or other DC load, two digital 12V inputs, one analog input and a connector for an OLED display. In addition, DS18B20 temperature sensors can be connected (5 in total).

This configuration makes it suitable for automation tasks such as:

- DC drive (DC motor with limit switches)
- Thermostat (relay connected to the output)
- Automatic water refill (solenoid valve with float switches)
- Smart timers

## Basic parameters and features

- Power supply 9–15 V DC, reverse voltage protection and battery undervoltage protection
- SoC ESP32-WROVER-IE (supports BT and WiFi communication)
- Driver DRV8220 for DC load control, max. load current 1,6 A
- 2x 12V input with short-circuit protection
- 1x analog input, intended for 2-wire sensors, e.g. NTC 100k temperature sensors, photoresistors
- 1wire interface for up to 5 DS18B20 temperature sensors
- 3x pushbutton, coneector for external 3-button keyboard (shared signals)
- 1x connector for I2C OLED display

## Quick-start guide

1. Connect ESP-PROG programmer to the 6pin connector (blue).
2. Connect peripherals.
   1. Power source (9–15 V DC) to – and + terminals.
   2. Motor (or other DC load) to "M" terminals (the polarity does not matter).
   3. (optional) SW1 (standard limit switch), polarity does not matter.
   4. (optional) SW2 (standard limit switch), polarity does not matter.
   5. (optional) PR – photoresistor. The PR value should be between 30 and 90 kΩ.
3. Attach jumper JP1 (connect pins). With jumper ON, the flashing/downloading of the SW is possible.

## Detailed description

### Power output (M)

A DC load (such as motors, relays, solenoid valves, heating elements etc.) with a current of max. 1.6 A can be connected to the power output (M).

The DRV8220 driver uses PWM mode and allows to change the direction of rotation of the DC motor, braking and coasting. Three signals are used for control - nSleep, IN1 and IN2, the table below describes all possible signal combinations. The motor is connected to OUT1 and OUT2.

| nSLEEP | IN1 | IN2 | OUT1 | OUT2 | DESCRIPTION                                          |
|--------|-----|-----|------|------|------------------------------------------------------|
| 0      | X   | X   | Hi-Z | Hi-Z | Low-power sleep mode                                 |
| 1      | 0   | 0   | Hi-Z | Hi-Z | Coast (H-bridge Hi-Z)/low-power automatic sleep mode |
| 1      | 0   | 1   | L    | H    | Reverse (OUT2 → OUT1)                                |
| 1      | 1   | 0   | H    | L    | Forward (OUT1 → OUT2)                                |
| 1      | 1   | 1   | L    | L    | Brake (low-side slow decay)                          |

The ACDU also allows to measure the load current. The lowest measurable current is ~150 mA. The current is measured using the voltage at the analog input A0 (SENSOR_VP). The voltage to current conversion is $I_{load} = V_{A0}/(5*0,22)$.

### 12V digital input (SW1, SW2)

These inputs are inteded for pushbuttons, limit switches, float switches etc. Do not connect external signals/voltage to these inputs.

### 12V analog input (PR)

Input is intended for variable-resistance 2-wire sensors, e.g. NTC 100k temperature sensors and photoresistors. One screw terminal is connected to 12 V via 60 kΩ pull-up resistance and to GND (ground) via 750 kΩ resistance. The second screw terminal is connected to ground. With nothing connected, expect non-zero value on the ADC.

### Pinout

![ACDU_pinout](https://github.com/JSC-electronics/acdu-support-library/blob/bcd0f757ce4ca1667f882ca5b78d6a925fbf2f98/documentation/ACDU-V2-description.png)

| Signal                                   | ESP GPIO |
|------------------------------------------|----------|
| 1-Wire (for DS18B20 temperature sensors) | 18       |
| I2C SDA (for SSD1306 OLED display)       | 25       |
| I2C SCL                                  | 26       |
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

### Dimensions

![dimensions](https://github.com/JSC-electronics/acdu-support-library/blob/bcd0f757ce4ca1667f882ca5b78d6a925fbf2f98/documentation/ACDU-V2-drawing.png)

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
