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

#include <stdbool.h>
#include <stdint.h>

enum BATTERY_STATUS
{
    BATTERY_STATUS_FULL,
    BATTERY_STATUS_MEDIUM,
    BATTERY_STATUS_LOW,
    BATTERY_STATUS_CRITICAL,
    BATTERY_STATUS_UNKNOWN
};

/**
  @Summary
    This method prints the potentiometer value on the LCD screen

  @Description
    This method prints the updated potentiometer value on the LCD screen, this 
    method takes the potentiometer value as an input param.

  @Preconditions
    SEG and COM for LCD segment characters has to be pre assigned to display the
    pot values on the LCD screen, This method calls LCD driver method to display
    values on the LCD Screen.
  
  @Returns
    None

  @Param
    Potentiometer value to be printed on the screen
*/
void LCD_DEMO_PrintPot(uint16_t value);
/**
  @Summary
    This method prints the Time value on the LCD screen

  @Description
    This method prints the updated Time value on the LCD screen, this 
    method takes the Time value as hour and minutes as an input

  @Preconditions
    SEG and COM for LCD segment characters has to be pre assigned to display the
    Time value on the LCD screen, This method calls LCD driver method to display
    values on the LCD Screen.
  
 
  @Returns
    None

  @Param
    hour : Hour value to be printed on LCD
    min  : Minute value to be printed on LCD.
*/
void LCD_DEMO_PrintTime(uint8_t hour, uint8_t min);
/**
   @Summary
    This method prints the Temperature value on the LCD screen

  @Description
    This method prints the updated Temperature value on the LCD screen, this 
    method takes the Temperature value in Celsius as an input parameter. This 
    Method prints the temperature value both in Celsius and Fahrenheit in 
    an alternate mode

  @Preconditions
   SEG and COM for LCD segment characters has to be pre assigned to display the
   Temperature values on the LCD screen, This method calls LCD driver method to display
   values on the LCD Screen.
  
  @Returns
    None

  @Param
    Temperature in Celsius value to be printed on the screen
*/
void LCD_DEMO_PrintTemperature(double temp);
/**
  @Summary
    This method sets the Battery icon status on the LCD screen

  @Description
    This method takes the BATTERY_STATUS enum values as an input parameter and
    sets the battery status according to the status on the LCD screen

  @Preconditions
    SEG and COM for LCD segment characters has to be pre assigned to display the
    Battery status the LCD screen, This method calls LCD driver method to display
    values on the LCD Screen.
  
  @Returns
    None

  @Param
    BATTERY_STATUS enum value
*/
void LCD_DEMO_SetBatteryStatus(enum BATTERY_STATUS status);

/**
  @Summary
    This method prints the Voltage value on the LCD screen

  @Description
    This method prints the updated Voltage value on the LCD screen, this 
    method takes the Voltage value in V as an input parameter.

  @Preconditions
   SEG and COM for LCD segment characters has to be pre assigned to display the
   Voltage values on the LCD screen, This method calls LCD driver method to display
   values on the LCD Screen.
  
  @Returns
    None

  @Param
    Voltage in Volts value to be printed on the screen
*/
void LCD_DEMO_PrintVoltage(double voltage);
/*
  @Summary
    This method prints PIC24 and LCD alternately the LCD screen

  @Description
    This method prints PIC24 and LCD alternately the LCD screen

  @Preconditions
   SEG and COM for LCD segment characters has to be pre assigned to display the
   PIC24 and LCD values on the LCD screen, This method calls LCD driver method 
   to display values on the LCD Screen.
  
  @Returns
    None

  @Param
    None
*/
void LCD_DEMO_PrintPIC24(void);

/**
  @Summary
 Clears the LCD screen

  @Description
    This routine clear the LCD Screen

  @Preconditions
    None.

  @Param
   None
 
  @Returns
    None.

  @Example
   None 
*/

void LCD_CLEAR(void);
#endif /* LCD_DEMO_H*/
