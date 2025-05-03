cmake_minimum_required(VERSION 3.15)
project(adc_to_celsius_project C)

# Ativa o CTest para testes unitários
enable_testing()

# 1) Cria o executável de teste a partir do seu main.c
add_executable(adc_test_runner
    main.c
)

# 2) Registra o teste no CTest
add_test(NAME adc_to_celsius_test
         COMMAND adc_test_runner)

# 3) (Opcional) Faz o CTest considerar “pass” apenas se imprimir “Teste passou”
set_tests_properties(adc_to_celsius_test PROPERTIES
    PASS_REGULAR_EXPRESSION "Teste passou"
)
