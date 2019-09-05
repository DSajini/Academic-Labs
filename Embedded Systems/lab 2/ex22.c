#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

#define BLINK_DELAY_MS 100

int main(void){
	DDRB = DDRB | (1<<0);   //Configure pin 0 in PORT B as output

	DDRD = DDRD &~ (1<<2);   //Configure pin 2 in PORT D (INT0) as input

	//detect falling edge
	EICRA = EICRA | (1<<ISC01);
	EICRA = EICRA | (0<<ISC00);


	sei();    //enable global interrupts

	EIMSK = EIMSK | (1<<INT0);   //enable external interrupts

	PORTB = PORTB | (1<<0);    //What is this??????????????????????????????????????
  

	while(1){

	}




}

ISR(INT0_vect){

	if(PIND & 1){
		PORTB = PORTB ^ (1<<0);	
	}

	


}