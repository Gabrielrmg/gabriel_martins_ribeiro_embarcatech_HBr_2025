# ⏱️ Countdown Display

**Autor:** Gabriel Martins Ribeiro  
**Engenheiro Eletrônico – FCTE – UnB**

Este projeto realiza uma contagem regressiva, de 9 até 0 segundos, com exibição em display OLED SSD1306 e monitor serial.  
O acionamento é feito pelo botão A. Além disso, é registrado o número de vezes que o botão B foi pressionado dentro desse intervalo de 9 segundos.

---

## 🧩 Estrutura do Código

A seguir, uma visão geral dos principais arquivos do projeto:

| Arquivo              | Descrição                                                                 |
|----------------------|---------------------------------------------------------------------------|
| `main.c`             | Código principal responsável pela lógica de contagem regressiva e interação com botões |
| `ssd1306.c`          | Implementação das funções de controle do display OLED SSD1306             |
| `ssd1306.h`          | Header com definições da interface do display                             |
| `font.c`             | Definições da fonte de caracteres utilizada na exibição                   |
| `font.h`             | Cabeçalho correspondente à fonte utilizada                                |
| `pico_sdk_import.cmake` | Importação do Raspberry Pi Pico SDK                                     |
| `CMakeLists.txt`     | Arquivo de configuração para compilação via CMake                         |

---

## ⚙️ Funcionalidades Implementadas

✅ Contagem regressiva visível no display  
✅ Início da contagem por botão físico  
✅ Comunicação via I2C com o display OLED  
✅ Compatível com Raspberry Pi Pico e Pico W  

---

## 💻 Requisitos

- Raspberry Pi Pico ou Pico W  
- Display OLED 128x64 com SSD1306 (I2C)  
- Botão físico conectado a GPIO  
- SDK oficial da Raspberry Pi Pico  
- Ambiente com suporte a CMake

