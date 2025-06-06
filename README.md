# 🌊 Monitor de Enchentes com Arduino

Sistema embarcado baseado em Arduino para monitoramento de umidade do solo e intensidade de chuva, com alertas visuais, sonoros e exibição de dados em display LCD.

---

## 🧩 Problemas a Solucionar

Acompanhar condições ambientais como umidade do solo e presença de chuva é importante para prevenção de riscos, automação e controle em diversas aplicações. Este projeto oferece uma solução simples e eficiente para esse tipo de monitoramento local.

---

## 💡 Visão Geral da Solução

O sistema utiliza sensores analógicos e digitais conectados a um Arduino Uno para medir umidade e simular chuva. Os dados são processados para acionar alertas com LEDs, buzzer e exibição em um display LCD 16x2 com alternância automática de tela.

---

## 🔧 Componentes Utilizados

- Arduino Uno
- Sensor de umidade do solo (simulado com potenciômetro)
- Sensor ultrassônico HC-SR04 (simula chuva)
- Display LCD 16x2 com módulo I2C
- Buzzer piezoelétrico
- LEDs: vermelho, amarelo e verde
- Protoboard, resistores e jumpers

---

## ⚙️ Funcionamento do Sistema

### 📊 Leitura dos Sensores

- **Umidade do Solo:** Lida via pino analógico A0 e convertida para percentual.
- **Chuva:** Simulada por variações na distância medida pelo sensor HC-SR04.

### 🔁 Estados Monitorados

**Umidade do Solo:**
- `< 30%` → **SECO**
- `30% a 70%` → **NORMAL**
- `> 70%` → **ALAGADO**

**Chuva (baseada na distância):**
- `< 30%` → **Sem chuva**
- `> 70%` → **Chuva intensa**

### 📺 Exibição no LCD

O display alterna entre duas telas a cada 3 segundos:

1. **Status do Solo:** Mostra o nível de umidade e o estado atual.
2. **Status da Chuva:** Exibe a estimativa de chuva e alerta se necessário.

### 🔊 Alertas Visuais e Sonoros

- **🔴 LED Vermelho:** Solo alagado **e** chuva intensa  
- **🟡 LED Amarelo:** Solo seco **e** chuva intensa  
- **🟢 LED Verde:** Situação normal  

- **🎵 Buzzer:**
  - 1000 Hz → Solo alagado
  - 800 Hz → Chuva intensa
  - Desligado → Sem alerta

---

## 🧪 Guia de Simulação (Wokwi)

1. Acesse o projeto: [**Simule aqui no Wokwi**](https://wokwi.com/projects/432982618749359105)
2. Gire o potenciômetro para simular diferentes níveis de umidade.
3. Aproxime objetos do sensor ultrassônico para simular chuva (menor distância = mais chuva).
4. Observe os LEDs, buzzer e as mensagens no LCD.

---

## 🎥 Demonstração em Vídeo

Assista ao funcionamento do projeto no vídeo abaixo:  
[**Ver vídeo demonstrativo**](--------)

---

## 🔄 Melhorias Futuras

- Integração com Wi-Fi (ESP8266/ESP32) para envio de dados
- Registro de histórico em cartão SD ou dashboard web
- Alimentação com energia solar
- Integração com aplicativos móveis

---

## 🧭 Aplicações Possíveis

- Sistemas de irrigação inteligente
- Monitoramento de ambientes sujeitos a alagamento
- Projetos educacionais com foco em eletrônica e IoT

---

## 📃 Licença

Este projeto é open-source e pode ser utilizado, modificado e distribuído livremente com os devidos créditos.

---

## Autor

Desenvolvido por **Matheus Tozarelli Egea (RM: 563490)**
