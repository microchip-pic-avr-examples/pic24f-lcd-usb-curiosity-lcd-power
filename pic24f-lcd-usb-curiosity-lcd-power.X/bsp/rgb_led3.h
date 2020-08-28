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

#ifndef RGB_LED3_H
#define RGB_LED3_H

void RGB_LED3_SetColor(uint16_t red, uint16_t green, uint16_t blue);

void RGB_LED3_On(void);

void RGB_LED3_Off(void);

void RGB_LED3_Toggle(void);

#endif
