
int estado;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, INPUT_PULLUP);
  pinMode(A0, INPUT_PULLUP);
  estado = 1;
}

void loop() {
  // estado 1
  if (estado == 1 && !digitalRead(A0)) {
    digitalWrite(13, HIGH);
    delay(10);
    estado = 2;
  }

  // estado 2
  if (estado == 2 && digitalRead(A0)) {
    estado = 3;
    delay(10);
  }

  // estado 3
  if (estado == 3 && !digitalRead(A0)) {
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    delay(10);
    estado = 4;
  }

  // estado 4
  if (estado == 4 && digitalRead(A0)) {
    estado = 5;
    delay(10);
  }

  // estado 5
  if (estado == 5 && !digitalRead(A0)) {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    delay(10);
    estado = 6;
  }

  // estado 6
  if (estado == 6 && digitalRead(A0)) {
    delay(10);
    estado = 7;
  }

  // estado 7
  if (estado == 7 && !digitalRead(A0)) {
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    delay(10);
    estado = 8;
  }

  // estado 8
  if (estado == 8 && digitalRead(A0)) {
    delay(10);
    estado = 9;
  }

  // estado 9
  if (estado == 9 && !digitalRead(A0)) {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    delay(10);
    estado = 10;
  }

  // estado 10
  if (estado == 10 && digitalRead(A0)) {
    delay(10);
    estado = 1;
  }

  // reseta estado
  if (!digitalRead(11)) {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    estado = 1;
  }
}
