//Librerias

#include <dht.h>
dht DHT;

//Deficion de los pines de entrada
#define Sensor1 9
#define Sensor2 A0

//Mensaje de trama

int nodo = 1;

//Variables sensores
int temperatura = 0;
int humedad_suelo = 0;
int humedad = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {


  DHT.read11(Sensor1);
  temperatura = DHT.temperature;
  humedad = DHT.humidity;
  humedad_suelo = analogRead(Sensor2);
  Serial.println(String(nodo)+","+String(humedad_suelo)+","+String(humedad)+","+String(temperatura)+",");
  delay(2000);

}
