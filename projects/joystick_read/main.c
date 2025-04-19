/**
 * Author: Gabriel Martins Ribeiro
 * Date: April 2025
 * Description: This program reads analog and digital signals from a joystick module connected to the Raspberry Pi Pico W.
 *        It displays the X and Y axis values, along with the button state, both on a serial terminal and on an OLED display.
 *
 * Hardware Components:
 * - Raspberry Pi Pico W
 * - Joystick module (X and Y axes connected to ADC0 and ADC1, button to GPIO22)
 * - OLED display with SSD1306 controller (connected via I2C1 on GPIO14/15)
 *
 * Functionality:
 * - Reads analog values from the joystick x and y axes using the onboard ADC.
 * - Reads the digital state of the joystick button (pressed or not).
 * - Displays real-time readings on both a serial interface and a 128x64 OLED display.
 
 */

 #include "pico/stdlib.h"        // Standard Raspberry Pi Pico W definitions and utility functions
 #include "hardware/adc.h"       // Provides ADC (Analog to Digital Converter) functionality
 #include "hardware/i2c.h"       // Provides I2C communication functions
 #include <stdio.h>              // Provides input/output functions such as printf
 #include "ssd1306.h"            // OLED display driver based on the SSD1306 controller
 #include "font.h"               // Font definitions for the OLED display
 
 // Define the GPIO pins connected to the joystick analog axes
 #define JOYSTICK_X_PIN 26       // GPIO26 is connected to the X-axis of the joystick (ADC0)
 #define JOYSTICK_Y_PIN 27       // GPIO27 is connected to the Y-axis of the joystick (ADC1)
 
 // Define the GPIO pin connected to the joystick button
 #define JOYSTICK_BTN_PIN 22     // GPIO22 is connected to the digital button of the joystick
 
 // Define the I2C configuration for the OLED display
 #define I2C_PORT        i2c1    // Use the second I2C peripheral (i2c1)
 #define I2C_SDA_PIN     14      // GPIO14 is used for the I2C data line (SDA)
 #define I2C_SCL_PIN     15      // GPIO15 is used for the I2C clock line (SCL)
 #define OLED_ADDR       0x3C    // I2C address of the SSD1306 OLED display
 
 ssd1306_t disp;                 // Structure representing the OLED display instance
 
 // Function to initialize and configure the OLED display
 void setup_display() {
     i2c_init(I2C_PORT, 400 * 1000);                      // Initialize I2C1 with a frequency of 400 kHz
     gpio_set_function(I2C_SDA_PIN, GPIO_FUNC_I2C);       // Set SDA pin to I2C mode
     gpio_set_function(I2C_SCL_PIN, GPIO_FUNC_I2C);       // Set SCL pin to I2C mode
     gpio_pull_up(I2C_SDA_PIN);                           // Enable pull-up resistor on SDA
     gpio_pull_up(I2C_SCL_PIN);                           // Enable pull-up resistor on SCL
 
     disp.external_vcc = false;                           // Specify that the OLED uses internal voltage (VCC)
     if (!ssd1306_init(&disp, 128, 64, OLED_ADDR, I2C_PORT)) { // Initialize the OLED display
         printf("Failed to initialize SSD1306\n");        // Display initialization error
         return;
     }
     ssd1306_clear(&disp);                                // Clear the display contents
 }
 
 // Main function
 int main() {
     stdio_init_all();                                    // Initialize all standard I/O interfaces
     sleep_ms(2000);                                      // Wait for 2 seconds before starting (e.g., for USB serial)
     printf("Starting joystick monitoring...\n");         // Output initial message to the terminal
 
     setup_display();                                     // Call function to initialize the OLED display
 
     adc_init();                                          // Initialize the ADC peripheral
     adc_gpio_init(JOYSTICK_X_PIN);                       // Enable ADC input on GPIO26 (X-axis)
     adc_gpio_init(JOYSTICK_Y_PIN);                       // Enable ADC input on GPIO27 (Y-axis)
 
     gpio_init(JOYSTICK_BTN_PIN);                         // Initialize the GPIO pin for the joystick button
     gpio_set_dir(JOYSTICK_BTN_PIN, GPIO_IN);             // Set the button pin as input
     gpio_pull_up(JOYSTICK_BTN_PIN);                      // Enable internal pull-up resistor
 
     while (true) {
         adc_select_input(0);                             // Select ADC input channel 0 (X-axis)
         uint16_t joystickXValue = adc_read();            // Read analog value from X-axis
 
         adc_select_input(1);                             // Select ADC input channel 1 (Y-axis)
         uint16_t joystickYValue = adc_read();            // Read analog value from Y-axis
 
         bool button_pressed = gpio_get(JOYSTICK_BTN_PIN) == 0; // Read the digital state of the joystick button (active-low)
 
         // Display joystick values on the serial terminal
         printf("Joystick X: %d | Joystick Y: %d", joystickXValue, joystickYValue);
         if (button_pressed) {
             printf(" | BUTTON PRESSED!");                // Append message if button is pressed
         }
         printf("\n");
 
         ssd1306_clear(&disp);                            // Clear the OLED display buffer
 
         char msgX[32];                                   // Buffer to hold formatted X-axis message
         char msgY[32];                                   // Buffer to hold formatted Y-axis message
         snprintf(msgX, sizeof(msgX), "JOYSTICK X: %d", joystickXValue); // Format X value
         snprintf(msgY, sizeof(msgY), "JOYSTICK Y: %d", joystickYValue); // Format Y value
 
         ssd1306_draw_string(&disp, 0, 0, 1, msgX);       // Draw X-axis value on the first line
         ssd1306_draw_string(&disp, 0, 16, 1, msgY);      // Draw Y-axis value on the second line
 
         if (button_pressed) {
             ssd1306_draw_string(&disp, 0, 32, 1, "BUTTON PRESSED!"); // Draw button message if pressed
         }
 
         ssd1306_show(&disp);                             // Refresh the OLED display with updated content
 
         sleep_ms(200);                                   // Wait 200 milliseconds before the next reading
     }
 
     return 0;                                            // Program will never reach here (infinite loop)
 }
 
