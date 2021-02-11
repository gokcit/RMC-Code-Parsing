/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F15345
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <string.h>

#define MAXLEN 10 // This will be the size of the buffer

char *ptr[MAXLEN];

int readBuffer(char *ptr[], int nth);

/*
                         Main application
 */

char intToAscii(uint16_t number) {
   return '0' + number;
}
void uitoa(uint16_t Value, uint8_t* Buffer)
{
    uint8_t i;
    bool Printed = false;

    if(Value)
    {
//        for(i = 0; i < 1; i++)
//        {
            *Buffer++ = Value;
            Printed = true;
//        }
    }
    else
    {
        *Buffer++ = '0';
    }

    *Buffer = '\0';
}
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    int i = 0;
    
    // Test line
    while (1)
    {
        // Add your application code
        uint16_t read = EUSART1_Read();
        uint8_t Buffer[10];
        uitoa(read, Buffer);
        printf(Buffer);
        EUSART2_Write(read);
        //EUSART2_Write(read);
//        uint16_t readVal1[10];
//        while(1 == RC1STAbits.OERR && i < 10){
//            readVal1[i] = RC1REG;
//            i++;
//        }
//        if(1 == RC1STAbits.OERR && i > 10){
//            break;
//        }
//        //readVal1 = EUSART1_Read();
//        //uint8_t readVal2 = EUSART2_Read();
//        // Add your application code
//        EUSART1_Write(readVal1);
    }
}
/**
 End of File
*/