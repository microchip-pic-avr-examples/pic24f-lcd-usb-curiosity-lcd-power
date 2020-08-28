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

#ifndef LED1_H
#define LED1_H

#include <xc.h>

#define LED1_LAT     LATAbits.LATA0
#define LED1_TRIS    TRISAbits.TRISA0

inline static void LED1_On(void)
{
	LED1_TRIS = 0;
	LED1_LAT = 1;
}

inline static void LED1_Off(void)
{
	LED1_TRIS = 0;
	LED1_LAT = 0;
}

inline static void LED1_Toggle(void)
{
	LED1_TRIS = 0;
	LED1_LAT ^= 1;
}

#endif
