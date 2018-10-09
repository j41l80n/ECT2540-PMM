#include <SPI.h>
#include <Ethernet.h>

#define LED 9
#define POTENCIOMETRO A0
#define BOTAO A1

byte mac[] = { 0x1E, 0xAF, 0xBE, 0x2F, 0xFF, 0xED };
int estado = 1;
bool ligado = true;
int intensidadeLED = 255;

EthernetServer server(80);
String readString;
void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // espera pela serial
  }
  Serial.print("teste ");
  Ethernet.begin(mac);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
  pinMode(BOTAO, INPUT_PULLUP);
}


void loop() {
  int leitura = map(analogRead(POTENCIOMETRO), 0, 1023, 0, 255);
  //int intensidadeLED = leitura < 0 ? 0 : leitura > 255 ? 255 : leitura;

  if (ligado) {
    analogWrite(LED, intensidadeLED);
  }
  else
  {
    digitalWrite(LED, LOW);
  }

  if (estado == 1 && !digitalRead(BOTAO)) {
    ligado = !ligado;
    estado = 2;
    delay(10);
  }

  if (estado == 2 && digitalRead(BOTAO)) {
    estado = 1;
    delay(10);
  }

  EthernetClient client = server.available();
  if (client) {
    Serial.println("cliente conectado");
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        //read char by char HTTP request
        if (readString.length() < 100) {
          //store characters to string
          readString += c;
        }
        //if HTTP request has ended– 0x0D is CarriageReturn \n ASCII
        if (c == 0x0D) {
          client.println("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n");
          client.println("<HTML><HEAD><TITLE>ARDUINO ETHERNET SHIELD</TITLE></HEAD>");
          client.println("<BODY><hr><hr><br>");
          client.println("<H1 style=\"color:green;\">ARDUINO ETHERNET SHIELD<br> Liga/Desliga LED</H1><hr><br>");
          client.println("<H2><a href=\"?led=LEDON\"\">Liga</a><br></H2>");
          client.println("<H2><a href=\"?led=LEDOFF\"\">Desliga</a><br></H2>");
          client.println("</BODY></HTML>");
          delay(10);
          //stopping client
          client.stop();
          // control arduino pin
          if (readString.indexOf("led=LEDON") > -1)
          {
            Serial.println("Acendendo LED...");
            ligado = true;
          }
          else {
            if (readString.indexOf("led=LEDOFF") > -1)
            {
              Serial.println("Apagando LED...");
              ligado = false;
            }
          }
          readString = "";
        }
      }
    }
  }
}
