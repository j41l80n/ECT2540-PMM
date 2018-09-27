#include<Servo.h>
#define PIN_SERVO A4
#define LDR A5

Servo servo;

void setup() {
  Serial.begin(9600);
  pinMode(LDR, INPUT);
  servo.attach(PIN_SERVO);
  servo.write(0);
}

int leitura = 1023;
int angulo = 0;
bool crescente = true;

void loop() {
  crescente = angulo == 180 ? false : angulo == 0 ? true : crescente;
  leitura = analogRead(LDR);
  if (crescente) {
    angulo += 5;
    servo.write(angulo);
  } else {
    angulo -= 5;
    servo.write(angulo);
  }
  delay(50);
  if (analogRead(LDR) > leitura) {
    crescente = !crescente;
  }
}
