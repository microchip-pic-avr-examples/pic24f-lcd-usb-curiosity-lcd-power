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

#include <stdio.h>

#include "timer_1ms.h"
#include "operational_mode.h"
#include "lcd_demo.h"
#include "mcc_generated_files/lcd.h"
#include "mcc_generated_files/rtcc.h"
#include "mcc_generated_files/system.h"

//------------------------------------------------------------------------------
//Application related definitions
//------------------------------------------------------------------------------
typedef enum
{
    BUTTON_COLOR_RED = 0,
    BUTTON_COLOR_GREEN = 1,
    BUTTON_COLOR_BLUE = 2
} BUTTON_COLOR;

enum DISPLAY_MODE
{
    DISPLAY_POT,
    DISPLAY_TEMPERATURE,
    DISPLAY_TIME,
    DISPLAY_PIC24
};

//------------------------------------------------------------------------------
//Private prototypes
//------------------------------------------------------------------------------
static void USBPowerModeTask_Initialize(void);
static void USBPowerModeTask_Deinitialization(void);
static void USBPowerModeTasks(void);

//------------------------------------------------------------------------------
//Global variables
//------------------------------------------------------------------------------
static volatile bool update_printout = true;

const struct OPERATIONAL_MODE usb_operational_mode = {
    &USBPowerModeTask_Initialize,
    &USBPowerModeTask_Deinitialization,
    &USBPowerModeTasks
};

//------------------------------------------------------------------------------
//Functions
//------------------------------------------------------------------------------
static void USBPowerModeTask_Initialize(void)
{           
    LCD_Initialize();
    LCD_SetPowerMode(LCD_POWER_MODE_HIGH);
    LCD_DEMO_SetBatteryStatus(BATTERY_STATUS_UNKNOWN);
    LCD_DEMO_PrintPIC24();
}

void USBPowerModeTasks(void)
{      

}

static void USBPowerModeTask_Deinitialization(void)
{
    TIMER_SetConfiguration(TIMER_CONFIGURATION_OFF);
}
