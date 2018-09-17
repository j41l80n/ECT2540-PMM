#define PIEZO 10
#define BOTAO A1
#define POTENCIOMETRO A0

int estado;
int frequencias [] = {261, 294, 329, 349, 392, 440, 493, 523};

void setup() {
  Serial.begin(9600);
  pinMode(BOTAO, INPUT_PULLUP);
  estado = 1;
}

void loop() {
  toca();
}

void toca() {
  Serial.println(digitalRead(BOTAO));

  if (!digitalRead(A1)) {
    int nota = map(analogRead(POTENCIOMETRO), 0, 1023, 0, 7);
    tone(PIEZO, frequencias[nota]);
    delay(5);
    estado = 2;
  }

  if (digitalRead(A1)) {
    estado = 1;
    noTone(PIEZO);
    delay(5);
  }
}

int frequencia(char nota) {
  switch (nota) {
    case 'c':
      return 261;
    case 'd':
      return 294;
    case 'e':
      return 329;
    case 'f':
      return 349;
    case 'g':
      return 392;
    case 'a':
      return 440;
    case 'b':
      return 493;
  }
}
