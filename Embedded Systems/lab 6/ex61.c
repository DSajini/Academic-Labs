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

	//UCSR0C = (0<<USBS0);	// Setting the stop bit to 1
	//UCSR0C = (0 << UPM01) | (0 << UPM00);	// Parity disabled
	//UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);	// 8 bit data frame
	//UCSR0C = (0 << UMSEL00) | (0 << UMSEL01);	// Choose the asynchronous mode

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

int main(void)
{
	

	char array[] = "E15299 - Ranushka L.M , E15249 - Pamoda W.A.D , E15139 Ishanthi D.S";

	usart_init(MYUBRR);

	int i;

	for(i = 0; array[i] != '\0'; i++)
	{
		usart_send(array[i]);
		_delay_ms(10);
	}
	
	

}