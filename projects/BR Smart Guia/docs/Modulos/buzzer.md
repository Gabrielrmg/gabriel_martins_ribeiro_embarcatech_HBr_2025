# 🔊 **Buzzer (MLT8530)**  

<p align="center">
  <img src="../../assets/img/modules/buzzer.png" alt="Buzzer MLT8530" width="250">
</p>  

O **Buzzer MLT8530** é um componente essencial do **BR SmartGuia**, responsável por **emitir sinais sonoros** para alertar o usuário sobre a presença de obstáculos. Ele trabalha em conjunto com o **Sensor Ultrassônico HC-SR04**, garantindo que o usuário receba um **feedback auditivo imediato** para uma navegação segura.  

---

## 📌 **1. O que é esse módulo?**  

O **MLT8530** é um **buzzer piezoelétrico** que converte sinais elétricos em **som audível**. Ele é amplamente utilizado em sistemas embarcados devido a suas vantagens:  

✅ **Consome pouca energia** 🔋  
✅ **Fácil de integrar com microcontroladores** 🖥  
✅ **Pode gerar sons de diferentes frequências** 🔊  

Esse componente é **fundamental para acessibilidade**, pois fornece **alertas sonoros instantâneos**, especialmente úteis para usuários com deficiência visual.  

---

## ⚙️ **2. Como ele funciona?**  

O **buzzer piezoelétrico** funciona a partir de **pulsos elétricos** que fazem com que um **disco cerâmico vibre**, gerando som.  

📢 **Fluxo de funcionamento do Buzzer MLT8530:**  
1️⃣ O **Raspberry Pi Pico W** envia um sinal de frequência variável.  
2️⃣ O **buzzer vibra**, transformando o sinal elétrico em som.  
3️⃣ O **som emitido** varia de acordo com o alerta necessário.  

💡 **Principais características:**  
✔ **Tensão de operação: 3V a 5V**  
✔ **Frequência de operação: ~4kHz**  
✔ **Modo ativo, não precisa de circuito externo**  

---

## 🎯 **3. Qual o papel dele no BR SmartGuia?**  

O **Buzzer MLT8530** é um dos principais **meios de comunicação do sistema**. Ele permite que o usuário receba **alertas sonoros sobre obstáculos** e outros avisos importantes.  

🔊 **Funções do buzzer no BR SmartGuia:**  
✅ **Emite alerta quando há um obstáculo próximo** (≤ 15 cm).  
✅ **Diferentes padrões sonoros** para indicar diferentes situações.  
✅ **Auxilia usuários com deficiência visual na navegação.**  

📢 O som do buzzer **aumenta conforme a proximidade do obstáculo**, tornando a experiência intuitiva para o usuário.  

---

## 🔄 **4. Como ele interage com os outros módulos?**  

O **Buzzer MLT8530** trabalha em conjunto com outros módulos para fornecer uma experiência integrada e acessível.  

| 🔗 **Módulo** | 🛠 **Interação com o Buzzer** |
|--------------|-------------------------------|
| **Sensor Ultrassônico (HC-SR04)** | Ativa o buzzer quando um **obstáculo é detectado**. 📏 |
| **Display OLED (SSD1306)** | Exibe informações enquanto o **buzzer alerta o usuário**. 📟 |
| **Matriz de LEDs RGB 5x5** | Trabalha em conjunto para **sinalização visual**. 💡 |
| **Botões (A e B)** | Permitem ao usuário **ativar/desativar alertas sonoros**. 🎛 |
| **Raspberry Pi Pico W** | Controla a ativação do buzzer conforme os sensores. 🖥 |

📌 **Fluxo de funcionamento do buzzer:**  
1️⃣ O **HC-SR04** detecta um obstáculo próximo.  
2️⃣ O **Raspberry Pi Pico W** processa os dados e aciona o buzzer.  
3️⃣ O **Buzzer emite um alerta sonoro** baseado na proximidade do obstáculo.  
4️⃣ O **Display OLED exibe informações sobre a distância do objeto**.  
5️⃣ Se necessário, os **LEDs piscam** para reforçar o alerta visualmente.  

---

### 🚀 **Resumo do Buzzer MLT8530 no BR SmartGuia**  
✅ **Fornece alertas sonoros para navegação segura** 🔊  
✅ **Baixo consumo de energia e fácil integração** ⚡  
✅ **Trabalha em conjunto com sensores e LEDs** 💡  
✅ **Crucial para acessibilidade de usuários com deficiência visual** 🦯  

Com esse buzzer, o **BR SmartGuia garante que os usuários recebam alertas instantâneos**, promovendo uma navegação segura e eficiente! 🚀🔊  