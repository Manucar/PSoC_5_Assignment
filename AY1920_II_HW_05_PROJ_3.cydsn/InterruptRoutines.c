/* ===========================================================
 *
 * In this file there is the functioning of the
 * ISR for the reading of the 3 values of acceleration @100Hz 
 *
 * ==========================================================
*/
#include "InterruptRoutines.h"
#include "DataConversion.h"

ErrorCode error; // Store the occurence of an error during the I2C reading

uint8_t status_register; // Store the value of the status register

uint8_t tmpBuffer[BYTE_TO_SEND]; // Temporary buffer to store the read values from the 6 registers
int16_t tmpAxis; // Temporary value to store the actual axis value

uint8_t register_block; // Variable used to cycle over the 3 axis registers[low + high at the same time]

float tmpFloat; // Temporary float value to keep the decimals of the read acceleration

uint8_t *addressFloat; // Pointer variable to store the address of the temporary float variable
 
CY_ISR(Custom_ISR_IMU)
{
    // Read Timer status register to bring interrupt line low
    Timer_ISR_ReadStatusRegister();
    
    // Read the status register in order to verify the readyness of the XYZ data
    error = I2C_Peripheral_ReadRegister(LIS3DH_DEVICE_ADDRESS,
                                        LIS3DH_STATUS_REG,
                                        &status_register);
    
    if (error == NO_ERROR)
    {
        /*  Bitwise mask to check only if the 'ZYXDA' bit in the register is '1', so if there are new available data
            |X X X X X X X X| & |0 0 0 0 1 0 0 0|  --> |0 0 0 0 X 0 0 0|   check if 'X' is '1' after masking
        */
        if((status_register & STATUS_REG_MASK) == STATUS_REG_MASK)
        {  
            // Read in sequence the 6 registers containing the 3-axis values with a multiRead function
            error = I2C_Peripheral_ReadRegisterMulti(LIS3DH_DEVICE_ADDRESS,
                                                     LIS3DH_OUT_X_L,
                                                     REGISTER_COUNT,
                                                     tmpBuffer);
            if (error == NO_ERROR)
            {
                // Loop through the X, Y, Z register block stored in the tmpBuffer
                for(register_block = 0; register_block < 3; register_block++)
                {
                    // Adjust and scale the data read previously in the registers, return a temporary float
                    tmpAxis = RightAdjust(&tmpBuffer[register_block * 2]); // Pass the appropriate address cell to the function
                    
                    // Casting tmpAxis (int6_t) to a float in this scale of values [+-2048] doesn't lost numerical information
                    tmpFloat = MinMaxScaler(MIN_OLD_SCALE, MAX_OLD_SCALE, MIN_NEW_SCALE * GRAVITY, MAX_NEW_SCALE * GRAVITY, (float)tmpAxis);
                    
                    // Save the address of the float value in a uint8_t pointer
                    addressFloat = (uint8_t *) &tmpFloat;
                    
                    // Insert the correct values in the appropriate position [from 1 to 12 of the buffer]
                    // increment the addressFloat in order to point at the next 8 bit of the float variable
                    dataBuffer[register_block*4 + 1] = *addressFloat++;
                    dataBuffer[register_block*4 + 2] = *addressFloat++;
                    dataBuffer[register_block*4 + 3] = *addressFloat++;
                    dataBuffer[register_block*4 + 4] = *addressFloat; // already the last byte pointed, no need to increment more
                }
                
                // Send the data packet over UART
                UART_Debug_PutArray(dataBuffer, TRANSMIT_BUFFER_SIZE);
            }
        }
    }
}


/* [] END OF FILE */
