#include <SoftwareSerial.h> // Librería para la comunicación Bluetooth
SoftwareSerial BT(4,6); //Pines Tx y Rx del módulo Bluetooth, respectivamente

char datos_serial; //Variable para guardar los datos que recibimos a través del módulo

void setup() {
  
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  BT.begin(9600); //La comunicación se suele hacer a 9600 bps, si no te funciona cambia esta línea a 38400 --> BT.begin(38400)
}

void loop() {
  
  if (BT.available()>0){ //Solo iniciamos la lectura cuando el módulo quiere comunicarse con la placa, para evitar errores
    
    char datos_serial=(char) BT.read(); //Leemos el mensaje y lo guardamos en nuestra variable
    Serial.println(datos_serial); //Imprimimos en el Serial para poder verlo en el mismo ordenador a través del Monitor Serie del IDE
    
    switch (datos_serial){
    
      case '1': //Si el mensaje recibido es "1"...
        digitalWrite(13,HIGH); //Enciende el LED
        break;
        
      case '0': //Si el mensaje recibido es "0"...
        digitalWrite(13,LOW); //Apaga el LED
        break;
    }
  }
}
