cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(adc_to_celsius C CXX ASM)

# Indica qual placa você está usando (ajuste se não for o Pico “padrão”)
set(PICO_BOARD pico)

# Inicializa o SDK do Pico
pico_sdk_init()

# Aqui: cria um executável chamado "adc_to_celsius" a partir do main.c
add_executable(adc_to_celsius
    main.c
)

# Linka as bibliotecas necessárias
target_link_libraries(adc_to_celsius
    pico_stdlib
    hardware_adc
)

# Habilita USB serial (console via USB) e desabilita UART
pico_enable_stdio_usb(adc_to_celsius 1)
pico_enable_stdio_uart(adc_to_celsius 0)

# Gera também o .uf2 para gravação no Pico
pico_add_extra_outputs(adc_to_celsius)
