int bocina = 11;
int valorSensor = 0;
float tem = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(bocina, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  valorSensor = analogRead(A0);
  Serial.println(valorSensor);
  tem = ((valorSensor * 100) / 1024);
  delay(50);
  Serial.println(tem);
  if (tem > 50) {
    digitalWrite(bocina, HIGH);
    delay(100);
  } else {
    digitalWrite(bocina, LOW);
    delay(50);
  }


}
