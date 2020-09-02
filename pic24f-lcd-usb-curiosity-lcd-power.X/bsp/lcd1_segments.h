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

#ifndef LCD1_SEGMENTS_H
#define LCD1_SEGMENTS_H

#include <xc.h>

enum LCD1_SEGMENT_CONTROL
{
    LCD1_SEGMENT_OFF = 0,
    LCD1_SEGMENT_ON = 1
};

#define    LCD1_PeriodIcon1_Set(value) LCDDATA14bits.S46C3 = value
#define    LCD1_PeriodIcon1_On() LCDDATA14bits.S46C3 = 1
#define    LCD1_PeriodIcon1_Off() LCDDATA14bits.S46C3 = 0
#define    LCD1_PeriodIcon1_AltSet(value) LCDSDATA14bits.S46C3 = value
#define    LCD1_PeriodIcon1_AltOn() LCDSDATA14bits.S46C3 = 1
#define    LCD1_PeriodIcon1_AltOff() LCDSDATA14bits.S46C3 = 0

#define    LCD1_PeriodIcon2_Set(value) LCDDATA30bits.S46C7 = value
#define    LCD1_PeriodIcon2_On() LCDDATA30bits.S46C7 = 1
#define    LCD1_PeriodIcon2_Off() LCDDATA30bits.S46C7 = 0
#define    LCD1_PeriodIcon2_AltSet(value) LCDSDATA30bits.S46C7 = value
#define    LCD1_PeriodIcon2_AltOn() LCDSDATA30bits.S46C7 = 1
#define    LCD1_PeriodIcon2_AltOff() LCDSDATA30bits.S46C7 = 0

#define    LCD1_PeriodIcon3_Set(value) LCDDATA15bits.S50C3 = value
#define    LCD1_PeriodIcon3_On() LCDDATA15bits.S50C3 = 1
#define    LCD1_PeriodIcon3_Off() LCDDATA15bits.S50C3 = 0
#define    LCD1_PeriodIcon3_AltSet(value) LCDSDATA15bits.S50C3 = value
#define    LCD1_PeriodIcon3_AltOn() LCDSDATA15bits.S50C3 = 1
#define    LCD1_PeriodIcon3_AltOff() LCDSDATA15bits.S50C3 = 0

#define    LCD1_PeriodIcon4_Set(value) LCDDATA31bits.S59C7 = value
#define    LCD1_PeriodIcon4_On() LCDDATA31bits.S59C7 = 1
#define    LCD1_PeriodIcon4_Off() LCDDATA31bits.S59C7 = 0
#define    LCD1_PeriodIcon4_AltSet(value) LCDSDATA31bits.S59C7 = value
#define    LCD1_PeriodIcon4_AltOn() LCDSDATA31bits.S59C7 = 1
#define    LCD1_PeriodIcon4_AltOff() LCDSDATA31bits.S59C7 = 0

#define    LCD1_PeriodIcon5_Set(value) LCDDATA11bits.S59C2 = value
#define    LCD1_PeriodIcon5_On() LCDDATA11bits.S59C2 = 1
#define    LCD1_PeriodIcon5_Off() LCDDATA11bits.S59C2 = 0
#define    LCD1_PeriodIcon5_AltSet(value) LCDSDATA11bits.S59C2 = value
#define    LCD1_PeriodIcon5_AltOn() LCDSDATA11bits.S59C2 = 1
#define    LCD1_PeriodIcon5_AltOff() LCDSDATA11bits.S59C2 = 0

#define    LCD1_PeriodIcon6_Set(value) LCDDATA31bits.S62C7 = value
#define    LCD1_PeriodIcon6_On() LCDDATA31bits.S62C7 = 1
#define    LCD1_PeriodIcon6_Off() LCDDATA31bits.S62C7 = 0
#define    LCD1_PeriodIcon6_AltSet(value) LCDSDATA31bits.S62C7 = value
#define    LCD1_PeriodIcon6_AltOn() LCDSDATA31bits.S62C7 = 1
#define    LCD1_PeriodIcon6_AltOff() LCDSDATA31bits.S62C7 = 0

#define    LCD1_Colon_Set(value) LCDDATA31bits.S50C7 = value
#define    LCD1_Colon_On() LCDDATA31bits.S50C7 = 1
#define    LCD1_Colon_Off() LCDDATA31bits.S50C7 = 0
#define    LCD1_Colon_AltSet(value) LCDSDATA31bits.S50C7 = value
#define    LCD1_Colon_AltOn() LCDSDATA31bits.S50C7 = 1
#define    LCD1_Colon_AltOff() LCDSDATA31bits.S50C7 = 0

#define    LCD1_Logos_Set(value) LCDDATA7bits.S59C1 = value
#define    LCD1_Logos_On() LCDDATA7bits.S59C1 = 1
#define    LCD1_Logos_Off() LCDDATA7bits.S59C1 = 0
#define    LCD1_Logos_AltSet(value) LCDSDATA7bits.S59C1 = value
#define    LCD1_Logos_AltOn() LCDSDATA7bits.S59C1 = 1
#define    LCD1_Logos_AltOff() LCDSDATA7bits.S59C1 = 0

#define    LCD1_BatteryBarLow_Set(value) LCDDATA3bits.S62C0 = value
#define    LCD1_BatteryBarLow_On() LCDDATA3bits.S62C0 = 1
#define    LCD1_BatteryBarLow_Off() LCDDATA3bits.S62C0 = 0
#define    LCD1_BatteryBarLow_AltSet(value) LCDSDATA3bits.S62C0 = value
#define    LCD1_BatteryBarLow_AltOn() LCDSDATA3bits.S62C0 = 1
#define    LCD1_BatteryBarLow_AltOff() LCDSDATA3bits.S62C0 = 0

#define    LCD1_BatteryBarMiddle_Set(value) LCDDATA3bits.S59C0 = value
#define    LCD1_BatteryBarMiddle_On() LCDDATA3bits.S59C0 = 1
#define    LCD1_BatteryBarMiddle_Off() LCDDATA3bits.S59C0 = 0
#define    LCD1_BatteryBarMiddle_AltSet(value) LCDSDATA3bits.S59C0 = value
#define    LCD1_BatteryBarMiddle_AltOn() LCDSDATA3bits.S59C0 = 1
#define    LCD1_BatteryBarMiddle_AltOff() LCDSDATA3bits.S59C0 = 0

#define    LCD1_BatteryBarHigh_Set(value) LCDDATA3bits.S61C0 = value
#define    LCD1_BatteryBarHigh_On() LCDDATA3bits.S61C0 = 1
#define    LCD1_BatteryBarHigh_Off() LCDDATA3bits.S61C0 = 0
#define    LCD1_BatteryBarHigh_AltSet(value) LCDSDATA3bits.S61C0 = value
#define    LCD1_BatteryBarHigh_AltOn() LCDSDATA3bits.S61C0 = 1
#define    LCD1_BatteryBarHigh_AltOff() LCDSDATA3bits.S61C0 = 0

#define    LCD1_MoonIcon_Set(value) LCDDATA7bits.S62C1 = value
#define    LCD1_MoonIcon_On() LCDDATA7bits.S62C1 = 1
#define    LCD1_MoonIcon_Off() LCDDATA7bits.S62C1 = 0
#define    LCD1_MoonIcon_AltSet(value) LCDSDATA7bits.S62C1 = value
#define    LCD1_MoonIcon_AltOn() LCDSDATA7bits.S62C1 = 1
#define    LCD1_MoonIcon_AltOff() LCDSDATA7bits.S62C1 = 0

#define    LCD1_Char1A_Set(value) LCDDATA1bits.S27C0 = value
#define    LCD1_Char1A_On() LCDDATA1bits.S27C0 = 1
#define    LCD1_Char1A_Off() LCDDATA1bits.S27C0 = 0
#define    LCD1_Char1A_AltSet(value) LCDSDATA1bits.S27C0 = value
#define    LCD1_Char1A_AltOn() LCDSDATA1bits.S27C0 = 1
#define    LCD1_Char1A_AltOff() LCDSDATA1bits.S27C0 = 0

#define    LCD1_Char1B_Set(value) LCDDATA2bits.S46C0 = value
#define    LCD1_Char1B_On() LCDDATA2bits.S46C0 = 1
#define    LCD1_Char1B_Off() LCDDATA2bits.S46C0 = 0
#define    LCD1_Char1B_AltSet(value) LCDSDATA2bits.S46C0 = value
#define    LCD1_Char1B_AltOn() LCDSDATA2bits.S46C0 = 1
#define    LCD1_Char1B_AltOff() LCDSDATA2bits.S46C0 = 0

#define    LCD1_Char1C_Set(value) LCDDATA10bits.S46C2 = value
#define    LCD1_Char1C_On() LCDDATA10bits.S46C2 = 1
#define    LCD1_Char1C_Off() LCDDATA10bits.S46C2 = 0
#define    LCD1_Char1C_AltSet(value) LCDSDATA10bits.S46C2 = value
#define    LCD1_Char1C_AltOn() LCDSDATA10bits.S46C2 = 1
#define    LCD1_Char1C_AltOff() LCDSDATA10bits.S46C2 = 0

#define    LCD1_Char1D_Set(value) LCDDATA13bits.S27C3 = value
#define    LCD1_Char1D_On() LCDDATA13bits.S27C3 = 1
#define    LCD1_Char1D_Off() LCDDATA13bits.S27C3 = 0
#define    LCD1_Char1D_AltSet(value) LCDSDATA13bits.S27C3 = value
#define    LCD1_Char1D_AltOn() LCDSDATA13bits.S27C3 = 1
#define    LCD1_Char1D_AltOff() LCDSDATA13bits.S27C3 = 0

#define    LCD1_Char1E_Set(value) LCDDATA9bits.S27C2 = value
#define    LCD1_Char1E_On() LCDDATA9bits.S27C2 = 1
#define    LCD1_Char1E_Off() LCDDATA9bits.S27C2 = 0
#define    LCD1_Char1E_AltSet(value) LCDSDATA9bits.S27C2 = value
#define    LCD1_Char1E_AltOn() LCDSDATA9bits.S27C2 = 1
#define    LCD1_Char1E_AltOff() LCDSDATA9bits.S27C2 = 0

#define    LCD1_Char1F_Set(value) LCDDATA5bits.S27C1 = value
#define    LCD1_Char1F_On() LCDDATA5bits.S27C1 = 1
#define    LCD1_Char1F_Off() LCDDATA5bits.S27C1 = 0
#define    LCD1_Char1F_AltSet(value) LCDSDATA5bits.S27C1 = value
#define    LCD1_Char1F_AltOn() LCDSDATA5bits.S27C1 = 1
#define    LCD1_Char1F_AltOff() LCDSDATA5bits.S27C1 = 0

#define    LCD1_Char1G_Set(value) LCDDATA6bits.S46C1 = value
#define    LCD1_Char1G_On() LCDDATA6bits.S46C1 = 1
#define    LCD1_Char1G_Off() LCDDATA6bits.S46C1 = 0
#define    LCD1_Char1G_AltSet(value) LCDSDATA6bits.S46C1 = value
#define    LCD1_Char1G_AltOn() LCDSDATA6bits.S46C1 = 1
#define    LCD1_Char1G_AltOff() LCDSDATA6bits.S46C1 = 0

#define    LCD1_Char2A_Set(value) LCDDATA17bits.S27C4 = value
#define    LCD1_Char2A_On() LCDDATA17bits.S27C4 = 1
#define    LCD1_Char2A_Off() LCDDATA17bits.S27C4 = 0
#define    LCD1_Char2A_AltSet(value) LCDSDATA17bits.S27C4 = value
#define    LCD1_Char2A_AltOn() LCDSDATA17bits.S27C4 = 1
#define    LCD1_Char2A_AltOff() LCDSDATA17bits.S27C4 = 0

#define    LCD1_Char2B_Set(value) LCDDATA18bits.S46C4 = value
#define    LCD1_Char2B_On() LCDDATA18bits.S46C4 = 1
#define    LCD1_Char2B_Off() LCDDATA18bits.S46C4 = 0
#define    LCD1_Char2B_AltSet(value) LCDSDATA18bits.S46C4 = value
#define    LCD1_Char2B_AltOn() LCDSDATA18bits.S46C4 = 1
#define    LCD1_Char2B_AltOff() LCDSDATA18bits.S46C4 = 0

#define    LCD1_Char2C_Set(value) LCDDATA26bits.S46C6 = value
#define    LCD1_Char2C_On() LCDDATA26bits.S46C6 = 1
#define    LCD1_Char2C_Off() LCDDATA26bits.S46C6 = 0
#define    LCD1_Char2C_AltSet(value) LCDSDATA26bits.S46C6 = value
#define    LCD1_Char2C_AltOn() LCDSDATA26bits.S46C6 = 1
#define    LCD1_Char2C_AltOff() LCDSDATA26bits.S46C6 = 0

#define    LCD1_Char2D_Set(value) LCDDATA29bits.S27C7 = value
#define    LCD1_Char2D_On() LCDDATA29bits.S27C7 = 1
#define    LCD1_Char2D_Off() LCDDATA29bits.S27C7 = 0
#define    LCD1_Char2D_AltSet(value) LCDSDATA29bits.S27C7 = value
#define    LCD1_Char2D_AltOn() LCDSDATA29bits.S27C7 = 1
#define    LCD1_Char2D_AltOff() LCDSDATA29bits.S27C7 = 0

#define    LCD1_Char2E_Set(value) LCDDATA25bits.S27C6 = value
#define    LCD1_Char2E_On() LCDDATA25bits.S27C6 = 1
#define    LCD1_Char2E_Off() LCDDATA25bits.S27C6 = 0
#define    LCD1_Char2E_AltSet(value) LCDSDATA25bits.S27C6 = value
#define    LCD1_Char2E_AltOn() LCDSDATA25bits.S27C6 = 1
#define    LCD1_Char2E_AltOff() LCDSDATA25bits.S27C6 = 0

#define    LCD1_Char2F_Set(value) LCDDATA21bits.S27C5 = value
#define    LCD1_Char2F_On() LCDDATA21bits.S27C5 = 1
#define    LCD1_Char2F_Off() LCDDATA21bits.S27C5 = 0
#define    LCD1_Char2F_AltSet(value) LCDSDATA21bits.S27C5 = value
#define    LCD1_Char2F_AltOn() LCDSDATA21bits.S27C5 = 1
#define    LCD1_Char2F_AltOff() LCDSDATA21bits.S27C5 = 0

#define    LCD1_Char2G_Set(value) LCDDATA22bits.S46C5 = value
#define    LCD1_Char2G_On() LCDDATA22bits.S46C5 = 1
#define    LCD1_Char2G_Off() LCDDATA22bits.S46C5 = 0
#define    LCD1_Char2G_AltSet(value) LCDSDATA22bits.S46C5 = value
#define    LCD1_Char2G_AltOn() LCDSDATA22bits.S46C5 = 1
#define    LCD1_Char2G_AltOff() LCDSDATA22bits.S46C5 = 0

#define    LCD1_Char3A_Set(value) LCDDATA19bits.S50C4 = value
#define    LCD1_Char3A_On() LCDDATA19bits.S50C4 = 1
#define    LCD1_Char3A_Off() LCDDATA19bits.S50C4 = 0
#define    LCD1_Char3A_AltSet(value) LCDSDATA19bits.S50C4 = value
#define    LCD1_Char3A_AltOn() LCDSDATA19bits.S50C4 = 1
#define    LCD1_Char3A_AltOff() LCDSDATA19bits.S50C4 = 0

#define    LCD1_Char3B_Set(value) LCDDATA19bits.S58C4 = value
#define    LCD1_Char3B_On() LCDDATA19bits.S58C4 = 1
#define    LCD1_Char3B_Off() LCDDATA19bits.S58C4 = 0
#define    LCD1_Char3B_AltSet(value) LCDSDATA19bits.S58C4 = value
#define    LCD1_Char3B_AltOn() LCDSDATA19bits.S58C4 = 1
#define    LCD1_Char3B_AltOff() LCDSDATA19bits.S58C4 = 0

#define    LCD1_Char3C_Set(value) LCDDATA27bits.S58C6 = value
#define    LCD1_Char3C_On() LCDDATA27bits.S58C6 = 1
#define    LCD1_Char3C_Off() LCDDATA27bits.S58C6 = 0
#define    LCD1_Char3C_AltSet(value) LCDSDATA27bits.S58C6 = value
#define    LCD1_Char3C_AltOn() LCDSDATA27bits.S58C6 = 1
#define    LCD1_Char3C_AltOff() LCDSDATA27bits.S58C6 = 0

#define    LCD1_Char3D_Set(value) LCDDATA31bits.S58C7 = value
#define    LCD1_Char3D_On() LCDDATA31bits.S58C7 = 1
#define    LCD1_Char3D_Off() LCDDATA31bits.S58C7 = 0
#define    LCD1_Char3D_AltSet(value) LCDSDATA31bits.S58C7 = value
#define    LCD1_Char3D_AltOn() LCDSDATA31bits.S58C7 = 1
#define    LCD1_Char3D_AltOff() LCDSDATA31bits.S58C7 = 0

#define    LCD1_Char3E_Set(value) LCDDATA27bits.S50C6 = value
#define    LCD1_Char3E_On() LCDDATA27bits.S50C6 = 1
#define    LCD1_Char3E_Off() LCDDATA27bits.S50C6 = 0
#define    LCD1_Char3E_AltSet(value) LCDSDATA27bits.S50C6 = value
#define    LCD1_Char3E_AltOn() LCDSDATA27bits.S50C6 = 1
#define    LCD1_Char3E_AltOff() LCDSDATA27bits.S50C6 = 0

#define    LCD1_Char3F_Set(value) LCDDATA23bits.S50C5 = value
#define    LCD1_Char3F_On() LCDDATA23bits.S50C5 = 1
#define    LCD1_Char3F_Off() LCDDATA23bits.S50C5 = 0
#define    LCD1_Char3F_AltSet(value) LCDSDATA23bits.S50C5 = value
#define    LCD1_Char3F_AltOn() LCDSDATA23bits.S50C5 = 1
#define    LCD1_Char3F_AltOff() LCDSDATA23bits.S50C5 = 0

#define    LCD1_Char3G_Set(value) LCDDATA23bits.S58C5 = value
#define    LCD1_Char3G_On() LCDDATA23bits.S58C5 = 1
#define    LCD1_Char3G_Off() LCDDATA23bits.S58C5 = 0
#define    LCD1_Char3G_AltSet(value) LCDSDATA23bits.S58C5 = value
#define    LCD1_Char3G_AltOn() LCDSDATA23bits.S58C5 = 1
#define    LCD1_Char3G_AltOff() LCDSDATA23bits.S58C5 = 0

#define    LCD1_Char4A_Set(value) LCDDATA3bits.S50C0 = value
#define    LCD1_Char4A_On() LCDDATA3bits.S50C0 = 1
#define    LCD1_Char4A_Off() LCDDATA3bits.S50C0 = 0
#define    LCD1_Char4A_AltSet(value) LCDSDATA3bits.S50C0 = value
#define    LCD1_Char4A_AltOn() LCDSDATA3bits.S50C0 = 1
#define    LCD1_Char4A_AltOff() LCDSDATA3bits.S50C0 = 0

#define    LCD1_Char4B_Set(value) LCDDATA3bits.S58C0 = value
#define    LCD1_Char4B_On() LCDDATA3bits.S58C0 = 1
#define    LCD1_Char4B_Off() LCDDATA3bits.S58C0 = 0
#define    LCD1_Char4B_AltSet(value) LCDSDATA3bits.S58C0 = value
#define    LCD1_Char4B_AltOn() LCDSDATA3bits.S58C0 = 1
#define    LCD1_Char4B_AltOff() LCDSDATA3bits.S58C0 = 0

#define    LCD1_Char4C_Set(value) LCDDATA11bits.S58C2 = value
#define    LCD1_Char4C_On() LCDDATA11bits.S58C2 = 1
#define    LCD1_Char4C_Off() LCDDATA11bits.S58C2 = 0
#define    LCD1_Char4C_AltSet(value) LCDSDATA11bits.S58C2 = value
#define    LCD1_Char4C_AltOn() LCDSDATA11bits.S58C2 = 1
#define    LCD1_Char4C_AltOff() LCDSDATA11bits.S58C2 = 0

#define    LCD1_Char4D_Set(value) LCDDATA15bits.S58C3 = value
#define    LCD1_Char4D_On() LCDDATA15bits.S58C3 = 1
#define    LCD1_Char4D_Off() LCDDATA15bits.S58C3 = 0
#define    LCD1_Char4D_AltSet(value) LCDSDATA15bits.S58C3 = value
#define    LCD1_Char4D_AltOn() LCDSDATA15bits.S58C3 = 1
#define    LCD1_Char4D_AltOff() LCDSDATA15bits.S58C3 = 0

#define    LCD1_Char4E_Set(value) LCDDATA11bits.S50C2 = value
#define    LCD1_Char4E_On() LCDDATA11bits.S50C2 = 1
#define    LCD1_Char4E_Off() LCDDATA11bits.S50C2 = 0
#define    LCD1_Char4E_AltSet(value) LCDSDATA11bits.S50C2 = value
#define    LCD1_Char4E_AltOn() LCDSDATA11bits.S50C2 = 1
#define    LCD1_Char4E_AltOff() LCDSDATA11bits.S50C2 = 0

#define    LCD1_Char4F_Set(value) LCDDATA7bits.S50C1 = value
#define    LCD1_Char4F_On() LCDDATA7bits.S50C1 = 1
#define    LCD1_Char4F_Off() LCDDATA7bits.S50C1 = 0
#define    LCD1_Char4F_AltSet(value) LCDSDATA7bits.S50C1 = value
#define    LCD1_Char4F_AltOn() LCDSDATA7bits.S50C1 = 1
#define    LCD1_Char4F_AltOff() LCDSDATA7bits.S50C1 = 0

#define    LCD1_Char4G_Set(value) LCDDATA7bits.S58C1 = value
#define    LCD1_Char4G_On() LCDDATA7bits.S58C1 = 1
#define    LCD1_Char4G_Off() LCDDATA7bits.S58C1 = 0
#define    LCD1_Char4G_AltSet(value) LCDSDATA7bits.S58C1 = value
#define    LCD1_Char4G_AltOn() LCDSDATA7bits.S58C1 = 1
#define    LCD1_Char4G_AltOff() LCDSDATA7bits.S58C1 = 0

#define    LCD1_Char5A_Set(value) LCDDATA7bits.S61C1 = value
#define    LCD1_Char5A_On() LCDDATA7bits.S61C1 = 1
#define    LCD1_Char5A_Off() LCDDATA7bits.S61C1 = 0
#define    LCD1_Char5A_AltSet(value) LCDSDATA7bits.S61C1 = value
#define    LCD1_Char5A_AltOn() LCDSDATA7bits.S61C1 = 1
#define    LCD1_Char5A_AltOff() LCDSDATA7bits.S61C1 = 0

#define    LCD1_Char5B_Set(value) LCDDATA11bits.S62C2 = value
#define    LCD1_Char5B_On() LCDDATA11bits.S62C2 = 1
#define    LCD1_Char5B_Off() LCDDATA11bits.S62C2 = 0
#define    LCD1_Char5B_AltSet(value) LCDSDATA11bits.S62C2 = value
#define    LCD1_Char5B_AltOn() LCDSDATA11bits.S62C2 = 1
#define    LCD1_Char5B_AltOff() LCDSDATA11bits.S62C2 = 0

#define    LCD1_Char5C_Set(value) LCDDATA19bits.S62C4 = value
#define    LCD1_Char5C_On() LCDDATA19bits.S62C4 = 1
#define    LCD1_Char5C_Off() LCDDATA19bits.S62C4 = 0
#define    LCD1_Char5C_AltSet(value) LCDSDATA19bits.S62C4 = value
#define    LCD1_Char5C_AltOn() LCDSDATA19bits.S62C4 = 1
#define    LCD1_Char5C_AltOff() LCDSDATA19bits.S62C4 = 0

#define    LCD1_Char5D_Set(value) LCDDATA27bits.S62C6 = value
#define    LCD1_Char5D_On() LCDDATA27bits.S62C6 = 1
#define    LCD1_Char5D_Off() LCDDATA27bits.S62C6 = 0
#define    LCD1_Char5D_AltSet(value) LCDSDATA27bits.S62C6 = value
#define    LCD1_Char5D_AltOn() LCDSDATA27bits.S62C6 = 1
#define    LCD1_Char5D_AltOff() LCDSDATA27bits.S62C6 = 0

#define    LCD1_Char5E_Set(value) LCDDATA31bits.S61C7 = value
#define    LCD1_Char5E_On() LCDDATA31bits.S61C7 = 1
#define    LCD1_Char5E_Off() LCDDATA31bits.S61C7 = 0
#define    LCD1_Char5E_AltSet(value) LCDSDATA31bits.S61C7 = value
#define    LCD1_Char5E_AltOn() LCDSDATA31bits.S61C7 = 1
#define    LCD1_Char5E_AltOff() LCDSDATA31bits.S61C7 = 0

#define    LCD1_Char5F_Set(value) LCDDATA27bits.S59C6 = value
#define    LCD1_Char5F_On() LCDDATA27bits.S59C6 = 1
#define    LCD1_Char5F_Off() LCDDATA27bits.S59C6 = 0
#define    LCD1_Char5F_AltSet(value) LCDSDATA27bits.S59C6 = value
#define    LCD1_Char5F_AltOn() LCDSDATA27bits.S59C6 = 1
#define    LCD1_Char5F_AltOff() LCDSDATA27bits.S59C6 = 0

#define    LCD1_Char5G_Set(value) LCDDATA19bits.S59C4 = value
#define    LCD1_Char5G_On() LCDDATA19bits.S59C4 = 1
#define    LCD1_Char5G_Off() LCDDATA19bits.S59C4 = 0
#define    LCD1_Char5G_AltSet(value) LCDSDATA19bits.S59C4 = value
#define    LCD1_Char5G_AltOn() LCDSDATA19bits.S59C4 = 1
#define    LCD1_Char5G_AltOff() LCDSDATA19bits.S59C4 = 0

#define    LCD1_Char5H_Set(value) LCDDATA15bits.S59C3 = value
#define    LCD1_Char5H_On() LCDDATA15bits.S59C3 = 1
#define    LCD1_Char5H_Off() LCDDATA15bits.S59C3 = 0
#define    LCD1_Char5H_AltSet(value) LCDSDATA15bits.S59C3 = value
#define    LCD1_Char5H_AltOn() LCDSDATA15bits.S59C3 = 1
#define    LCD1_Char5H_AltOff() LCDSDATA15bits.S59C3 = 0

#define    LCD1_Char5I_Set(value) LCDDATA19bits.S61C4 = value
#define    LCD1_Char5I_On() LCDDATA19bits.S61C4 = 1
#define    LCD1_Char5I_Off() LCDDATA19bits.S61C4 = 0
#define    LCD1_Char5I_AltSet(value) LCDSDATA19bits.S61C4 = value
#define    LCD1_Char5I_AltOn() LCDSDATA19bits.S61C4 = 1
#define    LCD1_Char5I_AltOff() LCDSDATA19bits.S61C4 = 0

#define    LCD1_Char5J_Set(value) LCDDATA23bits.S62C5 = value
#define    LCD1_Char5J_On() LCDDATA23bits.S62C5 = 1
#define    LCD1_Char5J_Off() LCDDATA23bits.S62C5 = 0
#define    LCD1_Char5J_AltSet(value) LCDSDATA23bits.S62C5 = value
#define    LCD1_Char5J_AltOn() LCDSDATA23bits.S62C5 = 1
#define    LCD1_Char5J_AltOff() LCDSDATA23bits.S62C5 = 0

#define    LCD1_Char5K_Set(value) LCDDATA11bits.S61C2 = value
#define    LCD1_Char5K_On() LCDDATA11bits.S61C2 = 1
#define    LCD1_Char5K_Off() LCDDATA11bits.S61C2 = 0
#define    LCD1_Char5K_AltSet(value) LCDSDATA11bits.S61C2 = value
#define    LCD1_Char5K_AltOn() LCDSDATA11bits.S61C2 = 1
#define    LCD1_Char5K_AltOff() LCDSDATA11bits.S61C2 = 0

#define    LCD1_Char5L_Set(value) LCDDATA15bits.S61C3 = value
#define    LCD1_Char5L_On() LCDDATA15bits.S61C3 = 1
#define    LCD1_Char5L_Off() LCDDATA15bits.S61C3 = 0
#define    LCD1_Char5L_AltSet(value) LCDSDATA15bits.S61C3 = value
#define    LCD1_Char5L_AltOn() LCDSDATA15bits.S61C3 = 1
#define    LCD1_Char5L_AltOff() LCDSDATA15bits.S61C3 = 0

#define    LCD1_Char5M_Set(value) LCDDATA15bits.S62C3 = value
#define    LCD1_Char5M_On() LCDDATA15bits.S62C3 = 1
#define    LCD1_Char5M_Off() LCDDATA15bits.S62C3 = 0
#define    LCD1_Char5M_AltSet(value) LCDSDATA15bits.S62C3 = value
#define    LCD1_Char5M_AltOn() LCDSDATA15bits.S62C3 = 1
#define    LCD1_Char5M_AltOff() LCDSDATA15bits.S62C3 = 0

#define    LCD1_Char5N_Set(value) LCDDATA27bits.S61C6 = value
#define    LCD1_Char5N_On() LCDDATA27bits.S61C6 = 1
#define    LCD1_Char5N_Off() LCDDATA27bits.S61C6 = 0
#define    LCD1_Char5N_AltSet(value) LCDSDATA27bits.S61C6 = value
#define    LCD1_Char5N_AltOn() LCDSDATA27bits.S61C6 = 1
#define    LCD1_Char5N_AltOff() LCDSDATA27bits.S61C6 = 0

#define    LCD1_Char5O_Set(value) LCDDATA23bits.S61C5 = value
#define    LCD1_Char5O_On() LCDDATA23bits.S61C5 = 1
#define    LCD1_Char5O_Off() LCDDATA23bits.S61C5 = 0
#define    LCD1_Char5O_AltSet(value) LCDSDATA23bits.S61C5 = value
#define    LCD1_Char5O_AltOn() LCDSDATA23bits.S61C5 = 1
#define    LCD1_Char5O_AltOff() LCDSDATA23bits.S61C5 = 0

#define    LCD1_Char5P_Set(value) LCDDATA23bits.S59C5 = value
#define    LCD1_Char5P_On() LCDDATA23bits.S59C5 = 1
#define    LCD1_Char5P_Off() LCDDATA23bits.S59C5 = 0
#define    LCD1_Char5P_AltSet(value) LCDSDATA23bits.S59C5 = value
#define    LCD1_Char5P_AltOn() LCDSDATA23bits.S59C5 = 1
#define    LCD1_Char5P_AltOff() LCDSDATA23bits.S59C5 = 0

#endif

