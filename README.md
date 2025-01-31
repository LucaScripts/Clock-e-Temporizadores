## 🚦 Simulação de Semáforo com Raspberry Pi Pico
📌 Autor: Lucas Dias

📆 Data: 31/01/2025

Este projeto implementa um **sistema de semáforo** utilizando o **Raspberry Pi Pico** e LEDs para indicar os estados de trânsito: **Vermelho (PARE), Amarelo (ATENÇÃO) e Verde (SIGA)**. O código utiliza **temporizadores periódicos** para alternar os sinais a cada **3 segundos**.  

---

## 📌 **Características**
✅ Alternância automática dos sinais do semáforo (vermelho → amarelo → verde).  
✅ Utilização da função `add_repeating_timer_ms()` para controle do tempo.  
✅ Exibição de mensagens via **serial** indicando o estado do semáforo.  
✅ Código otimizado, modular e bem documentado.  

---

## 🛠 **Materiais Necessários**
🔹 1x **Raspberry Pi Pico**  
🔹 1x **LED Vermelho** (🚦 PARE)  
🔹 1x **LED Amarelo** (⚠️ ATENÇÃO)  
🔹 1x **LED Verde** (✅ SIGA)  
🔹 3x **Resistores de 330Ω**  
🔹 Fios jumper e protoboard  

---

## 🏗 **Esquema de Ligação**
| Componente | Pino do Raspberry Pi Pico |
|------------|---------------------------|
| LED Verde  | GPIO 11                   |
| LED Amarelo| GPIO 12                   |
| LED Vermelho| GPIO 13                   |

**⚠️ OBS:** O lado positivo do LED deve ser conectado ao GPIO correspondente e o negativo ao GND através de um **resistor de 330Ω**.

---

## 📜 **Instalação e Execução**

### **1️⃣ Configurar o ambiente**
Certifique-se de ter o **Pico SDK** instalado e configurado no seu sistema.  

Se ainda não configurou, siga as instruções oficiais:  
🔗 [Guia Oficial do Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk)

### **2️⃣ Clonar o repositório**
```bash
git clone https://github.com/seu-usuario/semaforo-pico.git
cd semaforo-pico
```

### **3️⃣ Compilar e enviar o código para o Raspberry Pi Pico**
No ambiente **VS Code** com o **Pico SDK** configurado:  
```bash
mkdir build
cd build
cmake ..
make
```
Após a compilação, copie o arquivo `.uf2` gerado para o Raspberry Pi Pico (modo bootloader ativado).

### **4️⃣ Testar o projeto**
Abra um terminal serial para visualizar as mensagens do semáforo:  
```bash
minicom -b 115200 -o -D /dev/ttyUSB0
```
Ou utilize o **Putty** no Windows configurando a porta serial correta.

---

## 🎯 **Funcionamento**
- O código inicia com o **LED vermelho ligado** (PARE).  
- A cada **3 segundos**, alterna para **amarelo** e depois para **verde**.  
- No **terminal serial**, mensagens são exibidas indicando o estado do semáforo.  
- O loop principal imprime uma mensagem a cada **1 segundo**.  

---
## 🚦 Demonstração da Simulação

Abaixo está uma prévia da simulação do semáforo no **Wokwi**:

![Simulação do Semáforo no Wokwi] https://github.com/LucaScripts/Clock-e-Temporizadores/blob/main/docs/Clock-e-Temporizadores%20-%20Visual%20Studio%20Code%202025-01-31%2018-33-11.gif
---

## 🎥 **Demonstração (Simulação no Wokwi)**
🔗 Teste no Wokwi: [Clique Aqui](https://wokwi.com/projects/123456) *(Substitua pelo link da simulação)*  

---

## 📌 **Melhorias Futuras**
- 🚀 Implementação de um botão para **controle manual do semáforo**.  
- 📡 Adição de um **sensor de presença** para ativação automática.  
- 🕹️ Interface para controle remoto via **Wi-Fi/Bluetooth**.  

