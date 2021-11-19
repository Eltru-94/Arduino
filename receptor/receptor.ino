#include <VirtualWire.h>

void setup()
{
    Serial.begin(9600);  // Debugging only
    Serial.println("setup");

    // Se inicializa el RF
    vw_setup(2000);  // velocidad: Bits per segundo
    vw_set_rx_pin(2);  //Pin 2 como entrada del RF
    vw_rx_start();       // Se inicia como receptor
    
    pinMode(13, OUTPUT);    //Configuramos el pin del Led como entrada
    digitalWrite(13, false);
}

void loop()
{
    uint8_t dato;
    uint8_t datoleng=1;
    //verificamos si hay un dato valido en el RF
    if (vw_get_message(&dato,&datoleng))
    {
        if((char)dato=='a')
        {
            digitalWrite(13, true); //Encendemos el Led
        }
        else if((char)dato=='b')
        {
            digitalWrite(13, false); //Apagamos el Led
        }            
    }
}
