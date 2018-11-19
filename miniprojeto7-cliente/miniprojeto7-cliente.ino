#include <SPI.h>
#include <Ethernet.h>

#define LED 6

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xAD };
// endereço do servidor
char server[] = "10.6.9.81";

EthernetClient client;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // espera pela conexao com porta serial
  }
  Serial.println("iniciando com Ethernet modo DHCP:");
  Ethernet.begin(mac);
  Serial.print("cliente com endereco: ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  int len = client.available();
  //Serial.println(len);
  if (len > 0) {
    Serial.print("recebendo: ");
    Serial.println(len);
    analogWrite(LED, len);
    byte buffer[80];
    if (len > 80) len = 80;
    client.read(buffer, len);
    // mostra dados recebidos na serial
    Serial.write(buffer, len);
    Serial.println();
    String s = String((char *)buffer);
    int v = s.toInt();
    Serial.println(v);
  }

  // se o servidor desconectar
  if (!client.connected()) {
    client.stop();
    Serial.println("disconected");
    delay(5000);
    Serial.print("connecting to ");
    Serial.print(server);
    Serial.println("...");
    
    if (client.connect(server, 80)) {
      Serial.print("connected to ");
      Serial.println(client.remoteIP());
      // requisicao HTTP
      client.println("GET /?val=pot");
      client.println("Host: 10.6.9.81");
      client.println("Connection: close");
      client.println();
    } else {
      Serial.println("connection failed");
    }
  }
}
