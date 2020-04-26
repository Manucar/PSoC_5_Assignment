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
    ║ Content ║ xxxx xxxx ║ xx00 0000 ║
    ╚═════════╩═══════════╩═══════════╝
    
    to:
    ╔═════════╦═════════════════════╗   
    ║ 16int_t ║ 0000 00xx xxxx xxxx ║
    ╚═════════╩═════════════════════╝
*/
int16_t RightAdjust(uint8_t *arrayToAdjust)
{
    return (int16_t)((arrayToAdjust[0] | arrayToAdjust[1]<<REGISTER_SIZE))>>SHIFT_SIZE;
}


/*  Scale the old range in the new range of 'mg' through a MinMaxScaler

    Actually the old range is from -512 to 511 [is a 10bit integet, and the '0' is considered in the positive part], but
    to keep the '0' from the old scale in '0' to the new scale, -512 to 512 scale range was adopted,
    accepting the fact of losing some values in the positive new range (1996 instead of 2000) but this
    doesn't affect the measurement.

    All variables are taken as float for doing the correct operations and then casted to int6_t for the return value.
*/
int16_t MinMaxScaler(float min, float max, float a, float b, float x)
{   
    return (int16_t)((((x - min) * (b - a))/(max - min)) + a);
}

/* [] END OF FILE */
