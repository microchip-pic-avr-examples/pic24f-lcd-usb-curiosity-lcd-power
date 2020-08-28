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

#ifndef LCD1_H
#define LCD1_H

#include <stdint.h>

#include "lcd1_7seg.h"
#include "lcd1_16seg.h"
#include "lcd1_segments.h"

#include <xc.h>

enum LCD1_MODE
{
    LCD1_MODE_NORMAL,
    LCD1_MODE_BLINK_HIGH_POWER,
    LCD1_MODE_BLINK_LOW_POWER,
    LCD1_MODE_ALTERNATE
};
           
void LCD1_Initialize(void);
void LCD1_ModeSet(enum LCD1_MODE mode);

#endif

