#include <ESP32Servo.h>  // Biblioteca para controle dos servos no ESP32
#include <WiFi.h>        // Biblioteca para conexão Wi-Fi
#include <WiFiUDP.h>     // Biblioteca para comunicação UDP

// Configuração da rede Wi-Fi (substitua pelos dados corretos da sua rede)
const char* ssid = "biomedica";      // Nome da rede Wi-Fi
const char* password = "teste505";   // Senha da rede Wi-Fi

// Configuração do servidor UDP para recepção dos dados
WiFiUDP udp;
const int localUdpPort = 12345; // Porta UDP que receberá os pacotes de dados
char incomingPacket[255];       // Buffer para armazenar os dados recebidos

// Declaração dos servos que serão controlados
Servo servo1, servo2, servo3, servo4, servo5;

// Pinos digitais aos quais os servos estão conectados
const int servoPins[] = {23, 18, 19, 21, 22};
int servoPositions[5] = {0}; // Armazena a posição de cada servo

// Ajustes individuais para calibração dos servos
// Faixa de entrada baseada na leitura do sensor flexível
int inputMin[5] = {3900, 3400, 3000, 3600, 3000}; // Valor máximo de flexão (180 graus)
int inputMax[5] = {4095, 4095, 4095, 4095, 4095}; // Valor mínimo de flexão (0 graus)

// Faixa de saída correspondente ao movimento dos servos
int outputMin[5] = {180, 180, 180, 180, 180}; // Posição máxima dos servos (totalmente dobrado)
int outputMax[5] = {0, 0, 0, 0, 0};          // Posição mínima dos servos (totalmente estendido)

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial para depuração

  // Conexão com a rede Wi-Fi
  Serial.println("Conectando ao Wi-Fi...");
  WiFi.begin(ssid, password);
  
  // Aguarda a conexão ser estabelecida
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("\nWi-Fi conectado!");
  Serial.print("IP do ESP32 receptor: ");
  Serial.println(WiFi.localIP()); // Exibe o IP atribuído ao ESP32

  // Inicializa o servidor UDP na porta especificada
  udp.begin(localUdpPort);
  Serial.printf("Servidor UDP iniciado na porta %d\n", localUdpPort);

  // Associa cada servo a um pino digital correspondente
  servo1.attach(servoPins[0]);
  servo2.attach(servoPins[1]);
  servo3.attach(servoPins[2]);
  servo4.attach(servoPins[3]);
  servo5.attach(servoPins[4]);

  // Inicializa os servos na posição zero
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);
  servo5.write(0);
}

void loop() {
  int packetSize = udp.parsePacket(); // Verifica se há um pacote UDP disponível
  
  if (packetSize) {
    // Lê os dados recebidos via UDP
    int len = udp.read(incomingPacket, 255);
    if (len > 0) {
      incomingPacket[len] = '\0'; // Adiciona um terminador nulo para evitar problemas na string
    }
    
    Serial.printf("Dados recebidos: %s\n", incomingPacket);

    // Converte os dados recebidos em um array de valores dos sensores
    String data = String(incomingPacket);
    int sensorValues[5];
    int index = 0;
    
    while (data.length() > 0) {
      int commaIndex = data.indexOf(','); // Encontra a próxima vírgula
      if (commaIndex == -1) {
        sensorValues[index] = data.toInt(); // Converte o último valor
        break;
      }
      sensorValues[index] = data.substring(0, commaIndex).toInt(); // Converte a string para número inteiro
      data = data.substring(commaIndex + 1); // Remove o valor já processado
      index++;
    }

    // Converte os valores recebidos para ângulos compatíveis com os servos
    for (int i = 0; i < 5; i++) {
      servoPositions[i] = map(sensorValues[i], inputMax[i], inputMin[i], outputMax[i], outputMin[i]);
      servoPositions[i] = constrain(servoPositions[i], outputMax[i], outputMin[i]); // Garante que o valor está no intervalo permitido
    }

    // Atualiza a posição dos servos de acordo com os valores recebidos
    servo1.write(servoPositions[0]);
    servo2.write(servoPositions[1]);
    servo3.write(servoPositions[2]);
    servo4.write(servoPositions[3]);
    servo5.write(servoPositions[4]);
  }
}
