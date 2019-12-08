#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#define FOSC 16000000 // Clock Speed
#define BAUD 9600   //baud rate 
#define MYUBRR FOSC/16/BAUD-1          //from equation


void usart_init(unsigned int ubrr)
{
	//set baud rate
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;

	UCSR0B = (1 << RXEN0)  | (1 << TXEN0);		// Enable Transmission and Recieving

	UCSR0C = 6;
}

void usart_send(unsigned char data)
{
	while(!(UCSR0A & (1<<UDRE0)));  //wait for empty transmit buffer
	UDR0 = data;                 //put data into the buffer and send
}


unsigned char usart_recieve(void)
{
	while(!(UCSR0A & (1<< RXC0)));       //wait for the data to be received
	return UDR0;                           //get and return the received data from the buffer. 
}



void EEPROMwrite(unsigned int address, char data)
{
	// Wait for completion of previous write

	while(EECR & (1<<EEPE));

	// Set up address amd data type
	EEAR = address;
	EEDR = data;

	// Write logical 1 to EEM
	EECR |= (1<<EEMPE);

	//start eeprom write
	EECR |= (1<<EEPE);

	
}



int main (void)
{
	usart_init(MYUBRR);
	//int address = 0;
	char arr[1024];
	int i=0;

	while(1)
	{	

		char c  = usart_recieve();

		while(c!='\n'){

			arr[i]=c;
			i++;
			c  = usart_recieve();

		}

		i=0;
		char d  = usart_recieve();
		while(d!='\n'){

			d=arr[i];
			i++;
			usart_send(d);

		}
		i=0;

		
		//EEPROMwrite(address, c);


		
		//usart_send(EEPROMread(address));
		//address++;
		/*
		if (address == 1024)
		{
			address = 0;
		}
		*/
	}

	
	
	return 0;
}