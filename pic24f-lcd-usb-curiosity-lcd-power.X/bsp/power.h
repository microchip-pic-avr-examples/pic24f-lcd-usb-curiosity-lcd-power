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

#ifndef BSP_POWER_H
#define BSP_POWER_H

/** Type defintions *********************************/
typedef enum
{
    POWER_SOURCE_USB,
    POWER_SOURCE_MAINS
} POWER_SOURCE;


/*********************************************************************
* Function: POWER_SOURCE POWER_SourceGet(void)
*
* Overview: Gets the current source of power for the board
*
* PreCondition: None
*
* Input: None
*
* Output: POWER_SOURCE - the current source of power for the board
*
********************************************************************/
POWER_SOURCE POWER_SourceGet(void);
#define POWER_SourceGet() POWER_SOURCE_USB

#endif //BSP_POWER_H
