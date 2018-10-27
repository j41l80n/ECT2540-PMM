#include <TimerOne.h> 

void setup()
{
  pinMode(10, OUTPUT);
  Timer1.initialize(500000); // initialize timer1, and set a 1/2 second period
  Timer1.attachInterrupt(callback); // attaches callback() as a timer overflow interrupt
}

void callback()
{
  digitalWrite(10, digitalRead(10) ^ 1); //”^”: ou exclusivo (inverte o valor da porta)
}

void loop()
{
  // your program here...
}

