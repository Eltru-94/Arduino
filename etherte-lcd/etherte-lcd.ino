

/*
   Created by ArduinoGetStarted.com

   This example code is in the public domain

   Tutorial page: https://arduinogetstarted.com/tutorials/arduino-ethernet-shield-2
*/

#include <SPI.h>
#include <Ethernet.h>
#include  <LiquidCrystal.h>

//RS E D4 D5 D6 D7
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// replace the MAC address below by the MAC address printed on a sticker on the Arduino Shield 2
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// TODO: Declare something depending on your application

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);



}

void loop() {
  lcd.clear();
  lcd.print("Activas si entramos");
}
