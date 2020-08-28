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


// FSEC
#pragma config BWRP = OFF               // Boot Segment Write-Protect bit (Boot Segment may be written)
#pragma config BSS = DISABLED           // Boot Segment Code-Protect Level bits (No Protection (other than BWRP))
#pragma config BSEN = OFF               // Boot Segment Control bit (No Boot Segment)
#pragma config GWRP = OFF               // General Segment Write-Protect bit (General Segment may be written)
#pragma config GSS = DISABLED           // General Segment Code-Protect Level bits (No Protection (other than GWRP))
#pragma config CWRP = OFF               // Configuration Segment Write-Protect bit (Configuration Segment may be written)
#pragma config CSS = DISABLED           // Configuration Segment Code-Protect Level bits (No Protection (other than CWRP))
#pragma config AIVTDIS = OFF            // Alternate Interrupt Vector Table bit (Disabled AIVT)

// FBSLIM
#pragma config BSLIM = 0x1FFF           // Boot Segment Flash Page Address Limit bits (Enter Hexadecimal value)

// FOSCSEL
#pragma config FNOSC = FRCPLL           // Oscillator Source Selection (Primary Oscillator with PLL module (XT + PLL, HS + PLL, EC + PLL))
#pragma config PLLMODE = PLL96DIV2      // PLL Mode Selection (96 MHz PLL. Oscillator input is divided by 2 (8 MHz input))
#pragma config IESO = OFF               // Two-speed Oscillator Start-up Enable bit

// FOSC
#pragma config POSCMD = NONE              // Primary Oscillator Mode Select bits (EC (External Clock) mode)
#pragma config OSCIOFCN = OFF           // OSC2 Pin Function bit (RC14 (CLKO) outputs CPU clock)
#pragma config SOSCEN = ON              // SOSC Power Selection Configuration bits (SOSC crystal driver is enabled (SOSCI/SOSCO mode))
#pragma config PLLSS = PRI              // PLL Secondary Selection Configuration bit (PLL is fed by the Primary oscillator)
#pragma config IOL1WAY = ON             // Peripheral pin select configuration bit (Allow only one reconfiguration)
#pragma config FCKSM = CSDCMD           // Clock Switching Mode bits (Both Clock switching and Fail-safe Clock Monitor are disabled)

// FWDT
#pragma config WDTPS = PS32768          // Watchdog Timer Postscaler bits (1:32,768)
#pragma config FWPSA = PR128            // Watchdog Timer Prescaler bit (1:128)
#pragma config FWDTEN = ON              // Watchdog Timer Enable bits (WDT is always enabled (cannot be controlled by SWDTEN))
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable bit (WDT in non-windowed mode)
#pragma config WDTWIN = WIN25           // Watchdog Timer Window Select bits (WDT window is 25% of WDT period)
#pragma config WDTCMX = WDTCLK          // WDT MUX Source Select bits (WDT clock source is determined by the WDTCLK Configuration bits)
#pragma config WDTCLK = LPRC            // WDT Clock Source Select bits (WDT uses LPRC)

// FPOR
#pragma config BOREN = OFF               // Brown Out Enable bit (Brown Out is disabled)
#pragma config LPREGEN = OFF            // Low power regulator control (Low power regulator is disabled)
#pragma config LPBOREN = OFF             // Downside Voltage Protection Enable bit (Low power BOR is enabled when BOR is inactive)

// FICD
#pragma config ICS = PGD1               // ICD Communication Channel Select bits (Communicate on PGEC1 and PGED1)
#pragma config JTAGEN = OFF              // JTAG Enable bit (JTAG is disabled)
#pragma config BTSWP = OFF              //  (BOOTSWP instruction is disabled)

// FDMTIVTL
#pragma config DMTIVTL = 0xFFFF         //  (Enter Hexadecimal value)

// FDMTIVTH
#pragma config DMTIVTH = 0xFFFF         //  (Enter Hexadecimal value)

// FDMTCNTL
#pragma config DMTCNTL = 0xFFFF         //  (Enter Hexadecimal value)

// FDMTCNTH
#pragma config DMTCNTH = 0xFFFF         //  (Enter Hexadecimal value)

// FDMT
#pragma config DMTDIS = OFF             //  (Dead Man Timer is disabled and can be enabled by software)

// FDEVOPT1
#pragma config ALTCMPI = OFF            // Alternate Comparator Input Enable bit (C2INC and C3INC are on RG9 and RD11)
#pragma config TMPRPIN = OFF            // Tamper Pin Enable bit (TMPRN pin function is disabled)
#pragma config SOSCHP = ON              // SOSC High Power Enable bit (valid only when SOSCSEL = 1 (SOSC high power mode (default))
#pragma config ALTI2C1 = OFF            // Alternate I2C pin Location (SDA1 and SCL1 on RA15 and RA14)
