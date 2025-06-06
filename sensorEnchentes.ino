#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

// Sensor de umidade do solo (simulado por um potenciômetro)
const int sensorUmidadePin = A0;

// Sensor ultrassônico HC-SR04 (4 pinos: VCC, GND, Trig, Echo)
const int trigPin = 7;
const int echoPin = 5;

// Buzzer para alertas sonoros
const int buzzerPin = 6;

// Pinos dos LEDs
const int ledVermelho = 8;
const int ledAmarelo = 9;
const int ledVerde = 10;

// Variáveis para controle da exibição alternada no LCD
unsigned long previousMillis = 0;
const long interval = 3000; 
int lcdState = 0; 

void setup() {
  // Inicializa o LCD
  lcd.init();
  lcd.backlight();

  // Configura o pino do Buzzer como OUTPUT
  pinMode(buzzerPin, OUTPUT);

  // Configura os pinos dos LEDs como OUTPUT
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  // Configura os pinos do HC-SR04
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Inicia a comunicação serial para depuração
  Serial.begin(9600);

  // Mensagem inicial no LCD
  lcd.setCursor(0, 0);
  lcd.print("Monitor Enchente");
  lcd.setCursor(0, 1);
  lcd.print("Iniciando...");
  delay(3000);
  lcd.clear();
}

void loop() {
  int valorUmidade = analogRead(sensorUmidadePin);
  int umidadePercent = map(valorUmidade, 1023, 0, 0, 100);

  //Leitura do Sensor Ultrassônico HC-SR04 (COMO SENSOR DE CHUVA) 
  long duracao, distanciaBruta;

  // Limpa o trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Mede a duração do pulso no echoPin
  duracao = pulseIn(echoPin, HIGH, 30000);

  distanciaBruta = duracao * 0.034 / 2; 


  int chuvaPercent = map(distanciaBruta, 400, 0, 0, 100); 
  chuvaPercent = constrain(chuvaPercent, 0, 100); // Garante que o valor fique entre 0 e 100

  // --- Lógica de Status da Umidade ---
  String statusUmidade;
  if (umidadePercent < 30) {
    statusUmidade = "SECO"; 
  } else if (umidadePercent <= 70) {
    statusUmidade = "NORMAL";
  } else {
    statusUmidade = "ALAGADO!"; 
  }

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    lcdState = (lcdState + 1) % 2; 
    lcd.clear(); 
  }

  if (lcdState == 0) {
    // Exibe informações de umidade
    lcd.setCursor(0, 0);
    lcd.print("SOLO ");
    lcd.print(statusUmidade); 
    lcd.print("   "); 

    lcd.setCursor(0, 1);
    lcd.print("Umid: ");
    lcd.print(umidadePercent);
    lcd.print("%      "); 
  } else {
    // Exibe informações de chuva
    lcd.setCursor(0, 0);
    if (chuvaPercent > 70) { // Chuva intensa
      lcd.print("ALERTA CHUVA!"); 
    } else {
      lcd.print("Sem Alerta Chuva");
    }
    lcd.print("   "); 

    lcd.setCursor(0, 1);
    lcd.print("Chuva: ");
    lcd.print(chuvaPercent);
    lcd.print("%      "); 
  }

  //Saída para o Monitor Serial 
  Serial.print("Umid: ");
  Serial.print(umidadePercent);
  Serial.print("% (");
  Serial.print(statusUmidade);
  Serial.print(") | Chuva: "); 
  Serial.print(chuvaPercent);
  Serial.print("% (Dist: ");
  Serial.print(distanciaBruta);
  Serial.println(" cm)");


  // Buzzer alerta para umidade alta ou chuva intensa
  if (statusUmidade == "ALAGADO!") {
    tone(buzzerPin, 1000); 
  } else if (chuvaPercent > 70) { 
    tone(buzzerPin, 800); 
  } else {
    noTone(buzzerPin); 
  }

  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, LOW);

  // Condição: Chuva ALTA e Umidade ALTA -> LED VERMELHO
  if (chuvaPercent > 70 && umidadePercent > 70) {
    digitalWrite(ledVermelho, HIGH);
  }
  // Condição: Chuva ALTA e Umidade BAIXA/SECA -> LED AMARELO
  else if (chuvaPercent > 70 && umidadePercent < 30) {
    digitalWrite(ledAmarelo, HIGH);
  }
  // Condição: Chuva MEDIA/BAIXA e Umidade ALTA/BAIXA/SECA -> LED VERDE
  else if (chuvaPercent <= 70) {
    digitalWrite(ledVerde, HIGH);
  }

}
