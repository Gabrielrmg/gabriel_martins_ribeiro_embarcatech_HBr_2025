# 🌡️ Internal MCU Temperature Monitor

**Autor:** Gabriel Martins Ribeiro  
**Engenheiro Eletrônico – FCTE – UnB**

Este projeto realiza a leitura da temperatura interna do microcontrolador RP2040 utilizando o conversor analógico-digital (ADC). A temperatura é exibida em tempo real tanto no terminal serial quanto em um display OLED 128x64 com controlador SSD1306 via I2C.

---

## 🧩 Estrutura do Código

| Arquivo                | Descrição                                                                 |
|------------------------|---------------------------------------------------------------------------|
| `main.c`               | Código principal responsável por ler a temperatura e exibir no OLED       |
| `ssd1306.c`            | Implementação das funções de controle do display OLED SSD1306             |
| `ssd1306.h`            | Header com definições da interface do display                             |
| `font.c`               | Definições da fonte de caracteres utilizada na exibição                   |
| `font.h`               | Cabeçalho correspondente à fonte utilizada                                |
| `pico_sdk_import.cmake`| Importação do Raspberry Pi Pico SDK                                       |
| `CMakeLists.txt`       | Arquivo de configuração para compilação via CMake                         |

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

