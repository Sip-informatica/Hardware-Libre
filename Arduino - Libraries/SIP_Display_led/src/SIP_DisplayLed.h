/*
Cabecera de la libreria para controlar los segmentos del display led.
*/

#ifndef SIP_DisplayLed_h
#define SIP_DisplayLed_h

/* Control de la version de Arduino */
#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

/* Control de un display */ 
class SIP_DisplayLed {
public:
	/* Constructor nulo */
	SIP_DisplayLed(){};
	/* Contruir objeto display */
	SIP_DisplayLed(int n_Segment, int initial_Pin, int final_Pin);

	/* Control de las variables privadas */
	int getN_Segment();
	void setN_Segment(int n_segment);
	int getInitial_Pin();
	void setInitial_Pin(int initial_pin);
	int getFinal_Pin();
	void setFinal_Pin(int final_pin);
	int getAscii(int value);
	int setAscii(int value,int ascii);
	int getTime();
	int setTime(int time);


	/* Limpia el display, apaga todo los sgmentos del dispay */
	void clearDisplay();	
	/* Muestra un digito */ 
	void displayDigit(int value);
	/* Muestra un caracter */
	void displayChar(char value);
	/* Cuenta desde el valor minimo hasta el valor maximo */
	void count(int min, int max);
	/* Control de los segmentos del display */
	void displayControl(int a, int b, int c, int d, int e, int f, int g);

private:
	/* Control de los segmentos del display */
	/*void display(int a, int b, int c, int d, int e, int f, int g);*/
	void _display(int value);
	/* Define el numero de segmentos del display y los Pines que utiliza 
el microcontrolador */ 
	int _n_Segment;
	int _initial_Pin;
	int _final_Pin;
	int _time = 1000;

	/* Declaracion de los caracteres, ampliable ASCII */
	int _ascii[10][7] = {
		{1,1,1,1,1,1,0},
		{0,1,1,0,0,0,0},
		{1,1,0,1,1,0,1},
		{1,1,1,1,0,0,1},
		{0,1,1,0,0,1,1},
		{1,0,1,1,0,1,1},
		{1,0,1,1,1,1,1},
		{1,1,1,0,0,0,0},
		{1,1,1,1,1,1,1},
		{1,1,1,0,0,1,1}
	};
};

#endif
