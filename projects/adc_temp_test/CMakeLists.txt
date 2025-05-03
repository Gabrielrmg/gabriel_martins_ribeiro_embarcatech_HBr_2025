cmake_minimum_required(VERSION 3.13)
project(adc_temp_test C)

# Se PICO_SDK_PATH não estiver definido, baixa o Pico SDK via Git
set(PICO_SDK_FETCH_FROM_GIT ON CACHE BOOL "Fetch Pico SDK from git if not found")

# Alvo de TESTES (host/desktop)
add_subdirectory(unity)
include_directories(include unity/src)

add_library(adc_temp STATIC
    src/adc_temp.c
)

add_executable(run_tests
    test/test_adc_temp.c
    unity/src/unity.c
)
target_link_libraries(run_tests adc_temp)

enable_testing()
add_test(NAME adc_test COMMAND run_tests)

# Firmware para RP2040 (Pico)

include(pico_sdk_import.cmake)
pico_sdk_init()

add_executable(adc_temp_firmware
    src/main.c
    src/adc_temp.c
)

target_include_directories(adc_temp_firmware PRIVATE include)
target_link_libraries(adc_temp_firmware pico_stdlib hardware_adc)
pico_enable_stdio_usb(adc_temp_firmware 1)
pico_enable_stdio_uart(adc_temp_firmware 0)
pico_add_extra_outputs(adc_temp_firmware)
