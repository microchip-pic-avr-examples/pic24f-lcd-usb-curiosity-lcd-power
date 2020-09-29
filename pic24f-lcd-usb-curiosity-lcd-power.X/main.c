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

#include <stddef.h>

#include "power.h"
#include "application/usb_operational_mode.h"
#include "application/battery_operational_mode.h"
#include "mcc_generated_files/rtcc.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/lcd.h"
#include "application/build_time.h"

static void SwitchOperatoinalMode(enum POWER_SOURCE new_source);

static enum POWER_SOURCE current_source;
static const struct OPERATIONAL_MODE *operational_mode;

/*******************************************************************************
  GETTING STARTED
  -----------------------------------------------------------------------------
  To run this demo, please refer to the readme.txt file that is provided with
  this project.  You can find this file attached to the project in the 
  "Documentation" logical folder in the project view in the IDE.
  
  You can also locate the readme.txt file on next to the project folder where
  this demo was extracted.  
  
  The readme.txt contains the details of how to run the demo.
  
  There is an additional hardware.txt file also in the "Documentation" logical
  folder in the project that summarizes the hardware connections of the board.
 ******************************************************************************/

int main(void)
{
    struct tm build_time;
    
    enum POWER_SOURCE new_source;
    SYSTEM_Initialize();
   
    BUILDTIME_Get(&build_time);
    RTCC_TimeSet(&build_time);
    
    operational_mode = NULL;
    current_source = POWER_SOURCE_UNKNOWN;
    
    new_source = POWER_GetSource();
    
    while(1)
    {
        if(new_source != current_source)
        {
            current_source = new_source;
            SwitchOperatoinalMode(new_source);
        }
        
        do
        {
            operational_mode->Tasks();
            new_source = POWER_GetSource();
            
        } while( current_source == new_source );
    }
    
    return 0;
}

static void SwitchOperatoinalMode(enum POWER_SOURCE new_source)
{
    if(operational_mode != NULL)
    {
        operational_mode->Deinitialize();
    }
    
    switch(new_source)
    {
        case POWER_SOURCE_USB:
            operational_mode = &usb_operational_mode;
            break;

        case POWER_SOURCE_BATTERY:
            operational_mode = &battery_operational_mode;
            break;
            
        default:
            break;
    }
    
    if(operational_mode != NULL)
    {
        operational_mode->Initialize();
    }
}