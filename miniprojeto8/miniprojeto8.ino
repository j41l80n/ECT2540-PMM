int velocidade = 0;
int valor_lido = 0;
int estado = 0;

#define ENABLE 11
#define INPT1 6
#define INPT2 10
#define POTENCIOMETRO A2
#define BOTAO A0

void setup() {
  pinMode(POTENCIOMETRO, INPUT);
  pinMode(BOTAO, INPUT_PULLUP);
  pinMode(INPT1, OUTPUT);
  pinMode(INPT2, OUTPUT);
  pinMode(ENABLE, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  velocidade = map(analogRead(POTENCIOMETRO), 0, 1023, 0, 255);
  analogWrite(ENABLE, velocidade);
  Serial.println(velocidade);

  if (estado == 0) {
    digitalWrite(ENABLE, LOW);
    digitalWrite(INPT1, LOW);
    digitalWrite(INPT2, LOW);
    estado = 1;
    Serial.println("passo 0");
  }

  if (estado == 1) {
    if (!digitalRead(BOTAO)) {
      digitalWrite(ENABLE, HIGH);
      digitalWrite(INPT1, LOW);
      analogWrite(INPT2, velocidade);
      delay(500);
      Serial.println("passo 1");
      estado = 2;
    }
  }

  if (estado == 2) {
    if (digitalRead(BOTAO)) {
      delay(500);
      Serial.println("passo 2");
      estado = 3;
    }
  }

  if (estado == 3) {
    if (!digitalRead(BOTAO)) {
      digitalWrite(ENABLE, HIGH);
      analogWrite(INPT1, velocidade);
      digitalWrite(INPT2 , LOW);
      delay(500);
      Serial.println("passo 3");
      estado = 4;
    }
  }

  if (estado == 4) {
    if (digitalRead(BOTAO)) {
      delay(500);
      Serial.println("passo 4");
      estado = 1;
    }
  }
}
