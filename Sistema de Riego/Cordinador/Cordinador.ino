/*Cordinador o Nodo Central*/
/*Library*/
#include <SPI.h>
#include <Ethernet.h>
#include <Wire.h>
#include <RTClib.h>
#include  <LiquidCrystal.h>

/*Inicialización library*/
RTC_DS3231 rtc;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

/*Variables Ethernet*/
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 177);
EthernetClient client;

/*Servidor host*/
char server[] = "automatizacion-riego.herokuapp.com";

/*Variables Climatologicas*/
int humedad_suelo_nodoA = 0;
int humedad_relativa_A = 0;
int temperatura_A = 0;
int humedad_suelo_nodoB = 0;
boolean conexion = false;
/*Trama*/
String estado = "OFF";
char c;
const char separator = ',';
int data[5];

/*Variables Reloj*/
String fecha_actual;
String hora_actual;
unsigned long lastConnectionTime = 0;           // last time you connected to the server, in milliseconds
const unsigned long postingInterval = 10 * 1000; // delay between updates, in milliseconds

void setup() {
  Serial.print(hora_actual);
  Serial.begin(9600);
  lcd.begin(16, 2);
  CargarSistema();
  if (Ethernet.begin(mac) == 0) {
    lcd.print("Fallo conexión DHCP");
    delay(1000);
    lcd.clear();
  } else {
    lcd.print("DHCP ASIGNADO IP ");
    lcd.setCursor(0, 1);
    lcd.print(Ethernet.localIP());
    delay(5000);
    lcd.clear();
  }
  if (!rtc.begin()) {
    lcd.print("Modulo rtc no encontrado");
    delay(1000);
    lcd.clear();
  }
  rtc.adjust(DateTime(__DATE__, __TIME__));
  lcd.clear();
  delay(1000);
  // httpRequest();
  pinMode(9, OUTPUT);
}

void loop() {
  Reloj();
  //Metodos
  leerDatosSensores();
  leerDatosServidor();
  if (millis() - lastConnectionTime > postingInterval) {
    httpRequest();
  }
  c = "";
}

void imprimir(int hsA, int hsB, int hR, int t) {

  int tem_1 = (hsA * 10) / 100;
  int tem_2 = (hsB * 10) / 100;
  lcd.print("HSA:" + String(tem_1) + "% HSB:" + String(tem_2) + "%");
  lcd.setCursor(0, 1);
  lcd.print("HR:" + String(hR) + "% T:" + String(t) + "C " + estado);

}

// Este metodo realiza una conexión HTTP al servidor:
void httpRequest() {

  client.stop();
  if (client.connect(server, 80)) {
    Serial.println("connecting...");
    client.print("GET /ActivacionRiego/conectar/?");
    client.print("humedad_suelo_nodoA=");
    client.print(humedad_suelo_nodoA);
    client.print("&humedad_suelo_nodoB=");
    client.print(humedad_suelo_nodoB);
    client.print("&humedad_relativa_A=");
    client.print(humedad_relativa_A);
    client.print("&temperatura_A=");
    client.print(temperatura_A);
    client.print("&fecha_actual=");
    client.print(fecha_actual);
    client.print("&hora_actual=");
    client.print(hora_actual);
    client.println(" HTTP/1.0");
    client.println("Host: automatizacion-riego.herokuapp.com");
    client.println("Connection: close");
    client.println();

    // note the time that the connection was made:
    lastConnectionTime = millis();
  } else {
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("No existen");
    lcd.setCursor(0, 1);
    lcd.print("Conexion Ethernet");
    delay(1000);
  }


}
/*Este metodo recive datos enviados por el servidor servidor*/
void leerDatosServidor() {
  if (client.available()) {
    if (client.available()) {
      c = client.read(); // Leemos los caracteres de uno en uno
      if (c == '#') {
        estado = "ON";
        Serial.print("Activas si entramos");
        digitalWrite(9, HIGH);
        lcd.clear();
      }

      if (c == '*') {
        Serial.println("Desactivar Manual");
        estado = "OFF";
        digitalWrite(9, LOW);
        lcd.clear();
      }
    }
  }
}

/*Este metodo recive las lecturas de datos de los Nodo A y B*/
void leerDatosSensores() {

  if (Serial.available() > 0) {
    // read the incoming byte:
    String datos = Serial.readString();
    Serial.println(datos);
    conexion = true;
    for (int i = 0; i < 4 ; i++)
    {
      int index = datos.indexOf(separator);
      data[i] = datos.substring(0, index).toInt();
      datos = datos.substring(index + 1);
    }
    delay(50);
    if (data[0] == 1) {
      humedad_suelo_nodoA = data[1];
      humedad_relativa_A = data[2];
      temperatura_A = data[3];

    } else if (data[0] == 2) {
      humedad_suelo_nodoB = data[1];

    }
    imprimir(humedad_suelo_nodoA, humedad_suelo_nodoB, humedad_relativa_A, temperatura_A);
    delay(50);

  }
}
/*Este metodo sirve para el reloj del sistema*/
void Reloj() {

  DateTime fecha = rtc.now();
  fecha_actual = String(fecha.year()) + "-" + String(fecha.month()) + "-" + String(fecha.day());
  hora_actual = String(fecha.hour()) + ":" + String(fecha.minute()) + ":" + String(fecha.second());

}

/*Mensaje de inicialización sistema*/
void CargarSistema() {
  lcd.print("SISTEMA RIEGO");
  lcd.setCursor(0, 1);
  lcd.print("CREADO POR: APT");
  delay(5000);
  lcd.clear();
  lcd.print("conectado.");
  delay(1500);
  lcd.clear();
  lcd.print("conectado..");
  delay(1500);
  lcd.clear();
  lcd.print("conectado...");
  delay(1500);
  lcd.clear();
  lcd.print("conectado....");
  delay(1500);
  lcd.clear();
  lcd.print("conectado.....");
  delay(1500);
  lcd.clear();
  lcd.print("conectado......");
  delay(1500);
  lcd.clear();
}
