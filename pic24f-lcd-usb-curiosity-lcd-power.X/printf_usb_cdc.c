#include "mcc_generated_files/usb/usb.h"
#include "mcc_generated_files/usb/usb_device_cdc.h"

int __attribute__((__section__(".libc.write"))) write(int handle, void *buffer, unsigned int len) {
    unsigned int remaining = len;
    uint8_t to_send;
    
    if( USBGetDeviceState() < CONFIGURED_STATE )
    {
        return 0;
    }
    
    while(remaining != 0)
    {
        while(USBUSARTIsTxTrfReady() == false)
        {
            CDCTxService();
            #if defined(USB_POLLING)
                USBDeviceTasks();
            #endif
        }
        
        if(remaining <= 255)
        {
            to_send = (uint8_t) remaining;
        }
        else
        {
            to_send = 255;
        }

        putUSBUSART(buffer, to_send);
        
        remaining -= to_send;
    }
    
    //make sure last transfer goes out before completing.
    while(USBUSARTIsTxTrfReady() == false)
    {
        CDCTxService();
        #if defined(USB_POLLING)
            USBDeviceTasks();
        #endif
    }
    
    return len;
}
