#include <avr/io.h>




 int main(void)
{
	DDRB = DDRB|(1<<5);

 	DDRB = DDRB|(1<<4);        /* configure pin 4 of PORTB for output*/ 
 	DDRB = DDRB|(1<<3);
 	DDRB = DDRB|(1<<2);
 	DDRB = DDRB|(1<<1); 


 	sei();

 	TIMSK1 = 0x01;

    TCCR1A = 0x00;
    TCCR1B = 0x04;
    TCNT1 = 3036;



	while(1)
	{

		int i;
		for (i = 3; i >= 1; i--)
        {
            PORTB = PORTB | (1<<i);    
            _delay_ms(50); 
            //delay_timer1(); 
            PORTB = PORTB &~(1<<i);
            _delay_ms(50);
            //delay_timer1(); 
       
	    } 
	    int j;
        for ( j = 2; j <= 4; j++)
        {
            PORTB = PORTB | (1<<j);    
            _delay_ms(50); 
            //delay_timer1(); 
            PORTB = PORTB &~(1<<j);
            _delay_ms(50);
            //delay_timer1(); 
       
        }
		
	}
}



ISR(TIMER1_OVF_vect)
{
	PORTB = PORTB ^ (1<<5);
}


