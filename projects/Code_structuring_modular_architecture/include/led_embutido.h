#ifndef LED_EMBUTIDO_H
#define LED_EMBUTIDO_H

#include <stdbool.h>

// inicializa o hardware do LED (usa cyw43_arch)
void led_embutido_init(void);

// acende/apaga o LED embutido
void led_embutido_set(bool on);

#endif // LED_EMBUTIDO_H
