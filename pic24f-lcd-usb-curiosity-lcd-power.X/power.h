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

#ifndef POWER_H
#define	POWER_H

enum POWER_SOURCE
{
    POWER_SOURCE_UNKNOWN = -1,
    POWER_SOURCE_USB = 0,
    POWER_SOURCE_BATTERY
};

enum POWER_MODE
{
    POWER_MODE_FULL,
    POWER_MODE_LOW,
    POWER_MODE_SLEEP
};

void POWER_Initialize(void);
enum POWER_SOURCE POWER_GetSource(void);
double POWER_GetVddVoltage(void);
double POWER_GetBatteryVoltage(void);
void POWER_SetMode(enum POWER_MODE mode);

#endif	/* POWER_H */

