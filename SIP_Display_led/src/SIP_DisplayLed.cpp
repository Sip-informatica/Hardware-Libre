/*
Libreria para controlar los segmentos del display led.
*/

#include "SIP_DisplayLed.h"

/* 
Define el numero de segmentos del display y los Pines que utiliza 
el microcontrolador. Para display de 7 segmentos  
_n_Segment = 7;
_initial_Pin = 2;
_final_Pin = 8;
*/

SIP_DisplayLed::SIP_DisplayLed(int n_segment, int initial_Pin, int final_Pin) {
	_n_Segment =	n_segment;
	_initial_Pin = initial_Pin;
	_final_Pin = final_Pin;

	/* Inicializar los pin de los segmentos como salida */
	for(int segment=_initial_Pin; segment<_final_Pin+1; segment++){
		pinMode(segment, OUTPUT);
	}

}

	/* Limpia el display, apaga todo los sgmentos del dispay */
	void SIP_DisplayLed::clearDisplay(){

		displayControl (0,0,0,0,0,0,0);

	}	

	/* Muestra un digito */ 
	void SIP_DisplayLed::displayDigit(int value){

    	_display(value); 
    }

	/* Muestra un caracter */
	void SIP_DisplayLed::displayChar(char value){

	}
	/* Cuenta desde el valor minimo hasta el valor maximo */
	void SIP_DisplayLed::count(int min, int max){
		int count = min;

		while (count!=max+1){
		displayDigit(count);
		delay(_time);
		count++;
		}

	}
	/* Control de los segmentos del display */
	void SIP_DisplayLed::displayControl(int a, int b, int c, int d, int e, int f, int g){
		
		int pin = _initial_Pin;

		digitalWrite(pin,a);
		digitalWrite(pin++,b);
		digitalWrite(pin++,c);
		digitalWrite(pin++,d);
		digitalWrite(pin++,e);
		digitalWrite(pin++,f);
		digitalWrite(pin++,g);
		
	}
	/* Display  el valor */
	void SIP_DisplayLed::_display(int value){
		
		int pin = _initial_Pin;
		int Value = value;
		
		for (int segment=0; segment<_n_Segment; segment++){

			digitalWrite(pin, _ascii[Value][segment]);
			pin++;

		}		
		
	}

	/* Control de las variables privadas */

	/* Abrir el puerto serial Serial.begin(9600); */
	int SIP_DisplayLed::getN_Segment(){
		return _n_Segment;
	}
	void SIP_DisplayLed::setN_Segment(int n_segment){
		_n_Segment = n_segment;
	}
	int SIP_DisplayLed::getInitial_Pin(){
		return _initial_Pin;
	}
	void SIP_DisplayLed::setInitial_Pin(int initial_pin){
		_initial_Pin = initial_pin;
	}
	int SIP_DisplayLed::getFinal_Pin(){
		return _final_Pin;
	}
	void SIP_DisplayLed::setFinal_Pin(int final_pin){
		_final_Pin = final_pin;
	}
	int SIP_DisplayLed::getAscii(int value){
		int ascii[_n_Segment];

		for (int segment=0; segment<_n_Segment; segment++){
			
			ascii[segment] = _ascii[value][segment];			

		}	

		return ascii;
	}
	int SIP_DisplayLed::setAscii(int value,int ascii){

	}
	int SIP_DisplayLed::getTime(){
		return _time;
	}
	int SIP_DisplayLed::setTime(int time){
		_time = time;
	}
