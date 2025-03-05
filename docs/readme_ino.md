# Protótipo Biomédico: Mão Robótica - Usando Arduino

O projeto com Arduino consiste em uma mão robótica controlada por meio de uma luva equipada com sensores flexíveis. Os movimentos dos dedos da luva são capturados e acionam os servomotores para replicar os gestos na mão robótica.

# Funcionalidades

- Imitação dos movimentos e gestos de uma mão humana
- Aplicável a variados modelos 3D ([Modelos Compatíveis](compatibilidade_3d.md))

# Hardware necessário

- Modelo mão humana ([Modelos Compatíveis](compatibilidade_3d.md))
- Linha elástica (para estrutura) e Linha de poliamidas (0.9 mm em média)
- 1x Arduino
- 5X Sensores de pressão flexíveis
- 5x Servomotores (MG90 ou semelhante)
- Jumpers, resistores 10k (ou conforme seu sensor flexível) e materiais para conexão

# Software

- Arduino IDE (para programação do Arduino)
- Biblioteca Servo.h (para controle dos servos)

# Como Rodar o Projeto

## Preparo inicial

1. Realize a montagem do prótotico conforme indicado ([Modelos Compatíveis](compatibilidade_3d.md))
2. Use como base o modelo de simulação para [Arduino](simulacao_ino.md)
3. Conecte o Arduino ao Computador com Arduino IDE
4. Configure e instale as bibliotecas necesárias para o funcionamento do Arduino

## Upload

1. Carregue o código da `mao_robotica_ino.ino` na ESP32 da mão robótica.
5. Teste os movimentos!

## Calibração

Por se tratar de sensores simples, recomendamos uma calibração manual de cada sensor por meio da testagem em cada um dos dedos
```cpp
int inputMin[5] = {3900, 3400, 3000, 3600, 3000};
int inputMax[5] = {4095, 4095, 4095, 4095, 4095};
int outputMin[5] = {180, 180, 180, 180, 180};
int outputMax[5] = {0, 0, 0, 0, 0};
```
Nessa linha ocorre mapeamento dos valores dos sensores para movimentação (por angulação) dos servomotores, basta atualizar os valores conforme a leitura ocorra. Esses valores dos sensores podem ser encontrados no **monitor serial** durante a execução do código