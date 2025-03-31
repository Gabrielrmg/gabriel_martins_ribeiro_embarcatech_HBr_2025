# 📟 **Display OLED (SSD1306)**  

<p align="center">
  <img src="../../assets/img/modules/oled.png" alt="Display OLED SSD1306" width="250">
</p>  

O **Display OLED SSD1306** é um **módulo de exibição de informações visuais** utilizado no **BR SmartGuia**. Ele permite que o usuário visualize **dados importantes em tempo real**, como a distância do obstáculo detectado pelo **sensor ultrassônico**.  

---

## 📌 **1. O que é esse módulo?**  

O **SSD1306** é um **display gráfico OLED** (Organic Light-Emitting Diode), amplamente utilizado em projetos embarcados devido a suas vantagens:  

✅ **Baixo consumo de energia** 🔋  
✅ **Alto contraste e nitidez** 🌟  
✅ **Funciona sem backlight** 💡  

Esse display permite **exibir textos e gráficos simples**, sendo uma interface acessível para dispositivos assistivos como o **BR SmartGuia**.  

---

## ⚙️ **2. Como ele funciona?**  

O **Display OLED SSD1306** utiliza um **microcontrolador interno** para processar as imagens e textos recebidos via **comunicação I2C ou SPI**.  

🖥 **Fluxo de funcionamento do SSD1306**:  
1️⃣ O **Raspberry Pi Pico W** envia os dados via **I2C**.  
2️⃣ O **SSD1306** processa os comandos recebidos.  
3️⃣ As **informações são exibidas na tela OLED** com alta nitidez.  

💡 **Principais características:**  
✔ **Resolução de 128x64 pixels**  
✔ **Consome apenas 0,08W**  
✔ **Não precisa de luz de fundo** (os pixels brilham por si próprios)  

---

## 🎯 **3. Qual o papel dele no BR SmartGuia?**  

O **Display OLED SSD1306** é um dos módulos mais importantes do **BR SmartGuia**, pois exibe informações críticas para o usuário.  

📟 **O que o display exibe?**  
✅ A **distância** do obstáculo detectado pelo **Sensor Ultrassônico HC-SR04** 📏  
✅ Mensagens de **status do carrinho** 🚦

Isso torna o **BR SmartGuia mais acessível**, permitindo que o usuário tenha um **feedback visual imediato** sobre os obstáculos ao redor.  

---

## 🔄 **4. Como ele interage com os outros módulos?**  

O **Display OLED SSD1306** trabalha em conjunto com outros módulos para fornecer uma **experiência integrada e acessível**.  

| 🔗 **Módulo** | 🛠 **Interação com o SSD1306** |
|--------------|-------------------------------|
| **Sensor Ultrassônico (HC-SR04)** | Envia a **distância do obstáculo** para exibição. 📏 |
| **Buzzer (MLT8530)** | Exibe alertas visuais quando o **buzzer emite um som**. 🔊 |
| **Matriz de LEDs RGB 5x5** | Trabalha em conjunto para **alertar visualmente o ambiente**. 💡 |
| **Botões (A e B)** | Permitem ao usuário **alternar entre informações exibidas**. 🎛 |
| **Raspberry Pi Pico W** | Controla a comunicação e os dados do display. 🖥 |

📌 **Fluxo de funcionamento do display:**  
1️⃣ O **HC-SR04** detecta um obstáculo.  
2️⃣ O **Raspberry Pi Pico W** processa os dados e envia para o display.  
3️⃣ O **Display OLED exibe a distância do obstáculo** em tempo real.  
4️⃣ O **Buzzer e os LEDs são ativados**, caso necessário.  

---

### 🚀 **Resumo do Display OLED SSD1306 no BR SmartGuia**  
✅ **Exibição clara e de alto contraste** para facilitar a leitura.  
✅ **Baixo consumo de energia** e compatibilidade com **I2C**.  
✅ **Interação com sensores e alertas visuais** para maior acessibilidade.  

Com esse display, o **BR SmartGuia fornece informações instantâneas** para o usuário, garantindo maior segurança na mobilidade! 🚀📟 