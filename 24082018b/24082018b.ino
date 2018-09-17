int incomingByte = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    if (incomingByte == 97)
    {
      Serial.println("estou acesso");
      digitalWrite(13, HIGH);
    }
    else if (incomingByte == 65)
    {
      Serial.println("estou apagado");
      digitalWrite(13, LOW);
    }
  }
}
