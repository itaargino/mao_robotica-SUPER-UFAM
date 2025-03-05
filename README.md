# Protótipo Biomédico: Mão Robótica - Usando Arduino/

> Este projeto foi resultado de um estudo graduado produzido a partir do Projeto SUPER realizado na UFAM durante 2024-2025.  

O projeto consiste em uma mão robótica controlada por meio de uma luva equipada com sensores flexíveis e um microcontrolador. Os movimentos dos dedos da luva são capturados e usados como entrada para acionamento dos servomotores para replicar os gestos na mão robótica.

# Estrutura do Repositório

```
/mão-robotica-esp32
│-- /src              # Código-fonte do projeto
│-- /docs             # Documentação e relatórios
│-- /images           # Imagens do protótipo e esquemas
│-- README.md         # Este arquivo
│-- LICENSE           # Licença do projeto
```

# Usar Arduino ou ESP32? 

Nosso projeto foi um estudo gradual, iniciamos usando Arduino e migramos para ESP32. Apesar de apresentarem funcionalidades semelhantes, a ESP32 se torna mais vantajosa. No entanto, aqui apresentamos o projeto com os dois microcontroladores.
- [Como rodar no Arduino](docs/readme_ino.md) (Sem suporte Wi-fi)
- [Como rodar na ESP32](docs/readme_esp.md)

# Software

- Arduino IDE (para programação do Arduino/ESP32)
- Fritzing (para simulação do projeto)

# Simulação do sistema

Use como base para o esquema do projeto o [modelo de simulação](simulacao.md)

# Próximos Passos

- Substituir uso de sensores flexíveis por biossensores avançados.
- Implementação de banco de dados com coleta de dados automática para melhora de resposta

# Licença

Este projeto está licenciado sob a MIT License.