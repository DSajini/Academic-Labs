#include <avr/io.h>

int main(void){

	DDRD = DDRD | (1<<6);

	OCR0A = 127;                //duty cycle

	TCCR0A = (1<<WGM01) | (1<<WGM00);     //fast pwm mode

	TCCR0A |= (1<<COM0A1); 
	TCCR0A |= (0<<COM0A0);         //non inverting

	TCCR0B = 0X03;       //prescalar

	TCNT0=0;

	while(1){

		TCCR0B = 2;       //prescalar 1:8
		_delay_ms(500);

		TCCR0B = 3;        //1:64
		_delay_ms(500);
		TCCR0B = 4;       //1:256
		_delay_ms(500);

		TCCR0B = 5;       //1:1024
		_delay_ms(500);

	}
}