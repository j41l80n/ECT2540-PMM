const int LM35 = A0; // Define o pino de leitura
float temperatura; // Variável que armazenará a
//temperatura medida

void setup() {
  // inicializa a comunicação serial
  Serial.begin(9600);
}

void loop() {
  temperatura = (float(analogRead(LM35)) * 5 / (1023)) / 0.01;
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  delay(1000);
}
