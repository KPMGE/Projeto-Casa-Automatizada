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

###  Sistema climático :umbrella:
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
- 1 Botão
- 1 Sensor de Temperatura e Umidade do Ar (DHT11)
- 1 Arduino
- 1 Protoboard

#### Garagem:
- 1 LED (e resistor de 330 O)
- 1 Sensor Ultrassônico (HC-SR04)
- 1 ServoMotor (DGServo 9g)
- 1 Arduino
- 1 Protoboard


### Esquemáticos
Caso queira replicar este projeto, você pode clonar este repositório, mas precisará também de alguns esquemáticos, que lhe informarão como deve ser feita a pinagem para cada componente da casa, abaixo você pode encontrá-los. Divirta-se :smile:

<br>

### LDR
![LDR Sensor](https://github.com/KPMGE/Projeto-Casa-Automatizada/blob/kevin-branch/tests/img/LRD_test.jpeg?raw=true)


### Sensor Ultrasonico
![Ultrasonic Sensor](https://github.com/KPMGE/Projeto-Casa-Automatizada/blob/kevin-branch/tests/img/SensorUltrassonico_test.jpeg?raw=true)

### Sensor de Umidade
![Sensor umidade](https://github.com/KPMGE/Projeto-Casa-Automatizada/blob/kevin-branch/tests/img/SensorUmidade_test.jpg?raw=true)


### Servomotor
![Servomotor](https://github.com/KPMGE/Projeto-Casa-Automatizada/blob/kevin-branch/tests/img/ServoMotor_test.jpeg?raw=true)


### Sistema de Segurança
![Security System](https://github.com/KPMGE/Projeto-Casa-Automatizada/blob/kevin-branch/tests/img/Light-Sensor.png?raw=true)


### Garagem automatizada
![garage](https://github.com/KPMGE/Projeto-Casa-Automatizada/blob/kevin-branch/tests/img/garage-controller.png?raw=true)