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
#include <stdint.h>

#include "led3_red.h"
#include "led3_green.h"
#include "led3_blue.h"

/* This module uses 3 dimmable LEDs (red, green, blue).  It uses them to
 * implement one color changing LED.
 */

void RGB_LED3_SetColor(uint16_t red, uint16_t green, uint16_t blue)
{
    LED3_RED_SetIntensity(red);
    LED3_GREEN_SetIntensity(green);
    LED3_BLUE_SetIntensity(blue);
}

void RGB_LED3_On(void)
{
    LED3_RED_On();
    LED3_BLUE_On();
    LED3_GREEN_On();  
}

void RGB_LED3_Off(void)
{
    LED3_RED_Off();
    LED3_BLUE_Off();
    LED3_GREEN_Off();  
}

void RGB_LED3_Toggle(void)
{
    LED3_RED_Toggle();
    LED3_BLUE_Toggle();
    LED3_GREEN_Toggle();  
}


