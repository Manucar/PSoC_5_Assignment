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
#include "DataConversion.h"

int16_t RightAdjust(uint8_t *arrayToAdjust)
{
    return (int16_t)((arrayToAdjust[0] | arrayToAdjust[1]<<REGISTER_SIZE))>>SHIFT_SIZE;
}

int16_t MinMaxScaler(float min, float max, float a, float b, float x)
{   
    return (int16_t)((((x - min) * (b - a))/(max - min)) + a);
}

/* [] END OF FILE */
