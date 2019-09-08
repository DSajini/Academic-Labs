#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>

#define BLINK_DELAY_MS 100
int count=0;

int main(void){

	int i;
	for(i=0;i<4;i++){         //Configure pin 0,1,2,3 in PORT B as output
		DDRB = DDRB | (1<<i);  
	}
	 

	DDRD = DDRD &~ (1<<2);   //Configure pin 2 in PORT D (INT0) as input

	//detect falling edge
	EICRA = EICRA | (1<<ISC01);
	EICRA = EICRA | (0<<ISC00);


	sei();    //enable global interrupts

	EIMSK = EIMSK | (1<<INT0);   //enable external interrupts

	///PORTB = PORTB | (1<<0);    What is this??????????????????????????????????????
  

	while(1){

	}




}

ISR(INT0_vect){

	
		count++;


	PORTB = count;
	_delay_ms(1500);

	
	


}