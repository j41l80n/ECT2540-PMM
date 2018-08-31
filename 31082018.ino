#define LED 13
#define BOTAO A0

int estado = 1;
int tempoAtual = 0;
int tempoInicial = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BOTAO, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  tempoAtual = millis();
  
  // estado 1
  if (estado == 1 && !digitalRead(A0)) {
    digitalWrite(LED, HIGH);
    estado = 2;
    tempoInicial = millis();
    delay(50);
  }

  if(tempoAtual-tempoInicial >= 3000){
    digitalWrite(LED, LOW);
    estado = 1;
  }
 
  // estado 2
  if (estado == 2 && digitalRead(BOTAO)) {
    estado = 3;
    delay(50);
  }
  
  // estado 3
  if (estado == 3 && !digitalRead(BOTAO) && digitalRead(LED)) {
    digitalWrite(13, LOW);
    estado = 4;
    delay(50);
  }

  // estado 4
  if (estado == 4 && digitalRead(A0)) {
    estado = 1;
    delay(50);
  }
}
