/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products

  Este es mi primer programa en arduino

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald

  modified 2 Sep 2016
  by Arturo Guadalupi

  modified 8 Sep 2016
  by Colby Newman
*/

// aqui puedo poner un comentario de solo una linea con el doble slash
// the setup function runs once when you press reset or power the board
// Lugar para poner variables
int Rojo1 = 13;
int Amarillo1 = 12;
int Verde1 = 11;

int Rojo2 = 10;
int Amarillo2 = 9;
int Verde2 = 8;


//in de espacio para poner variables
void setup() {
  // initialize digital pin LED_BUILTIN as an output.

  pinMode(Rojo1, OUTPUT);
  pinMode(Amarillo1, OUTPUT);
  pinMode(Verde1, OUTPUT);

  pinMode(Rojo2, OUTPUT);
  pinMode(Amarillo2, OUTPUT);
  pinMode(Verde2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // SE PRENDE SOLO EL ROJO
  digitalWrite(Rojo1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(Amarillo1, LOW);
  digitalWrite(Verde1, LOW);

  digitalWrite(Rojo2, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(Amarillo2, LOW);
  digitalWrite(Verde2, LOW);
  delay(1000);                // wait for a second
  // SE PRENDE SOLO EL VERDE
  digitalWrite(Verde1, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(Rojo1, LOW);
  digitalWrite(Amarillo1, LOW);

  digitalWrite(Verde2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(Rojo2, LOW);
  digitalWrite(Amarillo2, LOW);
  delay(1000);                       // wait for a second
  // SE PRENDE EL AMARILLO
  digitalWrite(Amarillo1, HIGH);
  digitalWrite(Rojo1, LOW);
  digitalWrite(Verde1, HIGH);

  digitalWrite(Amarillo2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(Rojo2, LOW);
  digitalWrite(Verde2, LOW);
  delay(1000);                       // wait for a second


}
