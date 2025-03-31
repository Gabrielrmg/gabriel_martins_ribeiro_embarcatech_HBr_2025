# 🔋 **Fonte de Alimentação (Power Bank)**  

<p align="center">
  <img src="../../assets/img/modules/powerbank.png" alt="Fonte de Alimentação Power Bank" width="250">
</p>  

A **Fonte de Alimentação (Power Bank)** é a responsável por fornecer **energia contínua** para o funcionamento do **BR SmartGuia**, garantindo que todos os módulos operem de forma eficiente e confiável.  

Por ser um sistema portátil, o BR SmartGuia precisa de uma **fonte de energia compacta e duradoura**, permitindo que o usuário utilize o dispositivo **sem a necessidade de conexão direta à rede elétrica**.  

---

## 📌 **1. O que é esse módulo?**  

O **Power Bank** é uma **bateria recarregável portátil**, projetada para fornecer **energia via USB** a dispositivos eletrônicos, como **smartphones, microcontroladores e sensores**.  

✅ **Fornece energia para todos os módulos** 🔋  
✅ **Portátil e recarregável** 🔄  
✅ **Maior autonomia para o sistema** ⏳  

Essa fonte de alimentação garante que o **BR SmartGuia possa ser utilizado por longos períodos** sem necessidade de recarga imediata.  

---

## ⚙️ **2. Como ele funciona?**  

O **Power Bank** possui uma **bateria de íons de lítio** que armazena energia e a libera conforme necessário. Ele pode ser conectado ao **Raspberry Pi Pico W** via cabo USB, garantindo o fornecimento de energia de forma estável.  

📢 **Fluxo de funcionamento do Power Bank:**  
1️⃣ O usuário **carrega o Power Bank** antes do uso.  
2️⃣ Ele é conectado ao **Raspberry Pi Pico W** via cabo USB.  
3️⃣ O **microcontrolador distribui a energia para os sensores e atuadores**.  
4️⃣ Quando a carga acabar, basta **recarregar o Power Bank** para continuar usando o sistema.  

💡 **Principais características:**  
✔ **Saída de 5V e corrente suficiente para alimentar o sistema** ⚡  
✔ **Compatível com microcontroladores e sensores**  
✔ **Proteção contra curto-circuito e sobrecarga** 🛡  

---

## 🎯 **3. Qual o papel dele no BR SmartGuia?**  

A **Fonte de Alimentação (Power Bank)** é fundamental para garantir a **mobilidade e autonomia** do BR SmartGuia.  

🔋 **Funções do Power Bank no sistema:**  
✅ **Fornece energia para o Raspberry Pi Pico W e demais módulos** ⚡  
✅ **Permite o uso do dispositivo sem conexão direta à tomada** 🔄  
✅ **Facilmente recarregável para longas jornadas de uso** ⏳  

📌 **Exemplo de uso:**  
🔹 O usuário pode **carregar completamente o Power Bank** antes de sair de casa e utilizar o BR SmartGuia por várias horas sem precisar recarregar.  

---

## 🔄 **4. Como ele interage com os outros módulos?**  

O **Power Bank** é o **ponto central de alimentação** do sistema, garantindo que todos os módulos operem corretamente.  

| 🔗 **Módulo** | 🛠 **Interação com o Power Bank** |
|--------------|-------------------------------|
| **Raspberry Pi Pico W** | Recebe a energia do Power Bank e a distribui para os outros módulos. 🖥 |
| **Buzzer (MLT8530)** | Funciona apenas quando há energia suficiente. 🔊 |
| **Display OLED (SSD1306)** | Precisa de alimentação estável para exibir informações corretamente. 📟 |
| **Matriz de LEDs RGB 5x5** | Consome energia do Power Bank para exibir os padrões visuais. 💡 |
| **Sensor Ultrassônico (HC-SR04)** | Depende da alimentação para medir distâncias e detectar obstáculos. 📏 |

📌 **Fluxo de funcionamento do Power Bank no sistema:**  
1️⃣ O usuário **liga o BR SmartGuia** conectando o Power Bank.  
2️⃣ O **Raspberry Pi Pico W recebe energia** e distribui para os módulos.  
3️⃣ Todos os sensores e atuadores começam a funcionar.  

---

### 🚀 **Resumo da Fonte de Alimentação (Power Bank) no BR SmartGuia**  
✅ **Garante energia para todos os módulos do sistema** ⚡  
✅ **Permite o uso contínuo sem conexão elétrica** 🔄  
✅ **Facilmente recarregável para longa autonomia** 🔋  
✅ **Torna o BR SmartGuia um dispositivo realmente portátil** 🚶‍♂️  

Com essa **fonte de alimentação portátil**, o **BR SmartGuia** se torna um dispositivo **independente e funcional**, pronto para auxiliar o usuário em diferentes ambientes! 🚀🔋  