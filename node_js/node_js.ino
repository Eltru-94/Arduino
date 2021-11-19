int couter=0;
int pinLDR=0;
int valorLDR=0;
int led_1=8;
void setup() {
  Serial.begin(9600);
  pinMode(led_1,OUTPUT);
  
}

void loop() {

 valorLDR = analogRead(pinLDR); 
 Serial.print(valorLDR,DEC);
  if(valorLDR<512){
  digitalWrite(led_1,HIGH);
  }else{
     digitalWrite(led_1,LOW);
    }
 delay(1000);

}
