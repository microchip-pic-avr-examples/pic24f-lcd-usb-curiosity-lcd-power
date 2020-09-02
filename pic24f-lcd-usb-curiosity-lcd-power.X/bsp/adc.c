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

#include <xc.h>
#include "adc.h"
#include <stdint.h>
#include <stdbool.h>

#define PIN_ANALOG      1
#define PIN_DIGITAL     0

#define PIN_INPUT       1
#define PIN_OUTPUT      0
/*********************************************************************
 * Function: ADC_ReadPercentage(ADC_CHANNEL channel);
 *
 * Overview: Reads the requested ADC channel and returns the percentage
 *            of that conversions result (0-100%).
 *
 * PreCondition: channel is configured via the ADCConfigure() function
 *
 * Input: ADC_CHANNEL channel - enumeration of the ADC channels
 *        available in this demo.  They should be meaningful names and
 *        not the names of the ADC pins on the device (as the demo code
 *        may be ported to other boards).
 *         i.e. ADC_ReadPercentage(ADC_CHANNEL_POTENTIOMETER);
 *
 * Output: uint8_t indicating the percentage of the result 0-100% or
 *         0xFF for an error
 *
 ********************************************************************/
uint8_t ADC_ReadPercentage
( ADC_CHANNEL channel )
{
    uint8_t percent ;

    switch (channel)
    {
        case ADC_CHANNEL_5:
        case ADC_CHANNEL_VDD:
            break;

        case ADC_CHANNEL_BAND_GAP:
            while(HLVDCONbits.BGVST == 0)
            {
            }
            break;          

        default:
            return 0xFF ;
    }

    //A very crude percentage calculation
    percent = ( ADC_Read10bit ( channel ) / 10 ) ;

    if (percent > 100)
    {
        percent = 100 ;
    }
    return percent ;
}
/*********************************************************************
 * Function: ADC_Read10bit(ADC_CHANNEL channel);
 *
 * Overview: Reads the requested ADC channel and returns the 10-bit
 *           representation of this data.
 *
 * PreCondition: channel is configured via the ADCConfigure() function
 *
 * Input: ADC_CHANNEL channel - enumeration of the ADC channels
 *        available in this demo.  They should be meaningful names and
 *        not the names of the ADC pins on the device (as the demo code
 *        may be ported to other boards).
 *         i.e. - ADCReadPercentage(ADC_CHANNEL_POTENTIOMETER);
 *
 * Output: uint16_t the right adjusted 10-bit representation of the ADC
 *         channel conversion or 0xFFFF for an error.
 *
 ********************************************************************/
uint16_t ADC_Read10bit ( ADC_CHANNEL channel )
{
    uint16_t i ;

    AD1CON1bits.MODE12 = 0 ;
        
    switch (channel)
    {
        case ADC_CHANNEL_5:
        case ADC_CHANNEL_VDD:
            break;

        case ADC_CHANNEL_BAND_GAP:
            while(HLVDCONbits.BGVST == 0)
            {
            }
            break;

        default:
            return 0xFFFF ;
    }

    AD1CHS = channel ;

    // Get an ADC sample
    AD1CON1bits.SAMP = 1 ;           //Start sampling
    for (i = 0 ; i < 10000 ; i++) { Nop(); } //Sample delay, conversion start automatically

    AD1CON1bits.SAMP = 0 ;           //Start sampling
    for (i = 0 ; i < 10000 ; i++) { Nop(); } //Sample delay, conversion start automatically

    while (!AD1CON1bits.DONE) ;       //Wait for conversion to complete

    return ADC1BUF0 ;
}

/*********************************************************************
 * Function: ADC_Read12bit(ADC_CHANNEL channel);
 *
 * Overview: Reads the requested ADC channel and returns the 12-bit
 *           representation of this data.
 *
 * PreCondition: channel is configured via the ADCConfigure() function
 *
 * Input: ADC_CHANNEL channel - enumeration of the ADC channels
 *        available in this demo.  They should be meaningful names and
 *        not the names of the ADC pins on the device (as the demo code
 *        may be ported to other boards).
 *         i.e. - ADCReadPercentage(ADC_CHANNEL_POTENTIOMETER);
 *
 * Output: uint16_t the right adjusted 12-bit representation of the ADC
 *         channel conversion or 0xFFFF for an error.
 *
 ********************************************************************/
uint16_t ADC_Read12bit ( ADC_CHANNEL channel )
{
    uint16_t i ;
    
    AD1CON1bits.MODE12 = 1 ;

    switch (channel)
    {
        case ADC_CHANNEL_5:
        case ADC_CHANNEL_VDD:
            break;

        case ADC_CHANNEL_BAND_GAP:
            while(HLVDCONbits.BGVST == 0)
            {
            }
            break;

        default:
            return 0xFFFF ;
    }

    AD1CHS = channel ;

    // Get an ADC sample
    AD1CON1bits.SAMP = 1 ;           //Start sampling
    for (i = 0 ; i < 10000 ; i++) { Nop(); } //Sample delay, conversion start automatically

    AD1CON1bits.SAMP = 0 ;           //Start sampling
    for (i = 0 ; i < 10000 ; i++) { Nop(); } //Sample delay, conversion start automatically

    while (!AD1CON1bits.DONE) ;       //Wait for conversion to complete

    return ADC1BUF0 ;
}

/*********************************************************************
 * Function: ADC_Read16bit(ADC_CHANNEL channel);
 *
 * Overview: Reads the requested ADC channel and returns the 16-bit
 *           representation of this data.  NOTE: this device does not support
 *           16-bit ADC operation so the 12-bit data is shifted to form a 
 *           16-bit value and thus not full scale.
 *
 * PreCondition: channel is configured via the ADCConfigure() function
 *
 * Input: ADC_CHANNEL channel - enumeration of the ADC channels
 *        available in this demo.  They should be meaningful names and
 *        not the names of the ADC pins on the device (as the demo code
 *        may be ported to other boards).
 *         i.e. - ADCReadPercentage(ADC_CHANNEL_POTENTIOMETER);
 *
 * Output: uint16_t the 16-bit representation of the ADC value.
 *
 ********************************************************************/
uint16_t ADC_Read16bit ( ADC_CHANNEL channel )
{
    uint16_t result;
    
    result = ADC_Read12bit(channel);
    
    if(result != 0xFFFF)
    {
        result <<= 4;
    }
    
    return result;
}

/*********************************************************************
 * Function: bool ADC_ChannelEnable(ADC_CHANNEL channel, ADC_CONFIGURATION configuration);
 *
 * Overview: Configures the ADC module to specified setting
 *
 * PreCondition: none
 *
 * Input: ADC_CHANNEL channel - the channel to enable
 *        ADC_CONFIGURATION configuration - the mode in which to run the ADC
 *
 * Output: bool - true if successfully configured.  false otherwise.
 *
 ********************************************************************/
bool ADC_ChannelEnable ( ADC_CHANNEL channel )
{
    switch (channel)
    {
        case ADC_CHANNEL_5:
            ANSBbits.ANSB5 = PIN_ANALOG ;
            return true ;
            
        case ADC_CHANNEL_BAND_GAP:
            ANCFGbits.VBGEN3 = 1;
            return true;
            
        case ADC_CHANNEL_VDD:
            return true;

        default:
            return false ;
    }
}
/*********************************************************************
 * Function: bool ADC_SetConfiguration(ADC_CONFIGURATION configuration)
 *
 * Overview: Configures the ADC module to specified setting
 *
 * PreCondition: none
 *
 * Input: ADC_CONFIGURATION configuration - the mode in which to run the ADC
 *
 * Output: bool - true if successfully configured.  false otherwise.
 *
 ********************************************************************/
bool ADC_SetConfiguration ( ADC_CONFIGURATION configuration )
{
    if (configuration == ADC_CONFIGURATION_DEFAULT)
    {
        AD1CON2bits.PVCFG = 0x00 ;
        AD1CON2bits.NVCFG0 = 0x0 ;
        AD1CON3bits.ADCS = 0xFF ;
        AD1CON1bits.SSRC = 0x0 ;
        AD1CON3bits.SAMC = 0b10000 ;
        AD1CON1bits.FORM = 0b00 ;
        AD1CON2bits.SMPI = 0x0 ;
        AD1CON1bits.MODE12 = 0 ;
        AD1CON1bits.ADON = 1 ;
        AD1CON5bits.BGREQ = 1; //request band gap

        return true ;
    }

    return false ;
}