Controle de Servo Motor com Raspberry Pi Pico

Este projeto demonstra o controle de um servo motor utilizando o Raspberry Pi Pico e o PWM (Pulse Width Modulation).

Descrição

O código configura um servo motor conectado ao pino 22 do Raspberry Pi Pico para oscilar suavemente entre 0° e 180°.

Hardware Necessário

Raspberry Pi Pico

Servo motor (exemplo: SG90, MG995)

Fonte de alimentação adequada

Fios de conexão

Conexão do Servo Motor

Vermelho (VCC) -> 5V do Raspberry Pi Pico (ou fonte externa)

Preto/Marrom (GND) -> GND do Raspberry Pi Pico

Laranja/Branco (Sinal) -> GPIO 22 do Raspberry Pi Pico

Compilação e Upload

Para compilar e carregar o código no Raspberry Pi Pico:

Instale o SDK do Raspberry Pi Pico e o compilador arm-none-eabi-gcc.

Configure o CMakeLists.txt para compilar o projeto.

Compile o código com cmake e make.

Conecte o Raspberry Pi Pico no modo BOOTSEL e copie o arquivo .uf2 gerado.

link do video no youtube:https://youtu.be/bCMaF0lTgXM
