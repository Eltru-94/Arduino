const int ledpin1=0;
const int ledpin2=1;
const int ledpin3=2;
const int ledpin4=3;
const int ledpin5=4;
const int ledpin6=5;
const int ledpin7=6;
const int ledpin8=7;
const int ledpin9=8;
const int inputpin1=9;
const int inputpin2=10;
const int inputpin3=11;
const int debounceDelay=5; //tiempo para eliminar el rebote
int cont1 =0;
int cont2 =0;
void setup() {
 pinMode(ledpin1,OUTPUT);
 pinMode(ledpin2,OUTPUT);
 pinMode(ledpin3,OUTPUT);
 pinMode(ledpin4,OUTPUT);
 pinMode(ledpin5,OUTPUT);
 pinMode(ledpin6,OUTPUT);
 pinMode(ledpin7,OUTPUT);
 pinMode(ledpin8,OUTPUT);
 pinMode(ledpin9,OUTPUT);
 pinMode(inputpin1,INPUT);
 pinMode(inputpin2,INPUT);
 pinMode(inputpin3,INPUT);
   
}
void loop() {
  
  if (!digitalRead(inputpin1)){ //pregunta si el pin esta en 0
   delay(debounceDelay);
   while(!digitalRead(inputpin1)){
      }
    cont1++;
    numeros(cont1,ledpin1,ledpin2,ledpin3); 
    if(cont1==7){
      cont1=0;
      }     
    }
    
    if (!digitalRead(inputpin2)){ //pregunta si el pin esta en 0
    delay(debounceDelay);
    cont2++;
    
    while(!digitalRead(inputpin2)){ 
    }
    numeros(cont2,ledpin4,ledpin5,ledpin6);
    if(cont2==7){
      cont2=0;
      }     
    }
     if (!digitalRead(inputpin3)){ //pregunta si el pin esta en 0
    delay(debounceDelay);
    while(!digitalRead(inputpin3)){ 
    }
    if(cont1==cont2){
       digitalWrite(ledpin7,LOW);
       digitalWrite(ledpin8,HIGH);
       digitalWrite(ledpin9,LOW);
      } else if(cont1>cont2){
       digitalWrite(ledpin7,HIGH);
       digitalWrite(ledpin8,LOW);
       digitalWrite(ledpin9,LOW);
      }else{
       digitalWrite(ledpin7,LOW);
       digitalWrite(ledpin8,LOW);
       digitalWrite(ledpin9,HIGH);
        }
    }
}

void numeros(int cont, int led1,int led2,int led3){
     if(cont==1){
        digitalWrite(led1,HIGH);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        }
         if(cont==2){
        digitalWrite(led1,LOW);
        digitalWrite(led2,HIGH);
        digitalWrite(led3,LOW);
        }
        if(cont==3){
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);
        digitalWrite(led3,LOW);
        }
        if(cont==4){
        digitalWrite(led1,HIGH);
        digitalWrite(led2,LOW);
        digitalWrite(led3,HIGH);
        }
        if(cont==5){
        digitalWrite(led1,LOW);
        digitalWrite(led2,HIGH);
        digitalWrite(led3,LOW);
        }
        if(cont==6){
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);
        digitalWrite(led3,LOW);
        }
        if(cont==7){
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);
        digitalWrite(led3,HIGH);
        }
  }
