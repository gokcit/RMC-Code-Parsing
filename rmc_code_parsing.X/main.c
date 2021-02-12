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
#include <stdlib.h>

#define MAXLEN 10 // This will be the size of the buffer

char *ptr[MAXLEN];

int readBuffer(char *ptr[], int nth);

/*
                         Main application
 */


void parsing(uint16_t Value, uint8_t* Buffer)
{
    uint8_t i;
    bool Printed = false;

    if(Value)
    {
        *Buffer++ = Value;
        Printed = true;


    }
//    else
//    {
//        *Buffer++ = '0';
//    }

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
    
    char sentence[80] = "17,0*6A"
                "$GPTXT,01,01,02,ANTSTATUS=OPEN*2B"
                "17,0*6A"
                "$GPRMC,172118.081,V,,,,,0.00,172.60,120221,,,N,V*32"
                "$GPVTG,172.60,T,,M,0.00,N,0.00,K,N*30"
                "0221,,,N,V*32"
                "$GPGGA,172118.081,,,,,0,0,,,M,,M,,*4D"
                "0221,,,N,V*32"
                "$GPGSA,A,1,,,,,,,,,,,,,,,,1*03"
                "M,,*4D"
                "0221,,,N,V*32"
                "$GPGSA,A,1,,,,,,,,,,,,,,,,2*00"
                "$GPGSV,1,1,03,16,,,30,04,,,18,03,,,16,0*6B"
                "$GLGSV,1,1,02,73,,,28,75,,,20,1*74"
                "16,0*6B"
                "$GPGLL,,,,,172118.081,V,N*7F"
                ",1*74"
                "16,0*6B"
                "$GPTXT,01,01,02,ANTSTATUS=OPEN*2B"
                "16,0*6B"
                "$GPRMC,172125.081,V,,,,,0.00,172.60,120221,,,N,V*3C"
                "$GPVTG,172.60,T,,M,0.00,N,0.00,K,N*30";
    puts(sentence);
    char s1[] = "$GPRM"; 
    
//    char *position_ptr_sub = strstr(sentence, s1);
//    printf("Position Pointer index: %4d and Character: %s\r\n", *position_ptr_sub, *position_ptr_sub);

    int temp_position;
    
    for (int i = 0; i < strlen(s1); i++)
	{
		char *position_ptr = strchr(sentence, s1[i]);
        if (*position_ptr) {
            printf("Position Pointer: %c\r\n", *position_ptr);
            if(!(position_ptr - sentence - 1 == temp_position)){
            
                break;
            }
            temp_position = position_ptr - sentence;
        }
        
        
        //printf("Position Pointer index: %4d and Character: %c\r\n", *position_ptr, *position_ptr);
		int position = (position_ptr == NULL ? -1 : position_ptr - sentence);
        
//            temp_position = position;
//        }
//        else{
//            position -= i;
//            temp_position = position;
//            i = 0;
//        }
        
		printf("%4c: %4d\r\n", s1[i], position);
	}
    while (1) {
        // Add your application code
        uint16_t read = EUSART1_Read();
        uint8_t Buffer[10];
        parsing(read, Buffer);
        //printf(Buffer);
        
        
//        char *p; 
////
////        // Find first occurrence of s2 in s1 
//        p = strstr(sentence, s1); 
////
////        // Prints the result 
//        if (p) { 
//            printf("First occurrence of string '%s' is '%s'\r\n", s1, p); 
//        }
        //break;
//        //printf(Buffer);
//        //char* p; 
//        char ch1 = '$';
//        //char s1[] = "$G";
//        
//        p = strstr(Buffer, s1);
//        if(p){
//            printf("Test 3: %s", p);
//        }
//        
//        p = strchr(Buffer, ch1);
//        if(p){
//            printf("Test 4: %c\r\n", *p);
//        }
//        
//        //char *character = strchr(Buffer, '$');
//        //char *string[5] = strstr(Buffer, "$G");
//        if(*strchr(Buffer, '$') == '$'){
//            printf("Test 1: %c\r\n", *strchr(Buffer, '$'));
//        }
//        if(*strstr(Buffer, "$G")){
//            printf("Test 2: %s\r\n", *strstr(Buffer, "$G"));
//        
//        }
        
    }
    
    
    
    
//    int i = 0;
//    int char_counter = 0;
//    bool word_is_read = false;
//    // Test line
//    uint8_t Buffer[10];
//    while (1){
//        
//        uint16_t read = EUSART1_Read();
////        if(*strchr(read, '\n') == '\n'){
////            RC1REG = 0x00;
////        }
//
//        parsing(read, Buffer, char_counter);
//        printf(Buffer);
////        if(*strchr(Buffer, '\n') == '\n'){
////            //printf("The end. %c", *strchr(Buffer, '\n'));
////            printf("The end.\r\n");
////            break;
//////            //flag = false;
//////            PIE3bits.RC1IE = 1;
//////            PIE3bits.TX1IE = 1;
//////            PIR3bits.RC2IF = 1;
//////            PIR3bits.TX2IF = 1;
//////            //printf("%s", Buffer);
//////            //break;
////////            TX2STAbits.TXEN = 1;
////////            PIR3bits.TX2IF = 1;
//////            
////        }
//        if(*strchr(Buffer, "$GPRMC") == "$GPRMC"){
//            printf("This is a valid sentence that starts with: %s!\r\n", *strchr(Buffer, "$GPRMC"));
//        }
//        
//        
//        
//        
//        
//        //printf(Buffer);
//        
//        //printf(Buffer);
//        //printf(Buffer);
//        //EUSART2_Write(read);
//        //EUSART2_Write(read);
//    //        uint16_t readVal1[10];
//    //        while(1 == RC1STAbits.OERR && i < 10){
//    //            readVal1[i] = RC1REG;
//    //            i++;
//    //        }
//    //        if(1 == RC1STAbits.OERR && i > 10){
//    //            break;
//    //        }
//    //        //readVal1 = EUSART1_Read();
//    //        //uint8_t readVal2 = EUSART2_Read();
//    //        // Add your application code
//    //        EUSART1_Write(readVal1);
//    }
}
/**
 End of File
*/