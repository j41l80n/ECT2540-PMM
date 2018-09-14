#define PIEZO 10
int ligereza = 500;

char notas[] =  "ccggaagffeeddc ";
int batida[] = {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4};

void setup() {
  Serial.begin(9600);
  pinMode(A1, INPUT_PULLUP);
}

void loop() {
  toca();
}

void toca() {
  for (int i = 0; i < sizeof(notas) - 1; i++)
  {
    Serial.println(i);
    if (notas[i] == ' ') {
      tone(PIEZO, 0, batida[i] * ligereza);
    }
    else {
      tone(PIEZO, frequencia(notas[i]), batida[i] * ligereza);
    }
    delay( batida[i] * ligereza);
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
