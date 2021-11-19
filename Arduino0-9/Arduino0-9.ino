
int boton;
int cont = 0;
int salidas[] = {5, 6, 7, 8, 9, 10, 11};
void setup() {
  Serial.begin(9600);
  for (int index = 0; index < 7; index++) {
    pinMode(salidas[index], OUTPUT); //salida
  }

}

void loop() {
  boton = Serial.read();
  visualizar(cont);
  if (boton == '1' || boton == '2') {

    visualizar(cont);
    if (boton == '1') {
      if (cont == 99) {

        cont = 0;

      } else {
        cont++;
      }
      Serial.print(cont,DEC);
      visualizar(cont);

    } else if (boton == '2') {
      if (cont == 0) {

        cont = 99;

      } else {
        cont--;
      }
      visualizar(cont);
      Serial.print(cont,DEC);
    }

  }




}
void visualizar(int dato) {
  switch (dato) {
    case 0:
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);//
      break;
  }
  switch (dato) {
    case 1:
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);//
      digitalWrite(7, LOW);//
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      break;
  }
  switch (dato) {
    case 2:
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);//
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);//
      digitalWrite(11, LOW);
      break;
  }
  switch (dato) {
    case 3:
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);//
      digitalWrite(10, HIGH);//
      digitalWrite(11, LOW);
      break;
  }
  switch (dato) {
    case 4:
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);//
      digitalWrite(7, LOW);//
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);//
      digitalWrite(11, LOW);//
      break;
  }
  switch (dato) {
    case 5:
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);//
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);//
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      break;
  }
  switch (dato) {
    case 6:
      digitalWrite(5, HIGH);//
      digitalWrite(6, HIGH);//
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      break;
  }
  switch (dato) {
    case 7:
      digitalWrite(5, LOW);//
      digitalWrite(6, LOW);//
      digitalWrite(7, LOW);//
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      break;
  }
  switch (dato) {
    case 8:
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      break;
  }
  switch (dato) {
    case 9:
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);//
      digitalWrite(9, HIGH);//
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      break;
  }
}
