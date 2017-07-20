/* Libreria que controla el display */
#include <SIP_DisplayLed.h>


/* Define el numero de segmentos del display y los Pines que utiliza 
el microcontrolador */ 
  int n_Segment = 7;
  int initial_Pin = 2;
  int final_Pin = 8;
  
  /* Creamos el objeto led y lo inicializamos */
  SIP_DisplayLed display_7Segmentos = SIP_DisplayLed(n_Segment, initial_Pin, final_Pin);
  
void setup() { 
  // Abrir puerto serial 
  Serial.begin(9600);
}

void loop() {
  int value;
  /* Obtener los valores del monitor serial en forma de entero */
  // while(Serial.available() == 0);
  if(Serial.available() > 0) {
     value = Serial.parseInt();
    }
  
/* Metodo que muestra en el display el digito selecionado */
 display_7Segmentos.displayDigit(value);

}
