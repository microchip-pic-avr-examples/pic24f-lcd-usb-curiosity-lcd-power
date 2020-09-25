/**
  LCD Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    lcd.c

  @Summary
    This is the generated driver implementation file for the LCD driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This source file provides APIs for LCD.
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

/**
  Section: Included Files
*/
#include <xc.h>
#include "lcd.h"

/**
 Section: Driver Interface Function Definitions
*/

void LCD_Initialize()
{

    // Disable LCD module before configuring
    LCDCONbits.LCDEN = 0;

    //BIASMD 1/3 Bias mode; LP 1:1; WFT Type-A waveform; 
    LCDPS = 0x00;	
    //LRLAP High-Power mode; LRLBP High-Power mode; VLCD1PE Bias 1 level is internal; LCDCST Max contrast (Min Resistance); VLCD2PE Bias 2 level is internal; VLCD3PE Bias 3 level is internal; LRLAT Internal LCD reference ladder is always in B Power mode; LCDIRE enabled; 
    LCDREF = 0x80F0;	
    //CPEN disabled; CLKSEL disabled; 
    LCDREG = 0x00;	
    //SE04 disabled; SE15 disabled; SE05 disabled; SE02 disabled; SE13 disabled; SE03 enabled; SE14 disabled; SE00 disabled; SE11 disabled; SE01 disabled; SE12 disabled; SE10 disabled; SE08 disabled; SE09 disabled; SE06 disabled; SE07 disabled; 
    LCDSE0 = 0x08;	
    //SE30 disabled; SE26 disabled; SE16 disabled; SE27 enabled; SE24 disabled; SE25 disabled; SE22 disabled; SE23 disabled; SE20 disabled; SE31 disabled; SE21 disabled; SE19 disabled; SE17 disabled; SE18 disabled; SE29 disabled; 
    LCDSE1 = 0x800;	
    //SE40 disabled; SE41 disabled; SE37 disabled; SE38 disabled; SE35 disabled; SE46 enabled; SE36 disabled; SE33 disabled; SE44 disabled; SE34 disabled; SE45 disabled; SE42 disabled; SE32 disabled; SE43 disabled; SE39 disabled; 
    LCDSE2 = 0x4000;	
    //SE51 disabled; SE62 enabled; SE52 disabled; SE63 disabled; SE60 disabled; SE50 enabled; SE61 enabled; SE48 disabled; SE59 enabled; SE49 disabled; SE57 disabled; SE58 enabled; SE55 disabled; SE56 disabled; SE53 disabled; SE54 disabled; 
    LCDSE3 = 0x6C04;	
    //CS LPRC; SLPEN enabled; WERR disabled; LMUX 1/8 COM[7:0]; LCDSIDL continues to operate in CPU Idle mode; LCDEN disabled; 
    LCDCON = 0x0F;	

    //Enable memory clear
    LCDASTATbits.PMCLEAR = 1;
    LCDASTATbits.SMCLEAR = 1;

    //Disable memory clear
    LCDASTATbits.PMCLEAR = 0;
    LCDASTATbits.SMCLEAR = 0;

    //Enable secondary memory
    LCDASTATbits.SMEMEN = 1;

    // Enable LCD module
    LCDCONbits.LCDEN = 1;
}

void LCD_SetPowerMode(enum LCD_POWER_MODE powerMode)
{
    LCDREFbits.LRLBP = powerMode;
}

void LCD_ModeSet(enum LCD_MODE mode)
{
    switch(mode)
    {
        case LCD_MODE_NORMAL:
                    LCDACTRLbits.ELCDEN = 0;//Disable LCD enhanced Mode
                    break;

        //Blink All Pixels in Primary Memory            
        case LCD_BLINK_PRIMARY_MEMORY:
                    LCDACTRLbits.BLINKMODE = 0x0002;//Enable Blink Mode with all pixels
                    LCDASTATbits.DMSEL = 0x0000;//Primary memory as Display Memory 
                    LCDACTRLbits.BLINKFCS= 0x0001;
                    LCDFC1 = 0x0975;
                    LCDACTRLbits.ELCDEN = 1;//Enable LCD enhanced Mode
                    break;

        //Blink All Pixels in Secondary Memory
        case LCD_BLINK_SECONDARY_MEMORY_2:
                    LCDACTRLbits.BLINKMODE = 0x0002;//Enable Blink Mode with all pixels
                    LCDASTATbits.DMSEL = 0x0001;//Secondary memory as Display Memory 
                    LCDACTRLbits.BLINKFCS= 0x0001;
                    LCDFC1 = 0x0975;
                    LCDACTRLbits.ELCDEN = 1;//Enable LCD enhanced Mode
                    break;

        //Alternate With Continuous Switch Over 
        case LCD_MODE_ALTERNATE:
                    LCDACTRLbits.BLINKMODE = 0x0000;//Disable Blink Mode
                    LCDASTATbits.DMSEL = 0x0003;//Continuous switch over between primary and secondary memory
                    LCDACTRLbits.SMFCS = 0x0001;
                    LCDFC0 = 0x0975;
                    LCDACTRLbits.ELCDEN = 1;//Enable LCD enhanced Mode
                    break;

        //Blink Selected Pixels in Secondary Memory
        case LCD_COLON_BLINK:
                    LCDACTRLbits.BLINKMODE = 0x0001;//Enable Blink Mode with selected pixels
                    LCDASTATbits.DMSEL = 0x0000;//Primary memory as Display Memory 
                    LCDACTRLbits.BLINKFCS= 0x0001;
                    LCDFC1 = 0x0975;
                    LCDACTRLbits.ELCDEN = 1;//Enable LCD enhanced Mode
                    break;

        default:
                    break;
    }
}

