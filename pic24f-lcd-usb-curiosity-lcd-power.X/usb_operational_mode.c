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
#include "lcd1.h"
#include "operational_mode.h"
#include "mcc_generated_files/rtcc.h"
#include "lcd_demo.h"

//------------------------------------------------------------------------------
//Application related definitions
//------------------------------------------------------------------------------
#define BUTTON_DEBOUCE_TIME_MS      20

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
static void UpdateSegmentedLCD(void);
static void UpdatePrintout(void);

static void Initialize(void);
static void Deinitialize(void);
static void Tasks(void);

//------------------------------------------------------------------------------
//Global variables
//------------------------------------------------------------------------------
static volatile bool update_printout = true;
static struct tm date_time;

const struct OPERATIONAL_MODE usb_operational_mode = {
    &Initialize,
    &Deinitialize,
    &Tasks
};

//------------------------------------------------------------------------------
//Functions
//------------------------------------------------------------------------------
static void Initialize(void)
{   
    //Turn on a timer, so to generate periodic interrupts.
    TIMER_SetConfiguration(TIMER_CONFIGURATION_1MS);
    
    //Register the ButtonDebounce() callback function, so it gets called periodically
    //when the timer interrupts occur (in this case at 1:1 rate, so ButtonDebounce()
    //executes once per 1ms).
    TIMER_RequestTick(&UpdatePrintout, 10);
        
    LCD1_Initialize();
    LCD_DEMO_LowPowerModeEnable(false);
    LCD_DEMO_SetBatteryStatus(BATTERY_STATUS_UNKNOWN);
}

void Tasks(void)
{      
    if(update_printout == true)
    {
        update_printout = false;
        
        RTCC_TimeGet(&date_time);
                
        UpdateSegmentedLCD();
    }
}

static void Deinitialize(void)
{
    TIMER_SetConfiguration(TIMER_CONFIGURATION_OFF);
}

static void UpdateSegmentedLCD(void)
{
    LCD_DEMO_PrintPIC24();
}

static void UpdatePrintout(void)
{
    update_printout = true;
}
