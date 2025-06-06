# 🌊 Monitor de Enchentes com Arduino

Sistema embarcado baseado em Arduino para **monitoramento de umidade do solo** e **intensidade de chuva**, com alertas visuais (LEDs), sonoros (buzzer) e exibição em LCD.

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

## ⚙️ Funcionamento

### 📊 Leitura dos Sensores

- **Umidade do solo**: obtida via pino analógico A0 e convertida para percentual.
- **Chuva**: simulada com sensor ultrassônico, medindo distância até gotas ou obstáculos.

### 💡 Lógica de Estado

**Umidade do Solo:**
- `< 30%` → **SECO**
- `30% a 70%` → **NORMAL**
- `> 70%` → **ALAGADO**

**Chuva (calculada via distância):**
- `< 30%` → **Sem chuva**
- `> 70%` → **Chuva intensa**

---

## 📺 Exibição no LCD

O display LCD alterna automaticamente entre duas telas a cada 3 segundos:

1. **Status do Solo:**
   - Mostra o percentual de umidade e o estado atual (SECO / NORMAL / ALAGADO)

2. **Status da Chuva:**
   - Exibe o percentual estimado de chuva e alerta se estiver acima de 70%

---

## 🔊 Alertas Sonoros e Visuais

### 🎵 Buzzer
- **1000 Hz**: solo alagado
- **800 Hz**: chuva intensa
- **Desligado**: sem alerta

### 💡 LEDs
- 🔴 **LED Vermelho**: Solo alagado **e** chuva intensa
- 🟡 **LED Amarelo**: Solo seco **e** chuva intensa
- 🟢 **LED Verde**: Situação normal (sem chuva forte)

---

## 🧪 Simulação e Testes

- Umidade do solo pode ser simulada com **potenciômetro**.
- Chuva simulada aproximando objetos do **HC-SR04** (menor distância = mais chuva).

---

## 💡 Melhorias Futuras

- Envio de dados para nuvem (ESP8266 ou ESP32)
- Histórico de medições em cartão SD ou interface web
- Painel solar para alimentação autônoma
- Integração com aplicativos móveis

---

## 🧭 Aplicações Possíveis

- Sistemas de irrigação inteligente
- Monitoramento de áreas urbanas com risco de alagamento
- Educação e prototipagem em eletrônica e IoT

---

## 📃 Licença

Este projeto é open-source e pode ser utilizado, modificado e distribuído livremente com os devidos créditos.

---

## Autor

Desenvolvido por **[Matheus Tozarelli Egea (RM: 563490)]**
