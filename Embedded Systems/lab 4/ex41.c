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

	}
}