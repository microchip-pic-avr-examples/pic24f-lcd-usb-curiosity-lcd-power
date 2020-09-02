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

#ifndef IO_PINS_H
#define	IO_PINS_H

#include <stdbool.h>

void IO_PINS_Initialize(void);

/* Drive all unused pins to output low for lower current. */
void IO_PINS_HandleUnusedPins(void);

/* Tests to see if USB power is present. */
bool IO_PINS_USBPowerSense(void);

#endif	/* IO_PINS_H */

