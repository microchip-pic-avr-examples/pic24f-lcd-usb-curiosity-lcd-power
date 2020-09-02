/*******************************************************************************
Copyright 2016 Microchip Technology Inc. (www.microchip.com)

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

#ifndef LED3_BLUE_H
#define LED3_BLUE_H

#include <xc.h>

#define LED3_BLUE_LAT     LATDbits.LATD11
#define LED3_BLUE_TRIS    TRISDbits.TRISD11

#define LED_ON  1
#define LED_OFF 0

#define INPUT  1
#define OUTPUT 0

#define MAXIMUM_INTENSITY 0x03FF
#define DEFAULT_INTENSITY (MAXIMUM_INTENSITY/2)

static uint16_t current_intensity = DEFAULT_INTENSITY;

void LED3_BLUE_On(void)
{
	LED3_BLUE_TRIS = 0;
    
    _RP12R  = 20; //16 = OCM4A -> RD11[RP12]  (blue)

    //Blue - uses CCP6-PWM
    CCP6RAL = 0;
    CCP6RBL = current_intensity;
    CCP6PRL = MAXIMUM_INTENSITY;
    CCP6PRH = 0;
    CCP6TMRL = 0;
    CCP6CON1Lbits.MOD = 0b0100;     //dual-compare
    CCP6CON1Lbits.T32 = 0;          //16-bit mode
    CCP6CON1Lbits.CLKSEL = 0b000;   //System clock
    CCP6CON1Lbits.TMRPS = 0b00;     //1:1 Pre-scaler 
    CCP6CON1Lbits.CCSEL = 0;        //Output compare
    CCP6CON1Lbits.CCPON = 1;        //Enable  
}

void LED3_BLUE_Off(void)
{
	LED3_BLUE_TRIS = 0;
	LED3_BLUE_LAT = 0;

    CCP6CON1Lbits.CCPON = 0;        //Disable 
}

void LED3_BLUE_Toggle(void)
{
	if(CCP6CON1Lbits.CCPON)
    {
        LED3_BLUE_Off();
    }
    else
    {
        LED3_BLUE_On();
    }
}

void LED3_BLUE_SetIntensity(uint16_t new_intensity)
{  
    //Convert 16-bit to 10-bit to reduce flicker/jitter
    new_intensity >>= 6;
    
    CCP6RBL = new_intensity;
    
    current_intensity = new_intensity;

    if(CCP6TMRL > new_intensity)
    {
        CCP6TMRL = 0;
    }
}
#endif
