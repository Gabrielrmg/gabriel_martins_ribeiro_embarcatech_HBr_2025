# 💡 **Matriz de LEDs RGB 5x5**  

<p align="center">
  <img src="../../assets/img/modules/matriz_led.png" alt="Matriz de LEDs RGB 5x5" width="250">
</p>  

A **Matriz de LEDs RGB 5x5** é um módulo visual utilizado no **BR SmartGuia** para fornecer **sinalização luminosa**, aumentando a segurança e a acessibilidade do usuário. Com esse componente, é possível exibir padrões visuais, como a **bandeira do Brasil**, para alertar terceiros sobre a presença do carrinho.  

---

## 📌 **1. O que é esse módulo?**  

A **Matriz de LEDs RGB 5x5** é um display formado por **25 LEDs RGB**, organizados em uma grade de **5 colunas por 5 linhas**. Cada LED pode exibir **diferentes cores**, permitindo criar **padrões visuais dinâmicos**.  

✅ **Baixo consumo de energia** 🔋  
✅ **Pode exibir múltiplas cores** 🎨  
✅ **Alto brilho e excelente visibilidade** 🌟  

Essa matriz é muito utilizada em **sinalização eletrônica e projetos embarcados**, pois permite exibir **informações de forma rápida e intuitiva**.  

---

## ⚙️ **2. Como ela funciona?**  

A matriz funciona através de **endereçamento de linhas e colunas**, onde os LEDs são acionados individualmente através de sinais elétricos.  

📢 **Fluxo de funcionamento da Matriz de LEDs:**  
1️⃣ O **Raspberry Pi Pico W** envia comandos para ativar certos LEDs.  
2️⃣ Os LEDs acendem, formando padrões visuais definidos no código.  
3️⃣ O usuário pode ativar/desativar a matriz utilizando o **botão físico**.  

💡 **Principais características:**  
✔ **25 LEDs RGB de alta intensidade**  
✔ **Controlável via sinais digitais**  
✔ **Permite criar animações e padrões dinâmicos**  

---

## 🎯 **3. Qual o papel dela no BR SmartGuia?**  

A **Matriz de LEDs RGB 5x5** tem um papel fundamental na **sinalização do BR SmartGuia**, ajudando a **alertar terceiros** sobre a presença do usuário.  

💡 **Funções da matriz no sistema:**  
✅ Exibe padrões visuais para melhorar a **visibilidade do carrinho** 🚦  
✅ Mostra a **bandeira do Brasil** para facilitar identificação 🇧🇷  
✅ Ajuda na **navegação segura em locais escuros ou movimentados** 🔦  

📌 **Exemplo de uso:**  
🔹 Quando o ambiente estiver **escuro ou movimentado**, o usuário pode **ativar a matriz** para que outras pessoas percebam sua presença.  
🔹 Caso o carrinho esteja **ligado em modo de alerta**, os LEDs podem **piscar para chamar a atenção**.  

---

## 🔄 **4. Como ela interage com os outros módulos?**  

A **Matriz de LEDs RGB 5x5** trabalha em conjunto com os outros módulos para fornecer uma **experiência acessível e segura**.  

| 🔗 **Módulo** | 🛠 **Interação com a Matriz de LEDs** |
|--------------|-------------------------------|
| **Botões (A e B)** | Ativam ou desativam os **LEDs de sinalização**. 🎛 |
| **Buzzer (MLT8530)** | Pode piscar em sincronia com os **alertas sonoros**. 🔊💡 |
| **Display OLED (SSD1306)** | Informa o **status da matriz** ao usuário. 📟 |
| **Raspberry Pi Pico W** | Controla os padrões visuais exibidos. 🖥 |

📌 **Fluxo de funcionamento da matriz:**  
1️⃣ O usuário **pressiona um botão `A`** para ativar ou **`B`** para desativar a matriz.  
2️⃣ O **Raspberry Pi Pico W** processa o comando e aciona os LEDs.  
3️⃣ O **display OLED exibe o status** da matriz (ativada/desativada).  

---

### 🚀 **Resumo da Matriz de LEDs RGB 5x5 no BR SmartGuia**  
✅ **Aumenta a visibilidade e segurança do usuário** 💡  
✅ **Permite exibir padrões visuais personalizáveis** 🎨  
✅ **Trabalha em conjunto com buzzer e botões** 🔊🎛  
✅ **Baixo consumo de energia e fácil integração** ⚡  

Com essa matriz, o **BR SmartGuia se torna mais seguro e visível**, garantindo que o usuário seja **facilmente notado em ambientes movimentados ou de baixa iluminação**! 🚀💡  