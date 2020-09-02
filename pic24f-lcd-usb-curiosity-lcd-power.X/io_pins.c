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

#include <stdbool.h>
#include <stdint.h>
#include <xc.h>

#include "io_pins.h"

/* This sets all the unused pins on the board as an output and drives them low.
 * This will help lower the sleep current since the pins will not be floating
 * possibly causing input toggling. 
 */
void IO_PINS_HandleUnusedPins()
{
    /* mikroBus(tm) slot A */
    _TRISB7 = 0;
    _LATB7 = 0;
    
    _TRISD8 = 0;
    _LATD8 = 0;
    
    _TRISG9 = 0;
    _LATG9 = 0;
    
    _TRISD7 = 0;
    _LATD7 = 0;
    
    _TRISF8 = 0;
    _LATF8 = 0;
    
    _TRISF2 = 0;
    _LATF2 = 0;
    
    _TRISF3 = 0;
    _LATF3 = 0;
    
    _TRISA14 = 0;
    _LATA14 = 0;
    
    _TRISA15 = 0;
    _LATA15 = 0;

    /* mikroBus(tm) slot B */
    _TRISB4 = 0;
    _LATB4 = 0;
    
    _TRISE9 = 0;
    _LATE9 = 0;
    
    _TRISD6 = 0;
    _LATD6 = 0;
    
    _TRISD3 = 0;
    _LATD3 = 0;
    
    _TRISD4 = 0;
    _LATD4 = 0;
    
    _TRISD5 = 0;
    _LATD5 = 0;
    
    _TRISF3 = 0;
    _LATF3 = 0;
    
    _TRISB2 = 0;
    _LATB2 = 1;
    
    _TRISE8 = 0;
    _LATE8 = 1;
    
    _TRISF4 = 0;
    _LATF4 = 1;
    
    _TRISF5 = 0;
    _LATF5 = 1;
    
    _TRISA2 = 0;
    _LATA2 = 1;
    
    _TRISA3 = 0;
    _LATA3 = 1;
    
    /* programming/debug pins */
#ifndef __DEBUG
    _TRISB0 = 0;
    _LATB0 = 1;
    
    _TRISB1 = 0;
    _LATB1 = 1;  
#endif
    
    /* Unused pins not connected to anything other than the pin headers. */
    _TRISE4 = 0;
    _LATE4 = 1;
    
    _TRISF12 = 0;
    _LATF12 = 1;
    
    _TRISF13 = 0;
    _LATF13 = 1;
    
    _TRISH0 = 0;
    _LATH0 = 1;
    
    _TRISA4 = 0;
    _LATA4 = 1;
    
    _TRISA5 = 0;
    _LATA5 = 1;
    
    _TRISA9 = 0;
    _LATA9 = 1;
    
    _TRISA10 = 0;
    _LATA10 = 1;
    
    _TRISB3 = 0;
    _LATB3 = 1;
    
    _TRISB11 = 0;
    _LATB11 = 1;
    
    _TRISB12 = 0;
    _LATB12 = 1;
    
    _TRISB14 = 0;
    _LATB14 = 1;
    
    _TRISB15 = 0;
    _LATB15 = 1;
    
    _TRISC1 = 0;
    _LATC1 = 1;
    
    _TRISC2 = 0;
    _LATC2 = 1;
    
    _TRISC3 = 0;
    _LATC3 = 1;
    
    _TRISC4 = 0;
    _LATC4 = 1;
    
    _TRISC15 = 0;
    _LATC15 = 1;
    
    _TRISD0 = 0;
    _LATD0 = 1;
    
    _TRISD12 = 0;
    _LATD12 = 1;
}

void IO_PINS_Initialize()
{ 
    // TC77 chip select
    _TRISG14 = 0;
    _LATG14 = 0;
    
    //SPI PPS
    _RP23R = 7;     //MOSI
    _RP21R = 8;     //SCK
    _SDI1R = 24;    //MISO
   
    ANSELGbits.ANSELG6 = 0;

    //Power monitor pin
    ANSELBbits.ANSB13 = 0;   //Digital
    TRISBbits.TRISB13 = 1;   //Input
    IOCPBbits.IOCPB13 = 1;   //Interrupt on change
    _IOCON = 1;
    _IOCIF = 0;
    _IOCIE = 1;
    
    IO_PINS_HandleUnusedPins();
}

/* Tests to see if USB power is present. */
bool IO_PINS_USBPowerSense(void)
{
    return PORTBbits.RB13;
}

void __attribute__ ( ( weak, __interrupt__ , auto_psv ) ) _IOCInterrupt ( void )
{
    _IOCIF = 0;
}
