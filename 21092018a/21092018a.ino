#define LED 9
#define LDR A5

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT);
}

void loop() {
  int leitura = map(analogRead(LDR), 870, 1023, 0, 255);
  int intensidadeLED = leitura < 0 ? 0 : leitura > 255 ? 255 : leitura;
  analogWrite(LED, intensidadeLED);
}
