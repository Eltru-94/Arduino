
const byte numeral[10] = {
  B11111100, //0
  B01100000, //1
  B11011010, //2
  B11110010, //3
  B01100110, //4
  B10110110, //5
  B00111110, //6
  B11100000, //7
  B11111110, //8
  B11100110,  //9
};
//Definicion de pines en el Arudino Uno para los segmentos
//                dp, G, F, E, D, C, B, A
int  contador = 0  ;
const int segmentPins[8] = {6, 13, 12, 11, 10, 9, 8, 7};
int entradas[] = {2, 3, 4, 5};

void setup() {
  for (int i = 0; i < 8; i++)
  {
    pinMode(segmentPins[i], OUTPUT);  //declararlos como salidas
  }
  for (int index = 0; index < 4; index++) {
    pinMode(entradas[index], INPUT); //entrada
    digitalWrite(entradas[index], HIGH);
  }

}

void loop() {
  //contador de los diez numeros del 0 al 9

  if (!digitalRead(2)) {
    delay(300);

    while (!digitalRead(2)) {

    }
    if (contador == 9) {
      contador = 0;
       showDigit(contador);
    } else {
      contador++;
      showDigit(contador);

    }

  }
   showDigit(contador);
}

void showDigit(int number)
{
  boolean BitSetNum;
  for (int segment = 0; segment < 8; segment++) //
  {
    if (number < 0 || number > 9)
    {
      BitSetNum = 0;
    } else {

      BitSetNum = bitRead(numeral[number], segment);
    }
    BitSetNum = BitSetNum;
    digitalWrite(segmentPins[segment], BitSetNum);
  }
}

int Numero(int a, int b, int c, int d) {

  int uno = 0;
  int dos = 0;
  int tres = 0;
  int cuatro = 0;
  int suma;

  if (a == HIGH) {
    uno = 1;
  } else {
    uno = 0;
  }
  if (b == HIGH) {
    dos = 2;
  } else {
    dos = 0;
  }
  if (c == HIGH) {
    tres = 4;
  } else {
    tres = 0;
  }
  if (d == HIGH) {
    cuatro = 8;
  } else {
    cuatro = 0;
  }
  suma = uno + dos + tres + cuatro;
  return suma;
}
