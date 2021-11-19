const int interruptor = 7;
String mensaje;
int boton;
void setup() {
  Serial.begin(9600);
  pinMode(interruptor, OUTPUT);

}

void loop() {




  boton = Serial.read();
  if (boton == '1') {
    digitalWrite(interruptor, HIGH);
  }
  if (boton == '2') {
    digitalWrite(interruptor, LOW);
  }




}
