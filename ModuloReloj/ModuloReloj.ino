#include <Wire.h>
#include <RTClib.h>
RTC_DS3231 rtc;
void setup() {
  Serial.begin(9600);
  if (!rtc.begin()) {

    Serial.println("Modulo rtc no encontrado");
    while (1);
  }
  //rtc.adjust(DateTime(__DATE__,__TIME__));

}

void loop() {
  DateTime fecha = rtc.now();
  String fecha_actual=String(fecha.year())+"-"+String(fecha.month())+"-"+String(fecha.day());
  String hora_actual=String(fecha.hour())+":"+String(fecha.minute());
  Serial.print(fecha_actual);
  Serial.println(hora_actual);
  delay(1000);

}
