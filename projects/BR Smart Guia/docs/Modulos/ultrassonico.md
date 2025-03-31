# 🔍 **Sensor Ultrassônico (HC-SR04)**

<p align="center">
  <img src="../../assets/img/modules/ultrassonico.png" alt="Sensor Ultrassônico HC-SR04" width="250">
</p>

O **Sensor Ultrassônico HC-SR04** é um dos principais componentes do **BR SmartGuia**, sendo responsável pela **detecção de obstáculos** à frente do usuário. Ele mede a distância de objetos próximos e envia essa informação para o sistema, permitindo alertas sonoros e visuais para garantir a segurança do usuário.  

---

## 📌 **1. O que é esse sensor?**  

O **HC-SR04** é um **sensor de distância** que utiliza ondas ultrassônicas para **detectar objetos e calcular sua proximidade**. Ele é amplamente utilizado em projetos de robótica e sistemas de navegação assistiva devido à sua **precisão e baixo custo**.  

---

## ⚙️ **2. Como ele funciona?**  

O funcionamento do **HC-SR04** se baseia no **tempo de resposta das ondas ultrassônicas**:  

1️⃣ **Emissão do Pulso:** O sensor envia uma onda sonora inaudível pelo pino **Trigger**.  
2️⃣ **Reflexão:** A onda atinge um obstáculo e retorna para o sensor.  
3️⃣ **Cálculo da Distância:** O pino **Echo** mede o tempo que a onda demorou para voltar.  
4️⃣ **Conversão:** O tempo é convertido em **distância (cm)** e enviado ao microcontrolador.  

✅ **Fórmula utilizada:**  

<p align="center">
  <img src="../../assets/formula_ultrassonico.png" alt="Sensor Ultrassônico HC-SR04" width="400">
</p>

📏 O sensor pode detectar objetos a uma distância de **2 cm a 4 metros**!  

---

## 🎯 **3. Qual o papel dele no BR SmartGuia?**  

No projeto, o **HC-SR04** tem um papel essencial para a mobilidade segura do usuário:  

✅ **Monitora continuamente o ambiente à frente do carrinho** 🚶‍♂️  
✅ **Emite alertas sonoros no buzzer caso um obstáculo esteja a ≤ 15 cm** 🔊  
✅ **Atualiza as informações no display OLED** 📟  

Dessa forma, o sensor permite que o usuário **tenha consciência da proximidade de objetos**, evitando colisões.  

---

## 🔄 **4. Como ele interage com os outros módulos?**  

O **Sensor Ultrassônico HC-SR04** está **diretamente conectado ao Raspberry Pi Pico W** e interage com outros módulos para proporcionar uma experiência integrada:  

| 🔗 **Módulo** | 🛠 **Interação com o HC-SR04** |
|--------------|-------------------------------|
| **Buzzer (MLT8530)** | Emite um **alerta sonoro** caso um obstáculo seja detectado. 🔊 |
| **Display OLED (SSD1306)** | Exibe a **distância** do obstáculo em tempo real. 📟 |
| **Matriz de LEDs RGB 5x5** | Ajuda a **sinalizar visualmente** para terceiros. 💡 |
| **Botões (A e B)** | Permitem ao usuário **ativar/desativar alertas visuais**. 🎛 |
| **Raspberry Pi Pico W** | Processa os dados do sensor e toma as **decisões do sistema**. 🖥 |

📌 **Fluxo de funcionamento do sensor:**  
1️⃣ O **HC-SR04** detecta um obstáculo próximo.  
2️⃣ A **distância é enviada ao Raspberry Pi Pico W**.  
3️⃣ Se o obstáculo estiver a **≤ 15 cm**, o **buzzer emite um alerta sonoro**.  
4️⃣ O **display OLED exibe a distância** e a **Matriz de LEDs acende** para alertar terceiros (quando o usuário habilitá-la pressionando o botão `A`).  

---

### 🚀 **Resumo do Sensor Ultrassônico HC-SR04 no BR SmartGuia**  
✅ **Detecção precisa** de obstáculos em tempo real.  
✅ **Interação com buzzer, display e LEDs** para segurança e acessibilidade.  
✅ **Baixo consumo de energia** e compatível com o Raspberry Pi Pico W.  

Com esse sensor, o **BR SmartGuia proporciona mais autonomia e segurança** para o usuário em ambientes movimentados, como supermercados! 🛒✨  