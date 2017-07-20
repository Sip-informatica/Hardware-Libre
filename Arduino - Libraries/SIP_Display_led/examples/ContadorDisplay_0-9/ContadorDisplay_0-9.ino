
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

}

void loop() {
  /* Configurar retardo en que se muestra los digitos,
  (por defecto 1000 ms) */
  display_7Segmentos.setTime(1500);
/* Metodo que muestra en el display el rango de nº elegidos */ 
  display_7Segmentos.count(0, 9);

}
