cmake_minimum_required(VERSION 3.13)
project(pico_led_modular C CXX ASM)

# aponte para o SDK
if(NOT DEFINED ENV{PICO_SDK_PATH})
  message(FATAL_ERROR "PICO_SDK_PATH não definido")
endif()
set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})

# inclua o pico_sdk
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# inicializa o pico_sdk
pico_sdk_init()

# adicione seu executável (ajuste os fontes conforme sua estrutura)
add_executable(pico_led_modular
    app/main.c
    hal/hal_led.c
    drivers/led_embutido.c
)

# link com as libs do pico
target_link_libraries(pico_led_modular pico_stdlib)

# gera .uf2, etc
pico_add_extra_outputs(pico_led_modular)
