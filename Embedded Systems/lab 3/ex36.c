#include <avr/io.h> 
#include <util/delay.h> 
#include <avr/interrupt.h>

int n = 0;
 
 int main(){
 	 DDRB = DDRB | (1<<5);           //PB5 OUTPUT

 	 sei();
 	 TIMSK0 = 0x01;            //enable timer0 overflow interrupt

 	 TCNT0 = 231;               //load timer/counter0 register with an initial value

 	 TCCR0A = 0x01;
 	 TCCR0B = 0x05;

 	 while(1){

 	 }

 	 return 0;
}

ISR(TIMER0_OVF_vect){
	n++;

	if(n==7){
		n=0;
		PORTB = PORTB ^ (1<<5);
		TCNT0 = 231;
	}
}