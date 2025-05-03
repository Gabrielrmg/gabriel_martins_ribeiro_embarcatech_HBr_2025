#include "adc.h"
#include <stdio.h>
#include <math.h>

int main(void) {
    uint16_t adc_example = (uint16_t)roundf(0.706f / 3.3f * 4095.0f);
    float temp = adc_to_celsius(adc_example);

    printf("Leitura ADC: %u → Temperatura: %.3f °C\n", adc_example, temp);

    if (fabsf(temp - 27.0f) <= 0.1f) {
        printf("Teste OK!\n");
        return 0;
    } else {
        printf("Teste FALHOU!\n");
        return 1;
    }
}

