#define LED 13
#define BOTAO A0

int estado = 1;
int tempoAtual = 0;
int tempoInicial = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  tempoAtual = millis();
  Serial.println(estado);

  // estado 1
  if (estado == 1 && tempoAtual - tempoInicial >= 500) {
      digitalWrite(LED, HIGH);
      estado = 2;
      delay(50);
    }
  }

  // estado 1
  if (estado == 2 && tempoAtual - tempoInicial >= 300) {
      digitalWrite(LED, LOW);
      estado = 2;
      delay(50);
    }
  }

   // estado 1
  if (estado == 3 && tempoAtual - tempoInicial >= 500) {
      digitalWrite(LED, HIGH);
      estado = 4;
      delay(50);
    }
  }

  // estado 1
  if (estado == 2 && tempoAtual - tempoInicial >= 100) {
      digitalWrite(LED, LOW);
      estado = 2;
      delay(50);
    }
  }
}
