# 🖥️ **Raspberry Pi Pico W**  

<p align="center">
  <img src="../../assets/img/modules/pico_w.png" alt="Raspberry Pi Pico W" width="250">
</p>  

O **Raspberry Pi Pico W** é o **cérebro do BR SmartGuia**, sendo responsável por processar os dados dos sensores, ativar os módulos de resposta e garantir a comunicação entre os componentes. Graças à sua conectividade Wi-Fi, ele também permite futuras expansões do sistema.  

---

## 📌 **1. O que é esse módulo?**  

O **Raspberry Pi Pico W** é um **microcontrolador da Raspberry Pi Foundation**, baseado no processador **RP2040**, e voltado para aplicações embarcadas que exigem **baixo consumo de energia e conectividade Wi-Fi**.  

✅ **Baixo consumo de energia** 🔋  
✅ **Wi-Fi integrado para comunicação remota** 📶  
✅ **Processamento rápido e eficiente** ⚡  

Esse microcontrolador é ideal para **dispositivos portáteis**, como o **BR SmartGuia**, pois permite **controlar sensores e atuadores de forma precisa e eficiente**.  

---

## ⚙️ **2. Como ele funciona?**  

O **Raspberry Pi Pico W** recebe sinais dos sensores, processa os dados e aciona os módulos necessários. Ele pode tomar decisões em tempo real para **garantir a segurança e a eficiência do sistema**.  

📢 **Fluxo de funcionamento do Raspberry Pi Pico W:**  
1️⃣ Recebe os dados do **Sensor Ultrassônico HC-SR04** 📏  
2️⃣ Processa a distância e decide a resposta do sistema 🔄  
3️⃣ Ativa o **Buzzer e os LEDs** se necessário 🔊💡  
4️⃣ Exibe informações no **Display OLED SSD1306** 📟  

💡 **Principais características:**  
✔ **Processador RP2040 (dual-core ARM Cortex-M0+)**  
✔ **Conectividade Wi-Fi integrada (802.11 b/g/n)**  
✔ **Baixo consumo de energia e alta eficiência**  

---

## 🎯 **3. Qual o papel dele no BR SmartGuia?**  

O **Raspberry Pi Pico W** é a **unidade central de controle** do BR SmartGuia. Ele gerencia **todos os módulos e sensores**, garantindo um funcionamento integrado.  

🖥️ **Funções do Raspberry Pi Pico W no sistema:**  
✅ **Lê os sensores e processa as informações** 🤖  
✅ **Ativa os alertas sonoros e visuais quando necessário** 🔊💡  
✅ **Exibe feedback no Display OLED** 📟  
✅ **Garante a comunicação entre os módulos** 🔄  

📌 **Exemplo de uso:**  
🔹 Se um **obstáculo for detectado**, o **Raspberry Pi Pico W** decide qual alerta ativar (som, luz ou ambos).  
🔹 Permite futuras expansões, como **conectividade remota** para alertas em tempo real.  

---

## 🔄 **4. Como ele interage com os outros módulos?**  

O **Raspberry Pi Pico W** é **o centro de controle do sistema**, recebendo informações e comandando os módulos para garantir a acessibilidade do usuário.  

| 🔗 **Módulo** | 🛠 **Interação com o Raspberry Pi Pico W** |
|--------------|-------------------------------|
| **Sensor Ultrassônico (HC-SR04)** | Envia a **distância do obstáculo** para processamento. 📏 |
| **Buzzer (MLT8530)** | Ativado para **alertar o usuário de perigos**. 🔊 |
| **Display OLED (SSD1306)** | Exibe informações em **tempo real**. 📟 |
| **Matriz de LEDs RGB 5x5** | Ajuda na **sinalização visual** para terceiros. 💡 |
| **Botões (A e B)** | Permitem ao usuário **controlar funções do sistema**. 🎛 |

📌 **Fluxo de funcionamento do Raspberry Pi Pico W:**  
1️⃣ Recebe informações dos sensores.  
2️⃣ Analisa os dados e decide a resposta.  
3️⃣ Aciona **buzzer, LEDs ou display OLED**, conforme necessário.  
4️⃣ Permite ao usuário **interagir com os botões para personalizar a experiência**.  

---

### 🚀 **Resumo do Raspberry Pi Pico W no BR SmartGuia**  
✅ **Processa e controla todos os módulos do sistema** 🖥️  
✅ **Permite conectividade e expansão futura via Wi-Fi** 📶  
✅ **Eficiente, rápido e com baixo consumo de energia** ⚡  
✅ **Garante um funcionamento integrado e responsivo** 🔄  

Com o **Raspberry Pi Pico W**, o **BR SmartGuia** se torna um sistema **inteligente e acessível**, garantindo mais segurança e autonomia para o usuário! 🚀🖥️  