/**
  RTCC Generated Driver API Header File

  Company:
    Microchip Technology Inc.

  File Name:
    rtcc.h

  @Summary
    This is the generated header file for the RTCC driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides APIs for driver for RTCC.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.169.0
        Device            :  PIC24FJ512GU410
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.50
        MPLAB 	          :  MPLAB X v5.40
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#ifndef _RTCC_H
#define _RTCC_H


/**
 Section: Included Files
*/

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
 Section: types
*/
typedef struct tm bcdTime_t;

/**
 Section: Interface Routines
*/

/**
  @Summary
    Initializes and enables RTCC peripheral

  @Description
    This function sets a time in the RTCC and enables 
    RTCC for operation. It will also configure the Alarm settings.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Example
    <code>
    struct tm currentTime;

    RTCC_Initialize();

    while(!RTCC_TimeGet(&currentTime))
    {
        // Do something
    }
    </code>
*/

void RTCC_Initialize(void);


/**
  @Summary
    Returns the current time from the RTCC peripheral

  @Description
    This function returns the current time from the RTCC peripheral. This
    function uses the C library type struct tm parameter.

  @Preconditions
    None

  @Param
    currentTime - This the parameter which gets filled in by the function. The
    values are set by reading the hardware peripheral

  @Returns
    Whether the data is available or not, true if the data is available.
    false if the data is not available.

  @Example
    Refer to the example for the function RTCC_Initialize
*/

bool RTCC_TimeGet(struct tm *currentTime);

/**
  @Summary
    Sets the initial time for the RTCC peripheral

  @Description
    This function sets the initial time for the RTCC peripheral. This
    function uses the C library type struct tm parameter.

  @Preconditions
    None

  @Param
    initialTime - This parameter sets the values.

  @Returns
    None

  @Example
    Refer to the example for the function RTCC_Initialize
*/

void RTCC_TimeSet(struct tm *initialTime);
/**
  @Summary
    Returns the current time from the RTCC peripheral

  @Description
    This function returns the current time from the RTCC peripheral. This
    function uses the C library type struct tm parameter.

  @Preconditions
    None

  @Param
    currentTime - This the parameter which gets filled in by the function. The
    values are set by reading the hardware peripheral

  @Returns
    Whether the data is available or not, true if the data is available.
    false if the data is not available.

  @Example
    Refer to the example for the function RTCC_Initialize
*/

bool RTCC_BCDTimeGet(bcdTime_t *currentTime);

/**
  @Summary
    Sets the initial time for the RTCC peripheral in BCD format

  @Description
    This function sets the initial time for the RTCC peripheral. This
    the time value in BCD format

  @Preconditions
    None

  @Param
    initialTime - This parameter takes the input value in BCD format

  @Returns
    None

  @Example
    Refer to the example for the function RTCC_Initialize
*/
void RTCC_BCDTimeSet(bcdTime_t *initialTime);

/**
  @Summary
    This function indicates whether to reset the RTCC value or not on  system restart.

  @Description
    This function indicates whether to reset the RTCC value or not on  system restart.

  @Preconditions
    None

  @Param
    bool - parameter to indicate whether to reset RTCC value or not

  @Returns
    None

  @Example
    Refer to the example for the function RTCC_Initialize
*/
void RTCC_TimeReset(bool reset);

/**
  @Summary
    Sets the manual Timestamp A event

  @Description
    This function sets the manual timestamp event. This is a software trigger.

  @Preconditions
    None

  @Param
    None 

  @Returns
    None

  @Example
    Refer to the example for the function RTCC_Initialize
*/
void RTCC_TimestampAEventManualSet(void);



/**
  @Summary
    Gets the timestamp time for the RTCC peripheral

  @Description
    This function gets the RTCC time when timestamp A event occurs. This
    function uses the C library type struct tm parameter. Timestamp event can be
    software or hardware trigger.

  @Preconditions
    None

  @Param
    currentTime -  This is the parameter which gets filled in by the function. The
    values are set by reading the hardware peripheral.
    This is the RTCC time when timestamp occurs.

  @Returns
    Whether the data is available or not, true if the data is available.
    false if the data is not available.

  @Example
    Refer to the example for the function RTCC_Initialize
*/
bool RTCC_TimestampADataGet(struct tm *currentTime);


/**
  @Summary
    Gets the timestamp time for the RTCC peripheral in BCD format

  @Description
    This function gets the RTCC time when timestamp A event occurs. This
    function uses the C library type struct tm parameter. Timestamp event can be
    software or hardware trigger.

  @Preconditions
    None

  @Param
    currentTime -  This is the parameter which gets filled in by the function. The
    values are set by reading the hardware peripheral.
    This is the RTCC time when timestamp occurs.

  @Returns
    Whether the data is available or not, true if the data is available.
    false if the data is not available.

  @Example
    Refer to the example for the function RTCC_Initialize
*/
bool RTCC_TimestampA_BCDDataGet(bcdTime_t *currentTime);


/**
  @Summary
    Callback for RTCC.

  @Description
    This routine is callback for RTCC

  @Param
    None.

  @Returns
    None
 
  @Example 
	Refer to RTCC_Initialize(); for an example
*/
void RTCC_CallBack(void);


#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // _RTCC_H

/**
 End of File
*/
