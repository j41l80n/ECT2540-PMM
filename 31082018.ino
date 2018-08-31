#define LED 13
#define BOTAO A0

int quantidade = 0;
int estado = 1;
int incomingByte = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BOTAO, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  
}

void loop() {
  // estado 1
  if (estado == 1 && !digitalRead(A0)) {
    digitalWrite(13, HIGH);
    delay(3000);
    digitalWrite(13, LOW);
    estado = 2;
  }

  // estado 2
  if (estado == 2 && digitalRead(A0)) {
    estado = 1;
    delay(50);
  }
}
