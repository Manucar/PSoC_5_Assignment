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
    
    
    #define BYTE_TO_SEND 12  // 4 for X axis + 4 for Y axis + 4 for Z axis
    #define HEADER 0xA0
    #define TAIL 0xC0 
    #define TRANSMIT_BUFFER_SIZE 1+BYTE_TO_SEND+1  // Total packet length in byte: HEADER + BYTE_TO_SEND + TAIL
    
    volatile uint8 PacketReadyFlag;  // Variable containing the status of the packet [0 not ready, 1 ready]
    uint8_t dataBuffer[TRANSMIT_BUFFER_SIZE]; // Final buffer with the 3-axis data from the IMU

    CY_ISR_PROTO(Custom_ISR_IMU); // Custom ISR function prototype definition
    
 #endif

/* [] END OF FILE */
