/**
  LCD Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    lcd.h

  @Summary
    This is the generated header file for the LCD driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides APIs for driver for LCD.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.169.0
        Device            :  PIC24FJ512GU410
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.50
        MPLAB 	          :  MPLAB X v5.40
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#ifndef LCD_H
#define LCD_H

/**
 Section: Included Files
*/
#include "lcd_7seg.h"
#include "lcd_16seg.h"
#include "lcd_segments.h"

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
     
/**
 Section: Data Type Definitions
*/

/** LCD Operating Mode Definition
 
 @Summary 
   Defines the LCD operating mode.
 
 @Description
   This routine defines the LCD operating mode.
 
 Remarks:
   None
 */
enum LCD_MODE
{
    LCD_MODE_NORMAL,
    LCD_BLINK_PRIMARY_MEMORY,
    LCD_BLINK_SECONDARY_MEMORY_2,
    LCD_MODE_ALTERNATE,
    LCD_COLON_BLINK,
};

/** LCD Power Mode Definition
 
 @Summary 
   Defines the LCD power mode for reference ladder.
 
 @Description
   This routine defines the LCD power mode for reference ladder.
 
 Remarks:
   None
 */
enum LCD_POWER_MODE
{
    LCD_POWER_MODE_OFF = 0,
    LCD_POWER_MODE_LOW = 1,
    LCD_POWER_MODE_MEDIUM = 2,
    LCD_POWER_MODE_HIGH = 3
};

/**
 Section: Interface Routines
*/

/**
  @Summary
    Initializes the LCD module

  @Description
    This routine initializes the LCD module. This routine should only be called 
    once during system initialization.    

  @Preconditions
    None.

  @Param
    None.

  @Returns
    None.

  @Example
    <code>
    LCD_Initialize();
    </code>     
*/
void LCD_Initialize(void);

/**
  @Summary
    Sets LCD module power mode.
 
  @Description
    This routine sets the LCD module reference ladder
    power control.
 
  @Preconditions
    None.
 
  @Param
    powerMode   -   Power mode value for reference ladder.
 
  @Returns
    None.
 
  @Example
    <code>
    LCD_SetPowerMode (powerMode);
    </code>    
*/
void LCD_SetPowerMode (enum LCD_POWER_MODE powerMode);

/**
  @Summary
    Sets the operating mode for LCD module.

  @Description
    This routine sets the operating mode for LCD module.

  @Preconditions
    None.

  @Param
    mode -   Operating mode to be set for the LCD module.

  @Returns
    None.

  @Example
    <code>
    LCD_ModeSet(enum LCD_MODE mode);
    </code>     
*/
void LCD_ModeSet(enum LCD_MODE mode);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif //LCD_H



