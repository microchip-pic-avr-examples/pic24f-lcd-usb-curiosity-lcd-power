/**
  LCD Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    lcd_7seg.c

  @Summary
    This is the generated driver implementation file for the LCD driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This source file provides APIs for LCD.
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
#include "lcd_segments.h"

/**
 Section: File specific functions and data types
*/
static uint8_t decoder_7_segment[] = 
{ 
    //-GFEDCBA
    0b00000000, //0x20 = ' '
    0b00000110, //0x21 = '!'
    0b00100010, //0x22 = '"'
    0b01000001, //0x23 = '#'
    0b01001001, //0x24 = '$'
    0b01010010, //0x25 = '%'
    0b01000110, //0x26 = '&'
    0b00100000, //0x27 = '''
    0b00111001, //0x28 = '('
    0b00001111, //0x29 = ')'
    0b00100001, //0x2A = '*'
    0b01110000, //0x2B = '+'
    0b00010000, //0x2C = ','
    0b01000000, //0x2D = '-'
    0b00000100, //0x2E = '.'
    0b01010010, //0x2F = '/'
    
    //-GFEDCBA
    0b00111111, //0x30 = '0'
    0b00000110, //0x31 = '1'
    0b01011011, //0x32 = '2'
    0b01001111, //0x33 = '3'
    0b01100110, //0x34 = '4'
    0b01101101, //0x35 = '5'
    0b01111101, //0x36 = '6'
    0b00100111, //0x37 = '7'
    0b01111111, //0x38 = '8'
    0b01101111, //0x39 = '9'
    0b00001001, //0x3A = ':'
    0b00001101, //0x3B = ';'
    0b01100001, //0x3C = '<'
    0b01001000, //0x3D = '='
    0b01000011, //0x3E = '>'
    0b01010011, //0x3F = '?'
    
    //-GFEDCBA
    0b01011111, //0x40 = '@'
    0b01110111, //0x41 = 'A'
    0b01111100, //0x42 = 'B'
    0b00111001, //0x43 = 'C'
    0b01011110, //0x44 = 'D'
    0b01111001, //0x45 = 'E'
    0b01110001, //0x46 = 'F'
    0b00111101, //0x47 = 'G'
    0b01110110, //0x48 = 'H'
    0b00110000, //0x49 = 'I'
    0b00011110, //0x4A = 'J'
    0b01110101, //0x4B = 'K'
    0b00111000, //0x4C = 'L'
    0b00010101, //0x4D = 'M'
    0b00110111, //0x4E = 'N'
    0b00111111, //0x4F = 'O'
    
    //-GFEDCBA
    0b01110011, //0x50 = 'P'
    0b01101011, //0x51 = 'Q'
    0b00110011, //0x52 = 'R'
    0b01101101, //0x53 = 'S'
    0b01111000, //0x54 = 'T'
    0b00111110, //0x55 = 'U'
    0b00111110, //0x56 = 'V'
    0b00101010, //0x57 = 'W'
    0b01110110, //0x58 = 'X'
    0b01101110, //0x59 = 'Y'
    0b01011011, //0x5A = 'Z'
    0b00111001, //0x5B = '['
    0b01100100, //0x5C = '\'
    0b00001111, //0x5D = ']'
    0b00100011, //0x5E = '^'
    0b00001000, //0x5F = '_'
    
    //-GFEDCBA
    0b00000010, //0x60 = '`'
    0b01011111, //0x61 = 'a'
    0b01111100, //0x62 = 'b'
    0b01011000, //0x63 = 'c'
    0b01011110, //0x64 = 'd'
    0b01111011, //0x65 = 'e'
    0b01110001, //0x66 = 'f'
    0b01101111, //0x67 = 'g'
    0b01110100, //0x68 = 'h'
    0b00010000, //0x69 = 'i'
    0b00001100, //0x6A = 'j'
    0b01110110, //0x6B = 'k'
    0b00110000, //0x6C = 'l'
    0b00010100, //0x6D = 'm'
    0b01010100, //0x6E = 'n'
    0b01011100, //0x6F = 'o'
   
    //-GFEDCBA
    0b01110011, //0x70 = 'p'
    0b01100111, //0x71 = 'q'
    0b01010000, //0x72 = 'r'
    0b01101101, //0x73 = 's'
    0b01111000, //0x74 = 't'
    0b00011100, //0x75 = 'u'
    0b00011100, //0x76 = 'v'
    0b00010100, //0x77 = 'w'
    0b01110110, //0x78 = 'x'
    0b01101110, //0x79 = 'y'
    0b01011011, //0x7A = 'z'
    0b00111001, //0x7B = '{'
    0b00000110, //0x7C = '|'
    0b00001111, //0x7D = '}'
    0b01000000, //0x7E = '~'
    0b00000000, //0x7F = 'DEL'
};

static uint8_t CharTo7Seg(char inputCharacter);

/**
 Section: Driver Interface Function Definitions
*/

static uint8_t CharTo7Seg(char inputCharacter)
{
    if(   (inputCharacter < 0x20) 
       || (inputCharacter > 0x7F) )
    {
        return decoder_7_segment[0];
    }
    
    return decoder_7_segment[inputCharacter - 0x20];
}

void LCD_CHAR4_Print(char cData) 
{
    uint8_t data = CharTo7Seg(cData);

    CHAR4_A_Set(data & 0x01);
    data >>= 1;
    CHAR4_B_Set(data & 0x01);
    data >>= 1;
    CHAR4_C_Set(data & 0x01);
    data >>= 1;
    CHAR4_D_Set(data & 0x01);
    data >>= 1;
    CHAR4_E_Set(data & 0x01);
    data >>= 1;
    CHAR4_F_Set(data & 0x01);
    data >>= 1;
    CHAR4_G_Set(data & 0x01);
}

/* AltPrint is used for blinking and alternate screen modes.  This sets which
 * segments will be active in this alternate functionality. */
void LCD_CHAR4_AltPrint(char cData) 
{
    uint8_t data = CharTo7Seg(cData);
    
    CHAR4_A_AltSet(data & 0x01);
    data >>= 1;
    CHAR4_B_AltSet(data & 0x01);
    data >>= 1;
    CHAR4_C_AltSet(data & 0x01);
    data >>= 1;
    CHAR4_D_AltSet(data & 0x01);
    data >>= 1;
    CHAR4_E_AltSet(data & 0x01);
    data >>= 1;
    CHAR4_F_AltSet(data & 0x01);
    data >>= 1;
    CHAR4_G_AltSet(data & 0x01);
}

void LCD_CHAR1_Print(char cData) 
{
    uint8_t data = CharTo7Seg(cData);

    CHAR1_A_Set(data & 0x01);
    data >>= 1;
    CHAR1_B_Set(data & 0x01);
    data >>= 1;
    CHAR1_C_Set(data & 0x01);
    data >>= 1;
    CHAR1_D_Set(data & 0x01);
    data >>= 1;
    CHAR1_E_Set(data & 0x01);
    data >>= 1;
    CHAR1_F_Set(data & 0x01);
    data >>= 1;
    CHAR1_G_Set(data & 0x01);
}

/* AltPrint is used for blinking and alternate screen modes.  This sets which
 * segments will be active in this alternate functionality. */
void LCD_CHAR1_AltPrint(char cData) 
{
    uint8_t data = CharTo7Seg(cData);
    
    CHAR1_A_AltSet(data & 0x01);
    data >>= 1;
    CHAR1_B_AltSet(data & 0x01);
    data >>= 1;
    CHAR1_C_AltSet(data & 0x01);
    data >>= 1;
    CHAR1_D_AltSet(data & 0x01);
    data >>= 1;
    CHAR1_E_AltSet(data & 0x01);
    data >>= 1;
    CHAR1_F_AltSet(data & 0x01);
    data >>= 1;
    CHAR1_G_AltSet(data & 0x01);
}

void LCD_CHAR3_Print(char cData) 
{
    uint8_t data = CharTo7Seg(cData);

    CHAR3_A_Set(data & 0x01);
    data >>= 1;
    CHAR3_B_Set(data & 0x01);
    data >>= 1;
    CHAR3_C_Set(data & 0x01);
    data >>= 1;
    CHAR3_D_Set(data & 0x01);
    data >>= 1;
    CHAR3_E_Set(data & 0x01);
    data >>= 1;
    CHAR3_F_Set(data & 0x01);
    data >>= 1;
    CHAR3_G_Set(data & 0x01);
}

/* AltPrint is used for blinking and alternate screen modes.  This sets which
 * segments will be active in this alternate functionality. */
void LCD_CHAR3_AltPrint(char cData) 
{
    uint8_t data = CharTo7Seg(cData);
    
    CHAR3_A_AltSet(data & 0x01);
    data >>= 1;
    CHAR3_B_AltSet(data & 0x01);
    data >>= 1;
    CHAR3_C_AltSet(data & 0x01);
    data >>= 1;
    CHAR3_D_AltSet(data & 0x01);
    data >>= 1;
    CHAR3_E_AltSet(data & 0x01);
    data >>= 1;
    CHAR3_F_AltSet(data & 0x01);
    data >>= 1;
    CHAR3_G_AltSet(data & 0x01);
}

void LCD_CHAR2_Print(char cData) 
{
    uint8_t data = CharTo7Seg(cData);

    CHAR2_A_Set(data & 0x01);
    data >>= 1;
    CHAR2_B_Set(data & 0x01);
    data >>= 1;
    CHAR2_C_Set(data & 0x01);
    data >>= 1;
    CHAR2_D_Set(data & 0x01);
    data >>= 1;
    CHAR2_E_Set(data & 0x01);
    data >>= 1;
    CHAR2_F_Set(data & 0x01);
    data >>= 1;
    CHAR2_G_Set(data & 0x01);
}

/* AltPrint is used for blinking and alternate screen modes.  This sets which
 * segments will be active in this alternate functionality. */
void LCD_CHAR2_AltPrint(char cData) 
{
    uint8_t data = CharTo7Seg(cData);
    
    CHAR2_A_AltSet(data & 0x01);
    data >>= 1;
    CHAR2_B_AltSet(data & 0x01);
    data >>= 1;
    CHAR2_C_AltSet(data & 0x01);
    data >>= 1;
    CHAR2_D_AltSet(data & 0x01);
    data >>= 1;
    CHAR2_E_AltSet(data & 0x01);
    data >>= 1;
    CHAR2_F_AltSet(data & 0x01);
    data >>= 1;
    CHAR2_G_AltSet(data & 0x01);
}





