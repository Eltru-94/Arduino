// Programa 1 lado del emisor
#include <RH_ASK.H>
#include <SPI.h>
RH_ASK rf_driver;
void setup() {
  rf_driver.init();

}

void loop() {
 const char *msg= "Hola desde lejos";
 rf_driver.send((uint8_t *)msg,strlen(msg));
 rf_driver.waitPacketSent();
 delay(1000);

}
