#ifndef HAL_LED_H
#define HAL_LED_H

#include <stdbool.h>

// inicializa a HAL de LED (internamente chama led_embutido_init)
void hal_led_init(void);

// alterna o estado do LED (internamente chama led_embutido_set)
void hal_led_toggle(void);

#endif // HAL_LED_H
