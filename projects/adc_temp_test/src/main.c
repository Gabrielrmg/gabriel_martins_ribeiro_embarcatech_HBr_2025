#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "adc_temp.h"

int main(void)
{
    stdio_init_all();

    // inicializa ADC e sensor interno
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);  // canal 4 = sensor

    while (true) {
        uint16_t raw  = adc_read();
        float temp    = adc_to_celsius(raw);
        printf("Temp: %.2f °C  (raw=%u)\r\n", temp, raw);
        sleep_ms(1000);
    }
}
