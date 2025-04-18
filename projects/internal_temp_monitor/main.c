/**
 * Description: Internal Temperature Monitor using RP2040 and OLED Display (SSD1306)
 * Author: Gabriel Martins Ribeiro  
 */

 #include "pico/stdlib.h"           // Standard RP2040 functions (GPIO, sleep, etc.)
 #include "hardware/adc.h"          // Access to analog-to-digital converter (ADC)
 #include "hardware/i2c.h"          // Access to I2C hardware interface
 #include <stdio.h>                 // Standard I/O for printf
 #include "ssd1306.h"               // SSD1306 OLED display driver
 #include "font.h"                  // Font data used for text rendering
 
 // Definitions for I2C interface and OLED display address
 #define I2C_PORT        i2c1       // Using I2C1 port on RP2040
 #define I2C_SDA_PIN     14         // Pin 14 for I2C data line (SDA)
 #define I2C_SCL_PIN     15         // Pin 15 for I2C clock line (SCL)
 #define OLED_ADDR       0x3C       // I2C address for the SSD1306 display
 
 ssd1306_t disp;                    // Display structure for SSD1306
 
 // Initializes and configures the I2C display.
 void setup_display() {
     i2c_init(I2C_PORT, 400 * 1000);                        // Initialize I2C with 400kHz frequency
     gpio_set_function(I2C_SDA_PIN, GPIO_FUNC_I2C);         // Set SDA pin to I2C function
     gpio_set_function(I2C_SCL_PIN, GPIO_FUNC_I2C);         // Set SCL pin to I2C function
     gpio_pull_up(I2C_SDA_PIN);                             // Enable internal pull-up for SDA
     gpio_pull_up(I2C_SCL_PIN);                             // Enable internal pull-up for SCL
 
     disp.external_vcc = false;                             // Use internal VCC configuration
     if (!ssd1306_init(&disp, 128, 64, OLED_ADDR, I2C_PORT)) { // Initialize display with resolution and address
         printf("Failed to initialize SSD1306\n");          // Display initialization failed
         return;
     }
     ssd1306_clear(&disp);                                  // Clear display buffer
 }
 
 // Reads and converts internal temperature from the RP2040 sensor.
 // return Temperature in Celsius.
 float read_internal_temperature() {
     const float conversion_factor = 3.3f / (1 << 12);      // ADC conversion factor for 12-bit resolution
     uint16_t raw = adc_read();                             // Read raw ADC value
     float voltage = raw * conversion_factor;               // Convert ADC value to voltage
     float temperature = 27.0f - (voltage - 0.706f) / 0.001721f; // Convert voltage to temperature (datasheet formula)
     return temperature;
 }
 
// Main loop: reads temperature and displays on OLED and serial.
 int main() {
     stdio_init_all();                                      // Initialize serial communication
     sleep_ms(2000);                                        // Delay for stabilization
     printf("Starting...\n");                               // Print startup message
 
     setup_display();                                       // Initialize and configure OLED display
 
     adc_init();                                            // Initialize ADC hardware
     adc_set_temp_sensor_enabled(true);                     // Enable internal temperature sensor
     adc_select_input(4);                                   // Select temperature sensor channel
 
     char buffer[32];                                       // Buffer for formatted temperature string
 
     while (true) {
         float temp_c = read_internal_temperature();        // Read temperature in Celsius
         snprintf(buffer, sizeof(buffer), "TEMPERATURE : %.2f C", temp_c); // Format output
 
         ssd1306_clear(&disp);                              // Clear previous display content
         ssd1306_draw_string(&disp, 0, 0, 1, buffer);       // Draw temperature string at top-left corner
         ssd1306_show(&disp);                               // Send buffer to display
 
         printf("%s\n", buffer);                            // Print temperature to serial
         sleep_ms(1000);                                    // Wait 1 second before next reading
     }
 
     return 0;                                              // End of program (unreachable in this case)
 }
 