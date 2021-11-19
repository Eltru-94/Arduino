//RST           D9
//SDA(SS)      D10
//MOSI         D11
//MISO         D12
//SCK          D13

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
String Ids[] = {"1159814227", "11516811727", "38314327", "99196827"};
const int RST_PIN = 9;            // Pin 9 para el reset del RC522
const int SS_PIN = 10;            // Pin 10 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Crear instancia del MFRC522
String ID_Tarjeta ;
int pos = 0;
void printArray(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    //Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    ID_Tarjeta += (String)buffer[i];
    //Serial.print(buffer[i]);

  }
  for (int i = 0; i < 4; i++) {
    if (ID_Tarjeta == Ids[i]) {

      Serial.println(ID_Tarjeta);
      servo();
      break;
    }

  }

}
void servo() {

  for (pos = 0; pos <= 90; pos += 1) {
    // in steps of 1 degree
    myservo.write(pos);
    delay(25);
  }
  for (pos = 90; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(25);
  }

}
void setup()
{
  myservo.attach(7); // puerto servo
  Serial.begin(9600);      //Inicializa la velocidad de Serial
  SPI.begin();         //Función que inicializa SPI
  mfrc522.PCD_Init();     //Función  que inicializa RFID
}

void loop()
{
  // Detectar tarjeta
  if (mfrc522.PICC_IsNewCardPresent())
  {
    if (mfrc522.PICC_ReadCardSerial())
    {

      printArray(mfrc522.uid.uidByte, mfrc522.uid.size);

      // Finalizar lectura actual
      mfrc522.PICC_HaltA();
    }
  }

  if (digitalRead(5)) {
    servo();
  }
  ID_Tarjeta = "";
  delay(250);
}
