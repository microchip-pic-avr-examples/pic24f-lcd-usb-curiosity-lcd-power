![image](images/microchip.jpg) 

# PIC24F LCD USB Curiosity Development Board LCD and Power Demo.

## Summary

This is the demo software which runs on PIC24F LCD USB Curiosity Development Board (DM240018). The PIC24F LCD USB Curiosity Development Board is a cost-effective, fully integrated development platform targeted at first-time users, Makers, and those seeking a feature-rich rapid prototyping board. Refer to https://www.microchip.com/pic24flcdusbcuriosity for additional details about the board.


## Related Documentation

- PIC24F GU/GL Low Power MCUs: https://www.microchip.com/PIC24F-GU-GL
- PIC24FJ512GU410 microcontroller https://www.microchip.com/PIC24FJ512GU410


## Hardware Used 

- PIC24F LCD USB Curiosity Development Board (https://www.microchip.com/pic24flcdusbcuriosity) 

## Software Used 

- MPLAB® X IDE v5.40 or newer (https://www.microchip.com/mplabx)
- MPLAB® XC16 v1.50 or newer (https://www.microchip.com/xc)
- MPLAB® Code Configurator v4.0.1 (https://www.microchip.com/mplab/mcc)


## Operation

This example has two main modes of operation 
1. USB powered mode
2. Battery powered mode.

## USB Powered Mode

The display just toggles between the text "PIC24" and "LCD".  This toggling is done automatically by the LCD module using the alternate display mode of the module.  The core sets up the LCD module with the "PIC24" text in the main display memory and the "LCD" text in the alternate display memory and the LCD automatically toggles between the two texts.


## Battery Powered Mode

If the USB power is disconnected, the board can run from a battery backup and will go into battery powered mode.  In order to run in battery mode a CR2032 needs to be inserted in the B1 battery housing and jumper J9 needs a short between pins 2 and 3.

In battery powered mode the moon icon is displayed to indicate that it is in battery mode.  The battery status icon indicates the current battery status.

The time will be displayed on the screen in this mode.  The ":" blinks using the LCD modules blink feature.  The CPU does not need to wake up to update the screen for the ":".

The CPU wakes up once a minute in this mode to update the time on the screen. LED LED1 will blink while the CPU is awake.  The CPU will also wake up when the USB power is detected.

To measure the power consumption of the board, a meter can be placed between the pins 2 and 3 of jumper J9 (that goes to the battery housing.  To measure the current of the CPU, cut the trace on the bottom of the board under jumper J1 and place a meter between the two pins. 

![image](images/pic24f_lcdusbcuriosity.jpg)
