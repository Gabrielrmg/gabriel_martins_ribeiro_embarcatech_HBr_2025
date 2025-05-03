#include "led_embutido.h"
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

void led_embutido_init(void) {
    stdio_init_all();             // opcional, só se precisar de printf
    cyw43_arch_init();            // inicializa a pilha CYW43 (Wi-Fi + GPIO do LED)
}

void led_embutido_set(bool on) {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, on ? 1 : 0);
}
