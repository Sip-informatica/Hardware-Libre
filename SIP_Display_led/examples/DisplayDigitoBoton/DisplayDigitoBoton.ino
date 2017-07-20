/* Libreria que controla el display */
#include <SIP_DisplayLed.h>


/* Define el numero de segmentos del display y los Pines que utiliza 
el microcontrolador */ 
  int n_Segment = 7;
  int initial_Pin = 2;
  int final_Pin = 8;
/* Declarar e inicializar variables */
  int botonAvanzar = 0;
  int botonRetroceder = 0;
  int value = 0;
  
  /* Creamos el objeto led y lo inicializamos */
  SIP_DisplayLed display_7Segmentos = SIP_DisplayLed(n_Segment, initial_Pin, final_Pin);
  
void setup() { 
  /* Asignar pin a los botones como entrada */
  pinMode(9,INPUT);   // Retroceder
  pinMode(10,INPUT);  // Avanzar 
  
}

void loop() {

  botonAvanzar = digitalRead(10);
  botonRetroceder = digitalRead(9);

  if (botonAvanzar == LOW and value < 9){
    value = value++;    
    }
  if (botonRetroceder == LOW and value > 0){
    value = value--;
    }
    
    // controla efecto rebote del pulsador  
    delay(30); 
  
/* Metodo que muestra en el display el digito selecionado */
 display_7Segmentos.displayDigit(value);

}
