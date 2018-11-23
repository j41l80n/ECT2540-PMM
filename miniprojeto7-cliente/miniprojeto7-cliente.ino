#include <SPI.h>
#include <Ethernet.h>

#define LED 6
int potenc = 1;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xAD };
// endereço do servidor
char server[] = "10.6.9.81";

EthernetClient client;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Initialize Ethernet with DHCP:");
  Ethernet.begin(mac);
  delay(1000);
  Serial.print("client is at ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  bot();
  delay(1000);
//  client.println("Connection: close");
//  client.stop();
  potenciometro();
  delay(1000);
}

void potenciometro() {
  int len = client.available();
  //Serial.println(len);
  if (len > 0) {
    Serial.print("recebendo ");
    Serial.println(len);
    byte buffer[80];
    if (len > 80) len = 80;
    client.read(buffer, len);
    Serial.write(buffer, len); // show in the serial monitor (slows some boards)
    Serial.println();
    String s = String((char *)buffer);
    int v = s.toInt();
    potenc = v;
    analogWrite(LED, v);
    Serial.println(v);
  }

  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    client.stop();
    Serial.println("disconected");
    delay(5000);
    Serial.print("connecting to ");
    Serial.print(server);
    Serial.println("...");

    // if you get a connection, report back via serial:
    if (client.connect(server, 80)) {
      Serial.print("connected to ");
      Serial.println(client.remoteIP());
      // Make a HTTP request:
      client.println("GET /?val=pot");
      client.println("Host: 10.6.9.81");
      client.println("Connection: close");
      client.println();
    } else {
      Serial.println("connection failed");
    }
  }
}

void bot() {
  int len = client.available();
  Serial.print("len ");
  Serial.println(len);
  if (len > 0) {
    Serial.print("recebendo ");
    Serial.println(len);
    byte buffer[80];
    if (len > 80) len = 80;
    client.read(buffer, len);
    Serial.write(buffer, len); // show in the serial monitor (slows some boards)
    Serial.println();
    String s = String((char *)buffer);
    int v = s.toInt();
    Serial.print("botao: ");
    Serial.println(v);
    if (v == 1)
    {
      analogWrite(LED, potenciometro);
    }
    else
    {
      analogWrite(LED, LOW);
    }
  }

  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    client.stop();
    Serial.println("disconected");
    delay(500);
    Serial.print("connecting to ");
    Serial.print(server);
    Serial.println("...");

    // if you get a connection, report back via serial:
    if (client.connect(server, 80)) {
      Serial.print("connected to ");
      Serial.println(client.remoteIP());
      // Make a HTTP request:
      client.println("GET /?val=bot");
      client.println("Host: 10.6.9.81");
      client.println("Connection: close");
      client.println();
    } else {
      Serial.println("connection failed");
    }
  }
}
