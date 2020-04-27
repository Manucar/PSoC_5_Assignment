/* =========================================================
 * 
 * The following functions are used for the data conversion
 *
 * =========================================================
*/
#include "DataConversion.h"


/*  Right justify in a 16 bit integer:
    
    from:
    ╔═════════╦═══════════╦═══════════╗
    ║         ║  OUT_X_H  ║  OUT_X_L  ║
    ╠═════════╬═══════════╬═══════════╣
    ║ Content ║ xxxx xxxx ║ xxxx 0000 ║
    ╚═════════╩═══════════╩═══════════╝
    
    to:
    ╔═════════╦═════════════════════╗   
    ║ 16int_t ║ 0000 xxxx xxxx xxxx ║
    ╚═════════╩═════════════════════╝
*/
int16_t RightAdjust(uint8_t *arrayToAdjust)
{
    return (int16_t)((arrayToAdjust[0] | arrayToAdjust[1] << REGISTER_SIZE)) >> SHIFT_SIZE;
}


/*  Scale the old range in the new range[-4*9.81 m/s^2 + 4*9.81 m/s^2] through a MinMaxScaler

    Actually the old range is from -2048 to 2047 [is a 12bit integer, and the '0' is considered in the positive part], but
    to keep the '0' from the old scale in '0' to the new scale, -2048 to 2048 scale range was adopted,
    accepting the fact of losing some values in the positive new range but this doesn't affect the measurement.

    All variables are taken as float for executing the correct operations and then return the final float value.
*/
float MinMaxScaler(float min, float max, float a, float b, float x)
{   
    return (float)((((x - min) * (b - a))/(max - min)) + a);
}

// Select the desired byte from the given int32
uint8_t ByteSelection(int32_t value, uint8_t byteNumber)
{
    return (uint8_t)((value >> 8 * byteNumber) & 0xFF);
}

/* [] END OF FILE */
