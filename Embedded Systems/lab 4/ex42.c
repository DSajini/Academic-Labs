#include <avr/io.h>
#include <util/delay.h> 


void delay_timer1()
{
	TCNT1 = 25536;

	TCCR1A = 0x00;
	TCCR1B = 0x02;

	while((TIFR1&0x01) == 0);

	TCCR1A = 0x00;
	TCCR1B = 0x00;

	TIFR1 = 0x01;


}

int main(void){

	DDRD = DDRD | (1<<6);

	OCR0A = 0;                //duty cycle

	TCCR0A = (1<<WGM01) | (1<<WGM00);     //fast pwm mode

	TCCR0A |= (1<<COM0A1); 
	TCCR0A |= (0<<COM0A0);         //non inverting

	TCCR0B = 0X03;       //prescalar

	TCNT0=0;

	while(1){

		int i;

		for(i=0; i<255; i++){
			OCR0A = i;
			delay_timer1();
		}
		int j;
		for(j=255; j>0; j--){
			OCR0A = j;
			delay_timer1();
		}


	}
}