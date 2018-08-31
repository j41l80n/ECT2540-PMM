#define LED 13
#define BOTAO A0

int estado = 1;
int tempoAtual = 0;
int tempoInicial = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BOTAO, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  tempoAtual = millis();
  Serial.println(estado);

  // estado 1
  if (estado == 1 && !digitalRead(A0)) {
    digitalWrite(LED, HIGH);
    tempoInicial = millis();
    estado = 2;
    delay(50);
  }

  // estado 2
  if (estado == 2) {
    if (digitalRead(BOTAO)) {
      estado = 3;
      delay(50);
    }
    if (tempoAtual - tempoInicial >= 3000) {
      digitalWrite(LED, LOW);
      estado = 4;
      delay(50);
    }
  }

  // estado 3
  if (estado == 3) {
    if (!digitalRead(BOTAO)) {
      digitalWrite(LED, LOW);
      estado = 4;
      delay(50);
    }
    if (tempoAtual - tempoInicial >= 3000) {
      digitalWrite(LED, LOW);
      estado = 1;
      delay(50);
    }
  }

  // estado 4
  if (estado == 4 && digitalRead(A0)) {
    estado = 1;
    delay(50);
  }
}
