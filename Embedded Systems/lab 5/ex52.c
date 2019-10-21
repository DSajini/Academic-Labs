#include<avr/io.h>
#include<util/delay.h>


int main(void){
	

	DDRC = DDRC  &~ (1<<1);    //configure pin 1 of port C(ADC1) as input
	
		DDRD = DDRD | (1<<3);     ////configure pins of port D as output



	ADCSRA = ADCSRA | (1<<ADEN); //enable the ADC module

	ADCSRA = ADCSRA | (1<<ADPS0) ;  //conversion speed set ADPS2:0 bits to 128(division factor)
	ADCSRA = ADCSRA | (1<<ADPS1) ;
	ADCSRA = ADCSRA | (1<<ADPS2) ;


	ADMUX = ADMUX | (0<<REFS0) ; //bit REFS0 and REFS1 to select voltage reference to AREF
	ADMUX = ADMUX | (0<<REFS1) ;

	ADMUX = ADMUX | (1<<MUX0) ; //set ADC input channel to pc1 

	ADMUX = ADMUX | (1<<ADLAR) ; //left justified
  

	while(1){
		ADCSRA = ADCSRA | (1<<ADSC) ;  // Activate the start conversion 
		while(( ADCSRA & 0b00010000)==0){}   //Wait for the conversion to be completed by polling 

		
		if(ADCH<100){
			PORTD =PORTD | (1<<3);

		}
		else{
			PORTD =PORTD &~ (1<<3);
		}
		ADCSRA = ADCSRA | (1<<ADIF);

		_delay_ms(500);



	}




}

