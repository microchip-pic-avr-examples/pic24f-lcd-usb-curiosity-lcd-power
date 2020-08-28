/*******************************************************************************
Copyright 2019 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*******************************************************************************/

#ifndef LCD_DEMO_H
#define LCD_DEMO_H

#include <stdint.h>
#include <stdbool.h>

enum BATTERY_STATUS
{
    BATTERY_STATUS_FULL,
    BATTERY_STATUS_MEDIUM,
    BATTERY_STATUS_LOW,
    BATTERY_STATUS_CRITICAL,
    BATTERY_STATUS_UNKNOWN
};

void LCD_DEMO_PrintPot(uint16_t value);
void LCD_DEMO_PrintTime(uint8_t hour, uint8_t min);
void LCD_DEMO_PrintTemperature(double temp);
void LCD_DEMO_SetBatteryStatus(enum BATTERY_STATUS status);
void LCD_DEMO_LowPowerModeEnable(bool enabled);
void LCD_DEMO_PrintVoltage(double voltage);
void LCD_DEMO_PrintPIC24(void); /* Prints "PIC24" and then "LCD" on the screen alternating */

#endif
