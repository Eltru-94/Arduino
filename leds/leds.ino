int resultados = 0;   /// Variable para mostrar los resultados
int num1 = 0;
int num2 = 0;
boolean ver=true;
int comparar = 0; //1-iguales - diferentes

const int Puls_1 = 2;        // Ingreso de num1
const int Puls_2 = 3;        // Ingreso de num2
const int Puls_3 = 4;

const int debounceDelay = 5;  // milliseconds to wait until stable


int ledPins[] = {5, 6, 7, 8, 9, 10, 11, 12}; // create array of output pins for LEDs
// Se mostrará la variable resultados

void setup() {
  pinMode(Puls_1, INPUT);   // Inicializar puls 1
  pinMode(Puls_2, INPUT);   // Inicializar puls 2
  pinMode(Puls_3, INPUT);   // Inicializar comparacion

  for (int index = 0; index < 8; index++) {
    pinMode(ledPins[index], OUTPUT);         // declarar pines como salida
  }

}

void loop() {
 if (!digitalRead(Puls_1)) {     //SE pulsó
    delay(debounceDelay);           //Esperar un tiempo por rebotes
                 //Incrementar el contador
    if(ver){
     
      if(num1>16){
        ver=false;
        num1=15;
        }
         num1=num1+1;
     
    }else{
      
       num1=num1-1;
      if(num1>=0){
        ver=true;
        num1=0;
        }
      }
    
  }
  while (!digitalRead(Puls_1)) {  // Mientras se tenga presionado
  }
  resultados =  num1; // Mostrar los resultados en una sola variable
  Visualizar();
  delay(10);

}
void Visualizar()
{
  for (int index = 0; index < 8; index++)
  {
    digitalWrite(ledPins[index], bitRead(resultados, index));  ///  bitRead(var, index)
    ///  digitalWrite(pin, value)
  }
}
