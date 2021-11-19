#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
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

void loop() {
 int datosA0=analogRead(A0);
 int datosA1=analogRead(A1);
 int  temp = Thermistor(datosA1);
 Serial.println(temp);
 int porcentaje_humedad=map(datosA0,1023,0,0,100);
   if(porcentaje_humedad>0 && porcentaje_humedad<=10){
    
   lcd.setCursor(0, 0);
   lcd.print("Tem : ");
   lcd.setCursor(6, 0);
   lcd.print(porcentaje_humedad);
   lcd.setCursor(10, 0);
   lcd.print("%");
   lcd.setCursor(0, 1);
   lcd.print("No conectado");
  
   }else if (porcentaje_humedad>10 && porcentaje_humedad<=25){
    
   lcd.setCursor(0, 0);
   lcd.print("Tem : ");
   lcd.setCursor(6, 0);
   lcd.print(porcentaje_humedad);
   lcd.setCursor(10, 0);
   lcd.print("%");
   lcd.setCursor(0, 1);
   lcd.print("Suelo Seco");
   }else if (porcentaje_humedad>25 && porcentaje_humedad<=60){
    
   lcd.setCursor(0, 0);
   lcd.print("Tem : ");
   lcd.setCursor(6, 0);
   lcd.print(porcentaje_humedad);
   lcd.setCursor(10, 0);
   lcd.print("%");
   lcd.setCursor(0, 1);
   lcd.print("Suelo humedo");
   
   }else if(porcentaje_humedad>60 && porcentaje_humedad<=100){
    
   lcd.setCursor(0, 0);
   lcd.print("Tem : ");
   lcd.setCursor(6, 0);
   lcd.print(porcentaje_humedad);
   lcd.setCursor(10, 0);
   lcd.print("%");
   lcd.setCursor(0, 1);
   lcd.print("Exceso de agua");
        
  }
  delay(1000);
  lcd.clear();
}


double Thermistor(int RawADC) {

  double Temp;

  Temp = log(10000.0 * ((1024.0/RawADC-1)));

  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp);

  Temp = Temp - 273.15;

  return Temp;

}
