#include <SoftwareSerial.h>
SoftwareSerial XBee(3, 2);
void setup() {
  Serial.begin(9600);
  XBee.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (XBee.available() > 0) {

   int dato=XBee.read();
   Serial.write(char(dato));


  }


}
