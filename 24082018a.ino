int quantidade;
int estado;

void setup() {
  Serial.begin(9600);
  quantidade = 0;
  pinMode(A0, INPUT_PULLUP);
  estado = 1;
}

void loop() {
  // estado 1
  if (estado == 1 && !digitalRead(A0)) {
    quantidade++;
    Serial.println(quantidade);
    delay(10);
    estado = 2;
  }

  // estado 2
  if (estado == 2 && digitalRead(A0)) {
    estado = 1;
    delay(10);
  }
}
