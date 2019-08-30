#include<avr/io.h>
#include <util/delay.h> 


int main(void){
	DDRD = DDRD &~ (1<<7);

	int i;
	int count=0;
	for(i=0;i<6;i++){
		DDRB = DDRB | (1<<i);
	}

	while(1){

		
		if(PIND & 128){
			PORTB = PORTB &~ count;
			//_delay_ms(500);
			count++;
			

		}
		if(count>64){
			count=0;
		}
		PORTB = PORTB | count;
		//PORTB = count;

	}

	
}