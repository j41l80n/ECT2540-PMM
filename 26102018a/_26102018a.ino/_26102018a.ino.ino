#include <TimerOne.h>

int dado = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  // initialize timer1, and set a 1/2 second period
  Timer1.initialize(500000);
  // attaches callback() as a timer overflow interrupt
  Timer1.attachInterrupt(callback);
}

void callback()
{
  // ^ serve como ou exclusivo
  digitalWrite(13, digitalRead(13) ^ 1);
}

void loop()
{
  if (Serial.available() >  0) {
    dado = Serial.parseInt();
    Serial.print("dado recebido: ");
    Serial.println(dado);

    if (dado == 0) {
      Timer1.detachInterrupt();
      digitalWrite(13, LOW);
    }
    else {
      Timer1.setPeriod(dado * 100000);
      Timer1.attachInterrupt(callback);
    }
  }
}
