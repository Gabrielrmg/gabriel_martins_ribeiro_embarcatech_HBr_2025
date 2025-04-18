# 🌡️ Internal MCU Temperature Monitor

**Autor:** Gabriel Martins Ribeiro  
**Engenheiro Eletrônico – FCTE – UnB**

Este projeto realiza a leitura da temperatura interna do microcontrolador RP2040 utilizando o conversor analógico-digital (ADC). A temperatura é exibida em tempo real tanto no terminal serial quanto em um display OLED 128x64 com controlador SSD1306 via I2C.

---

## 🧩 Estrutura do Código

| Arquivo               | Descrição                                                                 |
|-----------------------|---------------------------------------------------------------------------|
| [`main.c`](https://github.com/Gabrielrmg/gabriel_martins_ribeiro_embarcatech_HBr_2025/blob/main/projects/internal_temp_monitor/src/main.c) | Código principal responsável pela leitura da temperatura interna e exibição no OLED |
| [`ssd1306.c`](https://github.com/Gabrielrmg/gabriel_martins_ribeiro_embarcatech_HBr_2025/blob/main/projects/internal_temp_monitor/src/ssd1306.c) | Controle do display OLED SSD1306 via I2C                                |
| [`ssd1306.h`](https://github.com/Gabrielrmg/gabriel_martins_ribeiro_embarcatech_HBr_2025/blob/main/projects/internal_temp_monitor/src/ssd1306.h) | Cabeçalho da interface do display                                        |
| [`font.c`](https://github.com/Gabrielrmg/gabriel_martins_ribeiro_embarcatech_HBr_2025/blob/main/projects/internal_temp_monitor/src/font.c) | Fonte usada na renderização de caracteres                               |
| [`font.h`](https://github.com/Gabrielrmg/gabriel_martins_ribeiro_embarcatech_HBr_2025/blob/main/projects/internal_temp_monitor/src/font.h) | Cabeçalho com definição da fonte                                         |
| [`pico_sdk_import.cmake`](https://github.com/Gabrielrmg/gabriel_martins_ribeiro_embarcatech_HBr_2025/blob/main/projects/internal_temp_monitor/src/pico_sdk_import.cmake) | Importação do Raspberry Pi Pico SDK                                     |
| [`CMakeLists.txt`](https://github.com/Gabrielrmg/gabriel_martins_ribeiro_embarcatech_HBr_2025/blob/main/projects/internal_temp_monitor/src/CMakeLists.txt) | Configuração via CMake                                                  |


---

## ⚙️ Funcionalidades Implementadas

✅ Leitura da temperatura interna via ADC  
✅ Cálculo da temperatura em ºC com base na tensão lida  
✅ Exibição contínua no display OLED (I2C 400kHz)  
✅ Compatível com Raspberry Pi Pico e Pico W

---

## 💻 Requisitos

- Raspberry Pi Pico ou Pico W  
- Display OLED 128x64 com SSD1306 (I2C)  
- SDK oficial da Raspberry Pi Pico  
- Ambiente com suporte a CMake

