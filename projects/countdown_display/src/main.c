// === Project: Countdown with OLED using Raspberry Pi Pico W ===
// Description: Displays a countdown timer on a 128x64 OLED screen with control via buttons
// Author: Gabriel Martins Ribeiro | Date: 2025-04-15

#include "pico/stdlib.h"                      // Standard Pico library
#include "hardware/i2c.h"                      // I2C communication
#include "hardware/gpio.h"                     // GPIO control
#include "hardware/irq.h"                      // Interrupt handling
#include "hardware/timer.h"                    // Timer library
#include <stdio.h>                             // Standard Input/Output
#include "ssd1306.h"                           // OLED display driver
#include "font.h"                              // Font rendering

#define I2C_PORT        i2c1                   // Use I2C1 peripheral
#define I2C_SDA_PIN     14                    // SDA on GPIO14
#define I2C_SCL_PIN     15                    // SCL on GPIO15
#define OLED_ADDR       0x3C                  // I2C address of the OLED display

#define BUTTON_A_PIN    5                     // Button A on GPIO5
#define BUTTON_B_PIN    6                     // Button B on GPIO6

// === System State Variables ===
volatile int  counter        = -1;            // Countdown value
volatile int  button_b_count = 0;             // Press count for button B
volatile bool counting       = false;         // Indicates countdown is active
volatile bool frozen         = false;         // Indicates countdown ended and frozen
volatile bool display_needs_update = true;    // Triggers display refresh

volatile uint32_t last_press_a = 0;           // Debounce control for button A
volatile uint32_t last_press_b = 0;           // Debounce control for button B
const uint32_t debounce_ms = 200;             // Debounce threshold in milliseconds

ssd1306_t disp;                               // OLED display structure

// Swap values of two integers
inline static void swap(int32_t *a, int32_t *b) {
    int32_t t = *a;
    *a = *b;
    *b = t;
}

// Bitmap for hourglass icon (16x16)
const uint8_t hourglass_bitmap[] = {
    0b11111111, 0b11111111,
    0b10000000, 0b00000001,
    0b01000000, 0b00000010,
    0b00100000, 0b00000100,
    0b00010000, 0b00001000,
    0b00001000, 0b00010000,
    0b00000100, 0b00100000,
    0b00000010, 0b01000000,
    0b00000010, 0b01000000,
    0b00000100, 0b00100000,
    0b00001000, 0b00010000,
    0b00010000, 0b00001000,
    0b00100000, 0b00000100,
    0b01000000, 0b00000010,
    0b10000000, 0b00000001,
    0b11111111, 0b11111111
};

// Bitmap for smile icon (16x16)
const uint8_t smile_bitmap[] = {
    0b00111100, 0b00000000,
    0b01000010, 0b00000000,
    0b10100101, 0b00000000,
    0b10000001, 0b00000000,
    0b10100101, 0b00000000,
    0b10011001, 0b00000000,
    0b01000010, 0b00000000,
    0b00111100, 0b00000000,
    0b00000000, 0b00000000,
    0b00000000, 0b00000000,
    0b00000000, 0b00000000,
    0b00000000, 0b00000000,
    0b00000000, 0b00000000,
    0b00000000, 0b00000000,
    0b00000000, 0b00000000,
    0b00000000, 0b00000000
};

// Draw a scaled bitmap at a specific position
void draw_bitmap(ssd1306_t *disp, int x, int y, const uint8_t *bitmap, int w, int h) {
    int scale = 2;
    for (int j = 0; j < h; j++) {
        for (int i = 0; i < w; i++) {
            int byteIndex = (j * w + i) / 8;
            int bitIndex = 7 - (i % 8);
            if (bitmap[byteIndex] & (1 << bitIndex)) {
                for (int dx = 0; dx < scale; dx++) {
                    for (int dy = 0; dy < scale; dy++) {
                        ssd1306_draw_pixel(disp, x + i * scale + dx, y + j * scale + dy);
                    }
                }
            }
        }
    }
}

// Forward declarations for GPIO interrupt handlers
void button_a_callback(uint gpio, uint32_t events);
void button_b_callback(uint gpio, uint32_t events);

// GPIO interrupt handler dispatcher
void gpio_callback_handler(uint gpio, uint32_t events) {
    if (gpio == BUTTON_A_PIN) {
        button_a_callback(gpio, events);
    } else if (gpio == BUTTON_B_PIN) {
        button_b_callback(gpio, events);
    }
}

// Start countdown when Button A is pressed
void button_a_callback(uint gpio, uint32_t events) {
    uint32_t now = to_ms_since_boot(get_absolute_time());
    if (now - last_press_a < debounce_ms) return;
    last_press_a = now;
    counter = 9;
    button_b_count = 0;
    frozen = false;
    counting = true;
    display_needs_update = true;
}

// Count presses on Button B during countdown
void button_b_callback(uint gpio, uint32_t events) {
    uint32_t now = to_ms_since_boot(get_absolute_time());
    if (now - last_press_b < debounce_ms) return;
    last_press_b = now;
    if (counting && !frozen) {
        button_b_count++;
        display_needs_update = true;
    }
}

// Decrement the counter every 1 second
bool timer_callback(struct repeating_timer *t) {
    if (counting) {
        if (counter > 0) {
            counter--;
            display_needs_update = true;
        } else {
            counting = false;
            frozen = true;
            display_needs_update = true;
        }
    }
    return true;
}

// Initialize I2C and OLED display
void setup_display() {
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA_PIN);
    gpio_pull_up(I2C_SCL_PIN);
    disp.external_vcc = false; // Use internal voltage generator
    if (!ssd1306_init(&disp, 128, 64, OLED_ADDR, I2C_PORT)) {
        printf("Failed to initialize SSD1306\n");
        return;
    }
    ssd1306_clear(&disp);
}

// Refresh the display with current system state
void update_display() {
    ssd1306_clear(&disp);

    if (!counting && !frozen && counter <= 0) {
        ssd1306_draw_string(&disp, 0, 16, 1, "PRESS A TO START!");
        printf("DISPLAY: PRESS A TO START!\n");
        int scale = 2;
        int icon_width = 16 * scale;
        int x = (128 - icon_width) / 2;
        int y = 32;
        draw_bitmap(&disp, x, y, smile_bitmap, 16, 16);
        ssd1306_show(&disp);
        return;
    }

    int display_counter = counter < 0 ? 0 : counter;
    char buf[32];
    snprintf(buf, sizeof(buf), "COUNTER: %d", display_counter);
    printf("%s\n", buf); // For serial monitoring
    ssd1306_draw_string(&disp, 0, 16, 1, buf);

    snprintf(buf, sizeof(buf), "BUTTON B: %d", button_b_count);
    printf("%s\n", buf);
    ssd1306_draw_string(&disp, 0, 32, 1, buf);

    if (frozen && counter == 0) {
        ssd1306_draw_string(&disp, 0, 48, 1, "DONE!"); 
        printf("DONE!\n"); // For serial monitoring
        int scale = 1;
        for (int j = 0; j < 16; j++) {
            for (int i = 0; i < 16; i++) {
                int byteIndex = (j * 16 + i) / 8;
                int bitIndex = 7 - (i % 8);
                if (hourglass_bitmap[byteIndex] & (1 << bitIndex)) {
                    ssd1306_draw_pixel(&disp, 36 + i * scale, 48 + j * scale);
                }
            }
        }
    }

    ssd1306_show(&disp);
}

// Main program loop
int main() {
    stdio_init_all(); // Start serial output
    sleep_ms(2000);   // Wait for monitor connection
    printf("Starting system...\n");
    setup_display();  // Initialize I2C + OLED

    gpio_init(BUTTON_A_PIN);
    gpio_set_dir(BUTTON_A_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_A_PIN);

    gpio_init(BUTTON_B_PIN);
    gpio_set_dir(BUTTON_B_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_B_PIN);

    gpio_set_irq_enabled_with_callback(BUTTON_A_PIN, GPIO_IRQ_EDGE_FALL, true, gpio_callback_handler);
    gpio_set_irq_enabled(BUTTON_B_PIN, GPIO_IRQ_EDGE_FALL, true);

    struct repeating_timer timer;
    add_repeating_timer_ms(1000, timer_callback, NULL, &timer);

    while (true) {
        if (display_needs_update) {
            update_display();
            display_needs_update = false;
        }
        sleep_ms(20);
    }
    return 0;
}
