/* * main.c


 *
 *  Created on: Oct 3, 2023
 *      Author: HP
 */
#include <util/delay.h>
#include <avr/io.h>
typedef unsigned char u8;

#define DDRA *((u8*)0x3A)
#define PORTA *((u8*)0x3B)
#define PINA *(( volatile u8*)0x39)

int main(void)
{
	DDRA |= 1;
	while(1)
	{
	PORTA |= 1;
	_delay_ms(1000);
	PORTA &= ~1;
	_delay_ms(1000);
	}
	return 0;
}
int main(void)
{
	DDRA =0xff;
	PORTA =0;
	int i=0;
	while(1)
	{
		for(i=7;i>=0;i--)
		{
			PORTA |=(1<<i);
				_delay_ms(500);
		}
		for(i=7;i>=0;i--)
				{
					PORTA &=~(1<<i);
						_delay_ms(500);
				}
	}

	return 0;
}
