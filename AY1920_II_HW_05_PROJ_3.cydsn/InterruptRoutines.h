/* ===================================================
 *
 * In this header file there are the declarations of 
 * some costants and the functions for the ISR
 *
 * ===================================================
*/

#ifndef Interrupt_Routines_H
    #define Interrupt_Routines_H
    
    #include "I2C_Interface.h"
    
    
    #define BYTE_TO_SEND 6  //  2 for X axis + 2 for Y axis + 2 for Z axis
    #define HEADER 0xA0
    #define TAIL 0xC0 
    #define TRANSMIT_BUFFER_SIZE 1+BYTE_TO_SEND+1  // Total packet length in byte: HEADER + BYTE_TO_SEND + TAIL
    
    
    uint8_t dataBuffer[TRANSMIT_BUFFER_SIZE]; // Final buffer with the 3-axis data from the IMU

    volatile uint8_t ready;
    CY_ISR_PROTO(Custom_ISR_IMU); // Custom ISR function prototype definition
    
 #endif

/* [] END OF FILE */
