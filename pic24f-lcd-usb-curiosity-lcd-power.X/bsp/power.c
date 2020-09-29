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
#include "power.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/adc1.h"

#define BANDGAP_TYPICAL_VOLTAGE     ((double)1.2)

/* Datasheet of D1 claims 0.240v max. */
#define DIODE_D1_DROP               ((double)0.24)

typedef enum
{
    ADC_CHANNEL_BAND_GAP = 28,
    ADC_CHANNEL_VDD = 30
} ADC_POWER_CHANNEL;

static uint16_t getBandGapChannelOutput(ADC1_CHANNEL channel);


enum POWER_SOURCE POWER_GetSource(void)
{
    if(IO_RB13_GetValue() == true)
    {
        return POWER_SOURCE_USB;
    }
    
    return POWER_SOURCE_BATTERY;
}

double POWER_GetVddVoltage(void)
{
    uint16_t vdd;
    uint16_t band_gap;
    vdd = getBandGapChannelOutput(CHANNEL_AVDD);
    while(HLVDCONbits.BGVST == 0)
    {
    }
    // Get the BandGap Channel Voltage
    band_gap = getBandGapChannelOutput(CHANNEL_VBG);
    return ( (BANDGAP_TYPICAL_VOLTAGE * vdd) / band_gap );
}

static uint16_t getBandGapChannelOutput(ADC1_CHANNEL channel) 
{
    uint16_t channelOuput = 0;
    uint16_t i=0;
    ADC1_Enable();
    
    ADC1_ChannelSelect(channel);
    //Start Sampling
    ADC1_SoftwareTriggerEnable();

    for(i=0;i<65535;i++)
    {
        //Do Nothing
    }
    ADC1_SoftwareTriggerDisable();
    //Check if the ADC conversion is completed
    while(!ADC1_IsConversionComplete(channel))
    {
        //Do Nothing
    }
    channelOuput = ADC1_ConversionResultGet(channel);// VDD Channel =30,Channel Band Gap = 28,Channel 16 = 16
    ADC1_Disable();
    return channelOuput;
}

double POWER_GetBatteryVoltage(void)
{
    /* For the battery voltage we need to take into account the voltage drop to
     * Vdd through the D1 diode.  Thus the battery voltage is actually a bit
     * higher. */
    return (POWER_GetVddVoltage() + DIODE_D1_DROP);
}

void POWER_SetMode(enum POWER_MODE mode)
{
    switch(mode)
    {            
        case POWER_MODE_LOW:
            /* Disable all unused modules. */
            PMD1 = (0xFFFF & (~_PMD1_AD1MD_MASK));
            PMD3 = (0xFFFF & (~_PMD3_RTCCMD_MASK));
            PMD4 = (0xFFFF & (~_PMD4_HLVDMD_MASK));
            PMD5 = 0xFFFF;
            PMD6 = (0xFFFF & (~_PMD6_LCDMD_MASK));
            PMD7 = 0xFFFF;
            PMD8 = 0xFFFF; 
            break;
            
        case POWER_MODE_SLEEP:
            _VREGS = 0; //fast wakeup disabled (low power)
            _RETEN = 1; //retention mode enabled
            
            /* Disable all unused modules. */
            PMD1 = 0xFFFF;
            PMD3 = (0xFFFF & (~_PMD3_RTCCMD_MASK));
            PMD4 = 0xFFFF;
            PMD5 = 0xFFFF;
            PMD6 = (0xFFFF & (~_PMD6_LCDMD_MASK));
            PMD7 = 0xFFFF;
            PMD8 = 0xFFFF; 
            break;
            
        case POWER_MODE_FULL:
            /* Re-enable all other modules so they are available for application use. */
            PMD1 = 0x0000;
            PMD3 = 0x0000;
            PMD4 = 0x0000;
            PMD5 = 0x0000;
            PMD6 = 0x0000;
            PMD7 = 0x0000;
            PMD8 = 0x0000;
            
        default:
            break;
    }
}
