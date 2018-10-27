#include <EEPROM.h>
#include <Servo.h>
#include <TimerOne.h>

#define PINO_SERVO 6
#define BOTAO 2
Servo servo;

int tempoInicial = 0;
int tempoAtual = 0;
volatile int posicaoServo = 0;
int endereco = 0;

void setup() {
  Serial.begin(9600);
  servo.attach(PINO_SERVO);
  servo.write(0);
  pinMode(BOTAO, INPUT_PULLUP);

  //  Timer1.initialize(500000);
  //  Timer1.attachInterrupt(callbackTimer);
  attachInterrupt(digitalPinToInterrupt(BOTAO), movimentaServo, FALLING);
  //  attachInterrupt(digitalPinToInterrupt(BOTAO2), PontosJogador2, RISING);
  Serial.println(digitalRead(BOTAO));
}

void movimentaServo() {
  Serial.println(digitalRead(BOTAO));
  tempoAtual = millis();
  posicaoServo += 30;
  if (tempoAtual - tempoInicial >= 500) {
    servo.write(posicaoServo);
    tempoInicial = tempoAtual;
  }
}
void loop() {

}

