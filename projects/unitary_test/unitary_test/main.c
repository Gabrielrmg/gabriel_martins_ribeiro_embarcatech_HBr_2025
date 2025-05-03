#include <stdio.h>
#include <stdint.h>
#include <math.h>

// Função que converte valor ADC (12 bits) para temperatura em Celsius
float adc_to_celsius(uint16_t adc_val) {
    // Fórmula oficial:
    // T = 27 - ((ADC_VAL * 3.3 / 4095) - 0.706) / 0.001721
    float voltage = (adc_val * 3.3f) / 4095.0f;
    float temperature = 27.0f - (voltage - 0.706f) / 0.001721f;
    return temperature;
}

// Função de teste unitário simples
void test_adc_to_celsius() {
    // Valor ADC para 0.706 V (aproximadamente)
    uint16_t adc_test_val = (uint16_t)((0.706f / 3.3f) * 4095);
    float temp = adc_to_celsius(adc_test_val);
    printf("Teste ADC: %u, Temperatura calculada: %.2f °C\n", adc_test_val, temp);

    // Esperado: aproximadamente 27 °C
    if (fabs(temp - 27.0f) < 0.5f) {
        printf("Teste passou! Temperatura está dentro da margem de erro.\n");
    } else {
        printf("Teste falhou! Temperatura fora da margem de erro.\n");
    }
}

int main() {
    // Executa o teste
    test_adc_to_celsius();

    // Aqui você pode adicionar o código para ler o ADC do sensor real e usar adc_to_celsius()
    // Exemplo:
    // uint16_t adc_val = adc_read(); // função hipotética para ler ADC
    // float temperature = adc_to_celsius(adc_val);
    // printf("Temperatura atual: %.2f °C\n", temperature);

    return 0;
}
