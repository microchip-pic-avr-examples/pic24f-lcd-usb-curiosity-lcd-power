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

#include <xc.h>
#include <string.h>
#include <stdio.h>
#include "lcd_demo.h"
#include "mcc_generated_files/lcd.h"

//------------------------------------------------------------------------------
//Application related definitions
//------------------------------------------------------------------------------
#define LCD_CHAR_LOCATION_ONE   (uint8_t)1
#define LCD_CHAR_LOCATION_TWO   (uint8_t)2
#define LCD_CHAR_LOCATION_THREE (uint8_t)3
#define LCD_CHAR_LOCATION_FOUR  (uint8_t)4 
#define LCD_CHAR_LOCATION_FIVE  (uint8_t)5

#define TWELVE_HOUR_FORMAT     12
#define TWENTY_FOUR_HOUR_FORMAT 24

#define FAHRENHEIT_RATIO        (double)9/5
#define FAHRENHEIT_CORRECTION_VALUE		(double)0x20

static void LCD_PrintChar(char c, uint8_t location);
static void LCD_PrintCharAlternate(char c, uint8_t location);

static char print_buffer[10];

void LCD_DEMO_PrintPIC24(void) 
{   
    LCD_CLEAR();
    LCD_MICROCHIP1_On();
    
    LCD_CHAR1_Print('P');
    LCD_CHAR2_Print('I');
    LCD_CHAR3_Print('C');
    LCD_CHAR4_Print('2');
    LCD_CHAR5_Print('4');
    
    LCD_CHAR1_AltPrint(' ');
    LCD_CHAR2_AltPrint(' ');
    LCD_CHAR3_AltPrint('L');       //L
    LCD_CHAR4_AltPrint('C');
    LCD_CHAR5_AltPrint('D');
    LCD_ModeSet(LCD_MODE_ALTERNATE);
    LCD_MICROCHIP1_AltOn();
}

void LCD_DEMO_PrintPot(uint16_t value) {
    
    memset(print_buffer, ' ', sizeof (print_buffer));
    sprintf(print_buffer, "%04i", value);
    LCD_CHAR1_Print(print_buffer[0]);
    LCD_CHAR2_Print(print_buffer[1]);
    LCD_CHAR3_Print(print_buffer[2]);
    LCD_CHAR4_Print(print_buffer[3]);
    LCD_CHAR5_Print(' ');
    LCD_ModeSet(LCD_MODE_NORMAL);
}

void LCD_DEMO_PrintTime(uint8_t hour, uint8_t minute) 
{  
    LCD_CLEAR();
    LCD_COLON1_On();
    
    LCD_CHAR1_AltPrint(' ');   // 
    LCD_CHAR2_AltPrint(' ');   // 
    LCD_CHAR3_AltPrint(' ');   // 
    LCD_CHAR4_AltPrint(' ');   // 
    LCD_CHAR5_AltPrint(' '); // 
    
    LCD_MICROCHIP1_AltOff();
    
    memset(print_buffer, ' ', sizeof (print_buffer));
    if(hour > 12)
    {
        hour -= 12;
        LCD_CHAR5_Print('P');
    }
    else if(hour == 0)
    {
        hour = 12;
        LCD_CHAR5_Print('A');
    }
    else if(hour == 12)
    {
        LCD_CHAR5_Print('P');
    }
    else
    {
        LCD_CHAR5_Print('A');
    }
    sprintf(print_buffer, "%2i", hour);
    LCD_CHAR1_Print(print_buffer[0]);
    LCD_CHAR2_Print(print_buffer[1]);
    memset(print_buffer, ' ', sizeof (print_buffer));
    sprintf(print_buffer, "%02i", minute);
    LCD_CHAR3_Print(print_buffer[0]);
    LCD_CHAR4_Print(print_buffer[1]);
    
    LCD_COLON1_AltOn();
    LCD_ModeSet(LCD_COLON_BLINK);
}

void LCD_DEMO_PrintVoltage(double voltage) 
{
	LCD_ModeSet(LCD_MODE_NORMAL);
    
    memset(print_buffer, ' ', sizeof (print_buffer));

    sprintf(print_buffer, "%.3f", voltage);

    LCD_CLEAR();
    LCD_COLON1_Off();
    LCD_DOT1_Off();
    LCD_DOT2_Off();
    LCD_DOT3_Off();
    LCD_DOT4_Off();
    LCD_DOT5_Off();
    LCD_DOT6_Off();

    LCD_CHAR1_Print(print_buffer[0]);
    LCD_DOT1_On();
    LCD_CHAR2_Print(print_buffer[2]);
    LCD_CHAR3_Print(print_buffer[3]);
    LCD_CHAR4_Print(print_buffer[4]);
    LCD_CHAR5_Print('V');
}

void LCD_DEMO_SetBatteryStatus(enum BATTERY_STATUS status) 
{
    switch (status) {
        case BATTERY_STATUS_UNKNOWN:
            BATTERY1_A_Off();
            BATTERY1_B_Off();
            BATTERY1_C_Off();
            BATTERY1_D_Off();
            BATTERY1_A_AltOff();
            break;
            
        case BATTERY_STATUS_FULL:
            BATTERY1_A_On();
            BATTERY1_B_On();
            BATTERY1_C_On();
            BATTERY1_D_On();
            BATTERY1_A_AltOff();
            break;

        case BATTERY_STATUS_MEDIUM:
            BATTERY1_A_On();
            BATTERY1_B_Off();
            BATTERY1_C_On();
            BATTERY1_D_Off();
            BATTERY1_A_AltOff();
            break;

        case BATTERY_STATUS_LOW:
            BATTERY1_A_On();
            BATTERY1_B_Off();
            BATTERY1_C_Off();
            BATTERY1_D_Off();
            BATTERY1_A_AltOff();
            break;

        case BATTERY_STATUS_CRITICAL:
            BATTERY1_A_On();
            BATTERY1_B_Off();
            BATTERY1_C_Off();
            BATTERY1_D_Off();
            BATTERY1_B_AltOn();
            break;
        default:
            break;
    }
}

void LCD_DEMO_PrintTemperature(double temp) 
{
    unsigned int i;
    unsigned int character;

    /* Print the Celsius temperature */
    LCD_COLON1_Off();
    LCD_DOT5_On();
    LCD_DOT2_Off();
    memset(print_buffer, ' ', sizeof (print_buffer));
    sprintf(print_buffer, "%.3f", temp);
    character = 0;
    for (i = 0; i<sizeof (print_buffer); i++) {
        if (print_buffer[i] == '.') {
            switch (character) {
                case 1:
                    LCD_DOT1_On();
                    LCD_DOT2_Off();
                    LCD_DOT3_Off();
                    LCD_DOT4_Off();
                    break;
                case 2:
                    LCD_DOT1_Off();
                    LCD_DOT2_On();
                    LCD_DOT3_Off();
                    LCD_DOT4_Off();
                    break;
                case 3:
                    LCD_DOT1_Off();
                    LCD_DOT2_Off();
                    LCD_DOT3_On();
                    LCD_DOT4_Off();
                    break;
                default:
                    break;
            }
        } else {
            LCD_PrintChar(print_buffer[i], (character + LCD_CHAR_LOCATION_ONE));
            character++;
        }

        if (character >= LCD_CHAR_LOCATION_FOUR) {
            break;
        }
    }
    
    LCD_CHAR5_Print('C');
    
    /* Print the Fahrenheit temperature */
    LCD_COLON1_AltOff();
    LCD_DOT5_AltOff();
    LCD_DOT6_AltOff();
    LCD_MICROCHIP1_AltOn();
    
    /* convert C to F */
    temp = ((temp * FAHRENHEIT_RATIO) + FAHRENHEIT_CORRECTION_VALUE);
            
    memset(print_buffer, ' ', sizeof (print_buffer));

    sprintf(print_buffer, "%.3f", temp);

    character = 0;
    for (i = 0; i<sizeof (print_buffer); i++) {
        if (print_buffer[i] == '.') {
            switch (character) {
                case 1:
                    LCD_DOT1_AltOn();
                    LCD_DOT2_AltOff();
                    LCD_DOT3_AltOff();
                    LCD_DOT4_AltOff();
                    break;
                case 2:
                    LCD_DOT1_AltOff();
                    LCD_DOT2_AltOn();
                    LCD_DOT3_AltOff();
                    LCD_DOT4_AltOff();
                    break;
                case 3:
                    LCD_DOT1_AltOff();
                    LCD_DOT2_AltOff();
                    LCD_DOT3_AltOn();
                    LCD_DOT4_AltOff();
                    break;
                default:
                    break;
            }
        } else {
            LCD_PrintCharAlternate(print_buffer[i], (character + LCD_CHAR_LOCATION_ONE));
            character++;
        }

        if (character >= LCD_CHAR_LOCATION_FOUR) {
            break;
        }
    }
    
    LCD_CHAR5_AltPrint('F');
    LCD_ModeSet(LCD_MODE_ALTERNATE);
}

static void LCD_PrintChar(char data, uint8_t location) 
{
    switch (location) {
        case 1:
            LCD_CHAR1_Print(data);
            break;

        case 2:
            LCD_CHAR2_Print(data);
            break;

        case 3:
            LCD_CHAR3_Print(data);
            break;

        case 4:
            LCD_CHAR4_Print(data);
            break;

        default:
            break;
    }
}

static void LCD_PrintCharAlternate(char data, uint8_t location) 
{
    switch (location) {
        case 1:
            LCD_CHAR1_AltPrint(data);
            break;

        case 2:
            LCD_CHAR2_AltPrint(data);
            break;

        case 3:
            LCD_CHAR3_AltPrint(data);
            break;

        case 4:
            LCD_CHAR4_AltPrint(data);
            break;

        default:
            break;
    }
}

void LCD_CLEAR(void)
{
    LCD_LOW_POWER_Off();
    LCD_LOW_POWER_AltOff();
    BATTERY1_A_Off();
    BATTERY1_B_Off();
    BATTERY1_C_Off();
    BATTERY1_D_Off();
    
    BATTERY1_A_AltOff();
    BATTERY1_B_AltOff();
    BATTERY1_C_AltOff();
    BATTERY1_D_AltOff();
    
    LCD_COLON1_AltOff();
    LCD_COLON1_Off();
    LCD_DOT1_AltOff();
    LCD_DOT2_AltOff();
    LCD_DOT3_AltOff();
    LCD_DOT4_AltOff();
    LCD_DOT5_AltOff();
    LCD_DOT6_AltOff();
    
    LCD_DOT1_Off();
    LCD_DOT2_Off();
    LCD_DOT3_Off();
    LCD_DOT4_Off();
    LCD_DOT5_Off();
    LCD_DOT6_Off();
}