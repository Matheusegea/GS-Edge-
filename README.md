# 🌊 Monitor de Enchentes com Arduino

Sistema embarcado baseado em Arduino para monitoramento de umidade do solo e intensidade de chuva, com alertas visuais (LEDs), sonoros (buzzer) e exibição em LCD.

---

## 🧩 Descrição do Problema

Enchentes e alagamentos causam sérios danos em áreas urbanas e rurais. A falta de monitoramento preventivo agrava esses problemas. Este projeto propõe um sistema simples e acessível para detectar condições de solo encharcado e chuva intensa, emitindo alertas visuais e sonoros para prevenir danos e agir rapidamente.

---

## 💡 Visão Geral da Solução

Este sistema usa sensores para medir umidade do solo e intensidade de chuva simulada, exibindo os dados em um display LCD e acionando alertas conforme os níveis detectados.

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

- **Umidade do solo:** Lida via pino analógico A0 e convertida para percentual.
- **Chuva:** Simulada por um sensor ultrassônico que mede a distância até gotas ou obstáculos (menor distância = mais chuva).

### 💡 Lógica de Estado

**Umidade do Solo:**
- < 30% → `SECO`
- 30% a 70% → `NORMAL`
- > 70% → `ALAGADO`

**Chuva (com base na distância):**
- > 70% (distância próxima) → `Chuva intensa`
- < 30% (distância longa) → `Sem chuva`

### 📺 Exibição no LCD

O display LCD alterna automaticamente entre duas telas a cada 3 segundos:

1. **Status do Solo**
   - Percentual de umidade
   - Estado: SECO / NORMAL / ALAGADO

2. **Status da Chuva**
   - Estimativa de chuva
   - Alerta se > 70%

### 🔊 Alertas Sonoros e Visuais

#### 🎵 Buzzer
- 1000 Hz → Solo alagado
- 800 Hz → Chuva intensa
- Desligado → Sem alerta

#### 💡 LEDs
- 🔴 Vermelho → Solo alagado **e** chuva intensa
- 🟡 Amarelo → Solo seco **e** chuva intensa
- 🟢 Verde → Situação normal

---

## 🧪 Guia de Simulação (Wokwi)

1. Acesse o projeto no Wokwi: [**Clique aqui para simular**](https://wokwi.com/projects/432982618749359105)
2. Gire o potenciômetro para simular diferentes níveis de umidade.
3. Aproxime objetos do sensor ultrassônico para simular chuva (menor distância = chuva intensa).
4. Observe a mudança de estado no LCD, o acionamento do buzzer e os LEDs.

---

## 🎥 Demonstração em Vídeo

Veja o projeto em funcionamento no vídeo abaixo:  
[**Assista no YouTube**](---------------)

---

## 💡 Melhorias Futuras

- Envio de dados para a nuvem via ESP8266/ESP32
- Registro de histórico em cartão SD ou via interface web
- Alimentação por energia solar
- Integração com apps móveis (ex: notificações via celular)

---

## 🧭 Aplicações Possíveis

- Sistemas de irrigação inteligentes
- Monitoramento de enchentes em áreas urbanas
- Projetos educacionais de eletrônica e IoT

---

## 📃 Licença

Este projeto é open-source e pode ser utilizado, modificado e distribuído livremente com os devidos créditos.

---

## Autor

Desenvolvido por **Matheus Tozarelli Egea (RM: 563490)**
