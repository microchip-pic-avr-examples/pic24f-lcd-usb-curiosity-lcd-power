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

#include "mcc_generated_files/spi1_types.h"
#include "mcc_generated_files/spi1_driver.h"

#define DEGREES_PER_BIT 0.0625

#define CHIP_SELECT_PIN     _RG14
#define CHIP_SELECT_TRIS    _TRISG14

#define CHIP_ENABLE 0
#define CHIP_DISABLE 1

#define INPUT 1
#define OUTPUT 0

void TC77_Initialize(void)
{

}

void TC77_Shutdown(void)
{
    while(spi1_open(SPI1_DEFAULT) == false)
    {
    }
    
    CHIP_SELECT_PIN = CHIP_ENABLE;
    (void)spi1_exchangeByte(0x00);
    (void)spi1_exchangeByte(0x00);
    (void)spi1_exchangeByte(0xFF);    
    (void)spi1_exchangeByte(0xFF);    //Shutdown = 0xFF in control byte
    CHIP_SELECT_PIN = CHIP_DISABLE;   
    
    spi1_close();
}

inline static bool isNegative(uint16_t data)
{
    return ((data & 0x8000) == 0x8000);
}

inline static uint16_t twosCompliment(uint16_t data)
{
    return (data ^ 0xFFFF);
}

/* Converts the native TC77 temperature to a float standard Celsius temperature.
 */
static double convert(uint16_t data)
{        
    if( isNegative(data) )
    {
        data ^= 0xFFFF;       
        data >>= 3;
        data += 1;
        
        return -1 * (DEGREES_PER_BIT * (double)data);
    }
    else
    {
        data >>= 3;
        
        return (DEGREES_PER_BIT * (double)data);
    }
}

/* The temperature data is only valid if Bit2 is set.  Otherwise the first
 * sample hasn't completed yet. */
inline static bool IsValid(uint16_t data)
{
    return ((data & 0x04) == 0x04);
}

double TC77_GetTemperatureCelsius(void)
{    
    uint8_t byte1, byte2, byte3, byte4;
    uint16_t data;
    
    while(spi1_open(SPI1_DEFAULT) == false)
    {
    }
    
    do
    {
        CHIP_SELECT_PIN = CHIP_ENABLE;
        byte1 = spi1_exchangeByte(0x00);
        byte2 = spi1_exchangeByte(0x00);
        byte3 = spi1_exchangeByte(0x00);    
        byte4 = spi1_exchangeByte(0x00);
        CHIP_SELECT_PIN = CHIP_DISABLE;   
        
        data = byte1;
        data <<= 8;
        data |= byte2;

    } while ( IsValid(data) == false );
    
    spi1_close();
    
    return convert(data);
}