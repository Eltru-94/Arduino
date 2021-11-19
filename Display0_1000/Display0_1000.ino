const byte numeral[10] = {
 //ABCDEFGdp
  B11111111,  // 0
  B11111110,  // 1
  B11111101,  // 2
  B11111100,  // 3
  B11111011,  // 4
  B11111010,  // 5
  B11111001,  // 6
  B11111000,  // 7
  B11110111,  // 8
  B11110110,  // 9
};

unsigned long previousMillis= 0;
const long interval =100;
int segundos=0;
int segmentPins[]= {6,7,8,9};
const int nbrDigits= 4;  // Numero de dígitos 
                         
const int digitPins[nbrDigits] = {5,4,3,2}; // Pines para encender cada display.

void setup() {

 for(int i=0; i < 4; i++)
   pinMode(segmentPins[i], OUTPUT); // set segment and DP pins to output
  
  for(int i=0; i < nbrDigits; i++)
    pinMode(digitPins[i], OUTPUT);   // Actvacion de displays

 for(int i=0; i < nbrDigits; i++)
   digitalWrite(digitPins[i], HIGH );

}
int contador=0;
void loop() {
  
unsigned long currentMillis= millis();
  if(currentMillis-previousMillis>=interval){
    previousMillis=currentMillis;
  
    showNumber(segundos);
    segundos++;  
    } else{      
    showNumber(segundos);      
      } 

}
void showNumber( int number)  
{
  if(number == 0)
    showDigit( 0, nbrDigits-1) ; // display 0 en el digito en la mas a la derecha
  else                           // para que no se encienda 00 sino solo 0.showDigit(number,numberdigit)
  {
    // display el valor correspondiente en cada display   
    for( int digit = nbrDigits-1; digit >= 0; digit--)
    {
      if(number > 0)
      {
         showDigit( number % 10, digit)  ;  // Extraer las unidades
         number = number / 10;              // Extraer las decenas
        
      }
    }
  }
}
void showDigit( int number, int digit)
{
  digitalWrite(digitPins[digit], LOW ); // Activando el display
 
  for(int segment = 0; segment < 4; segment++)
  {
    boolean isBitSet = bitRead(numeral[number], segment);
    // isBitSet will be true if given bit is 1
    isBitSet =  !isBitSet; // Comentar esta linea para un display catodo comun
    digitalWrite( segmentPins[segment], isBitSet);
    
  }
  delay(5); 
  
    digitalWrite( digitPins[digit], HIGH ); // Apagando el display
}
