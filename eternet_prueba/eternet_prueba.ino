

#include <SPI.h>
#include <Ethernet.h>


byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

IPAddress ip(192, 168, 1, 177);
IPAddress myDns(192, 168, 0, 1);

// initialize the library instance:
EthernetClient client;

char server[] = "192.168.1.124";  // also change the Host line in httpRequest()
//IPAddress server(64,131,82,241);

unsigned long lastConnectionTime = 0;           // last time you connected to the server, in milliseconds
const unsigned long postingInterval = 10 * 1000; // delay between updates, in milliseconds

void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // start the Ethernet connection:
  Serial.println("Inicializando Ethernet con DHCP:");
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Fallo la conexión configurando DHCP");

  } else {
    Serial.print("  DHCP asignado IP ");
    Serial.println(Ethernet.localIP());
  }
  // segundos para la inicializacion:
  delay(1000);
  httpRequest();
}


int humedad_suelo_nodoA = 45;
int humedad_relativa_A = 98;
int temperatura_A = 25;

int humedad_suelo_nodoB = 100;
char c;
void loop() {
  // if there's incoming data from the net connection.
  // send it out the serial port.  This is for debugging
  // purposes only:



  if (client.available()) {
    if (client.available()) {
      c = client.read(); // Leemos los caracteres de uno en uno
      Serial.print(c);
    }
  }


  if (millis() - lastConnectionTime > postingInterval) {

    httpRequest();
  }
  if (c == '1') {
    Serial.println("Activar Manual");
  }

  if (c == '2') {
    Serial.println("Desactivar Manual");

  }



}

// this method makes a HTTP connection to the server:
void httpRequest() {
  // close any connection before send a new request.
  // This will free the socket on the WiFi shield
  client.stop();

  // if there's a successful connection:
  if (client.connect(server, 4000)) {
    Serial.println("connecting...");
    // send the HTTP GET request:
    String cadena = "12";


    client.print("GET /ActivacionRiego/conectar/?");
    client.print("humedad_suelo_nodoA=");
    client.print(humedad_suelo_nodoA);
    client.print("&humedad_suelo_nodoB=");
    client.print(humedad_suelo_nodoB);
    client.print("&humedad_relativa_A=");
    client.print(humedad_relativa_A);
    client.print("&temperatura_A=");
    client.print(temperatura_A);
    client.println(" HTTP/1.0");
    client.println("User-Agent: arduino-ethernet");
    client.println("Connection: close");
    client.println();

    // note the time that the connection was made:
    lastConnectionTime = millis();
  } else {
    // if you couldn't make a connection:
    Serial.println("connection failed");
  }
}
