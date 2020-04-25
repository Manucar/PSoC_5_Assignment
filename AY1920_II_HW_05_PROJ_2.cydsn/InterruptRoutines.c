/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "InterruptRoutines.h"
#include "DataConversion.h"

ErrorCode error;

uint8_t status_register;

uint8_t tmpBuff[6];
int16_t tmpAxis;

uint8_t register_number;

CY_ISR(Custom_ISR_IMU)
{
    // Read Timer status register to bring interrupt line low
    Timer_ISR_ReadStatusRegister();

    error = I2C_Peripheral_ReadRegister(LIS3DH_DEVICE_ADDRESS,
                                        LIS3DH_STATUS_REG,
                                        &status_register);
    
    if (error == NO_ERROR)
    {
        if((status_register & STATUS_REG_MASK) == STATUS_REG_MASK)
        {  
            error = I2C_Peripheral_ReadRegisterMulti(LIS3DH_DEVICE_ADDRESS,
                                                     LIS3DH_OUT_X_L,
                                                     REGISTER_COUNT,
                                                     tmpBuff);
            if (error == NO_ERROR)
            {
                for(register_number = 0; register_number < 3; register_number++)
                {
                    tmpAxis = RightAdjust(&tmpBuff[register_number * 2]);
                    tmpAxis = MinMaxScaler(MIN_OLD_SCALE, MAX_OLD_SCALE, MIN_NEW_SCALE, MAX_NEW_SCALE, tmpAxis);
                    dataBuffer[register_number*2 + 1] = (uint8_t)(tmpAxis & 0xFF);
                    dataBuffer[register_number*2 + 2] = (uint8_t)(tmpAxis >> 8); 
                }
                
                UART_Debug_PutArray(dataBuffer, 8);
            }
        }
    }
}


/* [] END OF FILE */
