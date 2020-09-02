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

#ifndef LED2_H
#define LED2_H

#include <xc.h>

#define LED2_LAT     LATAbits.LATA1
#define LED2_TRIS    TRISAbits.TRISA1

inline static void LED2_On(void)
{
	LED2_TRIS = 0;
	LED2_LAT = 1;
}

inline static void LED2_Off(void)
{
	LED2_TRIS = 0;
	LED2_LAT = 0;
}

inline static void LED2_Toggle(void)
{
	LED2_TRIS = 0;
	LED2_LAT ^= 1;
}

#endif
