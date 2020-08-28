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

#include <xc.h>

#include "lcd1_segments.h"

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

static uint8_t CharTo7Seg(char input_character)
{
    if(   (input_character < 0x20) 
       || (input_character > 0x7F) )
    {
        return decoder_7_segment[0];
    }
    
    return decoder_7_segment[input_character - 0x20];
}

/************* Char1 **************/

void LCD1_Char1_Print(char c) 
{
    uint8_t data = CharTo7Seg(c);
    
    LCD1_Char1A_Set(data & 0x01);
    data >>= 1;
    LCD1_Char1B_Set(data & 0x01);
    data >>= 1;
    LCD1_Char1C_Set(data & 0x01);
    data >>= 1;
    LCD1_Char1D_Set(data & 0x01);
    data >>= 1;
    LCD1_Char1E_Set(data & 0x01);
    data >>= 1;
    LCD1_Char1F_Set(data & 0x01);
    data >>= 1;
    LCD1_Char1G_Set(data & 0x01);
}

/* AltPrint is used for blinking and alternate screen modes.  This sets which
 * segments will be active in this alternate functionality. */
void LCD1_Char1_AltPrint(char c) 
{
    uint8_t data = CharTo7Seg(c);
    
    LCD1_Char1A_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char1B_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char1C_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char1D_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char1E_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char1F_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char1G_AltSet(data & 0x01);
}

/************* Char2 **************/

void LCD1_Char2_Print(char c) 
{
    uint8_t data = CharTo7Seg(c);
    
    LCD1_Char2A_Set(data & 0x01);
    data >>= 1;
    LCD1_Char2B_Set(data & 0x01);
    data >>= 1;
    LCD1_Char2C_Set(data & 0x01);
    data >>= 1;
    LCD1_Char2D_Set(data & 0x01);
    data >>= 1;
    LCD1_Char2E_Set(data & 0x01);
    data >>= 1;
    LCD1_Char2F_Set(data & 0x01);
    data >>= 1;
    LCD1_Char2G_Set(data & 0x01);
}

/* AltPrint is used for blinking and alternate screen modes.  This sets which
 * segments will be active in this alternate functionality. */
void LCD1_Char2_AltPrint(char c) 
{
    uint8_t data = CharTo7Seg(c);
    
    LCD1_Char2A_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char2B_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char2C_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char2D_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char2E_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char2F_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char2G_AltSet(data & 0x01);
}

/************* Char3 **************/

void LCD1_Char3_Print(char c) 
{
    uint8_t data = CharTo7Seg(c);
    
    LCD1_Char3A_Set(data & 0x01);
    data >>= 1;
    LCD1_Char3B_Set(data & 0x01);
    data >>= 1;
    LCD1_Char3C_Set(data & 0x01);
    data >>= 1;
    LCD1_Char3D_Set(data & 0x01);
    data >>= 1;
    LCD1_Char3E_Set(data & 0x01);
    data >>= 1;
    LCD1_Char3F_Set(data & 0x01);
    data >>= 1;
    LCD1_Char3G_Set(data & 0x01);
}

/* AltPrint is used for blinking and alternate screen modes.  This sets which
 * segments will be active in this alternate functionality. */
void LCD1_Char3_AltPrint(char c) 
{
    uint8_t data = CharTo7Seg(c);
    
    LCD1_Char3A_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char3B_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char3C_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char3D_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char3E_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char3F_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char3G_AltSet(data & 0x01);
}

/************* Char4 **************/

void LCD1_Char4_Print(char c) 
{
    uint8_t data = CharTo7Seg(c);
    
    LCD1_Char4A_Set(data & 0x01);
    data >>= 1;
    LCD1_Char4B_Set(data & 0x01);
    data >>= 1;
    LCD1_Char4C_Set(data & 0x01);
    data >>= 1;
    LCD1_Char4D_Set(data & 0x01);
    data >>= 1;
    LCD1_Char4E_Set(data & 0x01);
    data >>= 1;
    LCD1_Char4F_Set(data & 0x01);
    data >>= 1;
    LCD1_Char4G_Set(data & 0x01);
}

/* AltPrint is used for blinking and alternate screen modes.  This sets which
 * segments will be active in this alternate functionality. */
void LCD1_Char4_AltPrint(char c) 
{
    uint8_t data = CharTo7Seg(c);
    
    LCD1_Char4A_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char4B_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char4C_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char4D_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char4E_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char4F_AltSet(data & 0x01);
    data >>= 1;
    LCD1_Char4G_AltSet(data & 0x01);
}
