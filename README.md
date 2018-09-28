# ECT2540 - Projetos com Micocontroladores e Minicomputadores

## Repositório para as listas da disciplina de PMM
## Miniprojeto 1
 Faça um projeto que controla o comportamento de um par de LEDs – um verde e outro vermelho - inicialmente apagados, de forma que ao se pressionar o botão uma vez o LED verde acende. Ao se pressionar uma segunda vez o LED verde apaga e o vermelho acende. Uma terceira pressionada no botão apaga novamente os dois LEDs. Ao se pressionar uma quarta vez os dois LEDs acendem, e finalmente ao se pressionar mais uma vez os dois apagam e voltam ao comportamente inicial (proxima pressionada irá acender o verde e assim por diante).

<img src="imagens/miniprojeto1.png" width="350" height="350">

## Miniprojeto 2
Apresentar	na	serial	quantas	vezes	o	botão	foi	pressionado	e,	quando	receber	a	letra	"r"	ou	"R",	deve	acender	um	LED	por	1	segundo	e	iniciar	a	contagem	do	zero.

<img src="imagens/miniprojeto2.png" width="350" height="350">

## Miniprojeto 3 
Faça um projeto que altere a intensidade de um LED, usando pwm, baseado em valores enviados pelo potenciômetro, lidos utilizando uma porta analógica. Inclua na montagem um botão “offset” que, ao ser pressionado, torna a tensão lida no momento equivalente a uma intensidade de LED igual a zero (apagado). Apresente o valor de “offset” na serial quando o botão for pressionado.

<img src="imagens/miniprojeto3.png" width="350" height="350">

## Miniprojeto 4
O	Código	Morse	é	um	sistema	binário	de	representação de	números,	letras	e	sinais	gráficos,	utilizando-se	de	sons	curtos	e longos,	além	de	pontos	e	traços	para	transmitir	mensagens.	Nesses	exercícios	iremos	utilizar	o	Código Morse	para	transmitir	dados	acendendo	e	apagando	o	LED.	No	site	abaixo	podemos	ver	todos	os	símbolos	da tabela.	

<img src="imagens/miniprojeto4.png" width="350" height="350">

## Miniprojeto 5
O	Usar o Piezo com WPM para fazer música. Seu programa deve ter um vetor com as notas da música, incluindo pausas, e outro vetor do mesmo tamanho com a duração de cada nota (vetor de inteiros, onde 1 é a duração de um tempo de música, 2 o dobro, e assim por diante). Utilize comandos tone() e dalay(). Lembre-se de dar uma pausa pequena entre duas notas quaisquer.	

<img src="imagens/miniprojeto5.png" width="350" height="350">

### Miniprojeto 5 - Bônus
Faça um instrumento composto por um botão, um potenciômetro e o Piezo. Ao se manter o botão pressionado, o Piezo deve emitir a frequencia definida pelo potenciometro. utilize a função map() para mapear uma ou duas oitavas.	

### Miniprojeto 6
Faça um "girasol" de uma dimensão utilizando um servomotor e um sensor de luz acoplado a este. O servo deve girar de forma que o sensor de luz aponte para o local com maior luminosidade. Dica: você deve "amostrar" duas luminosidades em ângulos diferentes, girar para a posição da maior, e repetir o processo. Faça melhorias no algoritmo de controle para tornar o movimento mais suave.

<img src="imagens/miniprojeto6.png" width="350" height="350">

### Miniprojeto 7
* Potenciometro e botão em um Arduino controlando LED em outro Arduino usando arquitetura cliente-servidor. O potenciometro controla o brilho, e o botão, ao ser pressionado, desliga o LED.
* Juntar de dois em dois grupos. Um será o Arduino com potenciometro e o outro o com o LED
* Cada grupo deverá implementar tanto o papel de servidor como o de cliente, ou seja, o Arduino com potenciometro será inicialmente servidor e em um Segundo momento cliente
* Qual fez mais sentido: Arduino com potenciometro como servidor ou como cliente? maior, e repetir o processo. Faça melhorias no algoritmo de controle para tornar o movimento mais suave.

<img src="imagens/miniprojeto6.png" width="350" height="350">
