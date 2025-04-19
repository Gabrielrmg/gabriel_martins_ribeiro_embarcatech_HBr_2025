# 🚀 BR SmartGuia - Firmware

<p align="center">
  <img src="assets/img/Gabriel.jpg" alt="Gabriel Martins Ribeiro" width="150">
</p>

**Autor:** Gabriel Martins Ribeiro  
 **Engenheiro Eletrônico - FCTE - UnB**  



Bem-vindo ao projeto **BR SmartGuia**! Este projeto foi desenvolvido para fornecer assistência a pessoas com deficiência visual, utilizando tecnologia embarcada e sensores.

---

## 📜 Estrutura do Código

A organização dos arquivos de código (pasta `src`) no projeto segue uma estrutura modular para facilitar a manutenção e escalabilidade. Abaixo, uma visão geral dos principais arquivos:

| Arquivo                    | Descrição |
|----------------------------|------------------------------------------------|
| [`BatGuia.c`](https://github.com/Gabrielrmg/EMBARCATECH/blob/main/codigos/BatGuia.c) | Código principal do firmware, responsável pelo controle dos periféricos e lógica do dispositivo. |
| [`ssd1306.h`](https://github.com/Gabrielrmg/EMBARCATECH/blob/main/codigos/ssd1306.h) | Header file para controle do display OLED SSD1306 via I2C. |
| [`ssd1306_i2c.c`](https://github.com/Gabrielrmg/EMBARCATECH/blob/main/codigos/ssd1306_i2c.c) | Implementação das funções para comunicação com o display OLED. |
| [`ssd1306_font.h`](https://github.com/Gabrielrmg/EMBARCATECH/blob/main/codigos/ssd1306_font.h) | Definições de fonte para exibição de caracteres no display. |
| [`ws2818b.pio.h`](https://github.com/Gabrielrmg/EMBARCATECH/blob/main/codigos/ws2818b.pio.h) | Código para controle da matriz de LEDs WS2818B via PIO. |
| [`pico_sdk_import.cmake`](https://github.com/Gabrielrmg/EMBARCATECH/blob/main/codigos/pico_sdk_import.cmake) | Importação do Raspberry Pi Pico SDK para o projeto. |
| [`CMakeLists.txt`](https://github.com/Gabrielrmg/EMBARCATECH/blob/main/codigos/CMakeLists.txt) | Configuração do CMake para compilação do projeto e dependências. |

---

## 📌 Sobre o Firmware

O **BR SmartGuia** utiliza sensores para fornecer feedback sonoro, para o usuário cego, e visual, para eventuais terceiros. O firmware é desenvolvido em **C**, utilizando o **Raspberry Pi Pico SDK**.

### ⚙️ Funcionalidades Implementadas:

✔️ **Sensor Ultrassônico** para detecção de obstáculos  
✔️ **Matriz de LEDs WS2818B** para sinalização visual  
✔️ **Display OLED SSD1306** para exibição de informações  
✔️ **Buzzer** para alertas sonoros  
✔️ **Botões físicos** para interação  

---

📌 Para mais detalhes, consulte o [site](https://gabrielrmg.github.io/EMBARCATECH/). 🚀
