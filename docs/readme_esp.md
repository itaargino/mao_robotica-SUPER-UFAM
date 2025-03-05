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
2. Conecte ambas placas ao Computador com Arduino IDE
3. Configure e instale as bibliotecas necesárias para o funcionamento da ESP32
4. Ligue o roteador e ajuste o SSID, Password e porta nos códigos conforme o desejado

## Upload
1. Carregue o código da `mao_robotica_esp` na ESP32 da mão robótica.
2. Copie o IP fornecido no monitor serial
3. Cole o IP fornecido para a `luva_esp` e carregue o código na ESP32 da luva.
4. Renicie as ESP32 e verifique se ocorre a conexão de ambas ao Wi-fi.
5. Teste os movimentos!