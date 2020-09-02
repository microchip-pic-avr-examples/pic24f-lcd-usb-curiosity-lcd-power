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

#include "lcd1.h"

void LCD1_Initialize(void) {
    // Initialize LCD: no charge pump, 8 common drivers
    LCDPSbits.WFT = 0; // Type A waveform
    LCDPSbits.LP = 2; // LCD Prescaller 1:3
    LCDCONbits.LMUX = 0x07; // 8 commons, 1/3 Bias
    LCDCONbits.CS = 1; // Clock is LPRC
    LCDREFbits.VLCD1PE = 0; // Enable internal bias
    LCDREFbits.VLCD2PE = 0;
    LCDREFbits.VLCD3PE = 0;
    LCDREFbits.LRLAP = 0x03; // ladder in High-Power Interval A (transition)
    LCDREFbits.LRLBP = 0x03; // ladder in High-Power Interval B (steady state, for higher contrast ratio))
    LCDREFbits.LRLAT = 0x03; // Internal LCD reference ladder is in A Power mode for 3 clocks and B Power mode for 13 clocks
    LCDREFbits.LCDIRE = 1; // Internal Reference Enable
    LCDREFbits.LCDCST = 0; // Contrast 
    LCDREFbits.LCDIRE = 1;
    
    LCDREGbits.CLKSEL = 0b01; //LPRC
    LCDREGbits.CPEN = 1;  //enable charge pump
   
    /* Turn on segments in use, turn off all others. */
    LCDSE0 = 0b0000000000000000;
    LCDSE1 = 0b0000100000000000;
    LCDSE2 = 0b0100000000000000;
    LCDSE3 = 0b0110110000000100;
    
    memset((void*)&LCDDATA0, 0, 32*2);
    memset((void*)&LCDSDATA0, 0, 32*2);
    
    _SMEMEN = 1;
    LCDFC1 = 256;
    
    LCDCONbits.LCDEN = 1; // enable LCD module
    
    LCD1_Logos_On();
}

void LCD1_ModeSet(enum LCD1_MODE mode)
{
    switch(mode)
    {
        case LCD1_MODE_NORMAL:
            _ELCDEN = 0;
            LCDREFbits.LRLAP = 0x3;
            LCDREFbits.LRLBP = 0x3;
            break;
            
        case LCD1_MODE_BLINK_HIGH_POWER:
            _BLINKMODE = 0b01;
            _BLINKFCS = 0b001;
            _DMSEL = 0b00;
            _SMEMEN = 1;
            LCDFC0 = 0;
            LCDFC1 = 0x100;
            _ELCDEN = 1;
            LCDREFbits.LRLAP = 0x3;
            LCDREFbits.LRLBP = 0x3;
            break;
            
        case LCD1_MODE_BLINK_LOW_POWER:
            _BLINKMODE = 0b01;
            _BLINKFCS = 0b001;
            _DMSEL = 0b00;
            _SMEMEN = 1;
            LCDFC0 = 0;
            LCDFC1 = 0x100;
            _ELCDEN = 1;
            LCDREFbits.LRLAP = 0x1;
            LCDREFbits.LRLBP = 0x1;
            break;
            
        case LCD1_MODE_ALTERNATE:
            _ELCDEN = 1;
            _SMEMEN = 1;
            _PMEMDIS = 0;
            _SMFCS = 1;
            _DMSEL = 0b11;
            _BLINKMODE = 0b00;
            LCDFC0=0x3FF;
            LCDACTRLbits.FCCS=00; // LCD clock source
            LCDREFbits.LRLAP = 0x3;
            LCDREFbits.LRLBP = 0x3;
            break;
            
        default:
            break;
    }
}
