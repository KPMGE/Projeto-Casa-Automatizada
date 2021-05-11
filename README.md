# Projeto Casa Automatizada :house_with_garden: - PIC 2021

> Grupo: Kevin Carvalho de Jesus, Alvaro Davi Santos Alves, Bruno Silva

### Idéia geral :boom:

A idéia deste projeto é criar uma miniatura de casa automatizada, com um sistema de segurança, detecção de nível de luminosidade
para controle das luzes, alerta da possibilidade de chuva e um sistema automatizado de garagem.

### Sistema de segurança :hand:

O sistema de segurança da casa basear-se-á em um laser, que ficará sempre ativo emitindo um raio que será lido por um
sensor de luminosidade LDR, caso alguém tente entrar na casa inadvertidamente, o fornecimento de luz do laser para o LDR
será temporariamente cortado, deste modo é possível, quando tal evento ocorrer, disparar os alarmes da casa (Buzzers).

### Sistema de detecção de luz natural para economia de energia :bulb:

A energia é um bem devéras importante em nossos cotidianos, logo toda medida possível deve ser tomada com o fito de mitigar
seu consumo. Este sistema detecta o nível de luminosidade da casa, caso haja luz suficiente, as luzes são automaticamente
apagadas para que não se consuma mais energia.

### Sistema climático :umbrella:

Este sistema tem como objetivo detectar a umidade do ar, a fim de tentar ajudar o usuário emitindo um sinal caso haja uma grande possibilidade de chuva para que o mesmo feche todas as janelas da casa.

### Garagem automatizada :red_car:

Todos sabemos o quão inconveniente é, por vezes, chegar em casa extenuados ou em um dia de chuva e termos que abrir o portão
de nossas casas. Este sistema veio revolucionar isto, quando é detectado que o carro do dono da casa se aproxima, o portão automaticamente se abre, então o usuário coloca-o dentro da garagem, e por fim, a mesma se fecha. Não é um sonho? :grin:

### Componentes usados

#### Casa

- 6 LEDs (e resistores de 330 O)
- 2 LDRs (e resistores de 11,2k O)
- 1 Módulo Laser
- 1 Buzzer
- 1 Sensor de Temperatura e Umidade do Ar (DHT11)
- 1 Arduino
- 1 Protoboard

#### Garagem:

- 1 Botão
- 1 LED (e resistor de 330 O)
- 1 Sensor Ultrassônico (HC-SR04)
- 1 ServoMotor (DGServo 9g)
- 1 Arduino
- 1 Protoboard

### Bibliotecas criadas :books:

Quando um projeto se torna maior, com inúmeros componentes trabalhando juntos, utilizar um único arquivo para armazenar
todo o código usado pode se tornar extremamente dispendioso, com o objetivo de mitigar este problema, implementamos pra você
algumas bibliotecas que o ajudarão no processo de gerenciamento do projeto. Há bibliotecas para controle automatico da garagem,
do sitema de segurança e do sistema de economia de energia! Você pode encontrá-las na pasta `libs` deste repositório. Para usálas é
simplíssimo, basta mover a pasta com a lib dejesada para a o seu diretório `Aduino/libraries` e pronto! Basta importá-las como qualquer
outra biblioteca e começar a usar! :flushed:

### Esquemáticos :bookmark_tabs:

Caso queira replicar este projeto, você pode clonar este repositório, mas precisará também de informações sobre como deve ser 
feita a pinagem para cada componente da casa, abaixo você pode encontrá-los. Divirta-se :smile:

<br>

### Primeiro Arduino

Aqui, temos o esquemático para montar o primeiro arduino, este será responsável por gerenciar o sistema de garagem automatizada

![fist arduino](https://github.com/KPMGE/Projeto-Casa-Automatizada/blob/kevin-branch/schematics/garage-controller.png?raw=true)

<br>

### Segundo Arduino

Este arduino será responsável pelo gerenciamento dos demais sistemas da casa, ou seja, os sistemas de economia de energia,
segurança e clima.

![second arduino](https://github.com/KPMGE/Projeto-Casa-Automatizada/blob/kevin-branch/schematics/second-arduino.png?raw=true)

> OBS: Este esquemático está parcialmente incompleto, você deve ligar ainda a ele o sensor de umidade e temperatura, que se encontra abaixo

### Sensor de Temperatura e Umidade

![umidity-temperature-sensor](https://github.com/KPMGE/Projeto-Casa-Automatizada/blob/kevin-branch/tests/img/SensorUmidade_test.jpg?raw=true)
