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
#include "mcc_generated_files/spi1.h"
#include "mcc_generated_files/pin_manager.h"

#define DEGREES_PER_BIT 				(double)0.0625

#define CONVERSION_STATUS_BIT			0x04
#define NEGATIVE_CHECK_MSB_BIT 			0x8000
#define ALL_BIT_SET						0xFFFF
#define SHIFT_INVALID_BITS				0x03
#define ADD_ONE_FOR_ONES_COMPLEMENT 	0x01
#define MINUS_ONE						(-1)

void TC77_Shutdown(void)
{
    SPI_CHIP_SELECT_SetLow();
    (void)SPI1_Exchange8bit(0x00);
    (void)SPI1_Exchange8bit(0x00);
    (void)SPI1_Exchange8bit(0xFF);    
    (void)SPI1_Exchange8bit(0xFF);    //Shutdown = 0xFF in control byte
    SPI_CHIP_SELECT_SetHigh();
}

inline static bool isNegative(uint16_t data)
{
    return ((data & NEGATIVE_CHECK_MSB_BIT) == NEGATIVE_CHECK_MSB_BIT);
}

inline static uint16_t twosCompliment(uint16_t data)
{
    return (data ^ ALL_BIT_SET);
}

/* Converts the native TC77 temperature to a float standard Celsius temperature.
 */
static double convert(uint16_t data)
{        
    if( isNegative(data) )
    {
        data ^= ALL_BIT_SET;       
        data >>= SHIFT_INVALID_BITS;
        data += ADD_ONE_FOR_ONES_COMPLEMENT;
        
        return -1 * (DEGREES_PER_BIT * (double)data);
    }
    else
    {
        data >>= SHIFT_INVALID_BITS;
        
        return (DEGREES_PER_BIT * (double)data);
    }
}

/* The temperature data is only valid if Bit2 is set.  Otherwise the first
 * sample hasn't completed yet. */
inline static bool IsValid(uint16_t data)
{
    return ((data & CONVERSION_STATUS_BIT) == CONVERSION_STATUS_BIT);
}

double TC77_GetTemperatureCelsius(void)
{    
    uint8_t byte1, byte2, byte3, byte4;
    uint16_t data;
    do
    {
        SPI_CHIP_SELECT_SetLow();
        byte1 = SPI1_Exchange8bit(0x00);
        byte2 = SPI1_Exchange8bit(0x00);
        byte3 = SPI1_Exchange8bit(0x00);    
        byte4 = SPI1_Exchange8bit(0x00);
        SPI_CHIP_SELECT_SetHigh();
        
        data = byte1;
        data <<= 8;
        data |= byte2;

    } while ( IsValid(data) == false );
    
    return convert(data);
}