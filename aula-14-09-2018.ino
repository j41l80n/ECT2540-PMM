#define POTENCIOMETRO A0
#define LED 13

int periodo = 10;
float dc = 0.0;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  dc = (float) map(analogRead(POTENCIOMETRO), 0, 1023, 0, 100) / 100.0;
  Serial.println(dc);
  pwm(dc);
}

void pwm(float DC) {
  digitalWrite(LED, HIGH);
  delay(DC * periodo);
  digitalWrite(LED, LOW);
  delay((1 - DC) * periodo);
}
