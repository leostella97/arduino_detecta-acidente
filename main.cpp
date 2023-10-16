// Inclua as bibliotecas necessárias para o sensor de inclinação
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

// Defina os pinos para o sensor de inclinação e módulo GSM
const int pinoSensorInclinacao = 2;  // Substitua pelo pino real que você está usando
const int pinoModuloGSM = 3;         // Substitua pelo pino real que você está usando

// Variáveis para controlar o estado da inclinação e detecção de acidente
bool acidenteDetectado = false;

void setup() {
  // Inicializa o sensor de inclinação como entrada
  pinMode(pinoSensorInclinacao, INPUT);

  // Inicializa o módulo GSM como saída
  pinMode(pinoModuloGSM, OUTPUT);

  // Inicializa a comunicação serial para monitoramento
  Serial.begin(9600);
}

void loop() {
  // Verifica o estado do sensor de inclinação
  int estadoInclinacao = digitalRead(pinoSensorInclinacao);

  // Se uma inclinação brusca for detectada (indicando um acidente)
  if (estadoInclinacao == HIGH) {
    // Chama a função para enviar alerta
    enviarAlertaAcidente();
  }

  // Aguarda por algum tempo antes de verificar novamente
  delay(1000);  // Pode ser ajustado conforme necessário
}

void enviarAlertaAcidente() {
  // Ativa o módulo GSM para enviar um alerta
  digitalWrite(pinoModuloGSM, HIGH);

  // Mensagem de alerta
  Serial.println("Acidente detectado! Chamando a polícia...");

  // Aguarda um tempo para a chamada ser realizada
  delay(5000);  // Pode ser ajustado conforme necessário

  // Desativa o módulo GSM
  digitalWrite(pinoModuloGSM, LOW);

  // Reinicia a variável para evitar alertas repetidos
  acidenteDetectado = false;
}
