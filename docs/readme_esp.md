# Protótipo Biomédico: Mão Robótica - Usando ESP32

O projeto com a ESP32 consiste em uma mão robótica controlada remotamente por meio de uma luva equipada com sensores flexíveis e um ESP32. Os movimentos dos dedos da luva são capturados e enviados via Wi-Fi para um segundo ESP32, que interpreta os sinais e aciona servomotores para replicar os gestos na mão robótica.

# Funcionalidades

- Imitação dos movimentos e gestos de uma mão humana
- Comunicação por Wifi (Protocolo UDP local)
- Aplicável a variados modelos 3D ([Modelos Compatíveis](compatibilidade_3d.md))

# Hardware necessário

- Modelo mão humana ([Modelos Compatíveis](compatibilidade_3d.md))
- Linha elástica (para estrutura) e Linha de poliamidas (0.9 mm em média)
- 2x ESP32
- 5X Sensores de pressão flexíveis
- 5x Servomotores (MG90 ou semelhante)
- Jumpers, resistores 10k (ou conforme seu sensor flexível) e materiais para conexão
- Wi-fi para hospedar as duas ESP32

# Software

- Arduino IDE (para programação do ESP32)
- Biblioteca Servo.h (para controle dos servos)
- WiFi.h (para comunicação entre ESP32s)

# Como Rodar o Projeto

## Preparo inicial

1. Realize a montagem do prótotico conforme indicado ([Modelos Compatíveis](compatibilidade_3d.md))
2. Use como base o modelo de simulação para [ESP32](simulacao_esp.md)
3. Conecte ambas placas ao Computador com Arduino IDE
4. Configure e instale as bibliotecas necesárias para o funcionamento da ESP32
5. Ligue o roteador e ajuste o SSID, Password e porta nos códigos conforme o desejado

## Upload

1. Carregue o código da `mao_robotica_esp.ino` na ESP32 da mão robótica.
2. Copie o IP fornecido no monitor serial
3. Cole o IP fornecido para a `luva_esp.ino` e carregue o código na ESP32 da luva.
4. Renicie as ESP32 e verifique se ocorre a conexão de ambas ao Wi-fi.
5. Teste os movimentos!

## Calibração

1. Por se tratar de sensores simples, recomendamos uma calibração manual de cada sensor por meio da testagem em cada um dos dedos
```cpp
int inputMin[5] = {3900, 3400, 3000, 3600, 3000};
int inputMax[5] = {4095, 4095, 4095, 4095, 4095};
int outputMin[5] = {180, 180, 180, 180, 180};
int outputMax[5] = {0, 0, 0, 0, 0};
```
Nessa linha ocorre mapeamento dos valores dos sensores para movimentação (por angulação) dos servomotores, basta atualizar os valores conforme a leitura ocorra. Esses valores dos sensores podem ser encontrados no **monitor serial** durante a execução do código