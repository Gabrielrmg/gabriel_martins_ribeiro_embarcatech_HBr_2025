#include "adc_temp.h"

/*
 * Fórmula oficial do datasheet RP2040:
 *   T[°C] = 27 – (Vsense – 0.706 V) / 0.001721 V
 * onde
 *   Vsense = (adc_val / 4095) * VREF
 *   VREF   = 3.3 V
 */
float adc_to_celsius(uint16_t adc_val)
{
    const float VREF    = 3.3f;
    const float ADCMAX  = 4095.0f;
    const float V_AT_27 = 0.706f;
    const float SLOPE   = 0.001721f;

    float vsense = (adc_val * VREF) / ADCMAX;
    return 27.0f - (vsense - V_AT_27) / SLOPE;
}
