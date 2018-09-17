#define LED 11

int quantidade = 0;
int estado = 1;
int incomingByte = 0;
int valorPotencimoetro = 0;
int valorMinimo = 0;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  valorPotencimoetro =  analogRead(A1);

  if (valorPotencimoetro < valorMinimo) {
    valorPotencimoetro = 0;
  }
  else
  {
    valorPotencimoetro = map(valorPotencimoetro, valorMinimo, 1023, 0, 255);
  }

  if (valorPotencimoetro < 0) {
    valorPotencimoetro = 0;
  }

  if (valorPotencimoetro >= 0) {
    analogWrite(LED, valorPotencimoetro );
  }

  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    quantidade = 0;
    if (incomingByte == 114 || incomingByte == 82)
    {
      Serial.println("contador zerado");
      digitalWrite(13, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
    }
  }

  // estado 1
  if (estado == 1 && !digitalRead(A0)) {
    valorMinimo = analogRead(A1);
    Serial.println(valorMinimo);
    delay(50);
    estado = 2;
  }

  // estado 2
  if (estado == 2 && digitalRead(A0)) {
    estado = 1;
    delay(50);
  }
}
