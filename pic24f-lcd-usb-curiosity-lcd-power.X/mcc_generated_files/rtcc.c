
/**
  RTCC Generated Driver API Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    rtcc.c

  @Summary:
    This is the generated header file for the RTCC driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description:
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


/**
 Section: Included Files
*/

#include "rtcc.h"

/**
// Section: Static function
*/

static void RTCC_Lock(void);
static bool rtccTimeInitialized;
static bool RTCCTimeInitialized(void);
static uint8_t ConvertHexToBCD(uint8_t hexvalue);
static uint8_t ConvertBCDToHex(uint8_t bcdvalue);

/**
// Section: Driver Interface Function Definitions
*/

void RTCC_Initialize(void)
{

   RTCCON1Lbits.RTCEN = 0;
   
   __builtin_write_RTCC_WRLOCK();
   
   
   if(!RTCCTimeInitialized())
   {
       // set 2020-09-02 11-44-51
       DATEH = 0x2009;    // Year/Month
       DATEL = 0x203;    // Date/Wday
       TIMEH = 0x1144;    // hours/minutes
       TIMEL = 0x5100;    // seconds
   }
   // set 2020-09-02 11-44-51
   ALMDATEH = 0x2009;    // Year/Month
   ALMDATEL = 0x203;    // Date/Wday
   ALMTIMEH = 0x1144;    // hours/minutes
   ALMTIMEL = 0x5100;    // seconds
   // AMASK Every Minute; ALMRPT 255; CHIME enabled; ALRMEN enabled; 
   RTCCON1H = 0xC3FF;

   // PWCPS 1:1; PS 1:1; CLKSEL LPRC; FDIV 0; 
   RTCCON2L = 0x01;
   // DIV 15499; 
   RTCCON2H = 0x3C8B;
   // PWCSTAB 0; PWCSAMP 0; 
   RTCCON3L = 0x00;

   // RTCEN enabled; OUTSEL Alarm Event; PWCPOE disabled; PWCEN disabled; WRLOCK disabled; PWCPOL disabled; TSAEN disabled; RTCOE disabled; 
   RTCCON1L = 0x8000; 
   
   // Enable RTCC, clear RTCWREN 
   RTCCON1Lbits.RTCEN = 1; 
   RTCC_Lock();

   IEC3bits.RTCIE = 1;
}

static void RTCC_Lock(void)
{
    asm volatile("DISI #6");
    asm volatile("MOV #NVMKEY, W1");
    asm volatile("MOV #0x55, W2");
    asm volatile("MOV W2, [W1]");
    asm volatile("MOV #0xAA, W3");
    asm volatile("MOV W3, [W1]");
    asm volatile("BSET RTCCON1L, #11");
}

bool RTCC_TimeGet(struct tm *currentTime)
{
    uint16_t register_value;
    if(RTCSTATLbits.SYNC){
        return false;
    }
 
    register_value = DATEH;
    currentTime->tm_year = ConvertBCDToHex((register_value & 0xFF00) >> 8);
    currentTime->tm_mon = ConvertBCDToHex(register_value & 0x00FF);
    
    register_value = DATEL;
    currentTime->tm_mday = ConvertBCDToHex((register_value & 0xFF00) >> 8);
    currentTime->tm_wday = ConvertBCDToHex(register_value & 0x00FF);
    
    register_value = TIMEH;
    currentTime->tm_hour = ConvertBCDToHex((register_value & 0xFF00) >> 8);
    currentTime->tm_min = ConvertBCDToHex(register_value & 0x00FF);
    
    register_value = TIMEL;
    currentTime->tm_sec = ConvertBCDToHex((register_value & 0xFF00) >> 8);
    
    return true;
}

void RTCC_TimeSet(struct tm *initialTime)
{

  __builtin_write_RTCC_WRLOCK();

   RTCCON1Lbits.RTCEN = 0;
   
   IFS3bits.RTCIF = false;
   IEC3bits.RTCIE = 0;

   // set RTCC initial time
   DATEH = (ConvertHexToBCD(initialTime->tm_year) << 8) | ConvertHexToBCD(initialTime->tm_mon) ;  // YEAR/MONTH-1
   DATEL = (ConvertHexToBCD(initialTime->tm_mday) << 8) | ConvertHexToBCD(initialTime->tm_wday) ;  // /DAY-1/WEEKDAY
   TIMEH = (ConvertHexToBCD(initialTime->tm_hour) << 8)  | ConvertHexToBCD(initialTime->tm_min); // /HOURS/MINUTES
   TIMEL = (ConvertHexToBCD(initialTime->tm_sec) << 8) ;   // SECOND
           
   // Enable RTCC, clear RTCWREN         
   RTCCON1Lbits.RTCEN = 1;  
   RTCC_Lock();

   //Enable RTCC interrupt
   IEC3bits.RTCIE = 1;
}

bool RTCC_BCDTimeGet(bcdTime_t *currentTime)
{
    uint16_t register_value;
    if(RTCSTATLbits.SYNC){
        return false;
    }

    register_value = DATEH;
    currentTime->tm_year = (register_value & 0xFF00) >> 8;
    currentTime->tm_mon = register_value & 0x00FF;
    
    register_value = DATEL;
    currentTime->tm_mday = (register_value & 0xFF00) >> 8;
    currentTime->tm_wday = register_value & 0x00FF;
    
    register_value = TIMEH;
    currentTime->tm_hour = (register_value & 0xFF00) >> 8;
    currentTime->tm_min = register_value & 0x00FF;
   
    register_value = TIMEL;
    currentTime->tm_sec = (register_value & 0xFF00) >> 8;

    return true;
}

void RTCC_BCDTimeSet(bcdTime_t *initialTime)
{

   __builtin_write_RTCC_WRLOCK();

   RTCCON1Lbits.RTCEN = 0;
   
   IFS3bits.RTCIF = false;
   IEC3bits.RTCIE = 0;

   // set RTCC initial time
   DATEH = (initialTime->tm_year << 8) | (initialTime->tm_mon) ;  // YEAR/MONTH-1
   DATEL = (initialTime->tm_mday << 8) | (initialTime->tm_wday) ;  // /DAY-1/WEEKDAY
   TIMEH = (initialTime->tm_hour << 8) | (initialTime->tm_min); // /HOURS/MINUTES
   TIMEL = (initialTime->tm_sec << 8);   // SECONDS   
           
   // Enable RTCC, clear RTCWREN         
   RTCCON1Lbits.RTCEN = 1;  
   RTCC_Lock();

   //Enable RTCC interrupt
   IEC3bits.RTCIE = 1;
}

/**
 This function implements RTCC_TimeReset.This function is used to
 used by application to reset the RTCC value and reinitialize RTCC value.
*/
void RTCC_TimeReset(bool reset)
{
    rtccTimeInitialized = reset;
}

static bool RTCCTimeInitialized(void)
{
    return(rtccTimeInitialized);
}

void RTCC_TimestampAEventManualSet(void)
{
    RTCSTATLbits.TSAEVT = 1;
}

bool RTCC_TimestampADataGet(struct tm *currentTime)
{
    uint16_t register_value;
    if(!RTCSTATLbits.TSAEVT){
        return false;
    }
  
    register_value = TSADATEH;
    currentTime->tm_year = ConvertBCDToHex((register_value & 0xFF00) >> 8);
    currentTime->tm_mon = ConvertBCDToHex(register_value & 0x00FF);
    
    register_value = TSADATEL;
    currentTime->tm_mday = ConvertBCDToHex((register_value & 0xFF00) >> 8);
    currentTime->tm_wday = ConvertBCDToHex(register_value & 0x00FF);
    
    register_value = TSATIMEH;
    currentTime->tm_hour = ConvertBCDToHex((register_value & 0xFF00) >> 8);
    currentTime->tm_min = ConvertBCDToHex(register_value & 0x00FF);
    
    register_value = TSATIMEL;
    currentTime->tm_sec = ConvertBCDToHex((register_value & 0xFF00) >> 8);
   
    RTCSTATLbits.TSAEVT = 0;

    return true;
}



bool RTCC_TimestampA_BCDDataGet(bcdTime_t *currentTime)
{
    uint16_t register_value;
    if(!RTCSTATLbits.TSAEVT){
        return false;
    }
  
    register_value = TSADATEH;
    currentTime->tm_year = (register_value & 0xFF00) >> 8;
    currentTime->tm_mon = (register_value & 0x00FF);
    
    register_value = TSADATEL;
    currentTime->tm_mday = (register_value & 0xFF00) >> 8;
    currentTime->tm_wday = (register_value & 0x00FF);
    
    register_value = TSATIMEH;
    currentTime->tm_hour = (register_value & 0xFF00) >> 8;
    currentTime->tm_min = (register_value & 0x00FF);
    
    register_value = TSATIMEL;
    currentTime->tm_sec = (register_value & 0xFF00) >> 8;
   
    RTCSTATLbits.TSAEVT = 0;

    return true;
}



static uint8_t ConvertHexToBCD(uint8_t hexvalue)
{
    uint8_t bcdvalue;
    bcdvalue = (hexvalue / 10) << 4;
    bcdvalue = bcdvalue | (hexvalue % 10);
    return (bcdvalue);
}

static uint8_t ConvertBCDToHex(uint8_t bcdvalue)
{
    uint8_t hexvalue;
    hexvalue = (((bcdvalue & 0xF0) >> 4)* 10) + (bcdvalue & 0x0F);
    return hexvalue;
}

void __attribute__ ((weak)) RTCC_CallBack(void)
{
    // Add your custom callback code here
}

/* Function:
  void __attribute__ ( ( interrupt, no_auto_psv ) ) _ISR _RTCCInterrupt( void )

  Summary:
    Interrupt Service Routine for the RTCC Peripheral

  Description:
    This is the interrupt service routine for the RTCC peripheral. Add in code if 
    required in the ISR. 
*/
void __attribute__ ( ( interrupt, no_auto_psv ) ) _ISR _RTCCInterrupt( void )
{
	// RTCC callback function 
	RTCC_CallBack();
	
    /* TODO : Add interrupt handling code */
    IFS3bits.RTCIF = false;
}
/**
 End of File
*/
