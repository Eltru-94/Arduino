//Deficion de los pines de entrada

#define Sensor2 A0

//Mensaje de trama
int nodo = 2;

//Variables sensores
int humedad_suelo = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  humedad_suelo = analogRead(Sensor2);
  Serial.println(String(nodo)+","+String(humedad_suelo)+",");
  delay(2000);
}
