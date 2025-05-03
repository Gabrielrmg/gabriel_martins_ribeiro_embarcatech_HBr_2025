#ifndef ADC_TEMP_H
#define ADC_TEMP_H

#include <stdint.h>

/**
 * Converte a leitura bruta de 12 bits do ADC interno
 * (sensor de temperatura do RP2040) para graus Celsius.
 *
 * @param adc_val  valor lido (0 – 4095)
 * @return temperatura em °C
 */
float adc_to_celsius(uint16_t adc_val);

#endif /* ADC_TEMP_H */
