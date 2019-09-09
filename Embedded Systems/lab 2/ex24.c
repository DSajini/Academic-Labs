#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>


#define BLINK_DELAY_MS 1000
int main(void){

DDRD = DDRD &~ (1<<2);
DDRD = DDRD &~ (1<<3);   //configure pin 2,3 of port D (INT 0, INT1) as input

int i;
for(i=0;i<6;i++){   //configure pin 0,1,2,3,4,5 of port B as output
	DDRB = DDRB | (1<<i);

}

//falling edge detection for INT0
EICRA = EICRA | (1<<ISC01);
EICRA = EICRA | (0<<ISC00);
sei();   //enable global interrupts

//falling edge detection for INT1
EICRA = EICRA | (1<<ISC11);
EICRA = EICRA | (0<<ISC10);

sei();   //enable global interrupts

//enable external interrupts
EIMSK = EIMSK | (1<<INT0);
EIMSK = EIMSK | (1<<INT1);

while(1){

}
}

ISR(INT0_vect){
	PORTB = PORTB<<1;
	PORTB = PORTB &~(1<<0);
	_delay_ms(1000);
	
}

ISR(INT1_vect){
	PORTB = PORTB<<1;
	PORTB = PORTB | (1<<0);
	_delay_ms(1000);
	
}
