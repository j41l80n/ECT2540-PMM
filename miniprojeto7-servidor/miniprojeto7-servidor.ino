#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xAE, 0xAE, 0xCE, 0xDF, 0xFE, 0xED }; //physical mac address
EthernetServer server(80); //server port
String readString;
#define ledPin = 2;
#define botao = 9;
#define potenciometro = A0;

int flag = 0;
int valpot = 0;
int valbot = 0;

void setup() {
  pinMode(ledPin, OUTPUT); //pin selected to control
  pinMode(botao, INPUT_PULLUP);
  pinMode(potenciometro, INPUT);

  Serial.begin(9600);

  Ethernet.begin(mac);

  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }

  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.print("Valor do cliente: ");
        Serial.println(c);
        //read char by char HTTP request
        if (readString.length() < 100) {
          //store characters to string
          readString += c;
        }
        //if HTTP request has ended– 0x0D is Carriage Return \n ASCII
        if (c == 0x0D) {

          delay(10);

          if (!digitalRead(botao) > 0 && valbot == 0) {
            valbot = 1;

            delay(500);
          } if (!digitalRead(botao) > 0 && valbot == 1) {
            valbot = 0;
            delay(500);
          }

          if (readString.indexOf("val=pot") > -1) //checks for LEDON
          {
            valpot = analogRead(A0);
            valpot = valpot / 4;
            Serial.println("Enviando valor potenciometro...");
            client.print(valpot);
            client.stop();
          readString = "";
          }
          else {
            if (readString.indexOf("val=bot") > -1)
            {

              Serial.println("Enviando valor do botao...");
              client.print(valbot);
             client.stop();
          //clearing string for next read
          readString = "";
            }
          }

        }
      }
      Serial.print(" Valor Potenciometro: ");
      Serial.print(valpot);
      Serial.print("Valor Botao: ");
      Serial.println(valbot);
    }
  }
}
