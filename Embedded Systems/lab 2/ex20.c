#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>


#define BLINK_DELAY_MS 1000


int main(void){
	DDRB = DDRB |(1<<2);    //configure pin 2 of port B as output

	DDRD = DDRD  &~ (1<<2);    //configure pin 2 of port D (INT 0) as input

	//Rising Edge Detection
	EICRA = EICRA | (1<<ISC01);
	EICRA = EICRA | (1<<ISC00);

	sei();    //enable global interrupts

	EIMSK = EIMSK | (1<<INT0);   //enable external interrupts for INT0

	while(1){

	}




}

ISR(INT0_vect){
	PORTB = PORTB |(1<<2);
	_delay_ms(BLINK_DELAY_MS);  //A
	PORTB = PORTB &~ (1<<2);
	_delay_ms(BLINK_DELAY_MS);  
}