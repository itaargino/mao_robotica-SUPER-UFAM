# Requisitos de compatibilidade do Modelo 3D usado
Para garantir que o código funcione corretamente com o modelo 3D da mão robótica, é necessário que o modelo atenda aos seguintes requisitos:

1. **Articulações**
- Os dedos devem possuir articulações móveis projetadas para permitir flexão e extensão com tração por fios.
É recomendado o uso de pelo menos três segmentos por dedo (falanges proximal, média e distal).
2. **Passagem de Fios**
- Deve haver canais internos ou externos para a passagem dos fios de poliamida, permitindo que os dedos se movam corretamente.
Os furos devem ser suaves e sem arestas para evitar o desgaste do fio ao longo do tempo.
3. **Pontos de Fixação**
- O modelo deve possuir pontos de ancoragem para a fixação dos fios nos dedos e na base da mão.
Também deve incluir locais para instalação dos servomotores responsáveis pelo movimento.
4. **Compatibilidade com Servomotores**
- O projeto deve prever espaços adequados para acomodar os servomotores (recomendado SG90 ou MG995).
Devem estar posicionados de forma que os fios possam ser enrolados e desenrolados sem obstáculos.

# Instruções de Montagem (Geral)
> Estas intruções são gerais e podem variar conforme o modelo que for utilizado
1. **Preparação**
- Certifique-se de que todas as peças foram impressas corretamente e sem imperfeições que possam atrapalhar o funcionamento.
Passe um fio fino pelos canais para garantir que não há bloqueios antes de inserir o fio de poliamida.
2. **Passagem do Fio de Poliamida (0,9 mm)**
- Insira o fio de poliamida pelos canais projetados nos dedos, garantindo que ele percorra todas as articulações.
Um lado do fio deve ser preso na ponta do dedo (distal), e o outro deve sair na base da mão.
3. **Fixação nos Servomotores (pode ser feita no final)**
- Com servomotor em sua posição, amarre a extremidade do fio que sai da base da mão ao eixo do servomotor correspondente.
Certifique-se de que o fio esteja tensionado, mas não excessivamente apertado, para evitar travamentos no movimento.
4. **Instalação dos Elásticos**
- Para que os dedos retornem à posição inicial quando os fios forem liberados, use elásticos no interior ou conectando na parte traseira das articulações.
Os elásticos devem estar esticados o suficiente para trazer os dedos de volta, mas sem prejudicar o movimento.
5. **Teste Inicial**
- Antes de conectar a alimentação, mova os fios manualmente para testar se os dedos respondem corretamente.
Ligue os servomotores e rode um teste simples para verificar se a tensão e o movimento estão adequados.
Se precisar de ajustes ou mais detalhes, só avisar! 