int quantidade = 0;
int estado = 1;
int incomingByte = 0;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
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
    quantidade++;
    Serial.println(quantidade);
    delay(50);
    estado = 2;
  }

  // estado 2
  if (estado == 2 && digitalRead(A0)) {
    estado = 1;
    delay(50);
  }


}
