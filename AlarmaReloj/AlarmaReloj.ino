#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//RS,E,D4,D5,D6,D7
String reloj;
String horAlarma = "";
String mensaje;
void setup() {
  lcd.begin(16, 2);
  pinMode (7, OUTPUT);
  Serial.begin(4800);
}

void loop() {


  while (Serial.available() == 0) { //A espera de recibir una cadena
  }
  mensaje = Serial.readString();
  int iniReloj = mensaje.indexOf('/') + 1;
  int iniAlarma = mensaje.indexOf('*') + 1;
  int fintrama = mensaje.indexOf('#');

  int tamReloj = iniAlarma - iniReloj - 1;
  int tamAlarma = fintrama - iniAlarma;
  reloj = mensaje.substring(iniReloj, iniReloj + tamReloj );
  horAlarma = mensaje.substring(iniAlarma, iniAlarma + tamAlarma );
  if (horAlarma == "ALARMA ON") {
    digitalWrite(7, HIGH);
  } else {
    digitalWrite(7, LOW);
  }

  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print(reloj);
  lcd.setCursor(3, 1);
  lcd.print(horAlarma);


}
