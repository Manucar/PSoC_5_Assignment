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
    #define SHIFT_SIZE 6 // Shift size according to the resolution chosen
    
    // Range of the old scale, 10 bit signed integer --> 1 bit for the sign and so
    // 9 bits remained for the representable number(512)
    #define MIN_OLD_SCALE -512
    #define MAX_OLD_SCALE 512

    // Range for the new scale, in this case +-2000 mg
    #define MIN_NEW_SCALE -2000
    #define MAX_NEW_SCALE 2000

    // Functions prototype declarations
    int16_t RightAdjust(uint8_t *arrayToAdjust);
    int16_t MinMaxScaler(float min, float max, float a, float b, float x);

#endif


/* [] END OF FILE */
