#include <stdio.h>
#include <stdint.h>
#include <math.h>

#include "pico/stdlib.h"
#include "hardware/adc.h"

// converte ADC (12‑bit) em °C
float adc_to_celsius(uint16_t adc_val) {
    float voltage = (adc_val * 3.3f) / 4095.0f;
    return 27.0f - (voltage - 0.706f) / 0.001721f;
}

int main() {
    stdio_init_all();        // inicializa USB serial ou UART
    adc_init();              // inicializa o bloco ADC
    adc_gpio_init(26);       // opcional se for sensor externo no GPIO26
    adc_select_input(4);     // canal 4 = sensor de temperatura interna

    sleep_ms(1000);
    printf("Iniciando leitura de temperatura...\n");

    while (true) {
        uint16_t raw = adc_read();           // lê 0..4095
        float temp = adc_to_celsius(raw);
        printf("ADC=%4u  Temp=%.2f °C\n", raw, temp);
        sleep_ms(1000);
    }

    return 0;
}
