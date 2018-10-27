#include <TimerOne.h>

#define BOTAO1 3
#define BOTAO2 2

volatile int pontosJogador1 = 0;
volatile int pontosJogador2 = 0;
int tempoInicial = 0;
int tempoAtual = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(BOTAO1, INPUT_PULLUP);
  pinMode(BOTAO2, INPUT_PULLUP);

  Timer1.initialize(500000);
  Timer1.attachInterrupt(callbackTimer);

  attachInterrupt(digitalPinToInterrupt(BOTAO1), PontosJogador1, RISING);
  attachInterrupt(digitalPinToInterrupt(BOTAO2), PontosJogador2, RISING);
}

void callbackTimer()
{
  Serial.print("Leonardo ");
  Serial.print(pontosJogador1);
  Serial.print(" X ");
  Serial.print(pontosJogador2);
  Serial.println(" Jailson ");
}

void PontosJogador1()
{
  tempoAtual = millis();
  if (tempoAtual - tempoInicial >= 1000) {
    pontosJogador1++;
    tempoInicial = tempoAtual;
  }
}

void PontosJogador2()
{
  tempoAtual = millis();
  if (tempoAtual - tempoInicial >= 1000) {
    pontosJogador2++;
    tempoInicial = tempoAtual;
  }
}

void loop()
{

}
