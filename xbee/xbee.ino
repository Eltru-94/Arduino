


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {


if (Serial.available() > 0) {
    // read the incoming byte:
    String data = Serial.readString();
    

 
    Serial.println(data);
    
  }
}
