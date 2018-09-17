#define LED 13
#define BOTAO A0
#define PONTO 100
#define PAUSA 200
#define TRACO 300
#define ESPERA

int estado = 1;
int tempoAtual = 0;
int tempoInicial = 0;
int incomingByte = 0;
int vetor[100];

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    
    if (incomingByte == 65 || incomingByte == 97)
    {
      morceA();
    }
    if (incomingByte == 69 || incomingByte == 101)
    {
      morceE();
    }
    if (incomingByte == 73 || incomingByte == 105)
    {
      morceI();
    }
    if (incomingByte == 79 || incomingByte == 111)
    {
      morceO();
    }
    if (incomingByte == 85 || incomingByte == 117)
    {
      morceU();
    }
    delay(500);
  }
}

void morceA() {
  sinal(PONTO);
  sinal(TRACO);
}

void morceE() {
  sinal(PONTO);
}

void morceI() {
  sinal(PONTO);
  sinal(PONTO);
}

void morceO() {
  sinal(TRACO);
  sinal(TRACO);
  sinal(TRACO);
}

void morceU() {
  sinal(PONTO);
  sinal(PONTO);
  sinal(TRACO);
}

void sinal(int tempo) {
  estado = 1;
  while (estado <= 2) {
    tempoAtual = millis();
    // estado 1
    if (estado == 1 && tempoAtual - tempoInicial >= PAUSA) {
      digitalWrite(LED, HIGH);
      tempoInicial = millis();
      estado++;
      delay(50);
    }
    // estado 2
    if (estado == 2 && tempoAtual - tempoInicial >= tempo) {
      tempoInicial = millis();
      digitalWrite(LED, LOW);
      estado++;
      delay(50);
    }
  }
}
