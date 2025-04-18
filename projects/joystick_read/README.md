# 🎮 Joystick Read

**Autor:** Gabriel Martins Ribeiro  
**Engenheiro Eletrônico – FCTE – UnB**

Este projeto realiza a leitura dos eixos X e Y de um joystick analógico, além de detectar o acionamento do botão central. As informações são exibidas em tempo real tanto no terminal serial quanto em um display OLED 128x64 com controlador SSD1306 via protocolo I2C.

---

## 🧩 Estrutura do Código

A seguir, uma visão geral dos principais arquivos do projeto:

| Arquivo              | Descrição                                                                 |
|----------------------|---------------------------------------------------------------------------|
| `main.c`             | Código principal responsável pela leitura dos sinais do joystick e exibição OLED |
| `ssd1306.c`          | Implementação das funções de controle do display OLED SSD1306             |
| `ssd1306.h`          | Header com definições da interface do display                             |
| `font.c`             | Definições da fonte de caracteres utilizada na exibição                   |
| `font.h`             | Cabeçalho correspondente à fonte utilizada                                |
| `pico_sdk_import.cmake` | Importação do Raspberry Pi Pico SDK                                     |
| `CMakeLists.txt`     | Arquivo de configuração para compilação via CMake                         |

---

## ⚙️ Funcionalidades Implementadas

✅ Leitura analógica dos eixos X e Y do joystick  
✅ Detecção digital do botão (pressão)  
✅ Exibição contínua das leituras no display OLED  
✅ Comunicação via I2C com taxa de 400kHz  
✅ Compatível com Raspberry Pi Pico e Pico W  

---

## 💻 Requisitos

- Raspberry Pi Pico ou Pico  W  
- Joystick analógico com botão  
- Display OLED 128x64 com SSD1306 (I2C)  
- SDK oficial da Raspberry Pi Pico  
- Ambiente com suporte a CMake


