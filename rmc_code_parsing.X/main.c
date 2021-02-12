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
#include <stdbool.h>

#define MAXLEN 10 // This will be the size of the buffer

char *ptr[MAXLEN];

int readBuffer(char *ptr[], int nth);

/*
                         Main application
 */


void parsing(uint16_t Value, uint8_t* Buffer, int char_counter)
{
    uint8_t i;
    bool Printed = false;

    if(Value)
    {
        *Buffer++ = Value;
        Printed = true;
//        if(char_counter == 0 && Value == '$'){
//            char_counter += 1;
//            printf("Sentence starts... ");
//            printf("Character found: %c\r\n", Value);
            //printf("%i", char_counter);
//        }
//        if(Value == '\n'){
//            printf("End of the sentence.\r\n");
//            char_counter = 0;
//        }

    }
    else
    {
        *Buffer++ = '0';
    }

    *Buffer = '\0';
}

//void print(char *C){
//    while(*C != '\0'){
//        if(*C == '$') {
//            printf("Sentence started");
//        }
//        printf("%c",*C);
//        C++;
//    }
//    printf("\r\n");
//    
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
    int char_counter = 0;
    bool word_is_read = false;
    // Test line
    uint8_t Buffer[10];
    while (1){
        
        // Add your application code
        if(word_is_read){
            
        }
        else{
            uint16_t read = EUSART1_Read(); 
            parsing(read, Buffer, char_counter);
            word_is_read = true;
        }
        
        
        //printf(Buffer);
        if(*strchr(Buffer, '\n') == '\n'){
            //printf("The end. %c", *strchr(Buffer, '\n'));
            printf("The end.\r\n");
//            //flag = false;
//            PIE3bits.RC1IE = 1;
//            PIE3bits.TX1IE = 1;
//            PIR3bits.RC2IF = 1;
//            PIR3bits.TX2IF = 1;
//            //printf("%s", Buffer);
//            //break;
////            TX2STAbits.TXEN = 1;
////            PIR3bits.TX2IF = 1;
//            
        }
        if(*strchr(Buffer, '$') == '$'){
            printf("This is a valid sentence that starts with: %c!\r\n", *strchr(Buffer, '$'));
        }
        //printf(Buffer);
        //printf(Buffer);
        //EUSART2_Write(read);
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