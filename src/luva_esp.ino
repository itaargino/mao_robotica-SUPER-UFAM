#include <WiFi.h>  // Biblioteca para conexão Wi-Fi no ESP32
#include <WiFiUdp.h> // Biblioteca para comunicação via UDP

// Definição dos pinos analógicos onde os sensores estão conectados
const int sensorPins[] = {25, 33, 32, 35, 34};  
int sensorValues[5]; // Array para armazenar as leituras dos sensores

// Configuração da rede Wi-Fi (substitua pelos dados corretos da sua rede)
const char* ssid = "biomedica";      // Nome da rede Wi-Fi
const char* password = "teste505";   // Senha da rede Wi-Fi

// Configuração do destino da comunicação UDP (substitua pelo IP correto)
const char* udpAddress = "192.168.29.17"; // Endereço IP do dispositivo que receberá os dados
const int udpPort = 12345;  // Porta utilizada para comunicação UDP

WiFiUDP udp; // Objeto para comunicação UDP

void setup() {
  Serial.begin(9600);  // Inicializa a comunicação serial para depuração

  // Conexão à rede Wi-Fi
  Serial.println("Conectando ao Wi-Fi...");
  WiFi.begin(ssid, password);

  // Aguarda a conexão Wi-Fi ser estabelecida
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nWi-Fi conectado!");
  Serial.print("IP do ESP32: ");
  Serial.println(WiFi.localIP());  // Exibe o IP atribuído ao ESP32

  // Configuração dos pinos dos sensores como entrada
  for (int i = 0; i < 5; i++) {
    pinMode(sensorPins[i], INPUT);
  }
}

void loop() {
  // Leitura dos valores dos sensores
  for (int i = 0; i < 5; i++) {
    sensorValues[i] = analogRead(sensorPins[i]); // Captura os valores analógicos dos sensores
  }

  // Impressão dos valores lidos no monitor serial
  Serial.print("Sensor 25: ");
  Serial.print(sensorValues[0]);
  Serial.print(" || Sensor 33: ");
  Serial.print(sensorValues[1]);
  Serial.print(" || Sensor 32: ");
  Serial.print(sensorValues[2]);
  Serial.print(" || Sensor 35: ");
  Serial.print(sensorValues[3]);
  Serial.print(" || Sensor 34: ");
  Serial.print(sensorValues[4]);

  // Formatação da string de dados a ser enviada via UDP
  String message = "";
  for (int i = 0; i < 5; i++) {
    message += String(sensorValues[i]);
    if (i < 4) message += ","; // Adiciona uma vírgula entre os valores
  }

  Serial.print(" Enviando: ");
  Serial.println(message);

  // Envio dos dados via UDP para o dispositivo de destino
  udp.beginPacket(udpAddress, udpPort); // Inicia o pacote UDP
  udp.print(message);  // Adiciona a string formatada no pacote
  udp.endPacket();  // Envia o pacote

  delay(300);  // Pequeno atraso para controle do envio de dados
}
