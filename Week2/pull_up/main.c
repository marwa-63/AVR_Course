/*
 * main.c
 *
 *  Created on: Oct 6, 2023
 *      Author: HP
 */
#include <util/delay.h>
#include <avr/io.h>
typedef unsigned char u8;

/*#define DDRA *((u8*)0x3A)
#define PORTA *((u8*)0x3B)
#define PINA *(( volatile u8*)0x39)

#define DDRB *((u8*)0x37)
#define PORTB *((u8*)0x38)*/

int main(void)
{
	//pin 0 out off
	DDRA |=1;
	PORTA &= ~1;
	//pin 1 out off
	DDRA |= (1<<1);
	PORTA &= ~(1<<1);
	//sw0 in
	DDRB &= ~1;
	//pull up
	PORTB |=1;

	//sw1 in
	DDRB &= ~(1<<1);
	//pull up
	PORTB |=(1<<1);

	//sw2 in
	DDRB &= ~(1<<2);
	//pull up
	PORTB |=(1<<2);

	while(1)
	{
		if((PINB&1)==0)
		{
			PORTA |= 1;
		}
		else PORTA &= ~1;

		 if( ((PINB>>1)&1)==0 ) PORTA |= (1<<1);
		 else PORTA &= ~(1<<1);
		 if( ((PINB>>2)&1)==0 )
			{
			PORTA |= 1;
			PORTA |= (1<<1);
			}
	}


	return 0;
}

