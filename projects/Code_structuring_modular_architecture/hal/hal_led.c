#include "hal_led.h"
#include "led_embutido.h"

static bool estado = false;

void hal_led_init(void) {
    led_embutido_init();
}

void hal_led_toggle(void) {
    estado = !estado;
    led_embutido_set(estado);
}
