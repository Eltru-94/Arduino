#include <dht.h>
dht DHT;
#define DHT11_PIN 8
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(){
 Serial.begin(9600);
 lcd.begin(16, 2);
 // Print a message to the LCD.
 lcd.print("Cargando");
 delay(2000);
 lcd.clear();
 lcd.print("Cargando..");
 delay(2000);
 lcd.clear();
 lcd.print("Cargando....");
 delay(2000);
 lcd.clear();
 lcd.print("Cargando......");
 delay(2000);
 lcd.clear(),
 lcd.setCursor(3, 0);
 lcd.print("Bienvenido");
 lcd.setCursor(0, 1);
 lcd.print("Llact Innovacion");
 delay(2000);
 lcd.clear();

  
}

void loop()
{
  DHT.read11(DHT11_PIN);

  //TEMPERATURA//
  lcd.setCursor(0, 0);
  lcd.print("Tem : ");
  lcd.setCursor(6, 0);
  lcd.print(DHT.temperature);
  lcd.setCursor(11, 0);
  lcd.print(" C");

   Serial.print(DHT.temperature,DEC);
  //HUMEDAD RELATIVA//
  lcd.setCursor(0, 1);
  lcd.print("Hum : ");
  lcd.setCursor(6, 1);
  lcd.print(DHT.humidity);
  lcd.setCursor(11, 1);
  lcd.print(" %");
  
  delay(2000);
}
