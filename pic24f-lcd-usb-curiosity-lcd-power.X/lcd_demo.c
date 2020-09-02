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
#include <string.h>
#include <stdio.h>

#include "lcd_demo.h"
#include "bsp/lcd1.h"

static char print_buffer[10];
static bool low_power = false;

void LCD_DEMO_PrintPIC24(void) 
{      
    LCD1_Colon_AltOff();
    
    LCD1_Colon_Off();
    LCD1_PeriodIcon1_Off();
    LCD1_PeriodIcon2_Off();
    LCD1_PeriodIcon3_Off();
    LCD1_PeriodIcon4_Off();
    LCD1_PeriodIcon5_Off();
    LCD1_PeriodIcon6_Off();
    
    LCD1_PeriodIcon1_AltOff();
    LCD1_PeriodIcon2_AltOff();
    LCD1_PeriodIcon3_AltOff();
    LCD1_PeriodIcon4_AltOff();
    LCD1_PeriodIcon5_AltOff();
    LCD1_PeriodIcon6_AltOff();
    
    LCD1_Logos_AltOn();

    LCD1_Char1_Print('P');
    LCD1_Char2_Print('I');
    LCD1_Char3_Print('C');
    LCD1_Char4_Print('2');
    LCD1_Char5_Print('4');
    
    LCD1_Char1_AltPrint(' '); 
    LCD1_Char2_AltPrint(' ');
    LCD1_Char3_AltPrint('L');
    LCD1_Char4_AltPrint('C');
    LCD1_Char5_AltPrint('D');
    
    LCD1_ModeSet(LCD1_MODE_ALTERNATE);
}

void LCD_DEMO_PrintPot(uint16_t value)
{
    LCD1_ModeSet(LCD1_MODE_NORMAL);
    
    memset(print_buffer, ' ', sizeof (print_buffer));

    sprintf(print_buffer, "%04i", value);

    LCD1_Colon_Off();
    LCD1_PeriodIcon1_Off();
    LCD1_PeriodIcon2_Off();
    LCD1_PeriodIcon3_Off();
    LCD1_PeriodIcon4_Off();
    LCD1_PeriodIcon5_Off();
    LCD1_PeriodIcon6_Off();

    LCD1_Char1_Print(print_buffer[0]);
    LCD1_Char2_Print(print_buffer[1]);
    LCD1_Char3_Print(print_buffer[2]);
    LCD1_Char4_Print(print_buffer[3]);
    
    LCD1_Char5_Print(' ');
}

void LCD_DEMO_PrintTime(uint8_t hour, uint8_t minute)
{      
    LCD1_Colon_On();
    
    LCD1_PeriodIcon1_Off();
    LCD1_PeriodIcon2_Off();
    LCD1_PeriodIcon3_Off();
    LCD1_PeriodIcon4_Off();
    LCD1_PeriodIcon5_Off();
    LCD1_PeriodIcon6_Off();
    
    LCD1_Char1_AltPrint(' ');
    LCD1_Char2_AltPrint(' ');
    LCD1_Char3_AltPrint(' ');
    LCD1_Char4_AltPrint(' ');
    LCD1_Char5_AltPrint(' ');
    
    LCD1_Logos_AltOff();
    
    memset(print_buffer, ' ', sizeof (print_buffer));

    if(hour > 12)
    {
        hour -= 12;
        LCD1_Char5_Print('P');
    }
    else if(hour == 0)
    {
        hour = 12;
        LCD1_Char5_Print('A');
    }
    else if(hour == 12)
    {
        LCD1_Char5_Print('P');
    }
    else
    {
        LCD1_Char5_Print('A');
    }
    sprintf(print_buffer, "%2i", hour);

    LCD1_Char1_Print(print_buffer[0]);
    LCD1_Char2_Print(print_buffer[1]);

    memset(print_buffer, ' ', sizeof (print_buffer));

    sprintf(print_buffer, "%02i", minute);

    LCD1_Char3_Print(print_buffer[0]);
    LCD1_Char4_Print(print_buffer[1]);
    
    LCD1_Colon_AltOn();
    
    if(low_power == true)
    {
        LCD1_ModeSet(LCD1_MODE_BLINK_LOW_POWER);
    }
    else
    {
        LCD1_ModeSet(LCD1_MODE_BLINK_HIGH_POWER);
    }
}

void LCD_DEMO_PrintVoltage(double voltage) 
{
    LCD1_ModeSet(LCD1_MODE_NORMAL);
    
    memset(print_buffer, ' ', sizeof (print_buffer));

    sprintf(print_buffer, "%.3f", voltage);

    LCD1_Colon_Off();
    LCD1_PeriodIcon1_Off();
    LCD1_PeriodIcon2_Off();
    LCD1_PeriodIcon3_Off();
    LCD1_PeriodIcon4_Off();
    LCD1_PeriodIcon5_Off();
    LCD1_PeriodIcon6_Off();

    LCD1_Char1_Print(print_buffer[0]);
    LCD1_PeriodIcon1_On();
    LCD1_Char2_Print(print_buffer[2]);
    LCD1_Char3_Print(print_buffer[3]);
    LCD1_Char4_Print(print_buffer[4]);
    
    LCD1_Char5_Print('V');
}

void LCD_DEMO_SetBatteryStatus(enum BATTERY_STATUS status) 
{
    switch (status) 
    {
        case BATTERY_STATUS_UNKNOWN:
            LCD1_BatteryBarLow_Off();
            LCD1_BatteryBarMiddle_Off();
            LCD1_BatteryBarHigh_Off();
            LCD1_BatteryBarLow_AltOff();
            break;
            
        case BATTERY_STATUS_FULL:
            LCD1_BatteryBarLow_On();
            LCD1_BatteryBarMiddle_On();
            LCD1_BatteryBarHigh_On();
            LCD1_BatteryBarLow_AltOff();
            break;

        case BATTERY_STATUS_MEDIUM:
            LCD1_BatteryBarLow_On();
            LCD1_BatteryBarMiddle_On();
            LCD1_BatteryBarHigh_Off();
            LCD1_BatteryBarLow_AltOff();
            break;

        case BATTERY_STATUS_LOW:
            LCD1_BatteryBarLow_On();
            LCD1_BatteryBarMiddle_Off();
            LCD1_BatteryBarHigh_Off();
            LCD1_BatteryBarLow_AltOff();
            break;

        case BATTERY_STATUS_CRITICAL:
        default:
            LCD1_BatteryBarLow_On();
            LCD1_BatteryBarMiddle_Off();
            LCD1_BatteryBarHigh_Off();
            LCD1_BatteryBarLow_AltOn();
            break;
    }
}

void LCD_DEMO_LowPowerModeEnable(bool low_power_mode_enabled) 
{   
    low_power = low_power_mode_enabled;
}

void LCD_DEMO_PrintTemperature(double temp) 
{
    unsigned int i;
    unsigned int character;

    /* Print the Celsius temperature */
    LCD1_Colon_Off();
    LCD1_Logos_On();
    LCD1_PeriodIcon5_On();
    LCD1_PeriodIcon6_Off();
    
    memset(print_buffer, ' ', sizeof (print_buffer));

    sprintf(print_buffer, "%.3f", temp);

    character = 1;
    for (i = 0; i<sizeof (print_buffer); i++)
    {
        if (print_buffer[i] == '.') 
        {
            switch (character) 
            {
                case 2:
                    LCD1_PeriodIcon1_On();
                    LCD1_PeriodIcon2_Off();
                    LCD1_PeriodIcon3_Off();
                    LCD1_PeriodIcon4_Off();
                    break;
                case 3:
                    LCD1_PeriodIcon1_Off();
                    LCD1_PeriodIcon2_On();
                    LCD1_PeriodIcon3_Off();
                    LCD1_PeriodIcon4_Off();
                    break;
                case 4:
                    LCD1_PeriodIcon1_Off();
                    LCD1_PeriodIcon2_Off();
                    LCD1_PeriodIcon3_On();
                    LCD1_PeriodIcon4_Off();
                    break;
                default:
                    break;
            }
        } 
        else 
        {
            switch(character){
                case 1:
                    LCD1_Char1_Print(print_buffer[i]);
                    break;
                case 2:
                    LCD1_Char2_Print(print_buffer[i]);
                    break;
                case 3:
                    LCD1_Char3_Print(print_buffer[i]);
                    break;
                case 4:
                    LCD1_Char4_Print(print_buffer[i]);
                    break;
                default:
                    break;
            }
            character++;
        }

        if (character >= 4) 
        {
            break;
        }
    }
    
    LCD1_Char5_Print('C');
    
    /* Print the Fahrenheit temperature */
    LCD1_Colon_AltOff();
    LCD1_Logos_AltOn();
    
    LCD1_PeriodIcon5_AltOn();
    
    /* convert C to F */
    temp = ((temp * 9/5) + 32);
            
    memset(print_buffer, ' ', sizeof (print_buffer));

    sprintf(print_buffer, "%.3f", temp);

    character = 1;
    for (i = 0; i<sizeof (print_buffer); i++) 
    {
        if (print_buffer[i] == '.') 
        {
            switch (character) 
            {
                case 2:
                    LCD1_PeriodIcon1_AltOn();
                    LCD1_PeriodIcon2_AltOff();
                    LCD1_PeriodIcon3_AltOff();
                    LCD1_PeriodIcon4_AltOff();
                    break;
                case 3:
                    LCD1_PeriodIcon1_AltOff();
                    LCD1_PeriodIcon2_AltOn();
                    LCD1_PeriodIcon3_AltOff();
                    LCD1_PeriodIcon4_AltOff();
                    break;
                case 4:
                    LCD1_PeriodIcon1_AltOff();
                    LCD1_PeriodIcon2_AltOff();
                    LCD1_PeriodIcon3_AltOn();
                    LCD1_PeriodIcon4_AltOff();
                    break;
                default:
                    break;
            }
        } 
        else 
        {
            switch(character){
                case 1:
                    LCD1_Char1_AltPrint(print_buffer[i]);
                    break;
                case 2:
                    LCD1_Char2_AltPrint(print_buffer[i]);
                    break;
                case 3:
                    LCD1_Char3_AltPrint(print_buffer[i]);
                    break;
                case 4:
                    LCD1_Char4_AltPrint(print_buffer[i]);
                    break;
                default:
                    break;
            }
            
            character++;
        }

        if (character > 4) 
        {
            break;
        }
    }
    
    LCD1_PeriodIcon6_AltOff();
    
    LCD1_Char5_AltPrint('F');
    
    LCD1_ModeSet(LCD1_MODE_ALTERNATE);
}