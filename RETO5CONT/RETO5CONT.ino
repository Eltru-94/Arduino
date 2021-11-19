
int tem[7];
int cont = 0;
int cont2 = 0;
int salidas[] = {5, 6, 7, 8, 9, 10, 11};
int salidas2[] = {14, 15, 16, 17, 18, 19, 20};
void setup() {
  pinMode(2, INPUT); //entrada
  pinMode(3, INPUT); //entrada
  for (int index = 0; index < 7; index++) {
    pinMode(salidas[index], OUTPUT); //salida
    pinMode(salidas2[index], OUTPUT); //salida
  }


}

void loop() {
  visualizar(cont);
  visualizar1(cont2);
  if (!digitalRead(2)) {
    delay(300);
    while (!digitalRead(2)) {
    }


    if (cont == 9) {
      cont = 0;
      if (cont2 == 9) {
        cont2 = 0;

      } else {
        cont2++;
      }
    } else {
      cont++;
    }
    visualizar(cont);
    visualizar1(cont2);
  }

  if (!digitalRead(3)) {
    delay(300);
    while (!digitalRead(3)) {
    }


    if (cont == 0) {
      cont = 9;
      if (cont2 == 0) {
        cont2 = 9;

      } else {
        cont2 --;

      }
    } else {
      cont--;

    }
    visualizar(cont);
    visualizar1(cont2);
  }

}
void visualizar1(int dato) {
  switch (dato) {
    case 0:
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
      digitalWrite(17, HIGH);
      digitalWrite(18, HIGH);
      digitalWrite(19, HIGH);
      digitalWrite(20, LOW);
      break;
  }
  switch (dato) {
    case 1:
      digitalWrite(14, LOW);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
      digitalWrite(17, LOW);
      digitalWrite(18, LOW);
      digitalWrite(19, LOW);
      digitalWrite(20, LOW);
      break;
  }
  switch (dato) {
    case 2:
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, LOW);
      digitalWrite(17, HIGH);
      digitalWrite(18, HIGH);
      digitalWrite(19, LOW);
      digitalWrite(20, HIGH);
      break;
  }
  switch (dato) {
    case 3:
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
      digitalWrite(17, HIGH);
      digitalWrite(18, LOW);
      digitalWrite(19, LOW);
      digitalWrite(20, HIGH);
      break;
  }
  switch (dato) {
    case 4:
      digitalWrite(14, LOW);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
      digitalWrite(17, LOW);
      digitalWrite(18, LOW);
      digitalWrite(19, HIGH);
      digitalWrite(20, HIGH);
      break;
  }
  switch (dato) {
    case 5:
      digitalWrite(14, HIGH);
      digitalWrite(15, LOW);
      digitalWrite(16, HIGH);
      digitalWrite(17, HIGH);
      digitalWrite(18, LOW);
      digitalWrite(19, HIGH);
      digitalWrite(20, HIGH);
      break;
  }
  switch (dato) {
    case 6:
      digitalWrite(14, LOW);
      digitalWrite(15, LOW);
      digitalWrite(16, HIGH);
      digitalWrite(17, HIGH);
      digitalWrite(18, HIGH);
      digitalWrite(19, HIGH);
      digitalWrite(20, HIGH);
      break;
  }
  switch (dato) {
    case 7:
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
      digitalWrite(17, LOW);
      digitalWrite(18, LOW);
      digitalWrite(19, LOW);
      digitalWrite(20, LOW);
      break;
  }
  switch (dato) {
    case 8:
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
      digitalWrite(17, HIGH);
      digitalWrite(18, HIGH);
      digitalWrite(19, HIGH);
      digitalWrite(20, HIGH);
      break;
  }
  switch (dato) {
    case 9:
      digitalWrite(14, HIGH);
      digitalWrite(15, HIGH);
      digitalWrite(16, HIGH);
      digitalWrite(17, LOW);
      digitalWrite(18, LOW);
      digitalWrite(19, HIGH);
      digitalWrite(20, HIGH);
      break;
  }
}


void visualizar(int dato) {
  switch (dato) {
    case 0:
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      break;
  }
  switch (dato) {
    case 1:
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      break;
  }
  switch (dato) {
    case 2:
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      break;
  }
  switch (dato) {
    case 3:
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      break;
  }
  switch (dato) {
    case 4:
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      break;
  }
  switch (dato) {
    case 5:
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      break;
  }
  switch (dato) {
    case 6:
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      break;
  }
  switch (dato) {
    case 7:
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      break;
  }
  switch (dato) {
    case 8:
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      break;
  }
  switch (dato) {
    case 9:
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      break;
  }
}


