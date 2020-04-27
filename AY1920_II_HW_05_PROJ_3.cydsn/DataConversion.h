/* ======================================================
 * 
 * In this header file there are the declarations of 
 * some costants and the functions for the data conversion
 *
 * ======================================================
*/
#ifndef Data_Conversion_H
    #define Data_Conversion_H
    #include "project.h"
    
    #define REGISTER_SIZE 8 // Register size in bit
    #define SHIFT_SIZE 4 // Shift size according to the resolution chosen [High mode]
    
    // Range of the old scale, 12 bit signed integer --> 1 bit for the sign and so
    // 1 bits remained for the representable number(2048)
    #define MIN_OLD_SCALE -2048
    #define MAX_OLD_SCALE 2048

    // Range for the new scale, in this case +-4 g
    #define MIN_NEW_SCALE -4
    #define MAX_NEW_SCALE 4
    #define GRAVITY 9.81
    
    // Desired decimal precision to keep from the float
    #define DECIMAL_PRECISION 10000

    // Functions prototype declarations
    int16_t RightAdjust(uint8_t *arrayToAdjust);
    float MinMaxScaler(float min, float max, float a, float b, float x);
    uint8_t ByteSelection(int32_t value, uint8_t byteNumber);

#endif


/* [] END OF FILE */
