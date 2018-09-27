#define SERVO 13

void setup() {
  Serial.begin(9600);
  pinMode(SERVO, OUTPUT);
}

bool crescente = true;
float ms = 500;

void loop() {
  pulso();
  crescente = ms > 2500 ? false : ms < 500 ? true : crescente;
  ms = crescente ? ms + 1 : ms - 1;
  Serial.println(ms);
}

void pulso() {
  digitalWrite(SERVO, HIGH);
  delayMicroseconds(ms);
  digitalWrite(SERVO, LOW);
  delayMicroseconds(20000);
}
