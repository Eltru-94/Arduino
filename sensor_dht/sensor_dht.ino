#include <dht.h>
dht DHT;
#define Sensor1 8
#define Sensor2 A0


void setup() {
  Serial.begin(9600);

}

void loop() {

  String mensaje ="NODOA";
  DHT.read11(Sensor1);
  int temperatura = DHT.temperature;
  int humedad = DHT.humidity;
  int humedad_suelo = analogRead(Sensor2);
  Serial.println(String(temperatura) + "," + String(humedad) + ","+String(humedad_suelo) +","+ mensaje);

  delay(60000);

}
