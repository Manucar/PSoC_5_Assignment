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
#ifndef Data_Conversion_H
    #define Data_Conversion_H
    #include "project.h"
    
    #define REGISTER_SIZE 8
    #define SHIFT_SIZE 6

    #define MIN_OLD_SCALE -512
    #define MAX_OLD_SCALE 512

    #define MIN_NEW_SCALE -2000
    #define MAX_NEW_SCALE 2000

    
    int16_t RightAdjust(uint8_t *arrayToAdjust);
    int16_t MinMaxScaler(float min, float max, float a, float b, float x);

#endif


/* [] END OF FILE */
