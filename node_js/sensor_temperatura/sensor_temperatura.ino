#include <math.h>
int analogCapteur = A0;
int digitCapteur=5;

double Thermistor(int RawADC) {

  double Temp;

  Temp = log(10000.0 * ((1024.0/RawADC-1)));

  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp);

  Temp = Temp - 273.15;

  return Temp;

}


void setup() {
//pinMode (analogCapteur, INPUT);
 Serial.begin(9600);
 pinMode(digitCapteur,INPUT);
}

void loop() {

int readVal = analogRead(analogCapteur);
int  temp = Thermistor(readVal);
Serial.print(readVal);
Serial.print(") , (");
Serial.println(temp);

delay(1000);
}
