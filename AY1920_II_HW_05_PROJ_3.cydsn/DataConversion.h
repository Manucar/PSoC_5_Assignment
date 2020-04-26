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
    
    // Range of the old scale, 10 bit signed integer --> 1 bit for the sign and so
    // 9 bits remained for the representable number(512)
    #define MIN_OLD_SCALE -2048
    #define MAX_OLD_SCALE 2048

    // Range for the new scale, in this case +-4 g
    #define MIN_NEW_SCALE -4
    #define MAX_NEW_SCALE 4
    #define GRAVITY 9.81

    // Functions prototype declarations
    int16_t RightAdjust(uint8_t *arrayToAdjust);
    float MinMaxScaler(float min, float max, float a, float b, float x);

#endif


/* [] END OF FILE */
