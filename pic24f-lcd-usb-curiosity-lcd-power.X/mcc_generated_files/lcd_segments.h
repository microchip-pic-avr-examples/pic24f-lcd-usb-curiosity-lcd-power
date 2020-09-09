/**
  LCD Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    lcd_segments.h

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

#ifndef LCD_SEGMENTS_H
#define LCD_SEGMENTS_H

/**
 Section: Included Files
*/
#include <xc.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
     
/**
 Section: Data Type Definitions
*/

/** LCD Segment Control Definition
 
 @Summary 
   Defines the LCD segment control.
 
 @Description
   This routine defines the LCD segment control.
 
 Remarks:
   None
 */
enum LCD_SEGMENT_CONTROL
{
    LCD_SEGMENT_OFF = 0,
    LCD_SEGMENT_ON = 1
};

/**
  Pixel Assignments
*/        
#define LCD_DOT6_Set(value) LCDDATA31bits.S62C7 = value
#define LCD_DOT6_On() LCDDATA31bits.S62C7 = 1
#define LCD_DOT6_Off() LCDDATA31bits.S62C7 = 0
#define LCD_DOT6_AltSet(value) LCDSDATA31bits.S62C7 = value
#define LCD_DOT6_AltOn() LCDSDATA31bits.S62C7 = 1
#define LCD_DOT6_AltOff() LCDSDATA31bits.S62C7 = 0

#define CHAR5_A_Set(value) LCDDATA7bits.S61C1 = value
#define CHAR5_A_On() LCDDATA7bits.S61C1 = 1
#define CHAR5_A_Off() LCDDATA7bits.S61C1 = 0
#define CHAR5_A_AltSet(value) LCDSDATA7bits.S61C1 = value
#define CHAR5_A_AltOn() LCDSDATA7bits.S61C1 = 1
#define CHAR5_A_AltOff() LCDSDATA7bits.S61C1 = 0

#define CHAR5_B_Set(value) LCDDATA11bits.S62C2 = value
#define CHAR5_B_On() LCDDATA11bits.S62C2 = 1
#define CHAR5_B_Off() LCDDATA11bits.S62C2 = 0
#define CHAR5_B_AltSet(value) LCDSDATA11bits.S62C2 = value
#define CHAR5_B_AltOn() LCDSDATA11bits.S62C2 = 1
#define CHAR5_B_AltOff() LCDSDATA11bits.S62C2 = 0

#define CHAR5_C_Set(value) LCDDATA19bits.S62C4 = value
#define CHAR5_C_On() LCDDATA19bits.S62C4 = 1
#define CHAR5_C_Off() LCDDATA19bits.S62C4 = 0
#define CHAR5_C_AltSet(value) LCDSDATA19bits.S62C4 = value
#define CHAR5_C_AltOn() LCDSDATA19bits.S62C4 = 1
#define CHAR5_C_AltOff() LCDSDATA19bits.S62C4 = 0

#define CHAR5_D_Set(value) LCDDATA27bits.S62C6 = value
#define CHAR5_D_On() LCDDATA27bits.S62C6 = 1
#define CHAR5_D_Off() LCDDATA27bits.S62C6 = 0
#define CHAR5_D_AltSet(value) LCDSDATA27bits.S62C6 = value
#define CHAR5_D_AltOn() LCDSDATA27bits.S62C6 = 1
#define CHAR5_D_AltOff() LCDSDATA27bits.S62C6 = 0

#define CHAR5_E_Set(value) LCDDATA31bits.S61C7 = value
#define CHAR5_E_On() LCDDATA31bits.S61C7 = 1
#define CHAR5_E_Off() LCDDATA31bits.S61C7 = 0
#define CHAR5_E_AltSet(value) LCDSDATA31bits.S61C7 = value
#define CHAR5_E_AltOn() LCDSDATA31bits.S61C7 = 1
#define CHAR5_E_AltOff() LCDSDATA31bits.S61C7 = 0

#define CHAR5_F_Set(value) LCDDATA27bits.S59C6 = value
#define CHAR5_F_On() LCDDATA27bits.S59C6 = 1
#define CHAR5_F_Off() LCDDATA27bits.S59C6 = 0
#define CHAR5_F_AltSet(value) LCDSDATA27bits.S59C6 = value
#define CHAR5_F_AltOn() LCDSDATA27bits.S59C6 = 1
#define CHAR5_F_AltOff() LCDSDATA27bits.S59C6 = 0

#define CHAR5_G_Set(value) LCDDATA19bits.S59C4 = value
#define CHAR5_G_On() LCDDATA19bits.S59C4 = 1
#define CHAR5_G_Off() LCDDATA19bits.S59C4 = 0
#define CHAR5_G_AltSet(value) LCDSDATA19bits.S59C4 = value
#define CHAR5_G_AltOn() LCDSDATA19bits.S59C4 = 1
#define CHAR5_G_AltOff() LCDSDATA19bits.S59C4 = 0

#define CHAR5_H_Set(value) LCDDATA15bits.S59C3 = value
#define CHAR5_H_On() LCDDATA15bits.S59C3 = 1
#define CHAR5_H_Off() LCDDATA15bits.S59C3 = 0
#define CHAR5_H_AltSet(value) LCDSDATA15bits.S59C3 = value
#define CHAR5_H_AltOn() LCDSDATA15bits.S59C3 = 1
#define CHAR5_H_AltOff() LCDSDATA15bits.S59C3 = 0

#define CHAR5_I_Set(value) LCDDATA19bits.S61C4 = value
#define CHAR5_I_On() LCDDATA19bits.S61C4 = 1
#define CHAR5_I_Off() LCDDATA19bits.S61C4 = 0
#define CHAR5_I_AltSet(value) LCDSDATA19bits.S61C4 = value
#define CHAR5_I_AltOn() LCDSDATA19bits.S61C4 = 1
#define CHAR5_I_AltOff() LCDSDATA19bits.S61C4 = 0

#define CHAR5_J_Set(value) LCDDATA23bits.S62C5 = value
#define CHAR5_J_On() LCDDATA23bits.S62C5 = 1
#define CHAR5_J_Off() LCDDATA23bits.S62C5 = 0
#define CHAR5_J_AltSet(value) LCDSDATA23bits.S62C5 = value
#define CHAR5_J_AltOn() LCDSDATA23bits.S62C5 = 1
#define CHAR5_J_AltOff() LCDSDATA23bits.S62C5 = 0

#define CHAR5_K_Set(value) LCDDATA11bits.S61C2 = value
#define CHAR5_K_On() LCDDATA11bits.S61C2 = 1
#define CHAR5_K_Off() LCDDATA11bits.S61C2 = 0
#define CHAR5_K_AltSet(value) LCDSDATA11bits.S61C2 = value
#define CHAR5_K_AltOn() LCDSDATA11bits.S61C2 = 1
#define CHAR5_K_AltOff() LCDSDATA11bits.S61C2 = 0

#define CHAR5_L_Set(value) LCDDATA15bits.S61C3 = value
#define CHAR5_L_On() LCDDATA15bits.S61C3 = 1
#define CHAR5_L_Off() LCDDATA15bits.S61C3 = 0
#define CHAR5_L_AltSet(value) LCDSDATA15bits.S61C3 = value
#define CHAR5_L_AltOn() LCDSDATA15bits.S61C3 = 1
#define CHAR5_L_AltOff() LCDSDATA15bits.S61C3 = 0

#define CHAR5_M_Set(value) LCDDATA15bits.S62C3 = value
#define CHAR5_M_On() LCDDATA15bits.S62C3 = 1
#define CHAR5_M_Off() LCDDATA15bits.S62C3 = 0
#define CHAR5_M_AltSet(value) LCDSDATA15bits.S62C3 = value
#define CHAR5_M_AltOn() LCDSDATA15bits.S62C3 = 1
#define CHAR5_M_AltOff() LCDSDATA15bits.S62C3 = 0

#define CHAR5_N_Set(value) LCDDATA27bits.S61C6 = value
#define CHAR5_N_On() LCDDATA27bits.S61C6 = 1
#define CHAR5_N_Off() LCDDATA27bits.S61C6 = 0
#define CHAR5_N_AltSet(value) LCDSDATA27bits.S61C6 = value
#define CHAR5_N_AltOn() LCDSDATA27bits.S61C6 = 1
#define CHAR5_N_AltOff() LCDSDATA27bits.S61C6 = 0

#define CHAR5_O_Set(value) LCDDATA23bits.S61C5 = value
#define CHAR5_O_On() LCDDATA23bits.S61C5 = 1
#define CHAR5_O_Off() LCDDATA23bits.S61C5 = 0
#define CHAR5_O_AltSet(value) LCDSDATA23bits.S61C5 = value
#define CHAR5_O_AltOn() LCDSDATA23bits.S61C5 = 1
#define CHAR5_O_AltOff() LCDSDATA23bits.S61C5 = 0

#define CHAR5_P_Set(value) LCDDATA23bits.S59C5 = value
#define CHAR5_P_On() LCDDATA23bits.S59C5 = 1
#define CHAR5_P_Off() LCDDATA23bits.S59C5 = 0
#define CHAR5_P_AltSet(value) LCDSDATA23bits.S59C5 = value
#define CHAR5_P_AltOn() LCDSDATA23bits.S59C5 = 1
#define CHAR5_P_AltOff() LCDSDATA23bits.S59C5 = 0

#define LCD_DOT5_Set(value) LCDDATA11bits.S59C2 = value
#define LCD_DOT5_On() LCDDATA11bits.S59C2 = 1
#define LCD_DOT5_Off() LCDDATA11bits.S59C2 = 0
#define LCD_DOT5_AltSet(value) LCDSDATA11bits.S59C2 = value
#define LCD_DOT5_AltOn() LCDSDATA11bits.S59C2 = 1
#define LCD_DOT5_AltOff() LCDSDATA11bits.S59C2 = 0

#define LCD_DOT4_Set(value) LCDDATA31bits.S59C7 = value
#define LCD_DOT4_On() LCDDATA31bits.S59C7 = 1
#define LCD_DOT4_Off() LCDDATA31bits.S59C7 = 0
#define LCD_DOT4_AltSet(value) LCDSDATA31bits.S59C7 = value
#define LCD_DOT4_AltOn() LCDSDATA31bits.S59C7 = 1
#define LCD_DOT4_AltOff() LCDSDATA31bits.S59C7 = 0

#define CHAR4_A_Set(value) LCDDATA3bits.S50C0 = value
#define CHAR4_A_On() LCDDATA3bits.S50C0 = 1
#define CHAR4_A_Off() LCDDATA3bits.S50C0 = 0
#define CHAR4_A_AltSet(value) LCDSDATA3bits.S50C0 = value
#define CHAR4_A_AltOn() LCDSDATA3bits.S50C0 = 1
#define CHAR4_A_AltOff() LCDSDATA3bits.S50C0 = 0

#define CHAR4_B_Set(value) LCDDATA3bits.S58C0 = value
#define CHAR4_B_On() LCDDATA3bits.S58C0 = 1
#define CHAR4_B_Off() LCDDATA3bits.S58C0 = 0
#define CHAR4_B_AltSet(value) LCDSDATA3bits.S58C0 = value
#define CHAR4_B_AltOn() LCDSDATA3bits.S58C0 = 1
#define CHAR4_B_AltOff() LCDSDATA3bits.S58C0 = 0

#define CHAR4_C_Set(value) LCDDATA11bits.S58C2 = value
#define CHAR4_C_On() LCDDATA11bits.S58C2 = 1
#define CHAR4_C_Off() LCDDATA11bits.S58C2 = 0
#define CHAR4_C_AltSet(value) LCDSDATA11bits.S58C2 = value
#define CHAR4_C_AltOn() LCDSDATA11bits.S58C2 = 1
#define CHAR4_C_AltOff() LCDSDATA11bits.S58C2 = 0

#define CHAR4_D_Set(value) LCDDATA15bits.S58C3 = value
#define CHAR4_D_On() LCDDATA15bits.S58C3 = 1
#define CHAR4_D_Off() LCDDATA15bits.S58C3 = 0
#define CHAR4_D_AltSet(value) LCDSDATA15bits.S58C3 = value
#define CHAR4_D_AltOn() LCDSDATA15bits.S58C3 = 1
#define CHAR4_D_AltOff() LCDSDATA15bits.S58C3 = 0

#define CHAR4_E_Set(value) LCDDATA11bits.S50C2 = value
#define CHAR4_E_On() LCDDATA11bits.S50C2 = 1
#define CHAR4_E_Off() LCDDATA11bits.S50C2 = 0
#define CHAR4_E_AltSet(value) LCDSDATA11bits.S50C2 = value
#define CHAR4_E_AltOn() LCDSDATA11bits.S50C2 = 1
#define CHAR4_E_AltOff() LCDSDATA11bits.S50C2 = 0

#define CHAR4_F_Set(value) LCDDATA7bits.S50C1 = value
#define CHAR4_F_On() LCDDATA7bits.S50C1 = 1
#define CHAR4_F_Off() LCDDATA7bits.S50C1 = 0
#define CHAR4_F_AltSet(value) LCDSDATA7bits.S50C1 = value
#define CHAR4_F_AltOn() LCDSDATA7bits.S50C1 = 1
#define CHAR4_F_AltOff() LCDSDATA7bits.S50C1 = 0

#define CHAR4_G_Set(value) LCDDATA7bits.S58C1 = value
#define CHAR4_G_On() LCDDATA7bits.S58C1 = 1
#define CHAR4_G_Off() LCDDATA7bits.S58C1 = 0
#define CHAR4_G_AltSet(value) LCDSDATA7bits.S58C1 = value
#define CHAR4_G_AltOn() LCDSDATA7bits.S58C1 = 1
#define CHAR4_G_AltOff() LCDSDATA7bits.S58C1 = 0

#define LCD_DOT3_Set(value) LCDDATA15bits.S50C3 = value
#define LCD_DOT3_On() LCDDATA15bits.S50C3 = 1
#define LCD_DOT3_Off() LCDDATA15bits.S50C3 = 0
#define LCD_DOT3_AltSet(value) LCDSDATA15bits.S50C3 = value
#define LCD_DOT3_AltOn() LCDSDATA15bits.S50C3 = 1
#define LCD_DOT3_AltOff() LCDSDATA15bits.S50C3 = 0

#define CHAR1_A_Set(value) LCDDATA1bits.S27C0 = value
#define CHAR1_A_On() LCDDATA1bits.S27C0 = 1
#define CHAR1_A_Off() LCDDATA1bits.S27C0 = 0
#define CHAR1_A_AltSet(value) LCDSDATA1bits.S27C0 = value
#define CHAR1_A_AltOn() LCDSDATA1bits.S27C0 = 1
#define CHAR1_A_AltOff() LCDSDATA1bits.S27C0 = 0

#define CHAR1_B_Set(value) LCDDATA2bits.S46C0 = value
#define CHAR1_B_On() LCDDATA2bits.S46C0 = 1
#define CHAR1_B_Off() LCDDATA2bits.S46C0 = 0
#define CHAR1_B_AltSet(value) LCDSDATA2bits.S46C0 = value
#define CHAR1_B_AltOn() LCDSDATA2bits.S46C0 = 1
#define CHAR1_B_AltOff() LCDSDATA2bits.S46C0 = 0

#define CHAR1_C_Set(value) LCDDATA10bits.S46C2 = value
#define CHAR1_C_On() LCDDATA10bits.S46C2 = 1
#define CHAR1_C_Off() LCDDATA10bits.S46C2 = 0
#define CHAR1_C_AltSet(value) LCDSDATA10bits.S46C2 = value
#define CHAR1_C_AltOn() LCDSDATA10bits.S46C2 = 1
#define CHAR1_C_AltOff() LCDSDATA10bits.S46C2 = 0

#define CHAR1_D_Set(value) LCDDATA13bits.S27C3 = value
#define CHAR1_D_On() LCDDATA13bits.S27C3 = 1
#define CHAR1_D_Off() LCDDATA13bits.S27C3 = 0
#define CHAR1_D_AltSet(value) LCDSDATA13bits.S27C3 = value
#define CHAR1_D_AltOn() LCDSDATA13bits.S27C3 = 1
#define CHAR1_D_AltOff() LCDSDATA13bits.S27C3 = 0

#define CHAR1_E_Set(value) LCDDATA9bits.S27C2 = value
#define CHAR1_E_On() LCDDATA9bits.S27C2 = 1
#define CHAR1_E_Off() LCDDATA9bits.S27C2 = 0
#define CHAR1_E_AltSet(value) LCDSDATA9bits.S27C2 = value
#define CHAR1_E_AltOn() LCDSDATA9bits.S27C2 = 1
#define CHAR1_E_AltOff() LCDSDATA9bits.S27C2 = 0

#define CHAR1_F_Set(value) LCDDATA5bits.S27C1 = value
#define CHAR1_F_On() LCDDATA5bits.S27C1 = 1
#define CHAR1_F_Off() LCDDATA5bits.S27C1 = 0
#define CHAR1_F_AltSet(value) LCDSDATA5bits.S27C1 = value
#define CHAR1_F_AltOn() LCDSDATA5bits.S27C1 = 1
#define CHAR1_F_AltOff() LCDSDATA5bits.S27C1 = 0

#define CHAR1_G_Set(value) LCDDATA6bits.S46C1 = value
#define CHAR1_G_On() LCDDATA6bits.S46C1 = 1
#define CHAR1_G_Off() LCDDATA6bits.S46C1 = 0
#define CHAR1_G_AltSet(value) LCDSDATA6bits.S46C1 = value
#define CHAR1_G_AltOn() LCDSDATA6bits.S46C1 = 1
#define CHAR1_G_AltOff() LCDSDATA6bits.S46C1 = 0

#define LCD_DOT2_Set(value) LCDDATA30bits.S46C7 = value
#define LCD_DOT2_On() LCDDATA30bits.S46C7 = 1
#define LCD_DOT2_Off() LCDDATA30bits.S46C7 = 0
#define LCD_DOT2_AltSet(value) LCDSDATA30bits.S46C7 = value
#define LCD_DOT2_AltOn() LCDSDATA30bits.S46C7 = 1
#define LCD_DOT2_AltOff() LCDSDATA30bits.S46C7 = 0

#define LCD_DOT1_Set(value) LCDDATA14bits.S46C3 = value
#define LCD_DOT1_On() LCDDATA14bits.S46C3 = 1
#define LCD_DOT1_Off() LCDDATA14bits.S46C3 = 0
#define LCD_DOT1_AltSet(value) LCDSDATA14bits.S46C3 = value
#define LCD_DOT1_AltOn() LCDSDATA14bits.S46C3 = 1
#define LCD_DOT1_AltOff() LCDSDATA14bits.S46C3 = 0

#define LCD_MICROCHIP1_Set(value) LCDDATA7bits.S59C1 = value
#define LCD_MICROCHIP1_On() LCDDATA7bits.S59C1 = 1
#define LCD_MICROCHIP1_Off() LCDDATA7bits.S59C1 = 0
#define LCD_MICROCHIP1_AltSet(value) LCDSDATA7bits.S59C1 = value
#define LCD_MICROCHIP1_AltOn() LCDSDATA7bits.S59C1 = 1
#define LCD_MICROCHIP1_AltOff() LCDSDATA7bits.S59C1 = 0

#define LCD_COLON1_Set(value) LCDDATA31bits.S50C7 = value
#define LCD_COLON1_On() LCDDATA31bits.S50C7 = 1
#define LCD_COLON1_Off() LCDDATA31bits.S50C7 = 0
#define LCD_COLON1_AltSet(value) LCDSDATA31bits.S50C7 = value
#define LCD_COLON1_AltOn() LCDSDATA31bits.S50C7 = 1
#define LCD_COLON1_AltOff() LCDSDATA31bits.S50C7 = 0

#define CHAR3_A_Set(value) LCDDATA19bits.S50C4 = value
#define CHAR3_A_On() LCDDATA19bits.S50C4 = 1
#define CHAR3_A_Off() LCDDATA19bits.S50C4 = 0
#define CHAR3_A_AltSet(value) LCDSDATA19bits.S50C4 = value
#define CHAR3_A_AltOn() LCDSDATA19bits.S50C4 = 1
#define CHAR3_A_AltOff() LCDSDATA19bits.S50C4 = 0

#define CHAR3_B_Set(value) LCDDATA19bits.S58C4 = value
#define CHAR3_B_On() LCDDATA19bits.S58C4 = 1
#define CHAR3_B_Off() LCDDATA19bits.S58C4 = 0
#define CHAR3_B_AltSet(value) LCDSDATA19bits.S58C4 = value
#define CHAR3_B_AltOn() LCDSDATA19bits.S58C4 = 1
#define CHAR3_B_AltOff() LCDSDATA19bits.S58C4 = 0

#define CHAR3_C_Set(value) LCDDATA27bits.S58C6 = value
#define CHAR3_C_On() LCDDATA27bits.S58C6 = 1
#define CHAR3_C_Off() LCDDATA27bits.S58C6 = 0
#define CHAR3_C_AltSet(value) LCDSDATA27bits.S58C6 = value
#define CHAR3_C_AltOn() LCDSDATA27bits.S58C6 = 1
#define CHAR3_C_AltOff() LCDSDATA27bits.S58C6 = 0

#define CHAR3_D_Set(value) LCDDATA31bits.S58C7 = value
#define CHAR3_D_On() LCDDATA31bits.S58C7 = 1
#define CHAR3_D_Off() LCDDATA31bits.S58C7 = 0
#define CHAR3_D_AltSet(value) LCDSDATA31bits.S58C7 = value
#define CHAR3_D_AltOn() LCDSDATA31bits.S58C7 = 1
#define CHAR3_D_AltOff() LCDSDATA31bits.S58C7 = 0

#define CHAR3_E_Set(value) LCDDATA27bits.S50C6 = value
#define CHAR3_E_On() LCDDATA27bits.S50C6 = 1
#define CHAR3_E_Off() LCDDATA27bits.S50C6 = 0
#define CHAR3_E_AltSet(value) LCDSDATA27bits.S50C6 = value
#define CHAR3_E_AltOn() LCDSDATA27bits.S50C6 = 1
#define CHAR3_E_AltOff() LCDSDATA27bits.S50C6 = 0

#define CHAR3_F_Set(value) LCDDATA23bits.S50C5 = value
#define CHAR3_F_On() LCDDATA23bits.S50C5 = 1
#define CHAR3_F_Off() LCDDATA23bits.S50C5 = 0
#define CHAR3_F_AltSet(value) LCDSDATA23bits.S50C5 = value
#define CHAR3_F_AltOn() LCDSDATA23bits.S50C5 = 1
#define CHAR3_F_AltOff() LCDSDATA23bits.S50C5 = 0

#define CHAR3_G_Set(value) LCDDATA23bits.S58C5 = value
#define CHAR3_G_On() LCDDATA23bits.S58C5 = 1
#define CHAR3_G_Off() LCDDATA23bits.S58C5 = 0
#define CHAR3_G_AltSet(value) LCDSDATA23bits.S58C5 = value
#define CHAR3_G_AltOn() LCDSDATA23bits.S58C5 = 1
#define CHAR3_G_AltOff() LCDSDATA23bits.S58C5 = 0

#define LCD_LOW_POWER_Set(value) LCDDATA7bits.S62C1 = value
#define LCD_LOW_POWER_On() LCDDATA7bits.S62C1 = 1
#define LCD_LOW_POWER_Off() LCDDATA7bits.S62C1 = 0
#define LCD_LOW_POWER_AltSet(value) LCDSDATA7bits.S62C1 = value
#define LCD_LOW_POWER_AltOn() LCDSDATA7bits.S62C1 = 1
#define LCD_LOW_POWER_AltOff() LCDSDATA7bits.S62C1 = 0

#define CHAR2_A_Set(value) LCDDATA17bits.S27C4 = value
#define CHAR2_A_On() LCDDATA17bits.S27C4 = 1
#define CHAR2_A_Off() LCDDATA17bits.S27C4 = 0
#define CHAR2_A_AltSet(value) LCDSDATA17bits.S27C4 = value
#define CHAR2_A_AltOn() LCDSDATA17bits.S27C4 = 1
#define CHAR2_A_AltOff() LCDSDATA17bits.S27C4 = 0

#define CHAR2_B_Set(value) LCDDATA18bits.S46C4 = value
#define CHAR2_B_On() LCDDATA18bits.S46C4 = 1
#define CHAR2_B_Off() LCDDATA18bits.S46C4 = 0
#define CHAR2_B_AltSet(value) LCDSDATA18bits.S46C4 = value
#define CHAR2_B_AltOn() LCDSDATA18bits.S46C4 = 1
#define CHAR2_B_AltOff() LCDSDATA18bits.S46C4 = 0

#define CHAR2_C_Set(value) LCDDATA26bits.S46C6 = value
#define CHAR2_C_On() LCDDATA26bits.S46C6 = 1
#define CHAR2_C_Off() LCDDATA26bits.S46C6 = 0
#define CHAR2_C_AltSet(value) LCDSDATA26bits.S46C6 = value
#define CHAR2_C_AltOn() LCDSDATA26bits.S46C6 = 1
#define CHAR2_C_AltOff() LCDSDATA26bits.S46C6 = 0

#define CHAR2_D_Set(value) LCDDATA29bits.S27C7 = value
#define CHAR2_D_On() LCDDATA29bits.S27C7 = 1
#define CHAR2_D_Off() LCDDATA29bits.S27C7 = 0
#define CHAR2_D_AltSet(value) LCDSDATA29bits.S27C7 = value
#define CHAR2_D_AltOn() LCDSDATA29bits.S27C7 = 1
#define CHAR2_D_AltOff() LCDSDATA29bits.S27C7 = 0

#define CHAR2_E_Set(value) LCDDATA25bits.S27C6 = value
#define CHAR2_E_On() LCDDATA25bits.S27C6 = 1
#define CHAR2_E_Off() LCDDATA25bits.S27C6 = 0
#define CHAR2_E_AltSet(value) LCDSDATA25bits.S27C6 = value
#define CHAR2_E_AltOn() LCDSDATA25bits.S27C6 = 1
#define CHAR2_E_AltOff() LCDSDATA25bits.S27C6 = 0

#define CHAR2_F_Set(value) LCDDATA21bits.S27C5 = value
#define CHAR2_F_On() LCDDATA21bits.S27C5 = 1
#define CHAR2_F_Off() LCDDATA21bits.S27C5 = 0
#define CHAR2_F_AltSet(value) LCDSDATA21bits.S27C5 = value
#define CHAR2_F_AltOn() LCDSDATA21bits.S27C5 = 1
#define CHAR2_F_AltOff() LCDSDATA21bits.S27C5 = 0

#define CHAR2_G_Set(value) LCDDATA22bits.S46C5 = value
#define CHAR2_G_On() LCDDATA22bits.S46C5 = 1
#define CHAR2_G_Off() LCDDATA22bits.S46C5 = 0
#define CHAR2_G_AltSet(value) LCDSDATA22bits.S46C5 = value
#define CHAR2_G_AltOn() LCDSDATA22bits.S46C5 = 1
#define CHAR2_G_AltOff() LCDSDATA22bits.S46C5 = 0

#define BATTERY1_A_Set(value) LCDDATA3bits.S62C0 = value
#define BATTERY1_A_On() LCDDATA3bits.S62C0 = 1
#define BATTERY1_A_Off() LCDDATA3bits.S62C0 = 0
#define BATTERY1_A_AltSet(value) LCDSDATA3bits.S62C0 = value
#define BATTERY1_A_AltOn() LCDSDATA3bits.S62C0 = 1
#define BATTERY1_A_AltOff() LCDSDATA3bits.S62C0 = 0

#define BATTERY1_B_Set(value) LCDDATA3bits.S61C0 = value
#define BATTERY1_B_On() LCDDATA3bits.S61C0 = 1
#define BATTERY1_B_Off() LCDDATA3bits.S61C0 = 0
#define BATTERY1_B_AltSet(value) LCDSDATA3bits.S61C0 = value
#define BATTERY1_B_AltOn() LCDSDATA3bits.S61C0 = 1
#define BATTERY1_B_AltOff() LCDSDATA3bits.S61C0 = 0

#define BATTERY1_C_Set(value) LCDDATA3bits.S59C0 = value
#define BATTERY1_C_On() LCDDATA3bits.S59C0 = 1
#define BATTERY1_C_Off() LCDDATA3bits.S59C0 = 0
#define BATTERY1_C_AltSet(value) LCDSDATA3bits.S59C0 = value
#define BATTERY1_C_AltOn() LCDSDATA3bits.S59C0 = 1
#define BATTERY1_C_AltOff() LCDSDATA3bits.S59C0 = 0

#define BATTERY1_D_Set(value) LCDDATA12bits.S03C3 = value
#define BATTERY1_D_On() LCDDATA12bits.S03C3 = 1
#define BATTERY1_D_Off() LCDDATA12bits.S03C3 = 0
#define BATTERY1_D_AltSet(value) LCDSDATA12bits.S03C3 = value
#define BATTERY1_D_AltOn() LCDSDATA12bits.S03C3 = 1
#define BATTERY1_D_AltOff() LCDSDATA12bits.S03C3 = 0


#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif //LCD_SEGMENTS_H



